#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"
// Create a new tree node with the specified type and value
tree_t *create_tree(char type, int val, tree_list_t *child, int isbool)
{
    tree_t *node = (tree_t *)malloc(sizeof(tree_t));
    node->type = type;
    node->isbool = isbool;
    if (node->type == 'n')
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

double evaluated_tree(tree_t *root)
{
    double res = 0;
    tree_list_t *child;
    switch (root->type)
    {
    case 'n':
        return root->value.integer;
    case 'u':
        return -evaluated_tree(root->value.children->tree);
    case '+':
        child = root->value.children;
        while (child != NULL)
        {
            res += evaluated_tree(child->tree);
            child = child->next;
        }
        return res;
    case '-':
        res = evaluated_tree(root->value.children->tree);
        child = root->value.children->next;
        while (child != NULL)
        {
            res -= evaluated_tree(child->tree);
            child = child->next;
        }
        return res;
    case '*':
        res = 1;
        child = root->value.children;
        while (child != NULL)
        {
            res *= evaluated_tree(child->tree);
            child = child->next;
        }
        return res;

    case '/':
        res = evaluated_tree(root->value.children->tree);
        child = root->value.children;
        while (child != NULL)
        {
            res /= evaluated_tree(child->tree);
            child = child->next;
        }
        return res;
    case '<':
        return evaluated_tree(root->value.children->tree) < evaluated_tree(root->value.children->next->tree);
    case '>':
        return evaluated_tree(root->value.children->tree) > evaluated_tree(root->value.children->next->tree);
    case 'I':
        return evaluated_tree(root->value.children->tree) <= evaluated_tree(root->value.children->next->tree);
    case 'S':
        return evaluated_tree(root->value.children->tree) >= evaluated_tree(root->value.children->next->tree);
    case '=':
        return evaluated_tree(root->value.children->tree) == evaluated_tree(root->value.children->next->tree);
    case '!':
        return evaluated_tree(root->value.children->tree) != evaluated_tree(root->value.children->next->tree);
    case '&':
        return evaluated_tree(root->value.children->tree) && evaluated_tree(root->value.children->next->tree);
    case '|':
        return evaluated_tree(root->value.children->tree) || evaluated_tree(root->value.children->next->tree);
    default:
        break;
    }
    return -1;
}

// Traverse the tree and print the values of all nodes
void print_tree(tree_t *root)
{
    switch (root->type)
    {
    case 'n':
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
            print_tree(child->tree);
            child = child->next;
        }
        break;
    default:
        break;
    }
}
void free_tree(tree_t *arbre)
{
    if (!arbre)
    {
        return;
    }

    if (arbre->type != 'n')
    {
        tree_list_t *current = arbre->value.children;
        while (current)
        {
            free_tree(current->tree);
            tree_list_t *next = current->next;
            free(current);
            current = next;
        }
    }
    free(arbre);
}
