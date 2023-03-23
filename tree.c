#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "List.h"
#include "hach_table.h"
#include <wchar.h>
#include <locale.h>
#include "level.h"
#include "include.h"
#include "tree.h"
// Create a new tree node with the specified type and value
tree_t *create_tree(char type, int val, tree_list_t *child, int isbool)
{
    tree_t *node = (tree_t *)malloc(sizeof(tree_t));
    node->type = type;
    node->isbool = isbool;
    if (node->type == 'i')
    {
        node->value.integer = val;
    }
    else
    {
        node->value.children = child;
    }

    return node;
}
tree_t *create_tree_var(char type, int val, tree_list_t *child, int isbool, char *name)
{
    tree_t *node = (tree_t *)malloc(sizeof(tree_t));
    node->type = type;
    node->isbool = isbool;
    if (node->type == 'i')
    {
        node->value.integer = val;
    }
    else
    {
        node->value.children = child;
    }
    node->name = name;
    return node;
}
// Add a child node to the specified parent node
void add_child_node(tree_t *parent, tree_t *child)
{
    tree_list_t *child_node = (tree_list_t *)malloc(sizeof(tree_list_t));
    child_node->tree = child;
    child_node->next = parent->value.children;
    parent->value.children = child_node;
}

tree_list_t *create_tree_list(tree_t *tree, tree_list_t *child)
{
    tree_list_t *list = (tree_list_t *)malloc(sizeof(tree_list_t));
    list->tree = tree;
    list->next = child;
    return list;
}

double calculate_expression(tree_t *root)
{
    if (root == NULL)
        return -1;
    double res = 0;
    tree_list_t *child;
    switch (root->type)
    {
    case 'i':
        return root->value.integer;
    case '+':
        child = root->value.children;
        while (child != NULL)
        {
            res += calculate_expression(child->tree);
            child = child->next;
        }
        return res;
    case '-':
        res = calculate_expression(root->value.children->tree);
        child = root->value.children->next;
        while (child != NULL)
        {
            res -= calculate_expression(child->tree);
            child = child->next;
        }
        return res;
    case '*':
        res = 1;
        child = root->value.children;
        while (child != NULL)
        {
            res *= calculate_expression(child->tree);
            child = child->next;
        }
        return res;

    case '/':
        res = calculate_expression(root->value.children->tree);
        child = root->value.children->next;
        while (child != NULL)
        {
            res /= calculate_expression(child->tree);
            child = child->next;
        }
        return res;
    case '<':
        return calculate_expression(root->value.children->tree) < calculate_expression(root->value.children->next->tree);
    case '>':
        return calculate_expression(root->value.children->tree) > calculate_expression(root->value.children->next->tree);
    case 'I':
        return calculate_expression(root->value.children->tree) <= calculate_expression(root->value.children->next->tree);
    case 'S':
        return calculate_expression(root->value.children->tree) >= calculate_expression(root->value.children->next->tree);
    case '=':
        return calculate_expression(root->value.children->tree) == calculate_expression(root->value.children->next->tree);
    case '!':
        return calculate_expression(root->value.children->tree) != calculate_expression(root->value.children->next->tree);
    case '&':
        return calculate_expression(root->value.children->tree) && calculate_expression(root->value.children->next->tree);
    case '|':
        return calculate_expression(root->value.children->tree) || calculate_expression(root->value.children->next->tree);
    case 'P':
        return put(calculate_expression(root->value.children->tree), calculate_expression(root->value.children->next->tree), calculate_expression(root->value.children->next->next->tree));
    case 'G':
        return get(calculate_expression(root->value.children->tree), calculate_expression(root->value.children->next->tree));
    default:
        break;
    }
    return -1;
}

// Traverse the tree and print the values of all nodes
void display_tree(tree_t *root)
{
    switch (root->type)
    {
    case 'i':
        printf("%d ", root->value.integer);
        break;
    case '+':
    case '-':
    case '*':
    case '/':
        printf("%c ", root->type);
        tree_list_t *child = root->value.children;
        while (child != NULL)
        {
            display_tree(child->tree);
            child = child->next;
        }
        break;
    default:
        break;
    }
}

void display_tree_list(tree_list_t *root)
{
    while (root != NULL)
    {
        printf("%c ", root->tree->type);
        root = root->next;
    }
    printf("\n");
}

void free_tree(tree_t *tree)
{
    if (!tree)
    {
        return;
    }

    if (tree->type != 'i')
    {
        tree_list_t *current = tree->value.children;
        while (current)
        {
            free_tree(current->tree);
            tree_list_t *next = current->next;
            free(current);
            current = next;
        }
    }
    free(tree);
}

void update_variable_in_tree(tree_t *tree, char *name, int value)
{
    if (tree == NULL)
    {
        return;
    }

    // Check if the current node's name matches the given name
    if (tree->name != NULL && strcmp(tree->name, name) == 0)
    {
        // Update the value
        tree->value.integer = value;
    }

    // If the current node has children, traverse them
    if (tree->type != 'i' && tree->value.children != NULL)
    {
        struct tree_list_t *child_list = tree->value.children;

        while (child_list != NULL)
        {
            update_variable_in_tree(child_list->tree, name, value);
            child_list = child_list->next;
        }
    }
}

void update_variable_in_tree_list(tree_list_t *tree_list, char *name, int value)
{
    while (tree_list)
    {
        tree_t *tr = tree_list->tree;
        update_variable_in_tree(tr, name, value);
        tree_list = tree_list->next;
    }
}
tree_t *deep_copy_tree(tree_t *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }

    tree_t *new_tree = malloc(sizeof(tree_t));
    if (new_tree == NULL)
    {
        fprintf(stderr, "Erreur : échec de l'allocation de mémoire pour un nouvel arbre.\n");
        exit(EXIT_FAILURE);
    }

    new_tree->type = tree->type;
    new_tree->isbool = tree->isbool;

    if (tree->name != NULL)
    {
        new_tree->name = strdup(tree->name);
        if (new_tree->name == NULL)
        {
            fprintf(stderr, "Erreur : échec de l'allocation de mémoire pour le nom de l'arbre.\n");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        new_tree->name = NULL;
    }

    if (tree->type == 'i')
    {
        new_tree->value.integer = tree->value.integer;
    }
    else
    {
        new_tree->value.children = NULL;
        tree_list_t *current = tree->value.children;
        tree_list_t *new_tail = NULL;

        while (current != NULL)
        {
            tree_list_t *new_child = malloc(sizeof(tree_list_t));
            if (new_child == NULL)
            {
                fprintf(stderr, "Erreur : échec de l'allocation de mémoire pour un nouveau noeud de liste chaînée.\n");
                exit(EXIT_FAILURE);
            }

            new_child->tree = deep_copy_tree(current->tree);
            new_child->next = NULL;

            if (new_tree->value.children == NULL)
            {
                new_tree->value.children = new_child;
            }
            else
            {
                new_tail->next = new_child;
            }
            new_tail = new_child;
            current = current->next;
        }
    }

    return new_tree;
}
