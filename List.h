#ifndef LISTE_H
#define LISTE_H

#define TYPE_ENTIER 0

typedef struct symbol
{
  int type;
  char *name;
  union
  {
    int integer;
  } value;
} symbol_t;

typedef struct cell
{
  symbol_t var;
  struct cell *prev;
  struct cell *next;
} cell_t;

typedef struct List
{
  cell_t *tete;
} list_t;

int variable_cmp(symbol_t a, symbol_t b);

void init_cell(cell_t *c, symbol_t symbol);

void init_list(list_t *l);

void add_list(list_t *, symbol_t symbol);

void delete_from_list(list_t *, symbol_t symbol);

void delete_cell(list_t *, cell_t *c);

cell_t *find_cell(list_t *, symbol_t symbol);

void display_list(list_t *);

void free_list(list_t *l);

int count_list(list_t *l);

#endif
