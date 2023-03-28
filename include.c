#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <wchar.h>
#include <dirent.h>
#include <ctype.h>
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

char *afficher_salons()
{
    system("clear");
    // Affichage de la liste des salons de jeu disponibles
    DIR *dir;
    struct dirent *ent;      // structure pour stocker les informations d'un fichier
    char *ext = ".txt";      // extension des fichiers à rechercher
    int found = 0;           // booléen pour savoir si des fichiers ont été trouvés
    char **filenames = NULL; // tableau dynamique pour stocker les noms de fichier
    int num_files = 0;       // nombre de fichiers trouvés

    dir = opendir("./maps");
    if (dir == NULL)
    {
        perror("Erreur lors de l'ouverture du répertoire");
        exit(EXIT_FAILURE);
    }

    printf("Veuillez sélectionner une map parmi ceux disponibles :\n");
    while ((ent = readdir(dir)) != NULL)
    {
        if (ent->d_type == DT_REG && strstr(ent->d_name, ext) != NULL)
        {
            char *name = strtok(ent->d_name, ".");
            printf("%s\n", name);
            found = 1;

            char *filename = malloc(strlen(ent->d_name) + 1);
            if (filename == NULL)
            {
                perror("Erreur lors de l'allocation de mémoire");
                exit(EXIT_FAILURE);
            }
            strcpy(filename, ent->d_name);
            for (char *c = filename; *c; c++)
                *c = tolower(*c);

            char **tmp_filenames = realloc(filenames, (num_files + 1) * sizeof(char *));
            if (tmp_filenames == NULL)
            {
                perror("Erreur lors de l'allocation de mémoire");
                exit(EXIT_FAILURE);
            }
            filenames = tmp_filenames;
            filenames[num_files++] = filename;
        }
    }

    if (!found)
    {
        printf("Aucune map trouvé.\n");
    }

    if (closedir(dir) != 0)
    {
        perror("Erreur lors de la fermeture du répertoire");
        exit(EXIT_FAILURE);
    }

    if (found)
    {
        printf("Saississez le nom de la map : ");
        char salon[50];
        scanf("%50s", salon);
        // convertir le nom du salon en minuscules
        for (char *c = salon; *c; c++)
        {
            *c = tolower(*c);
        }
        // vérifier si le nom du salon est dans le tableau
        int room_found = 0;
        for (int i = 0; i < num_files; i++)
        {
            // extraire le nom de fichier sans l'extension
            char *name = strtok(filenames[i], ".");
            if (strcmp(salon, name) == 0)
            {
                room_found = 1;
                break;
            }
        }
        if (room_found)
        {
            printf("Vous avez selectionné la map %s.\n", salon);
            char *room_name = malloc(strlen(salon) + 1);
            if (room_name == NULL)
            {
                perror("Erreur lors de l'allocation de mémoire");
                exit(EXIT_FAILURE);
            }
            strcpy(room_name, salon);
            return room_name;
        }
        else
        {
            printf("Le salon %s n'existe pas. Veuillez réessayer.\n", salon);
        }
        // désallouer la mémoire allouée pour les noms de fichier
        for (int i = 0; i < num_files; i++)
        {
            free(filenames[i]);
        }
        free(filenames);
    }
    printf("Appuyez sur Entrée pour continuer.\n");
    while (getchar() != '\n')
        ;
    getchar(); // attendre une touche
    return NULL;
}