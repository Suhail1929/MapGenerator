#define ENTIER 257
#define VARIABLE 258
#define POW 259
#define FACT 260
#define INCREMENT 261
#define DECREMENT 262
#define QUIT 263
#define EGAL 264
#define DIFFERENT 265
#define INFEGAL 266
#define SUPEGAL 267
#define ET 268
#define OU 269
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
extern YYSTYPE yylval;
