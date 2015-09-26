#ifndef NDB_CHECKSUM_H
#define NDB_CHECKSUM_H
#ifdef __cplusplus
extern "C" {
#endif

/* Includes *******************************************************************//******************************************************************************/

#include "ndb_statcode.h"
#include "ndb_util.h"

/* General Types **************************************************************//******************************************************************************/

typedef unsigned int  ndb_checksum_32;
typedef unsigned long ndb_checksum_64;

/* Function Prototypes ********************************************************//******************************************************************************/

ndb_statcode ndb_checksum_CRC32(   ndb_byte*, unsigned long, ndb_checksum_32* );
ndb_statcode ndb_checksum_CRC64(   ndb_byte*, unsigned long, ndb_checksum_64* );
ndb_statcode ndb_checksum_Adler32( ndb_byte*, unsigned long, ndb_checksum_32* );

/******************************************************************************//******************************************************************************/

#ifdef __cplusplus
}
#endif
#endif


