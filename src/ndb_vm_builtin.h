#ifndef NDB_VM_BUILTIN_H
#define NDB_VM_BUILTIN_H
#ifdef __cplusplus
extern "C" {
#endif

/* Includes *******************************************************************//******************************************************************************/

#include "ndb_vm.h"

/* Function Prototypes ********************************************************//******************************************************************************/

ndb_statcode ndb_vm_and( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_ceq( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_cge( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_cgt( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_cle( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_clt( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_cne( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_dec( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_dvd( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_dvf( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_dvi( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_ext( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_hsh( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_hsi( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_inc( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_inv( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_jmp( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_lf_( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_lpr( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_nul( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_or_( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_prf( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_rcd( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_rcp( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_rct( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_rud( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_rup( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_rut( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_scd( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_scf( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_sct( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_sf_( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_shs( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_snd( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_sr_( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_srf( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_wcd( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_wcp( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_wct( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_wf_( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_wqp( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_wud( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_wup( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_wut( ndb_vm_reg_index, ndb_vm_arg*, long* );
ndb_statcode ndb_vm_xor( ndb_vm_reg_index, ndb_vm_arg*, long* );

/* Definitions ****************************************************************//******************************************************************************/

#define NDB_VM_INST_AND ndb_vm_and
#define NDB_VM_INST_CEQ ndb_vm_ceq
#define NDB_VM_INST_CGE ndb_vm_cge
#define NDB_VM_INST_CGT ndb_vm_cgt
#define NDB_VM_INST_CLE ndb_vm_cle
#define NDB_VM_INST_CLT ndb_vm_clt
#define NDB_VM_INST_CNE ndb_vm_cne
#define NDB_VM_INST_DEC ndb_vm_dec
#define NDB_VM_INST_DVD ndb_vm_dvd
#define NDB_VM_INST_DVF ndb_vm_dvf
#define NDB_VM_INST_DVI ndb_vm_dvi
#define NDB_VM_INST_EXT ndb_vm_ext
#define NDB_VM_INST_HSH ndb_vm_hsh
#define NDB_VM_INST_HSI ndb_vm_hsi
#define NDB_VM_INST_INC ndb_vm_inc
#define NDB_VM_INST_INV ndb_vm_inv
#define NDB_VM_INST_JMP ndb_vm_jmp
#define NDB_VM_INST_LF_ ndb_vm_lf_
#define NDB_VM_INST_LPR ndb_vm_lpr
#define NDB_VM_INST_NUL ndb_vm_nul
#define NDB_VM_INST_OR_ ndb_vm_or_
#define NDB_VM_INST_PRF ndb_vm_prf
#define NDB_VM_INST_RCD ndb_vm_rcd
#define NDB_VM_INST_RCP ndb_vm_rcp
#define NDB_VM_INST_RCT ndb_vm_rct
#define NDB_VM_INST_RUD ndb_vm_rud
#define NDB_VM_INST_RUP ndb_vm_rup
#define NDB_VM_INST_RUT ndb_vm_rut
#define NDB_VM_INST_SCD ndb_vm_scd
#define NDB_VM_INST_SCF ndb_vm_scf
#define NDB_VM_INST_SCT ndb_vm_sct
#define NDB_VM_INST_SF_ ndb_vm_sf_
#define NDB_VM_INST_SHS ndb_vm_shs
#define NDB_VM_INST_SND ndb_vm_snd
#define NDB_VM_INST_SR_ ndb_vm_sr_
#define NDB_VM_INST_SRF ndb_vm_srf
#define NDB_VM_INST_WCD ndb_vm_wcd
#define NDB_VM_INST_WCP ndb_vm_wcp
#define NDB_VM_INST_WCT ndb_vm_wct
#define NDB_VM_INST_WF_ ndb_vm_wf_
#define NDB_VM_INST_WQP ndb_vm_wqp
#define NDB_VM_INST_WUD ndb_vm_wud
#define NDB_VM_INST_WUP ndb_vm_wup
#define NDB_VM_INST_WUT ndb_vm_wut
#define NDB_VM_INST_XOR ndb_vm_xor

/******************************************************************************//******************************************************************************/

#ifdef __cplusplus
}
#endif
#endif


