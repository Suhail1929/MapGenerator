#ifndef LISTE_H
#define LISTE_H

#define TYPE_ENTIER 0

typedef struct variable
{
  int type;
  char *name;
  union
  {
    int intiger;
  } value;
} variable_t;

typedef struct cell
{
  variable_t var;
  struct cell *prev;
  struct cell *next;
} cell_t;

typedef struct List
{
  cell_t *tete;
} list_t;

int variable_cmp(variable_t a, variable_t b);

void init_cell(cell_t *c, variable_t variable);

void init_list(list_t *l);

void add_list(list_t *, variable_t variable);

void delete_from_list(list_t *, variable_t variable);

void delete_cell(list_t *, cell_t *c);

cell_t *find_cell(list_t *, variable_t variable);

void display_list(list_t *);

void free_list(list_t *l);

int count_list(list_t *l);

#endif
