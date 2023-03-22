#ifndef HACH_TABLE_H
#define HACH_TABLE_H

/**
 * @brief hash table
 *
 *
 */
typedef struct Table
{
  list_t *tab;
  int size;
} hach_t;

/**
 * @brief hash function
 *
 * @param t
 * @param var
 * @return int
 */
int hach(hach_t *t, symbol_t var);

/**
 * @brief insert a symbol in the hash table
 *
 * @param t
 * @param var
 */

void insert_hach(hach_t *t, symbol_t var);

/**
 * @brief search a symbol in the hash table
 *
 * @param t
 * @param var
 * @return cell_t*
 */

cell_t *search_hach(hach_t *t, symbol_t var);

/**
 * @brief delete a symbol in the hash table
 *
 * @param t
 * @param c
 */

void delete_hach(hach_t *t, cell_t *c);

/**
 * @brief convert a string to an integer
 *
 * @param str
 * @return unsigned long
 */

unsigned long ch_to_int(char *str);

/**
 * @brief initialize a hash table
 *
 * @param t
 * @param size
 */

void init_hachtable(hach_t *t, int size);

/**
 * @brief destroy a hash table
 *
 * @param t
 */

void destroy_hachtable(hach_t *t);

/**
 * @brief display a hash table
 *
 * @param t
 */

void display_hachtable(hach_t *t);

#endif