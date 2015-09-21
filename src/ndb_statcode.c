/* Includes *******************************************************************//******************************************************************************/

#include "ndb_statcode.h"

/* Implementations ************************************************************//******************************************************************************/

const char* ndb_statcode2str( ndb_statcode code )
{
    switch( code )
    {
    case NDB_STATCODE_OK:
        return "OK";
    case NDB_STATCODE_CANCEL:
        return "CANCEL";
    case NDB_STATCODE_UNKNOWNERROR:
        return "UNKNOWN ERROR";
    case NDB_STATCODE_WRONGARGTYPE:
        return "WRONG ARGUMENT TYPE";
    case NDB_STATCODE_WRONGARGCOUNT:
        return "WRONG ARGUMENT COUNT";
    case NDB_STATCODE_VMPROCPTOOB:
        return "VM PROCESS POINTER OUT-OF-BOUNDS";
    case NDB_STATCODE_READONLY:
        return "READ-ONLY";
    case NDB_STATCODE_NOTIMPLEMENTED:
        return "NOT IMPLEMENTED";
    }
}

/******************************************************************************//******************************************************************************/


