/* Includes *******************************************************************//******************************************************************************/

#include "ndb_vm_builtin.h"

/* Static Globals *************************************************************//******************************************************************************/



/* Implementations ************************************************************//******************************************************************************/

ndb_statcode ndm_vm_and( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_ceq( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_cge( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_cgt( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_cle( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_clt( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_cne( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_dec( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_dvd( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_dvf( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_dvi( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_ext( ndb_vm_state* state )
{
    switch( state -> arg_types[ 0 ] )
    {
    case NDB_VM_REGTYPE_BLANK:
        return NDB_STATCODE_OK;
    case NDB_VM_REGTYPE_CONST_I:
        return ( ndb_statcode )( state -> arg_values[ 0 ].i );
    /*case NDB_VM_ARGTYPE_ATOM:
        break;*/
    default:
        return NDB_STATCODE_WRONGARGTYPE;
    }
}
ndb_statcode ndm_vm_hsh( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_hsi( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_inc( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_inv( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_jmp( ndb_vm_state* state )
{
    signed long instruction_pt;
    
    switch( state -> arg_types[ 1 ] )
    {
    case NDB_VM_REGTYPE__IR:
        instruction_pt = state -> ir[ state -> arg_values[ 1 ].index ] - 1;
        break;
    case NDB_VM_REGTYPE_CONST_I:
        instruction_pt = state -> arg_values[ 1 ].i - 1;
        break;
    case NDB_VM_REGTYPE_BLANK:
        return NDB_STATCODE_WRONGARGCOUNT;
    default:
        return NDB_STATCODE_WRONGARGTYPE;
    }
    
    switch( state -> arg_types[ 0 ] )
    {
    case NDB_VM_REGTYPE_CMP:
        if( state -> cmp )
            state -> instruction_pt = instruction_pt;
        break;
    case NDB_VM_REGTYPE__IR:
        if( state -> ir[ state -> arg_values[ 0 ].index ] )
            state -> instruction_pt = instruction_pt;
        break;
    case NDB_VM_REGTYPE_CONST_I:
        if( state -> arg_values[ 0 ].i )
            state -> instruction_pt = instruction_pt;
        break;
    case NDB_VM_REGTYPE_BLANK:
        return NDB_STATCODE_WRONGARGCOUNT;
    default:
        return NDB_STATCODE_WRONGARGTYPE;
    }
    
    return NDB_STATCODE_OK;
}
ndb_statcode ndm_vm_lf_( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_lpr( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_nul( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_or_( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_prf( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_rcd( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_rcp( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_rct( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_rud( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_rup( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_rut( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_scd( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_scf( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_sct( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_sf_( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_shs( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_snd( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_sr_( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_srf( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_wcd( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_wcp( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_wct( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_wf_( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_wqp( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_wud( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_wup( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_wut( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_xor( ndb_vm_state* state )
{
    return NDB_STATCODE_UNKNOWNERROR;
}

/******************************************************************************//******************************************************************************/


