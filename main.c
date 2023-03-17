#include "stdio.h"
#include "stdlib.h"
#include "List.h"
#include "hach_table.h"
#include <wchar.h>
#include "level.h"
#include "include.h"
extern int yyparse();
extern FILE *yyin;
int main(int argc, char *argv[])
{
    // if (argc != 2)
    // {
    //     printf("Usage: %s <file>\n", argv[0]);
    //     return EXIT_FAILURE;
    // }
    // FILE *f = fopen(argv[1], "r");
    // if (f == NULL)
    // {
    //     printf("Erreur d'ouverture du fichier %s\n", argv[1]);
    //     return EXIT_FAILURE;
    // }
    // yyin = f;
    init_hachtable(&table, TAILLE_TABLE);
    yyparse();
    destroy_hachtable(&table);
    printf("Fin du programme\n");
    return EXIT_SUCCESS;
}