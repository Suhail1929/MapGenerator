#include <stdio.h>
#include <stdlib.h>

typedef struct tree_t tree_t;
typedef struct tree_list_t tree_list_t;

struct tree_t
{
    char type; // n = entier, f = fonction
    int isbool;
    union
    {
        int integer; // si type == 0
        // char op;        // si type == 1
        // char *function; // si type == 2
        struct tree_list_t *children; // liste des fils
    } value;
};

struct tree_list_t
{
    tree_t *tree;
    tree_list_t *next;
};

tree_t *create_tree(char type, int val, tree_list_t *child, int isbool);
double evaluated_tree(tree_t *root);
tree_list_t *create_tree_list(tree_t *tree, tree_list_t *child);
void add_child_node(tree_t *parent, tree_t *child);
void print_tree(tree_t *root);
void free_tree(tree_t *arbre);