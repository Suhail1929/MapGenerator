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
#define VARIABLE 258
#define PUT 259
#define GET 260
#define DOOR 261
#define KEY 262
#define GATE 263
#define INCREMENT 264
#define DECREMENT 265
#define QUIT 266
#define EGAL 267
#define DIFFERENT 268
#define INFEGAL 269
#define SUPEGAL 270
#define ET 271
#define OU 272
#define LEVEL 273
#define END 274
#define IF 275
#define ELSE 276
#define ENDIF 277
#define addition 278
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    4,    0,    0,    3,    3,    3,    2,    2,    2,    2,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,
};
static const YYINT yylen[] = {                            2,
    0,    7,    2,    2,    2,    0,    1,    3,   12,    8,
    1,    3,    3,    3,    3,    3,    2,    1,    8,    6,
    4,    4,    4,    3,    2,    2,    3,    3,    3,    3,
    3,    3,    3,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    3,   18,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   25,
   26,    0,    0,    0,    0,    0,    0,    0,    5,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   24,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    1,    0,    0,   21,
   23,   22,    0,    0,    0,    0,    0,    2,    0,   20,
    0,    0,    0,   19,    0,   10,    0,    0,    0,    9,
};
static const YYINT yydgoto[] = {                          3,
   17,   18,   19,   74,
};
static const YYINT yysindex[] = {                        -9,
   -6,   -9,    0,  -10,    0,    0,  -58,  -34,  -32,  -28,
  -27,  -23,  -21,  -10, -254,  -30,   89,   16, -249,    0,
    0,  -30,  -30,  -30,  -30,  -30,  -30,  -30,    0,  -14,
   89,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
  -30,  -30,  -30,  -30,   19,   89,   68,   75,   24,   31,
   38,   47,    0,   89,   89,   89,   89,   89,   89,   89,
   89,   89,   89,   89,   89,   89,    0,  -30,  -30,    0,
    0,    0,   21,   -9,   82,   54,   15,    0,  -30,    0,
   22,   61,  -38,    0,   23,    0,   15,   26,  -17,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0, -240,    0,    0,   -1,    0,    0,    0,
    0,    0,    0, -240,    0,    0,   27,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    4,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -236,    0,    6,    0,    0,    0,    0,
    0,    0,    0,    8,   10,   12,  123,  128,  129,  130,
  135,  136,  137,  142,  143,   29,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         3,
  346,  -66,   43,    0,
};
#define YYTABLESIZE 435
static const YYINT yytable[] = {                         14,
    2,   15,   22,    4,    5,   23,   16,   24,   11,   15,
   81,   25,   26,   17,   16,   12,   27,   27,   28,   28,
   88,   31,   15,   30,   45,   44,   53,   16,   67,   15,
   77,   83,   87,    6,   16,   89,    7,    4,    8,   11,
   11,   11,   11,   11,   17,   11,   12,   17,   27,   12,
   28,   27,   31,   28,   15,   31,   29,    0,   11,   16,
   11,    0,    0,    0,   70,   40,   38,    0,   39,    0,
   41,   71,   40,   38,    0,   39,   78,   41,   72,   40,
   38,    0,   39,   42,   41,   43,    0,   73,   40,   38,
   42,   39,   43,   41,   80,   40,   38,   42,   39,   43,
   41,   84,   40,   38,    0,   39,   42,   41,   43,   40,
   38,   68,   39,   42,   41,   43,   40,   38,   69,   39,
   42,   41,   43,   40,   38,   79,   39,   42,   41,   43,
   40,   38,   32,   39,   42,   41,   43,   33,   34,   13,
    0,   42,    0,   43,   14,   15,   16,    0,   42,    0,
   43,   29,   30,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   32,    0,    0,   32,    0,   33,   34,
   13,   33,   34,   13,    0,   14,   15,   16,   14,   15,
   16,    0,   29,   30,    0,   29,   30,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   20,   21,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    6,    7,
    8,    9,   10,   11,   12,    0,    6,    7,    8,    9,
   10,   11,   12,    0,    0,    0,    0,   85,   86,    6,
    7,    8,    9,   10,   11,   12,    6,    7,    8,    9,
   10,   11,   12,    0,    0,    0,    0,    0,    0,   90,
    0,    0,    0,    1,   13,   11,   11,   11,   11,   11,
   11,    6,    7,    8,    9,   10,   11,   12,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   13,
   32,   33,   34,   35,   36,   37,    0,   32,   33,   34,
   35,   36,   37,    0,   32,   33,   34,   35,   36,   37,
    0,    0,    0,   32,   33,   34,   35,   36,   37,    0,
   32,   33,   34,   35,   36,   37,    0,   32,   33,   34,
   35,   36,   37,    0,   32,   33,   34,   35,   36,   37,
    0,   32,   33,   34,   35,   36,   37,    0,   32,   33,
   34,   35,   36,   37,    0,   32,   33,   34,   35,   36,
   37,   31,    0,    0,    0,    0,    0,   46,   47,   48,
   49,   50,   51,   52,    0,    0,    0,   54,   55,   56,
   57,   58,   59,   60,   61,   62,   63,   64,   65,   66,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   75,   76,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   82,    0,    0,    0,   66,    0,
    0,    0,    0,    0,   66,
};
static const YYINT yycheck[] = {                         10,
   10,   40,   61,   10,    2,   40,   45,   40,   10,   40,
   77,   40,   40,   10,   45,   10,   40,   10,   40,   10,
   87,   10,   40,  278,  274,   10,   41,   45,   10,   40,
   10,   10,   10,  274,   45,   10,   10,  274,   10,   41,
   42,   43,   44,   45,   41,   47,   41,   44,   41,   44,
   41,   44,   41,   44,   40,   44,   14,   -1,   60,   45,
   62,   -1,   -1,   -1,   41,   42,   43,   -1,   45,   -1,
   47,   41,   42,   43,   -1,   45,   74,   47,   41,   42,
   43,   -1,   45,   60,   47,   62,   -1,   41,   42,   43,
   60,   45,   62,   47,   41,   42,   43,   60,   45,   62,
   47,   41,   42,   43,   -1,   45,   60,   47,   62,   42,
   43,   44,   45,   60,   47,   62,   42,   43,   44,   45,
   60,   47,   62,   42,   43,   44,   45,   60,   47,   62,
   42,   43,   10,   45,   60,   47,   62,   10,   10,   10,
   -1,   60,   -1,   62,   10,   10,   10,   -1,   60,   -1,
   62,   10,   10,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   41,   -1,   -1,   44,   -1,   41,   41,
   41,   44,   44,   44,   -1,   41,   41,   41,   44,   44,
   44,   -1,   41,   41,   -1,   44,   44,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  264,  265,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,
  259,  260,  261,  262,  263,   -1,  257,  258,  259,  260,
  261,  262,  263,   -1,   -1,   -1,   -1,  276,  277,  257,
  258,  259,  260,  261,  262,  263,  257,  258,  259,  260,
  261,  262,  263,   -1,   -1,   -1,   -1,   -1,   -1,  277,
   -1,   -1,   -1,  273,  275,  267,  268,  269,  270,  271,
  272,  257,  258,  259,  260,  261,  262,  263,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  275,
  267,  268,  269,  270,  271,  272,   -1,  267,  268,  269,
  270,  271,  272,   -1,  267,  268,  269,  270,  271,  272,
   -1,   -1,   -1,  267,  268,  269,  270,  271,  272,   -1,
  267,  268,  269,  270,  271,  272,   -1,  267,  268,  269,
  270,  271,  272,   -1,  267,  268,  269,  270,  271,  272,
   -1,  267,  268,  269,  270,  271,  272,   -1,  267,  268,
  269,  270,  271,  272,   -1,  267,  268,  269,  270,  271,
  272,   16,   -1,   -1,   -1,   -1,   -1,   22,   23,   24,
   25,   26,   27,   28,   -1,   -1,   -1,   32,   33,   34,
   35,   36,   37,   38,   39,   40,   41,   42,   43,   44,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   68,   69,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   79,   -1,   -1,   -1,   83,   -1,
   -1,   -1,   -1,   -1,   89,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 278
#define YYUNDFTOKEN 285
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
0,0,0,0,0,0,"ENTIER","VARIABLE","PUT","GET","DOOR","KEY","GATE","INCREMENT",
"DECREMENT","QUIT","EGAL","DIFFERENT","INFEGAL","SUPEGAL","ET","OU","LEVEL",
"END","IF","ELSE","ENDIF","addition",0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : niveau",
"$$1 :",
"niveau : LEVEL '\\n' programme END '\\n' $$1 niveau",
"niveau : '\\n' niveau",
"programme : expr_list '\\n'",
"programme : '\\n' programme",
"programme :",
"expr_list : expression",
"expr_list : expr_list '\\n' expression",
"expr_list : IF '(' expression ')' '\\n' expr_list '\\n' ELSE '\\n' expr_list '\\n' ENDIF",
"expr_list : IF '(' expression ')' '\\n' expr_list '\\n' ENDIF",
"expression : VARIABLE",
"expression : VARIABLE '=' expression",
"expression : expression '+' expression",
"expression : expression '-' expression",
"expression : expression '*' expression",
"expression : expression '/' expression",
"expression : '-' expression",
"expression : ENTIER",
"expression : PUT '(' expression ',' expression ',' expression ')'",
"expression : GET '(' expression ',' expression ')'",
"expression : DOOR '(' expression ')'",
"expression : GATE '(' expression ')'",
"expression : KEY '(' expression ')'",
"expression : '(' addition ')'",
"expression : VARIABLE INCREMENT",
"expression : VARIABLE DECREMENT",
"expression : expression EGAL expression",
"expression : expression DIFFERENT expression",
"expression : expression '<' expression",
"expression : expression '>' expression",
"expression : expression INFEGAL expression",
"expression : expression SUPEGAL expression",
"expression : expression ET expression",
"expression : expression OU expression",

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
#line 248 "analyser.yacc.y"

#line 348 "y.tab.c"

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
#line 54 "analyser.yacc.y"
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
case 4:
#line 66 "analyser.yacc.y"
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
                tree_list_t *tree_list = yystack.l_mark[-1].tree_list;
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
case 7:
#line 102 "analyser.yacc.y"
	{
              yyval.tree_list = malloc(sizeof(tree_list_t));
              yyval.tree_list->tree = yystack.l_mark[0].tree;
              yyval.tree_list->next = NULL;
            }
break;
case 8:
#line 107 "analyser.yacc.y"
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
case 9:
#line 117 "analyser.yacc.y"
	{
              if(evaluated_tree(yystack.l_mark[-9].tree) == 1){
                  yyval.tree_list = yystack.l_mark[-6].tree_list;
              }else{
                  yyval.tree_list = yystack.l_mark[-3].tree_list;
              }
              }
break;
case 10:
#line 124 "analyser.yacc.y"
	{
                  if(evaluated_tree(yystack.l_mark[-5].tree) == 1){
                      yyval.tree_list = yystack.l_mark[-2].tree_list;
                  }else{
                      yyval.tree_list = NULL;
                  }
              }
break;
case 11:
#line 134 "analyser.yacc.y"
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
case 12:
#line 149 "analyser.yacc.y"
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
case 13:
#line 173 "analyser.yacc.y"
	{ yyval.tree = create_tree('+',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),0);}
break;
case 14:
#line 174 "analyser.yacc.y"
	{ yyval.tree = create_tree('-',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),0);}
break;
case 15:
#line 175 "analyser.yacc.y"
	{ yyval.tree = create_tree('*',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),0);}
break;
case 16:
#line 176 "analyser.yacc.y"
	{ if(yystack.l_mark[0].tree != 0){yyval.tree = create_tree('/',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),0);}}
break;
case 17:
#line 177 "analyser.yacc.y"
	{ yyval.tree = create_tree('u',0,create_tree_list(yystack.l_mark[0].tree,NULL),0);}
break;
case 18:
#line 178 "analyser.yacc.y"
	{ tree_t *t = create_tree('n',yystack.l_mark[0].entier,NULL,0); t->value.integer = yystack.l_mark[0].entier; yyval.tree = t;}
break;
case 19:
#line 179 "analyser.yacc.y"
	{ yyval.tree =create_tree('P',0,create_tree_list(yystack.l_mark[-5].tree,create_tree_list(yystack.l_mark[-3].tree,create_tree_list(yystack.l_mark[-1].tree,NULL))),0); }
break;
case 20:
#line 180 "analyser.yacc.y"
	{ yyval.tree = create_tree('G',0,create_tree_list(yystack.l_mark[-3].tree,create_tree_list(yystack.l_mark[-1].tree,NULL)),0); }
break;
case 21:
#line 181 "analyser.yacc.y"
	{ yyval.tree = create_tree('n',door(evaluated_tree(yystack.l_mark[-1].tree)),NULL,0); }
break;
case 22:
#line 182 "analyser.yacc.y"
	{ yyval.tree = create_tree('n',gate(evaluated_tree(yystack.l_mark[-1].tree)),NULL,0); }
break;
case 23:
#line 183 "analyser.yacc.y"
	{ yyval.tree = create_tree('n',key(evaluated_tree(yystack.l_mark[-1].tree)),NULL,0); }
break;
case 24:
#line 184 "analyser.yacc.y"
	{ yyval.tree = yystack.l_mark[-1].tree; }
break;
case 25:
#line 185 "analyser.yacc.y"
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
case 26:
#line 199 "analyser.yacc.y"
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
case 27:
#line 214 "analyser.yacc.y"
	{ 
              tree_t *egal = create_tree('=',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = egal;
            }
break;
case 28:
#line 218 "analyser.yacc.y"
	{ 
              tree_t *diff = create_tree('!',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = diff;
            }
break;
case 29:
#line 222 "analyser.yacc.y"
	{ 
              tree_t *petit = create_tree('<',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = petit;
            }
break;
case 30:
#line 226 "analyser.yacc.y"
	{ 
              tree_t *grand = create_tree('>',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = grand;
            }
break;
case 31:
#line 230 "analyser.yacc.y"
	{ 
              tree_t *petit = create_tree('I',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = petit;
            }
break;
case 32:
#line 234 "analyser.yacc.y"
	{ 
              tree_t *grand = create_tree('S',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = grand;
            }
break;
case 33:
#line 238 "analyser.yacc.y"
	{ 
              tree_t *et = create_tree('&',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = et;
            }
break;
case 34:
#line 242 "analyser.yacc.y"
	{ 
              tree_t *ou = create_tree('|',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
              yyval.tree = ou;
            }
break;
#line 822 "y.tab.c"
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
