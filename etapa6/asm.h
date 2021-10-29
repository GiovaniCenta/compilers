# include "tacs.h"
#include "hash.h"


void generate_asm(TAC* first);

void asm_beginfun(TAC* tac);
void asm_endfun();
void asm_print(TAC* tac);


TAC* asm_var_declar(TAC* first);

void asm_move(TAC* tac);