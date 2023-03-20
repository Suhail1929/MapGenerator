#include "stdio.h"
#include "stdlib.h"
#include "List.h"
#include "hach_table.h"
#include <wchar.h>
#include <locale.h>
#include "level.h"
#include "include.h"
extern int yyparse();
extern FILE *yyin;
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    yyin = fopen(argv[1], "r");
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