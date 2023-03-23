#ifndef TREE_H
#define TREE_H
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
    char *name;
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

typedef struct function
{
    char *name;
    tree_list_t *params;
    tree_list_t *instructions;
    struct function *next;
} function_t;

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
 * @brief Create a tree object
 *
 * @param type
 * @param val
 * @param child
 * @param isbool
 * @param name
 * @return tree_t*
 */

tree_t *create_tree_var(char type, int val, tree_list_t *child, int isbool, char *name);

/**
 * @brief Add a child node to the specified parent node
 *
 * @param parent
 * @param child
 */
double calculate_tree(tree_t *root);

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

/**
 * @brief update the value of a variable in the tree
 *
 * @param tree
 * @param name
 * @param value
 */
void update_variable_in_tree(tree_t *tree, char *name, int value);

/**
 * @brief get the value of a variable in the tree list
 *
 * @param tree
 * @param name
 * @param int
 */
void update_variable_in_tree_list(tree_list_t *tree_list, char *name, int value);

/**
 * @brief get a deep copy of a tree
 *
 * @param tree
 */
tree_t *deep_copy_tree(tree_t *tree);

/**
 * @brief create a function call
 * @param func_name
 * @param args
 * */
tree_t *create_tree_func_call(char *func_name, tree_list_t *args);
/**
 * @brief Create a tree prc call object
 *
 * @param func_name
 * @param args
 * @return tree_t*
 */
tree_t *create_tree_prc_call(char *func_name, tree_list_t *args);
#endif