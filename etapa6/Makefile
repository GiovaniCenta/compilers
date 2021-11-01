#
# UFRGS - Compiladores B - Giovani da Silva - 2021/ERE - Etapa 6
#

etapa5: main.o lex.yy.o y.tab.o hash.o list.o ast.o decompiler.o semantic.o tacs.o asm.o 
	gcc main.o lex.yy.o y.tab.o hash.o list.o ast.o decompiler.o semantic.o  tacs.o asm.o -o etapa6

main.o: main.c
	gcc -c main.c

hash.o: hash.c
	gcc -c hash.c

list.o: list.c
	gcc -c list.c

tacs.o: tacs.c
	gcc -c tacs.c

ast.o: ast.c
	gcc -c ast.c

decompiler.o: decompiler.c
	gcc -c decompiler.c --no-warnings

semantic.o: semantic.c
	gcc -c semantic.c

stack.o: stack.c
	gcc -c stack.c
	
lex.yy.o: lex.yy.c y.tab.o
	gcc -c lex.yy.c

y.tab.o: y.tab.c
	gcc -c y.tab.c

asm.o: asm.c
	gcc -c asm.c


y.tab.c: parser.y
	yacc -d parser.y 

lex.yy.c: scanner.l 
	lex scanner.l

clean:
	rm lex.yy.c y.tab.c y.tab.h *.o etapa6
