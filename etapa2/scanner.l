%{
#include "y.tab.h"
#include "hash.c"
#include "y.tab.c"

int running = 1;
int lineNumber = 1;

int isRunning(void){
        return running;
    }

int getLineNumber(void){
        return lineNumber;
    }
void initMe(void){
    hashInit();
}

%}

%x COMMENT

%%

"data"          return KW_DATA;
"char"          return KW_CHAR;
"int"           return KW_INT;
"float"         return KW_FLOAT;
"if"            return KW_IF;
"else"          return KW_ELSE;
"until"         return KW_UNTIL;
"comefrom"      return KW_COMEFROM;
"read"          return KW_READ;
"print"         return KW_PRINT;
"return"        return KW_RETURN;
     

[\,\;\:\(\)\[\]\{\}\+\-\*\/\|\&\~\=\>\<]      return yytext[0];

"<="    return OPERATOR_LE;
">="    return OPERATOR_GE;
"=="    return OPERATOR_EQ;
"!="    return OPERATOR_DIF;
"\.\."   return OPERATOR_RANGE;

[ \t]
[\n]            lineNumber++;

"##".*
"#/"           {BEGIN(COMMENT);}


[\+\-]?([0-9]+[\.])?[0-9]+e[\+\-]?[0-9]+    {printf("\nPONTO FLUTUANTE\n");exit(10);}

[a-zA-Z]+[a-zA-Z0-9 ]*[a-zA-Z0-9]+|[a-zA-Z]+  {hashInsert(yytext,SYMBOL_IDENTIFIER); return TK_IDENTIFIER;}


[0-9]+      {hashInsert(yytext,SYMBOL_LIT_INT);return LIT_INTEGER;}
'(.)'        {hashInsert(yytext,SYMBOL_LIT_CHAR);return LIT_CHAR;}
\"[^\"^\n]*\"   {hashInsert(yytext,SYMBOL_LIT_STRING);return LIT_STRING;}





.       return TOKEN_ERROR;


<COMMENT>.
<COMMENT>"/#"   {BEGIN(INITIAL);}
<COMMENT>"/n"   {++lineNumber;}


%%

#include "main.c"

int yywrap()
{
    running = 0;
    return 1;
}