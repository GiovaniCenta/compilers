#include "hash.h"
#include <stdlib.h>
#include <stdio.h>

HASH_NODE *Table[HASH_SIZE];

void hashInit(void)
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        Table[i] = 0;
    }
}

int hashAddress(char *text)
{

    int address = 1;
    int i;
    for (i = 0; i < strlen(text); ++i)
    {
        address = (address * text[i]) % HASH_SIZE + 1;
    }
    return address - 1;
}

HASH_NODE *hashFind(char *text)
{

    HASH_NODE *node;
    int address = hashAddress(text);

    for (node = Table[address]; node; node = node->next)
    {
        if (strcmp(node->text, text) == 0)
        {
            return node;
        }
    }
    return 0;
}

HASH_NODE *hashInsert(char *text, int Lextype)
{
    HASH_NODE *newnode;
    int nodeAddress = hashAddress(text);

    if ((newnode = hashFind(text)) != 0)
        return newnode;

    newnode = (HASH_NODE *)calloc(1, sizeof(HASH_NODE));
    newnode->type = Lextype;
    newnode->text = (char *)calloc(strlen(text) + 1, sizeof(char));
    strcpy(newnode->text, text);
    newnode->next = Table[nodeAddress];
    Table[nodeAddress] = newnode;
    return newnode;
}

void hashPrint(void)
{

    int i;
    HASH_NODE *node;
    for (i = 0; i < HASH_SIZE; i++)
        for (node = Table[i]; node; node = node->next)
            printf("Table[%d] has %s with type %d and datatype %d with %d parameters \n", i, node->text, node->type,node->datatype,node->numparam);
}

int hash_check_undeclared(void){
    int undeclared = 0;
    HASH_NODE *node;


    for(int i=0; i<HASH_SIZE; i++){
        for(node=Table[i]; node; node=node->next){

            if (node->type == SYMBOL_IDENTIFIER){ //i.e. it was inserted on hash, but didn't received a specific type by semantic.c
                fprintf(stderr, "(hash)Semantic ERROR! Undeclared identifier: %s\n", node->text);
                //fprintf(stderr,"      type:%d\n",node->type);
                ++undeclared;
            }
        }
    }
    return undeclared;
}

HASH_NODE* make_temp(){
    static int serial = 0;
    char buffer[256] = "";

    // NOTE: the goal here is to not colide with user defined identifiers
    // normally, the compiler does that by changing all user identifier names
    // from something like userVar to _userVar. This way it's possible to 
    // distinguish between user defined identifiers and compiler ones 
    sprintf(buffer, "mYWeeirT_emp%d", serial++);
    return hashInsert(buffer, SYMBOL_VARIABLE);
}