#ifndef _INCLUDE_
#define _INCLUDE_

#define TAILLE_TABLE 20

#define ERR_DIV_0 1
#define ERR_SYMBOLE 2

int yylex();
int yyerror(char *s);
hach_t table;

int fact(int a);

#endif