%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tree.h"
#include "List.h"
#include "hach_table.h"
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include "level.h"
#include "include.h"

int erreur = 0;
char *symbole_erreur = NULL;

%}

%union{
  char* str;
  int entier;
  tree_list_t* tree_list;
  tree_t* tree;
};

%token ENTIER
%token variable
%token put_
%token get_
%token door_
%token key_
%token gate_
%token incr
%token decr
%token egal
%token diff
%token infegal
%token supegal
%token et
%token ou
%token level_ 
%token end
%token IF
%token ELSE
%token endif
%token FOR
%token endfor
%token WHILE
%token endwhile
%token fct
%token endfct
%token FUNCNAME
%token prc 
%token endprc
%token PROCNAME

%type<entier> ENTIER
%type <str> FUNCNAME
%type<str> PROCNAME
%type<tree> BOOLEEN
%type<str> variable
%type<tree> EXPRESSION
%type<tree> VARIABLE
%type<tree_list_t> INSTR_LIST 
%type<tree_list_t> CONDITION 
%type<tree_list_t> FORLOOP
%type<tree_list_t> WHILELOOP
%type<tree_list_t> PARAM_LIST
%type<tree> PRC_CALL

%left ou
%left et
%left egal diff
%left infegal supegal

%left '='
%left '+' '-'
%left '*' '/' 
%left '<' '>' '!' '&' '|' 'i'


%%
LEVEL:
    level_ PROGRAMME end{
        printf("Found a level\n");
        if(setlocale(LC_ALL, "") == NULL)printf("setlocale failed.\n");
        level_t level;
        level_init(&level);  
        draw_map(&level);
        level_display(&level);
        map_init();
    }
    | LEVEL level_ PROGRAMME end{
        printf("Found a level\n");
        if(setlocale(LC_ALL, "") == NULL)printf("setlocale failed.\n");
        level_t level;
        level_init(&level);  
        draw_map(&level);
        level_display(&level);
        map_init();
    }
    |LEVEL PROCEDURE_DEF{
        printf("Procedure been saved\n");
    }
    ;

PROGRAMME: INSTR_LIST  {
              if (erreur == ERR_DIV_0) {
                printf("Erreur de division par zéro\n");
                erreur = 0;
              } else if (erreur == ERR_SYMBOLE) {
                printf("Symbole inconnu rencontré : %s\n", symbole_erreur);
                free(symbole_erreur);
                symbole_erreur = NULL;
                erreur = 0;
              } else {
                tree_list_t *tree_list = $<tree_list>1;
                while (tree_list) {
                  tree_t *tr = tree_list->tree;
                  if (tr->isbool == 1) {
                    if (calculate_tree(tr) == 1) {
                      printf("Vrai\n");
                    } else {
                      printf("Faux\n");
                    }
                  } else {
                    if (calculate_tree(tr) == PUT_ACC) {
                      printf("Put effectué\n");
                    } else if (calculate_tree(tr) == PUT_REJ) {
                      printf("ERROR : Put n'est pas effectué\n");
                    } else if(calculate_tree(tr) == FUNC_ACC){
                      printf("Procedure effectuée\n");
                    }else{
                      printf("=%.2f\n", calculate_tree(tr));
                      printf("\n");
                    }
                  }
                  tree_list = tree_list->next;
                }
              }
            };
            

INSTR_LIST: EXPRESSION  {
              $<tree_list>$ = malloc(sizeof(tree_list_t));
              $<tree_list>$->tree = $<tree>1;
              $<tree_list>$->next = NULL;
            }
            | INSTR_LIST EXPRESSION {
              tree_list_t *e = malloc(sizeof(tree_list_t));
              e->tree = $<tree>2;
              e->next = NULL;
              tree_list_t *last = $<tree_list>1;
              while (last->next) {
                last = last->next;
              }
              last->next = e;
            }| CONDITION
            | INSTR_LIST CONDITION {
              tree_list_t *last = $<tree_list>1;
              while (last->next) {
                last = last->next;
              }
              last->next = $<tree_list>2;
            }
            | FORLOOP
            | INSTR_LIST FORLOOP {
              tree_list_t *last = $<tree_list>1;
              while (last->next) {
                last = last->next;
              }
              last->next = $<tree_list>2;
              }
            | WHILELOOP
            | INSTR_LIST WHILELOOP {
              tree_list_t *last = $<tree_list>1;
              while (last->next) {
                last = last->next;
              }
              last->next = $<tree_list>2;
            }
              ;

CONDITION:   IF '(' BOOLEEN ')' INSTR_LIST ELSE INSTR_LIST endif {
              int booleen = calculate_tree($<tree>3);
              if(booleen== 1){
                  $<tree_list>$ = $<tree_list>5;
              }else{
                  $<tree_list>$ = $<tree_list>7;
              }
              }
              |  IF '(' BOOLEEN ')' INSTR_LIST endif {
                int booleen = calculate_tree($<tree>3);
                  if(booleen== 1){
                      $<tree_list>$ = $<tree_list>5;
                  }else{
                      $<tree_list>$ = NULL;
                  }
              };


PROCEDURE_DEF: prc PROCNAME '(' PARAM_LIST ')' INSTR_LIST endprc {
                function_t *new_func = malloc(sizeof(function_t));
                new_func->name = $<str>2;
                new_func->params = $<tree_list>4;
                new_func->instructions = $<tree_list>6;
                new_func->next = function_list;
                function_list = new_func;
            }|  fct FUNCNAME '(' PARAM_LIST ')' INSTR_LIST endfct {
                function_t *new_func = malloc(sizeof(function_t));
                new_func->name = $<str>2;
                new_func->params = $<tree_list>4;
                new_func->instructions = $<tree_list>6;
                new_func->next = function_list;
                function_list = new_func;
            };

PRC_CALL : PROCNAME '(' PARAM_LIST ')' {
                $$ = create_tree_prc_call($1, $<tree_list>3);
            }| FUNCNAME '(' PARAM_LIST ')' {
                $$ = create_tree_func_call($1, $<tree_list>3);
            };

PARAM_LIST : /* empty */{
                $<tree_list>$ = NULL;
            }
            | EXPRESSION {
                $<tree_list>$ = malloc(sizeof(tree_list_t));
                $<tree_list>$->tree = $<tree>1;
                $<tree_list>$->next = NULL;
            }
            | PARAM_LIST ',' EXPRESSION {
                tree_list_t *e = malloc(sizeof(tree_list_t));
                e->tree = $<tree>3;
                e->next = NULL;
                tree_list_t *last = $<tree_list>1;
                while (last->next) {
                    last = last->next;
                }
                last->next = e;
            }
            ;

FORLOOP : FOR '(' VARIABLE ',' EXPRESSION ',' EXPRESSION ',' EXPRESSION ')' INSTR_LIST endfor {
                  $<tree_list>$ = execute_for($3->name,calculate_tree($<tree>5),calculate_tree($<tree>7),calculate_tree($<tree>9),$<tree_list>11);
              };

WHILELOOP : WHILE '(' BOOLEEN ')' INSTR_LIST endwhile {
                $<tree_list>$ = execute_while($<tree>3,$<tree_list>5);
              };
        

VARIABLE : variable {
              $$ = create_tree_var('i',print_var($1),NULL,0,$1);
            }
            |
             variable '=' EXPRESSION {
              crt_or_upd_symbol(TYPE_ENTIER,$1,calculate_tree($<tree>3));
              $$ = create_tree_var('i',calculate_tree($<tree>3),NULL,0,$1);
              };

EXPRESSION:  VARIABLE
            | PRC_CALL
            |EXPRESSION '+' EXPRESSION  { 
              $$ = create_tree('+',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),0);
              }
            |EXPRESSION '-' EXPRESSION { 
              $$ = create_tree('-',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),0);
              }
            |EXPRESSION '*' EXPRESSION {
               $$ = create_tree('*',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),0);
               }
            |EXPRESSION '/' EXPRESSION {
              if($3 != 0){
                $$ = create_tree('/',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),0);
                }
              }
            | ENTIER { 
              $$ = create_tree('i',$1,NULL,0);
              }
            | put_ '(' EXPRESSION ',' EXPRESSION ','EXPRESSION')' {
              $$ =create_tree('P',0,create_tree_list($<tree>3,create_tree_list($<tree>5,create_tree_list($<tree>7,NULL))),0); 
              }
            | get_ '(' EXPRESSION ',' EXPRESSION ')' {
              $$ = create_tree('G',0,create_tree_list($<tree>3,create_tree_list($<tree>5,NULL)),0);
              }
            | door_ '(' EXPRESSION ')' {
              $$ = create_tree('i',door(calculate_tree($<tree>3)),NULL,0);
              }
            | gate_  '(' EXPRESSION ')' {
              $$ = create_tree('i',gate(calculate_tree($<tree>3)),NULL,0);
              }
            | key_  '(' EXPRESSION ')' {
               $$ = create_tree('i',key(calculate_tree($<tree>3)),NULL,0); 
               }
            | '(' EXPRESSION ')' {
              $$ = create_tree('i',calculate_tree($<tree>2),NULL,0); 
              }
            | variable incr {
              $$ = create_tree('i',incr_var($1),NULL,0);
              }
            | variable decr {
              $$ = create_tree('i',decr_var($1),NULL,0);
              }
              ;


BOOLEEN:     EXPRESSION egal EXPRESSION { 
              $<tree>$ = create_tree('=',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
            }
            | EXPRESSION diff EXPRESSION { 
              $<tree>$ = create_tree('!',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
            }
            | EXPRESSION '<' EXPRESSION { 
              $<tree>$ = create_tree('<',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
            }
            | EXPRESSION '>' EXPRESSION { 
              $<tree>$ = create_tree('>',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
            }
            | EXPRESSION infegal EXPRESSION { 
              $<tree>$ = create_tree('I',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
            }
            | EXPRESSION supegal EXPRESSION {
              $<tree>$ = create_tree('S',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
            }
            | EXPRESSION et EXPRESSION { 
              $<tree>$ = create_tree('&',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
            }
            | EXPRESSION ou EXPRESSION { 
              $<tree>$ = create_tree('|',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
            }
            | ENTIER {
              if(ENTIER==0){
                $$ = create_tree('i',0,NULL,1);
             }else{
                $$ = create_tree('i',1,NULL,1);
             }
             }
            | VARIABLE
            ;
  

%%
