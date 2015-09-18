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

#if 0
typedef struct
{
    /* Raw instruction calls */
    unsigned long        inst_count,
    struct
    {
        ndb_vm_reg_id    inputs [ NDB_VM_INSTARGC ];
        ndb_vm_reg_index indeces[ NDB_VM_INSTARGC ];
        ndb_vm_inst_id   instruction;
    }* insts,
    
    /* Single Registers */
    ndb_vm_arg con;
    ndb_vm_arg cmp;
    ndb_vm_arg dvi;
    ndb_vm_arg dmi;
    ndb_vm_arg dvd;
    
    /* Variable Registers */
    ndb_vm_arg* ir;
    ndb_vm_arg* dr;
    ndb_vm_arg* ar;
    ndb_vm_arg* fr;
    ndb_vm_arg* pr;
    ndb_vm_arg* rr;
    ndb_vm_arg* cr;
    
    /* Variable Register Counts */
    /*ndb_vm_reg_index ir_count;
    ndb_vm_reg_index dr_count;
    ndb_vm_reg_index ar_count;
    ndb_vm_reg_index fr_count;
    ndb_vm_reg_index pr_count;
    ndb_vm_reg_index rr_count;
    ndb_vm_reg_index cr_count;*/
} ndb_vm_procinfo;
#endif

/* Static Globals *************************************************************//******************************************************************************/



/* Implementations ************************************************************//******************************************************************************/

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
/*typedef struct
{
    ndb_vm_inst instruction;
    unsigned long args[ NDB_VM_INSTARGC ];
} ndb_vm_call;*/

/* Optimizes execution of the assembly */
/*static ndb_statcode ndb_vm_optimize_asm( ndb_vm_procinfo* info_p )
{
    
}*/

/* Compresses registers (and instructions?) */
/*static ndb_statcode ndb_vm_compress_asm( ndb_vm_procinfo* info_p,
                                            ndb_vm_state_compressed* comp_p )
{
    
}*/

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
        
        switch( asm[ instruction_pt ].instruction )
        {
            /* TODO: Handle other known, simple instructions like arithmetic */
        case NDB_VM_INST_EXT:
            if( call_registers[ 0 ].type == NDB_VM_ARGTYPE_LONG )
                call_statcode = call_registers[ 0 ].i;
            else
                /* call_statcode = NDB_STATCODE_WRONGARGTYPE; */
                call_statcode = NDB_VM_INST_EXT( register_count,
                                                 call_registers,
                                                 &instruction_pt );
            goto cleanup_and_return;
        default:
            if( ( call_statcode = asm[ instruction_pt ].instruction( register_count,
                                                                     call_registers,
                                                                     &instruction_pt ) )    /* Call instruction & handle return code */
                != NDB_STATCODE_OK )
            {
                switch( call_statcode )
                {
                    /* TODO: Handle other non-error codes here */
                default:
                    goto cleanup_and_return;
                }
            }                                                                   /* else... Skip statcode handling entirely so we don't multi-jump */
            
            break;
        }
        
        ++instruction_pt;
    }
    
cleanup_and_return:
    
    return call_statcode;
}

ndb_statcode ndb_execute( ndb_connection* connection, ndb_query* query )        /* Run a query */
{
    ndb_statcode query_statcode;
    
    ndb_vm_call_pattern* query_program;
    
    /* TODO: Just alloca() what we need so we don't use so much stack space */
    ndb_vm_arg query_registers[ 0x01 << ( sizeof( ndb_vm_reg_index ) * 8 ) ];
    
    /* Do some other stuff (that's an understatement)... */
    
    query_statcode = ndb_vm_run_asm( query_program,
                                     query_registers,
                                     query_register_count );                    /* Run the query program */
    
    return query_statcode;
}

/******************************************************************************//******************************************************************************/


