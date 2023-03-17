#ifndef _INCLUDE_
#define _INCLUDE_

#define TAILLE_TABLE 20

#define ERR_DIV_0 1
#define ERR_SYMBOLE 2
#define PUT_ACC 25555559
#define PUT_REJ -25555559
int map[20][60];
extern int yylineno;
int yylex();
hach_t table;
int get(int x, int y);
int put(int x, int y, int z);
int door(int x);
int key(int x);
int gate(int x);
int get_nb_line();
void draw_map(level_t *level);
void map_init();
void yyerror(const char *erreurMsg);

#endif