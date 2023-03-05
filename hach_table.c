#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#include "hach_table.h"

int hach(hach_t *t, variable_t var)
{
  return ch_to_int(var.name) % t->size;
}

void insert_hach(hach_t *t, variable_t var)
{
  list_t *l = &t->tab[hach(t, var)];
  add_list(l, var);
}

cell_t *search_hach(hach_t *t, variable_t var)
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
  unsigned long mul = 1, size = strlen(str);
  unsigned long res = 0;
  int i;

  for (i = size - 1; i >= 0; --i)
  {
    res += mul * str[i];
    mul *= 128;
  }

  return res;
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

int count_hachtable(hach_t *t)
{
  int count = 0, i;
  for (i = 0; i < t->size; ++i)
  {
    count += count_list(&t->tab[i]);
  }
  return count;
}
