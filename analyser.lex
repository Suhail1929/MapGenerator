%{
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "y.tab.h"
#include "List.h"
#include "hach_table.h"
#include <wchar.h>
#include "level.h"
#include "include.h"
extern void yyerror(const char *msg);
extern int yylineno;
%}

%option nounput
%option noinput

%%

[0-9]+	 {
           yylval.entier = atoi(yytext);
           return ENTIER;
         }
TRUE {yylval.entier=1; return ENTIER; }
FALSE {yylval.entier=0; return ENTIER; }
BLOCK { yylval.entier=1; return ENTIER; }
DELETE { yylval.entier=0; return ENTIER; }
LIFE { yylval.entier=2; return ENTIER; }
BOMB { yylval.entier=3; return ENTIER; }
TRAP { yylval.entier=4; return ENTIER; }
GATE {return GATE; }
LADDER { yylval.entier=5; return ENTIER; }
KEY {return KEY; }
PROBE { yylval.entier=6; return ENTIER; }
ROBOT { yylval.entier=7; return ENTIER; }
DOOR {return DOOR; }
EXIT { yylval.entier=8; return ENTIER; }
START { yylval.entier=9; return ENTIER; }
PLAYER { yylval.entier=40; return ENTIER; }
level { return LEVEL; }
end { return END; }
put { return PUT; }
get { return GET; }
"++" { return INCREMENT; }
"--" { return DECREMENT; }
"==" { return EGAL; }
"<>" { return DIFFERENT; }
"<=" { return INFEGAL; }
">=" { return SUPEGAL; }
"AND" { return ET; }
"OR" { return OU; }
\n { yylineno++;return *yytext;}
"quit" { return QUIT; }
[a-zA-Z]+ { yylval.str = (char*)malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.str,yytext); return VARIABLE; }
[-+*/<>\(\)=,]	 { return *yytext; }
[ \t]	 ;

.        yyerror("Caractère non valide");

%%

