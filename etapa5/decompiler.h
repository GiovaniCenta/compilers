#include "ast.h"
void decompileData(AST* node);
void get_Type(int TypeID, char* type);
void decompileVarDec(AST* node);
void decompileVarDec_vector(AST* node);
void decompileVarDec_vector_range(AST* node);
void decompileListList(AST* node);
void decompileFunctionList(AST* node);
void decompileFunction(AST* node);
void decompileparameterList(AST* node);
void decompileParameter(AST *node);

void decompileSwitchCMD(AST* node);
void decompileCMDLIST(AST* node);
void decompileSwitchExpr(AST *node);
void decompileNotExpr(AST *node);

void decompileAttr(AST* node);
void decompileVecAttr(AST* node);

void decompileSymbol(AST *node);

void decompileReturn(AST* node);
void decompileIF(AST *node);
void decompileIFElse(AST *node);
void decompileUntil(AST *node);

void decompilationComeFrom(AST *node);
void decompileVecSymbol(AST *node);


void decompileIden(AST *node);
void decompileIdenLit(AST *node);
void decompileParenthesis(AST *node);




void switchDecompilation(AST* node);
void decompile(FILE* outFile, AST* node);