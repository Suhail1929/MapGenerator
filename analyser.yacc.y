%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tree.h"
#include "stdio.h"
#include "stdlib.h"
#include "List.h"
#include "hach_table.h"
#include "include.h"

int erreur = 0;
char *symbole_erreur = NULL;
%}

%union{
  char* str;
  int entier;
  tree_t* tree;
}

%token ENTIER
%token VARIABLE
%token POW
%token FACT
%token INCREMENT
%token DECREMENT
%token QUIT
%token EGAL
%token DIFFERENT
%token INFEGAL
%token SUPEGAL
%token ET
%token OU

%type<entier> ENTIER POW FACT addition soustraction multiplication division moins expression
%type<str> VARIABLE
%type<tree> expression

%%

programme: addition '\n' {
        if(erreur==ERR_DIV_0){
          printf("Erreur de division par zéro\n");
          erreur=0;
        }else if(erreur==ERR_SYMBOLE){
          printf("Symbole inconnu rencontré : %s\n",symbole_erreur);
          free(symbole_erreur);
          symbole_erreur=NULL;
          erreur=0;
        }else{
          tree_t *tr = $<tree>1;
          if(tr->isbool == 1){
            if(evaluated_tree(tr) == 1){
              printf("Vrai\n");
            }else{
              printf("Faux\n");
            }
          }else{
            printf("=%lf\n", evaluated_tree($<tree>1));
            print_tree($<tree>1);
            printf("\n");
          }
        }
      } programme
      | VARIABLE '=' addition '\n' {
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
           printf("=%lf\n", evaluated_tree($<tree>3));
          print_tree($<tree>3);
          printf("\n");
        }
        free_tree($<tree>1);

      } programme
      | '\n' programme
      |
      ;

addition: addition '+' soustraction {
        tree_t *add = create_tree('+',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),0);
        $<tree>$ = add;
      }
      | soustraction;

soustraction: soustraction '-' multiplication {
        tree_t *sous = create_tree('-',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),0);
        $<tree>$ = sous;
      }
      | multiplication;

multiplication: multiplication '*' division {
        tree_t *mult = create_tree('*',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),0);
        $<tree>$ = mult;
      }
      | division;

division: division '/' moins {
        if($3!=0){
          tree_t *div = create_tree('/',0,create_tree_list($<tree>1,create_tree_list($<tree>3,NULL)),0);
          $<tree>$ = div;
        }else{
          if(erreur==0) erreur=ERR_DIV_0;
        }
      }
      | moins;

moins: '-' expression {
        tree_t *moins = create_tree('u',0,create_tree_list($<tree>2,NULL),0);
        $<tree>$ = moins;
  }
  | expression;




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
            | ENTIER { tree_t *t = create_tree('n',$1,NULL,0); t->value.integer = $1; $$ = t;}
            // | POW '(' addition ',' addition ')' { $$ = pow($3,$5); }
            // | FACT '(' addition ')' { $$ = fact($3); }
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
            | QUIT { exit(0); }
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

int fact(int a){
  int res=1,i;
  for(i=2;i<=a;++i){
    res*=i;
  }
  return res;
}

// int main(void) {
//   init_hachtable(&table,TAILLE_TABLE);
//   yyparse();
//   destroy_hachtable(&table);
//   printf("Fin du programme\n");
//   return EXIT_SUCCESS;
// }
