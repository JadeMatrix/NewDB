#ifndef NDB_VMAPI_H
#define NDB_VMAPI_H

typedef long ndb_vm_integer;
typedef double ndb_vm_float;

typedef long ndb_vm_value_type;
typedef long ndb_vm_statcode;

typedef struct
{
    
} ndb_vm_field;

typedef struct
{
    
} ndb_vm_page;

typedef struct
{
    
} ndb_vm_response;

typedef struct
{
    
} ndb_vm_connection;

typedef struct
{
    ndb_vm_value_type type;
    union
    {
        ndb_vm_integer*    i;
        ndb_vm_float*      d;
        ndb_vm_field*      f;
        ndb_vm_page*       p;
        ndb_vm_response*   r;
        ndb_vm_connection* c;
    } value;
} ndb_vm_value;

typedef ndb_vm_statcode (* ndb_vm_instruction )( ndb_vm_value,
                                                 ndb_vm_value,
                                                 ndb_vm_value );

typedef struct
{
    /* Process pointer */
    long process_ptr;
    
    /* Process array */
    ndb_vm_instruction* query;
    
    /* Registers */
    ndb_vm_integer*    ir;
    ndb_vm_float*      dr;
    ndb_vm_field*      fr;
    ndb_vm_page*       pr;
    ndb_vm_response*   rr;
    ndb_vm_connection* cr;
    
    ndb_vm_integer     dvi;
    ndb_vm_integer     dmi;
    ndb_vm_float       dvd;
} ndb_vm_process;

#endif


