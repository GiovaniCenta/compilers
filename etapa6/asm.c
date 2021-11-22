
#include "asm.h"
#include <string.h>

struct Node *functionNameList = NULL;
extern struct Node *head;
char *arraydefuncoes[100];
int funcoes_index = 0;

char *vectorsNames[100];
int vectorCount = 0;

char *vec_name;

int cont_param_1 = 0;
char *regsparameters[5] = {"esi", "edi", "edx", "ecx", "eax"};

int cont_param_2 = 0;
char *regsparameters_2[5] = {"esi", "edi", "edx", "ecx", "eax"};

FILE *fout;
int m = 1;
void generate_asm(TAC *first)
{

    //TAC *tac;
    fout = fopen("out.s", "w");

    //init
    fprintf(fout, ".printintstr: .string \"%%d\"\n"
                  ".printfloatstr: .string \"%%f\"\n"
                  ".printstring: .string \"%%s\"\n");

    TAC *tac = asm_var_declar(first);

    //each tac
    for (tac; tac; tac = tac->next)
    {
        switch (tac->type)
        {
        case TAC_MOVE:
            asm_move(tac);
            break;

        case TAC_DECL_VECTOR:
        {

            int valor = atoi(tac->op1->text);

            fprintf(fout, "\t.comm	%s,%d,16\n", tac->res->text, 4 * valor);

            break;
        }

        case TAC_MOVE_VECTOR:
            asm_move(tac);
            break;

        case TAC_PARAMETER_LIST:
            break;
        case TAC_PARAMETER:
            if (tac->res) //caso em que é parameter call
            {
                //movl	%esi,_p1(%rip)
                fprintf(fout, "\t movl	%%%s,_%s(%%rip)\n", regsparameters[cont_param_1], tac->res->text);
                ++cont_param_1;
                break;
            }
            else if (tac->op1)
            {
                // movl	$890,%esi
                fprintf(fout, "\t movl	$%s,%%%s\n", tac->op1->text, regsparameters_2[cont_param_2]);
                ++cont_param_2;
                break;
            }
            if ((!tac->res) && (!tac->op1))
            {

                break;
            }

            break;
        case TAC_FUNCTION_CALL:

            if (tac->op1)
            {
                fprintf(fout, "\t call _%s \n", tac->op1->text);
                fprintf(fout, "\tmovl	%%eax,_%s_Return(%%rip)\n", tac->op1->text);
                if(tac->res)
        fprintf(fout, "## TAC_FUNCTION_CALL \n \tmovl	%%eax,_%s_Return(%%rip)\n \tmovl _%s_Return(%%rip), %%eax\n \tmovl %%eax,_%s(%%rip)\n ", tac->op1->text,tac->op1->text,tac->res->text);
        break;
            }

            break;
        case TAC_BEGINFUN:
            asm_beginfun(tac);
            break;

        case TAC_ENDFUN:

            asm_endfun();

            break;
        case TAC_PRINT:

            asm_print(tac);

            break;

        case TAC_LABEL:
            fprintf(fout, "\n.%s:\n", tac->res->text);
            break;
        case TAC_JUMP:
            fprintf(fout, "\tjmp\t\t.%s\n", tac->res->text);
            break;
        case TAC_IFZ:
            fprintf(fout, "\n## TAC_IFZ\n"
                          "\tmovl	_%s(%%rip), %%eax\n"
                          "\ttestl	%%eax, %%eax\n"
                          "\tje\t\t.%s\n",
                    tac->op1->text, tac->res->text);
            break;

        case TAC_IF:
            fprintf(fout, "\n## TAC_IFZ\n"
                          "\tmovl	_%s(%%rip), %%eax\n"
                          "\ttestl	%%eax, %%eax\n"
                          "\tjne\t\t.%s\n",
                    tac->op1->text, tac->res->text);
            break;

        case TAC_ADD:
            asm_aritm_operation_edx_eax(tac, "addl");
            break;
        case TAC_SUB:
            asm_aritm_operation_eax_edx(tac, "subl");
            break;

        case TAC_OR:
            asm_aritm_operation_edx_eax(tac, "orl");
            break;

        case TAC_AND:
            asm_aritm_operation_edx_eax(tac, "andl");
            break;
        case TAC_MUL:
            asm_aritm_operation_edx_eax(tac, "imull");
            break;
        case TAC_DIV:
            asm_div(tac);
            break;
        case TAC_EQ:
            asm_aritm_operation_logical(tac, "sete");
            break;
        case TAC_GE:
            asm_aritm_operation_logical(tac, "setge");
            break;
        case TAC_LE:
            asm_aritm_operation_logical(tac, "setle");
            break;
        case TAC_DIF:
            asm_aritm_operation_logical(tac, "setne");
            break;
        case TAC_GRE:
            asm_aritm_operation_logical(tac, "setg");
            break;

        
        
        case TAC_LES:
            asm_aritm_operation_logical(tac, "setl");
            break;
        case TAC_NOT:
            asm_not(tac);
            break;

        case TAC_RET:
       
            fprintf(fout, "\t##TAC_RET\n");
            
            if(tac->op1){
            fprintf(fout, "\tmovl	_%s(%%rip), %%eax\n", tac->op1->text);
            }
            else if(tac->res){
                fprintf(fout, "\tmovl	_%s(%%rip), %%eax\n", tac->res->text);
            }
            
            
        }
    }

    print_asm(fout); //hash table

    fclose(fout);
}

void asm_beginfun(TAC *tac)
{

    fprintf(fout, "## TAC_BEGINFUN\n"
                  ".globl	_%s\n"
                  "_%s:\n"
                  "\tpushq	%%rbp\n"
                  "\tmovq	%%rsp, %%rbp\n\n",

            tac->res->text, tac->res->text);

    arraydefuncoes[funcoes_index] = tac->res->text;
    funcoes_index++;
}

void asm_endfun()
{
    fprintf(fout, "## TAC_ENDFUN\n"
                  "\tpopq	%%rbp\n"
                  "\tret\n");
}

void asm_print(TAC *tac)
{
    

    if(tac->res){
    if (tac->res->type == SYMBOL_LIT_STRING)
    {

        char str[50] = "str";
        char output[50];
        strcpy(output, tac->res->text);
        str_treatment(output);

        fprintf(fout, "## TAC_PRINT_STRING\n");
        fprintf(fout, "\tleaq	_%s(%%rip), %%rdi\n"
                      "\tmovl	$0, %%eax\n"
                      "\tcall	printf@PLT\n"
                      "\tmovl	$0, %%eax\n",
                output);
        m++;
        return;
    }
    
    
        
       
        char buffer[50];
        
        strcpy(buffer, str_treatment_vector_lenght(tac->res->text));
        //printf("\nbuffer:%s",buffer);
        
        //vec_name = str_treatment_vector_lenght(tac->res->text);
       // printf("\nvec_lenght:%s\n", buffer);
        

        str_treatment_vector(tac->res->text);
        
        //printf("\nvec_name:%s\n", tac->res->text);
        

        if (is_vector(tac->res->text) == 1)
        {
            //printf("\nentrou aqui vetor print");
            int valor = atoi(buffer);

            fprintf(fout, "## TAC_PRINT VECTOR\n"
                          "\tmovl	%d+_%s(%%rip), %%esi\n"
                          "\tleaq	.printintstr(%%rip), %%rdi\n"
                          "\tmovl	$0, %%eax\n"
                          "\tcall	printf@PLT\n"
                          "\tmovl	$0, %%eax\n",
                    4 * valor,
                    tac->res->text);
            return;
        }
        else{
        
        fprintf(fout, "## TAC_PRINT\n"
                      "\tmovl	_%s(%%rip), %%esi\n"
                      "\tleaq	.printintstr(%%rip), %%rdi\n"
                      "\tmovl	$0, %%eax\n"
                      "\tcall	printf@PLT\n"
                      "\tmovl	$0, %%eax\n",
                tac->res->text);
        }
    
    }
}

TAC *asm_var_declar(TAC *first)
{
    TAC *tac = first;

    fprintf(fout, "\n## VAR DECLARATION\n"
                  ".globl	main\n"
                  "main:\n"
                  "\tpushq	%%rbp\n"
                  "\tmovq	%%rsp, %%rbp\n\n");

    while (tac->type == TAC_DECL_VAR || tac->type == TAC_DECL_VECTOR)
    {

        if (tac)
        {

            asm_move(tac);
            tac = tac->next;
            if (tac->type == TAC_DECL_VECTOR)
            {

                vectorsNames[vectorCount] = tac->res->text;
                vectorCount++;
            }
        }
    }
    fprintf(fout, "\tcall\t_main\n");

    asm_endfun();
    fprintf(fout, "\n\n");
    return tac;
}

void asm_move(TAC *tac)
{

    if (!is_function(tac->op1->text))
    {

        if (tac->op2)
        { //ITS A VECTOR

            //int output;
            //sprintf(output, "4*%s",tac->op1->text);

            int valor = atoi(tac->op1->text);
            fprintf(fout, "## TAC_MOVE_VECTOR\n"
                          "\tmovl	$%s, %d+_%s(%%rip)\n"
                          "\tmovl	$0, %%eax\n",
                    tac->op2->text,
                    4 * valor,
                    tac->res->text);

            tac->op1->text = tac->op2->text;
        }

        else if (tac->op1->text)
        {

            fprintf(fout, "## TAC_MOVE\n");
            fprintf(fout, "\tmovl\t_%s(%%rip), %%eax\n"
                          "\tmovl\t%%eax, _%s(%%rip)\n",
                    tac->op1->text, tac->res->text);
        }
    }
    else
    {
        fprintf(fout, "## TAC_FUNCTION_CALL\n");
        //fprintf(fout, "\tmovl	%%eax,_%s(%%rip)\n \tmovl _%s(%%rip), %%eax\n \tmovl %%eax,_%s(%%rip)\n ", tac->op1->text,tac->op1->text,tac->op2->text);
        fprintf(fout, "\tmovl	%%eax, _%s(%%rip)\n", tac->res->text);
    }
}
void asm_aritm_operation_edx_eax(TAC *tac, char *instruction)
{

    if (is_function(tac->op2->text) == 1 || is_function(tac->op1->text) == 1)
    {
        fprintf(fout, "## OPERATION WITH FUNCTION CALL EDX EAX\n");
        fprintf(fout, "\tmovl\t_%s_Return(%%rip), %%eax\n"
                      "\tmovl\t_%s(%%rip), %%edx\n"
                      "\t%s\t%%edx, %%eax\n"
                      "\tmovl\t%%eax, _%s(%%rip)\n",
                tac->op1->text, tac->op2->text,
                instruction, tac->res->text);
        return;
    }

    char buffer[50],buffer2[50];
    strcpy(buffer, str_treatment_vector_lenght(tac->op1->text));
    strcpy(buffer2, str_treatment_vector_lenght(tac->op2->text));
    //vec_name = str_treatment_vector_lenght(tac->res->text);
    //printf("\nvec_lenght:%s", buffer);
    //printf("\nvec_lenght:%s\n", buffer2);
   

    str_treatment_vector(tac->op1->text);
     str_treatment_vector(tac->op2->text);
    //printf("\nvec_name:%s\n", tac->op1->text);
   // printf("\nvec_name:%s\n", tac->op2->text);
     

    if (is_vector(tac->op1->text) == 1)
    {
        //printf("entrou aqui");
        int valor = atoi(buffer);
         fprintf(fout, "## OPERATION EDX EAX WITH VECTOR OP1\n");
            fprintf(fout, "\tmovl\t%d+_%s(%%rip), %%edx\n"
                          "\tmovl\t_%s(%%rip), %%eax\n"
                          "\t%s\t%%edx, %%eax\n"
                          "\tmovl\t%%eax, _%s(%%rip)\n",valor*4,
                    tac->op1->text, tac->op2->text,
                    instruction, tac->res->text);
        return;
    }

    else if (is_vector(tac->op2->text) == 1)
    {
        //printf("entrou aqui");
        int valor = atoi(buffer2);
         fprintf(fout, "## OPERATION EDX EAX WITH VECTOR OP2\n");
            fprintf(fout, "\tmovl\t_%s(%%rip), %%edx\n"
                          "\tmovl\t%d+_%s(%%rip), %%eax\n"
                          "\t%s\t%%edx, %%eax\n"
                          "\tmovl\t%%eax, _%s(%%rip)\n",tac->op1->text,valor*4,
                    tac->op2->text,
                    instruction, tac->res->text);
        return;
    }

        else
        {
            fprintf(fout, "## OPERATION EDX EAX\n");
            fprintf(fout, "\tmovl\t_%s(%%rip), %%edx\n"
                          "\tmovl\t_%s(%%rip), %%eax\n"
                          "\t%s\t%%edx, %%eax\n"
                          "\tmovl\t%%eax, _%s(%%rip)\n",
                    tac->op1->text, tac->op2->text,
                    instruction, tac->res->text);
            return;
        }
    }

    void asm_aritm_operation_eax_edx(TAC * tac, char *instruction)
    {
        if (is_function(tac->op2->text) == 1 || is_function(tac->op1->text) == 1)
        {
            fprintf(fout, "## OPERATION WITH FUNCTION CALL EAX EDX\n");
            fprintf(fout, "\tmovl\t_%s_Return(%%rip), %%eax\n"
                          "\tmovl\t_%s(%%rip), %%edx\n"
                          "\t%s\t%%edx, %%eax\n"
                          "\tmovl\t%%eax, _%s(%%rip)\n",
                    tac->op1->text, tac->op2->text,
                    instruction, tac->res->text);
        }

        else
        {
            fprintf(fout, "## OPERATION EAX EDX\n");
            fprintf(fout, "\tmovl\t_%s(%%rip), %%eax\n"
                          "\tmovl\t_%s(%%rip), %%edx\n"
                          "\t%s\t%%edx, %%eax\n"
                          "\tmovl\t%%eax, _%s(%%rip)\n",
                    tac->op1->text, tac->op2->text,
                    instruction, tac->res->text);
        }
    }

    void asm_div(TAC * tac)
    {
        fprintf(fout, "\tmovl\t_%s(%%rip), %%eax\n"
                      "\tmovl\t_%s(%%rip), %%ecx\n"
                      "\tcltd\n"
                      "\tidivl\t%%ecx\n"
                      "\tmovl\t%%eax, _%s(%%rip)\n",
                tac->op1->text, tac->op2->text,
                tac->res->text);
    }

    void asm_aritm_operation_logical(TAC * tac, char *instruction)
    {
        fprintf(fout, "\tmovl\t_%s(%%rip), %%edx\n"
                      "\tmovl\t_%s(%%rip), %%eax\n"
                      "\tcmpl\t%%eax, %%edx\n"
                      "\t%s\t%%al\n"
                      "\tmovzbl\t%%al, %%eax\n"
                      "\tmovl\t%%eax, _%s(%%rip)\n",
                tac->op1->text, tac->op2->text,
                instruction, tac->res->text);
    }

    void asm_not(TAC * tac)
    {
        fprintf(fout, "\tmovl\t_%s(%%rip), %%eax\n"
                      "\ttestl\t%%eax, %%eax\n"
                      "\tsete\t%%al\n"
                      "\tmovzb\t%%al, %%eax\n"
                      "\tmovl\t%%eax, _%s(%%rip)\n",
                tac->op1->text, tac->res->text);
    }

    int is_function(char *functionName)
    {
        char buffer[256];
        sprintf(buffer, "_%s", functionName);
        for (int i = 0; i < 100; i++)
        {
            //printf("\n\tbuffer:%s\tarraydefuncoes[%d]:%s\n",functionName,i,arraydefuncoes[i]);
            if (arraydefuncoes[i] == functionName)
            {

                return 1;
            }
        }
        return 0;
    }

    int is_vector(char *vectorName)
    {

        //char buffer[256];

        //sprintf(buffer, "_%s", vectorName);

        // printf("\nbuffer:%s",buffer);
        for (int i = 0; i < 100; i++)
        {
           // printf("vectorsName[i]:%s \t vectorName:%s\n",vectorsNames[i],vectorName);
            //printf("\n\tbuffer:%s\tarraydefuncoes[%d]:%s\n",functionName,i,arraydefuncoes[i]);
            if(vectorsNames[i]){
            if (strcmp(vectorsNames[i],vectorName)==0)
            {
                
                return 1;
            }
            }
        }
        return 0;
    }