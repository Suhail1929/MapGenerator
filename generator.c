#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <wchar.h>
#include <locale.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include "level.h"
#include "List.h"
#include "hach_table.h"
#include "tree.h"
#include "include.h"

extern int yyparse();
extern FILE *yyin;
int main(int argc, char *argv[])
{
    char *map_name;
    char path[100];
    map_name = afficher_salons();
    sprintf(path, "./maps/%s.txt", map_name);
    yyin = fopen(path, "r");
    if (yyin == NULL)
    {
        printf("Erreur d'ouverture du fichier %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    init_hachtable(&table, TAILLE_TABLE);
    // printf("debug1\n");
    yyparse();
    destroy_hachtable(&table);
    fclose(yyin);
    printf("Fin du programme\n");
    return EXIT_SUCCESS;
}