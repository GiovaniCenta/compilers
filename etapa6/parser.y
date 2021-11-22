
%{
    #include "hash.h"
    #include "ast.h"
    #include "semantic.h"
    #include "tacs.h"
    #include "asm.h"
   
    #include <stdlib.h>
    int yyerror();
    int getLineNumber();
    int yylex();
    AST *mainAST;
    
%}

%union
{
    HASH_NODE *symbol;
    AST *ast;
}



%token KW_CHAR
%token KW_INT
%token KW_FLOAT
%token KW_DATA

%token KW_IF
%token KW_ELSE
%token KW_UNTIL
%token KW_COMEFROM
%token KW_READ
%token KW_PRINT
%token KW_RETURN

%token OPERATOR_LE
%token OPERATOR_GE   
%token OPERATOR_EQ   
%token OPERATOR_DIF  
%token OPERATOR_RANGE

%token<symbol> TK_IDENTIFIER
%token<symbol> LIT_INTEGER   
%token<symbol> LIT_CHAR      
%token<symbol> LIT_STRING    

%token TOKEN_ERROR

%type<ast> KW_DATA
%type<ast> data_decl
%type<ast> cmd
%type<ast> cmd_list
%type<ast> flow_control
%type<ast> block
%type<ast> expression
%type<ast> expression_list
%type<ast> functionlist
%type<ast> function
%type<ast> parameterslist
%type<ast> parameter
%type<ast> declist
%type<ast> dec
%type<ast> litlist
%type<ast> literal_withstring
%type<ast> literal
%type<ast> type
%type<symbol> identifier
%type<ast> functioncall
%type<ast> decl_block 

%type<ast> parameterslist_init
%type<ast> parameter_init

%type<ast> range_values
%type<ast> program


%left '<' '>' '&' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF 
%left '|'
%left '^'
%right '~' 
%left '+' '-'
%left '*' '/'


%%

program: data_decl { $$ = $1;  mainAST = $$;
                 TAC* code;
                check_and_set_declarations($1);
                
                //check_undeclared();
               //check_operands($1);
              
                //check_commands($1);
                 
                
                
                
                
                code = generate_code($1);
                
                tac_print_backwards(code);


                 code = tac_reverse(code);
                 generate_asm(code);
                
                        
               
                
                
                
                
                
                
                }
                ;

data_decl:
    KW_DATA decl_block  functionlist    { $$ = astCreate(AST_DATA,0,$1,$2,$3,0); }
    ;

decl_block:
    '{' declist '}'           { $$ = astCreate(AST_DECL_BLOCK,0,$2,0,0,0); }


cmd_list:
    cmd ';' cmd_list        { $$ = astCreate(AST_LCMD,0,$1,$3,0,0); }
    |cmd ';'                    { $$ = astCreate(AST_LCMD,0,$1,0,0,0); }
    |';'                    { $$ = astCreate(AST_LCMD,0,0,0,0,0); }
    ;


cmd:
    identifier '=' expression       { $$ = astCreate(AST_ATTR,$1,0,$3,0,0); }
    |identifier '[' expression ']' '=' expression      { $$ = astCreate(AST_VEC_ATTR,$1,0,$3,$6,0); }
    |KW_PRINT expression_list                       { $$ = astCreate(AST_PRINT,0,$2,0,0,0); }
    |KW_RETURN expression                           { $$ = astCreate(AST_RETURN,0,$2,0,0,0); }
    |KW_COMEFROM ':' expression       { $$ = astCreate(AST_COMEFROM,0,$3,0,0,0); }
    |flow_control                                    { $$ = astCreate(AST_FLOW_CONTROL,0,$1,0,0,0); }
    |block                                           { $$ = $1; }
    |identifier literal                         { $$ = astCreate(AST_LABEL_LIT,$1,0,$2,0,0); }
    |identifier  { $$ = astCreate(AST_LABEL,$1,0,0,0,0); }
    ;


flow_control:
    KW_IF '(' expression ')' cmd    { $$ = astCreate(AST_IF,0,$3,$5,0,0); }
    |KW_IF '(' expression ')' cmd KW_ELSE cmd  { $$ = astCreate(AST_IF_ELSE,0,$3,$5,$7,0); }
    |KW_UNTIL '(' expression ')' cmd       { $$ = astCreate(AST_UNTIL,0,$3,$5,0,0); }
    ;

block: '{' cmd_list '}' { $$ = astCreate(AST_BLOCK,0,$2,0,0,0); }
|'{' '}'   {$$ = astCreate(AST_BLOCK,0,0,0,0,0);}
;




expression:
    identifier  { $$ = astCreate(AST_IDEN,$1,0,0,0,0); }
    | identifier '[' expression ']'     { $$ = astCreate(AST_VEC_SYMBOL,$1,0,$3,0,0); }
    | expression '+' expression     { $$ = astCreate(AST_ADD,0,$1,$3,0,0); }
    | expression '-' expression     { $$ = astCreate(AST_SUB,0,$1,$3,0,0); }
    | expression '*' expression     { $$ = astCreate(AST_MUL,0,$1,$3,0,0); }
    | expression '/' expression     { $$ = astCreate(AST_DIV,0,$1,$3,0,0); }
    | expression '<' expression     { $$ = astCreate(AST_LES,0,$1,$3,0,0); }
    | expression '>' expression     { $$ = astCreate(AST_GRE,0,$1,$3,0,0); }
    | expression '|' expression     { $$ = astCreate(AST_OR,0,$1,$3,0,0); }
    | expression '&' expression     { $$ = astCreate(AST_AND,0,$1,$3,0,0); }
    | '~' expression     { $$ = astCreate(AST_NOT,0,$2,0,0,0); }
    |'(' expression ')'             { $$ = astCreate(AST_PARENTHESIS,0,0,0,0,$2); }
    | expression OPERATOR_LE expression         { $$ = astCreate(AST_LE,0,$1,$3,0,0); }
    | expression OPERATOR_GE expression         { $$ = astCreate(AST_GE,0,$1,$3,0,0); }
    | expression OPERATOR_EQ expression         { $$ = astCreate(AST_EQ,0,$1,$3,0,0); }
    | expression OPERATOR_DIF expression        { $$ = astCreate(AST_DIF,0,$1,$3,0,0); }
    |identifier literal                     { $$ = astCreate(AST_IDENLIT,$1,0,$2,0,0); }
    |KW_READ                                { $$ = astCreate(AST_READ,0,0,0,0,0); }
    |functioncall                              { $$ = astCreate(AST_FUNCTION_CALL,0,$1,0,0,0); }
    |LIT_CHAR            { $$ = astCreate(AST_SYMBOL_CHAR,$1,0,0,0,0); }
    |LIT_INTEGER       { $$ = astCreate(AST_SYMBOL_INT,$1,0,0,0,0); }
    |LIT_STRING         { $$ = astCreate(AST_SYMBOL_STRING,$1,0,0,0,0); }
    ;

expression_list:
    expression                              { $$ = astCreate(AST_EXP_LIST,0,$1,0,0,0); }
    |expression ',' expression_list         { $$ = astCreate(AST_EXP_LIST,0,$1,$3,0,0); }
    ;


functioncall:
    identifier '(' parameter parameterslist ')'     { $$ = astCreate(AST_FUNCTION_CALL,$1,0,$3,$4,0); }
    |identifier '(' ')'                             { $$ = astCreate(AST_FUNCTION_CALL,$1,0,0,0,0); }
    |identifier '(' parameter ')'     { $$ = astCreate(AST_FUNCTION_CALL,$1,0,$3,0,0); }
    ;

parameterslist: ',' parameter parameterslist                 { $$ = astCreate(AST_PARAMETER_LIST,0,$2,$3,0,0); }
    |   { $$ = astCreate(AST_PARAMETER_LIST,0,0,0,0,0); }
    ;


parameter: expression     { $$ = astCreate(AST_PARAMETER,0,$1,0,0,0); }
    

functionlist:
    function functionlist                   { $$ = astCreate(AST_FUNC_LIST,0,$1,$2,0,0); }               
    |                                       {$$ = 0;}
    ;



function:
    type ':' identifier '(' parameter_init parameterslist_init ')' block    { $$ = astCreate(AST_FUNC,$3,$1,$5,$6,$8); }
	|type ':' identifier '(' ')' block    { $$ = astCreate(AST_FUNC,$3,$1,$6,0,0); }
    |type ':' identifier '(' parameter_init ')' block    { $$ = astCreate(AST_FUNC,$3,$1,$5,$7,0); }
    ;


parameterslist_init: ',' parameter_init parameterslist_init                 { $$ = astCreate(AST_PARAMETER_LIST,0,$2,$3,0,0); }
   |                                 { $$ = astCreate(AST_PARAMETER_LIST,0,0,0,0,0); }
        ;


parameter_init:
    type ':' identifier      { $$ = astCreate(AST_PARAMETER_INIT,$3,$1,0,0,0); }
    ;



declist:
    dec ';' declist   { $$ = astCreate(AST_DEC_LIST,0,$1,$3,0,0);}
    |               {$$=0;}
    ;



dec:
	type ':' identifier '=' literal     { $$ = astCreate(AST_VAR_DEC,$3,$1,0,$5,0); }
    | type '[' literal ']' ':' identifier '=' litlist { $$ = astCreate(AST_VEC_DEC,$6,$1,$3,$8,0); }
    | type '[' range_values OPERATOR_RANGE range_values ']' ':' identifier '=' litlist   { $$ = astCreate(AST_VEC_DEC_RANGE,$8,$1,$5,$3,$10); }
    | type '[' range_values OPERATOR_RANGE range_values ']' ':' identifier        { $$ = astCreate(AST_VEC_DEC_RANGE,$8,$1,$5,$3,0); }
    | type '[' literal ']' ':' identifier   { $$ = astCreate(AST_VEC_DEC,$6,$1,$3,0,0);}
    | {$$=0;}
    ;

litlist:
    literal litlist     { $$ = astCreate(AST_LIT_LIST,0,$1,$2,0,0);}
    |                   {$$ = 0;}
    ;
range_values:
    LIT_INTEGER       { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
    ;

literal_withstring:
    LIT_CHAR            { $$ = astCreate(AST_SYMBOL_CHAR,$1,0,0,0,0); }
    | LIT_INTEGER       { $$ = astCreate(AST_SYMBOL_INT,$1,0,0,0,0); }
    |LIT_STRING         { $$ = astCreate(AST_SYMBOL_STRING,$1,0,0,0,0); }
    ;



literal:
    LIT_CHAR            { $$ = astCreate(AST_SYMBOL_CHAR,$1,0,0,0,0); }
    | LIT_INTEGER       { $$ = astCreate(AST_SYMBOL_INT,$1,0,0,0,0); }
    ;

identifier:
    TK_IDENTIFIER       {$$=$1;}


    ;

type:
	KW_INT        { $$ = astCreate(AST_INT,0,0,0,0,0); }
    | KW_FLOAT      { $$ = astCreate(AST_FLOAT,0,0,0,0,0); }
    | KW_CHAR       { $$ = astCreate(AST_CHAR,0,0,0,0,0); }
    |           { $$ = 0; }
	;

%%
int yyerror() {
    fprintf(stderr, "Syntax error at line %d \n", getLineNumber());
     (3);
}