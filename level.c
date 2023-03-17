#include <stdio.h>
#include <wchar.h>

#include "level.h"

/**
 * Initialize a level.
 * @param level the level
 */
void level_init(level_t *level) {
    int i, j;
    
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            level->cells[i][j] = btowc(' ');
            level->colors[i][j] = FG_WHITE;
        }
    }
}

/**
 * Display a level in the terminal.
 * @param level the level
 */
void level_display(level_t *level) {
    int i, j;
    
    for(i = 0; i < WIDTH + 2; i++)
        printf("*");
    printf("\n");
    
    for(i = 0; i < HEIGHT; i++) {
        printf("*");
        for(j = 0; j < WIDTH; j++) {
            printf("\x1b[%dm%C\x1b[0m", level->colors[i][j], level->cells[i][j]);
        }
        printf("*\n");
    }
    
    for(i = 0; i < WIDTH + 2; i++)
        printf("*");
    printf("\n");
}

/**
 * Add a robot in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_robot(level_t *level, int posX, int posY) {
    int i, j;
    
    for(i = posY; i < posY + 4; i++)
        for(j = posX; j < posX + 3; j++)
            level->colors[i][j] = FG_WHITE;
    
    level->cells[posY][posX] = 0x250C;             // ┌
    level->cells[posY][posX] = 0x250C;
    level->cells[posY][posX+1] = 0x2534;           // ┴
    level->cells[posY][posX+2] = 0x2510;           // ┐
    level->cells[posY+1][posX] = 0x2514;           // └
    level->cells[posY+1][posX+1] = 0x252C;         // ┬
    level->cells[posY+1][posX+2] = 0x2518;         // ┘
    level->cells[posY+2][posX] = 0x2500;           // ─
    level->cells[posY+2][posX+1] = 0x253C;         // ┼
    level->cells[posY+2][posX+2] = 0x2500;         // ─
    level->cells[posY+3][posX] = 0x250C;           // ┌
    level->cells[posY+3][posX+1] = 0x2534;         // ┴
    level->cells[posY+3][posX+2] = 0x2510;         // ┐
}

/**
 * Add a probe in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_probe(level_t *level, int posX, int posY) {
    int i, j;
    
    for(i = posY; i < posY + 2; i++)
        for(j = posX; j < posX + 3; j++)
            level->colors[i][j] = FG_WHITE;
    
    level->cells[posY][posX] = 0x251C;             // ├
    level->cells[posY][posX+1] = 0x2500;           // ─
    level->cells[posY][posX+2] = 0x2524;           // ┤
    level->cells[posY+1][posX] = 0x2514;           // └
    level->cells[posY+1][posX+1] = 0x2500;         // ─
    level->cells[posY+1][posX+2] = 0x2518;         // ┘
}

/**
 * Add a empty block in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_empty(level_t *level, int posX, int posY) {
    level->cells[posY][posX] = btowc(' ');
    level->colors[posY][posX] = FG_WHITE;
}

/**
 * Add a block in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_block(level_t *level, int posX, int posY) {
    level->cells[posY][posX] = btowc(' ');
    level->colors[posY][posX] = BK_BLUE;
}

/**
 * Add a trap in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_trap(level_t *level, int posX, int posY) {
    level->cells[posY][posX] = btowc('#');
    level->colors[posY][posX] = BK_BLUE;
}

/**
 * Add a ladder in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_ladder(level_t *level, int posX, int posY) {
    int i;
    
    for(i = posX; i < posX + 3; i++)
        level->colors[posY][i] = FG_YELLOW;
    
    level->cells[posY][posX] = 0x251C;             // ├
    level->cells[posY][posX+1] = 0x2500;           // ─
    level->cells[posY][posX+2] = 0x2524;           // ┤
}

/**
 * Add a bomb in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_bomb(level_t *level, int posX, int posY) {
    level->cells[posY][posX] = btowc('O');
    level->colors[posY][posX] = FG_WHITE;
}

/**
 * Add a life in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_life(level_t *level, int posX, int posY) {
    level->cells[posY][posX] = btowc('V');
    level->colors[posY][posX] = FG_RED;
}

/**
 * Add a key in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 * @param num the number of the key (1 to 4)
 */
void level_add_key(level_t *level, int posX, int posY, int num) {
    level->cells[posY][posX] = btowc('0' + num);
    level->cells[posY+1][posX] = 0x2518;         // ┘
    
    switch(num) {
        case 1:        
            level->colors[posY][posX] = BK_MAGENTA;
            level->colors[posY+1][posX] = FG_MAGENTA;
            break;
        case 2:        
            level->colors[posY][posX] = BK_GREEN;
            level->colors[posY+1][posX] = FG_GREEN;
            break;
        case 3:        
            level->colors[posY][posX] = BK_YELLOW;
            level->colors[posY+1][posX] = FG_YELLOW;
            break;
        case 4:        
            level->colors[posY][posX] = BK_BLUE;
            level->colors[posY+1][posX] = FG_BLUE;
            break;
    }        
}

/**
 * Add a gate in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 * @param num the number of the gate (1 to 4)
 */
void level_add_gate(level_t *level, int posX, int posY, int num) {
    level->cells[posY][posX] = 0x253C;           // ┼
    switch(num) {
        case 1:        
            level->colors[posY][posX] = FG_MAGENTA;
            break;
        case 2:        
            level->colors[posY][posX] = FG_GREEN;
            break;
        case 3:        
            level->colors[posY][posX] = FG_YELLOW;
            break;
        case 4:        
            level->colors[posY][posX] = FG_BLUE;
            break;
    } 
}

/**
 * Add a door in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 * @param num the number of the door (1 to 99)
 */
void level_add_door(level_t *level, int posX, int posY, int num) {
    int i, j;
    
    level->cells[posY][posX] = btowc('0' + num / 10);
    level->colors[posY][posX] = FG_WHITE;
    level->cells[posY][posX + 1] = btowc('0' + num % 10);
    level->colors[posY][posX + 1] = FG_WHITE;
    level->cells[posY][posX + 2] = btowc(' ');
    level->colors[posY][posX + 2] = BK_GREEN;
    
    for(i = posY + 1; i < posY + 4; i++)
        for(j = posX; j < posX + 3; j++) {
            level->cells[i][j] = btowc(' ');
            level->colors[i][j] = BK_GREEN;
        }
}

/**
 * Add a start door in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 * @param num the number of the door (1 to 99)
 */
void level_add_start(level_t *level, int posX, int posY) {
    int i, j;
    
    for(i = posY; i < posY + 4; i++)
        for(j = posX; j < posX + 3; j++) {
            level->cells[i][j] = btowc(' ');
            level->colors[i][j] = BK_MAGENTA;
        }
}

/**
 * Add an exit door in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_exit(level_t *level, int posX, int posY) {
    int i, j;
    
    for(i = posY; i < posY + 4; i++)
        for(j = posX; j < posX + 3; j++) {
            level->cells[i][j] = btowc(' ');
            level->colors[i][j] = BK_YELLOW;
        }
}