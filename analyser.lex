%{
#include "tree.h"
#include "y.tab.h"
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

"quit" { return QUIT; }
[a-zA-Z]+ { yylval.str = (char*)malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.str,yytext); return VARIABLE; }
[-+*/<>\n\(\)=,]	 { return *yytext; }
[ \t]	 ;

.        yyerror("Caractère non valide");

%%

