#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include "level.h"
#include "List.h"
#include "hach_table.h"
#include "tree.h"
#include "include.h"

void crt_or_upd_symbol(int type, char *name, int value)
{
  int erreur = 0;
  if (erreur == ERR_DIV_0)
  {
    printf("Erreur de division par zéro\n");
    erreur = 0;
  }
  else if (erreur == ERR_SYMBOLE)
  {
    printf("Symbole inconnu rencontré : %s\n", name);
    erreur = 0;
  }
  else
  {
    symbol_t var;
    cell_t *c;
    var.type = TYPE_ENTIER;
    var.name = name;
    var.value.integer = value;
    c = search_hach(&table, var);
    if (c == NULL)
    {
      insert_hach(&table, var);
    }
    else
    {
      c->var.value.integer = var.value.integer;
    }
  }
}

int print_var(char *name)
{
  symbol_t var;
  var.type = TYPE_ENTIER;
  var.name = name;
  cell_t *c = search_hach(&table, var);
  if (c == NULL)
  {
    printf("Variable inconnue : %s \n", var.name);
    exit(1);
  }
  else
  {
    return c->var.value.integer;
  }
}

int incr_var(char *name)
{
  symbol_t var;
  var.type = TYPE_ENTIER;
  var.name = name;
  cell_t *c = search_hach(&table, var);
  if (c == NULL)
  {
    printf("Variable inconnue : %s \n", var.name);
    exit(1);
  }
  else
  {
    c->var.value.integer++;
    return c->var.value.integer;
  }
}

int decr_var(char *name)
{
  symbol_t var;
  var.type = TYPE_ENTIER;
  var.name = name;
  cell_t *c = search_hach(&table, var);
  if (c == NULL)
  {
    printf("Variable inconnue : %s \n", var.name);
    exit(1);
  }
  else
  {
    c->var.value.integer--;
    return c->var.value.integer;
  }
}

int variable_cmp(symbol_t a, symbol_t b)
{
  return strcmp(a.name, b.name);
}

void init_cell(cell_t *c, symbol_t symbol)
{
  char *str = NULL;

  if (c != NULL)
  {
    str = (char *)malloc((strlen(symbol.name) + 1) * sizeof(char));
    strcpy(str, symbol.name);
    symbol.name = str;

    c->var = symbol;
    c->prev = NULL;
    c->next = NULL;
  }
}

void init_list(list_t *l)
{
  l->tete = NULL;
}

void add_list(list_t *l, symbol_t symbol)
{
  if (l != NULL)
  {
    cell_t *c = (cell_t *)malloc(sizeof(cell_t));
    init_cell(c, symbol);

    c->next = l->tete;
    if (l->tete != NULL)
    {
      l->tete->prev = c;
    }
    l->tete = c;
  }
}

void delete_from_list(list_t *l, symbol_t symbol)
{
  if (l != NULL)
  {
    cell_t *c = find_cell(l, symbol);
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

cell_t *find_cell(list_t *l, symbol_t symbol)
{
  if (l != NULL)
  {
    cell_t *c = l->tete;
    while (c != NULL && variable_cmp(c->var, symbol) != 0)
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
      printf("%s (value %d)", c->var.name, c->var.value.integer);
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
