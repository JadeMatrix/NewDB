/* Includes *******************************************************************//******************************************************************************/

#include "ndb_vm_builtin.h"

/* Static Globals *************************************************************//******************************************************************************/



/* Implementations ************************************************************//******************************************************************************/

ndb_statcode ndm_vm_and( ndb_vm_state* state )
{
    switch( state -> arg_types[ 0 ] )
    {
    case NDB_VM_REGTYPE_BLANK:
        return NDB_STATCODE_WRONGARGCOUNT;
    case NDB_VM_REGTYPE__IR:
        {
            switch( state -> arg_types[ 1 ] )
            {
            case NDB_VM_REGTYPE_BLANK:
                return NDB_STATCODE_WRONGARGCOUNT;
            case NDB_VM_REGTYPE_CONST_I:
                state -> ir[ state -> arg_values[ 0 ].index ] &= state -> arg_values[ 1 ].i;
                break;
            case NDB_VM_REGTYPE__IR:
                state -> ir[ state -> arg_values[ 0 ].index ] &= state -> ir[ state -> arg_values[ 1 ].index ];
                break;
            default:
                return NDB_STATCODE_WRONGARGTYPE;
            }
        }
        break;
    case NDB_VM_REGTYPE_CMP:
    case NDB_VM_REGTYPE_DVI:
    case NDB_VM_REGTYPE_DMI:
        return NDB_STATCODE_READONLY;
    default:
        return NDB_STATCODE_WRONGARGTYPE;
    }
    
    return NDB_STATCODE_OK;
}
ndb_statcode ndm_vm_ceq( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_cge( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_cgt( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_cle( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_clt( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_cne( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_dec( ndb_vm_state* state )
{
    ndb_vmf_integer delta;
    
    switch( state -> arg_types[ 1 ] )
    {
    case NDB_VM_REGTYPE_BLANK:
        return NDB_STATCODE_WRONGARGCOUNT;
    case NDB_VM_REGTYPE_CONST_I:
        delta = state -> arg_values[ 1 ].i;
        break;
    case NDB_VM_REGTYPE__IR:
        delta = state -> ir[ state -> arg_values[ 1 ].index ];
        break;
    default:
        return NDB_STATCODE_WRONGARGTYPE;
    }
    
    switch( state -> arg_types[ 0 ] )
    {
    case NDB_VM_REGTYPE_BLANK:
        return NDB_STATCODE_WRONGARGCOUNT;
    case NDB_VM_REGTYPE__IR:
        state -> ir[ state -> arg_values[ 0 ].index ] -= delta;
        break;
    case NDB_VM_REGTYPE_CMP:
    case NDB_VM_REGTYPE_DVI:
    case NDB_VM_REGTYPE_DMI:
        return NDB_STATCODE_READONLY;
    default:
        return NDB_STATCODE_WRONGARGTYPE;
    }
    
    return NDB_STATCODE_OK;
}
ndb_statcode ndm_vm_dvd( ndb_vm_state* state )
{
    ndb_vmf_float divisor;
    
    switch( state -> arg_types[ 1 ] )
    {
    case NDB_VM_REGTYPE_BLANK:
        return NDB_STATCODE_WRONGARGCOUNT;
    case NDB_VM_REGTYPE_CONST_D:
        divisor = state -> arg_values[ 1 ].d;
        break;
    case NDB_VM_REGTYPE__DR:
        divisor = state -> dr[ state -> arg_values[ 1 ].index ];
        break;
    default:
        return NDB_STATCODE_WRONGARGTYPE;
    }
    
    switch( state -> arg_types[ 0 ] )
    {
    case NDB_VM_REGTYPE_BLANK:
        return NDB_STATCODE_WRONGARGCOUNT;
    case NDB_VM_REGTYPE_CONST_D:
        state -> dvd = state -> arg_values[ 0 ].d / divisor;
        break;
    case NDB_VM_REGTYPE__DR:
        state -> dvd = state -> dr[ state -> arg_values[ 0 ].index ] / divisor;
        break;
    default:
        return NDB_STATCODE_WRONGARGTYPE;
    }
    
    return NDB_STATCODE_OK;
}
ndb_statcode ndm_vm_dvf( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_dvi( ndb_vm_state* state )
{
    ndb_vmf_integer divisor;
    
    switch( state -> arg_types[ 1 ] )
    {
    case NDB_VM_REGTYPE_BLANK:
        return NDB_STATCODE_WRONGARGCOUNT;
    case NDB_VM_REGTYPE_CONST_I:
        divisor = state -> arg_values[ 1 ].i;
        break;
    case NDB_VM_REGTYPE__IR:
        divisor = state -> ir[ state -> arg_values[ 1 ].index ];
        break;
    default:
        return NDB_STATCODE_WRONGARGTYPE;
    }
    
    switch( state -> arg_types[ 0 ] )
    {
    case NDB_VM_REGTYPE_BLANK:
        return NDB_STATCODE_WRONGARGCOUNT;
    case NDB_VM_REGTYPE_CONST_I:
        state -> dvi = state -> arg_values[ 0 ].i / divisor;
        state -> dmi = state -> arg_values[ 0 ].i % divisor;
        break;
    case NDB_VM_REGTYPE__IR:
        state -> dvi = state -> ir[ state -> arg_values[ 0 ].index ] / divisor;
        state -> dmi = state -> ir[ state -> arg_values[ 0 ].index ] % divisor;
        break;
    default:
        return NDB_STATCODE_WRONGARGTYPE;
    }
    
    return NDB_STATCODE_OK;
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
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_hsi( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_inc( ndb_vm_state* state )
{
    ndb_vmf_integer delta;
    
    switch( state -> arg_types[ 1 ] )
    {
    case NDB_VM_REGTYPE_BLANK:
        return NDB_STATCODE_WRONGARGCOUNT;
    case NDB_VM_REGTYPE_CONST_I:
        delta = state -> arg_values[ 1 ].i;
        break;
    case NDB_VM_REGTYPE__IR:
        delta = state -> ir[ state -> arg_values[ 1 ].index ];
        break;
    default:
        return NDB_STATCODE_WRONGARGTYPE;
    }
    
    switch( state -> arg_types[ 0 ] )
    {
    case NDB_VM_REGTYPE_BLANK:
        return NDB_STATCODE_WRONGARGCOUNT;
    case NDB_VM_REGTYPE__IR:
        state -> ir[ state -> arg_values[ 0 ].index ] += delta;
        break;
    case NDB_VM_REGTYPE_CMP:
    case NDB_VM_REGTYPE_DVI:
    case NDB_VM_REGTYPE_DMI:
        return NDB_STATCODE_READONLY;
    default:
        return NDB_STATCODE_WRONGARGTYPE;
    }
    
    return NDB_STATCODE_OK;
}
ndb_statcode ndm_vm_inv( ndb_vm_state* state )
{
    switch( state -> arg_types[ 0 ] )
    {
    case NDB_VM_REGTYPE_BLANK:
        return NDB_STATCODE_WRONGARGCOUNT;
    case NDB_VM_REGTYPE__IR:
        state -> ir[ state -> arg_values[ 0 ].index ] = ~( state -> ir[ state -> arg_values[ 0 ].index ] );
        break;
    case NDB_VM_REGTYPE_CMP:
    case NDB_VM_REGTYPE_DVI:
    case NDB_VM_REGTYPE_DMI:
        return NDB_STATCODE_READONLY;
    default:
        return NDB_STATCODE_WRONGARGTYPE;
    }
    
    return NDB_STATCODE_OK;
}
ndb_statcode ndm_vm_jmp( ndb_vm_state* state )
{
    signed long instruction_pt;
    
    switch( state -> arg_types[ 1 ] )
    {
    case NDB_VM_REGTYPE_BLANK:
        return NDB_STATCODE_WRONGARGCOUNT;
    case NDB_VM_REGTYPE_CONST_I:
        instruction_pt = state -> arg_values[ 1 ].i - 1;
        break;
    case NDB_VM_REGTYPE__IR:
        instruction_pt = state -> ir[ state -> arg_values[ 1 ].index ] - 1;
        break;
    default:
        return NDB_STATCODE_WRONGARGTYPE;
    }
    
    switch( state -> arg_types[ 0 ] )
    {
    case NDB_VM_REGTYPE_BLANK:
        return NDB_STATCODE_WRONGARGCOUNT;
    case NDB_VM_REGTYPE_CONST_I:
        if( state -> arg_values[ 0 ].i )
            state -> instruction_pt = instruction_pt;
        break;
    case NDB_VM_REGTYPE__IR:
        if( state -> ir[ state -> arg_values[ 0 ].index ] )
            state -> instruction_pt = instruction_pt;
        break;
    case NDB_VM_REGTYPE_CMP:
        if( state -> cmp )
            state -> instruction_pt = instruction_pt;
        break;
    default:
        return NDB_STATCODE_WRONGARGTYPE;
    }
    
    return NDB_STATCODE_OK;
}
ndb_statcode ndm_vm_lf_( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_lpr( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_nul( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_or_( ndb_vm_state* state )
{
    switch( state -> arg_types[ 0 ] )
    {
    case NDB_VM_REGTYPE_BLANK:
        return NDB_STATCODE_WRONGARGCOUNT;
    case NDB_VM_REGTYPE__IR:
        {
            switch( state -> arg_types[ 1 ] )
            {
            case NDB_VM_REGTYPE_BLANK:
                return NDB_STATCODE_WRONGARGCOUNT;
            case NDB_VM_REGTYPE_CONST_I:
                state -> ir[ state -> arg_values[ 0 ].index ] |= state -> arg_values[ 1 ].i;
                break;
            case NDB_VM_REGTYPE__IR:
                state -> ir[ state -> arg_values[ 0 ].index ] |= state -> ir[ state -> arg_values[ 1 ].index ];
                break;
            default:
                return NDB_STATCODE_WRONGARGTYPE;
            }
        }
        break;
    case NDB_VM_REGTYPE_CMP:
    case NDB_VM_REGTYPE_DVI:
    case NDB_VM_REGTYPE_DMI:
        return NDB_STATCODE_READONLY;
    default:
        return NDB_STATCODE_WRONGARGTYPE;
    }
    
    return NDB_STATCODE_OK;
}
ndb_statcode ndm_vm_prf( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_rcd( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_rcp( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_rct( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_rud( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_rup( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_rut( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_scd( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_scf( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_sct( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_sf_( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_shs( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_snd( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_sr_( ndb_vm_state* state )
{
    ndb_vm_argtype type;
    ndb_vm_argval value;
    
    switch( state -> arg_types[ 1 ] )
    {
    case NDB_VM_REGTYPE_BLANK:
        return NDB_STATCODE_WRONGARGCOUNT;
    case NDB_VM_REGTYPE_CONST_I:
        type = NDB_VM_REGTYPE_CONST_I;
        value.i = state -> arg_values[ 1 ].i;
    case NDB_VM_REGTYPE_CONST_D:
        type = NDB_VM_REGTYPE_CONST_D;
        value.d = state -> arg_values[ 1 ].d;
    case NDB_VM_REGTYPE__IR:
        type = NDB_VM_REGTYPE_CONST_I;
        value.i = state -> ir[ state -> arg_values[ 1 ].index ];
    case NDB_VM_REGTYPE__DR:
        type = NDB_VM_REGTYPE_CONST_D;
        value.d = state -> dr[ state -> arg_values[ 1 ].index ];
    case NDB_VM_REGTYPE_CMP:
        type = NDB_VM_REGTYPE_CONST_I;
        value.i = state -> cmp;
    case NDB_VM_REGTYPE_DVI:
        type = NDB_VM_REGTYPE_CONST_I;
        value.i = state -> dvi;
    case NDB_VM_REGTYPE_DMI:
        type = NDB_VM_REGTYPE_CONST_I;
        value.i = state -> dmi;
    case NDB_VM_REGTYPE_DVD:
        type = NDB_VM_REGTYPE_CONST_D;
        value.d = state -> dvd;
    default:
        return NDB_STATCODE_WRONGARGTYPE;
    }
    
    switch( state -> arg_types[ 0 ] )
    {
    case NDB_VM_REGTYPE_BLANK:
        return NDB_STATCODE_WRONGARGCOUNT;
    case NDB_VM_REGTYPE__IR:
        if( type == NDB_VM_REGTYPE_CONST_I )
            state -> ir[ state -> arg_values[ 0 ].index ] = value.i;
        else
            state -> ir[ state -> arg_values[ 0 ].index ] = value.d;
        break;
    case NDB_VM_REGTYPE__DR:
        if( type == NDB_VM_REGTYPE_CONST_I )
            state -> dr[ state -> arg_values[ 0 ].index ] = value.i;
        else
            state -> dr[ state -> arg_values[ 0 ].index ] = value.d;
        break;
    case NDB_VM_REGTYPE_CMP:
    case NDB_VM_REGTYPE_DVI:
    case NDB_VM_REGTYPE_DMI:
    case NDB_VM_REGTYPE_DVD:
        return NDB_STATCODE_READONLY;
    default:
        return NDB_STATCODE_WRONGARGTYPE;
    }
    
    return NDB_STATCODE_OK;
}
ndb_statcode ndm_vm_srf( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_wcd( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_wcp( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_wct( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_wf_( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_wqp( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_wud( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_wup( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_wut( ndb_vm_state* state )
{
    /* IMPLEMENT: */
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndm_vm_xor( ndb_vm_state* state )
{
    switch( state -> arg_types[ 0 ] )
    {
    case NDB_VM_REGTYPE_BLANK:
        return NDB_STATCODE_WRONGARGCOUNT;
    case NDB_VM_REGTYPE__IR:
        {
            switch( state -> arg_types[ 1 ] )
            {
            case NDB_VM_REGTYPE_BLANK:
                return NDB_STATCODE_WRONGARGCOUNT;
            case NDB_VM_REGTYPE_CONST_I:
                state -> ir[ state -> arg_values[ 0 ].index ] ^= state -> arg_values[ 1 ].i;
                break;
            case NDB_VM_REGTYPE__IR:
                state -> ir[ state -> arg_values[ 0 ].index ] ^= state -> ir[ state -> arg_values[ 1 ].index ];
                break;
            default:
                return NDB_STATCODE_WRONGARGTYPE;
            }
        }
        break;
    case NDB_VM_REGTYPE_CMP:
    case NDB_VM_REGTYPE_DVI:
    case NDB_VM_REGTYPE_DMI:
        return NDB_STATCODE_READONLY;
    default:
        return NDB_STATCODE_WRONGARGTYPE;
    }
    
    return NDB_STATCODE_OK;
}

/******************************************************************************//******************************************************************************/


