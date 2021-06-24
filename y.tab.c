
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <ctype.h>

  #define ANSI_COLOR_RED		"\e[1;31m"
  #define ANSI_COLOR_GREEN	"\e[1;32m"
  #define ANSI_COLOR_CYAN		"\e[1;36m"
  #define ANSI_COLOR_RESET	"\x1b[0m"

  int yylex();
  void yyerror(char *);
  typedef struct Abstract_syntax_tree
  {
  	char *name;
      char *type;
      int isConstant ;
  	struct Abstract_syntax_tree *left;
  	struct Abstract_syntax_tree *right;
      char *var; 
  }node; 
  
  node* buildTree(char *,node *,node *);
  node* buildTree2(char *,node *,node * , char * , int);
  char * getType(char * token);
  void insert_line_ST(node * n );
  void printTree(node *);
  void print2DUtil( node *root, int space) ;

  #define COUNT 10 
  #define YYSTYPE char*
  int count = 0;


/* Line 189 of yacc.c  */
#line 109 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     NUM = 259,
     WHILE = 260,
     INT = 261,
     CHAR = 262,
     FLOAT = 263,
     VOID = 264,
     MAINOP = 265,
     AUTO = 266,
     DO = 267,
     RETURN = 268,
     BREAK = 269,
     CONTINUE = 270,
     IF = 271,
     ELSE = 272,
     COUT = 273,
     STRING = 274,
     FOR = 275,
     ENDL = 276,
     CIN = 277,
     STRING_C = 278,
     CHAR_C = 279,
     FLOAT_C = 280,
     T_inc = 281,
     T_dec = 282,
     T_ls = 283,
     T_le = 284,
     T_l = 285,
     T_ge = 286,
     T_g = 287,
     T_ee = 288,
     T_ne = 289,
     T_aa = 290,
     T_oo = 291,
     T_x = 292,
     T_me = 293,
     T_de = 294,
     T_re = 295,
     T_pe = 296,
     T_se = 297,
     T_lse = 298,
     T_rse = 299,
     T_ae = 300,
     T_xe = 301,
     T_oe = 302,
     T_a = 303,
     T_n = 304,
     T_s = 305,
     T_p = 306,
     T_m = 307,
     T_d = 308,
     T_r = 309,
     T_o = 310,
     T_e = 311,
     lcm = 312,
     gcd = 313,
     pow = 314,
     per = 315,
     fact = 316
   };
#endif
/* Tokens.  */
#define ID 258
#define NUM 259
#define WHILE 260
#define INT 261
#define CHAR 262
#define FLOAT 263
#define VOID 264
#define MAINOP 265
#define AUTO 266
#define DO 267
#define RETURN 268
#define BREAK 269
#define CONTINUE 270
#define IF 271
#define ELSE 272
#define COUT 273
#define STRING 274
#define FOR 275
#define ENDL 276
#define CIN 277
#define STRING_C 278
#define CHAR_C 279
#define FLOAT_C 280
#define T_inc 281
#define T_dec 282
#define T_ls 283
#define T_le 284
#define T_l 285
#define T_ge 286
#define T_g 287
#define T_ee 288
#define T_ne 289
#define T_aa 290
#define T_oo 291
#define T_x 292
#define T_me 293
#define T_de 294
#define T_re 295
#define T_pe 296
#define T_se 297
#define T_lse 298
#define T_rse 299
#define T_ae 300
#define T_xe 301
#define T_oe 302
#define T_a 303
#define T_n 304
#define T_s 305
#define T_p 306
#define T_m 307
#define T_d 308
#define T_r 309
#define T_o 310
#define T_e 311
#define lcm 312
#define gcd 313
#define pow 314
#define per 315
#define fact 316




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 273 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   322

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  164

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    68,     2,     2,     2,     2,     2,     2,     2,
      65,    66,     2,     2,    67,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    64,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    62,     2,    63,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    11,    15,    19,    23,    26,
      29,    31,    34,    36,    37,    38,    46,    47,    48,    49,
      62,    63,    64,    78,    80,    81,    86,    87,    92,    93,
     100,   104,   106,   109,   111,   115,   118,   121,   123,   126,
     128,   130,   132,   134,   138,   140,   148,   155,   160,   164,
     169,   172,   176,   181,   183,   187,   191,   194,   196,   200,
     204,   208,   211,   215,   217,   221,   225,   227,   231,   235,
     237,   241,   245,   249,   255,   257,   259,   261,   263,   265,
     267,   269,   271,   273,   275,   277,   279,   281,   283,   285,
     287,   289,   291
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      70,     0,    -1,    71,    -1,    72,    -1,     9,    10,    73,
      -1,     6,    10,    73,    -1,    62,    74,    63,    -1,    74,
      90,    64,    -1,    90,    64,    -1,    74,    75,    -1,    75,
      -1,    74,    83,    -1,    83,    -1,    -1,    -1,     5,    65,
      76,    91,    66,    77,    88,    -1,    -1,    -1,    -1,    20,
      65,    92,    78,    64,    91,    79,    64,    90,    80,    66,
      88,    -1,    -1,    -1,    20,    65,    98,    67,    98,    81,
      67,    93,    82,    67,    93,    66,    88,    -1,    86,    -1,
      -1,    83,    17,    84,    86,    -1,    -1,    83,    17,    85,
      88,    -1,    -1,    16,    65,    91,    66,    87,    88,    -1,
      62,    89,    63,    -1,    64,    -1,    90,    64,    -1,    68,
      -1,    89,    90,    64,    -1,    89,    75,    -1,    90,    64,
      -1,    75,    -1,    89,    83,    -1,    83,    -1,    92,    -1,
      93,    -1,    97,    -1,    98,   100,    98,    -1,    98,    -1,
      98,   100,    98,   101,    98,   100,    98,    -1,   103,    65,
      98,   100,    98,    66,    -1,   103,    98,   100,    98,    -1,
      98,   101,    98,    -1,   103,    65,    98,    66,    -1,   103,
      98,    -1,    98,    56,    93,    -1,    99,    98,    56,    93,
      -1,    94,    -1,    93,    30,    93,    -1,    93,    32,    93,
      -1,    98,   102,    -1,    23,    -1,    93,    60,    93,    -1,
      93,    58,    93,    -1,    93,    57,    93,    -1,    93,    61,
      -1,    93,    59,    93,    -1,    95,    -1,    93,    51,    95,
      -1,    93,    50,    95,    -1,    96,    -1,    95,    52,    96,
      -1,    95,    53,    96,    -1,    98,    -1,    65,    93,    66,
      -1,    18,    28,    23,    -1,    18,    28,    98,    -1,    18,
      28,    23,    28,    21,    -1,     3,    -1,     4,    -1,    25,
      -1,    24,    -1,     6,    -1,     7,    -1,     8,    -1,    19,
      -1,    30,    -1,    32,    -1,    29,    -1,    31,    -1,    34,
      -1,    33,    -1,    35,    -1,    36,    -1,    26,    -1,    27,
      -1,    49,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    47,    47,    51,    55,    56,    60,    64,    65,    66,
      67,    68,    69,    74,    74,    74,    75,    75,    75,    75,
      76,    76,    76,    79,    80,    80,    81,    81,    84,    84,
      88,    89,    90,    91,    96,    97,    98,    99,   100,   101,
     106,   107,   108,   112,   113,   114,   115,   116,   117,   118,
     119,   123,   124,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   141,   142,   143,   147,   148,   149,   153,
     154,   158,   159,   160,   163,   164,   165,   166,   170,   171,
     172,   173,   176,   177,   178,   179,   180,   181,   184,   185,
     189,   190,   194
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "WHILE", "INT", "CHAR",
  "FLOAT", "VOID", "MAINOP", "AUTO", "DO", "RETURN", "BREAK", "CONTINUE",
  "IF", "ELSE", "COUT", "STRING", "FOR", "ENDL", "CIN", "STRING_C",
  "CHAR_C", "FLOAT_C", "T_inc", "T_dec", "T_ls", "T_le", "T_l", "T_ge",
  "T_g", "T_ee", "T_ne", "T_aa", "T_oo", "T_x", "T_me", "T_de", "T_re",
  "T_pe", "T_se", "T_lse", "T_rse", "T_ae", "T_xe", "T_oe", "T_a", "T_n",
  "T_s", "T_p", "T_m", "T_d", "T_r", "T_o", "T_e", "lcm", "gcd", "pow",
  "per", "fact", "'{'", "'}'", "';'", "'('", "')'", "','", "' '",
  "$accept", "S", "START", "MAIN", "BODY", "C", "LOOPS", "$@1", "$@2",
  "$@3", "$@4", "$@5", "$@6", "$@7", "ELF", "$@8", "$@9", "EFCHILD",
  "$@10", "LOOPBODY", "LOOPC", "statement", "COND", "ASSIGN_EXPR", "EXP",
  "ADDSUB", "TERM", "FACTOR", "PRINT", "LIT", "TYPE", "RELOP",
  "bin_boolop", "un_arop", "un_boolop", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   123,   125,    59,    40,    41,    44,    32
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    72,    72,    73,    74,    74,    74,
      74,    74,    74,    76,    77,    75,    78,    79,    80,    75,
      81,    82,    75,    83,    84,    83,    85,    83,    87,    86,
      88,    88,    88,    88,    89,    89,    89,    89,    89,    89,
      90,    90,    90,    91,    91,    91,    91,    91,    91,    91,
      91,    92,    92,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    94,    94,    94,    95,    95,    95,    96,
      96,    97,    97,    97,    98,    98,    98,    98,    99,    99,
      99,    99,   100,   100,   100,   100,   100,   100,   101,   101,
     102,   102,   103
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     3,     3,     3,     2,     2,
       1,     2,     1,     0,     0,     7,     0,     0,     0,    12,
       0,     0,    13,     1,     0,     4,     0,     4,     0,     6,
       3,     1,     2,     1,     3,     2,     2,     1,     2,     1,
       1,     1,     1,     3,     1,     7,     6,     4,     3,     4,
       2,     3,     4,     1,     3,     3,     2,     1,     3,     3,
       3,     2,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     3,     0,     0,     1,     0,
       5,     4,    74,    75,     0,    78,    79,    80,     0,     0,
      81,     0,    57,    77,    76,     0,     0,    10,    12,    23,
       0,    40,    41,    53,    63,    66,    42,    69,     0,    13,
       0,     0,     0,     0,    69,     6,     9,    11,     0,    26,
       8,     0,     0,     0,     0,     0,     0,     0,     0,    61,
       0,     0,    90,    91,     0,    56,     0,     0,    92,     0,
      44,     0,    71,    72,    16,     0,    70,     7,     0,     0,
      54,    55,    65,    69,    64,    60,    59,    62,    58,    67,
      68,    51,     0,     0,    28,    84,    82,    85,    83,    87,
      86,    88,    89,     0,     0,     0,    50,     0,     0,     0,
      25,     0,    31,    33,    27,     0,    52,    14,     0,    43,
      48,     0,     0,    73,     0,    20,    37,    39,     0,     0,
      32,     0,    29,     0,    49,     0,    47,    17,     0,    30,
      35,    38,     0,    36,    15,     0,     0,     0,     0,    34,
       0,    46,     0,    21,    45,    18,     0,     0,     0,     0,
       0,    19,     0,    22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    10,    26,    27,    67,   131,   108,
     147,   157,   138,   156,    28,    78,    79,    29,   118,   114,
     128,   115,    69,    31,    32,    33,    34,    35,    36,    44,
      38,   103,   104,    65,    71
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -113
static const yytype_int16 yypact[] =
{
       2,     0,    20,    12,  -113,  -113,   -47,   -47,  -113,   222,
    -113,  -113,  -113,  -113,   -31,  -113,  -113,  -113,     4,    21,
    -113,     8,  -113,  -113,  -113,    68,   171,  -113,    40,  -113,
       1,  -113,   253,  -113,   -32,  -113,  -113,   -13,    86,  -113,
      50,   113,   248,   218,    11,  -113,  -113,    40,    13,    66,
    -113,    68,    68,    56,    56,    68,    68,    68,    68,  -113,
      56,    56,  -113,  -113,    68,  -113,    30,    50,  -113,    35,
     286,   103,    80,  -113,  -113,   -51,  -113,  -113,    96,   148,
       5,     5,   -32,  -113,   -32,     5,     5,     5,     5,  -113,
    -113,   253,    68,    48,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,    86,    86,    86,    -6,    97,    59,    86,
    -113,   222,  -113,  -113,  -113,    67,   253,  -113,   148,    62,
    -113,   131,    86,  -113,    50,  -113,  -113,    40,   199,    75,
    -113,   148,  -113,    86,  -113,    86,  -113,  -113,    73,  -113,
    -113,    40,    81,  -113,  -113,    -6,    82,    83,    68,  -113,
      86,  -113,    60,   253,  -113,  -113,    79,    91,    68,   148,
     231,  -113,   148,  -113
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -113,  -113,  -113,  -113,   142,  -113,   -24,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,   -23,  -113,  -113,    92,  -113,  -112,
    -113,    -8,   -63,   116,   -16,  -113,    76,    74,  -113,    -9,
    -113,   -99,    61,  -113,  -113
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -25
static const yytype_int16 yytable[] =
{
      37,    30,    46,    47,    93,    64,   132,   122,     1,    43,
       6,     2,     8,    62,    63,     9,   109,    37,    48,   144,
      60,    61,   135,    95,    96,    97,    98,    99,   100,    66,
       7,    70,    73,    75,    39,    80,    81,    62,    63,    85,
      86,    87,    88,    64,    83,    83,   150,   161,    91,    41,
     163,    83,    83,    12,    13,    53,    54,    49,    70,    12,
      13,   137,   106,    12,    13,    50,    15,    16,    17,    40,
      37,    12,    13,    42,    23,    24,   116,    77,    19,    20,
      23,    24,   -24,    22,    23,    24,    92,   126,   127,    12,
      13,    22,    23,    24,   119,   120,   121,   101,   102,    68,
     125,    94,    37,   129,   140,   141,    12,    13,   107,    37,
      23,    24,    18,   136,   117,    70,    12,    13,   123,    37,
     142,    25,    37,   124,   145,    25,   146,    23,    24,    82,
      84,   130,   153,    25,    89,    90,    72,    23,    24,   143,
     148,   154,   160,    37,   155,   149,   158,   152,   151,    11,
      37,    12,    13,    37,    15,    16,    17,   159,    74,     0,
      95,    96,    97,    98,    99,   100,    19,    20,   105,     0,
     110,    22,    23,    24,    12,    13,    14,    15,    16,    17,
     133,     0,     0,     0,     0,     0,     0,    18,     0,    19,
      20,    21,     0,     0,    22,    23,    24,   134,     0,     0,
       0,     0,    12,    13,    14,    15,    16,    17,     0,     0,
     111,     0,   112,    25,     0,    18,   113,    19,    20,    21,
       0,     0,    22,    23,    24,    12,    13,    14,    15,    16,
      17,     0,     0,     0,    45,     0,    25,     0,    18,     0,
      19,    20,    21,     0,     0,    22,    23,    24,    51,     0,
      52,    12,    13,     0,    15,    16,    17,     0,     0,     0,
       0,    51,   139,    52,    25,     0,     0,    20,    53,    54,
       0,     0,    23,    24,     0,    55,    56,    57,    58,    59,
       0,    53,    54,    51,    76,    52,     0,    25,    55,    56,
      57,    58,    59,     0,     0,     0,     0,   162,     0,     0,
       0,     0,     0,    53,    54,     0,     0,     0,     0,     0,
      55,    56,    57,    58,    59,    95,    96,    97,    98,    99,
     100,   101,   102
};

static const yytype_int16 yycheck[] =
{
       9,     9,    26,    26,    67,    56,   118,   106,     6,    25,
      10,     9,     0,    26,    27,    62,    67,    26,    26,   131,
      52,    53,   121,    29,    30,    31,    32,    33,    34,    38,
      10,    40,    41,    42,    65,    51,    52,    26,    27,    55,
      56,    57,    58,    56,    53,    54,   145,   159,    64,    28,
     162,    60,    61,     3,     4,    50,    51,    17,    67,     3,
       4,   124,    71,     3,     4,    64,     6,     7,     8,    65,
      79,     3,     4,    65,    24,    25,    92,    64,    18,    19,
      24,    25,    16,    23,    24,    25,    56,   111,   111,     3,
       4,    23,    24,    25,   103,   104,   105,    35,    36,    49,
     109,    66,   111,   111,   128,   128,     3,     4,    28,   118,
      24,    25,    16,   122,    66,   124,     3,     4,    21,   128,
     128,    65,   131,    64,   133,    65,   135,    24,    25,    53,
      54,    64,   148,    65,    60,    61,    23,    24,    25,    64,
      67,   150,   158,   152,   152,    64,    67,    64,    66,     7,
     159,     3,     4,   162,     6,     7,     8,    66,    42,    -1,
      29,    30,    31,    32,    33,    34,    18,    19,    65,    -1,
      78,    23,    24,    25,     3,     4,     5,     6,     7,     8,
     119,    -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,    18,
      19,    20,    -1,    -1,    23,    24,    25,    66,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    -1,
      62,    -1,    64,    65,    -1,    16,    68,    18,    19,    20,
      -1,    -1,    23,    24,    25,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    63,    -1,    65,    -1,    16,    -1,
      18,    19,    20,    -1,    -1,    23,    24,    25,    30,    -1,
      32,     3,     4,    -1,     6,     7,     8,    -1,    -1,    -1,
      -1,    30,    63,    32,    65,    -1,    -1,    19,    50,    51,
      -1,    -1,    24,    25,    -1,    57,    58,    59,    60,    61,
      -1,    50,    51,    30,    66,    32,    -1,    65,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    61,    29,    30,    31,    32,    33,
      34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     9,    70,    71,    72,    10,    10,     0,    62,
      73,    73,     3,     4,     5,     6,     7,     8,    16,    18,
      19,    20,    23,    24,    25,    65,    74,    75,    83,    86,
      90,    92,    93,    94,    95,    96,    97,    98,    99,    65,
      65,    28,    65,    93,    98,    63,    75,    83,    90,    17,
      64,    30,    32,    50,    51,    57,    58,    59,    60,    61,
      52,    53,    26,    27,    56,   102,    98,    76,    49,    91,
      98,   103,    23,    98,    92,    98,    66,    64,    84,    85,
      93,    93,    95,    98,    95,    93,    93,    93,    93,    96,
      96,    93,    56,    91,    66,    29,    30,    31,    32,    33,
      34,    35,    36,   100,   101,    65,    98,    28,    78,    67,
      86,    62,    64,    68,    88,    90,    93,    66,    87,    98,
      98,    98,   100,    21,    64,    98,    75,    83,    89,    90,
      64,    77,    88,   101,    66,   100,    98,    91,    81,    63,
      75,    83,    90,    64,    88,    98,    98,    79,    67,    64,
     100,    66,    64,    93,    98,    90,    82,    80,    67,    66,
      93,    88,    66,    88
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 7:

/* Line 1455 of yacc.c  */
#line 64 "parser.y"
    {printTree((node*)(yyvsp[(2) - (3)]));}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 65 "parser.y"
    {printTree((yyvsp[(1) - (2)]));}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 66 "parser.y"
    {printTree((yyvsp[(2) - (2)]));}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 67 "parser.y"
    {printTree((yyvsp[(1) - (1)]));}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 68 "parser.y"
    {if_else4();printTree((yyvsp[(2) - (2)]));}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 69 "parser.y"
    {printTree((yyvsp[(1) - (1)]));}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 74 "parser.y"
    {while1();}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 74 "parser.y"
    {while2((yyvsp[(4) - (5)]));}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 74 "parser.y"
    {(yyval)=buildTree("WHILE",(yyvsp[(4) - (7)]),(yyvsp[(7) - (7)]));while3();}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 75 "parser.y"
    {for1();}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 75 "parser.y"
    {for2((yyvsp[(6) - (6)]));}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 75 "parser.y"
    {for4();}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 75 "parser.y"
    {(yyval)=buildTree("FOR",(yyvsp[(6) - (12)]),(yyvsp[(12) - (12)])); for3();}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 76 "parser.y"
    { for_new1((yyvsp[(3) - (5)]) , (yyvsp[(5) - (5)]));}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 76 "parser.y"
    {for_new2((yyvsp[(3) - (8)]), (yyvsp[(8) - (8)]));}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 76 "parser.y"
    {(yyval)=buildTree("FOR",(yyvsp[(7) - (13)]),(yyvsp[(10) - (13)])); for_new3((yyvsp[(3) - (13)]) ,(yyvsp[(11) - (13)])); forhelp3();}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 79 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 80 "parser.y"
    {if_else0();}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 80 "parser.y"
    { (yyval) = buildTree( "ELSE IF SEQ" , (yyvsp[(1) - (4)]) , (yyvsp[(4) - (4)]) );}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 81 "parser.y"
    {if_else0();}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 81 "parser.y"
    { (yyval) = buildTree( "ELSE SEQ" , (yyvsp[(1) - (4)]) ,buildTree("ELSE",NULL,(yyvsp[(4) - (4)]))  ); if_else2();}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 84 "parser.y"
    {if_else1((yyvsp[(3) - (4)]));}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 84 "parser.y"
    { (yyval) =  buildTree("IF",(yyvsp[(3) - (6)]),(yyvsp[(6) - (6)]));if_else2();}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 88 "parser.y"
    {(yyval)=(yyvsp[(2) - (3)]);}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 96 "parser.y"
    {(yyval)=buildTree("SEQ",(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]));}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 97 "parser.y"
    {(yyval)=buildTree("SEQ",(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    {(yyval)=(yyvsp[(1) - (2)]);}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 99 "parser.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 100 "parser.y"
    {if_else4();printTree((yyvsp[(2) - (2)]));}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 101 "parser.y"
    {if_else4();printTree((yyvsp[(1) - (1)]));}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 106 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    {(yyval)=buildTree("Print",NULL,NULL);}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 112 "parser.y"
    {search_id((yyvsp[(1) - (3)])  , 0);  search_id((yyvsp[(3) - (3)])  , 0);(yyval)=buildTree((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); codegen((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yyvsp[(2) - (3)]));}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 114 "parser.y"
    {  search_id((yyvsp[(1) - (7)])  , 0);  search_id((yyvsp[(3) - (7)])  , 0);  search_id((yyvsp[(5) - (7)])  , 0);  search_id((yyvsp[(7) - (7)])  , 0); (yyval)=buildTree((yyvsp[(4) - (7)]), buildTree((yyvsp[(2) - (7)]),(yyvsp[(1) - (7)]),(yyvsp[(3) - (7)])) , buildTree((yyvsp[(6) - (7)]),(yyvsp[(5) - (7)]),(yyvsp[(7) - (7)])));}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    {search_id((yyvsp[(1) - (3)])  , 0); check_Type((yyvsp[(1) - (3)]) , (yyvsp[(3) - (3)])); insert_line_ST((yyvsp[(1) - (3)])); add_value((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); (yyval)=buildTree("=",(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));codegen_assign((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 124 "parser.y"
    {search_id((yyvsp[(2) - (4)])  , 1); insert_type_ST((yyvsp[(2) - (4)]) , (yyvsp[(1) - (4)]));  insert_line_ST((yyvsp[(2) - (4)])); check_Type( (yyvsp[(2) - (4)]) , (yyvsp[(4) - (4)])); add_value((yyvsp[(2) - (4)]),(yyvsp[(4) - (4)])); (yyval)=buildTree("=",(yyvsp[(2) - (4)]),(yyvsp[(4) - (4)]));codegen_assign((yyval),(yyvsp[(2) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    { (yyval)=buildTree((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); codegen((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yyvsp[(2) - (3)]));}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    {(yyval)=buildTree((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));codegen((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yyvsp[(2) - (3)]));}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    { search_id((yyvsp[(1) - (2)])  , 0);  insert_line_ST((yyvsp[(1) - (2)])); (yyval) = buildTree((yyvsp[(2) - (2)]),(yyvsp[(1) - (2)]),buildTree("1",0,0));codegen((yyval),(yyvsp[(1) - (2)]),buildTree2("1",0,0 ,"INT" ,1),(yyvsp[(2) - (2)]));codegen_assign((yyval),(yyvsp[(1) - (2)]),(yyval));}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 132 "parser.y"
    { (yyval) = buildTree2((char *)yylval,0,0 , (char *)"STRING",1);}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 133 "parser.y"
    {search_id((yyvsp[(1) - (3)]),0);search_id((yyvsp[(3) - (3)]),0); (yyval) = buildTree("per" , (yyvsp[(1) - (3)]) , (yyvsp[(3) - (3)])); codegen_per((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yyvsp[(2) - (3)]));}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 134 "parser.y"
    {search_id((yyvsp[(1) - (3)]),0);search_id((yyvsp[(3) - (3)]),0); (yyval) = buildTree("gcd" , (yyvsp[(1) - (3)]) , (yyvsp[(3) - (3)])); codegen_gcd((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yyvsp[(2) - (3)]));}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    {search_id((yyvsp[(1) - (3)]),0);search_id((yyvsp[(3) - (3)]),0); (yyval) = buildTree("lcm" , (yyvsp[(1) - (3)]) , (yyvsp[(3) - (3)])); codegen_lcm((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yyvsp[(2) - (3)]));}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 136 "parser.y"
    {search_id((yyvsp[(1) - (2)]),0); (yyval) = buildTree("fact" , (yyvsp[(1) - (2)]) , NULL); codegen_fact((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 137 "parser.y"
    {search_id((yyvsp[(1) - (3)]),0);search_id((yyvsp[(3) - (3)]),0); (yyval) = buildTree("pow" , (yyvsp[(1) - (3)]) , (yyvsp[(3) - (3)])); codegen_pow((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yyvsp[(2) - (3)]));}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    {search_id((yyvsp[(1) - (3)]),0);search_id((yyvsp[(3) - (3)]),0);check_Type((yyvsp[(1) - (3)]) , (yyvsp[(3) - (3)])); (yyval)=buildTree((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));codegen((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),"+");}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    {search_id((yyvsp[(1) - (3)]),0);search_id((yyvsp[(3) - (3)]),0);check_Type((yyvsp[(1) - (3)]) , (yyvsp[(3) - (3)])); (yyval)=buildTree((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));codegen((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),"-");}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    {(yyval)=(yyvsp[(1) - (1)]); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 148 "parser.y"
    {search_id((yyvsp[(1) - (3)]),0);search_id((yyvsp[(3) - (3)]),0); check_Type((yyvsp[(1) - (3)]) , (yyvsp[(3) - (3)]));  (yyval)=buildTree((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]) );codegen((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),"*");}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 149 "parser.y"
    {search_id((yyvsp[(1) - (3)]),0);search_id((yyvsp[(3) - (3)]),0); check_Type((yyvsp[(1) - (3)]) , (yyvsp[(3) - (3)]));  (yyval)=buildTree((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));codegen((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),"/");}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]);}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    {  (yyval) = buildTree2((char *)yylval,0,0 , getType((yyvsp[(1) - (1)]))  , 0); }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    { (yyval) = buildTree2((char *)yylval,0,0 , (char *)"INT" ,1);}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    { (yyval) = buildTree2((char *)yylval,0,0 , (char *)"FLOAT",1);}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    { (yyval) = buildTree2((char *)yylval,0,0 , (char *)"CHAR",1); }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 170 "parser.y"
    {(yyval)="INT";}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    {(yyval)="CHAR";}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 172 "parser.y"
    {(yyval)="FLOAT";}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    { (yyval) = "STRING";}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 176 "parser.y"
    { (yyval) = "<";}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 177 "parser.y"
    {  (yyval) =">" ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 178 "parser.y"
    { (yyval) ="<=";}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    {  (yyval) =">="; }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 180 "parser.y"
    {  (yyval) ="!=" ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    {  (yyval) ="==";}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 184 "parser.y"
    {  (yyval) ="&&";}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 185 "parser.y"
    {  (yyval) ="||";}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    { (yyval) = "+";}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 190 "parser.y"
    { (yyval) = "-";}
    break;



/* Line 1455 of yacc.c  */
#line 2174 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 198 "parser.y"


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
extern FILE *yyin;
extern int yylineno;
extern char *yytext;
void printST();
extern struct SymbolTable{
        char name[20];
        char class[20];
        char type[20];
        char value[100];
        int line;
        int var_size;
    }ST[1001];
int x = 0;
FILE *myfile;
int main(int argc,char *argv[])
{
  yyin = fopen(argv[1], "r");
  char * str = argv[1];
  char name[100] = "./icg/icg";
  name[9] = str[10];
  name[10] = '\0';
  char * filet = ".txt";
  strcat(name,filet);
  myfile=fopen(name,"w");
  yylineno=1;
  /*
  node *root,*temp;
  root = (node*)malloc(sizeof(node));
  temp = (node*)malloc(sizeof(node));
  */
  if(!yyparse())  //yyparse-> 0 if success
  {
    printf(ANSI_COLOR_CYAN "\n********************************************************************** \n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "                               Parsing Complete\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_CYAN "\n********************************************************************** \n\n" ANSI_COLOR_RESET);
  }
  else
  {
    printf(ANSI_COLOR_CYAN "\n********************************************************************** \n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "                                 Parsing failed\n\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_CYAN "\n********************************************************************** \n\n" ANSI_COLOR_RESET);
  }
  printST();
  fclose(myfile);
  fclose(yyin);
  return 0;
}

void printnode(char *op){
     // printf("\n\n");
     // printf("%s" , op);
     // printf("\n\n");
}

void printchild(node *n){
      
      printf("\n\n");
      printf("%s %s" , n->name , n->var);
      printf("\n\n");
}

node* buildTree2(char *op,node *left,node *right , char *type ,int isConstant)
{
	node *new = (node*)malloc(sizeof(node));
	char *newstr = (char *)malloc(sizeof(char)*100+1);
      char *var_str = (char *)malloc(sizeof(char)*100+1);
	strcpy(newstr,op);
	
      char *typestr = (char *)malloc(strlen(type)+1);
	strcpy(typestr,type);

      new->left=left;
	new->right=right;
	new->name=newstr;
      new->type = typestr;
      new->isConstant = isConstant;
      new->var = newstr;
	return (new);
}

node* buildTree(char *op,node *left,node *right )
{
	node *new = (node*)malloc(sizeof(node));
	char *newstr = (char *)malloc(strlen(op)+1);
      char *var_str = (char *)malloc(sizeof(char)*100+1);
	strcpy(newstr,op);
	
      char *typestr = (char *)malloc(4);
	strcpy(typestr," ");

      new->left=left;
	new->right=right;
	new->name=newstr;
      new->type=typestr;
      new->var = var_str;
      if(left)
      new->type = left->type;
      
	return (new);
}

void printTree2(node *tree)
{
	if(tree->left || tree->right)
	      printf("(");
	//printf(" %s ",tree->name);
	if(tree->left)
	printTree(tree->left);

      printf(" %s",tree->name);
	if(tree->right)
		printTree(tree->right);
	if(tree->left || tree->right)
		printf(")");
	
}
void yyerror(char *s)
{
	printf("%d %s %s\n", yylineno, s, yytext);
	printf(ANSI_COLOR_RED "Status: Parsing Failed - Invalid\n" ANSI_COLOR_RESET);
}
void insert_type_ST(node * n ,char * type){
      
      for(int i = 0;i<1001;i++){
            if(strcmp(ST[i].name,n->name)==0){
                  strcpy(ST[i].type , type);
                  char *typestr = (char *)malloc(sizeof(type));
                  strcpy(typestr, type);
                  n->type=typestr;

            }
      }
}

void add_value(node * n ,node * n2){
      if(n2->isConstant==0 || !(n2->name[0]>='0' && (n2->name[0]<='9'))){
            return;
      }
      for(int i = 0;i<1001;i++){
            if(strcmp(ST[i].name,n->name)==0){
                  strcpy(ST[i].value , n2->name);
            }
      }
}

void search_id(node *n , int purpose)
{
      if(n->isConstant ){
            return;
      }
      
  int flag = 0;
  for(int i = 0;i < 1001 ;i++)
  {
    if(!strcmp(ST[i].name,n->name)  && strlen(ST[i].type)>0 ) 
    {
      if(purpose == 1)
      {
            printf(ANSI_COLOR_RED "error: Redeclaration of variable %s at line %d\n" ANSI_COLOR_RESET,n->name,yylineno);
            exit(0);
      }
      flag = 1;
      return;
    }
  }

  if(flag == 0 && purpose == 0)
  {
    printf(ANSI_COLOR_RED "Error at line %d : %s is not defined\n" ANSI_COLOR_RESET,yylineno,n->name);
    exit(0);
  }
}

void check_Type(node *a , node *b){
     // printf("\n%s  -----  %s \n", a->type , b->type);
        if(!strcmp(a->type,b->type) ){
              return;
        }else{
             printf(ANSI_COLOR_RED "Error at line %d : Type mismatch\n" ANSI_COLOR_RESET,yylineno);
    exit(0);   
        } 
  
}

char * getType(char * n){
      
  for(int i = 0;i < 1001 ;i++)
  {
    if(!strcmp(ST[i].name,n)  && strlen(ST[i].type)>0 ) 
    {
          return ST[i].type;
    }
  }
  return "";    
}


void print2DUtil( node *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->right, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = 0; i < space; i++) 
        printf(" "); 
    printf("%s\n", root->name); 
  
    // Process left child 
    print2DUtil(root->left, space); 
} 
  
void printTree( node *root) 
{ 
   // Pass initial space count as 0 
  // print2DUtil(root, 10); 
} 

void insert_line_ST(node * n ){
        for(int i = 0;i<1001;i++){
            if(strcmp(ST[i].name,n->name)==0){
                ST[i].line = yylineno;
            }
        }
}

int top = 0;
int temp = 0;
int l_num = 1;
int l_num1 = 50;
int flag = 0;
int arr[100];
int idx = -1;

codegen(node * cur, node * arg1 , node *arg2 , char *op){

      char *res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t[10] = "T";  
      strcat(t,res);
      strcpy(cur->var,t);
      printf("%s = %s %s %s \n" ,t,arg1->var , op , arg2->var);
      fprintf(myfile, "%s = %s %s %s\n" ,t,arg1->var , op , arg2->var);
      temp++;     
      flag = 0;
}
codegen_assign(node * cur, node * arg1 , node * arg2){
       printf("%s = %s  \n" ,arg1->var,arg2->var );   
      fprintf(myfile,"%s = %s\n" ,arg1->var,arg2->var );   

       strcpy(cur->var , arg1->var); 
       flag = 0;
}

void tostring(char * str, int num)
{
    int i, rem, len = 0, n;
    if(num==0){
          str[0]='0';
              str[1] = '\0';

          return;
    }
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
    
}
if_else0(){
      if(flag==0)
      printf("L%d: \n", l_num); 
      fprintf(myfile, "L%d:\n", l_num); 
      l_num++;
}
if_else1(node * cond){
      printf("T%d = not %s \n",temp,cond->var);
      printf("If T%d goto L%d \n",temp,l_num); 
      fprintf(myfile,"T%d = not %s\n",temp,cond->var);
      fprintf(myfile,"If T%d goto L%d\n",temp,l_num); 
      temp++;
      flag = 0;
      //l_num++;

}

if_else2(){
      printf("goto L%d \n",l_num1);
      fprintf(myfile,"goto L%d\n",l_num1);
      flag = 0;
}

if_else4(){
      printf("L%d: \ngoto L%d \n",l_num1,l_num);
      fprintf(myfile,"L%d: \ngoto L%d\n",l_num1,l_num);
      l_num1++;
      printf("L%d:\n",l_num);
      fprintf(myfile,"L%d:\n",l_num);
      l_num++;
      flag = 1;
}

while1(){
      if(flag==0)
      {
            printf("L%d: \n", l_num); 
            fprintf(myfile,"L%d:\n", l_num); 
            l_num++;
      }
}

while2(node * cond){
      // printf("%s \n",cond->name);
      idx++;
      arr[idx] = l_num;
      printf("T%d = not %s \n",temp,cond->var);
      fprintf(myfile,"T%d = not %s\n",temp,cond->var);
      printf("If T%d goto L%d \n",temp,l_num); 
      fprintf(myfile,"If T%d goto L%d \n",temp,l_num); 
      temp++;
      l_num++;
      flag = 0;
}

while3(){
      int pop = arr[idx];
      arr[idx] = 0;
      idx--;
     // printf("goto L%d \n",l_num-1);
     // printf("L%d : \n",l_num++);
      printf("goto L%d \n",pop-1);
      printf("L%d : \n",pop);
      fprintf(myfile,"goto L%d\n",pop-1);
      fprintf(myfile,"L%d: \n",pop);
      flag = 1;
}

for1(){
      if(flag == 0){
            printf("L%d: \n", l_num);
            fprintf(myfile,"L%d: \n", l_num);
      }
      idx++;
      arr[idx++] = l_num+3;
      arr[idx++] = l_num+1;
      arr[idx++] = l_num+2;
      arr[idx] = l_num;
}

for2(node * n){
      printf("T%d = not %s \n",temp,n->var);
      printf("If T%d goto L%d \n",temp,l_num+3);
      fprintf(myfile,"T%d = not %s \n",temp,n->var);
      fprintf(myfile,"If T%d goto L%d \n",temp,l_num+3);
      temp++;
      printf("If T%d goto L%d \n",temp-2,l_num+2); 
      printf("L%d: \n",l_num+1); 
    
      fprintf(myfile,"If T%d goto L%d \n",temp-2,l_num+2); 
      fprintf(myfile,"L%d: \n",l_num+1); 
      flag = 0;
      l_num+=4;
}

for3(){
      //printf("goto L%d : \n",l_num+1);
      //printf("L%d : \n",l_num+3);

      printf("goto L%d \n",arr[idx]);
      fprintf(myfile,"goto L%d \n",arr[idx--]);
      printf("L%d: \n",arr[idx]);
      fprintf(myfile,"L%d: \n",arr[idx--]);

      flag = 1;
      
}
for4(){
      //printf("goto L%d : \n",l_num);
      //printf("L%d : \n",l_num+2);

      printf("goto L%d \n",arr[idx]);
      fprintf(myfile,"goto L%d \n",arr[idx--]);
      printf("L%d: \n",arr[idx]);
      fprintf(myfile,"L%d: \n",arr[idx--]);

}

codegen_per(node * cur, node * arg1 , node *arg2 , char *op){
      char *res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t[10] = "T";  
      strcat(t,res);
      printf("%s = %s / %s \n" ,t , arg1->var , arg2->var);
      fprintf(myfile,"%s = %s / %s \n" ,t , arg1->var , arg2->var);
      char * prev = t;
      temp++;     
      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t2[10] = "T";  
      strcat(t2,res);
      strcpy(cur->var,t2);
      printf("%s = %s * 100 \n" ,t2 , t);      
      fprintf(myfile,"%s = %s * 100 \n" ,t2 , t);      
      temp++;
}

codegen_gcd(node * cur, node * arg1 , node *arg2 , char *op){
      char *res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t1[10] = "T";  
      strcat(t1,res);
      while1();
      printf("%s = %s %s %s \n" ,t1,arg1->var , "!=" , arg2->var);
      fprintf(myfile,"%s = %s %s %s \n" ,t1,arg1->var , "!=" , arg2->var);
      temp++;
      node *new = (node*)malloc(sizeof(node));
      new->var = t1;
      while2(new);
      //l_num++;
      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t2[10] = "T";  
      strcat(t2,res);
      printf("%s = %s %s %s \n",t2,arg1->var,">",arg2->var);
      fprintf(myfile,"%s = %s %s %s \n",t2,arg1->var,">",arg2->var);
      temp++;
      new = (node*)malloc(sizeof(node));
      new->var = t2;
      if_else1(new);
      
      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t3[10] = "T";  
      strcat(t3,res);
      printf("%s = %s %s %s \n",t3,arg1->var,"-",arg2->var);
      fprintf(myfile,"%s = %s %s %s \n",t3,arg1->var,"-",arg2->var);
      temp++;
      printf("%s = %s  \n" ,arg1->var,t3 );  
      fprintf(myfile,"%s = %s  \n" ,arg1->var,t3 );  
      
      
      if_else2();
      if_else0();
      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t4[10] = "T";  
      strcat(t4,res);
      printf("%s = %s %s %s \n",t4,arg2->var,"-",arg1->var);
      fprintf(myfile,"%s = %s %s %s \n",t4,arg2->var,"-",arg1->var);
      temp++;
      printf("%s = %s  \n" ,arg2->var,t4);
      printf("L%d: \ngoto L%d \n",l_num1,l_num);
      fprintf(myfile,"%s = %s  \n" ,arg2->var,t4);
      fprintf(myfile,"L%d: \ngoto L%d \n",l_num1,l_num);
      l_num1++;
      printf("L%d:\n",l_num);
      fprintf(myfile,"L%d:\n",l_num);
      l_num++;
      flag = 1;

      printf("goto L%d \n",l_num-4);
      printf("L%d: \n",l_num-3);
      fprintf(myfile,"goto L%d \n",l_num-4);
      fprintf(myfile,"L%d: \n",l_num-3);
      flag = 0;
      strcpy(cur->var,arg1->var);

}

codegen_lcm(node * cur, node * arg1 , node *arg2 , char *op){

      char *res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t7[10] = "T";  
      strcat(t7,res);
      printf("%s = %s %s %s \n" ,t7,arg1->var , "*" , arg2->var);
      fprintf(myfile,"%s = %s %s %s \n" ,t7,arg1->var , "*" , arg2->var);
      temp++;



      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t1[10] = "T";  
      strcat(t1,res);
      while1();
      printf("%s = %s %s %s \n" ,t1,arg1->var , "!=" , arg2->var);
      fprintf(myfile,"%s = %s %s %s \n" ,t1,arg1->var , "!=" , arg2->var);
      temp++;
      node *new = (node*)malloc(sizeof(node));
      new->var = t1;
      while2(new);
      //l_num++;
      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t2[10] = "T";  
      strcat(t2,res);
      printf("%s = %s %s %s \n",t2,arg1->var,">",arg2->var);
      fprintf(myfile,"%s = %s %s %s \n",t2,arg1->var,">",arg2->var);
      temp++;
      new = (node*)malloc(sizeof(node));
      new->var = t2;
      if_else1(new);
      
      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t3[10] = "T";  
      strcat(t3,res);
      printf("%s = %s %s %s \n",t3,arg1->var,"-",arg2->var);
      fprintf(myfile,"%s = %s %s %s \n",t3,arg1->var,"-",arg2->var);
      temp++;
      printf("%s = %s  \n" ,arg1->var,t3 );  
      fprintf(myfile,"%s = %s  \n" ,arg1->var,t3 );  
      
      
      if_else2();
      if_else0();
      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t4[10] = "T";  
      strcat(t4,res);
      printf("%s = %s %s %s \n",t4,arg2->var,"-",arg1->var);
      fprintf(myfile,"%s = %s %s %s \n",t4,arg2->var,"-",arg1->var);
      temp++;

      printf("%s = %s  \n" ,arg2->var,t4);
      printf("L%d: \ngoto L%d \n",l_num1,l_num);
      fprintf(myfile,"%s = %s  \n" ,arg2->var,t4);
      fprintf(myfile,"L%d: \ngoto L%d \n",l_num1,l_num);
      l_num1++;

      printf("L%d:\n",l_num);
      fprintf(myfile,"L%d:\n",l_num);
      l_num++;

      flag = 1;

      printf("goto L%d \n",l_num-4);
      printf("L%d: \n",l_num-3);
      fprintf(myfile,"goto L%d \n",l_num-4);
      fprintf(myfile,"L%d: \n",l_num-3);
      flag = 0;


      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t8[10] = "T";  
      strcat(t8,res);
      printf("%s = %s / %s \n" ,t8 , t7,arg1->var);
      fprintf(myfile,"%s = %s / %s \n" ,t8 , t7,arg1->var);
      temp++;
      strcpy(cur->var,t8);
}

codegen_fact(node * cur, node * arg1 , char *op){
      char *res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t1[10] = "T";  
      strcat(t1,res);
      printf("%s = %s  \n" ,t1 , "1");
      fprintf(myfile,"%s = %s  \n" ,t1 , "1");
      temp++; 

      while1();

      node *new = (node*)malloc(sizeof(node));

      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t4[10] = "T";  
      strcat(t4,res);
      temp++;
      printf("%s = %s > 0 \n" , t4,arg1->var);
      fprintf(myfile,"%s = %s > 0 \n" , t4,arg1->var);
      new->var = t4;


      while2(new);

      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t2[10] = "T";  
      strcat(t2,res);
      printf("%s = %s * %s \n",t2,t1,arg1->var);
      printf("%s = %s \n",t1,t2);
      fprintf(myfile,"%s = %s * %s \n",t2,t1,arg1->var);
      fprintf(myfile,"%s = %s \n",t1,t2);
      temp++;

      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t3[10] = "T";  
      strcat(t3,res);
      printf("%s = %s - 1 \n",t3,arg1->var);
      printf("%s = %s\n",arg1->var,t3);
      fprintf(myfile,"%s = %s - 1 \n",t3,arg1->var);
      fprintf(myfile,"%s = %s\n",arg1->var,t3);
      temp++;


      while3();
      flag = 1;

      strcpy(cur->var,t1);
}

codegen_pow(node * cur, node * arg1 , node * arg2 , char *op){
      char *res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t1[10] = "T";  
      strcat(t1,res);
      printf("%s = %s  \n" ,t1 , "1");
      fprintf(myfile,"%s = %s  \n" ,t1 , "1");
      temp++; 

      while1();

      node *new = (node*)malloc(sizeof(node));

      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t4[10] = "T";  
      strcat(t4,res);
      temp++;
      printf("%s = %s > 0 \n" , t4,arg2->var);
      fprintf(myfile,"%s = %s > 0 \n" , t4,arg2->var);
      new->var = t4;


      while2(new);

      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t2[10] = "T";  
      strcat(t2,res);
      printf("%s = %s * %s \n",t2,t1,arg1->var);
      printf("%s = %s \n",t1,t2);
      fprintf(myfile,"%s = %s * %s \n",t2,t1,arg1->var);
      fprintf(myfile,"%s = %s \n",t1,t2);
      temp++;

      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t3[10] = "T";  
      strcat(t3,res);
      printf("%s = %s - 1 \n",t3,arg2->var);
      printf("%s = %s\n",arg2->var,t3);
      fprintf(myfile,"%s = %s - 1 \n",t3,arg2->var);
      fprintf(myfile,"%s = %s\n",arg2->var,t3);
      temp++;


      while3();
      flag = 1;

      strcpy(cur->var,t1);
}


for_new1( node* arg1  ,node* arg2 ){
      printf("%s = %s\n" , arg1->name , arg2->name);
      fprintf(myfile,"%s = %s\n" , arg1->name , arg2->name);
      arg1->var = arg1->name;
      forhelp1();
}
for_new2( node* arg1 , node * arg2 ){

      char *res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t1[10] = "T";  
      strcat(t1,res);
      temp++;
      printf("%s = %s < %s \n"  ,t1, arg1->name , arg2->name);
      fprintf(myfile,"%s = %s < %s \n"  ,t1, arg1->name , arg2->name);

      node *new = (node*)malloc(sizeof(node));
      new->var = t1;

      forhelp2(new);
}
for_new3( node* arg1 , node * arg2 ){

      char *res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t1[10] = "T";  
      strcat(t1,res);
      temp++;
      printf("%s = %s + %s\n"  ,t1, arg1->var , arg2->var);
      printf("%s = %s \n"  , arg1->var , t1);
      fprintf(myfile,"%s = %s + %s\n"  ,t1, arg1->var , arg2->var);
      fprintf(myfile,"%s = %s \n"  , arg1->var , t1);
}


forhelp1(){
      if(flag == 0){
      printf("L%d: \n", l_num);
      fprintf(myfile,"L%d: \n", l_num);
      }
      idx++;
      arr[idx++] = l_num+1;
      arr[idx] = l_num;
 
}

forhelp2(node * n){
      printf("T%d = not %s \n",temp,n->var);
      fprintf(myfile,"T%d = not %s \n",temp,n->var);
      printf("If T%d goto L%d \n",temp,++l_num);
      fprintf(myfile,"If T%d goto L%d \n",temp,l_num);
      temp++;

      flag = 0;
}

forhelp3(){

      printf("goto L%d  \n",arr[idx]);
      fprintf(myfile,"goto L%d \n",arr[idx--]);
      printf("L%: \n",arr[idx]);
      fprintf(myfile,"L%d: \n",arr[idx--]);
      flag = 1;     
}
