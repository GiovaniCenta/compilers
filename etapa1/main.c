

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



while(isRunning()){
    tok=yylex();
    if(isRunning() ==0)
        break;
    
    
    }
printf("Main done! File has %d lines\n",lineNumber);
//hashPrint();
exit(0);

}
