#include "tacs.h"
#include <string.h>

//GIOVANI DA SILVA ERE 2021
int contOpVector = 0;

  

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

TAC *create_tac_op(int tac_type, TAC *code0, TAC *code1,AST *node,HASH_NODE* hashAux3[])
{
     

    if(node->son[0] && node->son[1]){
    
    if(node->son[0]->type == AST_IDEN && node->son[1]->type == AST_IDEN){
        return tac_join(tac_join(code0, code1),
                    tac_create(tac_type, make_temp(), node->son[0]->symbol, node->son[1]->symbol));
    }
    else if(node->son[0]->type == AST_IDEN){
        return tac_join(tac_join(code0, code1),
                    tac_create(tac_type, make_temp(), node->son[0]->symbol, code1 ? code1->res : 0));
    }
    else if(node->son[1]->type == AST_IDEN){
        return tac_join(tac_join(code0, code1),
                    tac_create(tac_type, make_temp(), code0?code0->res:0, node->son[1]->symbol));
    }

   
   

      if(node->son[1]->type == AST_VEC_SYMBOL && node->son[0]->type == AST_VEC_SYMBOL){
       
      
      
      
        sprintf(hashAux3[contOpVector]->text,"%s[%s]",node->son[0]->symbol->text,node->son[0]->son[1]->symbol->text);
      
       sprintf(hashAux3[contOpVector+1]->text,"%s[%s]",node->son[1]->symbol->text,node->son[1]->son[1]->symbol->text);

        return tac_create(tac_type, make_temp(),hashAux3[contOpVector] , hashAux3[contOpVector+1]);
    }



   else if(node->son[0]->type == AST_VEC_SYMBOL){
       
       contOpVector++;
      
       sprintf(hashAux3[contOpVector]->text,"%s[%s]",node->son[0]->symbol->text,node->son[0]->son[1]->symbol->text);
        return tac_create(tac_type, make_temp(), hashAux3[contOpVector], node->son[1]->symbol);
    }
   
    else if(node->son[1]->type == AST_VEC_SYMBOL){
       
        
      
       sprintf(hashAux3[contOpVector]->text,"%s[%s]",node->son[1]->symbol->text,node->son[1]->son[1]->symbol->text);
       contOpVector++;
        return tac_create(tac_type, make_temp(),node->son[0]->symbol , hashAux3[contOpVector]);
    }

  
    

    return tac_join(tac_join(code0, code1),
                    tac_create(tac_type, make_temp(), code0?code0->res:0, code1 ? code1->res : 0));
    }
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

    case TAC_DECL_VAR:
        fprintf(stderr, "TAC_DECL_VAR");
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

    case TAC_PARAMETER_INIT:
        fprintf(stderr, "TAC_PARAMETER_INIT");
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

    int vectorLen = 0;
    int contVector,contVectorPrint = 0;
    HASH_NODE *hashAux[100],*hashAux2[100];
     HASH_NODE *hashAux3[100];
    for (int i = 0; i < 100; i++)
    {
        hashAux[i] = hashCreate();
        hashAux2[i] = hashCreate();
        hashAux3[i] = hashCreate();
    }

    AST *auxVectorAst = 0;

    TAC *result = 0;
    TAC *PrintAux = 0;
    TAC *VectorAux = 0;
    AST *nodeAux2 = 0;
    AST *nodeAux = 0;
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

        result = create_tac_op(node->type, code[0], code[1],node,hashAux3);
        break;

    case AST_NOT:
        result = tac_join(tac_join(code[0], code[1]), tac_create(TAC_NOT, make_temp(), code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0));
        break;

    case AST_READ:
        result = tac_create(TAC_READ, make_temp(), 0, 0);
        break;
    case AST_RETURN:
        
        if(node->son[0]){
            if(node->son[0]->type == AST_PARENTHESIS){
                
                if(node->son[0]->son[3]){
                    
                    if(node->son[0]->son[3]->type == AST_IDEN){
                        astPrint(node->son[0]->son[3],0);
                        
                        result = tac_join(code[0], tac_create(TAC_RET, node->son[0]->son[3]->symbol, code[0] ? code[0]->res : 0, 0));
                        break;

                    }

                }

            }
        result = tac_join(code[0], tac_create(TAC_RET, node->symbol, code[0] ? code[0]->res : 0, 0));
        }
        
        
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
        printf("\n\n");
       

        if(node->son[0]->son[0]->son[3]){ //eh parenthesis
        if(node->son[0]->son[0]->son[3]->type == AST_VEC_SYMBOL){ 
            printf("\noi sou um vetor\n");
            sprintf(hashAux2[contVectorPrint]->text,"%s[%s]",node->son[0]->son[0]->son[3]->symbol->text,node->son[0]->son[0]->son[3]->son[1]->symbol->text);
            
             result =  tac_join(tac_join(code[0], tac_create(TAC_PRINT, hashAux2[contVectorPrint], 0, 0)), code[1]);
             contVectorPrint++;
             break;

        }
        else if(node->son[0]->son[0]->son[3]->type == AST_ADD ||node->son[0]->son[0]->son[3]->type == AST_SUB || node->son[0]->son[0]->son[3]->type == AST_MUL)
           { 
            
            result =  tac_join(tac_join(code[0], tac_create(TAC_PRINT, code[0] ? code[0]->res : 0, 0, 0)), code[1]);
            break;
        }

        }
        if (node->son[0]->son[1] == 0)
        {
            printf("\noie\n");
            astPrint(node->son[0]->son[0]->son[3],0);
            result =  tac_join(tac_join(code[0], tac_create(TAC_PRINT, node->son[0]->son[0]->son[3]->symbol, 0, 0)), code[1]);
            break;
        }

        else
        {
            
            PrintAux = tac_join(tac_join(tac_join(tac_create(TAC_PRINT, node->son[0]->son[0]->symbol, 0, 0), code[1]), code[2]), tac_join(code[3],
                                                                                                                                          tac_create(TAC_PRINT, node->son[0]->son[1]->son[0]->symbol, 0, 0)));

            nodeAux = node->son[0]->son[1];
            while (nodeAux)
            {
                /*if(node->son[0]->son[1]->son[1]){
        PrintAux = tac_join(PrintAux,tac_create(TAC_PRINT, node->son[0]->son[1]->son[1]->son[0]->symbol, 0, 0));
        

    }
    */
                if (nodeAux->son[1])
                {
                    PrintAux = tac_join(PrintAux, tac_create(TAC_PRINT, nodeAux->son[1]->son[0]->symbol, 0, 0));
                }

                nodeAux = nodeAux->son[1];
                printf("\n\n");
            }
        }
        result = PrintAux;

        // result = tac_join(tac_join(code[1], tac_create(TAC_PRINT, node->son[0]->son[0]->symbol, code[0] ? code[0]->res : 0, 0)), code[0]);
        //result = tac_join(code[0],tac_join(tac_create(TAC_PRINT, code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0, 0), code[1]));
        break;

    case AST_FUNCTION_CALL:
        // node->son[1]->son[0]?node->son[1]->son[0]->symbol:0

        //result = tac_join(code[1],tac_join(tac_create(TAC_FUNCTION_CALL,code[0] ? code[0]->res : 0, 0,0),0));
        
        
        result = tac_join(tac_join(code[1], tac_join(code[2], tac_create(TAC_FUNCTION_CALL, make_temp(),  node->symbol, 0))), code[0]);
        
        //result = tac_join(tac_join(code[0], tac_create(TAC_FUNCTION_CALL, make_temp(), node->son[0]->symbol, 0)),code[1]);
        //result = tac_join(code[0], tac_create(TAC_FUNCTION_CALL,make_temp(),node->symbol,0));
        break;

    case AST_PARAMETER:
        //result = tac_join(code[0],tac_create(TAC_PARAMETER, 0, code[1] ? code[1]->res : 0, code[2] ? code[2]->res : 0));
        //result = tac_join(code[0], tac_create(TAC_PARAMETER, code[1]?code[1]->res:0, node->son[0]->symbol, 0));
        result = tac_join(tac_join(code[0], tac_create(TAC_PARAMETER, node->symbol, code[0] ? code[0]->res : 0, 0)), code[1]);
        break;

    case AST_PARAMETER_INIT:
        result = tac_join(tac_join(code[0], tac_create(TAC_PARAMETER, node->symbol, code[0] ? code[0]->res : 0, 0)), code[1]);
        break;

    case AST_FUNC:

        if (strcmp(node->symbol->text, "main") != 0)
        { //
            result = tac_join(tac_join(tac_join(tac_create(TAC_BEGINFUN, node->symbol, 0, 0), code[1]), code[2]), tac_join(code[3],
                                                                                                                           tac_create(TAC_ENDFUN, node->symbol, 0, 0)));
            break;
        }
        else
        {
            result = tac_join(tac_join(tac_create(TAC_BEGINFUN, node->symbol, 0, 0), code[1]),
                              tac_create(TAC_ENDFUN, node->symbol, 0, 0));
        }
        break;

    case AST_ATTR:
        result = tac_join(code[1], tac_create(TAC_MOVE, node->symbol, code[1] ? code[1]->res : 0, 0));
        break;

    case AST_VAR_DEC:

        result = tac_join(code[0], tac_create(TAC_DECL_VAR, node->symbol, code[2] ? code[2]->res : 0, 0));

        break;

    case AST_VEC_DEC:

        if (!node->son[2])
        { //caso que nao inicia parametros
            VectorAux = tac_join(code[0], tac_create(TAC_DECL_VECTOR, node->symbol, node->son[1]->symbol, 0));
        }
        else
        {

            if (node->son[2]->son[1] == 0)
            {
                vectorLen = atoi(node->son[1]->symbol->text);
                VectorAux = tac_join(code[0], tac_create(TAC_DECL_VECTOR, node->symbol, node->son[1]->symbol, node->son[2]->son[0]->symbol));
            }
            else
            {
                vectorLen = atoi(node->son[1]->symbol->text);
                contVector = 0;
                sprintf(hashAux[contVector]->text, "%d", contVector);

                //sprintf(node->son[1]->symbol->text, "%d", contVector);

                VectorAux = tac_join(code[0], tac_create(TAC_DECL_VECTOR, node->symbol, hashAux[contVector], node->son[2]->son[0]->symbol));

                /*
               
                if (node->son[2]->son[1])
                {
                    contVector++;
                    sprintf(hashAux[contVector]->text, "%d", contVector);
                    VectorAux = tac_join(VectorAux, tac_create(TAC_DECL_VECTOR, node->symbol, hashAux[contVector], node->son[2]->son[1]->son[0]->symbol));
                }
*/
               auxVectorAst = node->son[2]->son[1];
               
                while (auxVectorAst)
                {
                    /*if(node->son[0]->son[1]->son[1]){
        PrintAux = tac_join(PrintAux,tac_create(TAC_PRINT, node->son[0]->son[1]->son[1]->son[0]->symbol, 0, 0));
        

    }
    */
                    if (auxVectorAst->son[0])
                    {
                       
                        contVector++;
                        sprintf(hashAux[contVector]->text, "%d", contVector);
                        VectorAux = tac_join(VectorAux, tac_create(TAC_DECL_VECTOR, node->symbol, hashAux[contVector], auxVectorAst->son[0]->symbol));
                    }

                    auxVectorAst = auxVectorAst->son[1];
                    printf("\n\n");
                }
            }
        
    }

    result = VectorAux;
    break;

case AST_VEC_DEC_RANGE:
    if (!node->son[2])
    {

        result = tac_join(code[0], tac_create(TAC_DECL_VECTOR_RANGE, node->symbol, code[0] ? code[0]->res : 0, 0));
    }
    else
    {

        result = tac_join(tac_create(TAC_DECL_VECTOR, node->symbol, code[0] ? code[0]->res : 0, 0), code[1]);
        // note: when reaching AST_VEC_DEC the TAC_MOVE will receive it's symbol and index

        break;
    }
    break;

case AST_VEC_ATTR:
    result = tac_join(code[2],
                      tac_create(TAC_MOVE_VECTOR, node->symbol, code[1] ? code[1]->res : 0, code[2] ? code[2]->res : 0));
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