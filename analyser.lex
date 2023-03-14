%{
#include "tree.h"
#include "y.tab.h"
void yyerror(const char *erreurMsg);
%}

%option nounput
%option noinput

%%

[0-9]+	 {
           yylval.entier = atoi(yytext);
           return ENTIER;
         }
fact { return FACT; }
pow { return POW; }
"++" { return INCREMENT; }
"--" { return DECREMENT; }
"==" { return EGAL; }
"!=" { return DIFFERENT; }
"<=" { return INFEGAL; }
">=" { return SUPEGAL; }
"&&" { return ET; }
"||" { return OU; }

"quit" { return QUIT; }
[a-zA-Z]+ { yylval.str = (char*)malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval.str,yytext); return VARIABLE; }
[-+*/<>\n\(\)=,]	 { return *yytext; }
[ \t]	 ;

.        yyerror("Caractère non valide");

%%

void yyerror(const char *erreurMsg) {
  fprintf(stderr, "\n Erreur '%s' sur '%s'.\n", erreurMsg, yytext);
  exit(EXIT_FAILURE);
}
