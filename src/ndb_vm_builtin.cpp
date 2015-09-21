/* Includes *******************************************************************//******************************************************************************/

#include "ndb_vm_builtin.h"

#include <map>
#include <string>

/* Static Globals *************************************************************//******************************************************************************/

namespace
{
    typedef std::map< ndb_vm_inst, std::string >::value_type bin_t;
    const bin_t builtin_names_raw[] = { bin_t( NDB_VM_INST_AND, "and" ),
                                        bin_t( NDB_VM_INST_CEQ, "ceq" ),
                                        bin_t( NDB_VM_INST_CGE, "cge" ),
                                        bin_t( NDB_VM_INST_CGT, "cgt" ),
                                        bin_t( NDB_VM_INST_CLE, "cle" ),
                                        bin_t( NDB_VM_INST_CLT, "clt" ),
                                        bin_t( NDB_VM_INST_CNE, "cne" ),
                                        bin_t( NDB_VM_INST_DEC, "dec" ),
                                        bin_t( NDB_VM_INST_DVD, "dvd" ),
                                        bin_t( NDB_VM_INST_DVF, "dvf" ),
                                        bin_t( NDB_VM_INST_DVI, "dvi" ),
                                        bin_t( NDB_VM_INST_EXT, "ext" ),
                                        bin_t( NDB_VM_INST_HSH, "hsh" ),
                                        bin_t( NDB_VM_INST_HSI, "hsi" ),
                                        bin_t( NDB_VM_INST_INC, "inc" ),
                                        bin_t( NDB_VM_INST_INV, "inv" ),
                                        bin_t( NDB_VM_INST_JMP, "jmp" ),
                                        bin_t( NDB_VM_INST_LF_, "lf"  ),
                                        bin_t( NDB_VM_INST_LPR, "lpr" ),
                                        bin_t( NDB_VM_INST_NUL, "nul" ),
                                        bin_t( NDB_VM_INST_OR_, "or"  ),
                                        bin_t( NDB_VM_INST_PRF, "prf" ),
                                        bin_t( NDB_VM_INST_RCD, "rcd" ),
                                        bin_t( NDB_VM_INST_RCP, "rcp" ),
                                        bin_t( NDB_VM_INST_RCT, "rct" ),
                                        bin_t( NDB_VM_INST_RUD, "rud" ),
                                        bin_t( NDB_VM_INST_RUP, "rup" ),
                                        bin_t( NDB_VM_INST_RUT, "rut" ),
                                        bin_t( NDB_VM_INST_SCD, "scd" ),
                                        bin_t( NDB_VM_INST_SCF, "scf" ),
                                        bin_t( NDB_VM_INST_SCT, "sct" ),
                                        bin_t( NDB_VM_INST_SF_, "sf"  ),
                                        bin_t( NDB_VM_INST_SHS, "shs" ),
                                        bin_t( NDB_VM_INST_SND, "snd" ),
                                        bin_t( NDB_VM_INST_SR_, "sr"  ),
                                        bin_t( NDB_VM_INST_SRF, "srf" ),
                                        bin_t( NDB_VM_INST_VEQ, "veq" ),
                                        bin_t( NDB_VM_INST_VGE, "vge" ),
                                        bin_t( NDB_VM_INST_VGT, "vgt" ),
                                        bin_t( NDB_VM_INST_VLE, "vle" ),
                                        bin_t( NDB_VM_INST_VLT, "vlt" ),
                                        bin_t( NDB_VM_INST_VNE, "vne" ),
                                        bin_t( NDB_VM_INST_WCD, "wcd" ),
                                        bin_t( NDB_VM_INST_WCP, "wcp" ),
                                        bin_t( NDB_VM_INST_WCT, "wct" ),
                                        bin_t( NDB_VM_INST_WF_, "wf"  ),
                                        bin_t( NDB_VM_INST_WQP, "wqp" ),
                                        bin_t( NDB_VM_INST_WUD, "wud" ),
                                        bin_t( NDB_VM_INST_WUP, "wup" ),
                                        bin_t( NDB_VM_INST_WUT, "wut" ),
                                        bin_t( NDB_VM_INST_XOR, "xor" ) };
    std::map< ndb_vm_inst, std::string > builtin_names( builtin_names_raw,
                                                        builtin_names_raw + ( sizeof( builtin_names_raw )
                                                                              / sizeof( bin_t ) ) );
}

/* Implementations ************************************************************//******************************************************************************/

const char* ndb_builtin2str( ndb_vm_inst instruction )
{
    return builtin_names[ instruction ].c_str();
}

/******************************************************************************//******************************************************************************/


