#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include "level.h"
#include "tree.h"
#include "List.h"
#include "hach_table.h"

int hach(hach_t *t, symbol_t var)
{
  return ch_to_int(var.name) % t->size;
}

void insert_hach(hach_t *t, symbol_t var)
{
  list_t *l = &t->tab[hach(t, var)];
  add_list(l, var);
}

cell_t *search_hach(hach_t *t, symbol_t var)
{
  list_t *l = &t->tab[hach(t, var)];
  return find_cell(l, var);
}

void delete_hach(hach_t *t, cell_t *c)
{
  list_t *l = &t->tab[hach(t, c->var)];
  delete_cell(l, c);
}

unsigned long ch_to_int(char *str)
{
  const unsigned long FNV_offset_basis = 14695981039346656037UL;
  const unsigned long FNV_prime = 1099511628211UL;

  unsigned long hash = FNV_offset_basis;
  int i;

  for (i = 0; str[i] != '\0'; ++i)
  {
    hash ^= (unsigned long)str[i];
    hash *= FNV_prime;
  }

  return hash;
}

void init_hachtable(hach_t *t, int size)
{
  int i;
  t->tab = (list_t *)malloc(size * sizeof(list_t));
  t->size = size;

  for (i = 0; i < t->size; ++i)
  {
    init_list(&t->tab[i]);
  }
}

void destroy_hachtable(hach_t *t)
{
  int i;
  for (i = 0; i < t->size; ++i)
  {
    free_list(&t->tab[i]);
  }
  free(t->tab);
}

void display_hachtable(hach_t *t)
{
  int i;
  for (i = 0; i < t->size; ++i)
  {
    printf("Liste %d :", i);
    display_list(&t->tab[i]);
  }
}
