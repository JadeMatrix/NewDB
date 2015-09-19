/* Includes *******************************************************************//******************************************************************************/

#include "ndb_vm.h"

#include "ndb_vm_builtin.h"

/* Macros *********************************************************************//******************************************************************************/



/* General Types **************************************************************//******************************************************************************/

typedef struct
{
    ndb_vm_inst instruction;
    ndb_vm_reg_index inputs[ NDB_VM_INSTARGC ];                                 /* A list of indexes to a private array of ndb_vm_arg's in parent caller */
} ndb_vm_call_pattern;

/* Static Globals *************************************************************//******************************************************************************/



/* Implementations ************************************************************//******************************************************************************/

static ndb_statcode ndb_vm_run_asm( ndb_vm_call_pattern* asm,
                                    ndb_vm_arg*          registers,
                                    ndb_vm_reg_index     register_count )       /* Runs the finalized assembly */
{
    ndb_statcode call_statcode = NDB_STATCODE_OK;
    
    ndb_vm_arg call_registers[ NDB_VM_INSTARGC ];
    long instruction_pt = 0;
    
    long call_register_i;
    
    while( 1 )
    {
        call_register_i = NDB_VM_INSTARGC + 1;
        while( --call_register_i )                                              /* Set registers for call */
            call_registers[ call_register_i ] = registers[ asm[ instruction_pt ].inputs[ call_register_i ] ];
        
        if( ( call_statcode = asm[ instruction_pt ].instruction( register_count,
                                                                 call_registers,
                                                                 &instruction_pt ) )
            != NDB_STATCODE_OK )                                                /* Call instruction & handle return code */
        {
            switch( call_statcode )
            {
                /* TODO: Handle other non-error codes here */
            default:
                goto cleanup_and_return;
            }
        }
        
        if( asm[ instruction_pt ].instruction == NDB_VM_INST_EXT )
            goto cleanup_and_return;
        else
            ++instruction_pt;
    }
    
cleanup_and_return:
    
    return call_statcode;
}

ndb_statcode ndb_execute( ndb_connection* connection, ndb_query* query )        /* Run a query */
{
    ndb_statcode query_statcode;
    
    ndb_vm_call_pattern* query_program;
    ndb_vm_reg_index     query_register_count = 0;
    
    /* TODO: Just alloca() what we need so we don't use so much stack space */
    ndb_vm_arg query_registers[ 0x01 << ( sizeof( ndb_vm_reg_index ) * 8 ) ];
    
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
    
    query_statcode = ndb_vm_run_asm( query_program,
                                     query_registers,
                                     query_register_count );                    /* Run the query program */
    
    return query_statcode;
}

/******************************************************************************//******************************************************************************/


