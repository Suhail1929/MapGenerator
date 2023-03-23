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

extern int yyparse();
extern FILE *yyin;
int main(int argc, char *argv[])
{
    char path[100];
    if (argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    sprintf(path, "./maps/%s.txt", argv[1]);
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