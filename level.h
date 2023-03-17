#ifndef _LEVEL_
#define _LEVEL_
typedef enum
{
    // Foreground colors
    FG_BLACK = 30,
    FG_RED = 31,
    FG_GREEN = 32,
    FG_YELLOW = 33,
    FG_BLUE = 34,
    FG_MAGENTA = 35,
    FG_CYAN = 36,
    FG_WHITE = 37,
    // Background Colors
    BK_BLACK = 40,
    BK_RED = 41,
    BK_GREEN = 42,
    BK_YELLOW = 43,
    BK_BLUE = 44,
    BK_MAGENTA = 45,
    BK_CYAN = 46,
    BK_WHITE = 47
} color_t;
// Grid size
#define HEIGHT 20
#define WIDTH 60
// Structure of a level
typedef struct
{
    wint_t cells[HEIGHT][WIDTH];
    color_t colors[HEIGHT][WIDTH];
} level_t;
/**
 * Initialize a level.
 * @param level the level
 */
void level_init(level_t *level);
/**
 * Display a level in the terminal.
 * @param level the level
 */
void level_display(level_t *level);
/**
 * Add a robot in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_robot(level_t *level, int posX, int posY);
/**
 * Add a probe in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_probe(level_t *level, int posX, int posY);
/**
 * Add a empty block in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_empty(level_t *level, int posX, int posY);
/**
 * Add a block in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_block(level_t *level, int posX, int posY);
/**
 * Add a trap in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_trap(level_t *level, int posX, int posY);
/**
 * Add a ladder in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_ladder(level_t *level, int posX, int posY);
/**
 * Add a bomb in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_bomb(level_t *level, int posX, int posY);
/**
 * Add a life in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_life(level_t *level, int posX, int posY);
/**
 * Add a key in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 * @param num the number of the key (1 to 4)
 */
void level_add_key(level_t *level, int posX, int posY, int num);
/**
 * Add a gate in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 * @param num the number of the gate (1 to 4)
 */
void level_add_gate(level_t *level, int posX, int posY, int num);
/**
 * Add a door in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 * @param num the number of the door (1 to 99)
 */
void level_add_door(level_t *level, int posX, int posY, int num);
/**
 * Add a start door in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 * @param num the number of the door (1 to 99)
 */
void level_add_start(level_t *level, int posX, int posY);
/**
 * Add an exit door in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_exit(level_t *level, int posX, int posY);
#endif