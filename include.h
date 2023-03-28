#ifndef _INCLUDE_
#define _INCLUDE_

#define TAILLE_TABLE 20

#define ERR_DIV_0 1
#define ERR_SYMBOLE 2
#define PUT_ACC 25555559
#define PUT_REJ -25555559
#define FUNC_ACC 25555558

/**
 * map is a 2D array of int representing the map
 */
int map[20][60];
/**
 * yylineno is the number of the current line
 */
extern int yylineno;
/**
 * yylex is a function that returns the next token
 */
int yylex();
/**
 * table is the hash table
 */
hach_t table;
/**
 * function_list is the list of functions
 */
function_t *function_list;
/**
 * @brief Get the object at the given coordinates
 *
 * @param x
 * @param y
 * @return int
 */

int get(int x, int y);
/**
 * @brief Put the given object at the given coordinates
 *
 * @param x
 * @param y
 * @param z
 * @return int
 */
int put(int x, int y, int z);
/**
 * @brief Get the door id
 *
 * @param x
 * @return int
 */
int door(int x);
/**
 * @brief Get the key id
 *
 * @param x
 * @return int
 */
int key(int x);
/**
 * @brief Get the gate id
 *
 * @param x
 * @return int
 */
int gate(int x);
/**
 * @brief Get the number of the current line
 *
 * @return int
 */
int get_nb_line();
/**
 * @brief Draw the map
 *
 * @param level
 */
void draw_map(level_t *level);
/**
 * @brief Initialize the map
 *
 */
void map_init();
/**
 * yyerror is a function that prints an error message
 */
void yyerror(const char *erreurMsg);

/**
 * @brief Execute while loop
 *
 * @param root
 * @param child
 * @return tree_list_t*
 */

tree_list_t *execute_while(tree_t *booleen, tree_list_t *inst_list);
/**
 * @brief Execute for loop
 *
 * @param var
 * @param start
 * @param end
 * @param incrementeur
 * @param inst_list
 * @return tree_list_t*
 */

tree_list_t *execute_for(char *name, int start, int end_, int incrementeur, tree_list_t *inst_list);

char *afficher_salons();
#endif