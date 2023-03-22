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
}



%token ENTIER
%token variable
%token put_
%token get_
%token door_
%token key_
%token gate_
%token incr
%token decr
%token quit
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

%type<entier> ENTIER
%type<entier> BOOLEEN
%type<str> variable
%type<tree> EXPRESSION
%type<tree> VARIABLE
%type<tree_list_t> INSTR_LIST 
%type<tree_list_t> CONDITION 
%type<tree_list_t> FORLOOP

%left '='
%left '*' '/' 
%left '+' '-'
%left '<' '>' '!' '&' '|' 'i'
%left ou
%left et
%left egal diff
%left infegal supegal

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
    | LEVEL
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
                    if (calculate_expression(tr) == 1) {
                      printf("Vrai\n");
                    } else {
                      printf("Faux\n");
                    }
                  } else {
                    if (calculate_expression(tr) == PUT_ACC) {
                      printf("Put effectué\n");
                    } else if (calculate_expression(tr) == PUT_REJ) {
                      printf("ERROR : Put n'est pas effectué\n");
                    } else {
                      printf("=%.2f\n", calculate_expression(tr));
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
              ;

CONDITION:   IF '(' BOOLEEN ')' INSTR_LIST ELSE INSTR_LIST endif {
              if($3== 1){
                  $<tree_list>$ = $<tree_list>5;
              }else{
                  $<tree_list>$ = $<tree_list>7;
              }
              }
              |  IF '(' BOOLEEN ')' INSTR_LIST endif {
                  if($3== 1){
                      $<tree_list>$ = $<tree_list>5;
                  }else{
                      $<tree_list>$ = NULL;
                  }
              };

FORLOOP : FOR '(' VARIABLE ',' ENTIER ',' ENTIER ',' ENTIER ')' INSTR_LIST endfor {
                tree_list_t *current_list = $<tree_list>11;
                tree_list_t *new_list = NULL;
                for (int i = $5; i < $7; i += $9) {
                  if(new_list == NULL){
                    new_list=current_list;
                  }else{
                    while(new_list->next){
                        new_list = current_list->next;
                    }
                    printf("debug\n");
                    new_list->next = current_list;
                  }
                }
                display_tree_list(new_list);
               $<tree_list>$ = new_list ;
          };


VARIABLE : variable {
              symbol_t var;
              var.type=TYPE_ENTIER;
              var.name=$1;
              var.value.integer=0;
              cell_t* c=search_hach(&table,var);
              if(c==NULL){
                erreur=ERR_SYMBOLE;
                if(symbole_erreur!=NULL) free(symbole_erreur);
                symbole_erreur=$1;
              }else{
                $$ = create_tree('i',c->var.value.integer,NULL,0);
              }
            }
            |
             variable '=' EXPRESSION {
              if(erreur==ERR_DIV_0){
                printf("Erreur de division par zéro\n");
                erreur=0;
              }else if(erreur==ERR_SYMBOLE){
                printf("Symbole inconnu rencontré : %s\n",symbole_erreur);
                free(symbole_erreur);
                symbole_erreur=NULL;
                erreur=0;
              }else{
                symbol_t var;
                cell_t* c;
                var.type=TYPE_ENTIER;
                var.name=$1;
                var.value.integer=calculate_expression($<tree>3);
                c=search_hach(&table,var);
                if(c==NULL){
                  insert_hach(&table,var);
                }else{
                  c->var.value.integer=var.value.integer;
                }
               $$ = create_tree('i',var.value.integer,NULL,0);
              }
              free_tree($<tree>3);
            };

EXPRESSION:  VARIABLE
            |EXPRESSION '+' EXPRESSION  { $$ = create_tree('+',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),0);}
            |EXPRESSION '-' EXPRESSION { $$ = create_tree('-',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),0);}
            |EXPRESSION '*' EXPRESSION { $$ = create_tree('*',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),0);}
            |EXPRESSION '/' EXPRESSION { if($3 != 0){$$ = create_tree('/',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),0);}}
            | ENTIER { tree_t *t = create_tree('i',$1,NULL,0); t->value.integer = $1; $$ = t;}
            | put_ '(' EXPRESSION ',' EXPRESSION ','EXPRESSION')' { $$ =create_tree('P',0,create_tree_list($<tree>3,create_tree_list($<tree>5,create_tree_list($<tree>7,NULL))),0); }
            | get_ '(' EXPRESSION ',' EXPRESSION ')' { $$ = create_tree('G',0,create_tree_list($<tree>3,create_tree_list($<tree>5,NULL)),0); }
            | door_ '(' EXPRESSION ')' { $$ = create_tree('i',door(calculate_expression($<tree>3)),NULL,0); }
            | gate_  '(' EXPRESSION ')' { $$ = create_tree('i',gate(calculate_expression($<tree>3)),NULL,0); }
            | key_  '(' EXPRESSION ')' { $$ = create_tree('i',key(calculate_expression($<tree>3)),NULL,0); }
            | '(' EXPRESSION ')' { $$ = create_tree('i',calculate_expression($<tree>2),NULL,0); }
            | variable incr { 
              symbol_t var;
              var.type = TYPE_ENTIER;
              var.name = $1;
              cell_t *c = search_hach(&table,var);
              if(c==NULL){
              printf("Variable inconnue : %s \n",var.name);
              exit(1);
              }else{
              c->var.value.integer++;
              $$ = create_tree('i',c->var.value.integer,NULL,0);
              }
              free_tree($<tree>1);
              }
            | variable decr {
              symbol_t var;
              var.type = TYPE_ENTIER;
              var.name = $1;
              cell_t *c = search_hach(&table,var);
              if(c==NULL){
              printf("Variable inconnue : %s \n",var.name);
              exit(1);
              }else{
              c->var.value.integer--;
              $$ = create_tree('i',c->var.value.integer,NULL,0);
              }
              free_tree($<tree>1);
              }
              ;
BOOLEEN:     EXPRESSION egal EXPRESSION { 
              tree_t *eg = create_tree('=',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
              $$ = calculate_expression(eg);
            }
            | EXPRESSION diff EXPRESSION { 
              tree_t *dif = create_tree('!',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
              $$ = calculate_expression(dif);
            }
            | EXPRESSION '<' EXPRESSION { 
              tree_t *petit = create_tree('<',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
              $$ = calculate_expression(petit);
            }
            | EXPRESSION '>' EXPRESSION { 
              tree_t *grand = create_tree('>',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
              $$ = calculate_expression(grand);
            }
            | EXPRESSION infegal EXPRESSION { 
              tree_t *petit = create_tree('I',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
              $$ = calculate_expression(petit);
            }
            | EXPRESSION supegal EXPRESSION {
              tree_t *grand = create_tree('S',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
              $$ = calculate_expression(grand);
            }
            | EXPRESSION et EXPRESSION { 
              tree_t *e = create_tree('&',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
              $$ = calculate_expression(e);
            }
            | EXPRESSION ou EXPRESSION { 
              tree_t *o = create_tree('|',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
              $$ = calculate_expression(o);
            }
            | ENTIER {
              if(ENTIER==0){
                $$ = 0;
             }else{
                $$ = 1;
             }
             }
            | VARIABLE{
              $$ = calculate_expression($<tree>1);
            }
            ;
  

%%
