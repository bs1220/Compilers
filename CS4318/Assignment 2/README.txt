READ ME

The files needed to build the parser are listed in the Makefile.
They are tree.c tree.h scanner.l parser.y hash.h hash.c. As of now I am using two slip days. Only known issue is a non issue but the assignment does not have s print the symbol table and therefore when the program runs it does show a difference in symbols from a global and local aspect. A scope counter was implemented to keep track internally. 

Below are the instructions in the makefile.
GRAMMAR = parser.y

CFLAGS = -I. -funsigned-char -g -DYYDEBUG 	
YFLAGS = -v -d

mcc: y.tab.o lex.yy.o tree.o hash.o
	gcc $(CFLAGS) -o mcc y.tab.o lex.yy.o tree.o hash.o -ll

y.tab.o: y.tab.c y.tab.h 
	gcc $(CFLAGS) -c y.tab.c 

y.tab.c: $(GRAMMAR)
	yacc $(YFLAGS) $(GRAMMAR)

lex.yy.o: lex.yy.c y.tab.h 
	gcc $(CFLAGS) -c lex.yy.c

lex.yy.c: scanner.l
	lex scanner.l

tree.o: tree.c tree.h
	gcc $(CFLAGS) -c tree.c

hash.o: hash.h hash.c
	gcc $(CFLAGS) -c hash.c
	
clean:
	rm -f y.tab.* y.output lex.yy.* *.o *~ mcc