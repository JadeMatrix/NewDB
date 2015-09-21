/* Includes *******************************************************************//******************************************************************************/

#include "ndb_vm.h"

#include <alloca.h>
/* DEBUG: */ #include <stdio.h>

#include "ndb_vm_builtin.h"
#include "ndb_debug.h"

/* Macros *********************************************************************//******************************************************************************/



/* General Types **************************************************************//******************************************************************************/



/* Static Globals *************************************************************//******************************************************************************/



/* Implementations ************************************************************//******************************************************************************/

static ndb_statcode ndb_vm_run_asm( ndb_vm_state*   state,
                                    long            instruction_count,
                                    ndb_vm_inst*    instruction_list,
                                    ndb_vm_argtype* argument_types,
                                    ndb_vm_argval*  argument_values )           /* Runs the finalized assembly */
{
    ndb_statcode call_statcode = NDB_STATCODE_OK;
    
    signed long* instruction_pt = &( state -> instruction_pt );                 /* So we don't have to keep using -> */
    *instruction_pt = 0;
    
    while( *instruction_pt >= 0 )
    {
        /* DEBUG: */ printf( "Executing instruction %li: %s (0x%X)\n",
                             *instruction_pt,
                             ndb_debug_builtin2str( instruction_list[ *instruction_pt ] ),
                             ( unsigned int )instruction_list[ *instruction_pt ] );
        
        if( *instruction_pt >= instruction_count )
            goto cleanup_and_return;                                            /* Exit if we've run out of instructions */
        
        state -> arg_types  = &argument_types [ *instruction_pt * NDB_VM_INSTARGC ];    /* Set up instruction call arguments in state */
        state -> arg_values = &argument_values[ *instruction_pt * NDB_VM_INSTARGC ];
        
        if( ( call_statcode = instruction_list[ *instruction_pt ]( state ) )
            != NDB_STATCODE_OK )                                                /* Call instruction & handle return code */
        {
            /* DEBUG: */ printf( "Instruction return %s\n", ndb_debug_statcode2str( call_statcode ) );
            
            switch( call_statcode )
            {
                /* TODO: Handle other non-error codes here */
            default:
                goto cleanup_and_return;
            }
        }
        
        if( instruction_list[ *instruction_pt ] == NDB_VM_INST_EXT )
        {
            /* DEBUG: */ printf( "Exit called, exiting...\n" );
            goto cleanup_and_return;
        }
        else
        {
            ++( *instruction_pt );
            /* DEBUG: */ printf( "Incremented instruction pointer to %li\n", *instruction_pt );
        }
    }
    
    call_statcode = NDB_STATCODE_VMPROCPTOOB;
    
cleanup_and_return:
    
    /* DEBUG: */ printf( "Exiting with statcode %s\n", ndb_debug_statcode2str( call_statcode ) );
    return call_statcode;
}

ndb_statcode ndb_execute( ndb_connection* connection, ndb_query* query )        /* Run a query */
{
    #if 0
    ndb_statcode query_statcode;
    
    ndb_vm_state    query_program_state;
    long            instruction_count;
    ndb_vm_inst*    query_program_instructions;
    ndb_vm_argtype* query_program_arg_types;
    ndb_vm_argval*  query_program_arg_values;
    
    /*
     * in program parent caller (know ahead of time, arrangement doesn't chage):
     *   - program instruction list, allocated on stack or heap
     *   - register array(s), allocated on stack or heap
     *
     * passed to each instruction:
     *   - argument count
     *   - argument array
     *   - pointer to instruction pointer
     *
     * note that instruction pointer will be incremented after every instruction
     * call, so jumps must set pointer to value - 1 of where they want to go
     */
    
    /*query_program_state.con = connection;*/
    /*query_program_state.query_string = query;*/
    
    query_statcode = ndb_vm_run_asm( &query_program_state,
                                     instruction_count,
                                     query_program_instructions,
                                     query_program_arg_types,
                                     query_program_arg_values );                /* Run the query program */
    
    return query_statcode;
    #endif
    
    return NDB_STATCODE_OK;
}

/******************************************************************************//******************************************************************************/

int main( int argc, char* argv[] )
{
    /* Test program:
        sr ir0 -1
        inc ir0 1
        cle ir0 10
        jmp cmp 1
        ext
    */
    ndb_statcode   query_statcode;
    ndb_vm_state   query_program_state;
    long           instruction_count;
    ndb_vm_inst    test_instructions[ 5 ];
    ndb_vm_argtype test_argtypes[ 5 ][ 3 ];
    ndb_vm_argval  test_argvals[ 5 ][ 3 ];
    
    instruction_count = 5;
    query_program_state.ir = ( ndb_vmf_integer* )alloca( sizeof( ndb_vmf_integer ) );
    
    {
        test_instructions[ 0 ] = NDB_VM_INST_SR_;
        test_argtypes[ 0 ][ 0 ] = NDB_VM_REGTYPE__IR;
        test_argvals[ 0 ][ 0 ].index = 0;
        test_argtypes[ 0 ][ 1 ] = NDB_VM_REGTYPE_CONST_I;
        test_argvals[ 0 ][ 1 ].i = -1;
        test_argtypes[ 0 ][ 2 ] = NDB_VM_REGTYPE_BLANK;
        
        test_instructions[ 1 ] = NDB_VM_INST_INC;
        test_argtypes[ 1 ][ 0 ] = NDB_VM_REGTYPE__IR;
        test_argvals[ 1 ][ 0 ].index = 0;
        test_argtypes[ 1 ][ 1 ] = NDB_VM_REGTYPE_CONST_I;
        test_argvals[ 1 ][ 1 ].i = 1;
        test_argtypes[ 1 ][ 2 ] = NDB_VM_REGTYPE_BLANK;
        
        test_instructions[ 2 ] = NDB_VM_INST_CLT;
        test_argtypes[ 2 ][ 0 ] = NDB_VM_REGTYPE__IR;
        test_argvals[ 2 ][ 0 ].index = 0;
        test_argtypes[ 2 ][ 1 ] = NDB_VM_REGTYPE_CONST_I;
        test_argvals[ 2 ][ 1 ].i = 10;
        test_argtypes[ 2 ][ 2 ] = NDB_VM_REGTYPE_BLANK;
        
        test_instructions[ 3 ] = NDB_VM_INST_JMP;
        test_argtypes[ 3 ][ 0 ] = NDB_VM_REGTYPE_CMP;
        test_argtypes[ 3 ][ 1 ] = NDB_VM_REGTYPE_CONST_I;
        test_argvals[ 3 ][ 1 ].i = 1;
        test_argtypes[ 3 ][ 2 ] = NDB_VM_REGTYPE_BLANK;
        
        test_instructions[ 4 ] = NDB_VM_INST_EXT;
        test_argtypes[ 4 ][ 0 ] = NDB_VM_REGTYPE_BLANK;
        test_argtypes[ 4 ][ 1 ] = NDB_VM_REGTYPE_BLANK;
        test_argtypes[ 4 ][ 2 ] = NDB_VM_REGTYPE_BLANK;
    }
    
    {
        int i;
        printf( "Program:\n" );
        for( i = 0; i < instruction_count; ++i )
        {
            printf( "%i:    %s %s %s %s\n",
                    i,
                    ndb_debug_builtin2str( test_instructions[ i ] ),
                    ndb_debug_arg2str( test_argtypes[ i ][ 0 ], test_argvals[ i ][ 0 ] ),
                    ndb_debug_arg2str( test_argtypes[ i ][ 1 ], test_argvals[ i ][ 1 ] ),
                    ndb_debug_arg2str( test_argtypes[ i ][ 2 ], test_argvals[ i ][ 2 ] ) );
        }
    }
    
    query_statcode = ndb_vm_run_asm( &query_program_state,
                                     instruction_count,
                                     ( ndb_vm_inst* )test_instructions,
                                     ( ndb_vm_argtype* )test_argtypes,
                                     ( ndb_vm_argval* )test_argvals );
    
    printf( "Final value of $ir0: %li\n", query_program_state.ir[0] );
}


