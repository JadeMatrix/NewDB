/* Includes *******************************************************************//******************************************************************************/

#include "ndb_vm_builtin.h"

/* Static Globals *************************************************************//******************************************************************************/



/* Implementations ************************************************************//******************************************************************************/

/*void ndb_vm_register_builtins()
{
    int i;
    for( i = 0; i < sizeof( builtins ) / sizeof( ndb_vm_instinfo ); ++i )
        ndb_vm_register_instruction( &builtins[ i ] );
}*/

ndb_statcode ndm_vm_and( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_ceq( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_cge( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_cgt( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_cle( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_clt( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_cne( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_dec( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_dvd( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_dvf( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_dvi( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_ext( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    if( argc == 0 )
        return NDB_STATCODE_OK;
    
    if( argc == 1 )
        switch( argv[ 0 ].type )
        {
        case NDB_VM_ARGTYPE_LONG:
            return ( ndb_statcode )argv[ 0 ].value.i;
        /*case NDB_VM_ARGTYPE_ATOM:
        case NDB_VM_ARGTYPE_RESPONSE:*/
        default:
            return NDB_STATCODE_WRONGARGTYPE;
        }
    
    return NDB_STATCODE_WRONGARGCOUNT;
}
ndb_statcode ndm_vm_hsh( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_hsi( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_inc( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_inv( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_jmp( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_lf_( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_lpr( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_nul( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_or_( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_prf( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_rcd( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_rcp( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_rct( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_rud( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_rup( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_rut( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_scd( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_scf( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_sct( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_sf_( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_shs( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_snd( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_sr_( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_srf( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_wcd( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_wcp( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_wct( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_wf_( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_wqp( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_wud( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_wup( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_wut( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}
ndb_statcode ndm_vm_xor( ndb_vm_reg_index argc,
                         ndb_vm_arg* argv,
                         long* proc_pt )
{
    return NDB_STATCODE_UNKNOWNERROR;
}

/******************************************************************************//******************************************************************************/


