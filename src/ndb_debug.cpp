/* Includes *******************************************************************//******************************************************************************/

#include "ndb_debug.h"

#include <map>
#include <string>
#include <sstream>

#include "ndb_vm_builtin.h"

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

const char* ndb_debug_statcode2str( ndb_statcode code )
{
    switch( code )
    {
    case NDB_STATCODE_OK:
        return "OK";
    case NDB_STATCODE_CANCEL:
        return "CANCEL";
    case NDB_STATCODE_UNKNOWNERROR:
        return "UNKNOWN ERROR";
    case NDB_STATCODE_WRONGARGTYPE:
        return "WRONG ARGUMENT TYPE";
    case NDB_STATCODE_WRONGARGCOUNT:
        return "WRONG ARGUMENT COUNT";
    case NDB_STATCODE_VMPROCPTOOB:
        return "VM PROCESS POINTER OUT-OF-BOUNDS";
    case NDB_STATCODE_READONLY:
        return "READ-ONLY";
    case NDB_STATCODE_NOTIMPLEMENTED:
        return "NOT IMPLEMENTED";
    case NDB_STATCODE_NULLPOINTER:
        return "NULL POINTER";
    case NDB_STATCODE_IOERROR:
        return "I/O ERROR";
    case NDB_STATCODE_MEMERROR:
        return "MEMORY ERROR";
    case NDB_STATCODE_CHECKSUMFAIL:
        return "CHECKSUM FAILURE";
    }
}

const char* ndb_debug_builtin2str( ndb_vm_inst instruction )
{
    return builtin_names[ instruction ].c_str();
}

const char* ndb_debug_arg2str( ndb_vm_argtype type, ndb_vm_argval val )
{
    std::stringstream ss;
    
    switch( type )
    {
    case NDB_VM_REGTYPE_BLANK:
        return "";
    case NDB_VM_REGTYPE_CONST_I:
        ss << val.i;
        return ss.str().c_str();
        break;
    case NDB_VM_REGTYPE_CONST_D:
        ss << val.d;
        return ss.str().c_str();
        break;
    case NDB_VM_REGTYPE_CONST_A:
        ss << '{' << val.a.pos << ',' << val.a.len << '}';
        return ss.str().c_str();
        break;
    case NDB_VM_REGTYPE__IR:
        ss << "$ir" << ( int )val.index;
        return ss.str().c_str();
        break;
    case NDB_VM_REGTYPE__DR:
        ss << "$dr" << ( int )val.index;
        return ss.str().c_str();
        break;
    case NDB_VM_REGTYPE__FR:
        ss << "$fr" << ( int )val.index;
        return ss.str().c_str();
        break;
    case NDB_VM_REGTYPE__PR:
        ss << "$pr" << ( int )val.index;
        return ss.str().c_str();
        break;
    case NDB_VM_REGTYPE__RR:
        ss << "$rr" << ( int )val.index;
        return ss.str().c_str();
        break;
    case NDB_VM_REGTYPE_CON:
        return "$con";
    case NDB_VM_REGTYPE_CMP:
        return "$cmp";
    case NDB_VM_REGTYPE_DVI:
        return "$dvi";
    case NDB_VM_REGTYPE_DMI:
        return "$dmi";
    case NDB_VM_REGTYPE_DVD:
        return "$dvd";
    default:
        return "UNKNOWN ARGTYPE";
    }
}

/******************************************************************************//******************************************************************************/


