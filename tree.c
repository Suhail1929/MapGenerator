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
