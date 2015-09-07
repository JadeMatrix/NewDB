#ifndef NDB_PAGE_H
#define NDB_PAGE_H

#include <stdio.h>

#include "ndb_statcode.h"

typedef struct
{
    FILE* cfile;                                                                /* C handle for the page file */
    long size;                                                                  /* Size of the page file in bytes */
    long lname;                                                                 /* Unique ID of the page file as a 64-bit number */
    char* cname[ 8 ];                                                           /* Unique ID of the page as a hexadecimal string */
} ndb_page;

ndb_page* ndb_page_readclaim( long );                                           /* Read-claim a page by its lname */
ndb_page* ndb_page_writeclaim( long );                                          /* Write-claim a page by its lname */

long ndb_page_rowcount( ndb_page* );                                            /* Get the number of rows (empty & filled) in the page file */
ndb_statcode ndb_page_read( ndb_page*, long, long, void* );                     /* Read the field on the page at the given row & field index into the buffer */

#endif


