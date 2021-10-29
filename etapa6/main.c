#include <stdio.h>
#include "hash.h"
#include "ast.h"
#include "decompiler.h"
#include "semantic.h"

extern AST *mainAST;

extern FILE *yyin;
int yyparse();
int getLineNumber();
void initMe();

FILE *decompilationOutputFile;

int main(int argc, char **argv)
{
    
initMe();
int tok;
if (argc<2)
{
    fprintf(stderr,"Call: ./etapa3 file_name\n");
    exit(1);
}
yyin = fopen(argv[1],"r"); 

decompilationOutputFile = fopen(argv[2], "w");
  if (decompilationOutputFile == 0){
    fprintf(stderr, "Cannot open file %s\n", argv[2]);
    exit(2);
  }
  
  
  yyparse();

   int semanticErrors = get_semantic_errors();
  if (semanticErrors > 0){
      fprintf(stderr, "ERROR! There are : %d  Semantic Errors! \n", semanticErrors);
      exit(4);
    }
  //hashPrint();
  
  //fprintf(stdout, "Compilation successful!\n");
  //fprintf(stdout, "Generated AST:\n\n");
  //astPrint(mainAST, 0);
  
  
  //fprintf(stdout, "\n\n\t...Decompiling...\n");
  //decompile(decompilationOutputFile, mainAST);
  //fprintf(stdout, "\n\n=========================================================================\n\n");
  fprintf(stdout, "\n\nDecompilation done!\n\n");
  
  
  
  
  exit(0); //0 is CODE for SUCCESS
}

