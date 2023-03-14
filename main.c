#include "stdio.h"
#include "stdlib.h"
#include "List.h"
#include "hach_table.h"
#include "include.h"
extern int yyparse();
int main(void)
{
    init_hachtable(&table, TAILLE_TABLE);
    yyparse();
    destroy_hachtable(&table);
    printf("Fin du programme\n");
    return EXIT_SUCCESS;
}