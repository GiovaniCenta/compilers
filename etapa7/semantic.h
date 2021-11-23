#ifndef SEMANTIC_HEADER
#define SEMANTIC_HEADER

#include "ast.h"
#include "hash.h"
#include "semantic.h"

extern int SemanticErrors;

//void compiler_error(void);

void check_dec_and_set_two(AST *node,int symboltype);
void check_and_set_declarations(AST* node);
void check_undeclared();
int get_semantic_errors();
void check_operands(AST *node);
int is_number(AST *node);
int count_numparam(AST *node);
void check_numparam(AST *node);
void check_vectorparam_nature(AST *node);
void check_dec_var_nature(AST *node);
void check_commands(AST *node);
void check_return_nature(AST *node,int func_dataype);
void check_param_nature(AST *node, int func_datatype);
void decl_parameters(AST *node);
void call_parameters(AST *node);
void check_parameters(AST *node);
void check_label(AST *node);
int cont_vector_param(AST *node);
void check_param_out_of_function(AST *node);

void declare_parameters(AST *node,char *parameter_function_name);
void declare_parameters2(AST *node,char *parameter_function_name);
void check_parameter_in_other_function(AST *node,char *function_name);

void check_vector_length(AST *node);






#endif