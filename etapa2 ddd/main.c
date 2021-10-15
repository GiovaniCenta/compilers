

int main(int argc, char **argv)
{
    
initMe();
int tok;
if (argc<2)
{
    fprintf(stderr,"Call: ./etapa1 file_name\n");
    exit(1);
}
yyin = fopen(argv[1],"r"); 



yyparse();
hashPrint();
printf("Main done! File has %d lines\n",lineNumber);
exit(0); 

}
