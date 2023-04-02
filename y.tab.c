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

#line 1 "generator.yacc.y"

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

#line 19 "generator.yacc.y"
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
#line 52 "y.tab.c"

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

#define put_ 257
#define get_ 258
#define door_ 259
#define key_ 260
#define gate_ 261
#define incr 262
#define decr 263
#define egal 264
#define diff 265
#define infegal 266
#define supegal 267
#define et 268
#define ou 269
#define level_ 270
#define end 271
#define IF 272
#define ELSE 273
#define endif 274
#define FOR 275
#define endfor 276
#define WHILE 277
#define endwhile 278
#define fct 279
#define endfct 280
#define prc 281
#define endprc 282
#define ENTIER 283
#define FUNCNAME 284
#define PROCNAME 285
#define variable 286
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,   10,    4,    4,    4,    4,    4,    4,
    4,    4,    5,    5,   11,   11,    9,    9,    8,    8,
    8,    6,    7,    3,    3,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
};
static const YYINT yylen[] = {                            2,
    3,    4,    2,    1,    1,    2,    1,    2,    1,    2,
    1,    2,    8,    6,    7,    7,    4,    4,    0,    1,
    3,   12,    6,    1,    3,    1,    1,    3,    3,    3,
    3,    1,    8,    6,    4,    4,    4,    3,    2,    2,
    3,    3,    3,    3,    3,    3,    3,    3,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   32,    0,    0,    0,    0,    0,   26,    0,    7,    9,
   11,   27,    0,    0,    0,    0,    3,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   39,   40,    0,
    0,    0,    0,    0,    0,    0,    8,   10,   12,    1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   38,
    0,    0,   30,   31,    2,    0,    0,    0,    0,   35,
   37,   36,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   18,    0,   17,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   34,    0,   14,    0,   23,
    0,    0,    0,    0,    0,   16,   15,   33,   13,    0,
    0,    0,    0,   22,
};
static const YYINT yydgoto[] = {                          2,
   60,   16,   17,   18,   19,   20,   21,   67,   22,   23,
   27,
};
static const YYINT yysindex[] = {                      -257,
  310, -258,  -25,  -21,  -12,   -4,   -3,    1,    5,   29,
    0,   31,   36,  -55,  119,  167,    0,  310,    0,    0,
    0,    0, -239,  310, -233, -199,    0,  119,  119,  119,
  119,  119,  289, -198,  289,  119,  119,    0,    0,  119,
   25,  119,  119,  119,  119,  167,    0,    0,    0,    0,
 -179,   58,   60,   11,  121,   32,   42,   54,    0,   61,
   79,    0,   43,   71,   76,  167,  -27,  -17,  167,    0,
  -31,  -31,    0,    0,    0,  119,  119,  119,  119,    0,
    0,    0,  310,  119,  119,  119,  119,  119,  119,  119,
  119,  119,  310,    0,  119,    0,  -15,    2,  127,   64,
  140,  167,  167,  167,  167,  167,  167,  167,  167,  134,
  161,  167,  310,  310,  119,    0,  310,    0,  119,    0,
  199,  229,  106,  259,  148,    0,    0,    0,    0,  119,
  115,  310,  280,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -40,    0,   80,    0, -152,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    3,    3,    0,    0,    0,
    0,    0,    0,    0,    0,  110,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  142,    0,
    0,  407,   83,    0,    0,   18,    0,    0,   50,    0,
  -10,   20,    0,    0,    0,    3,    3,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   89,   91,   96,   97,  104,  111,  113,  120,    0,
    0,   37,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  107,  601,  101,  -75,   -8,    7,   22,  -28,    0,  143,
    0,
};
#define YYTABLESIZE 734
static const YYINT yytable[] = {                         24,
   24,   24,   24,   24,   24,   40,   24,  101,   68,   47,
   44,   24,    1,   94,   28,   45,   95,  111,   29,   24,
   25,   24,   26,   96,   48,  113,   95,   30,   95,   28,
   28,   50,   28,   28,   28,   31,   32,  121,  122,   49,
   33,  124,  114,   19,   34,   95,   19,   97,   98,   28,
   52,   28,   44,   42,   78,   43,  133,   45,   20,   29,
   29,   20,   29,   29,   29,   70,   44,   42,   35,   43,
   36,   45,   80,   44,   42,   37,   43,   21,   45,   29,
   21,   29,   81,   44,   42,   53,   43,   63,   45,   25,
   25,   75,   47,   25,   82,   44,   42,   76,   43,   77,
   45,   83,   47,   40,  116,   44,   42,   48,   43,   25,
   45,   25,   47,   47,   92,   47,   93,   48,    4,    5,
   44,   42,   49,   43,   47,   45,   24,   48,   48,   41,
   48,   42,   49,   62,   64,   62,   45,   46,   90,   48,
   91,   65,   49,   49,   47,   49,  128,   44,   42,    6,
   43,   48,   45,   43,   49,  132,   44,   42,   15,   43,
   44,   45,   44,   42,   79,   43,   51,   45,   44,   42,
  115,   43,    0,   45,    0,   44,   42,  119,   43,   15,
   45,    0,   49,   32,   32,    0,   32,    0,   32,   44,
   42,  130,   43,    0,   45,    0,    0,    0,    0,    0,
   15,   32,    0,   32,    0,    0,   38,   39,   44,   42,
    0,   43,    0,   45,    0,    0,   24,   24,   24,   24,
   24,    0,    0,   24,   24,   24,   24,   24,   24,    0,
   24,   24,   24,   24,   24,   24,   24,   24,   15,   24,
    0,   24,   24,   24,   24,   24,   28,   28,   28,   28,
   28,    0,    0,   28,   28,   28,   28,   28,   28,    0,
   28,   28,   28,   28,   28,   28,   28,   28,   15,   28,
    0,   28,   28,   28,   28,   28,   29,   29,   29,   29,
   29,    0,    0,   29,   29,   29,   29,   29,   29,    0,
   29,   29,   29,   29,   29,   29,   29,   29,   15,   29,
    0,   29,   29,   29,   29,   29,   25,   25,   25,   25,
   25,    0,    0,   25,   25,   25,   25,   25,   25,   15,
   25,   25,   25,   25,   25,   25,   25,   25,   15,   25,
    0,   25,   25,   25,   25,   25,    5,    5,    5,    5,
    5,    0,   84,   85,   86,   87,   88,   89,    0,   15,
    5,    5,    5,    5,    5,    5,    5,    5,    0,    5,
    0,    5,    5,    5,    5,    5,    6,    6,    6,    6,
    6,    0,    0,    0,    0,    3,    4,    5,    6,    7,
    6,    6,    6,    6,    6,    6,    6,    6,    0,    6,
    0,    6,    6,    6,    6,    6,    3,    4,    5,    6,
    7,   11,   12,   13,   14,   32,   32,   32,   32,   32,
   32,    8,  117,  118,    9,    0,   10,    3,    4,    5,
    6,    7,   11,   12,   13,   14,    0,    0,    0,    0,
    0,    0,    8,    0,    0,    9,    0,   10,  120,    0,
    0,    0,    0,   11,   12,   13,   14,   50,   26,   26,
    0,   26,    0,   26,    0,    3,    4,    5,    6,    7,
    0,    0,    0,    0,    0,    0,   26,    0,   26,    0,
    8,    0,    0,    9,    0,   10,    0,    0,  126,    0,
    0,   11,   12,   13,   14,    3,    4,    5,    6,    7,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    8,    0,    0,    9,    0,   10,    0,    0,    0,    0,
  127,   11,   12,   13,   14,    3,    4,    5,    6,    7,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    8,    0,  129,    9,    0,   10,    3,    4,    5,    6,
    7,   11,   12,   13,   14,    3,    4,    5,    6,    7,
    0,    8,    0,    0,    9,  134,   10,    0,    0,    0,
    0,    0,   11,   12,   13,   14,    3,    4,    5,    6,
    7,   59,   12,   13,   14,    0,    0,    0,    0,    0,
    0,    8,    0,    0,    9,    0,   10,    0,    0,    0,
    0,    0,   11,   12,   13,   14,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   41,    0,    0,   46,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   54,   55,
   56,   57,   58,   61,    0,   61,   66,   66,    0,    0,
   69,    0,   71,   72,   73,   74,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   26,   26,   26,   26,   26,   26,   66,   66,   99,  100,
    0,    0,    0,    0,  102,  103,  104,  105,  106,  107,
  108,  109,  110,    0,    0,  112,    0,    0,    0,    0,
    0,   46,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   46,    0,    0,    0,  123,    0,    0,    0,  125,
    0,   46,   46,    0,   46,    0,    0,    0,    0,    0,
  131,    0,    0,   46,
};
static const YYINT yycheck[] = {                         40,
   41,   42,   43,   44,   45,   61,   47,   83,   37,   18,
   42,  270,  270,   41,   40,   47,   44,   93,   40,   60,
  279,   62,  281,   41,   18,   41,   44,   40,   44,   40,
   41,  271,   43,   44,   45,   40,   40,  113,  114,   18,
   40,  117,   41,   41,   40,   44,   44,   76,   77,   60,
  284,   62,   42,   43,   44,   45,  132,   47,   41,   40,
   41,   44,   43,   44,   45,   41,   42,   43,   40,   45,
   40,   47,   41,   42,   43,   40,   45,   41,   47,   60,
   44,   62,   41,   42,   43,  285,   45,  286,   47,   40,
   41,  271,  101,   44,   41,   42,   43,   40,   45,   40,
   47,   41,  111,   61,   41,   42,   43,  101,   45,   60,
   47,   62,  121,  122,   44,  124,   41,  111,  271,   40,
   42,   43,  101,   45,  133,   47,   44,  121,  122,   41,
  124,   41,  111,   33,   34,   35,   41,   41,   60,  133,
   62,   35,  121,  122,   41,  124,   41,   42,   43,   40,
   45,   41,   47,   41,  133,   41,   42,   43,   40,   45,
   41,   47,   42,   43,   44,   45,   24,   47,   42,   43,
   44,   45,   -1,   47,   -1,   42,   43,   44,   45,   40,
   47,   -1,   41,   42,   43,   -1,   45,   -1,   47,   42,
   43,   44,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,
   40,   60,   -1,   62,   -1,   -1,  262,  263,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,  257,  258,  259,  260,
  261,   -1,   -1,  264,  265,  266,  267,  268,  269,   -1,
  271,  272,  273,  274,  275,  276,  277,  278,   40,  280,
   -1,  282,  283,  284,  285,  286,  257,  258,  259,  260,
  261,   -1,   -1,  264,  265,  266,  267,  268,  269,   -1,
  271,  272,  273,  274,  275,  276,  277,  278,   40,  280,
   -1,  282,  283,  284,  285,  286,  257,  258,  259,  260,
  261,   -1,   -1,  264,  265,  266,  267,  268,  269,   -1,
  271,  272,  273,  274,  275,  276,  277,  278,   40,  280,
   -1,  282,  283,  284,  285,  286,  257,  258,  259,  260,
  261,   -1,   -1,  264,  265,  266,  267,  268,  269,   40,
  271,  272,  273,  274,  275,  276,  277,  278,   40,  280,
   -1,  282,  283,  284,  285,  286,  257,  258,  259,  260,
  261,   -1,  264,  265,  266,  267,  268,  269,   -1,   40,
  271,  272,  273,  274,  275,  276,  277,  278,   -1,  280,
   -1,  282,  283,  284,  285,  286,  257,  258,  259,  260,
  261,   -1,   -1,   -1,   -1,  257,  258,  259,  260,  261,
  271,  272,  273,  274,  275,  276,  277,  278,   -1,  280,
   -1,  282,  283,  284,  285,  286,  257,  258,  259,  260,
  261,  283,  284,  285,  286,  264,  265,  266,  267,  268,
  269,  272,  273,  274,  275,   -1,  277,  257,  258,  259,
  260,  261,  283,  284,  285,  286,   -1,   -1,   -1,   -1,
   -1,   -1,  272,   -1,   -1,  275,   -1,  277,  278,   -1,
   -1,   -1,   -1,  283,  284,  285,  286,   41,   42,   43,
   -1,   45,   -1,   47,   -1,  257,  258,  259,  260,  261,
   -1,   -1,   -1,   -1,   -1,   -1,   60,   -1,   62,   -1,
  272,   -1,   -1,  275,   -1,  277,   -1,   -1,  280,   -1,
   -1,  283,  284,  285,  286,  257,  258,  259,  260,  261,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  272,   -1,   -1,  275,   -1,  277,   -1,   -1,   -1,   -1,
  282,  283,  284,  285,  286,  257,  258,  259,  260,  261,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  272,   -1,  274,  275,   -1,  277,  257,  258,  259,  260,
  261,  283,  284,  285,  286,  257,  258,  259,  260,  261,
   -1,  272,   -1,   -1,  275,  276,  277,   -1,   -1,   -1,
   -1,   -1,  283,  284,  285,  286,  257,  258,  259,  260,
  261,  283,  284,  285,  286,   -1,   -1,   -1,   -1,   -1,
   -1,  272,   -1,   -1,  275,   -1,  277,   -1,   -1,   -1,
   -1,   -1,  283,  284,  285,  286,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   15,   -1,   -1,   18,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   28,   29,
   30,   31,   32,   33,   -1,   35,   36,   37,   -1,   -1,
   40,   -1,   42,   43,   44,   45,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  264,  265,  266,  267,  268,  269,   76,   77,   78,   79,
   -1,   -1,   -1,   -1,   84,   85,   86,   87,   88,   89,
   90,   91,   92,   -1,   -1,   95,   -1,   -1,   -1,   -1,
   -1,  101,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  111,   -1,   -1,   -1,  115,   -1,   -1,   -1,  119,
   -1,  121,  122,   -1,  124,   -1,   -1,   -1,   -1,   -1,
  130,   -1,   -1,  133,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 286
#define YYUNDFTOKEN 300
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,0,"'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,
0,0,0,0,0,"'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'i'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'|'",
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,"put_","get_","door_","key_","gate_","incr","decr",
"egal","diff","infegal","supegal","et","ou","level_","end","IF","ELSE","endif",
"FOR","endfor","WHILE","endwhile","fct","endfct","prc","endprc","ENTIER",
"FUNCNAME","PROCNAME","variable",0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : LEVEL",
"LEVEL : level_ PROGRAMME end",
"LEVEL : LEVEL level_ PROGRAMME end",
"LEVEL : LEVEL PROCEDURE_DEF",
"PROGRAMME : INSTR_LIST",
"INSTR_LIST : EXPRESSION",
"INSTR_LIST : INSTR_LIST EXPRESSION",
"INSTR_LIST : CONDITION",
"INSTR_LIST : INSTR_LIST CONDITION",
"INSTR_LIST : FORLOOP",
"INSTR_LIST : INSTR_LIST FORLOOP",
"INSTR_LIST : WHILELOOP",
"INSTR_LIST : INSTR_LIST WHILELOOP",
"CONDITION : IF '(' BOOLEEN ')' INSTR_LIST ELSE INSTR_LIST endif",
"CONDITION : IF '(' BOOLEEN ')' INSTR_LIST endif",
"PROCEDURE_DEF : prc PROCNAME '(' PARAM_LIST ')' INSTR_LIST endprc",
"PROCEDURE_DEF : fct FUNCNAME '(' PARAM_LIST ')' INSTR_LIST endfct",
"PRC_CALL : PROCNAME '(' PARAM_LIST ')'",
"PRC_CALL : FUNCNAME '(' PARAM_LIST ')'",
"PARAM_LIST :",
"PARAM_LIST : EXPRESSION",
"PARAM_LIST : PARAM_LIST ',' EXPRESSION",
"FORLOOP : FOR '(' VARIABLE ',' EXPRESSION ',' EXPRESSION ',' EXPRESSION ')' INSTR_LIST endfor",
"WHILELOOP : WHILE '(' BOOLEEN ')' INSTR_LIST endwhile",
"VARIABLE : variable",
"VARIABLE : variable '=' EXPRESSION",
"EXPRESSION : VARIABLE",
"EXPRESSION : PRC_CALL",
"EXPRESSION : EXPRESSION '+' EXPRESSION",
"EXPRESSION : EXPRESSION '-' EXPRESSION",
"EXPRESSION : EXPRESSION '*' EXPRESSION",
"EXPRESSION : EXPRESSION '/' EXPRESSION",
"EXPRESSION : ENTIER",
"EXPRESSION : put_ '(' EXPRESSION ',' EXPRESSION ',' EXPRESSION ')'",
"EXPRESSION : get_ '(' EXPRESSION ',' EXPRESSION ')'",
"EXPRESSION : door_ '(' EXPRESSION ')'",
"EXPRESSION : gate_ '(' EXPRESSION ')'",
"EXPRESSION : key_ '(' EXPRESSION ')'",
"EXPRESSION : '(' EXPRESSION ')'",
"EXPRESSION : variable incr",
"EXPRESSION : variable decr",
"BOOLEEN : EXPRESSION egal EXPRESSION",
"BOOLEEN : EXPRESSION diff EXPRESSION",
"BOOLEEN : EXPRESSION '<' EXPRESSION",
"BOOLEEN : EXPRESSION '>' EXPRESSION",
"BOOLEEN : EXPRESSION infegal EXPRESSION",
"BOOLEEN : EXPRESSION supegal EXPRESSION",
"BOOLEEN : EXPRESSION et EXPRESSION",
"BOOLEEN : EXPRESSION ou EXPRESSION",
"BOOLEEN : ENTIER",
"BOOLEEN : VARIABLE",

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
#line 339 "generator.yacc.y"

#line 453 "y.tab.c"

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
#line 80 "generator.yacc.y"
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
case 2:
#line 89 "generator.yacc.y"
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
case 3:
#line 98 "generator.yacc.y"
	{
        printf("Procedure been saved\n");
    }
break;
case 4:
#line 103 "generator.yacc.y"
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
            }
break;
case 5:
#line 140 "generator.yacc.y"
	{
              yyval.tree_list = malloc(sizeof(tree_list_t));
              yyval.tree_list->tree = yystack.l_mark[0].tree;
              yyval.tree_list->next = NULL;
            }
break;
case 6:
#line 145 "generator.yacc.y"
	{
              tree_list_t *e = malloc(sizeof(tree_list_t));
              e->tree = yystack.l_mark[0].tree;
              e->next = NULL;
              tree_list_t *last = yystack.l_mark[-1].tree_list;
              while (last->next) {
                last = last->next;
              }
              last->next = e;
            }
break;
case 8:
#line 155 "generator.yacc.y"
	{
              tree_list_t *last = yystack.l_mark[-1].tree_list;
              while (last->next) {
                last = last->next;
              }
              last->next = yystack.l_mark[0].tree_list;
            }
break;
case 10:
#line 163 "generator.yacc.y"
	{
              tree_list_t *last = yystack.l_mark[-1].tree_list;
              while (last->next) {
                last = last->next;
              }
              last->next = yystack.l_mark[0].tree_list;
              }
break;
case 12:
#line 171 "generator.yacc.y"
	{
              tree_list_t *last = yystack.l_mark[-1].tree_list;
              while (last->next) {
                last = last->next;
              }
              last->next = yystack.l_mark[0].tree_list;
            }
break;
case 13:
#line 180 "generator.yacc.y"
	{
              int booleen = calculate_tree(yystack.l_mark[-5].tree);
              if(booleen== 1){
                  yyval.tree_list = yystack.l_mark[-3].tree_list;
              }else{
                  yyval.tree_list = yystack.l_mark[-1].tree_list;
              }
              }
break;
case 14:
#line 188 "generator.yacc.y"
	{
                int booleen = calculate_tree(yystack.l_mark[-3].tree);
                  if(booleen== 1){
                      yyval.tree_list = yystack.l_mark[-1].tree_list;
                  }else{
                      yyval.tree_list = NULL;
                  }
              }
break;
case 15:
#line 198 "generator.yacc.y"
	{
                function_t *new_func = malloc(sizeof(function_t));
                new_func->name = yystack.l_mark[-5].str;
                new_func->params = yystack.l_mark[-3].tree_list;
                new_func->instructions = yystack.l_mark[-1].tree_list;
                new_func->next = function_list;
                function_list = new_func;
            }
break;
case 16:
#line 205 "generator.yacc.y"
	{
                function_t *new_func = malloc(sizeof(function_t));
                new_func->name = yystack.l_mark[-5].str;
                new_func->params = yystack.l_mark[-3].tree_list;
                new_func->instructions = yystack.l_mark[-1].tree_list;
                new_func->next = function_list;
                function_list = new_func;
            }
break;
case 17:
#line 214 "generator.yacc.y"
	{
                yyval.tree = create_tree_prc_call(yystack.l_mark[-3].str, yystack.l_mark[-1].tree_list);
            }
break;
case 18:
#line 216 "generator.yacc.y"
	{
                yyval.tree = create_tree_func_call(yystack.l_mark[-3].str, yystack.l_mark[-1].tree_list);
            }
break;
case 19:
#line 220 "generator.yacc.y"
	{
                yyval.tree_list = NULL;
            }
break;
case 20:
#line 223 "generator.yacc.y"
	{
                yyval.tree_list = malloc(sizeof(tree_list_t));
                yyval.tree_list->tree = yystack.l_mark[0].tree;
                yyval.tree_list->next = NULL;
            }
break;
case 21:
#line 228 "generator.yacc.y"
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
case 22:
#line 240 "generator.yacc.y"
	{
                  yyval.tree_list = execute_for(yystack.l_mark[-9].tree->name,calculate_tree(yystack.l_mark[-7].tree),calculate_tree(yystack.l_mark[-5].tree),calculate_tree(yystack.l_mark[-3].tree),yystack.l_mark[-1].tree_list);
              }
break;
case 23:
#line 244 "generator.yacc.y"
	{
                yyval.tree_list = execute_while(yystack.l_mark[-3].tree,yystack.l_mark[-1].tree_list);
              }
break;
case 24:
#line 249 "generator.yacc.y"
	{
              yyval.tree = create_tree_var('i',print_var(yystack.l_mark[0].str),NULL,0,yystack.l_mark[0].str);
            }
break;
case 25:
#line 253 "generator.yacc.y"
	{
              crt_or_upd_symbol(TYPE_ENTIER,yystack.l_mark[-2].str,calculate_tree(yystack.l_mark[0].tree));
              yyval.tree = create_tree_var('i',calculate_tree(yystack.l_mark[0].tree),NULL,0,yystack.l_mark[-2].str);
              }
break;
case 28:
#line 260 "generator.yacc.y"
	{ 
              yyval.tree = create_tree('+',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),0);
              }
break;
case 29:
#line 263 "generator.yacc.y"
	{ 
              yyval.tree = create_tree('-',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),0);
              }
break;
case 30:
#line 266 "generator.yacc.y"
	{
               yyval.tree = create_tree('*',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),0);
               }
break;
case 31:
#line 269 "generator.yacc.y"
	{
              if(yystack.l_mark[0].tree != 0){
                yyval.tree = create_tree('/',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),0);
                }
              }
break;
case 32:
#line 274 "generator.yacc.y"
	{ 
              yyval.tree = create_tree('i',yystack.l_mark[0].entier,NULL,0);
              }
break;
case 33:
#line 277 "generator.yacc.y"
	{
              yyval.tree =create_tree('P',0,create_tree_list(yystack.l_mark[-5].tree,create_tree_list(yystack.l_mark[-3].tree,create_tree_list(yystack.l_mark[-1].tree,NULL))),0); 
              }
break;
case 34:
#line 280 "generator.yacc.y"
	{
              yyval.tree = create_tree('G',0,create_tree_list(yystack.l_mark[-3].tree,create_tree_list(yystack.l_mark[-1].tree,NULL)),0);
              }
break;
case 35:
#line 283 "generator.yacc.y"
	{
              yyval.tree = create_tree('i',door(calculate_tree(yystack.l_mark[-1].tree)),NULL,0);
              }
break;
case 36:
#line 286 "generator.yacc.y"
	{
              yyval.tree = create_tree('i',gate(calculate_tree(yystack.l_mark[-1].tree)),NULL,0);
              }
break;
case 37:
#line 289 "generator.yacc.y"
	{
               yyval.tree = create_tree('i',key(calculate_tree(yystack.l_mark[-1].tree)),NULL,0); 
               }
break;
case 38:
#line 292 "generator.yacc.y"
	{
              yyval.tree = create_tree('i',calculate_tree(yystack.l_mark[-1].tree),NULL,0); 
              }
break;
case 39:
#line 295 "generator.yacc.y"
	{
              yyval.tree = create_tree('i',incr_var(yystack.l_mark[-1].str),NULL,0);
              }
break;
case 40:
#line 298 "generator.yacc.y"
	{
              yyval.tree = create_tree('i',decr_var(yystack.l_mark[-1].str),NULL,0);
              }
break;
case 41:
#line 304 "generator.yacc.y"
	{ 
              yyval.tree = create_tree('=',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
            }
break;
case 42:
#line 307 "generator.yacc.y"
	{ 
              yyval.tree = create_tree('!',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
            }
break;
case 43:
#line 310 "generator.yacc.y"
	{ 
              yyval.tree = create_tree('<',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
            }
break;
case 44:
#line 313 "generator.yacc.y"
	{ 
              yyval.tree = create_tree('>',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
            }
break;
case 45:
#line 316 "generator.yacc.y"
	{ 
              yyval.tree = create_tree('I',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
            }
break;
case 46:
#line 319 "generator.yacc.y"
	{
              yyval.tree = create_tree('S',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
            }
break;
case 47:
#line 322 "generator.yacc.y"
	{ 
              yyval.tree = create_tree('&',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
            }
break;
case 48:
#line 325 "generator.yacc.y"
	{ 
              yyval.tree = create_tree('|',0,create_tree_list(yystack.l_mark[-2].tree,create_tree_list(yystack.l_mark[0].tree,NULL)),1);
            }
break;
case 49:
#line 328 "generator.yacc.y"
	{
              if(ENTIER==0){
                yyval.tree = create_tree('i',0,NULL,1);
             }else{
                yyval.tree = create_tree('i',1,NULL,1);
             }
             }
break;
#line 1020 "y.tab.c"
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
