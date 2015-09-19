#ifndef NDB_VM_H
#define NDB_VM_H
#ifdef __cplusplus
extern "C" {
#endif

/* Includes *******************************************************************//******************************************************************************/

/*#include "ndb_vm_instruction.h"*/
#include "ndb_connection.h"
#include "ndb_query.h"
#include "ndb_statcode.h"

/* Definitions ****************************************************************//******************************************************************************/

#define NDB_VM_INSTARGC 3

/* General Types **************************************************************//******************************************************************************/

typedef unsigned long ndb_vm_argtype;

/* #define NDB_VM_ARGTYPE_NULL       ( ( ndb_vm_argtype )0x01 ) */
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
typedef unsigned long             ndb_vmf_atom;
/*typedef struct ndb_field*         ndb_vmf_field;
typedef struct ndb_page*          ndb_vmf_page;
typedef struct ndb_response*      ndb_vmf_response;
typedef struct ndb_connection*    ndb_vmf_connection;*/

/*typedef union
{
    struct
    {
        ndb_vm_objtype;
    } generic;
    ndb_vm_field field;
    ndb_vm_page page;
    ndb_vm_response response;
    ndb_vm_connection connection;
} ndb_vm_object;*/

typedef struct
{
    ndb_vm_argtype type;
    union
    {
        ndb_vmf_integer    i;
        ndb_vmf_float      d;
        ndb_vmf_atom       a;
        /*ndb_vm_object    obj;*/
        /*ndb_vmf_field      f;
        ndb_vmf_page       p;
        ndb_vmf_response   r;
        ndb_vmf_connection c;*/
    } value;
} ndb_vm_arg;

/*typedef struct
{
    long            inst_pt;
    long          reg_count;
    ndb_vm_arg*   registers;
} ndb_vm_state;*/

/* TODO:
 * Typedef for something to contain:
 *  - program pointer
 *  - instruction arguments
 *  - registers
 */

typedef unsigned char ndb_vm_reg_index;

/* VM Process Types ***********************************************************//******************************************************************************/

typedef ndb_statcode (* ndb_vm_inst )( ndb_vm_reg_index, ndb_vm_arg*, long* );

/* Function Prototypes ********************************************************//******************************************************************************/

ndb_statcode ndb_execute( ndb_connection*, ndb_query* );

/******************************************************************************//******************************************************************************/

#ifdef __cplusplus
}
#endif
#endif


