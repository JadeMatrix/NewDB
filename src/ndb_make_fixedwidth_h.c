/* There is nothing that can be done in C99 than cannot be done more cleverly
 * (ie more verbosely) in C89.
 *                                  - Me, right now.
 */

/* Includes *******************************************************************//******************************************************************************/

#include <stdio.h>

/* Static Globals *************************************************************//******************************************************************************/

static char* header_upper =
"#ifndef NDB_FIXEDWIDTH_H\n"
"#define NDB_FIXEDWIDTH_H\n"
"#ifdef __cplusplus\n"
"extern \"C\" {\n"
"#endif\n"
"\n"
"/* WARNING: Automatically generated - do not edit */\n"
"\n"
"/* General Types **************************************************************/"
"/******************************************************************************/\n"
"\n";

static char* header_lower =
"\n"
"/******************************************************************************/"
"/******************************************************************************/\n"
"\n"
"#ifdef __cplusplus\n"
"}\n"
"#endif\n"
"#endif\n"
"\n"
"\n";

/* Implementations ************************************************************//******************************************************************************/

static int log2( int in )
{
    int out = 0;
    while( in >>= 1)
        ++out;
    return out;
}

int main( int argc, char* argv[] )
{
    int byte_bits = 0;
    char* types[] = { 0,
                      0,
                      0,
                      0,
                      0 };                                                      /* Each index is the type that has byte_bits * 2^i bits */
    int i;
    unsigned char byte_tester = 0x01;
    
    do
    {
        ++byte_bits;
    } while( byte_tester <<= 1 );
    
    /*types[ log2( sizeof( long long ) ) ] =  "long long";*/
    types[ log2( sizeof( long  ) ) ] =  "long";
    types[ log2( sizeof( int   ) ) ] =   "int";
    types[ log2( sizeof( short ) ) ] = "short";
    types[ log2( sizeof( char  ) ) ] =  "char";
    
    printf( "%s", header_upper );
    
    printf( "#define NBD_BYTE_BITS %i\n\n", byte_bits );
    
    for( i = 0; i < sizeof( types ) / sizeof( char* ); ++i )
        if( types[ i ] != 0 )
            printf( "typedef %s ndb_int%i;\n",
                    types[ i ],
                    byte_bits * ( 1 << i ) );
    
    printf( "%s", header_lower );
    
    return 0x00;
}


