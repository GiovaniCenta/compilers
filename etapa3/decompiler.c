#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "decompiler.h"
FILE* decompilationFile;

char kwType[5]; //variável auxiliar para achar o tipo 
   
void get_Type(int TypeID, char* type){
    switch (TypeID) {
        case AST_INT: strcpy(type, "int"); break;
        case AST_FLOAT: strcpy(type, "float"); break;
        case AST_CHAR: strcpy(type, "char"); break;
        default: fprintf(stderr, "ERROR! UNKNOW TYPE: %d\n\n", TypeID); exit(15); break;
    }
    return;
}


void decompileData(AST* node){
    fprintf(decompilationFile,"data{\n");
    switchDecompilation(node->son[1]);
    fprintf(decompilationFile,"}");
    switchDecompilation(node->son[2]);
}

void decompileDecblock(AST* node){
    
    switchDecompilation(node->son[0]);
    switchDecompilation(node->son[1]);
    
}

void decompileDeclist(AST* node){
    
    switchDecompilation(node->son[0]);
    if (node->son[1] != 0)
        switchDecompilation(node->son[1]);

    
}


void decompileBlock(AST* node){
    fprintf(decompilationFile,"{");
    switchDecompilation(node->son[1]);
    fprintf(decompilationFile,"\n}");
}

void decompileVarDec(AST* node){
    

    get_Type(node->son[0]->type, kwType);
    fprintf(decompilationFile, kwType);
    

    fprintf(decompilationFile, ":");
    fprintf(decompilationFile, node->son[1]->symbol->text);
    fprintf(decompilationFile, "=");
    fprintf(decompilationFile, node->son[2]->symbol->text);
    fprintf(decompilationFile, ";\n");
    return;
}

void decompileListList(AST* node){
    fprintf(decompilationFile, " ");
    fprintf(decompilationFile, node->son[0]->symbol->text);
    
    if (node->son[1]!=0)
        decompileListList(node->son[1]);
}

void decompileVarDec_vector(AST* node){
    
    
    /*| type '[' literal ']' ':' identifier '=' litlist { $$ = astCreate(AST_VEC_DEC,$1,$3,$6,$8,0); }
    
    | type '[' literal ']' ':' identifier   { $$ = astCreate(AST_VEC_DEC,$1,$3,$6,0,0);}
    */

    get_Type(node->symbol->type, kwType);
    fprintf(decompilationFile, kwType);
    
    fprintf(decompilationFile, "[");
    fprintf(decompilationFile, node->son[0]->symbol->text);
    fprintf(decompilationFile, "]");
    

    fprintf(decompilationFile, ":");
    fprintf(decompilationFile, node->son[1]->symbol->text); //identifier

    if (node->son[2] != 0){
    fprintf(decompilationFile, "=");
    decompileListList(node->son[2]);
    }
    fprintf(decompilationFile, ";\n");
    return;
}



void decompileVarDec_vector_range(AST* node){

    //| type '[' LIT_INTEGER OPERATOR_RANGE LIT_INTEGER ']' ':' identifier '=' litlist   { $$ = astCreate(AST_VEC_DEC_RANGE,$1,$3,$5,$8,$10); }
    //| type '[' LIT_INTEGER OPERATOR_RANGE LIT_INTEGER ']' ':' identifier        { $$ = astCreate(AST_VEC_DEC_RANGE,$1,$3,$5,$8,0); }
    
    
    get_Type(node->symbol->type, kwType);
    fprintf(decompilationFile, kwType);
    
    fprintf(decompilationFile, "[");
    fprintf(decompilationFile, node->son[0]->symbol->text);
    fprintf(decompilationFile, "..");
    fprintf(decompilationFile, node->son[1]->symbol->text);
    
    fprintf(decompilationFile, "]");
    fprintf(decompilationFile, ":");
    fprintf(decompilationFile, node->son[2]->symbol->text); //identifier
    if (node->son[3] != 0){
        fprintf(decompilationFile, "=");
        decompileListList(node->son[3]);
        
        }
    fprintf(decompilationFile, ";\n");
    return;


}


void decompileFunctionList(AST* node){
    switchDecompilation(node->son[0]);
    if (node->son[1]!=0)
    switchDecompilation(node->son[1]);

}

void decompileParameter(AST *node){
   if (node->son[0] != 0){
    
    
    get_Type(node->son[0]->type, kwType);
    fprintf(decompilationFile, kwType);
    fprintf(decompilationFile, " : ");
    fprintf(decompilationFile, node->son[1]->symbol->text);
    }

}


void decompileparameterList(AST* node){

    /*parameterslist:
   |',' parameter parameterslist        { $$ = astCreate(AST_PARAMETER_LIST,0,$2,$3,0,0); }
    ;*/
    
    if(node->son[0]!=0){
        decompileParameter(node->son[0]);
        fprintf(decompilationFile, " ");

    
    if (node->son[1]!=0)
        {
        fprintf(decompilationFile, ", ");
        decompileparameterList(node->son[1]);
        
        }
    }
}

void decompilationBlock(AST* node){
    
    if (node->son[0]!=0){
    fprintf(decompilationFile, "\n{");
    switchDecompilation(node->son[0]);
    fprintf(decompilationFile, "\n}");
    }
    else
{
    fprintf(decompilationFile, "\n{");
    fprintf(decompilationFile, "}");
}




}







void decompileFunction(AST* node){
   
    
    
    fprintf(decompilationFile, "\n");
    get_Type(node->symbol->type, kwType);
    fprintf(decompilationFile, kwType);
    fprintf(decompilationFile, ":");
   
    fprintf(decompilationFile, node->son[0]->symbol->text);
    
    if (node->son[2]!= 0 && node->son[3] == 0) {   //caso em que tem 1 parametro
    fprintf(decompilationFile, "(");
    decompileParameter(node->son[1]);
    fprintf(decompilationFile, " )");
    decompilationBlock(node->son[2]);
    }
    
    else if(node->son[3]!= 0)    //caso com 2 ou mais parametros
    {
         fprintf(decompilationFile, "(");
    decompileParameter(node->son[1]);
    fprintf(decompilationFile, ", ");
    decompileparameterList(node->son[2]);
    fprintf(decompilationFile, ")");
    decompilationBlock(node->son[3]);
    }
    else{
        fprintf(decompilationFile, "()"); 
        switchDecompilation(node->son[1]);
    }
     
}



void decompileExprList(AST *node){
    if (node->son[0]!=0){
        fprintf(decompilationFile, " ");
        decompileSwitchExpr(node->son[0]);
    
    if (node->son[1]!=0){
        fprintf(decompilationFile, ",");
        decompileExprList(node->son[1]);
    }
}
}

void decompilePrint(AST* node){
    
    fprintf(decompilationFile, "print ");
    //decompileSwitchExpr(node->son[0]);
    //astPrint(node->son[0],0);
    //decompileSwitchExpr(node->son[0]);
    decompileExprList(node->son[0]);
    //exit(5);
}


void decompileReturn(AST* node){
    
    fprintf(decompilationFile, "return ");
    decompileSwitchExpr(node->son[0]);
    //exit(5);
}


void decompileAttr(AST* node){
    //identifier '=' expression       { $$ = astCreate(AST_ATTR,0,$1,$3,0,0); }
    
    fprintf(decompilationFile, node->son[0]->symbol->text);
    fprintf(decompilationFile, " = ");
    
    //fprintf(decompilationFile, "expression");
   decompileSwitchExpr(node->son[1]);
    
}


void decompileVecAttr(AST* node){
    //|identifier '[' expression ']' '=' expression      { $$ = astCreate(AST_VEC_ATTR,0,$1,$3,$6,0); }
    fprintf(decompilationFile, node->son[0]->symbol->text);
    //astPrint(node->son[1],0);
    fprintf(decompilationFile, "[");
    decompileSwitchExpr(node->son[1]);
    fprintf(decompilationFile, "]");
    fprintf(decompilationFile, " = ");
    decompileSwitchExpr(node->son[2]);

}



void decompileMathExprSwitch(AST *node){
    
    if (node->type == AST_NOT){
        decompileNotExpr(node);
        return;
    }
    
    
    if(node->son[0]->son[0]!=0)
     {   decompileSwitchExpr(node->son[0]);
        
     }
        //fprintf(decompilationFile, node->son[0]->son[0]->symbol->text);
    else
        fprintf(decompilationFile, node->son[0]->symbol->text);

    switch(node->type){
        case AST_ADD:fprintf(decompilationFile," + ");break;
        case AST_SUB:fprintf(decompilationFile, " - ");break;
        case AST_MUL:fprintf(decompilationFile," * ");break;
        case AST_DIV:fprintf(decompilationFile, " / ");break;
        case AST_LES:fprintf(decompilationFile," < " );break;
        case AST_GRE:fprintf(decompilationFile," > " );break;
        case AST_OR:fprintf(decompilationFile, " | ");break;
        case AST_AND:fprintf(decompilationFile, " & ");break;
        case AST_NOT:fprintf(decompilationFile," ~ " );printf("\npassou aqui \n");break;
        case AST_LE:fprintf(decompilationFile, " <= ");break;
        case AST_GE:fprintf(decompilationFile," >= " );break;
        case AST_EQ:fprintf(decompilationFile, " == ");break;
        case AST_DIF:fprintf(decompilationFile," != " );break;
        default:printf("\n\ntype not found\n\n");exit(5);break;
   }
    
   if(node->son[1]->son[0]!=0)
        decompileSwitchExpr(node->son[1]);//fprintf(decompilationFile, node->son[1]->son[0]->symbol->text);
    else
        fprintf(decompilationFile, node->son[1]->symbol->text);
    //exit(5);
}


void decompileSymbol(AST *node){
    fprintf(decompilationFile,node->symbol->text);  //caso "string"
    }



void decompileIden(AST *node){
   
    fprintf(decompilationFile,node->son[0]->symbol->text);

}
void decompileIdenLit(AST *node){
    //|identifier literal                     { $$ = astCreate(AST_IDENLIT,0,$1,$2,0,0); }
    
    fprintf(decompilationFile,node->son[0]->symbol->text);
    fprintf(decompilationFile," ");
    fprintf(decompilationFile,node->son[1]->symbol->text);
    exit(5);

}

void decompileParenthesis(AST *node){
    fprintf(decompilationFile,"(");
    decompileSwitchExpr(node->son[3]);
    fprintf(decompilationFile,")");

}


void decompileVecSymbol(AST *node){
    //| identifier '[' expression ']'     { $$ = astCreate(AST_VEC_SYMBOL,0,$1,$3,0,0); }
    fprintf(decompilationFile,node->son[0]->symbol->text); 
    fprintf(decompilationFile,"["); 
    decompileSwitchExpr(node->son[1]);
    fprintf(decompilationFile,"]"); 


}






decompileFunctionCall(AST *node)
{
    fprintf(decompilationFile, node->son[0]->son[0]->symbol->text);
    fprintf(decompilationFile, "(");
    if (node->son[0]->son[1] == 0)
    { //caso sem parametros
        
        fprintf(decompilationFile, ")");
    }
    else if (node->son[0]->son[1] != 0 && node->son[0]->son[2] == 0){ //caso com 1 parametro
    
    fprintf(decompilationFile, node->son[0]->son[1]->son[0]->symbol->text);
    fprintf(decompilationFile, ")");
    }
    else if(node->son[0]->son[2]!=0){
    
    fprintf(decompilationFile, node->son[0]->son[1]->son[0]->symbol->text);
    functioncallparameterlist(node->son[0]->son[2]);
    fprintf(decompilationFile, ")");
}






}


void decompileSwitchExpr(AST *node){
    switch(node->type){
        case AST_SYMBOL: decompileSymbol(node);break;
        case AST_VEC_SYMBOL:decompileVecSymbol(node);break;
        case AST_ADD:decompileMathExprSwitch(node);break;
        case AST_SUB:decompileMathExprSwitch(node);break;
        case AST_MUL:decompileMathExprSwitch(node);break;
        case AST_DIV:decompileMathExprSwitch(node);break;
        case AST_LES:decompileMathExprSwitch(node);break;
        case AST_GRE:decompileMathExprSwitch(node);break;
        case AST_OR:decompileMathExprSwitch(node);break;
        case AST_AND:decompileMathExprSwitch(node);break;
        case AST_NOT:decompileNotExpr(node);break;
        case AST_LE:decompileMathExprSwitch(node);break;
        case AST_GE:decompileMathExprSwitch(node);break;
        case AST_EQ:decompileMathExprSwitch(node);break;
        case AST_DIF:decompileMathExprSwitch(node);break;
        case AST_READ:fprintf(decompilationFile,"read");break;
        case AST_FUNCTION_CALL:decompileFunctionCall(node);break;
        case AST_IDENLIT :decompileIdenLit(node);break;
        case AST_IDEN :decompileIden(node);break;
        case AST_PARENTHESIS :decompileParenthesis(node);break;
        




        default:printf("\n\ndecompilation error, expression not found...exiting\n\n");exit(5);break;
    }

}


functioncallparameterlist(AST *node){
    
    
    fprintf(decompilationFile, ", ");
    fprintf(decompilationFile,node->son[0]->son[0]->symbol->text);
    
   if(node->son[1]!=0)
        {
        functioncallparameterlist(node->son[1]);
        }

}


void decompileNotExpr(AST *node){
    fprintf(decompilationFile, " ~");
    decompileSwitchExpr(node->son[0]);
    

}



void switchDecompilation(AST* node){
    if (node == NULL)
        return;

    switch(node->type){
        
        //DECLARAÇÃO DE VARIAVEIS
        case AST_DATA: decompileData(node);/*printf("\n\nentrou no data \n\n")*/;break;
        case AST_VAR_DEC: decompileVarDec(node); /*printf("\n\nentrou no vardec \n\n")*/;break;
        case AST_VEC_DEC: decompileVarDec_vector(node);/* printf("\n\nentrou no vardec_vetor \n\n")*/;break;
        case AST_VEC_DEC_RANGE:decompileVarDec_vector_range(node);/*printf("\n\nentrou no vardec_vetor_range \n\n")*/;break;
        case AST_DECL_BLOCK: decompileDecblock(node);/*printf("\n\nentrou no DECL BLOCK \n\n");*/break;
        case AST_DEC_LIST: decompileDeclist(node);/*printf("\n\nentrou no DECL LIST \n\n")*/;break;
       
        


        //FUNCOES
         case AST_FUNC_LIST:decompileFunctionList(node);/*printf("\n\nentrou no FUNC LIST \n\n")*/;break;
        case AST_FUNC:decompileFunction(node);/*printf("\n\nentrou no FUNC \n\n")*/;break;

        //COMANDOS
        case AST_BLOCK: decompilationBlock(node);/*printf("\n\nentrou no BLOCO \n\n")*/;break;
        case AST_LCMD:decompileCMDLIST(node);/*printf("\n\nentrou no CMDLIST \n\n")*/;break;

        
        
        
        default: printf("\n\ndecompilation error, exiting... \n\n"); exit(101);break;
    }
    return;
}




void decompileIF(AST *node){
    fprintf(decompilationFile,"if (");
    //printf("\n\n = = == = = = = = = = = =\n\n\n");
    astPrint(node->son[1],0);
    decompileSwitchExpr(node->son[0]);
    fprintf(decompilationFile," ) ");
    fprintf(decompilationFile,"\n");
    decompileSwitchCMD(node->son[1]);
    }

void decompileIFElse(AST *node){
    fprintf(decompilationFile,"if (");
    //printf("\n\n = = == = = = = = = = = =\n\n\n");
    astPrint(node->son[1],0);
    decompileSwitchExpr(node->son[0]);
    fprintf(decompilationFile,") ");
    decompileSwitchCMD(node->son[1]);
    fprintf(decompilationFile,"\n    else\n");
    decompileSwitchCMD(node->son[2]);
    }

void decompileUntil(AST *node){
    fprintf(decompilationFile,"until (");
    //printf("\n\n = = == = = = = = = = = =\n\n\n");
    astPrint(node->son[1],0);
    decompileSwitchExpr(node->son[0]);
    fprintf(decompilationFile," ) ");
    fprintf(decompilationFile,"\n");
    decompileSwitchCMD(node->son[1]);
}

void decompileFlowControl(AST *node){
    
    switch(node->son[0]->type){
        case AST_IF:decompileIF(node->son[0]);break;
        case AST_IF_ELSE:decompileIFElse(node->son[0]);break;
        case AST_UNTIL:decompileUntil(node->son[0]);break;
        default:printf("\nFLOW CONTROL NOT FOUND...exiting\n");exit(5);break;
}

}

void decompilationComeFrom(AST *node){

    //|KW_COMEFROM ':' expression       { $$ = astCreate(AST_COMEFROM,0,$3,0,0,0); }
    fprintf(decompilationFile,"comefrom: ");
    decompileSwitchExpr(node->son[0]);
}


void decompileSwitchCMD(AST* node){
    // printf("\n\nCHEGOU AQUI no switch CMD");
    //exit(201);
    fprintf(decompilationFile,"    ");
    switch(node->type){
        case AST_ATTR: decompileAttr(node);break;
        case AST_VEC_ATTR:decompileVecAttr(node);break;
        case AST_PRINT:decompilePrint(node);break;
        case AST_RETURN:decompileReturn(node);break;
        case AST_FLOW_CONTROL:decompileFlowControl(node);break;
        case AST_BLOCK:decompilationBlock(node);break;
        case AST_COMEFROM:decompilationComeFrom(node);break;
        case AST_IDENLIT:decompileIdenLit(node);break;
        case AST_IDEN:decompileIden(node);break;




        default:printf("\n\ndecompilation error, cmd not found...exiting\n\n");exit(5);break;
    }
    }

void decompileCMDLIST(AST* node){
    if(node->son[0]!=0){
    fprintf(decompilationFile, "\n");
    decompileSwitchCMD(node->son[0]);
    fprintf(decompilationFile, " ;");
   
    if(node->son[1]!=0)
        decompileCMDLIST(node->son[1]);
    }
    if(node->son[0]==0){
        fprintf(decompilationFile, " ;");

    }
    
}




void decompile(FILE* outFile, AST* node){
    
    if (node == NULL)
        return;
    //printf(" \n\n\npassou do return oi\n\n\n");
    decompilationFile = outFile;
    //decompileData(node);
    switchDecompilation(node);
}   