EXECUTABLE = analyser

LEX_FILE = analyser.lex
YACC_FILE = analyser.yacc.y

LEX = flex
LEXFLAGS =
LEXLIB = -lfl
YACC = yacc
YACCFLAGS = -vd
YACCLIB =

$(EXECUTABLE): List.o hach_table.o y.tab.o lex.yy.o
	gcc -o $(EXECUTABLE) List.o hach_table.o lex.yy.o y.tab.o $(LEXLIB) $(YACCLIB) -W -Wall -lm

lex.yy.o: lex.yy.c y.tab.h
	gcc -c lex.yy.c

lex.yy.c: $(LEX_FILE)
	$(LEX) $(LEXFLAGS) $(LEX_FILE)

y.tab.o : y.tab.h y.tab.c
	gcc -c y.tab.c

List.o: List.h List.c
	gcc -c List.c

hach_table.o: hach_table.h hach_table.c
	gcc -c hach_table.c

y.tab.c y.tab.h : $(YACC_FILE)
	$(YACC) $(YACCFLAGS) $(YACC_FILE)

clean:
	rm -f *~ \#* *.o
	rm -f $(EXECUTABLE) $(EXECUTABLE:=.exe)
	rm -f *.core *.stackdump
	rm -f lex.yy.c lex.yy.o
	rm -f y.tab.* y.output
