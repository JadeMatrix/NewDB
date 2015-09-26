/* Includes *******************************************************************//******************************************************************************/

#include "ndb_page.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/* Macros *********************************************************************//******************************************************************************/

/* TODO: Make this more dynamic */
#define _NDB_MAX_PAGES_PER  128
#define _NDB_MAX_LIST_PAGES 128

/* Static Globals *************************************************************//******************************************************************************/

#if 0
typedef struct
{
    /*ndb_page_iden identifier;*/
    ndb_page*     page;
    unsigned long flags;
} _ndb_page_record;

static _ndb_page_record** page_records = NULL;
#endif

/* Implementations ************************************************************//******************************************************************************/

ndb_statcode ndb_page_claim_read( ndb_page_iden identifier, ndb_page** page )
{
    #if 0
    int record_i;
    int list_i;
    
    if( page_records == NULL )
        page_records = calloc( _NDB_MAX_LIST_PAGES,
                               sizeof( _ndb_page_record* ) );
    
    for( record_i = 0; record_i < _NDB_MAX_LIST_PAGES; ++record_i )
        if( page_records[ record_i ] != NULL )
        {
            _ndb_page_record* list = page_records[ record_i ];
            
            for( list_i = 0; list_i < _NDB_MAX_PAGES_PER; ++list_i )
                if( list[ list_i ].page != NULL )
                {
                    
                }
                else
                {
                    
                }
        }
        else
        {
            page_records[ record_i ] = calloc( _NDB_MAX_PAGES_PER,
                                               sizeof( _ndb_page_record ) );
            --record_i;
        }
    #endif
    
    FILE* page_file;
    char  page_file_path[ sizeof( "data/" ) + NDB_PAGE_IDEN_CHARLEN ];
    size_t read_bytes;
    
    page_file_path[ 0 ] = 'd';
    page_file_path[ 1 ] = 'a';
    page_file_path[ 2 ] = 't';
    page_file_path[ 3 ] = 'a';
    page_file_path[ 4 ] = '/';
    page_file_path[ sizeof( page_file_path ) - 1 ] = '\0';
    
    ( *page ) = valloc( NDB_PAGE_SIZE );
    if( *page == NULL )
        return NDB_STATCODE_MEMERROR;
    
    ndb_encode_page_iden( identifier, page_file_path + sizeof( "data/" ) - 1 );
    page_file = fopen( page_file_path, "rb" );
    
    if( page_file == NULL )
    {
        ( *page ) -> structure.metadata.identifier = identifier;
        
        /* TODO: Generate checksum */
    }
    else
    {
        ndb_statcode page_valid;
        
        read_bytes = fread( ( *page ) -> raw_data, 1, NDB_PAGE_SIZE, page_file );
        
        if( read_bytes != NDB_PAGE_SIZE
            || ferror( page_file ) )
        {
            free( *page );
            return NDB_STATCODE_IOERROR;
        }
        
        if( ( page_valid = ndb_page_verify( *page ) ) != NDB_STATCODE_OK )
        {
            return page_valid;
        }
    }
    
    return NDB_STATCODE_OK;
}
ndb_statcode ndb_page_claim_write( ndb_page_iden identifier, ndb_page** page )
{
    
    
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndb_page_unclaim_read( ndb_page** page )
{
    
    
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndb_page_unclaim_write( ndb_page** page )
{
    
    
    return NDB_STATCODE_NOTIMPLEMENTED;
}

ndb_statcode ndb_page_verify( ndb_page* page )
{
    
    
    return NDB_STATCODE_NOTIMPLEMENTED;
}

ndb_statcode ndb_encode_page_iden( ndb_page_iden identifier,
                                   char buffer[ NDB_PAGE_IDEN_CHARLEN ] )
{
    int i;
    
    if( !buffer )
        return NDB_STATCODE_NULLPOINTER;
    
    switch( NDB_PAGE_IDEN_ENCODEBASE )                                          /* Assuming this'll be optimized out by the compiler */
    {
    case 16:
        #if NDB_PAGE_IDEN_ENCODEBASE != 16
        #error ndb_encode_page_iden() not implemented for NDB_PAGE_IDEN_ENCODEBASE != 16
        #endif
        for( i = 0; i < NDB_PAGE_IDEN_CHARLEN; ++i )
        {
            unsigned int quartet = ( sizeof( identifier ) * 8 ) - ( ( i + 1 ) * 4 );
            unsigned int segval = 0x0F & ( identifier >> quartet );
            
            buffer[ i ] = "0123456789ABCDEF"[ segval ];
        }
        return NDB_STATCODE_OK;
    #if 0
    case 32:
        for( i = 0; i < NDB_PAGE_IDEN_CHARLEN; ++i )
        {
            unsigned int quartet = ( sizeof( identifier ) * 8 ) - ( ( i + 1 ) * 5 );
            unsigned int segval = 0x1F & ( identifier >> quartet );
            
            buffer[ i ] = "0123456789ABCDEFGHIJKLMNOPQRSTUV"[ segval ];
        }
        return NDB_STATCODE_OK;
    case 64:
        for( i = 0; i < NDB_PAGE_IDEN_CHARLEN; ++i )
        {
            unsigned int quartet = ( sizeof( identifier ) * 8 ) - ( ( i + 1 ) * 6 );
            unsigned int segval = 0x3F & ( identifier >> quartet );
            
            buffer[ i ] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+-"[ segval ];
        }
        return NDB_STATCODE_OK;
    #endif
    default:
        return NDB_STATCODE_NOTIMPLEMENTED;
    }
}

/******************************************************************************//******************************************************************************/


