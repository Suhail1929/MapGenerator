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
%token WHILE
%token endwhile

%type<entier> ENTIER
%type<tree> BOOLEEN
%type<str> variable
%type<tree> EXPRESSION
%type<tree> VARIABLE
%type<tree_list_t> INSTR_LIST 
%type<tree_list_t> CONDITION 
%type<tree_list_t> FORLOOP
%type<tree_list_t> WHILELOOP

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
              int booleen = calculate_expression($<tree>3);
              if(booleen== 1){
                  $<tree_list>$ = $<tree_list>5;
              }else{
                  $<tree_list>$ = $<tree_list>7;
              }
              }
              |  IF '(' BOOLEEN ')' INSTR_LIST endif {
                int booleen = calculate_expression($<tree>3);
                  if(booleen== 1){
                      $<tree_list>$ = $<tree_list>5;
                  }else{
                      $<tree_list>$ = NULL;
                  }
              };

FORLOOP : FOR '(' VARIABLE ',' ENTIER ',' ENTIER ',' ENTIER ')' INSTR_LIST endfor {
                   tree_list_t* head = NULL;
                    tree_list_t* tail = NULL;
                    for (int i = $5; i < $7; i += $9) {
                        symbol_t var;
                        cell_t* c;
                        var.type = TYPE_ENTIER;
                        var.name = $<tree>3->name;
                        var.value.integer = i;
                        c = search_hach(&table, var);
                        if (c == NULL) {
                            insert_hach(&table, var);
                        } else {
                            c->var.value.integer = i;
                        }
                        printf("i = %d\n", c->var.value.integer);
                        tree_list_t* curr = $<tree_list>11;
                        while (curr != NULL) {
                            tree_t* copied_tree = deep_copy_tree(curr->tree);
                            update_variable_in_tree(copied_tree, var.name, i);
                            tree_list_t* new_node = malloc(sizeof(tree_list_t));
                            if (new_node == NULL) {
                                fprintf(stderr, "Erreur : échec de l'allocation de mémoire pour un nouveau noeud de liste chaînée.\n");
                                exit(EXIT_FAILURE);
                            }
                            new_node->tree = copied_tree;
                            new_node->next = NULL;
                            if (tail == NULL) {
                                head = new_node;
                            } else {
                                tail->next = new_node;
                            }
                            tail = new_node;
                            curr = curr->next;
                        }
                    }
                    $<tree_list>$ = head;
                    };

WHILELOOP : WHILE '(' BOOLEEN ')' INSTR_LIST endwhile {
              tree_list_t* head = NULL;
              tree_list_t* tail = NULL;
              int booleen = calculate_expression($<tree>3);
              while(booleen==1){
                        booleen = calculate_expression($<tree>3);
                        tree_list_t* curr = $<tree_list>5;
                        while (curr != NULL) {
                            tree_t* copied_tree = deep_copy_tree(curr->tree);
                            tree_list_t* new_node = malloc(sizeof(tree_list_t));
                            if (new_node == NULL) {
                                fprintf(stderr, "Erreur : échec de l'allocation de mémoire pour un nouveau noeud de liste chaînée.\n");
                                exit(EXIT_FAILURE);
                            }
                            new_node->tree = copied_tree;
                            new_node->next = NULL;
                            if (tail == NULL) {
                                head = new_node;
                            } else {
                                tail->next = new_node;
                            }
                            tail = new_node;
                            curr = curr->next;
                        }
              }
                $<tree_list>$ = head;
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
                $$ = create_tree_var('i',c->var.value.integer,NULL,0,$1);
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
               $$ = create_tree_var('i',var.value.integer,NULL,0,$1);
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
