#ifndef _INCLUDE_
#define _INCLUDE_

#define TAILLE_TABLE 20

#define ERR_DIV_0 1
#define ERR_SYMBOLE 2
#define PUT_ACC 25555559
#define PUT_REJ -25555559

int yylex();
hach_t table;
int get(int x, int y);
int put(int x, int y, int z);

#endif