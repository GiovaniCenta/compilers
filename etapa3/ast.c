//AST - Abstract Syntax Tree

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

AST *astCreate(int type, HASH_NODE *symbol, AST* s0, AST* s1, AST* s2, AST* s3){

    AST* newNode;
    newNode = (AST*) calloc(1, sizeof(AST));
    newNode->type = type;
    newNode->symbol = symbol;
    newNode->son[0] = s0;
    newNode->son[1] = s1;
    newNode->son[2] = s2;
    newNode->son[3] = s3;

    return newNode;
}

void astPrint(AST *node, int level){
    if (node == 0)
        return;
    
    int i;

    for (i=0; i<level; i++)
        fprintf(stderr, "--");

    fprintf(stderr, "\nTYPE: ");
    switch(node->type){
        case AST_SYMBOL: fprintf(stderr, "AST_SYMBOL"); break;
        case AST_ADD: fprintf(stderr, "AST_ADD"); break;
        case AST_SUB: fprintf(stderr, "AST_SUB"); break;
        case AST_MUL: fprintf(stderr, "AST_MUL"); break;
        case AST_DIV: fprintf(stderr, "AST_DIV"); break;
        case AST_EQ: fprintf(stderr, "AST_EQ"); break;
        case AST_GE: fprintf(stderr, "AST_GE"); break;
        case AST_LE: fprintf(stderr, "AST_LE"); break;
        case AST_DIF: fprintf(stderr, "AST_DIF"); break;
        case AST_GRE: fprintf(stderr, "AST_GRE"); break;
        case AST_LES: fprintf(stderr, "AST_LES"); break;
        case AST_AND: fprintf(stderr, "AST_AND"); break;
        case AST_OR: fprintf(stderr, "AST_OR"); break;
        case AST_NOT: fprintf(stderr, "AST_NOT"); break;
        case AST_VEC_SYMBOL: fprintf(stderr, "AST_VEC_SYMBOL"); break;
        case AST_ATTR: fprintf(stderr, "AST_ATTR"); break;
        case AST_VEC_ATTR: fprintf(stderr, "AST_VEC_ATTR"); break;
        case AST_LCMD: fprintf(stderr, "AST_LCMD"); break;
        case AST_IF: fprintf(stderr, "AST_IF"); break;
        case AST_IF_ELSE: fprintf(stderr, "AST_IF_ELSE"); break;
        case AST_PRINT: fprintf(stderr, "AST_PRINT"); break;
        case AST_READ: fprintf(stderr, "AST_READ"); break;
        case AST_RETURN: fprintf(stderr, "AST_RETURN"); break;

        

        case AST_EXP_LIST : fprintf(stderr, "AST_EXP_LIST"); break;
        case AST_LIT_LIST : fprintf(stderr, "AST_LIT_LIST"); break;
        case AST_PROGRAM : fprintf(stderr, "AST_PROGRAM"); break;
        case AST_FUNC_LIST : fprintf(stderr, "AST_FUNC_LIST"); break;
        case AST_FUNC : fprintf(stderr, "AST_FUNC"); break;

        case AST_UNTIL: fprintf(stderr, "AST_UNTIL"); break;
        case AST_PARAMETER : fprintf(stderr, "AST_PARAMETER"); break;
        case AST_PARAMETER_LIST : fprintf(stderr, "AST_PARAMETER_LIST"); break;

        case AST_DATA : fprintf(stderr, "AST_DATA"); break;
        case AST_COMEFROM : fprintf(stderr, "AST_COMEFROM"); break;
        
        case AST_BLOCK: fprintf(stderr, "AST_BLOCK"); break;
        
        case AST_CHAR: fprintf(stderr, "AST_CHAR"); break;
        case AST_INT: fprintf(stderr, "AST_INT"); break;
        case AST_FLOAT: fprintf(stderr, "AST_FLOAT"); break;
        case AST_DECL_BLOCK: fprintf(stderr, "AST_DECL_BLOCK"); break;
        case AST_VAR_DEC: fprintf(stderr, "AST_VAR_DEC"); break;
        case AST_VEC_DEC: fprintf(stderr, "AST_VEC_DEC"); break;
        case AST_VEC_DEC_RANGE: fprintf(stderr, "AST_VEC_DEC_RANGE"); break;

        case AST_IDENLIT :fprintf(stderr,"AST_IDENLIT");break;
        case AST_IDEN :fprintf(stderr,"AST_IDEN");break;
        case AST_PARENTHESIS :fprintf(stderr,"AST_PARENTHESIS");break;

        case AST_FLOW_CONTROL:fprintf(stderr,"AST_FLOW_CONTROL");break;

        case AST_FUNCTION_CALL: fprintf(stderr, "AST_FUNCTION_CALL"); break;


       
        
        
        default: fprintf(stderr, "AST_UNKNOWN"); break;
    }

    if (node->symbol != 0)
        fprintf(stderr, "\nsymbol= %s\n", node->symbol->text);
    else
        fprintf(stderr, ",0\n");

    for (i=0; i<MAX_SONS; ++i){
        printf("\nson[%d] = ",i);
        astPrint(node->son[i], level+1);
    }

}