//AST - Abstract Syntax Tree

#include "hash.h"

#ifndef AST_HEADER
#define AST_HEADER

#define MAX_SONS 4

#define AST_SYMBOL 1

#define AST_ADD 2
#define AST_SUB 3
#define AST_MUL 4
#define AST_DIV 5
#define AST_EQ 6
#define AST_GE 7
#define AST_LE 8
#define AST_DIF 9
#define AST_GRE 10
#define AST_LES 11
#define AST_AND 12
#define AST_OR 13
#define AST_NOT 14

#define AST_ATTR 15
#define AST_VEC_ATTR 16
#define AST_VEC_SYMBOL 17
#define AST_LCMD 18

#define AST_IF 19
#define AST_IF_ELSE 20
#define AST_UNTIL 21

#define AST_PRINT 23
#define AST_READ 24
#define AST_RETURN 25

#define AST_EXP_LIST 26
#define AST_LIT_LIST 27
#define AST_PROGRAM 28
#define AST_FUNC_LIST 29
#define AST_FUNC 30



#define AST_BLOCK 31


#define AST_INT 33
#define AST_FLOAT 34
#define AST_CHAR 35

#define AST_DEC_LIST 36
#define AST_VAR_DEC 37
#define AST_VEC_DEC 38


#define AST_PARAMETER 40
#define AST_PARAMETER_LIST 41

#define AST_DATA 42
#define AST_COMEFROM 43

#define AST_FUNCTION_CALL 44
#define AST_DECL_BLOCK 45

#define AST_VEC_DEC_RANGE 46
#define AST_FLOW_CONTROL 47
#define AST_IDENLIT 48
#define AST_IDEN 49
#define AST_PARENTHESIS 50
typedef struct astnode
{
    int type;
    HASH_NODE *symbol;
    struct astnode *son[MAX_SONS];
} AST;

AST *astCreate(int type, HASH_NODE *symbol, AST* s0, AST* s1, AST* s2, AST* s3);
void astPrint(AST *node, int level);

#endif

// END OF FILE