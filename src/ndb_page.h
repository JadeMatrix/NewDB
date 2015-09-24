#ifndef NDB_PAGE_H
#define NDB_PAGE_H
#ifdef __cplusplus
extern "C" {
#endif

/* General Types **************************************************************//******************************************************************************/

typedef unsigned char ndb_byte;

typedef struct
{
    unsigned long page_size_exp;
    ndb_byte* page;
} ndb_page;

/* Function Prototypes ********************************************************//******************************************************************************/



/******************************************************************************//******************************************************************************/

#ifdef __cplusplus
}
#endif
#endif


