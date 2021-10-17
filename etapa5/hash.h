#ifndef HASH_HEADER
#define HASH_HEADER

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 997

#define SYMBOL_LIT_INT 1
#define SYMBOL_LIT_CHAR 2
#define SYMBOL_LIT_STRING 3

#define SYMBOL_IDENTIFIER 7

#define SYMBOL_VARIABLE 8
#define SYMBOL_FUNCTION 9
#define SYMBOL_VECTOR 10
#define SYMBOL_PARAMETER 11
#define SYMBOL_OUT_OF_SCOPE 12
#define SYMBOL_VECTOR_RANGE 13
#define SYMBOL_PARAMETER_LIST 14

#define SYMBOL_LABEL 15
#define SYMBOL_LABEL_LIT 16

#define DATATYPE_INT 1
#define DATATYPE_FLOAT 2
#define DATATYPE_CHAR 3


typedef struct hash_node {

    int type;
    int datatype;
    int numparam;
    char *text;
    char *parameter_function_name;
    struct hash_node * next;

} HASH_NODE;


void hashInit(void);
int hashAddress(char *text);
HASH_NODE *hashFind(char *text);
HASH_NODE *hashInsert(char *text,int Lextype);
void hashPrint(void);
int hash_check_undeclared(void);


HASH_NODE* make_temp();
HASH_NODE* make_label();
#endif
// END
