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
