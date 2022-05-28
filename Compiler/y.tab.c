
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



	int yylex();
	void yyerror(const char *s);
	#include "semanticAnalyzer.h"
	char* currentName;
	int currentScope = 0;
	int currentDataTypeNumber;
	int yylineno;
	struct entry* currentEntry = NULL;
	extern struct entry** mainTable;
	struct table* tableList;


	int yylex(void);
	#define maxLinesToParse 256
	extern FILE * yyin;
    FILE * f1;
	int lineCount=0;
	char outputMessages [maxLinesToParse][maxLinesToParse];
	int isLeftSide = 0;
	int isDeclaration = 0; 

	

	struct entry * insert( char *name, int value, int data_type, struct entry** mainTable);
	struct entry * YaccInsert(char* currentName,double number,int typeNumber,struct entry ** mainTable);
	void printInFile(char message[maxLinesToParse]);
	void type_check(int,int,int);


/* Line 189 of yacc.c  */
#line 106 "y.tab.c"

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
     IF = 258,
     ELSE = 259,
     FOR = 260,
     WHILE = 261,
     DO = 262,
     SWITCH = 263,
     CASE = 264,
     DEFAULT = 265,
     BREAK = 266,
     CONTINUE = 267,
     RETURN = 268,
     SEMICOLON = 269,
     INTEGER = 270,
     CHARACTER = 271,
     FLOAT = 272,
     STRING = 273,
     DOUBLE = 274,
     BOOLEAN = 275,
     CONSTANT = 276,
     VOID = 277,
     VAL_INTEGER = 278,
     VAL_FLOAT = 279,
     VAL_DOUBLE = 280,
     VAL_STRING = 281,
     VAL_CHAR = 282,
     VAL_BOOLEAN = 283,
     IDETIFIER = 284,
     OP_INCREMENT = 285,
     OP_DECREMENT = 286,
     OP_MODULO_EQUAL = 287,
     OP_DIVIDE_EQUAL = 288,
     OP_MULTIPLY_EQUAL = 289,
     OP_MINUS_EQUAL = 290,
     OP_PLUS_EQUAL = 291,
     OP_LOGICAL_OR = 292,
     OP_LOGICAL_AND = 293,
     OP_INEQUALITY = 294,
     OP_EQUALITY = 295,
     OP_GREATER_THAN = 296,
     OP_LESS_THAN = 297,
     OP_GREATER_OR_EQUAL = 298,
     OP_LESS_OR_EQUAL = 299,
     OP_LOGICAL_NOT = 300,
     THEN = 301
   };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define DO 262
#define SWITCH 263
#define CASE 264
#define DEFAULT 265
#define BREAK 266
#define CONTINUE 267
#define RETURN 268
#define SEMICOLON 269
#define INTEGER 270
#define CHARACTER 271
#define FLOAT 272
#define STRING 273
#define DOUBLE 274
#define BOOLEAN 275
#define CONSTANT 276
#define VOID 277
#define VAL_INTEGER 278
#define VAL_FLOAT 279
#define VAL_DOUBLE 280
#define VAL_STRING 281
#define VAL_CHAR 282
#define VAL_BOOLEAN 283
#define IDETIFIER 284
#define OP_INCREMENT 285
#define OP_DECREMENT 286
#define OP_MODULO_EQUAL 287
#define OP_DIVIDE_EQUAL 288
#define OP_MULTIPLY_EQUAL 289
#define OP_MINUS_EQUAL 290
#define OP_PLUS_EQUAL 291
#define OP_LOGICAL_OR 292
#define OP_LOGICAL_AND 293
#define OP_INEQUALITY 294
#define OP_EQUALITY 295
#define OP_GREATER_THAN 296
#define OP_LESS_THAN 297
#define OP_GREATER_OR_EQUAL 298
#define OP_LESS_OR_EQUAL 299
#define OP_LOGICAL_NOT 300
#define THEN 301




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 40 "parser.y"

		char* lex_token_str;
		int data_type;
		struct entry* entry;
	


/* Line 214 of yacc.c  */
#line 242 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 254 "y.tab.c"

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
#define YYFINAL  83
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   577

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNRULES -- Number of states.  */
#define YYNSTATES  219

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    50,     2,     2,
      52,    53,    48,    46,    56,    47,     2,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    55,
       2,    37,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    58,     2,     2,     2,     2,
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
      35,    36,    38,    39,    40,    41,    42,    43,    44,    45,
      51,    54
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    15,    18,    21,
      24,    27,    30,    33,    36,    39,    42,    45,    49,    53,
      54,    58,    61,    65,    68,    71,    74,    76,    78,    80,
      82,    86,    88,    90,    92,    94,    96,    98,   102,   106,
     110,   114,   118,   121,   125,   129,   133,   137,   141,   145,
     149,   153,   156,   160,   163,   167,   171,   175,   179,   183,
     186,   189,   192,   195,   198,   201,   204,   208,   211,   220,
     228,   240,   248,   258,   260,   262,   273,   275,   277,   283,
     287,   288,   296,   302,   305,   307,   308,   312,   314,   315,
     320,   323,   325,   327,   329,   331,   333,   335,   337,   339,
     341,   343,   345,   347,   349,   351,   353,   355,   357
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      61,     0,    -1,    62,    -1,    63,    -1,    79,    -1,    65,
      62,    -1,    71,    62,    -1,    91,    62,    -1,    80,    62,
      -1,    81,    62,    -1,    82,    62,    -1,    84,    62,    -1,
      87,    62,    -1,    76,    62,    -1,    77,    62,    -1,    73,
      62,    -1,    78,    62,    -1,    11,    55,    62,    -1,    12,
      55,    62,    -1,    -1,    70,    56,    64,    -1,    70,    55,
      -1,    29,    56,    64,    -1,    29,    55,    -1,    96,    64,
      -1,    21,    65,    -1,    67,    -1,    90,    -1,    68,    -1,
      69,    -1,    52,    66,    53,    -1,    94,    -1,    70,    -1,
      74,    -1,    75,    -1,    72,    -1,    29,    -1,    66,    46,
      66,    -1,    66,    47,    66,    -1,    66,    48,    66,    -1,
      66,    49,    66,    -1,    66,    50,    66,    -1,    47,    66,
      -1,    66,    41,    66,    -1,    66,    40,    66,    -1,    66,
      44,    66,    -1,    66,    45,    66,    -1,    66,    42,    66,
      -1,    66,    43,    66,    -1,    66,    38,    66,    -1,    66,
      39,    66,    -1,    51,    66,    -1,    29,    37,    66,    -1,
      70,    55,    -1,    29,    36,    66,    -1,    29,    35,    66,
      -1,    29,    34,    66,    -1,    29,    33,    66,    -1,    29,
      32,    66,    -1,    72,    55,    -1,    30,    29,    -1,    29,
      30,    -1,    31,    29,    -1,    29,    31,    -1,    74,    55,
      -1,    75,    55,    -1,    13,    66,    55,    -1,    13,    55,
      -1,    96,    29,    52,    88,    53,    57,    63,    58,    -1,
       3,    52,    66,    53,    57,    63,    58,    -1,     3,    52,
      66,    53,    57,    63,    58,     4,    57,    63,    58,    -1,
       6,    52,    66,    53,    57,    63,    58,    -1,     7,    57,
      63,    58,     6,    52,    66,    53,    55,    -1,    65,    -1,
      71,    -1,     5,    52,    83,    66,    55,    66,    53,    57,
      63,    58,    -1,    23,    -1,    27,    -1,     9,    85,    59,
      63,    86,    -1,    10,    59,    63,    -1,    -1,     8,    52,
      29,    53,    57,    86,    58,    -1,    95,    29,    56,    95,
      29,    -1,    95,    29,    -1,    22,    -1,    -1,    66,    56,
      89,    -1,    66,    -1,    -1,    29,    52,    89,    53,    -1,
      90,    55,    -1,    23,    -1,    24,    -1,    28,    -1,    27,
      -1,    26,    -1,    92,    -1,    93,    -1,    15,    -1,    17,
      -1,    16,    -1,    18,    -1,    20,    -1,    15,    -1,    17,
      -1,    16,    -1,    18,    -1,    20,    -1,    22,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   111,   111,   114,   115,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     135,   136,   137,   138,   142,   148,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   165,   166,   167,
     168,   169,   170,   173,   174,   175,   176,   177,   178,   181,
     182,   183,   189,   197,   200,   201,   202,   203,   204,   207,
     210,   211,   214,   215,   218,   221,   224,   225,   231,   236,
     237,   242,   245,   249,   250,   253,   256,   257,   260,   261,
     262,   265,   269,   270,   271,   272,   275,   276,   277,   281,
     282,   284,   285,   288,   289,   290,   293,   294,   297,   298,
     299,   300,   301,   304,   305,   306,   307,   308,   309
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "DO",
  "SWITCH", "CASE", "DEFAULT", "BREAK", "CONTINUE", "RETURN", "SEMICOLON",
  "INTEGER", "CHARACTER", "FLOAT", "STRING", "DOUBLE", "BOOLEAN",
  "CONSTANT", "VOID", "VAL_INTEGER", "VAL_FLOAT", "VAL_DOUBLE",
  "VAL_STRING", "VAL_CHAR", "VAL_BOOLEAN", "IDETIFIER", "OP_INCREMENT",
  "OP_DECREMENT", "OP_MODULO_EQUAL", "OP_DIVIDE_EQUAL",
  "OP_MULTIPLY_EQUAL", "OP_MINUS_EQUAL", "OP_PLUS_EQUAL", "'='",
  "OP_LOGICAL_OR", "OP_LOGICAL_AND", "OP_INEQUALITY", "OP_EQUALITY",
  "OP_GREATER_THAN", "OP_LESS_THAN", "OP_GREATER_OR_EQUAL",
  "OP_LESS_OR_EQUAL", "'+'", "'-'", "'*'", "'/'", "'%'", "OP_LOGICAL_NOT",
  "'('", "')'", "THEN", "';'", "','", "'{'", "'}'", "':'", "$accept",
  "program", "Starter", "Statement", "OneLineDeclaration",
  "VarDeclaration", "Expression", "ArithmeticExp", "RelationalExp",
  "LogicalExp", "AssignExp", "Assign", "ArithmeticAssignExp",
  "ArithmeticAssign", "IncrementExp", "DecrementExp", "Increment",
  "Decrement", "Return", "Function", "Condition", "WhileLoop",
  "DoWhileLoop", "ForLoopInit", "ForLoop", "SwitchValueTypes", "Case",
  "SwitchCase", "Parameters", "Arguments", "FunctionCallExp",
  "FunctionCall", "ValueTypeNumber", "ValueTypeLetter", "ValueTypeAll",
  "DataTypeNoVoid", "DataType", 0
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
     285,   286,   287,   288,   289,   290,   291,    61,   292,   293,
     294,   295,   296,   297,   298,   299,    43,    45,    42,    47,
      37,   300,    40,    41,   301,    59,    44,   123,   125,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      64,    64,    64,    64,    65,    65,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    67,    67,    67,
      67,    67,    67,    68,    68,    68,    68,    68,    68,    69,
      69,    69,    70,    71,    72,    72,    72,    72,    72,    73,
      74,    74,    75,    75,    76,    77,    78,    78,    79,    80,
      80,    81,    82,    83,    83,    84,    85,    85,    86,    86,
      86,    87,    88,    88,    88,    88,    89,    89,    89,    90,
      91,    92,    92,    93,    93,    93,    94,    94,    95,    95,
      95,    95,    95,    96,    96,    96,    96,    96,    96
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     3,     3,     0,
       3,     2,     3,     2,     2,     2,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     2,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     2,     2,     2,     3,     2,     8,     7,
      11,     7,     9,     1,     1,    10,     1,     1,     5,     3,
       0,     7,     5,     2,     1,     0,     3,     1,     0,     4,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      19,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     105,   104,   106,   107,     0,   108,     0,     0,     0,     0,
       2,     3,    19,     0,    19,     0,    19,     0,     0,    19,
      19,    19,     4,    19,    19,    19,    19,    19,     0,    19,
       0,     0,     0,     0,    19,     0,    19,    19,    91,    92,
      95,    94,    93,    36,     0,     0,     0,    67,     0,    26,
      28,    29,    32,    35,    33,    34,    27,    96,    97,    31,
      25,     0,    61,    63,     0,     0,     0,     0,     0,     0,
      88,    60,    62,     1,     5,    53,     6,    59,    15,    64,
      65,    13,    14,    16,     8,     9,    10,    11,    12,    90,
       7,     0,    24,     0,     0,     0,    73,    74,     0,     0,
       0,     0,    17,    18,    42,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      66,     0,    58,    57,    56,    55,    54,    52,    87,     0,
      85,    23,     0,    21,     0,     0,     0,     0,     0,     0,
      30,    49,    50,    44,    43,    47,    48,    45,    46,    37,
      38,    39,    40,    41,    88,    89,    98,   100,    99,   101,
     102,    84,     0,     0,    22,    20,    19,     0,    19,     0,
      80,    86,     0,    83,     0,     0,     0,     0,     0,     0,
       0,    19,     0,    69,     0,    71,     0,    76,    77,     0,
      19,    81,     0,     0,     0,    19,     0,    19,    79,    68,
      82,    19,     0,    72,    80,     0,    75,    78,    70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    21,   102,    22,   138,    59,    60,    61,
      62,    24,    63,    26,    64,    65,    29,    30,    31,    32,
      33,    34,    35,   108,    36,   199,   190,    37,   172,   139,
      66,    39,    67,    68,    69,   173,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -142
static const yytype_int16 yypact[] =
{
     355,   -29,   -27,   -25,   -19,     5,     4,     9,   157,  -142,
    -142,  -142,  -142,  -142,   200,  -142,   -24,    38,    39,    69,
    -142,  -142,   355,    17,   355,    21,   355,    28,    36,   355,
     355,   355,  -142,   355,   355,   355,   355,   355,    53,   355,
      45,   286,   133,   286,   355,    64,   355,   355,  -142,  -142,
    -142,  -142,  -142,   -24,   286,   286,   286,  -142,   280,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,    81,  -142,  -142,   286,   286,   286,   286,   286,   286,
     286,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,   -35,  -142,   -40,   415,    75,  -142,  -142,   286,   431,
      63,    74,  -142,  -142,  -142,  -142,   447,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
    -142,    23,   495,   495,   495,   495,   495,   495,   378,    76,
     217,  -142,    81,  -142,    81,    77,   397,    83,   125,    84,
    -142,   507,   518,   527,   527,   110,   110,   110,   110,    97,
      97,  -142,  -142,  -142,   286,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,    85,   114,  -142,  -142,   355,   286,   355,   111,
      52,  -142,   107,   109,   112,   463,   113,   286,    -9,   108,
     115,   355,   237,   165,   117,  -142,   479,  -142,  -142,   116,
     355,  -142,   119,   150,   132,   355,   127,   355,  -142,  -142,
    -142,   355,   134,  -142,    52,   135,  -142,  -142,  -142
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -142,  -142,   365,   -39,  -141,   -10,   228,  -142,  -142,  -142,
       0,   148,    19,  -142,    51,    70,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,   -20,  -142,  -142,    32,
      89,  -142,  -142,  -142,  -142,     6,    88
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      23,   174,    79,   175,    70,   110,    72,    73,    74,    75,
      76,    77,    78,    79,   197,   143,   144,   140,   198,    25,
     141,   142,    23,    41,    23,    42,    23,    43,    80,    23,
      23,    23,   106,    23,    23,    23,    23,    23,    44,    23,
     103,    25,    23,    25,    23,    25,    23,    23,    25,    25,
      25,    27,    25,    25,    25,    25,    25,    45,    25,    46,
      79,   188,   189,    25,    47,    25,    25,    81,    82,    83,
      28,   103,    85,    27,   101,    27,    87,    27,   141,   142,
      27,    27,    27,    89,    27,    27,    27,    27,    27,    38,
      27,    90,    28,   111,    28,    27,    28,    27,    27,    28,
      28,    28,    71,    28,    28,    28,    28,    28,    99,    28,
     131,    38,    79,    38,    28,    38,    28,    28,    38,    38,
      38,   148,    38,    38,    38,    38,    38,   149,    38,   165,
      71,   179,    71,    38,   176,    38,    38,   184,   182,   186,
     178,   180,   103,   183,   103,   127,   128,   129,     9,    10,
      11,    12,   202,    13,    14,    15,   125,   126,   127,   128,
     129,   208,   105,   187,   191,   192,   212,   200,   214,   204,
     193,   195,   215,   201,   205,   207,    23,   209,    23,   210,
      48,    49,   213,    50,    51,    52,    53,    17,    18,   211,
     107,    23,   216,   218,   217,    25,   181,    25,   203,     0,
      23,     0,     0,     0,    54,    23,     0,    23,    55,    56,
      25,    23,    57,     0,     0,     9,    10,    11,    12,    25,
      13,    14,    15,     0,    25,     0,    25,    27,     0,    27,
      25,     0,   166,   167,   168,   169,    58,   170,     0,   171,
       0,     0,    27,     0,     0,     0,    28,     0,    28,     0,
       0,    27,   166,   167,   168,   169,    27,   170,    27,     0,
       0,    28,    27,     0,    71,    38,    71,    38,     0,   104,
      28,   109,     0,     0,     0,    28,     0,    28,     0,    71,
      38,    28,   114,   115,   116,     0,     0,     0,    71,    38,
       0,     0,     0,    71,    38,    71,    38,     0,     0,    71,
      38,     0,   132,   133,   134,   135,   136,   137,     0,    48,
      49,     0,    50,    51,    52,    53,    17,    18,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,     0,     0,    54,     0,   130,   146,    55,    56,     0,
       0,     0,     0,     0,     0,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,     1,     0,
       2,     3,     4,     5,     0,     0,     6,     7,     8,     0,
       9,    10,    11,    12,     0,    13,    14,    15,     0,     0,
       0,     0,     0,     0,    16,    17,    18,    84,     0,    86,
       0,    88,     0,     0,    91,    92,    93,     0,    94,    95,
      96,    97,    98,     0,   100,   185,     0,     0,     0,     0,
       0,   112,   113,     0,     0,   196,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,     0,
       0,     0,     0,     0,   164,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     0,     0,
       0,     0,   177,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     0,     0,   145,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     0,     0,   147,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     0,     0,
     150,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,     0,     0,   194,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       0,     0,   206,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   121,
     122,   123,   124,   125,   126,   127,   128,   129
};

static const yytype_int16 yycheck[] =
{
       0,   142,    37,   144,    14,    44,    30,    31,    32,    33,
      34,    35,    36,    37,    23,    55,    56,    52,    27,     0,
      55,    56,    22,    52,    24,    52,    26,    52,    52,    29,
      30,    31,    42,    33,    34,    35,    36,    37,    57,    39,
      40,    22,    42,    24,    44,    26,    46,    47,    29,    30,
      31,     0,    33,    34,    35,    36,    37,    52,    39,    55,
      37,     9,    10,    44,    55,    46,    47,    29,    29,     0,
       0,    71,    55,    22,    29,    24,    55,    26,    55,    56,
      29,    30,    31,    55,    33,    34,    35,    36,    37,     0,
      39,    55,    22,    29,    24,    44,    26,    46,    47,    29,
      30,    31,    14,    33,    34,    35,    36,    37,    55,    39,
      29,    22,    37,    24,    44,    26,    46,    47,    29,    30,
      31,    58,    33,    34,    35,    36,    37,    53,    39,    53,
      42,     6,    44,    44,    57,    46,    47,   176,    53,   178,
      57,    57,   142,    29,   144,    48,    49,    50,    15,    16,
      17,    18,   191,    20,    21,    22,    46,    47,    48,    49,
      50,   200,    29,    52,    57,    56,   205,    59,   207,     4,
      58,    58,   211,    58,    57,    59,   176,    58,   178,    29,
      23,    24,    55,    26,    27,    28,    29,    30,    31,    57,
      42,   191,    58,    58,   214,   176,   164,   178,   192,    -1,
     200,    -1,    -1,    -1,    47,   205,    -1,   207,    51,    52,
     191,   211,    55,    -1,    -1,    15,    16,    17,    18,   200,
      20,    21,    22,    -1,   205,    -1,   207,   176,    -1,   178,
     211,    -1,    15,    16,    17,    18,     8,    20,    -1,    22,
      -1,    -1,   191,    -1,    -1,    -1,   176,    -1,   178,    -1,
      -1,   200,    15,    16,    17,    18,   205,    20,   207,    -1,
      -1,   191,   211,    -1,   176,   176,   178,   178,    -1,    41,
     200,    43,    -1,    -1,    -1,   205,    -1,   207,    -1,   191,
     191,   211,    54,    55,    56,    -1,    -1,    -1,   200,   200,
      -1,    -1,    -1,   205,   205,   207,   207,    -1,    -1,   211,
     211,    -1,    74,    75,    76,    77,    78,    79,    -1,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    47,    -1,    55,   108,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     3,    -1,
       5,     6,     7,     8,    -1,    -1,    11,    12,    13,    -1,
      15,    16,    17,    18,    -1,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    22,    -1,    24,
      -1,    26,    -1,    -1,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    -1,    39,   177,    -1,    -1,    -1,    -1,
      -1,    46,    47,    -1,    -1,   187,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,    -1,    56,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    -1,    55,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    53,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    -1,    53,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    -1,
      53,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    53,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    -1,    53,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    42,
      43,    44,    45,    46,    47,    48,    49,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,     8,    11,    12,    13,    15,
      16,    17,    18,    20,    21,    22,    29,    30,    31,    61,
      62,    63,    65,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    84,    87,    90,    91,
      96,    52,    52,    52,    57,    52,    55,    55,    23,    24,
      26,    27,    28,    29,    47,    51,    52,    55,    66,    67,
      68,    69,    70,    72,    74,    75,    90,    92,    93,    94,
      65,    96,    30,    31,    32,    33,    34,    35,    36,    37,
      52,    29,    29,     0,    62,    55,    62,    55,    62,    55,
      55,    62,    62,    62,    62,    62,    62,    62,    62,    55,
      62,    29,    64,    70,    66,    29,    65,    71,    83,    66,
      63,    29,    62,    62,    66,    66,    66,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      55,    29,    66,    66,    66,    66,    66,    66,    66,    89,
      52,    55,    56,    55,    56,    53,    66,    53,    58,    53,
      53,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    56,    53,    15,    16,    17,    18,
      20,    22,    88,    95,    64,    64,    57,    55,    57,     6,
      57,    89,    53,    29,    63,    66,    63,    52,     9,    10,
      86,    57,    56,    58,    53,    58,    66,    23,    27,    85,
      59,    58,    63,    95,     4,    57,    53,    59,    63,    58,
      29,    57,    63,    55,    63,    63,    58,    86,    58
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
        case 23:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    { 	currentEntry = YaccInsert(currentName,0,currentDataTypeNumber,mainTable);
																}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    {	
																if(currentEntry!= NULL){	
																	isDeclaration = 1; 
																	printInFile("Variable Defined succefully\n");
																}
															}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),0); }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),0); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),0); }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),0); }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),0); }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    { 	if(isDeclaration){
																						currentEntry = YaccInsert(currentName,0,currentDataTypeNumber,mainTable);
																						isDeclaration = 0;
																						}
																						
																				}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 197 "parser.y"
    {printInFile("Assigned succefully\n");}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    {printInFile("Prefix increment Exp detected\n");}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    {printInFile("Postfix increment Exp detected\n");}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 214 "parser.y"
    {printInFile("Prefix decrement Exp detected\n");}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 215 "parser.y"
    {printInFile("Postfix decrement Exp detected\n");}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 218 "parser.y"
    {printInFile("increment detected\n");}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 221 "parser.y"
    {printInFile("decrement detected\n");}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 231 "parser.y"
    {printInFile("Function constructed successfully\n");}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 242 "parser.y"
    {printInFile("While Loop constructed successfully\n");}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 245 "parser.y"
    {printInFile("Do while Loop constructed successfully\n");}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 253 "parser.y"
    {printInFile("For Loop constructed successfully\n");}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 265 "parser.y"
    {printInFile("Switch case constructed successfully\n");}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 284 "parser.y"
    {(yyval.data_type) = INTEGER;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 285 "parser.y"
    {(yyval.data_type) = FLOAT; }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 288 "parser.y"
    {(yyval.data_type) = BOOLEAN; }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 289 "parser.y"
    {(yyval.data_type) = CHARACTER; }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 290 "parser.y"
    {(yyval.data_type) = STRING; }
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 297 "parser.y"
    {currentDataTypeNumber = INTEGER; }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 298 "parser.y"
    {currentDataTypeNumber = FLOAT;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 299 "parser.y"
    {currentDataTypeNumber = CHARACTER;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 300 "parser.y"
    {currentDataTypeNumber = STRING;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 301 "parser.y"
    {currentDataTypeNumber = BOOLEAN;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 304 "parser.y"
    {currentDataTypeNumber = INTEGER; (yyval.data_type) = INTEGER;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 305 "parser.y"
    {currentDataTypeNumber = FLOAT; (yyval.data_type) = FLOAT;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 306 "parser.y"
    {currentDataTypeNumber = CHARACTER; (yyval.data_type) = CHARACTER;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 307 "parser.y"
    {currentDataTypeNumber = STRING; (yyval.data_type) = STRING;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 308 "parser.y"
    {currentDataTypeNumber = BOOLEAN; (yyval.data_type) = BOOLEAN;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 309 "parser.y"
    {currentDataTypeNumber = VOID; (yyval.data_type) = VOID;}
    break;



/* Line 1455 of yacc.c  */
#line 1980 "y.tab.c"
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
#line 312 "parser.y"


void type_check(int left, int right, int flag){
	if(left != right)
	{	
		switch(flag)
		{
			case 0: yyerror("Error: Type mismatch in arithmetic expression"); break;
			case 1: yyerror("Error: Type mismatch in assignment expression"); break;
			case 2: yyerror("Error: Type mismatch in logical expression"); break;
		}
	}
}

struct entry * YaccInsert(char* currentName,double number,int typeNumber,struct entry ** mainTable){
	currentEntry = insert(currentName,number,typeNumber,mainTable);
	if(currentEntry == NULL){
		yyerror("Error: Variable already declared in this scope");
	}
}

void yyerror (char const *s) {
	int value = yylineno + 1;
	printf ("%s in line number : %d\n", s, value);
	char errorString[256];
	strcpy(errorString,s);
	printInFile(errorString);
}

void printInFile(char message[maxLinesToParse]){
	strcpy(outputMessages[lineCount],message);
	lineCount++;
}


int main(void) {
	mainTable = Initialize();
    yyin = fopen("test1.txt", "r");
	f1=fopen("output.txt","w");
   if(!yyparse())
	{
		printf("\nParsing complete\n");
		for(int i=0; i<lineCount ; i++)
			fprintf(f1,outputMessages[i]);
		printTableData(tableList);	
	}
	else
	{
		for(int i=0; i<lineCount ; i++)
			fprintf(f1,outputMessages[i]);
		printf("\nParsing failed\n");
		return 0;
	}
	fclose(yyin);
	fclose(f1);
    return 0;
}

