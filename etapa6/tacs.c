#include "tacs.h"
#include <string.h>
#include "list.h"

//GIOVANI DA SILVA ERE 2021
char buffer_vector[256];
char serial[256];
char* buffer2;
int g = 0;
int h =0;
char buffer3[256][100];
char buffer4[256][100];

int l = 0;
char vector_name[256];


TAC *create_tac_if(TAC *code0, TAC *code1);
TAC *create_tac_if_else(TAC *code0, TAC *code1, TAC *code2);
TAC *create_tac_until(TAC *code0, TAC *code1);

TAC *tac_create(int type, HASH_NODE *res, HASH_NODE *op1, HASH_NODE *op2)
{

    TAC *new_tac = 0;
    new_tac = (TAC *)calloc(1, sizeof(TAC));
    new_tac->type = type;
    new_tac->res = res;
    new_tac->op1 = op1;
    new_tac->op2 = op2;
    new_tac->prev = 0;
    new_tac->next = 0;

    return new_tac;
}

TAC *create_tac_op(int tac_type, TAC *code0, TAC *code1, AST *node)
{
    HASH_NODE *aux2;
    aux2 = (HASH_NODE *)calloc(1, sizeof(HASH_NODE));
    //astPrint(node->son[0], 0);
    if (node->son[0]->type == AST_VEC_SYMBOL)
    {
        aux2->text = node->son[0]->son[0]->symbol->text;

        return tac_join(tac_join(code0, code1),
                        tac_create(tac_type, make_temp(), aux2, code1 ? code1->res : 0));
    }

     else if (node->son[1]->type == AST_VEC_SYMBOL)
    {
        aux2->text = node->son[1]->son[0]->symbol->text;

        return tac_join(tac_join(code0, code1),
                        tac_create(tac_type, make_temp(), aux2, code1 ? code1->res : 0));
    }

    else return tac_join(tac_join(code0, code1),
                    tac_create(tac_type, make_temp(), code0 ? code0->res : 0, code1 ? code1->res : 0));
}

void tac_print(TAC *tac)
{

    if (!tac)
        return;

    if (tac->type == TAC_SYMBOL)
        return;
    fprintf(stderr, "TAC(");

    switch (tac->type)
    {
    case TAC_SYMBOL:
        fprintf(stderr, "TAC_SYMBOL");
        break;

        //case TAC_RETURN:
        //fprintf(stderr, "TAC_RETURN");
        // break;
    case TAC_ADD:
        fprintf(stderr, "TAC_ADD");
        break;
    case TAC_SUB:
        fprintf(stderr, "TAC_SUB");
        break;
    case TAC_MUL:
        fprintf(stderr, "TAC_MUL");
        break;
    case TAC_DIV:
        fprintf(stderr, "TAC_DIV");
        break;
    case TAC_EQ:
        fprintf(stderr, "TAC_EQ");
        break;
    case TAC_GE:
        fprintf(stderr, "TAC_GE");
        break;
    case TAC_LE:
        fprintf(stderr, "TAC_LE");
        break;
    case TAC_DIF:
        fprintf(stderr, "TAC_DIF");
        break;
    case TAC_GRE:
        fprintf(stderr, "TAC_GRE");
        break;
    case TAC_LES:
        fprintf(stderr, "TAC_LES");
        break;
    case TAC_AND:
        fprintf(stderr, "TAC_AND");
        break;
    case TAC_OR:
        fprintf(stderr, "TAC_OR");
        break;
    case TAC_NOT:
        fprintf(stderr, "TAC_NOT");
        break;
    case TAC_IFZ:
        fprintf(stderr, "TAC_IFZ");
        break;

    case TAC_IF:
        fprintf(stderr, "TAC_IF");
        break;
    case TAC_LABEL:
        fprintf(stderr, "TAC_LABEL");
        break;
    case TAC_UNTIL:
        fprintf(stderr, "TAC_UNTIL");
        break;
    case TAC_JUMP:
        fprintf(stderr, "TAC_JUMP");
        break;
    case TAC_PRINT:
        fprintf(stderr, "TAC_PRINT");
        break;
    case TAC_READ:
        fprintf(stderr, "TAC_READ");
        break;
    case TAC_RET:
        fprintf(stderr, "TAC_RET");
        break;
    case TAC_FUNCTION_CALL:
        fprintf(stderr, "TAC_FUNCTION_CALL");
        break;
    case TAC_PARAMETER:
        fprintf(stderr, "TAC_PARAMETER");
        break;

    case TAC_PARAMETER_LIST:
        fprintf(stderr, "TAC_PARAMETER_LIST");
        break;
    case TAC_BEGINFUN:
        fprintf(stderr, "TAC_BEGINFUN");
        break;
    case TAC_ENDFUN:
        fprintf(stderr, "TAC_ENDFUN");
        break;

    case TAC_MOVE:
        fprintf(stderr, "TAC_MOVE");
        break;

    case TAC_MOVE_VECTOR:
        fprintf(stderr, "TAC_MOVE_VECTOR");
        break;

    case TAC_DECL_VECTOR:
        fprintf(stderr, "TAC_DECL_VECTOR");
        break;

    default:
        fprintf(stderr, "TAC_UNKNOWN");
        break;
    }

    fprintf(stderr, ", %s", (tac->res) ? tac->res->text : "0");
    fprintf(stderr, ", %s", (tac->op1) ? tac->op1->text : "0");
    fprintf(stderr, ", %s", (tac->op2) ? tac->op2->text : "0");

    fprintf(stderr, ")\n");
}

void tac_print_backwards(TAC *tac)
{

    if (!tac)
        return;

    else
    {
        tac_print_backwards(tac->prev);
        tac_print(tac);
    }
    return;
}

TAC *tac_join(TAC *l1, TAC *l2)
{

    TAC *point;

    if (!l1)
        return l2;
    if (!l2)
        return l1;

    for (point = l2; point->prev != 0; point = point->prev)
        ; // do nothing, what we are interested in is terminate pointing to the last tac

    point->prev = l1;
    return l2;
}

TAC *generate_code(AST *node)
{
    HASH_NODE *aux;
        aux = (HASH_NODE *)calloc(1, sizeof(HASH_NODE));

    TAC *result = 0;
    TAC *code[MAX_SONS];

    if (!node)
        return 0;

    // PROCESS CHILDREN
    for (int i = 0; i < MAX_SONS; i++)
        code[i] = generate_code(node->son[i]);

    // PROCESS THIS NODE

    switch (node->type)
    {

    case AST_SYMBOL:
        result = tac_create(TAC_SYMBOL, node->symbol, 0, 0);
        break;

    case AST_SYMBOL_INT ... AST_SYMBOL_STRING:
        result = tac_create(TAC_SYMBOL, node->symbol, 0, 0);
        break;

    case AST_ADD ... AST_OR:

        result = create_tac_op(node->type, code[0], code[1], node);
        break;

    case AST_NOT:
        result = tac_join(tac_join(code[0], code[1]), tac_create(TAC_NOT, make_temp(), code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0));
        break;

    case AST_READ:
        result = tac_create(TAC_READ, node->symbol, 0, 0);
        break;
    case AST_RETURN:

        result = tac_join(code[0], tac_create(TAC_RET, node->symbol, code[0] ? code[0]->res : 0, 0));
        break;

    case AST_IF:

        if (code[0])
            result = create_tac_if(code[0], code[1]);
        break;

    case AST_IF_ELSE:
        result = create_tac_if_else(code[0], code[1], code[2]);
        break;
    case AST_UNTIL:
        result = create_tac_until(code[0], code[1]);
        break;

    case AST_PRINT:
        astPrint(node->son[0]->son[0]->son[3],0);
        HASH_NODE *aux3;
        aux3 = (HASH_NODE *)calloc(1, sizeof(HASH_NODE));
        if(node->son[0]->son[0]->son[3]){
            printf("\nentro aqui\n");
        if(node->son[0]->son[0]->son[3]->type == AST_VEC_SYMBOL){
            printf("\nentro aqui 2 \n");
            aux3->text = node->son[0]->son[0]->son[3]->son[0]->symbol->text;
            result = tac_join(tac_create(TAC_PRINT, aux3, 0, 0), code[1]);
            break;
        }
        else
        {
            result = tac_join(tac_create(TAC_PRINT, code[0] ? code[0]->res : 0, 0, 0), code[1]);
        }
       
        }
         break;
        
        

    case AST_FUNCTION_CALL:
        // node->son[1]->son[0]?node->son[1]->son[0]->symbol:0

        //result = tac_join(code[1],tac_join(tac_create(TAC_FUNCTION_CALL,code[0] ? code[0]->res : 0, 0,0),0));
        result = tac_join(tac_join(code[1], tac_join(code[2], tac_create(TAC_FUNCTION_CALL, make_temp(), node->son[0]->symbol, 0))), code[0]);

        break;

    case AST_PARAMETER:
        //result = tac_join(code[0],tac_create(TAC_PARAMETER, 0, code[1] ? code[1]->res : 0, code[2] ? code[2]->res : 0));
        //result = tac_join(code[0], tac_create(TAC_PARAMETER, code[1]?code[1]->res:0, node->son[0]->symbol, 0));
        result = tac_join(tac_join(code[0], tac_create(TAC_PARAMETER, code[1] ? code[1]->res : 0, code[0] ? code[0]->res : 0, 0)), code[1]);
        break;

    case AST_FUNC:

        if (strcmp(node->son[0]->symbol->text, "main") != 0)
        { //
            result = tac_join(tac_join(tac_join(tac_create(TAC_BEGINFUN, node->son[0]->symbol, 0, 0), code[1]), code[2]), tac_join(code[3],
                                                                                                                                   tac_create(TAC_ENDFUN, node->son[0]->symbol, 0, 0)));
            break;
        }
        else
        {
            result = tac_join(tac_join(tac_create(TAC_BEGINFUN, node->son[0]->symbol, 0, 0), code[1]),
                              tac_create(TAC_ENDFUN, node->son[0]->symbol, 0, 0));
        }
        break;

    case AST_ATTR:
        result = tac_join(code[1], tac_create(TAC_MOVE, node->son[0]->symbol, code[1] ? code[1]->res : 0, 0));
        break;

    case AST_VAR_DEC:
        result = tac_join(code[0], tac_create(TAC_MOVE, node->son[1]->symbol, code[2] ? code[2]->res : 0, 0));
        break;

    case AST_VEC_DEC:
        if (!node->son[2])
        {

            result = tac_join(code[0], tac_create(TAC_DECL_VECTOR, node->son[1]->symbol, code[0] ? code[0]->res : 0, 0));
        }
        else
        {

            result = tac_join(tac_create(TAC_DECL_VECTOR, node->son[1]->symbol, code[0] ? code[0]->res : 0, 0), code[1]);
            // note: when reaching AST_VEC_DEC the TAC_MOVE will receive it's symbol and index

            break;
        }
        break;

    case AST_VEC_DEC_RANGE:
        if (!node->son[2])
        {

            result = tac_join(code[0], tac_create(TAC_DECL_VECTOR, node->son[1]->symbol, code[0] ? code[0]->res : 0, 0));
        }
        else
        {
            
            result = tac_join(tac_create(TAC_DECL_VECTOR, node->son[1]->symbol, code[0] ? code[0]->res : 0, 0), code[1]);
            // note: when reaching AST_VEC_DEC the TAC_MOVE will receive it's symbol and index

            break;
        }
        break;

    case AST_VEC_ATTR:
      
         
        
        if(l==0){
            strcpy(buffer_vector, node->son[0]->symbol->text);
            strcpy(vector_name,buffer_vector);
            
            //l++;
        }
        strcpy(serial, node->son[1]->symbol->text);

        printf("\nserial:%s\n",serial);
        printf("\nvector_name:%s\n",vector_name);
        
        
        

        sprintf(buffer3[g], "%s[%s]", vector_name, serial);
        printf("\nbuffer3[%d]:%s\n",g,buffer3[g]);
        strcpy(buffer4[h],buffer3[g]);
        
        if(h == 0){
            printf("\nh = 0\n");
        node->son[0]->symbol->text = buffer4[0];
        }
        else if(h == 1){
            printf("\nh = 1\n");
        node->son[0]->symbol->text = buffer4[1];
        }
        else{
            printf("\nh = 2\n");
        node->son[0]->symbol->text = buffer4[2];
        }
        
        aux->text = buffer3[g];
        node->son[0]->symbol = aux;
        h++;
        g++;
        
        

        result = tac_join(code[2],
                          tac_create(TAC_MOVE_VECTOR, aux, code[1] ? code[1]->res : 0, code[2] ? code[2]->res : 0));
        //result = code[2];
    
      
        break;

    default:
        result = tac_join(code[0], tac_join(code[1], tac_join(code[2], code[3])));
        break;
    }

    return result;
}

TAC *create_tac_if(TAC *code0, TAC *code1)
{

    TAC *jumptac = 0;
    TAC *labeltac = 0;
    HASH_NODE *newlabel = 0;

    newlabel = make_label();

    jumptac = tac_create(TAC_IFZ, newlabel, code0 ? code0->res : 0, 0);
    jumptac->prev = code0;
    labeltac = tac_create(TAC_LABEL, newlabel, 0, 0);
    labeltac->prev = code1;

    return tac_join(jumptac, labeltac);
}

TAC *create_tac_if_else(TAC *code0, TAC *code1, TAC *code2)
{

    TAC *jumpz_tac = 0;
    TAC *jump_tac = 0;

    TAC *label_else_tac = 0;
    TAC *label_after_else_tac = 0;

    HASH_NODE *label_else = 0;
    HASH_NODE *label_after_else = 0;

    label_else = make_label();
    label_after_else = make_label();

    jumpz_tac = tac_create(TAC_IFZ, label_else, code0 ? code0->res : 0, 0);
    jumpz_tac->prev = code0;

    jump_tac = tac_create(TAC_JUMP, label_after_else, 0, 0);
    jump_tac->prev = code1;

    label_else_tac = tac_create(TAC_LABEL, label_else, 0, 0);
    label_else_tac->prev = jump_tac;

    label_after_else_tac = tac_create(TAC_LABEL, label_after_else, 0, 0);
    label_after_else_tac->prev = code2;

    tac_join(jumpz_tac, jump_tac);
    return tac_join(label_else_tac, label_after_else_tac);
}

TAC *create_tac_until(TAC *code0, TAC *code1)
{

    TAC *jumpz = 0;
    TAC *jump = 0;

    TAC *label_before_tac = 0;
    TAC *label_after_tac = 0;

    HASH_NODE *label_before = 0;
    HASH_NODE *label_after = 0;
    label_before = make_label();
    label_after = make_label();

    label_before_tac = tac_create(TAC_LABEL, label_before, 0, 0);
    tac_join(label_before_tac, code0);

    jumpz = tac_create(TAC_IF, label_after, code0 ? code0->res : 0, 0);
    jumpz->prev = code0;

    jump = tac_create(TAC_JUMP, label_before, 0, 0);
    jump->prev = code1;

    label_after_tac = tac_create(TAC_LABEL, label_after, 0, 0);
    label_after_tac->prev = jump;

    tac_join(jumpz, jump);
    return label_after_tac;
}

TAC *tac_reverse(TAC *tac)
{

    TAC *t = tac;
    for (t = tac; t->prev; t = t->prev)
        t->prev->next = t;
    return t;
}