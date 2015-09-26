/* Includes *******************************************************************//******************************************************************************/

#include "ndb_checksum.h"

/* Macros *********************************************************************//******************************************************************************/



/* Static Globals *************************************************************//******************************************************************************/



/* Implementations ************************************************************//******************************************************************************/

ndb_statcode ndb_checksum_CRC32( ndb_byte* source,
                                 unsigned long length,
                                 ndb_checksum_32* target )
{
    
    
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndb_checksum_CRC64( ndb_byte* source,
                                 unsigned long length,
                                 ndb_checksum_64* target )
{
    
    
    return NDB_STATCODE_NOTIMPLEMENTED;
}
ndb_statcode ndb_checksum_Adler32( ndb_byte* source,
                                   unsigned long length,
                                   ndb_checksum_32* target )
{
    unsigned int adler_a = 1;
    unsigned int adler_b = 0;
    
    unsigned long i;
    
    for( i = 0; i < length; ++i )
    {
        adler_a += source[ i ];
        adler_b += adler_a;
    }
    
    adler_a %= 65521;
    adler_b %= 65521;
    
    *target = ( adler_b << 16 ) | adler_a;
    
    return NDB_STATCODE_OK;
}

/******************************************************************************//******************************************************************************/


