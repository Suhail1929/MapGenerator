#include "stdio.h"
#include "stdlib.h"

typedef struct instruction_list
{
    char *instruction;
    struct instruction_list *next;
} instruction_list;