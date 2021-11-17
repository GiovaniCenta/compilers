# include "tacs.h"
#include "hash.h"


void generate_asm(TAC* first);

void asm_beginfun(TAC* tac);
void asm_endfun();
void asm_print(TAC* tac);


TAC* asm_var_declar(TAC* first);

void asm_move(TAC* tac);

void asm_aritm_operation_edx_eax(TAC *tac, char *instruction);
void asm_aritm_operation_eax_edx(TAC *tac, char *instruction);
void asm_div(TAC *tac);
void asm_aritm_operation_logical(TAC *tac, char *instruction);
void asm_not(TAC *tac);

int is_function(char *functionName);