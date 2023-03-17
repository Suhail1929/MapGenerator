#
# MAIN CONFIGURATION
#

EXEC = main
ANALYSER = analyser
OBJECTS = lex.yy.o y.tab.o hach_table.o tree.o List.o level.o
PROJECT_NAME = main

#
# SUFFIXES
#

.SUFFIXES: .c .o

#
# OBJECTS
#

EXEC_O = $(EXEC:=.o)
OBJECTS_O = $(OBJETS) $(EXEC_O)

#
# ARGUMENTS AND COMPILER
#

CC = gcc
CCFLAGS_STD = -Wall -Werror
CCFLAGS_DEBUG = -D _DEBUG_ 
CCFLAGS = $(CCFLAGS_STD)
CCLIBS = -lfl
YACCFLAGS = -d

#
# RULES
#

all: msg $(OBJECTS) $(EXEC_O)
	@echo "Create executables..."
	@for i in $(EXEC); do \
	$(CC) -o $$i $$i.o $(OBJECTS) $(CCLIBS); \
	done
	@echo "Done."

msg:
	@echo "Create objects..."

debug: CCFLAGS = $(CCFLAGS_STD) $(CCFLAGS_DEBUG)
debug: all

#
# DEFAULT RULES
#

%.o : %.c
	@cd $(dir $<) && ${CC} ${CCFLAGS} -c $(notdir $<) -o $(notdir $@)

lex.yy.c : $(ANALYSER).lex y.tab.h
	@flex $(ANALYSER).lex

y.tab.c y.tab.h : $(ANALYSER).yacc.y
	@yacc ${YACCFLAGS} $(ANALYSER).yacc.y

#
# GENERAL RULES
#

clean:
	@echo "Delete objects, temporary files..."
	@rm -f $(OBJECTS) $(EXEC_O)
	@rm -f *~ *#
	@rm -f $(EXEC)
	@rm -f dependancies
	@rm -f y.tab.* lex.yy.* y.output
	@echo "Done."

depend:
	@echo "Create dependancies..."
	@sed -e "/^# DEPENDANCIES/,$$ d" makefile > dependancies
	@echo "# DEPENDANCIES" >> dependancies
	@for i in $(OBJECTS_O); do \
	$(CC) -MM -MT $$i $(CCFLAGS) `echo $$i | sed "s/\(.*\)\\.o$$/\1.c/"` >> dependancies; \
	done
	@cat dependancies > makefile
	@rm dependancies
	@echo "Done."

#
# CREATE ARCHIVE
#

ARCHIVE_FILES = *

archive: clean
	@echo "Create archive $(PROJECT_NAME)_$(shell date '+%y%m%d.tar.gz')..."
	@REP=`basename "$$PWD"`; cd .. && tar zcf $(PROJECT_NAME)_$(shell date '+%y%m%d.tar.gz') $(addprefix "$$REP"/,$(ARCHIVE_FILES))
	@echo "Done."

# DEPENDANCIES
main.o: main.c List.h hach_table.h include.h
