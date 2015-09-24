#ifndef NDB_PAGE_H
#define NDB_PAGE_H
#ifdef __cplusplus
extern "C" {
#endif

/* Includes *******************************************************************//******************************************************************************/

#include "ndb_statcode.h"

/* Definitions ****************************************************************//******************************************************************************/

#define _NDB_PAGE_IDEN_TYPE         unsigned long
#define NDB_PAGE_IDEN_ENCODEBASE    16
#define NDB_PAGE_IDEN_CHARLEN       ( ( sizeof( _NDB_PAGE_IDEN_TYPE ) * 8 ) / ( NDB_PAGE_IDEN_ENCODEBASE >> 2 ) )

#define NDB_PAGE_SIZE_EXP   15
#define NDB_PAGE_SIZE       ( ( 2 << NDB_PAGE_SIZE_EXP ) - sizeof( _NDB_PAGE_IDEN_TYPE ) )

/* General Types **************************************************************//******************************************************************************/

typedef _NDB_PAGE_IDEN_TYPE ndb_page_iden;

typedef unsigned char ndb_byte;

typedef struct
{
    ndb_page_iden identifier;
    ndb_byte      data[ NDB_PAGE_SIZE ];
} ndb_page;

/* Function Prototypes ********************************************************//******************************************************************************/

ndb_statcode ndb_page_claim_read(    ndb_page_iden, ndb_page** );
ndb_statcode ndb_page_claim_write(   ndb_page_iden, ndb_page** );
ndb_statcode ndb_page_unclaim_read(                 ndb_page** );
ndb_statcode ndb_page_unclaim_write(                ndb_page** );

/*ndb_statcode ndb_page_open(  ndb_page**, ndb_page_iden );
ndb_statcode ndb_page_close( ndb_page** );*/

ndb_statcode ndb_encode_page_iden( ndb_page_iden, char* );                      /* Takes a string buffer of at least NDB_PAGE_IDEN_CHARLEN */

/******************************************************************************//******************************************************************************/

#ifdef __cplusplus
}
#endif
#endif


