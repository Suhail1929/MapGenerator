#ifndef HACH_TABLE_H
#define HACH_TABLE_H
typedef struct Table
{
  list_t *tab;
  int size;
} hach_t;

int hach(hach_t *t, variable_t var);

void insert_hach(hach_t *t, variable_t var);

cell_t *search_hach(hach_t *t, variable_t var);

void delete_hach(hach_t *t, cell_t *c);

unsigned long ch_to_int(char *str);

void init_hachtable(hach_t *t, int size);

void destroy_hachtable(hach_t *t);

void display_hachtable(hach_t *t);

int count_hachtable(hach_t *t);
#endif