html: lex.yy.c
	gcc -o html lex.yy.c
lex.yy.c: scanner.l
	lex scanner.l

clean:
	rm lex.yy.c html
