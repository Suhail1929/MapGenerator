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
#include "List.h"
#include "hach_table.h"
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include "level.h"
#include "include.h"

int erreur = 0;
char *symbole_erreur = NULL;
#line 18 "analyser.yacc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
  char* str;
  int entier;
  tree_list_t* tree_list;
  tree_t* tree;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 51 "y.tab.c"

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
#define variable 258
#define put_ 259
#define get_ 260
#define door_ 261
#define key_ 262
#define gate_ 263
#define incr 264
#define decr 265
#define quit 266
#define egal 267
#define diff 268
#define infegal 269
#define supegal 270
#define et 271
#define ou 272
#define level_ 273
#define end 274
#define IF 275
#define ELSE 276
#define endif 277
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    3,    3,    4,    4,    4,    2,    2,    2,
    2,    2,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,
};
static const YYINT yylen[] = {                            2,
    1,    2,    4,    2,    1,    2,    0,    1,    3,   12,
    8,    3,    1,    3,    3,    3,    3,    3,    2,    1,
    8,    6,    4,    4,    4,    3,    2,    2,    3,    3,
    3,    3,    3,    3,    3,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,   20,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    4,    2,
   27,   28,    0,    0,    0,    0,    0,    0,    0,    6,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   26,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   12,    3,    0,
    0,   23,   25,   24,    0,    0,    0,    0,    0,   22,
    0,    0,    0,   21,    0,   11,    0,    0,    0,   10,
};
static const YYINT yydgoto[] = {                          3,
   16,   17,    4,   68,
};
static const YYINT yysindex[] = {                        -9,
   18,   -9,   -9,    0,    0,  -55,  -29,  -27,  -18,  -17,
  -16,  -13,   18,  -30,  -30,  152,   19, -243,    0,    0,
    0,    0,  -30,  -30,  -30,  -30,  -30,  -30,  -30,    0,
   64,  152,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
  -30,  -30,  -30,  -30,   18,   22,  152,  122,  131,   71,
   78,   87,   94,    0,  152,  152,  152,  152,  152,  152,
  152,  152,  152,  152,  152,  152,  152,    0,    0,  -30,
  -30,    0,    0,    0,   23,  143,  101,  -37,  -30,    0,
   24,  110,  -10,    0,   31,    0,  -37,   34,   -3,    0,
};
static const YYINT yyrindex[] = {                         0,
 -226,    0,    0,    0,    0,   28,    0,    0,    0,    0,
    0,    0, -226,    0,    0,   -6, -210,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   -5,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -226,    0,   -1,    0,    0,    0,
    0,    0,    0,    0,    8,    9,   10,   15,   16,   35,
   36,   37,   45,   51,   52,   56,   -6,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  402,  -66,   14,    1,
};
#define YYTABLESIZE 491
static const YYINT yytable[] = {                         13,
    2,   18,   14,    8,   19,   23,   13,   15,   14,   14,
   24,   81,   25,   30,   15,   19,   20,   29,   30,   33,
   88,   26,   27,   28,   34,   35,   29,   13,   45,   14,
   46,   69,   78,   83,   15,   19,   14,   13,   19,   14,
   87,   15,   14,   89,   36,   15,   16,    7,   29,   30,
   33,   29,   30,   33,   17,   34,   35,   14,   34,   35,
   18,   31,   15,    5,    0,   32,    0,    0,   13,   13,
   13,   13,   13,    0,   13,   36,   15,   16,   36,   15,
   16,    0,    0,    0,    0,   17,    0,   13,   17,   13,
    0,   18,   31,    0,   18,   31,   32,    0,    0,   32,
    0,    0,    0,    0,   54,   41,   39,    0,   40,    0,
   42,   72,   41,   39,    0,   40,    0,   42,   73,   41,
   39,    0,   40,   43,   42,   44,    0,   74,   41,   39,
   43,   40,   44,   42,   75,   41,   39,   43,   40,   44,
   42,   80,   41,   39,    0,   40,   43,   42,   44,    0,
   84,   41,   39,   43,   40,   44,   42,    0,    0,    0,
   43,    0,   44,   41,   39,   70,   40,    0,   42,   43,
    0,   44,   41,   39,   71,   40,    0,   42,    0,    0,
    0,   43,    0,   44,   41,   39,   79,   40,    0,   42,
   43,    0,   44,   41,   39,    0,   40,    0,   42,    0,
    0,    0,   43,    0,   44,    0,    0,    0,   21,   22,
    0,   43,    0,   44,    0,    0,    0,    0,    0,    5,
    6,    7,    8,    9,   10,   11,    5,    6,    7,    8,
    9,   10,   11,    0,    0,    0,    0,   12,    0,    0,
    0,    0,    0,    0,    0,    0,    5,    6,    7,    8,
    9,   10,   11,    5,    6,    7,    8,    9,   10,   11,
    0,    0,    0,    1,   12,   85,   86,    8,   19,    0,
    0,   12,   14,   90,    5,    6,    7,    8,    9,   10,
   11,   29,   30,   33,    0,    0,    0,    0,   34,   35,
    0,    0,   12,    0,   13,   13,   13,   13,   13,   13,
    0,   13,    0,    0,    0,    0,    0,    0,   36,   15,
   16,    0,    0,    0,    0,    0,    0,    0,   17,    0,
    0,    0,    0,    0,   18,   31,    0,    0,    0,   32,
   33,   34,   35,   36,   37,   38,    0,   33,   34,   35,
   36,   37,   38,    0,   33,   34,   35,   36,   37,   38,
    0,    0,    0,   33,   34,   35,   36,   37,   38,    0,
   33,   34,   35,   36,   37,   38,    0,   33,   34,   35,
   36,   37,   38,    0,    0,    0,   33,   34,   35,   36,
   37,   38,    0,    0,    0,    0,    0,    0,   33,   34,
   35,   36,   37,   38,    0,    0,    0,   33,   34,   35,
   36,   37,   38,    0,    0,    0,    0,    0,    0,   33,
   34,   35,   36,   37,   38,   31,   32,    0,   33,   34,
   35,   36,   37,   38,   47,   48,   49,   50,   51,   52,
   53,    0,    0,    0,   55,   56,   57,   58,   59,   60,
   61,   62,   63,   64,   65,   66,   67,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   76,   77,    0,    0,    0,    0,    0,    0,    0,
   82,    0,    0,    0,   67,    0,    0,    0,    0,    0,
   67,
};
static const YYINT yycheck[] = {                         10,
   10,    1,   40,   10,   10,   61,   10,   45,   10,   40,
   40,   78,   40,   13,   45,    2,    3,   10,   10,   10,
   87,   40,   40,   40,   10,   10,   40,   10,   10,   40,
  274,   10,   10,   10,   45,   41,   40,   10,   44,   41,
   10,   45,   44,   10,   10,   10,   10,  274,   41,   41,
   41,   44,   44,   44,   10,   41,   41,   40,   44,   44,
   10,   10,   45,  274,   -1,   10,   -1,   -1,   41,   42,
   43,   44,   45,   -1,   47,   41,   41,   41,   44,   44,
   44,   -1,   -1,   -1,   -1,   41,   -1,   60,   44,   62,
   -1,   41,   41,   -1,   44,   44,   41,   -1,   -1,   44,
   -1,   -1,   -1,   -1,   41,   42,   43,   -1,   45,   -1,
   47,   41,   42,   43,   -1,   45,   -1,   47,   41,   42,
   43,   -1,   45,   60,   47,   62,   -1,   41,   42,   43,
   60,   45,   62,   47,   41,   42,   43,   60,   45,   62,
   47,   41,   42,   43,   -1,   45,   60,   47,   62,   -1,
   41,   42,   43,   60,   45,   62,   47,   -1,   -1,   -1,
   60,   -1,   62,   42,   43,   44,   45,   -1,   47,   60,
   -1,   62,   42,   43,   44,   45,   -1,   47,   -1,   -1,
   -1,   60,   -1,   62,   42,   43,   44,   45,   -1,   47,
   60,   -1,   62,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   -1,   60,   -1,   62,   -1,   -1,   -1,  264,  265,
   -1,   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,  257,
  258,  259,  260,  261,  262,  263,  257,  258,  259,  260,
  261,  262,  263,   -1,   -1,   -1,   -1,  275,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,
  261,  262,  263,  257,  258,  259,  260,  261,  262,  263,
   -1,   -1,   -1,  273,  275,  276,  277,  274,  274,   -1,
   -1,  275,  274,  277,  257,  258,  259,  260,  261,  262,
  263,  274,  274,  274,   -1,   -1,   -1,   -1,  274,  274,
   -1,   -1,  275,   -1,  267,  268,  269,  270,  271,  272,
   -1,  274,   -1,   -1,   -1,   -1,   -1,   -1,  274,  274,
  274,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,   -1,
   -1,   -1,   -1,   -1,  274,  274,   -1,   -1,   -1,  274,
  267,  268,  269,  270,  271,  272,   -1,  267,  268,  269,
  270,  271,  272,   -1,  267,  268,  269,  270,  271,  272,
   -1,   -1,   -1,  267,  268,  269,  270,  271,  272,   -1,
  267,  268,  269,  270,  271,  272,   -1,  267,  268,  269,
  270,  271,  272,   -1,   -1,   -1,  267,  268,  269,  270,
  271,  272,   -1,   -1,   -1,   -1,   -1,   -1,  267,  268,
  269,  270,  271,  272,   -1,   -1,   -1,  267,  268,  269,
  270,  271,  272,   -1,   -1,   -1,   -1,   -1,   -1,  267,
  268,  269,  270,  271,  272,   14,   15,   -1,  267,  268,
  269,  270,  271,  272,   23,   24,   25,   26,   27,   28,
   29,   -1,   -1,   -1,   33,   34,   35,   36,   37,   38,
   39,   40,   41,   42,   43,   44,   45,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   70,   71,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   79,   -1,   -1,   -1,   83,   -1,   -1,   -1,   -1,   -1,
   89,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 277
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
0,0,0,0,0,0,"ENTIER","variable","put_","get_","door_","key_","gate_","incr",
"decr","quit","egal","diff","infegal","supegal","et","ou","level_","end","IF",
"ELSE","endif",0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : LEVELS",
"LEVELS : LEVEL",
"LEVELS : LEVELS LEVEL",
"LEVEL : level_ PROGRAMME end '\\n'",
"LEVEL : '\\n' LEVEL",
"PROGRAMME : EXPR_LIST",
"PROGRAMME : '\\n' PROGRAMME",
"PROGRAMME :",
"EXPR_LIST : EXPRESSION",
"EXPR_LIST : EXPR_LIST '\\n' EXPRESSION",
"EXPR_LIST : IF '(' EXPRESSION ')' '\\n' EXPR_LIST '\\n' ELSE '\\n' EXPR_LIST '\\n' endif",
"EXPR_LIST : IF '(' EXPRESSION ')' '\\n' EXPR_LIST '\\n' endif",
"EXPR_LIST : EXPR_LIST '\\n' PROGRAMME",
"EXPRESSION : variable",
"EXPRESSION : variable '=' EXPRESSION",
"EXPRESSION : EXPRESSION '+' EXPRESSION",
"EXPRESSION : EXPRESSION '-' EXPRESSION",
"EXPRESSION : EXPRESSION '*' EXPRESSION",
"EXPRESSION : EXPRESSION '/' EXPRESSION",
"EXPRESSION : '-' EXPRESSION",
"EXPRESSION : ENTIER",
"EXPRESSION : put_ '(' EXPRESSION ',' EXPRESSION ',' EXPRESSION ')'",
"EXPRESSION : get_ '(' EXPRESSION ',' EXPRESSION ')'",
"EXPRESSION : door_ '(' EXPRESSION ')'",
"EXPRESSION : gate_ '(' EXPRESSION ')'",
"EXPRESSION : key_ '(' EXPRESSION ')'",
"EXPRESSION : '(' EXPRESSION ')'",
"EXPRESSION : variable incr",
"EXPRESSION : variable decr",
"EXPRESSION : EXPRESSION egal EXPRESSION",
"EXPRESSION : EXPRESSION diff EXPRESSION",
"EXPRESSION : EXPRESSION '<' EXPRESSION",
"EXPRESSION : EXPRESSION '>' EXPRESSION",
"EXPRESSION : EXPRESSION infegal EXPRESSION",
"EXPRESSION : EXPRESSION supegal EXPRESSION",
"EXPRESSION : EXPRESSION et EXPRESSION",
"EXPRESSION : EXPRESSION ou EXPRESSION",

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
#line 253 "analyser.yacc.y"

#line 361 "y.tab.c"

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
case 3:
#line 58 "analyser.yacc.y"
	{
        printf("Found a level\n");
        if(setlocale(LC_ALL, "") == NULL)printf("setlocale failed.\n");
        level_t level;
        level_init(&level);  
        draw_map(&level);
        level_display(&level);
        map_init();
    }
break;
case 5:
#line 70 "analyser.yacc.y"
	{
              if (erreur == ERR_DIV_0) {
                printf("Erreur de division par zéro\n");
                erreur = 0;
              } else if (erreur == ERR_SYMBOLE) {
                printf("Symbole inconnu rencontré : %s\n", symbole_erreur);
                free(symbole_erreur);
                symbole_erreur = NULL;
                erreur = 0;
              } else {
                tree_list_t *tree_list = yystack.l_mark[0].tree_list;
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
break;
case 8:
#line 106 "analyser.yacc.y"
	{
              yyval.tree_list = malloc(sizeof(tree_list_t));
              yyval.tree_list->tree = yystack.l_mark[0].tree;
              yyval.tree_list->next = NULL;
            }
break;
case 9:
#line 111 "analyser.yacc.y"
	{
              tree_list_t *e = malloc(sizeof(tree_list_t));
              e->tree = yystack.l_mark[0].tree;
              e->next = NULL;
              tree_list_t *last = yystack.l_mark[-2].tree_list;
              while (last->next) {
                last = last->next;
              }
              last->next = e;
            }
break;
case 10:
#line 121 "analyser.yacc.y"
	{
              if(evaluated_tree(yystack.l_mark[-9].tree) == 1){
                  yyval.tree_list = yystack.l_mark[-6].tree_list;
              }else{
                  yyval.tree_list = yystack.l_mark[-2].tree_list;
              }
              }
break;
case 11:
#line 128 "analyser.yacc.y"
	{
                  if(evaluated_tree(yystack.l_mark[-5].tree) == 1){
                      yyval.tree_list = yystack.l_mark[-2].tree_list;
                  }else{
                      yyval.tree_list = NULL;
                  }
              }
break;
case 13:
#line 139 "analyser.yacc.y"
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
case 14:
#line 154 "analyser.yacc.y"
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
                var.name=yystack.l_mark[-2].str;
                var.value.integer=evaluated_tree(yystack.l_mark[0].tree);
                c=search_hach(&table,var);
                if(c==NULL){
                  insert_hach(&table,var);
                }else{
                  c->var.value.integer=var.value.integer;
                }
               yyval.tree = create_tree('n',var.value.integer,NULL,0);
              }
              free_tree(yystack.l_mark[0].tree);
            }
break;
case 15:
#line 178 "analyser.yacc.y"
	{ yyval.tree = create_tree('+',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),0);}
break;
case 16:
#line 179 "analyser.yacc.y"
	{ yyval.tree = create_tree('-',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),0);}
break;
case 17:
#line 180 "analyser.yacc.y"
	{ yyval.tree = create_tree('*',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),0);}
break;
case 18:
#line 181 "analyser.yacc.y"
	{ if(yystack.l_mark[0].tree != 0){yyval.tree = create_tree('/',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),0);}}
break;
case 19:
#line 182 "analyser.yacc.y"
	{ yyval.tree = create_tree('u',0,create_tree_list(yystack.l_mark[0].tree,NULL),0);}
break;
case 20:
#line 183 "analyser.yacc.y"
	{ tree_t *t = create_tree('n',yystack.l_mark[0].entier,NULL,0); t->value.integer = yystack.l_mark[0].entier; yyval.tree = t;}
break;
case 21:
#line 184 "analyser.yacc.y"
	{ yyval.tree =create_tree('P',0,create_tree_list(yystack.l_mark[-5].tree,create_tree_list(yystack.l_mark[-3].tree,create_tree_list(yystack.l_mark[-1].tree,NULL))),0); }
break;
case 22:
#line 185 "analyser.yacc.y"
	{ yyval.tree = create_tree('G',0,create_tree_list(yystack.l_mark[-3].tree,create_tree_list(yystack.l_mark[-1].tree,NULL)),0); }
break;
case 23:
#line 186 "analyser.yacc.y"
	{ yyval.tree = create_tree('n',door(evaluated_tree(yystack.l_mark[-1].tree)),NULL,0); }
break;
case 24:
#line 187 "analyser.yacc.y"
	{ yyval.tree = create_tree('n',gate(evaluated_tree(yystack.l_mark[-1].tree)),NULL,0); }
break;
case 25:
#line 188 "analyser.yacc.y"
	{ yyval.tree = create_tree('n',key(evaluated_tree(yystack.l_mark[-1].tree)),NULL,0); }
break;
case 26:
#line 189 "analyser.yacc.y"
	{ yyval.tree = create_tree('n',evaluated_tree(yystack.l_mark[-1].tree),NULL,0); }
break;
case 27:
#line 190 "analyser.yacc.y"
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
case 28:
#line 204 "analyser.yacc.y"
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
case 29:
#line 219 "analyser.yacc.y"
	{ 
              tree_t *eg = create_tree('=',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = eg;
            }
break;
case 30:
#line 223 "analyser.yacc.y"
	{ 
              tree_t *dif = create_tree('!',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = dif;
            }
break;
case 31:
#line 227 "analyser.yacc.y"
	{ 
              tree_t *petit = create_tree('<',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = petit;
            }
break;
case 32:
#line 231 "analyser.yacc.y"
	{ 
              tree_t *grand = create_tree('>',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = grand;
            }
break;
case 33:
#line 235 "analyser.yacc.y"
	{ 
              tree_t *petit = create_tree('I',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = petit;
            }
break;
case 34:
#line 239 "analyser.yacc.y"
	{ 
              tree_t *grand = create_tree('S',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = grand;
            }
break;
case 35:
#line 243 "analyser.yacc.y"
	{ 
              tree_t *e = create_tree('&',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = e;
            }
break;
case 36:
#line 247 "analyser.yacc.y"
	{ 
              tree_t *o = create_tree('|',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = o;
            }
break;
#line 835 "y.tab.c"
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
