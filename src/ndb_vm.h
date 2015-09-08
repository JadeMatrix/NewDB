#ifndef NDB_VM_H
#define NDB_VM_H
#ifdef __cplusplus
extern "C" {
#endif

/* Includes *******************************************************************//******************************************************************************/

/* Definitions ****************************************************************//******************************************************************************/

#define NDB_VM_INST_ARGC       3

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

typedef long ndb_vm_statcode;

typedef ndb_vm_statcode (* ndb_vm_inst )( unsigned int, ndb_vm_arg*, long* );

/* TODO: Move to ndb_vm.c */
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
typedef struct
{
    ndb_vm_inst instruction;
    unsigned long args[ NDB_VM_INST_ARGC ];                                     /* A list of indexes to a private array of ndb_vm_arg's in parent caller */
} ndb_vm_call;

/******************************************************************************//******************************************************************************/

#ifdef __cplusplus
}
#endif
#endif


