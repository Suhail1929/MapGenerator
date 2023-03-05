#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int variable_cmp(variable_t a, variable_t b)
{
  return strcmp(a.name, b.name);
}

void init_cell(cell_t *c, variable_t variable)
{
  char *str = NULL;

  if (c != NULL)
  {
    str = (char *)malloc((strlen(variable.name) + 1) * sizeof(char));
    strcpy(str, variable.name);
    variable.name = str;

    c->var = variable;
    c->prev = NULL;
    c->next = NULL;
  }
}

void init_list(list_t *l)
{
  l->tete = NULL;
}

void add_list(list_t *l, variable_t variable)
{
  if (l != NULL)
  {
    cell_t *c = (cell_t *)malloc(sizeof(cell_t));
    init_cell(c, variable);

    c->next = l->tete;
    if (l->tete != NULL)
    {
      l->tete->prev = c;
    }
    l->tete = c;
  }
}

void delete_from_list(list_t *l, variable_t variable)
{
  if (l != NULL)
  {
    cell_t *c = find_cell(l, variable);
    delete_cell(l, c);
    free(c->var.name);
    free(c);
  }
}

void delete_cell(list_t *l, cell_t *c)
{
  if (l != NULL && c != NULL)
  {

    if (c->prev != NULL)
    {
      c->prev->next = c->next;
    }
    else
    {
      l->tete = c->next;
    }

    if (c->next != NULL)
    {
      c->next->prev = c->prev;
    }
  }
}

cell_t *find_cell(list_t *l, variable_t variable)
{
  if (l != NULL)
  {
    cell_t *c = l->tete;
    while (c != NULL && variable_cmp(c->var, variable) != 0)
    {
      c = c->next;
    }
    return c;
  }
  return NULL;
}

void display_list(list_t *l)
{
  cell_t *c = l->tete;
  while (c != NULL)
  {
    switch (c->var.type)
    {
    case TYPE_ENTIER:
      printf("%s (value %d)", c->var.name, c->var.value.intiger);
      break;
    default:
      break;
    }

    if (c->next != NULL)
    {
      printf("-> ");
    }
    c = c->next;
  }
  printf("\n");
}

void free_list(list_t *l)
{
  cell_t *c = l->tete, *tmp = NULL;
  while (c != NULL)
  {
    tmp = c->next;
    free(c->var.name);
    free(c);
    c = tmp;
  }
}

int count_list(list_t *l)
{
  cell_t *c = l->tete;
  int count = 0;
  while (c != NULL)
  {
    ++count;
    c = c->next;
  }
  return count;
}
