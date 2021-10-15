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

%token TK_IDENTIFIER

%token LIT_INTEGER   
%token LIT_CHAR      
%token LIT_STRING    

%token TOKEN_ERROR


%left '<' '>' '&' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF 
%left '|'
%left '^'
%right '~' 
%left '+' '-'
%left '*' '/'


%%

program: 
	KW_DATA '{' declist '}'  functionlist
    ;



cmd_list:
    cmd ';' cmd_list
    |cmd ';'
    ;


cmd:
    identifier '=' expression
    |identifier '[' literal ']' '=' expression
    |identifier '[' expression ']' '=' expression
    |KW_PRINT expression_list
    |KW_RETURN expression
    |KW_COMEFROM ':' expression
    |flow_control
    |block
    |identifier
    |

    ;


flow_control:
    KW_IF '(' expression ')' cmd
    |KW_IF '(' expression ')' cmd KW_ELSE cmd
    |KW_UNTIL '(' expression ')' cmd
    ;

block: '{' cmd_list '}'
|'{' '}'
;




expression:
    identifier
    | identifier '[' expression ']' 
    | literal_withstring
    | expression '+' expression 
    | expression '-' expression 
    | expression '*' expression 
    | expression '/' expression
    | expression '<' expression
    | expression '>' expression 
    | expression '|' expression
    | expression '&' expression
    | expression '~' expression
    | '~' expression
    |'(' expression ')'
    | expression OPERATOR_LE expression
    | expression OPERATOR_GE expression 
    | expression OPERATOR_EQ expression
    | expression OPERATOR_DIF expression
    |identifier literal
    |functioncall
    |KW_READ
    |function
    |identifier '(' expression_list ')'
    ;

expression_list:
    expression
    |expression ',' expression_list
    ;

functioncall:
    identifier '(' parameter parameterslist ')'
    |identifier '(' ')'
    ;


functionlist:
    function functionlist
    |
    ;



function:
    type ':' identifier '(' parameter parameterslist ')' block
    |type ':' identifier '(' ')' block
    ;

parameterslist:
    |',' parameter parameterslist
    ;



parameter:
    type ':' identifier
    ;




declist:
    dec ';' declist
    | 
    ;


dec:
	type ':' identifier '=' literal
    | type '[' literal ']' ':' identifier '=' litlist
    | type '[' LIT_INTEGER OPERATOR_RANGE LIT_INTEGER ']' ':' identifier '=' litlist
    | type '[' LIT_INTEGER OPERATOR_RANGE LIT_INTEGER ']' ':' identifier
    | type '[' literal ']' ':' identifier
    ;

litlist:
    literal litlist
    |
    ;

literal_withstring:
    literal
    |LIT_STRING
    ;



literal:
    LIT_CHAR
    | LIT_INTEGER
    ;

identifier:
    TK_IDENTIFIER
    ;

type:
	KW_INT 
	| KW_FLOAT 
	| KW_CHAR
	;

%%
int yyerror() {
    fprintf(stderr, "Syntax error at line %d \n", getLineNumber());
    exit(3);
}