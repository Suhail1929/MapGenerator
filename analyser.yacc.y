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
%token VARIABLE
%token PUT
%token GET
%token DOOR
%token KEY
%token GATE
%token INCREMENT
%token DECREMENT
%token QUIT
%token EGAL
%token DIFFERENT
%token INFEGAL
%token SUPEGAL
%token ET
%token OU
%token LEVEL 
%token END
%token IF
%token ELSE
%token ENDIF

%type<entier> ENTIER GET
%type<str> VARIABLE
%type<tree> expression
%type<tree_list_t> expr_list

%%
niveau:
    LEVEL'\n' programme END '\n'{
        printf("Found a level\n");
        if(setlocale(LC_ALL, "") == NULL)printf("setlocale failed.\n");
        level_t level;
        level_init(&level);  
        draw_map(&level);
        level_display(&level);
        map_init();
    }niveau
    | '\n' niveau
    ;

programme: expr_list '\n' {
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
                    if (evaluated_tree(tr) == 1) {
                      printf("Vrai\n");
                    } else {
                      printf("Faux\n");
                    }
                  } else {
                    if (evaluated_tree(tr) == PUT_ACC) {
                      printf("Put effectué\n");
                    } else if (evaluated_tree(tr) == PUT_REJ) {
                      printf("ERROR : Put n'est pas effectué\n");
                    } else {
                      printf("=%.2f\n", evaluated_tree(tr));
                      printf("\n");
                    }
                  }
                  tree_list = tree_list->next;
                }
              }
            } 
            | '\n' programme
            | ;

expr_list: expression  {
              $<tree_list>$ = malloc(sizeof(tree_list_t));
              $<tree_list>$->tree = $<tree>1;
              $<tree_list>$->next = NULL;
            }
            | expr_list '\n' expression {
              tree_list_t *e = malloc(sizeof(tree_list_t));
              e->tree = $<tree>3;
              e->next = NULL;
              tree_list_t *last = $<tree_list>1;
              while (last->next) {
                last = last->next;
              }
              last->next = e;
            }| 
              IF '(' expression ')' '\n' expr_list '\n' ELSE '\n' expr_list '\n' ENDIF {
              if(evaluated_tree($<tree>3) == 1){
                  $<tree_list>$ = $<tree_list>6;
              }else{
                  $<tree_list>$ = $<tree_list>9;
              }
              }
              | IF '(' expression ')' '\n' expr_list '\n' ENDIF {
                  if(evaluated_tree($<tree>3) == 1){
                      $<tree_list>$ = $<tree_list>6;
                  }else{
                      $<tree_list>$ = NULL;
                  }
              } ;



expression: VARIABLE {
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
                $$ = create_tree('n',c->var.value.integer,NULL,0);
              }
            }
            |
             VARIABLE '=' expression {
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
                var.value.integer=evaluated_tree($<tree>3);
                c=search_hach(&table,var);
                if(c==NULL){
                  insert_hach(&table,var);
                }else{
                  c->var.value.integer=var.value.integer;
                }
               $$ = create_tree('n',var.value.integer,NULL,0);
              }
              free_tree($<tree>3);
            }|expression '+' expression  { $$ = create_tree('+',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),0);}
            |expression '-' expression { $$ = create_tree('-',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),0);}
            |expression '*' expression { $$ = create_tree('*',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),0);}
            |expression '/' expression { if($3 != 0){$$ = create_tree('/',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),0);}}
            |'-'expression { $$ = create_tree('u',0,create_tree_list($<tree>2,NULL),0);}
            | ENTIER { tree_t *t = create_tree('n',$1,NULL,0); t->value.integer = $1; $$ = t;}
            | PUT '(' expression ',' expression ','expression')' { $$ =create_tree('P',0,create_tree_list($<tree>3,create_tree_list($<tree>5,create_tree_list($<tree>7,NULL))),0); }
            | GET '(' expression ',' expression ')' { $$ = create_tree('G',0,create_tree_list($<tree>3,create_tree_list($<tree>5,NULL)),0); }
            | DOOR '(' expression ')' { $$ = create_tree('n',door(evaluated_tree($<tree>3)),NULL,0); }
            | GATE  '(' expression ')' { $$ = create_tree('n',gate(evaluated_tree($<tree>3)),NULL,0); }
            | KEY  '(' expression ')' { $$ = create_tree('n',key(evaluated_tree($<tree>3)),NULL,0); }
            | '(' addition ')' { $$ = $<tree>2; }
            | VARIABLE INCREMENT { 
              symbol_t var;
              var.type = TYPE_ENTIER;
              var.name = $1;
              cell_t *c = search_hach(&table,var);
              if(c==NULL){
              printf("Variable inconnue : %s \n",var.name);
              exit(1);
              }else{
              c->var.value.integer++;
              $$ = create_tree('n',c->var.value.integer,NULL,0);
              }
              free_tree($<tree>1);
              }
            | VARIABLE DECREMENT {
              symbol_t var;
              var.type = TYPE_ENTIER;
              var.name = $1;
              cell_t *c = search_hach(&table,var);
              if(c==NULL){
              printf("Variable inconnue : %s \n",var.name);
              exit(1);
              }else{
              c->var.value.integer--;
              $$ = create_tree('n',c->var.value.integer,NULL,0);
              }
              free_tree($<tree>1);
              }
            // | QUIT { exit(0); }
            | expression EGAL expression { 
              tree_t *egal = create_tree('=',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
              $$ = egal;
            }
            | expression DIFFERENT expression { 
              tree_t *diff = create_tree('!',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
              $$ = diff;
            }
            | expression '<' expression { 
              tree_t *petit = create_tree('<',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
              $$ = petit;
            }
            | expression '>' expression { 
              tree_t *grand = create_tree('>',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
              $$ = grand;
            }
            | expression INFEGAL expression { 
              tree_t *petit = create_tree('I',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
              $$ = petit;
            }
            | expression SUPEGAL expression { 
              tree_t *grand = create_tree('S',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
              $$ = grand;
            }
            | expression ET expression { 
              tree_t *et = create_tree('&',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
              $$ = et;
            }
            | expression OU expression { 
              tree_t *ou = create_tree('|',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),1);
              $$ = ou;
            }
  

%%
