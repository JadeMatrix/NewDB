/* Includes *******************************************************************//******************************************************************************/

#include "ndb_page.h"

/* Macros *********************************************************************//******************************************************************************/



/* Static Globals *************************************************************//******************************************************************************/



/* Implementations ************************************************************//******************************************************************************/

ndb_statcode ndb_page_claim_read( ndb_page_iden identifier, ndb_page** page )
{
    
    
    return NDB_STATCODE_NOTIMPLEMENTED;
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


