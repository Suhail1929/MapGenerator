%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "List.h"
#include "hach_table.h"

#define TAILLE_TABLE 20

#define ERR_DIV_0 1
#define ERR_SYMBOLE 2

int erreur=0;
char* symbole_erreur=NULL;
hach_t table;

int fact(int a);
%}

%union{
  char* str;
  int entier;
}

%token ENTIER
%token VARIABLE
%token POW
%token FACT

%type<entier> ENTIER POW FACT addition soustraction multiplication division moins expression
%type<str> VARIABLE

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
          printf("=%d\n", $1);
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
          variable_t var;
          cell_t* c;
          var.type=TYPE_ENTIER;
          var.name=$1;
          var.value.intiger=$3;
          c=search_hach(&table,var);
          if(c==NULL){
            insert_hach(&table,var);
          }else{
            c->var.value.intiger=var.value.intiger;
          }
          printf("=%d\n", $3);
        }
        free($1);

      } programme
      | '\n' programme
      |
      ;

addition: addition '+' soustraction {
        $$ = $1 + $3;
      }
      | soustraction;

soustraction: soustraction '-' multiplication {
        $$ = $1 - $3;
      }
      | multiplication;

multiplication: multiplication '*' division {
        $$ = $1 * $3;
      }
      | division;

division: division '/' moins {
        if($3!=0){
          $$ = $1 / $3;
        }else{
          if(erreur==0) erreur=ERR_DIV_0;
        }
      }
      | moins;

moins: '-' expression {
    $$ = -$2;
  }
  | expression;

expression: VARIABLE {
              variable_t var;
              var.type=TYPE_ENTIER;
              var.name=$1;
              var.value.intiger=0;
              cell_t* c=search_hach(&table,var);
              if(c==NULL){
                erreur=ERR_SYMBOLE;
                if(symbole_erreur!=NULL) free(symbole_erreur);
                symbole_erreur=$1;
              }else{
                $$ = c->var.value.intiger;
              }
            }
            | ENTIER
            | POW '(' addition ',' addition ')' { $$ = pow($3,$5); }
            | FACT '(' addition ')' { $$ = fact($3); }
            | '(' addition ')' { $$ = $2; };

%%

int fact(int a){
  int res=1,i;
  for(i=2;i<=a;++i){
    res*=i;
  }
  return res;
}

int main(void) {
  init_hachtable(&table,TAILLE_TABLE);
  yyparse();
  destroy_hachtable(&table);
  return EXIT_SUCCESS;
}
