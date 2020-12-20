
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "mld.h"

#define OFFSETOF(struct_name, fld_name)     \
    (unsigned long)&(((struct_name *)0)->fld_name)

typedef struct emp_ {

    char emp_name[30];

    unsigned int emp_id;

    unsigned int age;

    struct emp_ *mgr;

    float salary;

}emp_t;

void Fill_Up(struct_db_rec_t *record){

    record->next = NULL;
    strcpy(record->struct_name, "emp_t");
    record->ds_size = sizeof(emp_t);
    record->n_fields = 5;
    record->fields = (field_info_t *) malloc(sizeof(field_info_t));



    strcpy(record->fields[0].fname, "emp_t");
    record->fields[0].size = (unsigned int) sizeof(char) * 30;
    record->fields[0].offset = 0;
    record->fields[0].dtype = CHAR;
    memset(record->fields[0].nested_str_name, '\0', sizeof(record->fields[0].nested_str_name));

    strcpy(record->fields[1].fname, "emp_id");
    record->fields[1].size = (unsigned int) sizeof(unsigned int);
    record->fields[1].offset = record->fields[0].offset + record->fields[0].size;
    record->fields[1].dtype = UINT32;
    memset(record->fields[1].nested_str_name, '\0', sizeof(record->fields[1].nested_str_name));

    strcpy(record->fields[2].fname, "age");
    record->fields[2].size = (unsigned int) sizeof(unsigned int);
    record->fields[2].offset = record->fields[1].offset + record->fields[1].size;;
    record->fields[2].dtype = UINT32;
    memset(record->fields[2].nested_str_name, '\0', sizeof(record->fields[2].nested_str_name));

    strcpy(record->fields[3].fname, "mgr");
    record->fields[3].size = (unsigned int) sizeof(void *);
    record->fields[3].offset = record->fields[2].offset + record->fields[2].size;;
    record->fields[3].dtype = OBJ_PTR;
    strcpy(record->fields[3].nested_str_name, "emp_t");

    strcpy(record->fields[4].fname, "salary");
    record->fields[4].size = (unsigned int) sizeof(float);
    record->fields[4].offset = record->fields[3].offset + record->fields[3].size;;
    record->fields[4].dtype = FLOAT;
    memset(record->fields[4].nested_str_name, '\0', sizeof(record->fields[4].nested_str_name));

}


int main(int argc, char *argv[]){

    struct_db_rec_t record;
    int amount = 0;
    Fill_Up(&record);   // Assing the information to memory record

    printf("\tThe size of emp_t        : %d\n\n", record.ds_size);

    while(amount < 5){
        printf("\tFiled[%d].fname           : %s\n", amount, record.fields[amount].fname);
        printf("\tFiled[%d].size            : %d\n", amount, record.fields[amount].size);
        printf("\tFiled[%d].offset          : %d\n", amount, record.fields[amount].offset);        
        printf("\tFiled[%d].dtype           : %d\n", amount, record.fields[amount].dtype);
        if(strlen(record.fields[amount].nested_str_name) != 0){
            printf("\tFiled[%d].nested_str_name : %s\n", amount, record.fields[amount].nested_str_name);        
        }else{
            printf("\tField[%d] is null\n", amount);
        }
        printf("\n");
        // printf("OFFSETOF[%d] : %ld\n", amount, OFFSETOF(struct_db_rec_t, fields[amount].fname));                
        amount++;
    }

}


/*

To compute the size of a field and offset of a field in a given C structure, we should write C macros.



A macro to compute the offset of a field 'fld_name' in a C structure 'struct_name' will be :

#define OFFSETOF(struct_name, fld_name) \

         (unsigned int)&(((struct_name *)0)->fld_name)



A macro to compute the size of a field 'fld_name' in a C structure 'struct_name' will be :

#define FIELD_SIZE(struct_name, fld_name) \

       sizeof(((struct_name *)0)->fld_name)



You will be using such macros in system programming very often.

*/