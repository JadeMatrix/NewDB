/* Includes *******************************************************************//******************************************************************************/

#include "ndb_vm.h"

#include "ndb_vm_builtin.h"

/* Macros *********************************************************************//******************************************************************************/



/* General Types **************************************************************//******************************************************************************/



/* Static Globals *************************************************************//******************************************************************************/



/* Implementations ************************************************************//******************************************************************************/

static ndb_statcode ndb_vm_run_asm( ndb_vm_state*    state,
                                    ndb_vm_inst*     instruction_list,
                                    ndb_vm_argtype** argument_types,
                                    ndb_vm_argval**  argument_values )          /* Runs the finalized assembly */
{
    ndb_statcode call_statcode = NDB_STATCODE_OK;
    
    signed long* instruction_pt = &( state -> instruction_pt );                 /* So we don't have to keep using -> */
    *instruction_pt = 0;
    
    while( 1 )
    {
        state -> arg_types  = argument_types [ *instruction_pt ];
        state -> arg_values = argument_values[ *instruction_pt ];
        
        if( ( call_statcode = instruction_list[ *instruction_pt ]( state ) )
            != NDB_STATCODE_OK )                                                /* Call instruction & handle return code */
        {
            switch( call_statcode )
            {
                /* TODO: Handle other non-error codes here */
            default:
                goto cleanup_and_return;
            }
        }
        
        if( instruction_list[ *instruction_pt ] == NDB_VM_INST_EXT )
            goto cleanup_and_return;
        else
            ++( *instruction_pt );
    }
    
cleanup_and_return:
    
    return call_statcode;
}

ndb_statcode ndb_execute( ndb_connection* connection, ndb_query* query )        /* Run a query */
{
    ndb_statcode query_statcode;
    
    ndb_vm_state     query_program_state;
    ndb_vm_inst*     query_program_instructions;
    ndb_vm_argtype** query_program_arg_types;
    ndb_vm_argval**  query_program_arg_values;
    
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
    
    query_statcode = ndb_vm_run_asm( &query_program_state,
                                     query_program_instructions,
                                     query_program_arg_types,
                                     query_program_arg_values );                /* Run the query program */
    
    return query_statcode;
}

/******************************************************************************//******************************************************************************/


