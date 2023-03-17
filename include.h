#ifndef _INCLUDE_
#define _INCLUDE_

#define TAILLE_TABLE 20

// #define DELETE 0
// #define BLOCK 1
// #define LIFE 2
// #define BOMB 3
// #define TRAP 4
// #define GATE 10
// #define LADDER 5
// #define KEY 20
// #define PROBE 6
// #define ROBOT 7
// #define DOOR 3000
// #define EXIT 8
// #define START 9
// #define PLAYER 40
#define ERR_DIV_0 1
#define ERR_SYMBOLE 2
#define PUT_ACC 25555559
#define PUT_REJ -25555559

int yylex();
hach_t table;
int get(int x, int y);
int put(int x, int y, int z);
int door(int x);
int key(int x);
int gate(int x);
int get_nb_line();
void draw_map(level_t *level);

#endif