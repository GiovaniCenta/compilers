#include "hash.h"
#include <stdlib.h>
#define _OPEN_SYS_ITOA_EXT
#include <stdio.h>
#include <string.h>
#include "list.h"
#define STR_MAX 100;
//GIOVANI DA SILVA ERE 2021

struct Node *head = NULL;

char *nome_strings[100];
int strj = 1;

HASH_NODE *Table[HASH_SIZE];

char *strings[100];
int str_index = 0;

char str[4] = "str";
char output[50];
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

    if (Lextype != SYMBOL_LIT_STRING)
    {
        if ((newnode = hashFind(text)) != 0)
        {
            return newnode;
        }
    }

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
            printf("Table[%d] has %s with type %d and datatype %d with %d parameters \n", i, node->text, node->type, node->datatype, node->numparam);
}

int hash_check_undeclared(void)
{
    int undeclared = 0;
    HASH_NODE *node;

    for (int i = 0; i < HASH_SIZE; i++)
    {
        for (node = Table[i]; node; node = node->next)
        {

            if (node->type == SYMBOL_IDENTIFIER)
            { //i.e. it was inserted on hash, but didn't received a specific type by semantic.c
                fprintf(stderr, "(hash)Semantic ERROR! Undeclared identifier: %s\n", node->text);
                //fprintf(stderr,"      type:%d\n",node->type);
                ++undeclared;
            }
        }
    }
    return undeclared;
}

HASH_NODE *make_temp()
{
    static int serial = 0;
    char buffer[256] = "";

    sprintf(buffer, "mYWeeirT_emp%d", serial++);
    return hashInsert(buffer, SYMBOL_VARIABLE);
}

HASH_NODE *make_label()
{
    static int serial = 0;
    char buffer[256] = "";

    sprintf(buffer, "mYLabule_%d", serial++);
    hashInsert(buffer, SYMBOL_LABEL);
}

void print_asm(FILE *fout)
{

    fprintf(fout, "\n## DATA SECTION\n"
                  ".data\n");

    HASH_NODE *node;
    for (int i = 0; i < HASH_SIZE; i++)
    {
        for (node = Table[i]; node; node = node->next)
        {
            if (!search(head, node->text))
            {
                push(&head, node->text);

                switch (node->type)
                {

                case SYMBOL_FUNCTION:
                    fprintf(fout, "_%s_Return: .long\t0\n", node->text);
                    break;
                case SYMBOL_VARIABLE:
                    fprintf(fout, "_%s: .long\t0\n", node->text);
                    break;

                case SYMBOL_VECTOR:
                    fprintf(fout, "_%s: .zero\t400\n", node->text);
                    break;

                case SYMBOL_LIT_INT:
                    fprintf(fout, "_%s: .long\t%s\n", node->text, node->text);
                    break;

                case SYMBOL_LIT_CHAR: //CONVERTER PRA ASCII
                    fprintf(fout, "_%s: \t.byte %s\n", node->text, node->text);
                    break;

                case SYMBOL_PARAMETER:

                    fprintf(fout, "_%s: .long\t0\n", node->text);
                    break;

                case SYMBOL_LIT_STRING:
                    printf("\n");
                    char out[50];
                    stpcpy(out,node->text);
                    str_treatment(node->text);
                    if(string_already(node->text) == 0){
                    strings[str_index] = node->text;
                    str_index++;
                    fprintf(fout, "_%s: .string\t%s\n", node->text, out);
                    }
                    break;

                
                default:
                    break;
                }
            }
        }
    }
    //rintList(head);

    fprintf(fout, ".section .rodata\n");
}

int string_already(char *str)
{
    int i;
    for (i = 0; i < 100; i++)
    {
        if (strings[i])
        {
            if (strcmp(strings[i], str) == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}


 void str_treatment(char* str_in){
                    char *string1;
                    string1 = malloc(sizeof(str_in)); 
                    strcpy(string1, str_in);

                    //printf("\nstring antes da remocao de espaco: %s\n", string1);

                   //remover espaços   oook
                    char *str = str_in;

                    char *write = str, *read = str;
                    do
                    {
                        if (*read != ' ')
                            *write++ = *read;
                    } while (*read++);
                    //printf("\nstring dps da remocao de espaco: %s\n", str);
                   

                    

                    //trocar /n por barra n

                char *str1 = str_in;

                    char *write1 = str1, *read1 = str1;
                    do
                    {
                        if (*read1 != '\\')
                            *write1++ = *read1;
                    } while (*read1++);
                    //printf("\nstring dps da remocao de barra: %s\n", str1);


                char *str2 = str_in;

                    char *write2 = str2, *read2 = str2;
                    do
                    {
                        if (*read2 != '\"')
                            *write2++ = *read2;
                    } while (*read2++);
                    //printf("\nstring dps da remocao de aspas: %s\n", str2);

                return str2;
                    }

