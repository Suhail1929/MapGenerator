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
#include "tree.h"
#include "stdio.h"
#include "stdlib.h"
#include "List.h"
#include "hach_table.h"
#include "include.h"
extern int yylineno;
void yyerror(const char *erreurMsg)
{
    fprintf(stderr, "Error at line %d: %s\n", yylineno, erreurMsg);
    exit(EXIT_FAILURE);
}
int erreur = 0;
char *symbole_erreur = NULL;
int map[20][60];
#line 22 "analyser.yacc.y"
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
#line 54 "y.tab.c"

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
#define PUT 259
#define GET 260
#define INCREMENT 261
#define DECREMENT 262
#define QUIT 263
#define EGAL 264
#define DIFFERENT 265
#define INFEGAL 266
#define SUPEGAL 267
#define ET 268
#define OU 269
#define LEVEL 270
#define END 271
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    9,    0,   10,    0,    0,    0,    1,    1,    2,    2,
    3,    3,    4,    4,    5,    5,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,
    6,    6,    7,    7,    8,
};
static const YYINT yylen[] = {                            2,
    0,    4,    0,    6,    2,    0,    3,    1,    3,    1,
    3,    1,    3,    1,    2,    1,    1,    1,    8,    6,
    3,    2,    2,    1,    3,    3,    3,    3,    3,    3,
    3,    3,    2,    2,    1,
};
static const YYINT yydefred[] = {                         0,
   18,    0,    0,    0,   24,    0,    0,    0,    0,    0,
    0,    0,    0,   14,    0,   22,   23,    0,    0,    0,
    5,    0,    0,    0,    1,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   21,    0,    0,    0,    0,   13,    0,    0,    0,    0,
    0,    0,    0,    0,    3,    0,    0,    2,    0,    0,
    0,    4,    0,   20,    0,   19,
};
static const YYINT yydgoto[] = {                          9,
   10,   11,   12,   13,   14,   15,    0,    0,   42,   59,
};
static const YYINT yysindex[] = {                         9,
    0,  -49,  -35,  -24,    0,    9,   38,   30,    0,   -7,
  -28,  -21,  -29,    0,  -58,    0,    0,   30,   38,   38,
    0, -248,  -58,  -33,    0,   30,   30,   30,   30,   38,
   38,   38,   38,   38,   38,   38,   38,    1,  -20,   11,
    0,    9,  -28,  -21,  -29,    0,  -58,  -58,  -58,  -58,
  -58,  -58,  -58,  -58,    0,   38,   38,    0,    9,   17,
  -40,    0,   38,    0,  -34,    0,
};
static const YYINT yyrindex[] = {                        23,
    0,   -4,    0,    0,    0,   23,    0,    0,    0,    0,
    5,  155,  145,    0,   80,    0,    0,    0,    0,    0,
    0,  -10,  132,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   23,  161,  173,  152,    0,   41,   59,   66,   89,
  102,  109,  116,  125,    0,    0,    0,    0,   23,    0,
    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         3,
   39,   -1,    2,   25,   -2,   61,    0,    0,    0,    0,
};
#define YYTABLESIZE 301
static const YYINT yytable[] = {                         17,
   64,   36,   25,   37,   19,   17,   66,   41,   21,   26,
   55,   18,   16,   17,    8,   20,   27,   29,    6,   36,
   28,   37,    6,   56,   43,   36,   46,   37,   44,    0,
   17,   17,   17,   17,   17,   26,   17,   17,   17,   36,
   17,   37,   17,   26,   58,    8,   24,    8,    8,   17,
   25,   17,   45,    7,   57,   17,   38,   17,    0,    0,
   63,   62,    0,    0,    0,    0,    0,   23,   26,    8,
   36,    0,   37,    0,    7,   29,   36,    8,   37,   39,
   40,   25,   25,   25,   25,   25,    0,   25,    0,   16,
   47,   48,   49,   50,   51,   52,   53,   54,   30,   26,
   26,   26,   26,   26,    0,   26,   29,   29,   29,   29,
   29,   31,   29,    0,    0,    0,   60,   61,   32,    0,
   16,   16,   16,   65,   16,   27,   16,    0,    0,   30,
   30,   30,   30,   30,   28,   30,    0,    0,    0,    0,
    0,   15,   31,   31,   31,   31,   31,    0,   31,   32,
   32,   32,   32,   32,   12,   32,   27,   27,   27,   27,
   27,   11,   27,    0,   10,   28,   28,   28,   28,   28,
    7,   28,   15,   15,   15,    0,   15,    0,   15,    0,
    0,    0,    9,    0,    0,   12,   12,   12,    0,   12,
    0,    0,   11,   11,   11,   10,   11,   10,    0,   10,
    0,    7,    0,    7,    0,   30,   31,   32,   33,   34,
   35,   16,   17,    9,    0,    9,    0,    9,    0,    0,
    0,    0,    0,   30,   31,   32,   33,   34,   35,   30,
   31,   32,   33,   34,   35,    0,    0,    0,    0,    0,
    0,    0,    0,   30,   31,   32,   33,   34,   35,    0,
    0,    0,    0,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   17,    1,    2,    3,    4,    0,
    0,    5,    0,    0,   30,   31,   32,   33,   34,   35,
   30,   31,   32,   33,   34,   35,    1,   22,    3,    4,
    0,    0,    5,    0,    1,   22,    3,    4,    0,    0,
    5,
};
static const YYINT yycheck[] = {                         10,
   41,   60,   10,   62,   40,   10,   41,   41,    6,   43,
   10,   61,  261,  262,   10,   40,   45,   47,   10,   60,
   42,   62,    0,   44,   26,   60,   29,   62,   27,   -1,
   41,   42,   43,   44,   45,   43,   47,   42,   43,   60,
   45,   62,   47,   43,   42,   41,    8,   43,   40,   60,
   10,   62,   28,   45,   44,   60,   18,   62,   -1,   -1,
   44,   59,   -1,   -1,   -1,   -1,   -1,    7,   10,   40,
   60,   -1,   62,   -1,   45,   10,   60,   40,   62,   19,
   20,   41,   42,   43,   44,   45,   -1,   47,   -1,   10,
   30,   31,   32,   33,   34,   35,   36,   37,   10,   41,
   42,   43,   44,   45,   -1,   47,   41,   42,   43,   44,
   45,   10,   47,   -1,   -1,   -1,   56,   57,   10,   -1,
   41,   42,   43,   63,   45,   10,   47,   -1,   -1,   41,
   42,   43,   44,   45,   10,   47,   -1,   -1,   -1,   -1,
   -1,   10,   41,   42,   43,   44,   45,   -1,   47,   41,
   42,   43,   44,   45,   10,   47,   41,   42,   43,   44,
   45,   10,   47,   -1,   10,   41,   42,   43,   44,   45,
   10,   47,   41,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   -1,   10,   -1,   -1,   41,   42,   43,   -1,   45,
   -1,   -1,   41,   42,   43,   41,   45,   43,   -1,   45,
   -1,   41,   -1,   43,   -1,  264,  265,  266,  267,  268,
  269,  261,  262,   41,   -1,   43,   -1,   45,   -1,   -1,
   -1,   -1,   -1,  264,  265,  266,  267,  268,  269,  264,
  265,  266,  267,  268,  269,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  264,  265,  266,  267,  268,  269,   -1,
   -1,   -1,   -1,  264,  265,  266,  267,  268,  269,  264,
  265,  266,  267,  268,  269,  257,  258,  259,  260,   -1,
   -1,  263,   -1,   -1,  264,  265,  266,  267,  268,  269,
  264,  265,  266,  267,  268,  269,  257,  258,  259,  260,
   -1,   -1,  263,   -1,  257,  258,  259,  260,   -1,   -1,
  263,
};
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 271
#define YYUNDFTOKEN 284
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,
0,0,0,"'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"ENTIER","VARIABLE","PUT","GET","INCREMENT","DECREMENT","QUIT",
"EGAL","DIFFERENT","INFEGAL","SUPEGAL","ET","OU","LEVEL","END",0,0,0,0,0,0,0,0,
0,0,0,0,"illegal-symbol",
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
"expression : PUT '(' expression ',' expression ',' expression ')'",
"expression : GET '(' expression ',' expression ')'",
"expression : '(' addition ')'",
"expression : VARIABLE INCREMENT",
"expression : VARIABLE DECREMENT",
"expression : QUIT",
"expression : expression EGAL expression",
"expression : expression DIFFERENT expression",
"expression : expression '<' expression",
"expression : expression '>' expression",
"expression : expression INFEGAL expression",
"expression : expression SUPEGAL expression",
"expression : expression ET expression",
"expression : expression OU expression",
"niveau : LEVEL end",
"niveau : LEVEL error",
"end : END",

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
#line 243 "analyser.yacc.y"


int put(int x,int y,int z){
  if(x>20 || x<0 || y>60 || y<0){
    fprintf(stderr, "Error at line %d: %s\n", yylineno, "Coordonnées incorrectes");
    return PUT_REJ;
  }else{
    map[x][y]=z;
    return PUT_ACC;
  }
}
int get(int x,int y){
  if(x>20 || x<0 || y>60 || y<0){
    fprintf(stderr, "Error at line %d: %s\n", yylineno, "Coordonnées incorrectes");
    exit(EXIT_FAILURE);
  }else{
    return map[x][y];
  }
}
#line 331 "y.tab.c"

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
#line 49 "analyser.yacc.y"
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
          
          tree_t *tr = yystack.l_mark[-1].tree;
          
          if(tr->isbool == 1){
            if(evaluated_tree(tr) == 1){
              printf("Vrai\n");
            }else{
              printf("Faux\n");
            }
          }else{
            if(evaluated_tree(yystack.l_mark[-1].tree) == PUT_ACC){
              printf("Put effectué\n");
            }else if(evaluated_tree(yystack.l_mark[-1].tree) == PUT_REJ){
              printf("ERROR : Put n'est pas effectué\n");
            }
            else{
              printf("=%lf\n", evaluated_tree(yystack.l_mark[-1].tree));
              print_tree(yystack.l_mark[-1].tree);
              printf("\n");
            }
          }
        }
      }
break;
case 3:
#line 82 "analyser.yacc.y"
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
#line 114 "analyser.yacc.y"
	{
        tree_t *add = create_tree('+',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),0);
        yyval.tree = add;
      }
break;
case 9:
#line 120 "analyser.yacc.y"
	{
        tree_t *sous = create_tree('-',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),0);
        yyval.tree = sous;
      }
break;
case 11:
#line 126 "analyser.yacc.y"
	{
        tree_t *mult = create_tree('*',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),0);
        yyval.tree = mult;
      }
break;
case 13:
#line 132 "analyser.yacc.y"
	{
        if(yystack.l_mark[0].entier!=0){
          tree_t *div = create_tree('/',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),0);
          yyval.tree = div;
        }else{
          if(erreur==0) erreur=ERR_DIV_0;
        }
      }
break;
case 15:
#line 142 "analyser.yacc.y"
	{
        tree_t *moins = create_tree('u',0,create_tree_list(yystack.l_mark[0].tree,NULL),0);
        yyval.tree = moins;
  }
break;
case 17:
#line 151 "analyser.yacc.y"
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
                yyval.tree = create_tree('n',c->var.value.integer,NULL,0);
              }
            }
break;
case 18:
#line 165 "analyser.yacc.y"
	{ tree_t *t = create_tree('n',yystack.l_mark[0].entier,NULL,0); t->value.integer = yystack.l_mark[0].entier; yyval.tree = t;}
break;
case 19:
#line 166 "analyser.yacc.y"
	{ yyval.tree =create_tree('n',put(evaluated_tree(yystack.l_mark[-5].tree),evaluated_tree(yystack.l_mark[-3].tree),evaluated_tree(yystack.l_mark[-1].tree)),NULL,0); }
break;
case 20:
#line 167 "analyser.yacc.y"
	{ yyval.tree = create_tree('n',get(evaluated_tree(yystack.l_mark[-3].tree),evaluated_tree(yystack.l_mark[-1].tree)),NULL,0); }
break;
case 21:
#line 168 "analyser.yacc.y"
	{ yyval.tree = yystack.l_mark[-1].tree; }
break;
case 22:
#line 169 "analyser.yacc.y"
	{ 
              symbol_t var;
              var.type = TYPE_ENTIER;
              var.name = yystack.l_mark[-1].str;
              cell_t *c = search_hach(&table,var);
              if(c==NULL){
              printf("Variable inconnue : %s \n",var.name);
              exit(1);
              }else{
              c->var.value.integer++;
              yyval.tree = create_tree('n',c->var.value.integer,NULL,0);
              }
              free_tree(yystack.l_mark[-1].tree);
              }
break;
case 23:
#line 183 "analyser.yacc.y"
	{
              symbol_t var;
              var.type = TYPE_ENTIER;
              var.name = yystack.l_mark[-1].str;
              cell_t *c = search_hach(&table,var);
              if(c==NULL){
              printf("Variable inconnue : %s \n",var.name);
              exit(1);
              }else{
              c->var.value.integer--;
              yyval.tree = create_tree('n',c->var.value.integer,NULL,0);
              }
              free_tree(yystack.l_mark[-1].tree);
              }
break;
case 24:
#line 197 "analyser.yacc.y"
	{ exit(0); }
break;
case 25:
#line 198 "analyser.yacc.y"
	{ 
              tree_t *egal = create_tree('=',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = egal;
            }
break;
case 26:
#line 202 "analyser.yacc.y"
	{ 
              tree_t *diff = create_tree('!',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = diff;
            }
break;
case 27:
#line 206 "analyser.yacc.y"
	{ 
              tree_t *petit = create_tree('<',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = petit;
            }
break;
case 28:
#line 210 "analyser.yacc.y"
	{ 
              tree_t *grand = create_tree('>',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = grand;
            }
break;
case 29:
#line 214 "analyser.yacc.y"
	{ 
              tree_t *petit = create_tree('I',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = petit;
            }
break;
case 30:
#line 218 "analyser.yacc.y"
	{ 
              tree_t *grand = create_tree('S',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = grand;
            }
break;
case 31:
#line 222 "analyser.yacc.y"
	{ 
              tree_t *et = create_tree('&',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = et;
            }
break;
case 32:
#line 226 "analyser.yacc.y"
	{ 
              tree_t *ou = create_tree('|',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = ou;
            }
break;
case 33:
#line 232 "analyser.yacc.y"
	{
        printf("Found a level\n");
    }
break;
case 34:
#line 235 "analyser.yacc.y"
	{
        fprintf(stderr, "Error at line %d: %s\n", yylineno, "Niveau non terminé");
        exit(EXIT_FAILURE);
    }
break;
case 35:
#line 240 "analyser.yacc.y"
	{
    }
break;
#line 784 "y.tab.c"
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
