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
