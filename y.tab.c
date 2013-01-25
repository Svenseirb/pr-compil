/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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

/* Line 268 of yacc.c  */
#line 1 "parse.y"

  #include <stdio.h>
  #include <string.h>
  #include "y.tab.h"
  #include "hashtab/hashtab.h"
  #include <stdlib.h>

  int reg = 0;
  Hashtab *htab;
  char **regtoid;

  void idCopy(char * src, char *dest){
    int i = 0;
    while (src[i] != '\0' && src[i] != ' ' && src[i] != '=' && src[i] != '(' && src[i] != '\n'){
      dest[i]=src[i];
      i++;
    }
    dest[i] = '\0';
  }


  int len_string = 0;

  void clean_string(char * s)
  {
    int i;
    int len = strlen(s);
    for (i = 0; i < len - 1; i++)
      {
	s[i] = s[i + 1];
      }
    s[len-2] = '\0';
  }

  void error(char *msg){
    int len = strlen(msg) + 11;
    char *errmsg = malloc(len*sizeof(char));
    strcpy(errmsg, "erreur : ");
    strcat(errmsg, msg);
    strcat(errmsg, "\n");
    write(2, errmsg, len);
    exit(1);
  }



/* Line 268 of yacc.c  */
#line 118 "y.tab.c"

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
     AND = 258,
     OR = 259,
     CLASS = 260,
     IF = 261,
     THEN = 262,
     ELSE = 263,
     END = 264,
     WHILE = 265,
     DO = 266,
     DEF = 267,
     LEQ = 268,
     GEQ = 269,
     STRING = 270,
     FLOAT = 271,
     INT = 272,
     ID = 273,
     BOOL = 274,
     FOR = 275,
     TO = 276,
     RETURN = 277,
     IN = 278,
     NEQ = 279,
     EQ = 280
   };
#endif
/* Tokens.  */
#define AND 258
#define OR 259
#define CLASS 260
#define IF 261
#define THEN 262
#define ELSE 263
#define END 264
#define WHILE 265
#define DO 266
#define DEF 267
#define LEQ 268
#define GEQ 269
#define STRING 270
#define FLOAT 271
#define INT 272
#define ID 273
#define BOOL 274
#define FOR 275
#define TO 276
#define RETURN 277
#define IN 278
#define NEQ 279
#define EQ 280




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 53 "parse.y"

  int nombre;
  char *chaine;
  float flottant;
  struct mix{int nombre;
  char *chaine;
}mix;


/* Line 293 of yacc.c  */
#line 214 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 226 "y.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   255

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNRULES -- Number of states.  */
#define YYNSTATES  119

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      38,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      33,    34,    25,    27,    35,    28,    36,    26,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
      29,    32,    30,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      31
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     7,     9,    13,    19,    27,    29,
      30,    32,    36,    43,    53,    64,    72,    76,    79,    87,
      88,    91,    95,    99,   101,   103,   107,   112,   116,   118,
     120,   122,   124,   126,   128,   132,   136,   140,   142,   146,
     150,   154,   158,   162,   166,   168,   170,   174,   178,   182,
     186,   188,   189,   191,   194,   197,   199,   201,   203
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    41,    54,    -1,    -1,    42,    -1,    41,
      55,    42,    -1,     5,    18,    56,    43,     9,    -1,     5,
      18,    29,    18,    56,    43,     9,    -1,    44,    -1,    -1,
      44,    -1,    43,    55,    44,    -1,     6,    50,     7,    43,
      55,     9,    -1,     6,    50,     7,    43,    55,     8,    43,
      55,     9,    -1,    20,    18,    23,    50,    21,    50,    56,
      43,    55,     9,    -1,    10,    50,    11,    56,    43,    55,
       9,    -1,    47,    32,    50,    -1,    22,    50,    -1,    12,
      18,    45,    56,    43,    55,     9,    -1,    -1,    33,    34,
      -1,    33,    46,    34,    -1,    18,    35,    46,    -1,    18,
      -1,    18,    -1,    18,    36,    49,    -1,    18,    33,    48,
      34,    -1,    48,    35,    50,    -1,    50,    -1,    47,    -1,
      15,    -1,    16,    -1,    17,    -1,    19,    -1,    33,    50,
      34,    -1,    50,     3,    51,    -1,    50,     4,    51,    -1,
      51,    -1,    52,    29,    52,    -1,    52,    30,    52,    -1,
      52,    13,    52,    -1,    52,    14,    52,    -1,    52,    31,
      52,    -1,    52,    24,    52,    -1,    52,    -1,    53,    -1,
      52,    27,    53,    -1,    52,    28,    53,    -1,    53,    25,
      49,    -1,    53,    26,    49,    -1,    49,    -1,    -1,    55,
      -1,    55,    37,    -1,    55,    38,    -1,    37,    -1,    38,
      -1,    37,    -1,    38,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    67,    68,    69,    71,    72,    73,    76,
      77,    78,    81,    82,    83,    84,    85,   101,   102,   105,
     106,   107,   109,   110,   112,   116,   117,   119,   120,   124,
     133,   135,   141,   147,   153,   157,   158,   159,   163,   172,
     173,   174,   175,   176,   177,   181,   183,   219,   250,   286,
     314,   319,   320,   323,   324,   325,   326,   329,   330
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "OR", "CLASS", "IF", "THEN",
  "ELSE", "END", "WHILE", "DO", "DEF", "LEQ", "GEQ", "STRING", "FLOAT",
  "INT", "ID", "BOOL", "FOR", "TO", "RETURN", "IN", "NEQ", "'*'", "'/'",
  "'+'", "'-'", "'<'", "'>'", "EQ", "'='", "'('", "')'", "','", "'.'",
  "';'", "'\\n'", "$accept", "program", "topstmts", "topstmt", "stmts",
  "stmt", "opt_params", "params", "lhs", "exprs", "primary", "expr",
  "comp_expr", "additive_expr", "multiplicative_expr", "opt_terms",
  "terms", "term", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    42,    47,    43,    45,    60,
      62,   280,    61,    40,    41,    44,    46,    59,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    41,    42,    42,    42,    43,
      43,    43,    44,    44,    44,    44,    44,    44,    44,    45,
      45,    45,    46,    46,    47,    47,    47,    48,    48,    49,
      49,    49,    49,    49,    49,    50,    50,    50,    51,    51,
      51,    51,    51,    51,    51,    52,    52,    52,    53,    53,
      53,    54,    54,    55,    55,    55,    55,    56,    56
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     3,     5,     7,     1,     0,
       1,     3,     6,     9,    10,     7,     3,     2,     7,     0,
       2,     3,     3,     1,     1,     3,     4,     3,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     1,     3,     3,     3,     3,
       1,     0,     1,     2,     2,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     0,    24,     0,     0,     0,    51,
       4,     8,     0,     0,    30,    31,    32,    33,     0,    29,
      50,     0,    37,    44,    45,     0,    19,     0,     0,     0,
      17,     1,    55,    56,     2,    52,     0,     0,    57,    58,
       9,     0,     0,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      25,     0,    53,    54,     5,    16,     0,     0,    10,    34,
      35,    36,     0,    40,    41,    43,    46,    47,    38,    39,
      42,    48,    49,     9,    23,    20,     0,     9,    26,     0,
       0,     9,     6,     0,     0,     0,     0,    21,     0,    27,
       0,     0,    11,     9,    12,     0,    22,     0,     0,     7,
       0,    15,    18,     9,     0,     0,    13,     0,    14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     8,     9,    10,    67,    68,    57,    86,    19,    58,
      20,    21,    22,    23,    24,    34,    93,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -55
static const yytype_int16 yypact[] =
{
     225,   -10,   209,   209,    14,     1,    25,   209,    20,    15,
     -55,   -55,    -7,    31,   -55,   -55,   -55,   -55,   209,   -55,
     -55,   156,   -55,   188,    40,     7,    22,   209,   209,    -1,
      77,   -55,   -55,   -55,   -55,     9,   209,    30,   -55,   -55,
     135,     2,   209,   209,   135,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,    62,   -11,    62,    94,    77,
     -55,   209,   -55,   -55,   -55,    77,    62,    19,   -55,   -55,
     -55,   -55,    15,   109,   109,   109,    40,    40,   109,   109,
     109,   -55,   -55,   135,    27,   -55,    41,   135,   -55,   209,
      75,   135,   -55,   185,    64,    15,    59,   -55,    15,    77,
     209,    21,   -55,   135,   -55,   113,   -55,   134,    13,   -55,
      15,   -55,   -55,   135,   155,    15,   -55,   176,   -55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -55,   -55,   -55,    50,   -42,     4,   -55,    -8,     0,   -55,
      10,     6,    96,   203,   100,   -55,    17,   -54
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      12,    83,    72,    87,    11,    42,    43,    84,    13,    25,
      42,    43,    91,    30,     1,     2,    42,    43,    55,     3,
      31,     4,    61,    85,    41,    36,    35,     5,    92,     6,
     109,     7,    26,    59,    27,    12,    69,    28,    60,    11,
      12,    95,    65,    29,    12,    98,    62,    63,    66,   101,
      38,    39,    32,    33,   113,    56,    32,    33,    32,    33,
      37,   110,    96,    81,    82,    53,    54,    90,    38,    39,
       2,   115,   103,   104,     3,    97,     4,    84,    42,    43,
      42,    43,     5,    12,     6,    64,     7,    12,   106,    94,
       0,    12,     0,    12,    12,    99,   100,   102,   102,    38,
      39,    62,    63,    12,     0,    12,   108,    12,     0,   102,
       0,   102,   105,    12,    12,   107,     0,    12,   102,     2,
       0,   102,   111,     3,     0,     4,     0,   114,    88,    89,
       0,     5,   117,     6,     0,     7,    48,    49,    70,    71,
       2,     2,     0,   112,     3,     3,     4,     4,    76,    77,
      62,    63,     5,     5,     6,     6,     7,     7,     0,    42,
      43,     2,     0,    44,   116,     3,     0,     4,     0,     0,
       0,    62,    63,     5,     0,     6,     0,     7,     0,     0,
       0,     0,     2,     0,     0,   118,     3,     0,     4,     0,
       0,     2,    62,    63,     5,     3,     6,     4,     7,     0,
       0,    45,    46,     5,     0,     6,     0,     7,     0,     0,
       0,     0,    47,    62,    63,    48,    49,    50,    51,    52,
       0,     0,    62,    63,    14,    15,    16,     5,    17,     0,
       1,     2,     0,     0,     0,     3,     0,     4,     0,     0,
       0,     0,    18,     5,     0,     6,     0,     7,    73,    74,
      75,     0,     0,    78,    79,    80
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-55))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
       0,    55,    44,    57,     0,     3,     4,    18,    18,     3,
       3,     4,    66,     7,     5,     6,     3,     4,    11,    10,
       0,    12,    23,    34,    18,    32,     9,    18,     9,    20,
       9,    22,    18,    27,    33,    35,    34,    36,    28,    35,
      40,    83,    36,    18,    44,    87,    37,    38,    18,    91,
      37,    38,    37,    38,   108,    33,    37,    38,    37,    38,
      29,   103,    35,    53,    54,    25,    26,    61,    37,    38,
       6,   113,     8,     9,    10,    34,    12,    18,     3,     4,
       3,     4,    18,    83,    20,    35,    22,    87,    96,    72,
      -1,    91,    -1,    93,    94,    89,    21,    93,    94,    37,
      38,    37,    38,   103,    -1,   105,   100,   107,    -1,   105,
      -1,   107,    95,   113,   114,    98,    -1,   117,   114,     6,
      -1,   117,     9,    10,    -1,    12,    -1,   110,    34,    35,
      -1,    18,   115,    20,    -1,    22,    27,    28,    42,    43,
       6,     6,    -1,     9,    10,    10,    12,    12,    48,    49,
      37,    38,    18,    18,    20,    20,    22,    22,    -1,     3,
       4,     6,    -1,     7,     9,    10,    -1,    12,    -1,    -1,
      -1,    37,    38,    18,    -1,    20,    -1,    22,    -1,    -1,
      -1,    -1,     6,    -1,    -1,     9,    10,    -1,    12,    -1,
      -1,     6,    37,    38,    18,    10,    20,    12,    22,    -1,
      -1,    13,    14,    18,    -1,    20,    -1,    22,    -1,    -1,
      -1,    -1,    24,    37,    38,    27,    28,    29,    30,    31,
      -1,    -1,    37,    38,    15,    16,    17,    18,    19,    -1,
       5,     6,    -1,    -1,    -1,    10,    -1,    12,    -1,    -1,
      -1,    -1,    33,    18,    -1,    20,    -1,    22,    45,    46,
      47,    -1,    -1,    50,    51,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    10,    12,    18,    20,    22,    40,    41,
      42,    44,    47,    18,    15,    16,    17,    19,    33,    47,
      49,    50,    51,    52,    53,    50,    18,    33,    36,    18,
      50,     0,    37,    38,    54,    55,    32,    29,    37,    38,
      56,    50,     3,     4,     7,    13,    14,    24,    27,    28,
      29,    30,    31,    25,    26,    11,    33,    45,    48,    50,
      49,    23,    37,    38,    42,    50,    18,    43,    44,    34,
      51,    51,    43,    52,    52,    52,    53,    53,    52,    52,
      52,    49,    49,    56,    18,    34,    46,    56,    34,    35,
      50,    56,     9,    55,    55,    43,    35,    34,    43,    50,
      21,    43,    44,     8,     9,    55,    46,    55,    50,     9,
      43,     9,     9,    56,    55,    43,     9,    55,     9
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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


/*----------.
| yyparse.  |
`----------*/

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
  if (yypact_value_is_default (yyn))
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
      if (yytable_value_is_error (yyn))
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
        case 16:

/* Line 1806 of yacc.c  */
#line 86 "parse.y"
    {
  int tmpreg;
  tmpreg = hashtab_getreg(htab, (yyvsp[(1) - (3)].mix).chaine);
  if(tmpreg != -1){
    if(strcmp(hashtab_gettype(htab, (yyvsp[(1) - (3)].mix).chaine),(yyvsp[(3) - (3)].mix).chaine) !=0){
      error("Mauvais type assigne a la variable");
    }
    free(regtoid[tmpreg]);
  }
  else{ 
    hashtab_addtype(htab,(yyvsp[(1) - (3)].mix).chaine, (yyvsp[(3) - (3)].mix).chaine); 
  }
  hashtab_addreg(htab,(yyvsp[(1) - (3)].mix).chaine,reg-1); 
  regtoid[reg-1]=strdup((yyvsp[(1) - (3)].mix).chaine);
  }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 113 "parse.y"
    {
(yyval.mix).chaine = malloc(strlen((yyvsp[(1) - (1)].chaine))*sizeof(char));  
idCopy((yyvsp[(1) - (1)].chaine), (yyval.mix).chaine);}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 125 "parse.y"
    {
  idCopy((yyvsp[(1) - (1)].mix).chaine, (yyvsp[(1) - (1)].mix).chaine);
  (yyval.mix).nombre = hashtab_getreg(htab,(yyvsp[(1) - (1)].mix).chaine);
  (yyval.mix).chaine = hashtab_gettype(htab,(yyvsp[(1) - (1)].mix).chaine);
  if((yyval.mix).nombre == -1){
    error("utilisation d'un variable non initialisee");
  }
}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 134 "parse.y"
    {/*$$.nombre = reg; clean_string((char *)$1); len_string = strlen((char *)$1) + 1; printf("\%r%d = internal constant [%d x i8] c\"%s\\00\"\n", reg, len_string, (char *)$1); reg++;*/}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 136 "parse.y"
    {(yyval.mix).nombre = reg;
  (yyval.mix).chaine = malloc(6*sizeof(char));
  (yyval.mix).chaine = "float"; 
  printf("\%r%d = fadd float 0.0, %f\n", reg, (yyvsp[(1) - (1)].flottant)); 
  reg++;}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 142 "parse.y"
    {(yyval.mix).nombre = reg; 
  (yyval.mix).chaine = malloc(4*sizeof(char));
  (yyval.mix).chaine = "int";
  printf("\%r%d = add i32 0, %d\n", reg, (yyvsp[(1) - (1)].nombre)); 
  reg++;}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 148 "parse.y"
    {(yyval.mix).nombre = reg; 
  (yyval.mix).chaine = malloc(5*sizeof(char));
  (yyval.mix).chaine = "bool";
  printf("\%r%d = add i1 0, %d\n", reg, (yyvsp[(1) - (1)].nombre)); 
  reg++;}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 164 "parse.y"
    {
  
  (yyval.mix).nombre = reg;
  (yyval.mix).chaine = malloc(5*sizeof(char));
  (yyval.mix).chaine = "bool";
  printf("\%r%d = icmp ult i32 \%r%d, \%r%d\n",reg, (yyvsp[(1) - (3)].mix).nombre, (yyvsp[(3) - (3)].mix).nombre);
  reg++;
  }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 181 "parse.y"
    {}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 184 "parse.y"
    {
  (yyval.mix).nombre = reg;
  if(strcmp((yyvsp[(1) - (3)].mix).chaine, "float")==0 || strcmp((yyvsp[(3) - (3)].mix).chaine, "float")==0){
    if(strcmp((yyvsp[(1) - (3)].mix).chaine, "int")==0){
      int ntemp = (yyvsp[(1) - (3)].mix).nombre;
      (yyvsp[(1) - (3)].mix).nombre = reg;
      reg++;
      printf("\%r%d = sitofp i32 \%r%d to float\n",(yyvsp[(1) - (3)].mix).nombre, ntemp);
    }
    if(strcmp((yyvsp[(3) - (3)].mix).chaine, "int")==0){
      int ntemp = (yyvsp[(3) - (3)].mix).nombre;
      (yyvsp[(3) - (3)].mix).nombre = reg;
      reg++;
      printf("\%r%d = sitofp i32 \%r%d to float\n",(yyvsp[(3) - (3)].mix).nombre, ntemp);
    }
    (yyval.mix).chaine = malloc(6*sizeof(char));
    (yyval.mix).chaine = "float"; 
    printf("\%r%d = fadd float \%r%d, \%r%d\n",reg, (yyvsp[(1) - (3)].mix).nombre, (yyvsp[(3) - (3)].mix).nombre);
  }
  else if(strcmp((yyvsp[(1) - (3)].mix).chaine, "bool")==0 && strcmp((yyvsp[(3) - (3)].mix).chaine, "bool")==0){
    (yyval.mix).chaine = malloc(4*sizeof(char));
    (yyval.mix).chaine = "bool";
    printf("\%r%d = or i1 \%r%d, \%r%d\n",reg, (yyvsp[(1) - (3)].mix).nombre, (yyvsp[(3) - (3)].mix).nombre);
  }
  else if(strcmp((yyvsp[(1) - (3)].mix).chaine, "bool")==0 ||  strcmp((yyvsp[(3) - (3)].mix).chaine, "bool")==0){
    error("addition d'un booleen avec un autre type");
  }
  else{
    (yyval.mix).chaine = malloc(4*sizeof(char));
    (yyval.mix).chaine = "int"; 
    printf("\%r%d = add i32 \%r%d, \%r%d\n",reg, (yyvsp[(1) - (3)].mix).nombre, (yyvsp[(3) - (3)].mix).nombre); 
  }
  reg++;
}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 220 "parse.y"
    {
  (yyval.mix).nombre = reg; 
  if(strcmp((yyvsp[(1) - (3)].mix).chaine, "float")==0 || strcmp((yyvsp[(3) - (3)].mix).chaine, "float")==0){
    if(strcmp((yyvsp[(1) - (3)].mix).chaine, "int")==0){
      int ntemp = (yyvsp[(1) - (3)].mix).nombre;
      (yyvsp[(1) - (3)].mix).nombre = reg;
      reg++;
      printf("\%r%d = sitofp i32 \%r%d to float\n",(yyvsp[(1) - (3)].mix).nombre, ntemp);
    }
    if(strcmp((yyvsp[(3) - (3)].mix).chaine, "int")==0){
      int ntemp = (yyvsp[(3) - (3)].mix).nombre;
      (yyvsp[(3) - (3)].mix).nombre = reg;
      reg++;
      printf("\%r%d = sitofp i32 \%r%d to float\n",(yyvsp[(3) - (3)].mix).nombre, ntemp);
    }
    (yyval.mix).chaine = malloc(6*sizeof(char));
    (yyval.mix).chaine = "float"; 
    printf("\%r%d = fsub float \%r%d, \%r%d\n",reg, (yyvsp[(1) - (3)].mix).nombre, (yyvsp[(3) - (3)].mix).nombre);
  }
  else{
    (yyval.mix).chaine = malloc(4*sizeof(char));
    (yyval.mix).chaine = "int"; 
    printf("\%r%d = sub i32 \%r%d, \%r%d\n",reg, (yyvsp[(1) - (3)].mix).nombre, (yyvsp[(3) - (3)].mix).nombre); 
  }
  reg++;
}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 251 "parse.y"
    {
  (yyval.mix).nombre = reg; 
  if(strcmp((yyvsp[(1) - (3)].mix).chaine, "float")==0 || strcmp((yyvsp[(3) - (3)].mix).chaine, "float")==0){
    if(strcmp((yyvsp[(1) - (3)].mix).chaine, "int")==0){
      int ntemp = (yyvsp[(1) - (3)].mix).nombre;
      (yyvsp[(1) - (3)].mix).nombre = reg;
      reg++;
      printf("\%r%d = sitofp i32 \%r%d to float\n",(yyvsp[(1) - (3)].mix).nombre, ntemp);
    }
    if(strcmp((yyvsp[(3) - (3)].mix).chaine, "int")==0){
      int ntemp = (yyvsp[(3) - (3)].mix).nombre;
      (yyvsp[(3) - (3)].mix).nombre = reg;
      reg++;
      printf("\%r%d = sitofp i32 \%r%d to float\n",(yyvsp[(3) - (3)].mix).nombre, ntemp);
    }
    (yyval.mix).chaine = malloc(6*sizeof(char));
    (yyval.mix).chaine = "float"; 
    printf("\%r%d = fmul float \%r%d, \%r%d\n",reg, (yyvsp[(1) - (3)].mix).nombre, (yyvsp[(3) - (3)].mix).nombre);
  }
  else if(strcmp((yyvsp[(1) - (3)].mix).chaine, "bool")==0 && strcmp((yyvsp[(3) - (3)].mix).chaine, "bool")==0){
    (yyval.mix).chaine = malloc(4*sizeof(char));
    (yyval.mix).chaine = "bool";
    printf("\%r%d = and i1 \%r%d, \%r%d\n",reg, (yyvsp[(1) - (3)].mix).nombre, (yyvsp[(3) - (3)].mix).nombre);
  }
  else if(strcmp((yyvsp[(1) - (3)].mix).chaine, "bool")==0 ||  strcmp((yyvsp[(3) - (3)].mix).chaine, "bool")==0){
    error("multiplication d'un booleen avec un autre type");
  }
  else{
    (yyval.mix).chaine = malloc(4*sizeof(char));
    (yyval.mix).chaine = "int"; 
    printf("\%r%d = mul i32 \%r%d, \%r%d\n",reg, (yyvsp[(1) - (3)].mix).nombre, (yyvsp[(3) - (3)].mix).nombre); 
  }
  reg++;
}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 287 "parse.y"
    {
  (yyval.mix).nombre = reg; 
  if(strcmp((yyvsp[(1) - (3)].mix).chaine, "float")==0 || strcmp((yyvsp[(3) - (3)].mix).chaine, "float")==0){
    if(strcmp((yyvsp[(1) - (3)].mix).chaine, "int")==0){
      int ntemp = (yyvsp[(1) - (3)].mix).nombre;
      (yyvsp[(1) - (3)].mix).nombre = reg;
      reg++;
      printf("\%r%d = sitofp i32 \%r%d to float\n",(yyvsp[(1) - (3)].mix).nombre, ntemp);
    }
    if(strcmp((yyvsp[(3) - (3)].mix).chaine, "int")==0){
      int ntemp = (yyvsp[(3) - (3)].mix).nombre;
      (yyvsp[(3) - (3)].mix).nombre = reg;
      reg++;
      printf("\%r%d = sitofp i32 \%r%d to float\n",(yyvsp[(3) - (3)].mix).nombre, ntemp);
    }
    (yyval.mix).chaine = malloc(6*sizeof(char));
    (yyval.mix).chaine = "float"; 
    printf("\%r%d = fdiv float \%r%d, \%r%d\n",reg, (yyvsp[(1) - (3)].mix).nombre, (yyvsp[(3) - (3)].mix).nombre);
  }
  else{
    (yyval.mix).chaine = malloc(4*sizeof(char));
    (yyval.mix).chaine = "int"; 
    printf("\%r%d = sdiv i32 \%r%d, \%r%d\n",reg, (yyvsp[(1) - (3)].mix).nombre, (yyvsp[(3) - (3)].mix).nombre); 
  }
  reg++;
}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 315 "parse.y"
    {(yyval.mix) = (yyvsp[(1) - (1)].mix);}
    break;



/* Line 1806 of yacc.c  */
#line 1828 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
      if (!yypact_value_is_default (yyn))
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 334 "parse.y"


void print_begin() {
        puts("@str = constant [ 7 x i8 ] c\"=> %d\\0A\\00\"");
        puts("declare i32 @printf(i8*, ...)\n");
        puts("define i1 @calcule() {");
}

void print_end() {
	printf("ret i1 \%r%d\n", reg-1);
        puts("}\n");
        puts("define i32 @main() {");
        puts("\t%x = call i1 @calcule()");
        puts("\tcall i32 (i8*, ...)* @printf(i8* getelementptr ([7 x i8]* @str, i32 0, i32 0), i1 %x)");
        puts("\tret i32 0\n}");
}

int main() {
  htab = hashtab_create();
  regtoid = malloc(10000*sizeof(char*));

  print_begin();
  yyparse(); 
  print_end();

  hashtab_delete(htab);
  return 0;
}

