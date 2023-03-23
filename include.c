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

void yyerror(const char *erreurMsg)
{
    fprintf(stderr, "Error at line %d: %s\n", get_nb_line(), erreurMsg);
    exit(EXIT_FAILURE);
}

int put(int y, int x, int z)
{
    if (x > 20 || x < 0 || y > 60 || y < 0)
    {
        yyerror("Coordonnées incorrectes");
        return PUT_REJ;
    }
    else
    {
        map[x][y] = z;
        return PUT_ACC;
    }
}
int get(int x, int y)
{
    if (x > 20 || x < 0 || y > 60 || y < 0)
    {
        yyerror("Coordonnées incorrectes");
        return -1;
    }
    else
    {
        return map[x][y];
    }
}
int door(int x)
{
    if (x > 99 || x < 1)
    {
        yyerror("Clé incorrecte");
        return -1;
    }
    else
    {
        return 300 + x;
    }
}
int key(int x)
{
    if (x > 4 || x < 0)
    {
        yyerror("Clé incorrecte");
        return -1;
    }
    else
    {
        return 20 + x;
    }
}
int gate(int x)
{
    if (x > 4 || x < 0)
    {
        yyerror("Clé incorrecte");
        return -1;
    }
    else
    {
        return 10 + x;
    }
}
int get_nb_line()
{
    return yylineno;
}
void map_init()
{
    int i, j;
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 60; j++)
        {
            map[i][j] = 0;
        }
    }
}
void draw_map(level_t *level)
{
    int x, y;
    for (x = 0; x < 20; x++)
    {
        for (y = 0; y < 60; y++)
        {
            switch (map[x][y])
            {
            case 1:
                level_add_block(level, y, x);
                break;
            case 7:
                level_add_robot(level, y, x);
                break;
            case 6:
                level_add_probe(level, y, x);
                break;
            case 4:
                level_add_trap(level, y, x);
                break;
            case 5:
                level_add_ladder(level, y, x);
                break;
            case 3:
                level_add_bomb(level, y, x);
                break;
            case 2:
                level_add_life(level, y, x);
                break;
            case 21 ... 24:
                level_add_key(level, y, x, map[x][y] - 20);
                break;
            case 11 ... 14:
                level_add_gate(level, y, x, map[x][y] - 10);
                break;
            case 301 ... 399:
                level_add_door(level, y, x, map[x][y] - 300);
                break;
            case 9:
                level_add_start(level, y, x);
                break;
            case 8:
                level_add_exit(level, y, x);
                break;
            default:
                break;
            }
        }
    }
}

tree_list_t *execute_while(tree_t *booleen, tree_list_t *inst_list)
{
    tree_list_t *head = NULL;
    tree_list_t *tail = NULL;
    int bool_ = calculate_tree(booleen);
    while (bool_ == 1)
    {
        bool_ = calculate_tree(booleen);
        tree_list_t *curr = inst_list;
        while (curr != NULL)
        {
            tree_t *copied_tree = deep_copy_tree(curr->tree);
            tree_list_t *new_node = malloc(sizeof(tree_list_t));
            if (new_node == NULL)
            {
                fprintf(stderr, "Erreur : échec de l'allocation de mémoire pour un nouveau noeud de liste chaînée.\n");
                exit(EXIT_FAILURE);
            }
            new_node->tree = copied_tree;
            new_node->next = NULL;
            if (tail == NULL)
            {
                head = new_node;
            }
            else
            {
                tail->next = new_node;
            }
            tail = new_node;
            curr = curr->next;
        }
    }
    return head;
}

tree_list_t *execute_for(char *name, int start, int end_, int incrementeur, tree_list_t *inst_list)
{
    tree_list_t *head = NULL;
    tree_list_t *tail = NULL;
    for (int i = start; i < end_; i += incrementeur)
    {
        symbol_t var;
        cell_t *c;
        var.type = TYPE_ENTIER;
        var.name = name;
        var.value.integer = i;
        c = search_hach(&table, var);
        if (c == NULL)
        {
            insert_hach(&table, var);
        }
        else
        {
            c->var.value.integer = i;
        }
        tree_list_t *curr = inst_list;
        while (curr != NULL)
        {
            tree_t *copied_tree = deep_copy_tree(curr->tree);
            update_variable_in_tree(copied_tree, var.name, i);
            tree_list_t *new_node = malloc(sizeof(tree_list_t));
            if (new_node == NULL)
            {
                fprintf(stderr, "Erreur : échec de l'allocation de mémoire pour un nouveau noeud de liste chaînée.\n");
                exit(EXIT_FAILURE);
            }
            new_node->tree = copied_tree;
            new_node->next = NULL;
            if (tail == NULL)
            {
                head = new_node;
            }
            else
            {
                tail->next = new_node;
            }
            tail = new_node;
            curr = curr->next;
        }
    }
    return head;
}