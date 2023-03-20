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
GATE {return gate_; }
LADDER { yylval.entier=5; return ENTIER; }
KEY {return key_; }
PROBE { yylval.entier=6; return ENTIER; }
ROBOT { yylval.entier=7; return ENTIER; }
DOOR {return door_; }
EXIT { yylval.entier=8; return ENTIER; }
START { yylval.entier=9; return ENTIER; }
PLAYER { yylval.entier=40; return ENTIER; }
level { return level_; }
end { return end; }
put { return put_; }
get { return get_; }
if  { return IF; }
else  { return ELSE; }
endif  { return endif; }
"++" { return incr; }
"--" { return decr; }
"==" { return egal; }
"<>" { return diff; }
"<=" { return infegal; }
">=" { return supegal; }
"AND" { return et; }
"OR" { return ou; }
[\n] { yylineno++;return *yytext;}
"quit" { return quit; }
[a-zA-Z]+ { yylval.str = (char*)malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.str,yytext); return variable; }
[-+*/<>\(\)=,]	 { return *yytext; }
[ \t]	 {}
[[:space:]] ;
.        yyerror("Caractère non valide");

%%

