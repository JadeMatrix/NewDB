#ifndef NDB_STATCODE_H
#define NDB_STATCODE_H
#ifdef __cplusplus
extern "C" {
#endif

/* General Types **************************************************************//******************************************************************************/

typedef enum
{
    NDB_STATCODE_OK,
    NDB_STATCODE_CANCEL,
    NDB_STATCODE_UNKNOWNERROR,
    NDB_STATCODE_WRONGARGTYPE,
    NDB_STATCODE_WRONGARGCOUNT,
    NDB_STATCODE_VMPROCPTOOB,
    NDB_STATCODE_READONLY,
    NDB_STATCODE_NOTIMPLEMENTED
} ndb_statcode;

/* Function Prototypes ********************************************************//******************************************************************************/

const char* ndb_statcode2str( ndb_statcode );

/******************************************************************************//******************************************************************************/

#ifdef __cplusplus
}
#endif
#endif


