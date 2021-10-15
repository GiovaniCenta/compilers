%{

#define MAX 1000

int running = 1;
int lineNumber = 1;
int i = 0;

int isRunning(void){
        return running;
    }

int getLineNumber(void){
        return lineNumber;
    }


%}



%%
\<p.*\>.*\<\/p\> {write_to_file(yytext);}


[ \t]
[\n]            lineNumber++;
. ;


%%



int yywrap()
{
    running = 0;
    return 1;
}

void write_to_file(char* text){
    
    printf("\nParagrafo: %s",text);
    

    const char* fileName = "00";
    const char* fileType = ".html";

    FILE *output_html[i];
    char name_buffer[512];
    sprintf(name_buffer,"%s%d%s",fileName,i,fileType);
    output_html[i] = fopen(name_buffer,"w");
    fprintf(output_html[i],text);

    i++;


}

int main(int argc, char **argv)
{
    

int tok;
if (argc<2)
{
    fprintf(stderr,"Call: ./html file_name\n");
    exit(1);
}
yyin = fopen(argv[1],"r"); 



while(isRunning()){
    tok=yylex();
    if(isRunning() ==0)
        break;
    
    
    }
printf("Main done! File has %d lines\n",lineNumber);

exit(0);

}