#include <stdio.h>
#include <string.h>
#include "semantic.h"
#include "decompiler.h"
#include <stdlib.h>
//#include "stack.h"
#define MAX_FUNCTIONS 10
#define MAX_PARAMETERS 1000
#define MAX_VECTORS 1000
#define MAX_LABELS 1000

char *functions_name[MAX_FUNCTIONS];
char *vectors_name[MAX_VECTORS];
char *vectors_range_name[MAX_VECTORS];
char *labels_name[MAX_LABELS];
int *nparam[MAX_FUNCTIONS];
int parameters_type[MAX_PARAMETERS];
int call_parameters_type[MAX_PARAMETERS];
char *param_function[MAX_PARAMETERS];
int param_id[MAX_PARAMETERS];
char *param_names[MAX_PARAMETERS];
int array_of_vectors_lenght[MAX_VECTORS];
int array_of_vectors_lenght_initial[MAX_VECTORS];
int array_of_vectors_lenght_final[MAX_VECTORS];
int label_vector[MAX_LABELS];

AST *aux;
int vl, vrl = 0;
int pid = 0;
int lc = 0;
int n = 0;
int pt = 0;
int cpt = 0;
char kwType[5]; //variável auxiliar para achar o tipo
int param_counter = 0;

int SemanticErrors = 0;

void check_dec_and_set_two(AST *node, int symboltype)
{

    if (node->symbol || node->son[0]->symbol || node->son[1]->symbol || node)
    {
        if (symboltype == SYMBOL_FUNCTION) //tive que fazer um caso especial para function pois é o filho, nao o symbol diretamente
        {

            if ((node->son[0]->symbol->type != SYMBOL_IDENTIFIER) && (node->son[0]->symbol->type != SYMBOL_OUT_OF_SCOPE))
            {
                fprintf(stderr, "Semantic ERROR: identifier %s already declared\n",
                        node->son[0]->symbol->text);
                ++SemanticErrors;
            }

            node->son[0]->symbol->type = symboltype;
            node->son[0]->symbol->numparam = count_numparam(node);
            for (int i = 0; i < node->son[0]->symbol->numparam; i++)
            {
                param_function[i] = node->son[0]->symbol->text;
            }

            //decl_parameters(node);
            declare_parameters(node,node->son[0]->symbol->text);
            check_parameter_in_other_function(node,node->son[0]->symbol->text);
            functions_name[n] = node->son[0]->symbol->text;
            nparam[n] = node->son[0]->symbol->numparam;
            n++;
            //fprintf(stderr, "\n identifier %s na posicao %d \n", node->son[0]->symbol->text, n);

            //==============SET DATATYPE=============================
            if (node->son[0])
            {

                if (node->symbol->type == AST_CHAR)
                    node->son[0]->symbol->datatype = DATATYPE_CHAR;
                else if (node->symbol->type == AST_INT)
                    node->son[0]->symbol->datatype = DATATYPE_INT;
                else if (node->symbol->type == AST_FLOAT)
                    node->son[0]->symbol->datatype = DATATYPE_FLOAT;
            }
            int func_dataype = node->son[0]->symbol->datatype;
            check_return_nature(node, func_dataype);

            //===========================================
        }
        else if (symboltype == SYMBOL_VECTOR) //tive que fazer um caso especial para function pois é o filho, nao o symbol diretamente
        {
            if ((node->son[1]->symbol->type != SYMBOL_IDENTIFIER) && (node->son[1]->symbol->type != SYMBOL_OUT_OF_SCOPE))
            {
                fprintf(stderr, "Semantic ERROR: identifier %s already declared\n",
                        node->son[1]->symbol->text);
                ++SemanticErrors;
            }
            node->son[1]->symbol->type = symboltype;

            check_vector_length(node);
            //check_vectorparam_nature(node);

            //==============SET DATATYPE=============================
            if (node->son[0])
            {
                if (node->symbol->type == AST_CHAR)
                    node->son[1]->symbol->datatype = DATATYPE_CHAR;
                else if (node->symbol->type == AST_INT)
                    node->son[1]->symbol->datatype = DATATYPE_INT;
                else if (node->symbol->type == AST_FLOAT)
                    node->son[1]->symbol->datatype = DATATYPE_FLOAT;
            }
            //===========================================
        }
        else if (symboltype == SYMBOL_VECTOR_RANGE) //tive que fazer um caso especial para function pois é o filho, nao o symbol diretamente
        {
            if ((node->son[2]->symbol->type != SYMBOL_IDENTIFIER) && (node->son[2]->symbol->type != SYMBOL_OUT_OF_SCOPE))
            {
                fprintf(stderr, "Semantic ERROR: identifier %s already declared\n",
                        node->son[2]->symbol->text);
                ++SemanticErrors;
            }

            check_vector_length(node);
            check_vectorparam_nature(node);
            node->son[2]->symbol->type = symboltype;

            //==============SET DATATYPE=============================
            if (node->son[2])
            {
                if (node->symbol->type == AST_CHAR)
                    node->son[2]->symbol->datatype = DATATYPE_CHAR;
                else if (node->symbol->type == AST_INT)
                    node->son[2]->symbol->datatype = DATATYPE_INT;
                else if (node->symbol->type == AST_FLOAT)
                    node->son[2]->symbol->datatype = DATATYPE_FLOAT;
            }
            //===========================================
        }

        else if (symboltype == SYMBOL_VARIABLE)
        {
            if ((node->son[1]->symbol->type != SYMBOL_IDENTIFIER) && (node->son[1]->symbol->type != SYMBOL_OUT_OF_SCOPE))
            {
                fprintf(stderr, "Semantic ERROR: identifier %s already declared\n",
                        node->son[1]->symbol->text);
                ++SemanticErrors;
            }

            node->son[1]->symbol->type = SYMBOL_VARIABLE;

            //==============SET DATATYPE=============================
            if (node->son[0])
            {
                if (node->son[0]->type == AST_CHAR)
                    node->son[1]->symbol->datatype = DATATYPE_CHAR;
                else if (node->son[0]->type == AST_INT)
                    node->son[1]->symbol->datatype = DATATYPE_INT;
                else if (node->son[0]->type == AST_FLOAT)
                    node->son[1]->symbol->datatype = DATATYPE_FLOAT;
            }
            //===========================================
            check_dec_var_nature(node);
        }
        else if (symboltype == SYMBOL_PARAMETER)
        {

            if ((node->son[1]->symbol->type != SYMBOL_IDENTIFIER) && (node->son[1]->symbol->type != SYMBOL_OUT_OF_SCOPE))
            {
                fprintf(stderr, "Semantic ERROR: identifier %s already declared\n",
                        node->son[1]->symbol->text);
                ++SemanticErrors;
            }

            node->son[1]->symbol->type = SYMBOL_PARAMETER;
            //param_names[pid] = node->son[1]->symbol->text;
            //pid++;

            if (node->son[0])
            {
                if (node->son[0]->type == AST_CHAR)
                    node->son[1]->symbol->datatype = DATATYPE_CHAR;
                else if (node->son[0]->type == AST_INT)
                    node->son[1]->symbol->datatype = DATATYPE_INT;
                else if (node->son[0]->type == AST_FLOAT)
                    node->son[1]->symbol->datatype = DATATYPE_FLOAT;
            }
        }
        else if (symboltype == SYMBOL_LABEL) //tive que fazer um caso especial para function pois é o filho, nao o symbol diretamente
        {
            if ((node->son[0]->symbol->type != SYMBOL_IDENTIFIER) && (node->son[0]->symbol->type != SYMBOL_OUT_OF_SCOPE))
            {
                fprintf(stderr, "Semantic ERROR: identifier %s already declared\n",
                        node->son[0]->symbol->text);
                ++SemanticErrors;
            }
            node->son[0]->symbol->type = symboltype;
            labels_name[lc] = node->son[0]->symbol->text;
            label_vector[lc] = 0;
            lc++;
        }
        else if (symboltype == SYMBOL_LABEL_LIT) //tive que fazer um caso especial para function pois é o filho, nao o symbol diretamente
        {
            if ((node->son[0]->symbol->type != SYMBOL_IDENTIFIER) && (node->son[0]->symbol->type != SYMBOL_OUT_OF_SCOPE))
            {
                fprintf(stderr, "Semantic ERROR: identifier %s already declared\n",
                        node->son[0]->symbol->text);
                ++SemanticErrors;
            }
            node->son[0]->symbol->type = symboltype;
            labels_name[lc] = node->son[0]->symbol->text;
            label_vector[lc] = 0;
            lc++;
        }
    }
}

void check_and_set_declarations(AST *node)
{
    AST *aux = node;
    int flag_pl = 0;
    if (aux == 0)
        return;

    int i;

    switch (aux->type)
    {
    case AST_VAR_DEC:
    {
        check_dec_and_set_two(aux, SYMBOL_VARIABLE);
        break;
    }

    case AST_VEC_DEC:
        check_dec_and_set_two(aux, SYMBOL_VECTOR);

        break;

    case AST_VEC_DEC_RANGE:
        check_dec_and_set_two(aux, SYMBOL_VECTOR_RANGE);
        break;

    case AST_FUNC:

        check_dec_and_set_two(aux, SYMBOL_FUNCTION);

        break;

    

    case (AST_LABEL):

        check_dec_and_set_two(aux, SYMBOL_LABEL);
        break;

    case (AST_LABEL_LIT):
        check_dec_and_set_two(aux, SYMBOL_LABEL_LIT);
        break;
    }
    if (aux == 0)
        return;

    for (i = 0; i < MAX_SONS; ++i)
    {

        check_and_set_declarations(aux->son[i]);
    }
}

void check_undeclared(AST *node)
{

    SemanticErrors += hash_check_undeclared();
}

int get_semantic_errors()
{
    return SemanticErrors;
}

void check_operands(AST *node)
{

    int i;
    if (node == 0) //||node->son[0]==0 || node->son[0]->son[0]==0 || node->son[0]->son[0]->son[0]  )
    {
        return;
    }

    switch (node->type)
    {

    case AST_ADD:
    case AST_SUB:
    case AST_DIV:
    case AST_MUL:
    case AST_OR:
    case AST_AND:
    {
        if (!is_number(node->son[0]))
        {
            fprintf(stderr, "Semantic ERROR: INVALID left operand for ADD ,SUB, MUL, OR DIV\n");
            ++SemanticErrors;

            ////exit(5);
        }

        if (!is_number(node->son[1]))
        {
            fprintf(stderr, "Semantic ERROR: INVALID right operand for ADD ,SUB, MUL, OR DIV\n");
            ++SemanticErrors;
            ////exit(5);
        }
        break;
    }
    case AST_PARENTHESIS:
    {
        check_operands(node->son[0]);
        break;
    }
        //default:printf("\n\neae rapaziada switch type :%d\n\n",node->type);break;
    }
    for (i = 0; i < MAX_SONS; ++i)
        check_operands(node->son[i]);
}

void check_range_vector(AST *node)
{
    int j = 0;
    int lth = atoi(node->son[1]->symbol->text);

    int flag = 1;
    while (flag)
    {
       // printf("\nnome : %s length : %d\n", vectors_name[j], array_of_vectors_lenght[j]);
        if (vectors_name[j] == node->son[0]->symbol->text)
        {
            if (lth > array_of_vectors_lenght[j] || lth < 0)
            {
                printf("\nSemantic Error! Vector out of range!\n");
                SemanticErrors++;
                //exit(9);

                break;
            }
            flag = 0;
        }
        else if (vectors_range_name[j] == node->son[0]->symbol->text)
        {
            if (lth < array_of_vectors_lenght_initial[j] || lth > array_of_vectors_lenght_final[j] || lth < 0)
            {
                printf("\nSemantic Error! Vector out of range!\n");
                SemanticErrors++;
                //exit(9);

                break;
            }
            flag = 0;
        }
        j++;
    }
}

int is_number(AST *node)
{
    

    if (node->type == AST_GRE || node->type == AST_EQ || node->type == AST_LES || node->type == AST_GE || node->type == AST_NOT || node->type == AST_LE)
    {
        return 0;
    }
    else if (node->type == AST_SYMBOL_STRING)
    {
        return 0;
    }

    else if (node->type == AST_SYMBOL_CHAR)
        return 0;
    
    else if (node->type == AST_IDEN)
    {
        if (node->son[0]->symbol->datatype != DATATYPE_CHAR && node->son[0]->symbol->datatype != DATATYPE_INT)
        {
            return 0;
        }
        else
            return 1;
    }
    else if (node->type == AST_VEC_SYMBOL)
    {

        check_range_vector(node);
        return 1;
    }

    else if (node->type == AST_FUNCTION_CALL)
    {

        check_numparam(node);
        call_parameters(node);
        check_parameters(node);

        return 1;
    }

    else if (node->type == AST_ADD || node->type == AST_SUB || node->type == AST_AND || node->type == AST_OR||
             node->type == AST_DIV || node->type == AST_ADD || node->type == AST_MUL || node->type == AST_PARENTHESIS)
    {
        
        
        if (node->son[0])
        {
            //is_number(node->son[0]);
        }
        return 1;
    }
    else if (node->symbol->datatype == DATATYPE_INT)
    {

        return 1;
    }

    else if (node->type == AST_SYMBOL_INT || (node->son[0]->symbol->datatype == DATATYPE_INT) ||
             (node->type == AST_FUNCTION_CALL && (node->son[0]->son[0]->symbol->datatype == DATATYPE_INT || node->son[0]->son[0]->symbol->datatype == DATATYPE_FLOAT)) //TEM QUE GARANTIR QUE É INT OU FLOAT
    )
    {

        return 1;
    }

    else
        return 0;
}

int is_boolean(AST *node)
{

    if (node->type == AST_GRE || node->type == AST_EQ || node->type == AST_GE || node->type == AST_EQ || node->type == AST_AND || node->type == AST_OR || node->type == AST_DIF)
    {
        if (is_number(node->son[0]))
        {
            if (is_number(node->son[1]))
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    else
        return 0;
}

void check_vector_length(AST *node)
{

    if (node->type == AST_VEC_DEC)
    {
        int length = atoi(node->son[0]->symbol->text);
        if (node->son[2] != 0)
        { //caso em que parametros foram inicializados

            int numparam;
            numparam = cont_vector_param(node);
            if (node->son[2] != 0)
            {
                if (length != cont_vector_param(node))
                {
                    printf("\nSemantic Error! Vector number of parameters and length are different! \n");
                    SemanticErrors++;
                }
            }
        }
        array_of_vectors_lenght[vl] = length;
        vectors_name[vl] = node->son[1]->symbol->text;
        vl++;
    }
    else if (node->type == AST_VEC_DEC_RANGE)
    {
        int length;
        int length_in = atoi(node->son[0]->symbol->text);
        int length_end = atoi(node->son[1]->symbol->text);
        length = length_end - length_in + 1;
        if (node->son[3] != 0)
        { //caso em que parametros foram inicializados

            if (length != cont_vector_param(node))
            {
                printf("\nSemantic Error! Vector RANGE number of parameters and length are different! \n");
                SemanticErrors++;
            }
        }

        vectors_range_name[vrl] = node->son[2]->symbol->text;

        array_of_vectors_lenght_initial[vrl] = length_in;
        array_of_vectors_lenght_final[vrl] = length_end;
        vrl++;
    }
}

int cont_vector_param(AST *node)
{
    int cont = 0;
    if (node->type == AST_VEC_DEC) //caso do vetor sem range
    {

        if (node->son[2] == 0)
        {
            //caso em que parametros nao foram inicializados
            return 0;
        }

        else if (node->son[2] != 0) //caso que tem parameters list
        {
            //printf("\n\nentrou no caso que tem mais de um parametro\n\n");
            cont++;

            AST *aux;
            aux = node->son[2]->son[1];
            while (aux != 0)
            {
                cont++;

                aux = aux->son[1];
            }
            return cont;
        }
    }
    else if (node->type == AST_VEC_DEC_RANGE) //caso do vetor range
    {

        if (node->son[3] == 0)
        {
            //caso em que parametros nao foram inicializados
            return 0;
        }

        else if (node->son[3] != 0) //caso que tem parameters list
        {
            //printf("\n\nentrou no caso que tem mais de um parametro\n\n");
            cont++;

            AST *aux;
            aux = node->son[3]->son[1];
            while (aux != 0)
            {
                cont++;

                aux = aux->son[1];
            }
            return cont;
        }
    }
}

void check_numparam(AST *node)
{

    //logica: toda vez que uma funcao é declarada é guardada uma posicao no vetor de nome de funcoes e outra no numero de parametros
    //serao usadas na comparacao aqui em baixo, ambas sao a mesma posicao

    for (int i = 0; i < MAX_FUNCTIONS; i++)
    {
        if (functions_name[i] == node->son[0]->son[0]->symbol->text)
        {
            if (nparam[i]  != count_numparam(node))
            {
                printf("\nnparam_decl:%d\tcount_num_call:%d\n",nparam[i],count_numparam(node));
                printf("\n\nSEMANTIC ERROR! number of parameters of function declaration:%d and call:%d are different\n\n",nparam[i],count_numparam(node));
                SemanticErrors++;
                //exit(7);
            }
        }
    }
}

void check_param_nature(AST *node, int func_datatype)
{
    switch (func_datatype)
    {
    case (DATATYPE_CHAR):
        printf("\nENTROU AQUI DT CHAR\n");
        if (node->type != AST_CHAR)
        {
            printf("\nSemantic Error! sending parameter with wrong type,expected char\n");
            SemanticErrors++;
        }
        break;
    case (DATATYPE_INT):
        printf("\nENTROU AQUI DT INT\n");
        if (node->type != AST_INT)
        {
            printf("\nSemantic Error! sending parameter with wrong type,expected INT\n");
            SemanticErrors++;
        }
        break;
    case (DATATYPE_FLOAT):
        if (node->type != AST_INT)
        {
            printf("\nSemantic Error! sending parameter with wrong type,expected FLOAT\n");
            SemanticErrors++;
        }
        break;
    }
}

void call_parameters(AST *node)
{

    n = count_numparam(node);

    if (node->type == AST_FUNCTION_CALL)
    {

        if (node->son[0]->son[2] == 0 && node->son[0]->son[1] == 0)
        {

            return;
        }
        else if (node->son[0]->son[2] == 0 && node->son[0]->son[1] != 0)
        {

            return; //caso que tem um parametro apenas
        }
        else if (node->son[0]->son[2] != 0) //caso que tem parameters list
        {
            int cont = 0;
            cont++;

            call_parameters_type[cpt] = node->son[0]->son[1]->son[0]->symbol->datatype;
            if(!is_number(node->son[0]->son[1]->son[0])){
                printf("Semantic error : Parameter 1 of function call is invalid!");
                SemanticErrors++;
            }
            cpt++;

            AST *aux;
            aux = node->son[0]->son[2];
            
            call_parameters_type[cpt] = aux->son[0]->son[0]->symbol->datatype;
            if(!is_number(aux->son[0]->son[0])){
                printf("Semantic error : Parameter 2 of function call is invalid!");
                SemanticErrors++;
            }
            while (cont < n - 1)
            {
                cpt++;
                
                if(!is_number(aux->son[0]->son[0]) && aux->son[0]->son[0]->type!= AST_SYMBOL_CHAR){
                astPrint(aux->son[0]->son[0],0);
                printf("Semantic error : Parameter of function call is invalid!");
                SemanticErrors++;
                return;
                }
                if (aux->son[0]->son[0]->type)
                {
                    call_parameters_type[cpt] = aux->son[0]->son[0]->symbol->datatype;
                    
                aux = aux->son[1];
                cont++;
            }
        }
    }
}
}

void check_parameters(AST *node)
{
    
    for (int i = 0; i < count_numparam(node); i++)
    {
       // printf("\ncall_parameters_type[%d]", call_parameters_type[i]);
       // printf("\ndecl_parameters_type[%d]", parameters_type[i]);
        switch(parameters_type[i]){
        case AST_INT:
        case AST_CHAR:{if((call_parameters_type[i]!=DATATYPE_INT) && (call_parameters_type[i]!=DATATYPE_CHAR) ){
            printf("\nSemantic Error! Parameters call (%d) and declaration with different type (INT)\n",call_parameters_type[i]);//exit(7);
        }
        break;}
        case AST_FLOAT:{
        if(call_parameters_type[i]!=DATATYPE_INT){
            printf("\nSemantic Error! Parameters call and declaration with different type (FLOAT)\n");//exit(7);
        }
        break;
        }
        default:
        break;
        }
    }
     return;
    }
    
   


int count_numparam(AST *node)
{

    int cont = 0;
    if (node->type == AST_FUNC) //caso da declaração
    {

        ////exit(0);
        int func_datatype = node->son[0]->symbol->datatype;

        if (node->son[3] == 0 && node->son[2] == 0)
        {
            //printf("\n\nentrou no caso vazio\n\n");
            return 0;
        }
        else if (node->son[3] == 0 && node->son[2] != 0)
        {
            parameters_type[cont] = node->son[2]->type;
            return 1; //caso que tem um parametro apenas
        }
        else if (node->son[3] != 0) //caso que tem parameters list
        {
            //printf("\n\nentrou no caso que tem mais de um parametro\n\n");
            cont++;

            AST *aux;
            AST *aux_type;

            aux = node->son[2]->son[1];
            aux_type = node->son[2]->son[0]->son[0];

            while (aux != 0)
            {

                cont++;
                aux = aux->son[1];
                /*check_return_nature(aux,)
                
                if (aux!=0)
                {
                    aux_type = aux->son[0]->son[0];
                   
                    
                    
                }
                */

                //node->son[2]->son[2] = node->son[2]->son[2]->son[0];
            }

            return cont;
        }
    }
    else if (node->type == AST_FUNCTION_CALL)
    {
        int cont = 0;

        if (node->son[0]->son[2] == 0 && node->son[0]->son[1] == 0)
        {

            return 0;
        }
        else if (node->son[0]->son[2] == 0 && node->son[0]->son[1] != 0)
        {

            return 1; //caso que tem um parametro apenas
        }
        else if (node->son[0]->son[2] != 0) //caso que tem parameters list
        {

            

            AST *aux;
            aux = node->son[0]->son[2];
            while (aux != 0)
            {
                cont++;
                aux = aux->son[1];
            }
            return cont;
        }
    }
}

void check_vectorparam_nature(AST *node)
{

    if (node->type == AST_VEC_DEC)
    {
        switch (node->symbol->type)
        {
        case 33:
        {
            AST *aux;
            if (node->son[2]->son[0]->type != AST_SYMBOL_INT)
            {
                printf("\n\naqui Vector param and nature(int) are not equal\n\n");
                //exit(7);
                break;
            }
            aux = node->son[2]->son[1];

            while (aux != 0)
            {
                if (aux->son[0]->type != AST_SYMBOL_INT)
                {
                    printf("\n\nVector param and nature(int) are not equal\n\n");
                    //exit(7);
                    break;
                }

                aux = aux->son[1];
            }
            break;
        }
        case 34:
        {
            AST *aux;
            if (node->son[2]->son[0]->type != AST_SYMBOL_INT)
            {
                printf("\n\nVector param and nature(float) are not equal\n\n");
                //exit(7);
                break;
            }
            aux = node->son[2]->son[1];

            while (aux != 0)
            {
                if (aux->son[0]->type != AST_SYMBOL_INT)
                {
                    printf("\n\nVector param and nature(float) are not equal\n\n");
                    //exit(7);
                    break;
                }

                aux = aux->son[1];
            }
            break;
        }
        case 35:
        {
            AST *aux;
            if (node->son[2]->son[0]->type != AST_SYMBOL_CHAR)
            {
                printf("\n\nVector param and nature(char) are not equal\n\n");
                //exit(7);
                break;
            }
            aux = node->son[2]->son[1];

            while (aux != 0)
            {
                if (aux->son[0]->type != AST_SYMBOL_CHAR)
                {
                    printf("\n\nVector param and nature(char) are not equal\n\n");
                    //exit(7);
                    break;
                }

                aux = aux->son[1];
            }
            break;
        }
        }
    }
    else if (node->type == AST_VEC_DEC_RANGE)
    {
        if (node->son[3] != 0)
        {
            switch (node->symbol->type)

            {
            case 33:
            {
                AST *aux;
                if (node->son[3]->son[0]->type != AST_SYMBOL_INT)
                {
                    printf("\n\naqui Vector RANGE param and nature(int) are not equal\n\n");
                    //exit(7);
                    break;
                }
                aux = node->son[3]->son[1];

                while (aux != 0)
                {
                    if (aux->son[0]->type != AST_SYMBOL_INT)
                    {
                        printf("\n\nVector RANGE param and nature(int) are not equal\n\n");
                        //exit(7);
                        break;
                    }

                    aux = aux->son[1];
                }
                break;
            }
            case 34:
            {
                AST *aux;
                if (node->son[3]->son[0]->type != AST_SYMBOL_INT)
                {
                    printf("\n\nVector RANGE param and nature(float) are not equal\n\n");
                    //exit(7);
                    break;
                }
                aux = node->son[3]->son[1];

                while (aux != 0)
                {
                    if (aux->son[0]->type != AST_SYMBOL_INT)
                    {
                        printf("\n\nVector RANGE param and nature(float) are not equal\n\n");
                        //exit(7);
                        break;
                    }

                    aux = aux->son[1];
                }
                break;
            }
            case 35:
            {
                AST *aux;
                if (node->son[3]->son[0]->type != AST_SYMBOL_CHAR)
                {
                    printf("\n\nVector RANGE param and nature(char) are not equal\n\n");
                    //exit(7);
                    break;
                }
                aux = node->son[3]->son[1];

                while (aux != 0)
                {
                    if (aux->son[0]->type != AST_SYMBOL_CHAR)
                    {
                        printf("\n\nVector RANGE param and nature(char) are not equal\n\n");
                        //exit(7);
                        break;
                    }

                    aux = aux->son[1];
                }
                break;
            }
            }
        }
    }
}

void check_dec_var_nature(AST *node)
{

    switch (node->son[0]->type)
    {
    case AST_CHAR:
        if (node->son[2]->type != AST_SYMBOL_CHAR)
        {
            printf("\nSemantic Error! Variable nature and datatype(char) are different\n");
            SemanticErrors++;
            //exit(5);
        }
        break;
    case AST_INT:
        if (node->son[2]->type != AST_SYMBOL_INT)
        {
            printf("Semantic Error! Variable nature and datatype(int) are different");
            SemanticErrors++;
            //exit(5);
        }
        break;
    case AST_FLOAT:
        if (node->son[2]->type != AST_SYMBOL_INT)
        {
            printf("Semantic Error! Variable nature and datatype are different");
            SemanticErrors++;
            //exit(5);
        }
        break;
    }
}

void check_commands(AST *node)
{
    

    int i;
    if (node == 0) //||node->son[0]==0 || node->son[0]->son[0]==0 || node->son[0]->son[0]->son[0]  )
    {
        return;
    }

    switch (node->type)
    {
    case (AST_ATTR):

    {
        
        
        
       
        
         if (node->son[0]->symbol->datatype == DATATYPE_CHAR || node->son[0]->symbol->datatype == DATATYPE_INT)
        {
           
        

        if (node->son[1]->type == AST_SYMBOL_CHAR || node->son[1]->type == AST_SYMBOL_INT)
        {
            
            return;
        }

        else
        {
            

            for (int i = 1; i < MAX_SONS; i++)
            {
                
                
                if (node->son[i])
                {
                    
                    
                    if (!is_number(node->son[i]))
                    {
                        
                        
                        printf("\nSemantic Error! ATTRIBUTE WITH INCORRET OPERAND!\n");
                        SemanticErrors++;
                        return;
                        //exit(8);
                    }
                }
            }
        }

      
    }

    break;
    }

    case (AST_VEC_ATTR):
    {
        if (node->son[0]->symbol->datatype == DATATYPE_CHAR || node->son[0]->symbol->datatype == DATATYPE_INT)
        {
        if (node->son[0]->type == AST_SYMBOL_CHAR || node->son[0]->type == AST_SYMBOL_INT)
        {
            return;
        }

       for (int i = 1; i < MAX_SONS; i++)
            {
                
                if (node->son[i])
                {
                    
                    if (!is_number(node->son[i]) && node->son[i]->type != AST_SYMBOL_CHAR)
                    {
                        
                        printf("\nSemantic Error! ATTRIBUTE WITH INCORRET OPERAND!\n");
                        SemanticErrors++;
                        return;
                        //exit(8);
                    }
                }
            }

        if (node->son[0]->symbol->datatype == DATATYPE_INT || node->son[0]->symbol->datatype == DATATYPE_CHAR)
        {

            if (node->son[2]->type == AST_ADD || node->son[2]->type == AST_SUB || node->son[2]->type == AST_MUL || node->son[2]->type == AST_DIV || node->son[2]->type == AST_AND || node->son[2]->type == AST_OR || node->son[2]->type == AST_VEC_SYMBOL || node->son[2]->type == AST_FUNCTION_CALL)
            {
                
                check_operands(node);
            }

            else if (node->son[2]->type != AST_SYMBOL_INT && node->son[2]->type != AST_SYMBOL_CHAR)
            {
                printf("\nSemantic Error!! datatype and attribute are from different types\n");
                SemanticErrors++;
                //exit(9);
            }
        }

        if (node->son[1]->type == AST_SYMBOL_INT) //verifica se é inteiro o indice
        {
            int j = 0;
            int lth = atoi(node->son[1]->symbol->text);

            int flag = 1;
            while (flag)
            {
                if (vectors_name[j] == node->son[0]->symbol->text)
                {
                    if (lth > array_of_vectors_lenght[j] || lth < 0)
                    {
                        printf("\nSemantic Error!Semantic Error! Vector out of range!\n");

                        SemanticErrors++;

                        //exit(9);

                        break;
                    }
                    flag = 0;
                }
                else if (vectors_range_name[j] == node->son[0]->symbol->text)
                {
                    if (lth < array_of_vectors_lenght_initial[j] || lth > array_of_vectors_lenght_final[j] || lth < 0)
                    {
                        printf("\nSemantic Error! Semantic Error! Vector out of range!\n");

                        SemanticErrors++;
                        //exit(9);

                        break;
                    }
                    flag = 0;
                }
                j++;
            }
        }
        else
        {
            printf("\nSemantic Error! Vector size must be an integer\n");
            SemanticErrors++;
            //exit(99);
        }
    }
    }
    break;
    case (AST_PRINT):
    {
        break;
    }

    case (AST_COMEFROM):
    {
        check_label(node);
    }
    case (AST_FLOW_CONTROL):
    {

        is_boolean(node->son[0]->son[0]);
        break;
    }
    }
    for (i = 0; i < MAX_SONS; ++i)
        check_commands(node->son[i]);
}

void check_label(AST *node)
{

    if (node->son[0]->son[0]->symbol->type != SYMBOL_LABEL && node->son[0]->son[0]->symbol->type != SYMBOL_LABEL_LIT)
    {
        printf("\nSEMANTIC ERROR! Label not identified!");
        SemanticErrors++;
        //exit(9);
    }

    else
    {

        for (int i = 0; i < MAX_LABELS; i++)
        {
            if (labels_name[i] == node->son[0]->son[0]->symbol->text)
            {
                if (label_vector[i] > 0)
                {
                    printf("\nSemantic Error! Label already referencied\n");
                    SemanticErrors++;
                    //exit(7);
                }
                else
                {
                    label_vector[i]++;
                }
            }
        }
    }
}

void check_return_nature(AST *node, int func_dataype)
{

    int i;
    if (node == 0) //||node->son[0]==0 || node->son[0]->son[0]==0 || node->son[0]->son[0]->son[0]  )
    {
        return;
    }

    if (node->type == AST_RETURN)
    {

        if (node->son[0]->type == AST_SYMBOL_STRING)
        {
            printf("\nSEMANTIC ERROR! Return cant be an string!\n");
            SemanticErrors++;
            return;
            //exit(8);
        }

        else if (!is_number(node->son[0]))
        {
            printf("\nSEMANTIC ERROR! Return type is an boolean!!!\n");
            SemanticErrors++;
            return;
            //exit(9);
        }

        else if (node->son[0]->type == AST_PARENTHESIS)
        {

            if (node->son[0]->son[3]->type == AST_SYMBOL_STRING)
            {
                printf("\nSEMANTIC ERROR! Return type cant be an string!\n");
                SemanticErrors++;
                return;
                //exit(8);
            }

            if (node->son[0]->son[3]->type == AST_PARAMETER)
            {
                printf("\nSEMANTIC ERROR! Return type cant be an string!\n");
                SemanticErrors++;
                return;
                //exit(8);
            }

            else if (node->son[0]->son[3]->type == AST_SYMBOL_CHAR || node->son[0]->son[3]->type == AST_SYMBOL_INT)
            {
                switch (func_dataype)
                {
                case DATATYPE_CHAR:
                case DATATYPE_INT:

                    if ((node->son[0]->son[3]->type != AST_SYMBOL_INT) && (node->son[0]->son[3]->type != AST_SYMBOL_CHAR))
                    {

                        printf("\naq SEMANTIC ERROR! Return and function type(int) are not equal!\n");
                        SemanticErrors++;
                        return;
                        //exit(10);
                    }

                case DATATYPE_FLOAT:
                    if (node->son[0]->son[3]->type != AST_SYMBOL_INT)
                    {
                        printf("\nSEMANTIC ERROR! Return and function type(float) are not equal!\n");
                        SemanticErrors++;
                        return;
                        //exit(10);
                    }
                    break;
                }
            }

            else if (node->son[0]->son[3]->type == AST_IDEN)
            {

                if (node->son[0]->son[3]->son[0]->symbol->datatype)
                    switch (func_dataype)
                    {

                    case DATATYPE_CHAR:
                    case DATATYPE_INT:
                        if (node->son[0]->son[3]->son[0]->symbol->datatype != DATATYPE_INT && node->son[0]->son[3]->son[0]->symbol->datatype != DATATYPE_CHAR)
                        {
                            printf("\nSEMANTIC ERROR! Return IDENTIFIER  and function type(int) are not equal!\n");
                            SemanticErrors++;
                            return;
                            //exit(10);
                        }
                        break;

                    case DATATYPE_FLOAT:
                        if (node->son[0]->son[3]->son[0]->symbol->datatype != DATATYPE_INT)
                        {
                            printf("\nSEMANTIC ERROR! Return IDENTIFIER and function type(float) are not equal!\n");
                            SemanticErrors++;
                            return;
                            //exit(10);
                        }
                        break;
                    }
            }

            else
            {

                if (!is_number(node->son[0]->son[3]))
                {
                    printf("\nSemantic Error! Return type invalid!\n");
                    SemanticErrors++;
                    //exit(8);
                }
                return;
            }
        }
    }

    for (i = 0; i < MAX_SONS; ++i)
        check_return_nature(node->son[i], func_dataype);
}



void declare_parameters(AST *node,char *parameter_function_name){


if(node->son[2] == 0){   //caso que é void
    return;
}

else if(node->son[2] == 0 || node->son[3] == 0){   //caso que tem um parametro
    declare_parameters2(node->son[1],parameter_function_name);

}




else if (node->son[3] != 0) //caso que tem parameters list
        {
            //printf("\n\nentrou no caso que tem mais de um parametro\n\n");
            
            declare_parameters2(node->son[1],parameter_function_name);
            AST *aux;
            AST *aux_type;
           
            
            declare_parameters2(node->son[2]->son[0],parameter_function_name);
            
            aux = node->son[2]->son[1];

            
            
            

            while (aux != 0)
            {

               
                
                
                
               
                if (!aux->son[0])
                {
                    
                   return;
                    
                    
                }

                declare_parameters2(aux->son[0],parameter_function_name);
                aux = aux->son[1];
                

                //node->son[2]->son[2] = node->son[2]->son[2]->son[0];
            }

            
        }

}





void declare_parameters2(AST *node,char *parameter_function_name){
    if ((node->son[1]->symbol->type != SYMBOL_IDENTIFIER) && (node->son[1]->symbol->type != SYMBOL_OUT_OF_SCOPE))
            {
                fprintf(stderr, "Semantic ERROR: identifier %s already declared\n",
                        node->son[1]->symbol->text);
                ++SemanticErrors;
            }

            node->son[1]->symbol->type = SYMBOL_PARAMETER;
            //param_names[pid] = node->son[1]->symbol->text;
            //pid++;

            if (node->son[0])
            {
                if (node->son[0]->type == AST_CHAR)
                    node->son[1]->symbol->datatype = DATATYPE_CHAR;
                else if (node->son[0]->type == AST_INT)
                    node->son[1]->symbol->datatype = DATATYPE_INT;
                else if (node->son[0]->type == AST_FLOAT)
                    node->son[1]->symbol->datatype = DATATYPE_FLOAT;
            }
            node->son[1]->symbol->parameter_function_name = parameter_function_name;
            return;
}


void check_parameter_in_other_function(AST *node,char *function_name){
    if(node==0){
        return;
    }
    
    if(node->symbol){
    if(node->symbol->type == SYMBOL_PARAMETER){
        
        if(node->symbol->parameter_function_name!=function_name){
         
            
            printf("\nSemantic Error! Parameter called out of function scope!!");
            SemanticErrors++;
            return;
        }
    }
    }
    for(int i=0;i < MAX_SONS;i++){
        check_parameter_in_other_function(node->son[i],function_name);
    }

}
