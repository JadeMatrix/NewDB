#ifndef NDB_STATCODE_H
#define NDB_STATCODE_H
#ifdef __cplusplus
extern "C" {
#endif

/* General Types **************************************************************//******************************************************************************/

typedef long ndb_statcode;

/* Statcode Values ************************************************************//******************************************************************************/

#define NDB_STATCODE_OK             ( ( ndb_statcode )0x00 )
#define NDB_STATCODE_WRONGARGTYPE   ( ( ndb_statcode )0x01 )

/******************************************************************************//******************************************************************************/

#ifdef __cplusplus
}
#endif
#endif


