#ifndef NDB_VM_H
#define NDB_VM_H
#ifdef __cplusplus
extern "C" {
#endif

/* Includes *******************************************************************//******************************************************************************/

#include "ndb_atom.h"

/* Definitions ****************************************************************//******************************************************************************/

#define NDB_VM_PROG_STACK_SIZE 64
#define NDB_VM_INST_ARGC       3

/* General Types **************************************************************//******************************************************************************/

typedef unsigned long ndb_vm_argtype;

#define NDB_VM_ARGTYPE_NULL       ( ( ndb_vm_argtype )0x01 )
#define NDB_VM_ARGTYPE_LONG       ( ( ndb_vm_argtype )0x02 )
#define NDB_VM_ARGTYPE_DOUBLE     ( ( ndb_vm_argtype )0x04 )
#define NDB_VM_ARGTYPE_ATOM       ( ( ndb_vm_argtype )0x08 )
#define NDB_VM_ARGTYPE_PAGE       ( ( ndb_vm_argtype )0x10 )
#define NDB_VM_ARGTYPE_FIELD      ( ( ndb_vm_argtype )0x20 )
#define NDB_VM_ARGTYPE_RESPONSE   ( ( ndb_vm_argtype )0x40 )
#define NDB_VM_ARGTYPE_CONNECTION ( ( ndb_vm_argtype )0x80 )

/* Register Types *************************************************************//******************************************************************************/

typedef long                      ndb_vmf_integer;
typedef double                    ndb_vmf_float;
/* typedef unsigned long             ndb_vmf_atom; */                           /* Defined in ndb_atom.h */
typedef struct ndb_vm_field*      ndb_vmf_field;
typedef struct ndb_vm_page*       ndb_vmf_page;
typedef struct ndb_vm_response*   ndb_vmf_response;
typedef struct ndb_vm_connection* ndb_vmf_connection;

typedef struct
{
    ndb_vm_argtype type;
    union
    {
        ndb_vmf_integer    i;
        ndb_vmf_float      d;
        ndb_vmf_atom       a;
        ndb_vmf_field      f;
        ndb_vmf_page       p;
        ndb_vmf_response   r;
        ndb_vmf_connection c;
    } value;
} ndb_vm_arg;

/* VM Process Types ***********************************************************//******************************************************************************/

typedef struct ndb_vm_process ndb_vm_process;                                   /* Predeclare process type so it can be passed to instructions */

typedef long ndb_vm_statcode;

typedef ndb_vm_statcode (* ndb_vm_inst )( ndb_vm_process* );

typedef struct
{
    ndb_vm_inst instruction;
    
} ndb_vm_call;

struct
{
    long process_ptr;                                                           /* Process instruction pointer */
    ndb_vm_inst** program;                                                      /* Pointer to program instruction array (can be on the stack or heap) */
    
    ndb_vm_arg args[ NDB_VM_INST_ARGC ];                                        /* Instruction arguments */
    
    /* Registers *//*
    ndb_vm_integer*    ir;
    ndb_vm_float*      dr;
    ndb_vm_field*      fr;
    ndb_vm_page*       pr;
    ndb_vm_response*   rr;
    ndb_vm_connection* cr;
    
    ndb_vm_integer     dvi;
    ndb_vm_integer     dmi;
    ndb_vm_float       dvd;*/
    
    
} ndb_vm_process;



/******************************************************************************//******************************************************************************/

#ifdef __cplusplus
}
#endif
#endif


