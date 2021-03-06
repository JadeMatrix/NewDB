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
    NDB_STATCODE_NOTIMPLEMENTED,
    NDB_STATCODE_NULLPOINTER,
    NDB_STATCODE_IOERROR,
    NDB_STATCODE_MEMERROR,
    NDB_STATCODE_CHECKSUMFAIL
} ndb_statcode;

/******************************************************************************//******************************************************************************/

#ifdef __cplusplus
}
#endif
#endif


