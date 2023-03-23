#ifndef LISTE_H
#define LISTE_H

// Definition of a macro for an integer type
#define TYPE_ENTIER 0
#define TYPE_FUNCTION 1

// Definition of a structure for a symbol
typedef struct symbol
{
  int type;   // Type of the symbol (in this case, always TYPE_ENTIER)
  char *name; // Name of the symbol
  union       // A union to hold the value of the symbol
  {
    // function_t *function;
    char *string; // The string value of the symbol
    int integer;  // The integer value of the symbol
  } value;
} symbol_t;

// Definition of a structure for a cell in the linked list
typedef struct cell
{
  symbol_t var;      // The symbol stored in the cell
  struct cell *prev; // Pointer to the previous cell in the list
  struct cell *next; // Pointer to the next cell in the list
} cell_t;

// Definition of a structure for the linked list itself
typedef struct List
{
  cell_t *tete; // Pointer to the first cell in the list
} list_t;

// Function prototypes for the linked list operations
// Create a new symbol or update the value of an existing symbol
void crt_or_upd_symbol(int type, char *name, int value);

// Print the value of a symbol with the given name
int print_var(char *name);

// Increment the value of a symbol with the given name
int incr_var(char *name);

// Decrement the value of a symbol with the given name
int decr_var(char *name);

// Compare two symbols by value
int variable_cmp(symbol_t a, symbol_t b);

// Initialize a cell with the given symbol
void init_cell(cell_t *c, symbol_t symbol);

// Initialize a linked list
void init_list(list_t *l);

// Add a new symbol to the linked list
void add_list(list_t *, symbol_t symbol);

// Remove a symbol from the linked list
void delete_from_list(list_t *, symbol_t symbol);

// Remove a cell from the linked list
void delete_cell(list_t *, cell_t *c);

// Find the cell containing the given symbol
cell_t *find_cell(list_t *, symbol_t symbol);

// Display the contents of the linked list
void display_list(list_t *);

// Free the memory used by the linked list
void free_list(list_t *l);

// Count the number of cells in the linked list
int count_list(list_t *l);

#endif
