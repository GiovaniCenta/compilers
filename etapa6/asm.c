
#include "asm.h"
#include <string.h>

FILE *fout;

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

        case TAC_ADD:
            asm_aritm_operation_edx_eax(tac, "addl");
            break;
        case TAC_SUB:
            asm_aritm_operation_edx_eax(tac, "subl");
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
        }
    }

    //hash table
    print_asm(fout);

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
}

void asm_endfun()
{
    fprintf(fout, "## TAC_ENDFUN\n"
                  "\tpopq	%%rbp\n"
                  "\tret\n");
}

void asm_print(TAC *tac)
{
    fprintf(fout, "## TAC_PRINT\n"
                  "\tmovl	_%s(%%rip), %%esi\n"
                  "\tleaq	.printintstr(%%rip), %%rdi\n"
                  "\tmovl	$0, %%eax\n"
                  "\tcall	printf@PLT\n"
                  "\tmovl	$0, %%eax\n",
            tac->res->text);
}

TAC *asm_var_declar(TAC *first)
{
    TAC *tac = first;

    fprintf(fout, "\n## VAR DECLARATION\n"
                  ".globl	main\n"
                  "main:\n"
                  "\tpushq	%%rbp\n"
                  "\tmovq	%%rsp, %%rbp\n\n");

    while (tac->type == TAC_MOVE)
    {
        asm_move(tac);
        tac = tac->next;
    }
    fprintf(fout, "\tcall\t_main\n");

    asm_endfun();
    fprintf(fout, "\n\n");
    return tac;
}

void asm_move(TAC *tac)
{

    if (tac->op2)
    { //ITS A VECTOR
        printf("ENTROU AQUI");
        exit(9);
        fprintf(fout, "\tmovl\t_%s(%%rip), %%edx\n"
                      "\tmovl\t_%s(%%rip), %%eax\n"
                      "\tmovslq\t%%edx, %%rdx\n"
                      "\tleaq\t0(,%%rdx,4), %%rcx\n"
                      "\tleaq\t_%s(%%rip), %%rdx\n"
                      "\tmovl\t%%eax, (%%rcx,%%rdx)\n",
                tac->op2->text,
                tac->op1->text,
                tac->res->text);
    }

    else
    {
        fprintf(fout, "\tmovl\t_%s(%%rip), %%eax\n"
                      "\tmovl\t%%eax, _%s(%%rip)\n",
                tac->op1->text, tac->res->text);
    }
}
void asm_aritm_operation_edx_eax(TAC *tac, char *instruction)
{
    fprintf(fout, "\tmovl\t_%s(%%rip), %%edx\n"
                  "\tmovl\t_%s(%%rip), %%eax\n"
                  "\t%s\t%%edx, %%eax\n"
                  "\tmovl\t%%eax, _%s(%%rip)\n",
            tac->op1->text, tac->op2->text,
            instruction, tac->res->text);
}

void asm_aritm_operation_eax_edx(TAC *tac, char *instruction)
{
    fprintf(fout, "\tmovl\t_%s(%%rip), %%eax\n"
                  "\tmovl\t_%s(%%rip), %%edx\n"
                  "\t%s\t%%edx, %%eax\n"
                  "\tmovl\t%%eax, _%s(%%rip)\n",
            tac->op1->text, tac->op2->text,
            instruction, tac->res->text);
}

void asm_div(TAC *tac)
{
    fprintf(fout, "\tmovl\t_%s(%%rip), %%eax\n"
                  "\tmovl\t_%s(%%rip), %%ecx\n"
                  "\tcltd\n"
                  "\tidivl\t%%ecx\n"
                  "\tmovl\t%%eax, _%s(%%rip)\n",
            tac->op1->text, tac->op2->text,
            tac->res->text);
}

void asm_aritm_operation_logical(TAC *tac, char *instruction)
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

void asm_not(TAC *tac)
{
    fprintf(fout, "\tmovl\t_%s(%%rip), %%eax\n"
                  "\ttestl\t%%eax, %%eax\n"
                  "\tsete\t%%al\n"
                  "\tmovzb\t%%al, %%eax\n"
                  "\tmovl\t%%eax, _%s(%%rip)\n",
            tac->op1->text, tac->res->text);
}