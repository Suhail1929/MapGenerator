/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "analyser.yacc.y"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "List.h"
#include "hach_table.h"
#include "tree.h"

#define TAILLE_TABLE 20

#define ERR_DIV_0 1
#define ERR_SYMBOLE 2

int yylex();
int yyerror(char* s);
int erreur=0;
char* symbole_erreur=NULL;
hach_t table;

int fact(int a);
#line 23 "analyser.yacc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
  char* str;
  int entier;
  tree_t* tree;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 55 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define ENTIER 257
#define VARIABLE 258
#define POW 259
#define FACT 260
#define INCREMENT 261
#define DECREMENT 262
#define QUIT 263
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    7,    0,    8,    0,    0,    0,    1,    1,    2,    2,
    3,    3,    4,    4,    5,    5,    6,    6,    6,    6,
    6,    6,
};
static const YYINT yylen[] = {                            2,
    0,    4,    0,    6,    2,    0,    3,    1,    3,    1,
    3,    1,    3,    1,    2,    1,    1,    1,    3,    2,
    2,    1,
};
static const YYINT yydefred[] = {                         0,
   18,    0,   22,    0,    0,    0,    0,    0,    0,    0,
    0,   14,   16,   20,   21,    0,    5,    0,   15,    0,
    1,    0,    0,    0,    0,    0,   19,    0,    0,    0,
    0,   13,    3,    2,    0,    4,
};
static const YYINT yydgoto[] = {                          7,
    8,    9,   10,   11,   12,   13,   28,   35,
};
static const YYINT yysindex[] = {                       -10,
    0,  -59,    0,  -10,  -37,  -39,    0,    9,  -41,  -32,
  -30,    0,    0,    0,    0,  -39,    0, -246,    0,  -34,
    0,  -39,  -39,  -39,  -39,   22,    0,  -10,  -41,  -32,
  -30,    0,    0,    0,  -10,    0,
};
static const YYINT yyrindex[] = {                        20,
    0,    1,    0,   20,    0,    0,    0,    0,   -2,   16,
    8,    0,    0,    0,    0,    0,    0,   -5,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   20,    4,   19,
   13,    0,    0,    0,   20,    0,
};
static const YYINT yygindex[] = {                        59,
    6,   -9,    2,   -3,   -1,   23,    0,    0,
};
#define YYTABLESIZE 253
static const YYINT yytable[] = {                          4,
    6,   16,    6,   23,   17,    5,   27,    8,   22,   24,
   17,   20,   29,    7,   14,   15,   25,   12,   21,    6,
   31,   26,   11,   32,   30,   10,    0,   19,    9,    6,
    0,   33,    0,    0,    5,   17,   17,   17,    8,   17,
    8,   17,   17,   17,    7,   17,    7,   17,   12,   12,
   12,   22,   12,   11,   11,   11,   10,   11,   10,    9,
   10,    9,   17,    9,   22,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   34,    0,    0,    0,
    0,    0,    0,   36,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   14,   15,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    1,   18,    1,
   18,    0,    0,    3,    0,    3,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    1,    2,    0,    0,
    0,    0,    3,
};
static const YYINT yycheck[] = {                         10,
   40,   61,   40,   45,   10,   45,   41,   10,   43,   42,
   10,    6,   22,   10,  261,  262,   47,   10,   10,    0,
   24,   16,   10,   25,   23,   10,   -1,    5,   10,   40,
   -1,   10,   -1,   -1,   45,   41,   42,   43,   41,   45,
   43,   47,   42,   43,   41,   45,   43,   47,   41,   42,
   43,   43,   45,   41,   42,   43,   41,   45,   43,   41,
   45,   43,    4,   45,   43,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   28,   -1,   -1,   -1,
   -1,   -1,   -1,   35,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  261,  262,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  257,
  258,   -1,   -1,  263,   -1,  263,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,   -1,   -1,
   -1,   -1,  263,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 263
#define YYUNDFTOKEN 274
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
0,0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"ENTIER","VARIABLE","POW","FACT","INCREMENT","DECREMENT","QUIT",0,0,0,0,0,0,0,0,
0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : programme",
"$$1 :",
"programme : addition '\\n' $$1 programme",
"$$2 :",
"programme : VARIABLE '=' addition '\\n' $$2 programme",
"programme : '\\n' programme",
"programme :",
"addition : addition '+' soustraction",
"addition : soustraction",
"soustraction : soustraction '-' multiplication",
"soustraction : multiplication",
"multiplication : multiplication '*' division",
"multiplication : division",
"division : division '/' moins",
"division : moins",
"moins : '-' expression",
"moins : expression",
"expression : VARIABLE",
"expression : ENTIER",
"expression : '(' addition ')'",
"expression : VARIABLE INCREMENT",
"expression : VARIABLE DECREMENT",
"expression : QUIT",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 177 "analyser.yacc.y"


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
  printf("Fin du programme\n");
  return EXIT_SUCCESS;
}
#line 287 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 43 "analyser.yacc.y"
	{
        if(erreur==ERR_DIV_0){
          printf("Erreur de division par zéro\n");
          erreur=0;
        }else if(erreur==ERR_SYMBOLE){
          printf("Symbole inconnu rencontré : %s\n",symbole_erreur);
          free(symbole_erreur);
          symbole_erreur=NULL;
          erreur=0;
        }else{
          printf("=%lf\n", evaluated_tree(yystack.l_mark[-1].tree));
          print_tree(yystack.l_mark[-1].tree);
          printf("\n");
        }
      }
break;
case 3:
#line 58 "analyser.yacc.y"
	{
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
          var.name=yystack.l_mark[-3].str;
          var.value.integer=evaluated_tree(yystack.l_mark[-1].tree);
          c=search_hach(&table,var);
          if(c==NULL){
            insert_hach(&table,var);
          }else{
            c->var.value.integer=var.value.integer;
          }
           printf("=%lf\n", evaluated_tree(yystack.l_mark[-1].tree));
          print_tree(yystack.l_mark[-1].tree);
          printf("\n");
        }
        free_tree(yystack.l_mark[-3].tree);

      }
break;
case 7:
#line 90 "analyser.yacc.y"
	{
        tree_t *add = create_tree('+',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)));
        yyval.entier = add;
      }
break;
case 9:
#line 96 "analyser.yacc.y"
	{
        tree_t *sous = create_tree('-',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)));
        yyval.entier = sous;
      }
break;
case 11:
#line 102 "analyser.yacc.y"
	{
        tree_t *mult = create_tree('*',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)));
        yyval.entier = mult;
      }
break;
case 13:
#line 108 "analyser.yacc.y"
	{
        if(yystack.l_mark[0].entier!=0){
          tree_t *div = create_tree('/',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)));
          yyval.entier = div;
        }else{
          if(erreur==0) erreur=ERR_DIV_0;
        }
      }
break;
case 15:
#line 118 "analyser.yacc.y"
	{
        tree_t *moins = create_tree('-',0,create_tree_list(yystack.l_mark[0].tree,NULL));
        yyval.entier = moins;
  }
break;
case 17:
#line 126 "analyser.yacc.y"
	{
              symbol_t var;
              var.type=TYPE_ENTIER;
              var.name=yystack.l_mark[0].str;
              var.value.integer=0;
              cell_t* c=search_hach(&table,var);
              if(c==NULL){
                erreur=ERR_SYMBOLE;
                if(symbole_erreur!=NULL) free(symbole_erreur);
                symbole_erreur=yystack.l_mark[0].str;
              }else{
                yyval.tree = create_tree('n',c->var.value.integer,NULL);
              }
            }
break;
case 18:
#line 140 "analyser.yacc.y"
	{ tree_t *t = create_tree('n',yystack.l_mark[0].entier,NULL); t->value.integer = yystack.l_mark[0].entier; yyval.tree = t;}
break;
case 19:
#line 143 "analyser.yacc.y"
	{ yyval.tree = yystack.l_mark[-1].entier; }
break;
case 20:
#line 144 "analyser.yacc.y"
	{ 
              symbol_t var;
              var.type = TYPE_ENTIER;
              var.name = yystack.l_mark[-1].str;
              cell_t *c = search_hach(&table,var);
              if(c==NULL){
              var.value.integer = 1;
              insert_hach(&table,var);
              yyval.tree = 1;
              }else{
              c->var.value.integer++;
              yyval.tree = create_tree('n',c->var.value.integer,NULL);
              }
              free_tree(yystack.l_mark[-1].str);
              }
break;
case 21:
#line 159 "analyser.yacc.y"
	{
              symbol_t var;
              var.type = TYPE_ENTIER;
              var.name = yystack.l_mark[-1].str;
              cell_t *c = search_hach(&table,var);
              if(c==NULL){
              var.value.integer = 1;
              insert_hach(&table,var);
              yyval.tree = 1;
              }else{
              c->var.value.integer--;
              yyval.tree = create_tree('n',c->var.value.integer,NULL);
              }
              free_tree(yystack.l_mark[-1].str);
              }
break;
case 22:
#line 174 "analyser.yacc.y"
	{ exit(0); }
break;
#line 642 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
