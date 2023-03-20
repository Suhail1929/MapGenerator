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
extern YYSTYPE yylval;
