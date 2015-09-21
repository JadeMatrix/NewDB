#ifndef NDB_DEBUG_H
#define NDB_DEBUG_H
#ifdef __cplusplus
extern "C" {
#endif

/* Includes *******************************************************************//******************************************************************************/

#include "ndb_vm.h"

/* Function Prototypes ********************************************************//******************************************************************************/

const char* ndb_debug_statcode2str( ndb_statcode );

const char* ndb_debug_builtin2str( ndb_vm_inst );

const char* ndb_debug_arg2str( ndb_vm_argtype, ndb_vm_argval );

/******************************************************************************//******************************************************************************/

#ifdef __cplusplus
}
#endif
#endif


