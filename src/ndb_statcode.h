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
    NDB_STATCODE_WRONGARGCOUNT
} ndb_statcode;

/******************************************************************************//******************************************************************************/

#ifdef __cplusplus
}
#endif
#endif


