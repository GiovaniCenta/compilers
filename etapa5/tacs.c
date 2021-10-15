#include "tacs.h"
#include <string.h>


// used to know how many init values were
// given for the vector declaration
int vec_init_i = 0;


TAC* tac_create(int type, HASH_NODE* res, HASH_NODE* op1, HASH_NODE* op2){

    TAC* new_tac=0;
    new_tac = (TAC*) calloc(1,sizeof(TAC));
    new_tac->type = type;
    new_tac->res = res;
    new_tac->op1 = op1;
    new_tac->op2 = op2;
    new_tac->prev = 0;
    new_tac->next = 0;

    return new_tac;
}


void tac_print(TAC* tac){

    if (!tac)
        return;

    if (tac->type == TAC_SYMBOL) return;
    //fprintf(stderr, "TAC(");

    switch (tac->type){
    case TAC_SYMBOL:
        fprintf(stderr, "TAC_SYMBOL"); break;
    case TAC_ADD:
        fprintf(stderr, "TAC_ADD"); break;
    case TAC_SUB:
        fprintf(stderr, "TAC_SUB"); break;
    case TAC_MUL:
        fprintf(stderr, "TAC_MUL"); break;
    case TAC_DIV:
        fprintf(stderr, "TAC_DIV"); break;
    case TAC_EQ:
        fprintf(stderr, "TAC_EQ"); break;
    case TAC_GE:
        fprintf(stderr, "TAC_GE"); break;
    case TAC_LE:
        fprintf(stderr, "TAC_LE"); break;
    case TAC_DIF:
        fprintf(stderr, "TAC_DIF"); break;
    case TAC_GRE:
        fprintf(stderr, "TAC_GRE"); break;
    case TAC_LES:
        fprintf(stderr, "TAC_LES"); break;
    case TAC_AND:
        fprintf(stderr, "TAC_AND"); break;
    case TAC_OR:
        fprintf(stderr, "TAC_OR"); break;
    case TAC_NOT:
        fprintf(stderr, "TAC_NOT"); break;
    case TAC_IFZ:
        fprintf(stderr, "TAC_IFZ"); break;
    case TAC_LABEL:
        fprintf(stderr, "TAC_LABEL"); break;
    case TAC_JUMP:
        fprintf(stderr, "TAC_JUMP"); break;
    case TAC_PRINT:
        fprintf(stderr, "TAC_PRINT"); break;
    case TAC_READ:
        fprintf(stderr, "TAC_READ"); break;
    case TAC_RET:
        fprintf(stderr, "TAC_RET"); break;
    case TAC_CALL:
        fprintf(stderr, "TAC_CALL"); break;
    case TAC_ARG:
        fprintf(stderr, "TAC_ARG"); break;
    case TAC_BEGINFUN:
        fprintf(stderr, "TAC_BEGINFUN"); break;
    case TAC_ENDFUN:
        fprintf(stderr, "TAC_ENDFUN"); break;
    
    case TAC_MOVE:
        fprintf(stderr, "TAC_MOVE"); break;
    
    default: fprintf(stderr, "TAC_UNKNOWN"); break;
    }

    fprintf(stderr,", %s", (tac->res) ? tac->res->text : "0");
    fprintf(stderr,", %s", (tac->op1) ? tac->op1->text : "0");
    fprintf(stderr,", %s", (tac->op2) ? tac->op2->text : "0");

    fprintf(stderr, "\n");

}



void tac_print_backwards(TAC* tac){

    if (!tac)
        return;
    
    else {
        tac_print_backwards(tac->prev);
        tac_print(tac);
    }
    return;
}


TAC* tac_join(TAC* l1, TAC* l2){
    
    TAC* point;

    if (!l1) return l2;
    if (!l2) return l1;

    for (point=l2; point->prev != 0; point = point->prev)
        ; // do nothing, what we are interested in is terminate pointing to the last tac

    point->prev = l1;
    return l2;

}



TAC* generate_code(AST* node){

    TAC* result = 0;
    TAC* code[MAX_SONS];

    if (!node)
        return 0;

    // PROCESS CHILDREN
    for(int i=0; i<MAX_SONS; i++)
        code[i] = generate_code(node->son[i]);


    // PROCESS THIS NODE
    switch (node->type){
    

    case AST_SYMBOL:
        result = tac_create(TAC_SYMBOL,node->symbol,0,0); 
        break;
    
    case AST_SYMBOL_INT ... AST_SYMBOL_STRING:
        result = tac_create(TAC_SYMBOL,node->symbol,0,0); 
        break;
    

    // IMPORTANT NOTE: THE TAC TYPES  VALUE FOR BIN OPERATORS ARE THE SAME
    // FOR THE AST TYPES (AST_ADD == 2 == TAC_ADD)
    case AST_ADD ... AST_OR: 
        result = create_tac_bin_op(node->type, code[0], code[1]);
        break;

    case AST_ATTR:
        result = tac_join(code[0], tac_create(TAC_MOVE, node->symbol, code[0]?code[0]->res:0, 0));
        break;
    
    case AST_VAR_DEC:
        result = tac_join(code[0], tac_create(TAC_MOVE, node->symbol, code[1]?code[1]->res:0, 0));
        break;
    
    case AST_VEC_ATTR: 
        result = tac_join(code[0], 
                    tac_create(TAC_MOVE, node->symbol, code[1]?code[1]->res:0, code[0]?code[0]->res:0));
        break;


    
    
    default: 
        result = tac_join(code[0], tac_join(code[1], tac_join(code[2], code[3])));
        break;


    }



    return result;
}


TAC* create_tac_bin_op(int tac_type, TAC* son1, TAC* son2){

    return tac_join(tac_join(son1, son2),
            tac_create(tac_type, make_temp(), son1?son1->res:0, son2?son2->res:0)); 
}