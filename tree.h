#include <stdio.h>
#include <stdlib.h>

/**
 * @brief struct of a tree node
 *
 */

typedef struct tree_t tree_t;

/**
 * @brief struct of a tree list
 *
 */
typedef struct tree_list_t tree_list_t;

struct tree_t
{
    char type; // n = entier ...
    int isbool;
    union
    {
        int integer;
        struct tree_list_t *children; // liste des fils
    } value;
};

struct tree_list_t
{
    tree_t *tree;
    tree_list_t *next;
};

/**
 * @brief Create a tree object
 *
 * @param type
 * @param val
 * @param child
 * @param isbool
 * @return tree_t*
 */

tree_t *create_tree(char type, int val, tree_list_t *child, int isbool);

/**
 * @brief Add a child node to the specified parent node
 *
 * @param parent
 * @param child
 */
double calculate_expression(tree_t *root);

/**
 * @brief Create a tree list object
 *
 * @param tree
 * @param child
 * @return tree_list_t*
 */
tree_list_t *create_tree_list(tree_t *tree, tree_list_t *child);

/**
 * @brief Add a child node to the specified parent node
 *
 * @param parent
 * @param child
 */
void add_child_node(tree_t *parent, tree_t *child);

/**
 * @brief Display the tree
 *
 * @param root
 */
void display_tree(tree_t *root);

/**
 * @brief Display the tree list
 *
 * @param root
 */

void display_tree_list(tree_list_t *root);

/**
 * @brief Free the tree
 *
 * @param arbre
 */
void free_tree(tree_t *arbre);