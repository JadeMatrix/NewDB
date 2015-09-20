#ifndef NDB_VM_H
#define NDB_VM_H
#ifdef __cplusplus
extern "C" {
#endif

/* Includes *******************************************************************//******************************************************************************/

/*#include "ndb_field.h"
#include "ndb_page.h"
#include "ndb_response.h"*/
#include "ndb_connection.h"
#include "ndb_query.h"
#include "ndb_statcode.h"

/* Definitions ****************************************************************//******************************************************************************/

#define NDB_VM_INSTARGC 3

/* General Types **************************************************************//******************************************************************************/

typedef enum
{
    NDB_VM_REGTYPE_BLANK,
    NDB_VM_REGTYPE_CONST_I,
    NDB_VM_REGTYPE_CONST_D,
    NDB_VM_REGTYPE_CONST_A,
    NDB_VM_REGTYPE__IR,
    NDB_VM_REGTYPE__DR,
    NDB_VM_REGTYPE__FR,
    NDB_VM_REGTYPE__PR,
    NDB_VM_REGTYPE__RR,
    NDB_VM_REGTYPE_CON,
    NDB_VM_REGTYPE_CMP,
    NDB_VM_REGTYPE_DVI,
    NDB_VM_REGTYPE_DMI,
    NDB_VM_REGTYPE_DVD
} ndb_vm_argtype;

/* Register Types *************************************************************//******************************************************************************/

typedef long                   ndb_vmf_integer;
typedef double                 ndb_vmf_float;
typedef unsigned long          ndb_vmf_atom;
typedef struct ndb_field*      ndb_vmf_field;
typedef struct ndb_page*       ndb_vmf_page;
typedef struct ndb_response*   ndb_vmf_response;
typedef struct ndb_connection* ndb_vmf_connection;

typedef unsigned char ndb_vm_reg_index;

typedef union
{
    ndb_vm_reg_index index;                                                     /* N in irN, drN, arN, frN, prN, and rrN */
    ndb_vmf_integer  i;                                                         /* Integer constant if type = NDB_VM_REGTYPE_CONST_I */
    ndb_vmf_float    d;                                                         /* Float constant if type = NDB_VM_REGTYPE_CONST_D */
    ndb_vmf_atom     a;                                                         /* Atom constant if type = NDB_VM_REGTYPE_CONST_A */
} ndb_vm_argval;                                                                /* Unused if register is con, cmp, dvi, dmi, dvd, or is blank */

typedef struct
{
    /* Instruction pointer */
    signed long instruction_pt;
    
    /* Arguments to current instruction */
    ndb_vm_argtype* arg_types;
    ndb_vm_argval*  arg_values;
    
    /* Registers */
    ndb_vmf_integer*    ir;
    ndb_vmf_float*      dr;
    ndb_vmf_field*      fr;
    ndb_vmf_page*       pr;
    ndb_vmf_response*   rr;
    ndb_vmf_connection con;
    ndb_vmf_integer    cmp;
    ndb_vmf_integer    dvi;
    ndb_vmf_integer    dmi;
    ndb_vmf_float      dvd;
    
    /* TODO: Atoms */
} ndb_vm_state;

/* VM Process Types ***********************************************************//******************************************************************************/

typedef ndb_statcode (* ndb_vm_inst )( ndb_vm_state* );

/* Function Prototypes ********************************************************//******************************************************************************/

ndb_statcode ndb_execute( ndb_connection*, ndb_query* );

/******************************************************************************//******************************************************************************/

#ifdef __cplusplus
}
#endif
#endif


