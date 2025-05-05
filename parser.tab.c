
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
#include <string.h>
#define MAX_ERRORES 100 //manejo de errores
typedef struct {
    int tipoError;
    int linea;
} ErrorSintactico;

int numErroresSintacticos = 0;
ErrorSintactico listaErrores[MAX_ERRORES];

void agregarError(int tipoError, int linea); 
int errorYaRegistrado(int tipoError, int linea); 
void mostrarErrores();

extern int yylineno;
extern int yylex(void);
extern int numErroresLex;
extern int numTokens;
extern int numComentarios;
int errores_sintacticos = 0;

void yyerror(const char *s);


/* Line 189 of yacc.c  */
#line 101 "parser.tab.c"

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
     ENTERO = 258,
     FLOTANTE = 259,
     CARACTER = 260,
     CADENA = 261,
     SI = 262,
     SINOSI = 263,
     SINO = 264,
     ELEGIR = 265,
     CASO = 266,
     DEFECTO = 267,
     MIENTRAS = 268,
     PARA = 269,
     HACER = 270,
     DEVOLVER = 271,
     ROMPER = 272,
     CONTINUAR = 273,
     IMPRIMIR = 274,
     LEER = 275,
     ERROR = 276,
     ESTRUCTURA = 277,
     VOID = 278,
     CONSTANTE = 279,
     OR = 280,
     AND = 281,
     IGUAL = 282,
     DIFERENTE = 283,
     MENORIGUAL = 284,
     MAYORIGUAL = 285,
     INCREMENTO = 286,
     DECREMENTO = 287,
     ENTERO_T = 288,
     FLOTANTE_T = 289,
     CARACTER_T = 290,
     BOOLEANO_T = 291,
     CADENA_T = 292,
     VERDADERO = 293,
     FALSO = 294,
     ID = 295
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 28 "parser.y"

    int    entero;
    float  flotante;
    char   caracter;
    char*  cadena;



/* Line 214 of yacc.c  */
#line 186 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 198 "parser.tab.c"

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
#define YYFINAL  104
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1741

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  204
/* YYNRULES -- Number of states.  */
#define YYNSTATES  474

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,     2,     2,    48,     2,     2,
      51,    52,    46,    44,    56,    45,    53,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,    59,
      42,    49,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    18,
      20,    22,    24,    28,    32,    36,    38,    40,    43,    45,
      48,    50,    52,    54,    56,    58,    60,    62,    66,    70,
      76,    82,    88,    95,   102,   109,   116,   123,   130,   137,
     148,   159,   170,   177,   188,   199,   210,   221,   232,   237,
     246,   248,   250,   252,   256,   260,   262,   264,   266,   268,
     270,   272,   275,   278,   285,   292,   299,   306,   308,   311,
     315,   319,   325,   331,   337,   340,   343,   349,   355,   361,
     367,   373,   379,   385,   392,   399,   406,   413,   415,   422,
     429,   436,   443,   446,   453,   456,   464,   472,   480,   483,
     485,   488,   490,   492,   497,   502,   504,   507,   511,   515,
     518,   521,   523,   525,   527,   533,   539,   545,   555,   565,
     575,   585,   595,   605,   615,   625,   635,   645,   650,   655,
     663,   671,   679,   687,   691,   695,   702,   709,   716,   723,
     730,   737,   744,   750,   752,   756,   760,   762,   765,   767,
     769,   773,   777,   779,   784,   785,   799,   803,   807,   809,
     813,   815,   819,   823,   825,   829,   833,   837,   841,   843,
     847,   851,   853,   857,   861,   865,   867,   870,   873,   876,
     879,   881,   884,   887,   889,   891,   893,   898,   903,   908,
     913,   917,   921,   925,   929,   933,   937,   939,   941,   943,
     945,   947,   949,   951,   953
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      61,     0,    -1,   112,    -1,    62,    -1,    62,    63,    -1,
      63,    -1,    94,    -1,    74,    -1,    68,    -1,    69,    -1,
      70,    -1,    73,    -1,    57,    65,    58,    -1,    57,    65,
       1,    -1,     1,    65,    58,    -1,   112,    -1,   112,    -1,
      65,    63,    -1,    67,    -1,    24,    67,    -1,    40,    -1,
      33,    -1,    34,    -1,    35,    -1,    36,    -1,    40,    -1,
      37,    -1,    66,    40,    59,    -1,    66,    40,     1,    -1,
      66,    40,    49,    97,    59,    -1,    66,    40,     1,    97,
      59,    -1,    66,    40,    49,    97,     1,    -1,    24,    67,
      40,    49,    97,    59,    -1,    24,    67,    40,     1,    97,
      59,    -1,    24,    67,    40,    49,    97,     1,    -1,    66,
      40,    54,    71,    55,    59,    -1,    66,    40,     1,    71,
      55,    59,    -1,    66,    40,    54,    71,     1,    59,    -1,
      66,    40,    54,    71,    55,     1,    -1,    66,    40,    54,
      71,    55,    49,    57,    72,    58,    59,    -1,    66,    40,
      54,    71,    55,     1,    57,    72,    58,    59,    -1,    66,
      40,    55,    71,    55,    49,    57,    72,    58,    59,    -1,
      66,    40,    55,    71,    55,    59,    -1,    66,    40,     1,
      71,    55,    49,    57,    72,    58,    59,    -1,    66,    40,
      54,    71,     1,    49,    57,    72,    58,    59,    -1,    66,
      40,    54,    71,    55,    49,    57,    72,    58,     1,    -1,
      66,    40,    54,    71,    55,    49,    57,    72,     1,    59,
      -1,    66,    40,    54,    71,    55,    49,     1,    72,    58,
      59,    -1,    66,    40,    55,     1,    -1,    66,    40,     1,
      49,    57,    72,    58,    59,    -1,     3,    -1,    40,    -1,
      97,    -1,    72,    56,    97,    -1,    72,     1,    97,    -1,
      77,    -1,    78,    -1,    80,    -1,    88,    -1,    93,    -1,
      87,    -1,    18,    59,    -1,    18,     1,    -1,    22,    40,
      57,    75,    58,    59,    -1,    22,    40,    57,    75,    58,
       1,    -1,    22,    40,    57,    75,     1,    59,    -1,    22,
      40,     1,    75,    58,    59,    -1,   112,    -1,    76,    75,
      -1,    66,    40,    59,    -1,    66,    40,     1,    -1,    66,
      40,    49,    97,    59,    -1,    66,    40,     1,    97,    59,
      -1,    66,    40,    49,    97,     1,    -1,    97,    59,    -1,
      97,     1,    -1,    19,    51,   110,    52,    59,    -1,    19,
      51,   110,    52,     1,    -1,    19,     1,   110,    52,    59,
      -1,    19,    51,   110,     1,    59,    -1,    20,    51,    40,
      52,    59,    -1,    20,     1,    40,    52,    59,    -1,    20,
      51,    40,     1,    59,    -1,     7,    51,    97,    52,    64,
      79,    -1,     7,     1,    97,    52,    64,    79,    -1,     7,
      51,    97,     1,    64,    79,    -1,     7,    51,    97,    52,
       1,    79,    -1,   112,    -1,     8,    51,    97,    52,    64,
      79,    -1,     8,     1,    97,    52,    64,    79,    -1,     8,
      51,    97,     1,    64,    79,    -1,     8,    51,    97,    52,
       1,    79,    -1,     9,    64,    -1,     9,     7,    51,    97,
      52,    64,    -1,     9,     1,    -1,    10,    51,    97,    52,
      57,    81,    58,    -1,    10,    51,    97,    52,    57,    81,
       1,    -1,    10,    51,    97,    52,     1,    81,    58,    -1,
      82,    83,    -1,   112,    -1,    82,    84,    -1,   112,    -1,
      86,    -1,    11,    97,    41,    85,    -1,    11,    97,     1,
      85,    -1,    73,    -1,    85,    73,    -1,    12,    41,    85,
      -1,    12,     1,    85,    -1,    17,    59,    -1,    17,     1,
      -1,    89,    -1,    90,    -1,    92,    -1,    13,    51,    97,
      52,    64,    -1,    13,     1,    97,    52,    64,    -1,    13,
      51,    97,     1,    64,    -1,    14,    51,    91,    59,    97,
      59,    97,    52,    64,    -1,    14,    51,    91,     1,    97,
      59,    97,    52,    64,    -1,    14,    51,    91,    59,    97,
       1,    97,    52,    64,    -1,    14,     1,    91,    59,    97,
      59,    97,    52,    64,    -1,    14,    51,    91,    59,    97,
      59,    97,     1,    64,    -1,    14,    51,    77,    59,    97,
      59,    97,    52,    64,    -1,    14,    51,    77,     1,    97,
      59,    97,    52,    64,    -1,    14,    51,    77,    59,    97,
       1,    97,    52,    64,    -1,    14,     1,    77,    59,    97,
      59,    97,    52,    64,    -1,    14,    51,    77,    59,    97,
      59,    97,     1,    64,    -1,    66,    40,    49,    97,    -1,
      66,    40,     1,    97,    -1,    15,    64,    13,    51,    97,
      52,    59,    -1,    15,    64,    13,    51,    97,    52,     1,
      -1,    15,    64,    13,     1,    97,    52,    59,    -1,    15,
      64,    13,    51,    97,     1,    59,    -1,    16,    97,    59,
      -1,    16,    97,     1,    -1,    66,    40,    51,    95,    52,
      64,    -1,    66,    40,     1,    95,    52,    64,    -1,    66,
      40,    51,    95,    52,     1,    -1,    66,    40,    51,    95,
       1,    64,    -1,    23,    40,    51,    95,    52,    64,    -1,
      23,    40,     1,    95,    52,    64,    -1,    23,    40,    51,
      95,     1,    64,    -1,    66,    40,    51,    52,     1,    -1,
      96,    -1,    96,    56,    95,    -1,    96,     1,    95,    -1,
     112,    -1,    66,    40,    -1,    98,    -1,   101,    -1,    99,
      49,    97,    -1,    99,     1,    97,    -1,    40,    -1,    40,
      54,    97,    55,    -1,    -1,    40,    54,    97,    55,    40,
       1,    97,    55,   100,    40,    54,    97,     1,    -1,    40,
      53,    40,    -1,   102,    25,   102,    -1,   102,    -1,   103,
      26,   103,    -1,   103,    -1,   104,    27,   104,    -1,   104,
      28,   104,    -1,   104,    -1,   105,    42,   105,    -1,   105,
      29,   105,    -1,   105,    43,   105,    -1,   105,    30,   105,
      -1,   105,    -1,   106,    44,   106,    -1,   106,    45,   106,
      -1,   106,    -1,   107,    46,   107,    -1,   107,    47,   107,
      -1,   107,    48,   107,    -1,   107,    -1,    50,   107,    -1,
      45,   107,    -1,    31,   107,    -1,    32,   107,    -1,   108,
      -1,   109,    31,    -1,   109,    32,    -1,   109,    -1,   111,
      -1,    40,    -1,    40,    51,   110,    52,    -1,    40,     1,
     110,    52,    -1,    40,    51,   110,     1,    -1,    40,    54,
      97,    55,    -1,     1,    97,    55,    -1,    54,    97,     1,
      -1,    40,    53,    40,    -1,    51,    97,    52,    -1,     1,
      97,    52,    -1,    51,    97,     1,    -1,   112,    -1,    72,
      -1,     3,    -1,     4,    -1,     5,    -1,    38,    -1,    39,
      -1,     6,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    85,    89,    90,    94,    95,    96,    97,
      98,    99,   103,   104,   109,   114,   118,   119,   123,   124,
     125,   129,   130,   131,   132,   133,   134,   138,   139,   144,
     145,   150,   158,   159,   164,   172,   173,   178,   183,   188,
     189,   194,   199,   204,   209,   214,   219,   224,   229,   234,
     243,   244,   248,   249,   250,   258,   259,   260,   261,   262,
     263,   264,   265,   273,   274,   279,   284,   292,   293,   297,
     298,   303,   304,   309,   317,   318,   323,   324,   329,   334,
     339,   340,   345,   359,   360,   365,   370,   378,   379,   380,
     384,   388,   392,   393,   399,   407,   408,   413,   421,   425,
     426,   430,   431,   435,   436,   444,   445,   449,   450,   459,
     460,   468,   469,   470,   474,   475,   481,   490,   491,   496,
     501,   506,   511,   512,   517,   522,   527,   535,   536,   544,
     545,   550,   555,   563,   564,   572,   573,   578,   583,   588,
     589,   594,   599,   607,   608,   609,   614,   618,   622,   623,
     627,   628,   636,   637,   639,   638,   649,   653,   654,   658,
     659,   663,   664,   665,   669,   670,   671,   672,   673,   677,
     678,   679,   683,   684,   685,   686,   690,   691,   692,   693,
     694,   698,   699,   700,   704,   705,   706,   707,   712,   717,
     718,   723,   728,   729,   730,   735,   742,   743,   747,   748,
     749,   750,   751,   752,   776
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ENTERO", "FLOTANTE", "CARACTER",
  "CADENA", "SI", "SINOSI", "SINO", "ELEGIR", "CASO", "DEFECTO",
  "MIENTRAS", "PARA", "HACER", "DEVOLVER", "ROMPER", "CONTINUAR",
  "IMPRIMIR", "LEER", "ERROR", "ESTRUCTURA", "VOID", "CONSTANTE", "OR",
  "AND", "IGUAL", "DIFERENTE", "MENORIGUAL", "MAYORIGUAL", "INCREMENTO",
  "DECREMENTO", "ENTERO_T", "FLOTANTE_T", "CARACTER_T", "BOOLEANO_T",
  "CADENA_T", "VERDADERO", "FALSO", "ID", "':'", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'='", "'!'", "'('", "')'", "'.'", "'['",
  "']'", "','", "'{'", "'}'", "';'", "$accept", "programa",
  "declaraciones", "declaracion", "bloque", "lista_declaraciones", "tipo",
  "tipo_base", "variable", "constante", "arreglo", "tamano",
  "lista_expresiones", "sentencia", "estructura", "miembros", "miembro",
  "expr_sent", "si", "sinosi_opt", "elegir", "casos", "lista_casos",
  "defecto_opt", "caso", "sentencias", "defecto", "romper", "bucle",
  "mientras", "para", "decl_var_inicializacion", "hacer_mientras",
  "retorno", "funcion", "parametros", "parametro", "expresion",
  "asignacion", "lvalor", "$@1", "logica_or", "logica_and", "igualdad",
  "relacional", "aditiva", "multiplicativa", "unaria", "postfija",
  "primaria", "argumentos", "literal", "vacio", 0
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
     295,    58,    60,    62,    43,    45,    42,    47,    37,    61,
      33,    40,    41,    46,    91,    93,    44,   123,   125,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      63,    63,    64,    64,    64,    64,    65,    65,    66,    66,
      66,    67,    67,    67,    67,    67,    67,    68,    68,    68,
      68,    68,    69,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      71,    71,    72,    72,    72,    73,    73,    73,    73,    73,
      73,    73,    73,    74,    74,    74,    74,    75,    75,    76,
      76,    76,    76,    76,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    78,    78,    78,    78,    79,    79,    79,
      79,    79,    79,    79,    79,    80,    80,    80,    81,    82,
      82,    83,    83,    84,    84,    85,    85,    86,    86,    87,
      87,    88,    88,    88,    89,    89,    89,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    91,    91,    92,
      92,    92,    92,    93,    93,    94,    94,    94,    94,    94,
      94,    94,    94,    95,    95,    95,    95,    96,    97,    97,
      98,    98,    99,    99,   100,    99,    99,   101,   101,   102,
     102,   103,   103,   103,   104,   104,   104,   104,   104,   105,
     105,   105,   106,   106,   106,   106,   107,   107,   107,   107,
     107,   108,   108,   108,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   110,   110,   111,   111,
     111,   111,   111,   111,   112
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     1,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     5,
       5,     5,     6,     6,     6,     6,     6,     6,     6,    10,
      10,    10,     6,    10,    10,    10,    10,    10,     4,     8,
       1,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     2,     2,     6,     6,     6,     6,     1,     2,     3,
       3,     5,     5,     5,     2,     2,     5,     5,     5,     5,
       5,     5,     5,     6,     6,     6,     6,     1,     6,     6,
       6,     6,     2,     6,     2,     7,     7,     7,     2,     1,
       2,     1,     1,     4,     4,     1,     2,     3,     3,     2,
       2,     1,     1,     1,     5,     5,     5,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     4,     4,     7,
       7,     7,     7,     3,     3,     6,     6,     6,     6,     6,
       6,     6,     5,     1,     3,     3,     1,     2,     1,     1,
       3,     3,     1,     4,     0,    13,     3,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     2,     2,     2,     2,
       1,     2,     2,     1,     1,     1,     4,     4,     4,     4,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,   198,   199,   200,   203,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,    22,    23,    24,    26,   201,   202,     0,     0,
       0,     0,     0,     0,     0,     5,     0,    18,     8,     9,
      10,    11,     7,    55,    56,    57,    60,    58,   111,   112,
     113,    59,     6,     0,   148,     0,   149,   158,   160,   163,
     168,   171,   175,   180,   183,   184,     2,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,   204,     0,    15,
       0,   110,   109,    62,    61,     0,     0,     0,     0,     0,
       0,    25,     0,     0,   178,   179,     0,     0,     0,     0,
     177,   176,     0,     0,     1,     4,     0,    75,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   181,   182,   194,   190,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     0,     0,   134,   133,     0,    52,     0,   196,     0,
       0,     0,   204,   204,   204,   204,     0,     0,     0,     0,
       0,   192,     0,   195,   193,   191,     0,     0,   204,     0,
       0,    27,   151,   150,   157,   159,   161,   162,   165,   167,
     164,   166,   169,   170,   172,   173,   174,     0,     0,     0,
       0,     0,     0,     0,    19,     0,     0,     0,     0,     0,
       0,     0,    14,    17,     0,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,     0,     0,   204,
      67,     0,     0,     0,     0,   146,     0,     0,     0,   192,
       0,   187,   188,   186,   189,   198,     0,     0,     0,     0,
       0,     0,     0,     0,    50,    51,     0,    48,     0,   204,
     204,   204,   204,   204,   204,   115,   116,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,    53,
      78,    79,    77,    76,    81,    82,    80,     0,     0,    68,
       0,     0,   147,     0,   204,   204,     0,     0,     0,     0,
     189,     0,     0,     0,     0,    30,    31,    29,   142,     0,
       0,     0,     0,     0,     0,     0,    84,    87,    85,    86,
      16,    83,     0,   204,    99,     0,   128,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    66,    65,    64,    63,   140,   145,   144,   141,
     139,    33,    34,    32,     0,     0,     0,    36,   136,   138,
     137,   135,     0,    37,    38,     0,    35,     0,    42,     0,
       0,    94,     0,    92,    97,     0,     0,    98,   100,   102,
     101,    96,    95,     0,     0,     0,     0,     0,     0,     0,
       0,   131,   132,   130,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    72,    73,    71,   154,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,     0,
       0,   125,   120,   123,   124,   126,   122,   118,   119,   121,
     117,     0,     0,     0,     0,     0,     0,     0,     0,   204,
     204,   204,   204,     0,     0,     0,   106,     0,    43,    44,
      40,    47,    46,    45,    39,    41,    89,    90,    91,    88,
      93,     0,     0,   155
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    33,    34,   203,    78,   139,   222,    37,    38,    39,
      40,   238,   145,    41,    42,   218,   219,    43,    44,   306,
      45,   312,   313,   367,   368,   429,   369,    46,    47,    48,
      49,   136,    50,    51,    52,   223,   224,    53,    54,    55,
     441,    56,    57,    58,    59,    60,    61,    62,    63,    64,
     147,    65,    79
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -266
static const yytype_int16 yypact[] =
{
    1456,  1644,  -266,  -266,  -266,  -266,   172,    -7,   193,   221,
     135,  1644,    15,    19,   236,   238,    -2,    99,  1177,  1687,
    1687,  -266,  -266,  -266,  -266,  -266,  -266,  -266,   988,  1687,
    1687,  1644,  1644,    48,  1508,  -266,   112,  -266,  -266,  -266,
    -266,  -266,  -266,  -266,  -266,  -266,  -266,  -266,  -266,  -266,
    -266,  -266,  -266,    20,  -266,   264,  -266,   130,   155,   152,
       7,   282,   309,  -266,   317,  -266,  -266,   918,     8,  1644,
    1644,  1644,  1644,  1644,  1584,  1584,  -266,  -266,   163,  -266,
      21,  -266,  -266,  -266,  -266,  1627,  1627,   201,   207,    10,
     239,  -266,   212,   252,  -266,  -266,  1627,  1627,   216,  1644,
    -266,  -266,    13,   242,  -266,  -266,     2,  -266,  -266,  1644,
    1644,  1687,  1687,  1687,  1687,  1687,  1687,  1687,  1687,  1687,
    1687,  1687,  1687,  1687,  -266,  -266,  -266,  -266,   210,    25,
     224,   234,    39,  1177,   301,   302,   315,    22,    23,  1077,
    -266,  1133,   241,  -266,  -266,   158,  -266,   320,  -266,    89,
     325,   149,   425,   425,   425,   425,   313,   346,  1644,   335,
     150,   314,   339,  -266,  -266,  -266,   763,  1644,  1672,   248,
     181,  -266,  -266,  -266,  -266,  -266,  -266,  -266,  -266,  -266,
    -266,  -266,  -266,  -266,  -266,  -266,  -266,   397,   397,   471,
     129,   645,   645,   645,  -266,   324,  1644,  1644,  1644,  1644,
    1644,  1644,  -266,  -266,   589,  -266,  1644,  1644,  1644,  1644,
     336,   340,    24,   363,   364,   365,  -266,   378,   367,   425,
    -266,    57,   386,   375,   159,  -266,   157,  1644,  1644,  -266,
     383,  -266,  -266,  -266,   311,   384,   953,   387,   385,   389,
     391,    27,   442,   173,  -266,  -266,    11,  -266,   398,   357,
     357,   357,   357,  -266,  -266,  -266,  -266,  -266,  1644,  1644,
     393,   404,   405,    28,   414,    38,   394,   176,  -266,  -266,
    -266,  -266,  -266,  -266,  -266,  -266,  -266,     3,   433,  -266,
     437,    40,  -266,   819,   425,   425,   819,   819,   438,    41,
    -266,   455,  1644,    -4,   819,  -266,  -266,  -266,  -266,   819,
     878,   205,     5,   226,   258,   704,  -266,  -266,  -266,  -266,
     156,  -266,   399,   359,  -266,    58,  -266,  -266,  1644,  1644,
    1644,  1644,  1644,  1644,  1644,  1644,   439,   440,    42,  1400,
    1644,  -266,  -266,  -266,  -266,  -266,  -266,  -266,  -266,  -266,
    -266,  -266,  -266,  -266,  1644,    87,   443,  -266,  -266,  -266,
    -266,  -266,   444,  -266,   456,   136,  -266,   457,  -266,  1644,
    1644,  -266,   461,  -266,  -266,  1644,   134,  -266,  -266,  -266,
    -266,  -266,  -266,   463,   465,   466,   467,   186,   468,   472,
     203,  -266,  -266,  -266,  -266,   464,    45,   477,   492,  1644,
    1644,  1644,  1644,  1644,  1644,   474,   211,  1644,   137,  1560,
    1560,   645,   645,   645,   645,   645,   645,   645,   645,   645,
     645,  -266,  -266,  -266,  -266,  -266,    88,    91,   105,   106,
     132,   133,   397,   397,   530,   475,  1560,  1560,  -266,  1301,
    1357,  -266,  -266,  -266,  -266,  -266,  -266,  -266,  -266,  -266,
    -266,   515,   497,   498,   499,   500,  1020,    46,   501,   357,
     357,   357,   357,   645,  1189,  1245,  -266,   517,  -266,  -266,
    -266,  -266,  -266,  -266,  -266,  -266,  -266,  -266,  -266,  -266,
    -266,  1644,   571,  -266
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -266,  -266,  -266,   316,   -70,   496,     1,   -13,  -266,  -266,
    -266,   206,  -265,  -181,  -266,  -146,  -266,   305,  -266,  -218,
    -266,   322,  -266,  -266,  -266,   -58,  -266,  -266,  -266,  -266,
    -266,   502,  -266,  -266,  -266,  -153,  -266,    -1,  -266,  -266,
    -266,  -266,   480,   462,   268,   229,   265,   -11,  -266,  -266,
     164,  -266,    17
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -205
static const yytype_int16 yytable[] =
{
      68,    36,   226,   166,   329,    92,   354,   221,    94,    95,
      80,   152,   301,   239,   163,   243,    81,    66,   100,   101,
      83,   107,   143,   198,   200,   272,   188,   345,   296,   321,
     102,   103,   308,   309,   311,    36,   115,   116,    89,   324,
     192,   334,   342,   383,    71,   346,   412,   463,   104,   117,
     118,   167,   330,   168,   355,   347,   169,   170,   280,   371,
     126,   171,   331,   127,   356,   164,   302,   153,   128,   129,
     130,   131,   132,   279,    82,   134,   134,   189,    84,   108,
     144,   199,   201,   273,   146,   146,   297,   322,   208,   208,
     211,   193,   208,   140,   140,   146,   146,   325,   162,   335,
     343,   384,   148,   148,   413,   464,   208,   208,   172,   173,
     184,   185,   186,   148,   148,   281,   372,   249,   250,   252,
     194,   255,   256,   257,   416,   417,   418,   419,   420,   421,
     253,   337,   338,   446,   208,   399,    76,   392,   426,    90,
      36,   212,    36,   209,   209,   388,   442,   209,  -204,   443,
     214,   232,   106,   217,   217,   111,   -87,   230,   286,   208,
     284,   209,   209,   444,   445,   240,   241,   -87,   -87,   220,
     220,   225,   225,    69,   299,   400,   142,   327,   427,   113,
     114,   112,   247,   225,   244,   225,   254,   405,   209,   209,
     447,   448,    77,   393,    72,   260,   261,   262,   263,   264,
     265,   215,   233,    68,   409,   266,   267,   268,   269,   287,
    -197,  -143,   423,   336,   209,   285,   339,   340,   428,   428,
     217,   245,    74,    70,   348,   300,   288,   289,   328,   349,
     351,   466,   467,   468,   469,   363,   220,    85,   406,    87,
     154,   150,   206,   165,    73,   428,   428,   151,   456,   456,
     149,   244,   156,    96,   352,   410,   161,   316,   317,   359,
     159,   160,   187,   424,   353,   109,   307,   307,   310,   307,
     314,   314,    75,   456,   456,   357,   190,  -185,  -185,  -185,
    -185,  -185,  -185,  -185,  -185,   358,   191,    86,   245,    88,
     155,   146,   207,  -185,  -185,  -185,  -185,  -185,  -185,  -185,
    -185,   225,   225,    97,  -185,   157,   158,  -185,  -185,   360,
    -185,  -185,  -153,   110,   227,  -156,    35,   373,   374,   375,
     376,   377,   378,   379,   380,   258,   119,   120,   385,   386,
     370,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   195,   430,   387,   178,   179,   180,   181,   124,   125,
     105,   291,   449,   450,   452,   121,   122,   123,   395,   396,
    -153,   196,   228,  -156,   398,   304,   305,   140,   454,   455,
     365,   366,   210,   259,   197,   246,   248,   213,   140,   135,
     137,   176,   177,   470,   182,   183,   229,   231,   146,   146,
     146,   146,   146,   146,   234,   270,   425,  -204,    76,   271,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,   277,  -204,
    -204,  -204,   274,   275,   276,   278,   282,   283,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,   290,   -50,
     293,   294,  -204,   298,   292,   268,   326,  -204,  -204,   133,
     295,  -204,   318,   303,    77,  -204,   344,   364,    21,    22,
      23,    24,    25,   319,   320,   216,   307,   307,   310,   307,
     472,  -204,   251,   323,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,   332,  -204,  -204,  -204,   333,   341,   381,   382,
     389,   390,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,   397,   391,   394,   401,  -204,   402,   403,   404,
     407,  -204,  -204,   411,   408,  -204,   422,   453,    77,  -204,
    -204,   451,   414,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,   415,  -204,  -204,  -204,   457,   458,   459,   460,   461,
     465,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,   471,   473,   141,   175,  -204,   315,   138,     0,     0,
    -204,  -204,     0,     0,  -204,     0,     0,    77,  -204,   -13,
       1,   174,     2,     3,     4,     5,   -13,   -13,   -13,   -13,
     -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,
       0,   -13,   -13,   -13,     0,     0,     0,     0,     0,     0,
      19,    20,   -13,   -13,   -13,   -13,   -13,    26,    27,    67,
       0,     0,     0,     0,    29,     0,     0,     0,     0,    30,
      31,     0,     0,    32,     0,  -204,    76,   -13,  -204,  -204,
    -204,  -204,  -204,     0,     0,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,     0,  -204,  -204,  -204,
       0,     0,     0,     0,     0,     0,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,     0,     0,     0,     0,
    -204,     0,     0,     0,     0,  -204,  -204,     0,     0,  -204,
       0,     0,    77,  -204,  -204,   361,     0,  -204,  -204,  -204,
    -204,   362,     0,     0,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,     0,  -204,  -204,  -204,     0,
       0,     0,     0,     0,     0,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,     0,     0,     0,     0,  -204,
       0,     0,     0,     0,  -204,  -204,     0,     0,  -204,     0,
       0,    77,  -204,   -28,     1,     0,   235,     3,     4,     5,
     -28,     0,     0,   -28,     0,     0,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,     0,   -28,   -28,   133,     0,     0,
       0,     0,     0,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   236,     0,     0,     0,     0,    29,     0,
       0,     0,   237,    30,    31,  -204,     0,    32,     0,  -204,
      76,   -28,  -204,  -204,  -204,  -204,  -204,     0,     0,  -204,
       0,     0,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
       0,  -204,  -204,  -204,     0,     0,     0,     0,     0,     0,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
       0,     0,     0,     0,  -204,     0,     0,     0,     0,  -204,
    -204,     0,     0,  -204,     0,     0,    77,  -204,  -204,   350,
       0,  -204,  -204,  -204,  -204,  -204,     0,     0,  -204,     0,
       0,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,     0,
    -204,  -204,  -204,     0,     0,     0,     0,     0,     0,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,    96,
       0,     0,     0,  -204,     0,     0,     0,     0,  -204,  -204,
       0,     0,  -204,     0,     0,    77,  -204,     0,     0,     0,
       0,     0,     0,  -185,  -185,  -185,  -185,  -185,  -185,  -185,
    -185,     0,     0,     0,    96,     0,     0,     0,     0,  -185,
    -185,  -185,  -185,  -185,  -185,  -185,  -185,  -152,     0,    97,
    -185,    98,    99,  -185,  -185,     0,  -185,  -185,  -185,  -185,
    -185,  -185,  -185,  -185,  -185,  -185,     0,     0,     0,    96,
       0,     0,     0,   -20,     0,  -185,  -185,  -185,  -185,  -185,
    -185,  -185,  -152,     0,    97,     0,    98,    99,   -51,     0,
       0,     0,  -185,  -185,  -185,  -185,  -185,  -185,  -185,  -185,
    -185,     1,     0,     2,     3,     4,     5,     0,   -20,     0,
    -185,  -185,  -185,  -185,  -185,  -185,  -185,  -152,     0,    97,
       0,    98,    99,     0,     0,     0,     0,  -185,     0,     0,
       0,    19,    20,     0,     0,     0,     0,     0,    26,    27,
      67,     0,     0,     0,     0,    29,     0,     0,     0,     0,
      30,    31,     0,     0,    32,     0,     0,     0,     1,   462,
       2,     3,     4,     5,     6,     0,     0,     7,     0,     0,
       8,     9,    10,    11,    12,    13,    14,    15,     0,    16,
      17,    18,     0,     0,     0,     0,     0,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     0,     0,
       0,     0,    29,     0,     0,     0,     0,    30,    31,     0,
       0,    32,     0,     0,   204,   202,     2,     3,     4,     5,
       6,     0,     0,     7,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,     0,    16,    17,    18,     0,     0,
       0,     0,     0,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,     0,     0,     0,     0,    29,     0,
       0,     0,     0,    30,    31,     0,     0,    32,     0,     0,
       1,   205,     2,     3,     4,     5,     6,     0,     0,     7,
    -104,  -104,     8,     9,    10,    11,    12,    13,    14,    15,
      21,    22,    23,    24,    25,     0,     0,    91,     0,     0,
      19,    20,     0,     0,     0,     0,     0,    26,    27,    67,
       0,     0,     0,     0,    29,     0,     0,     0,     0,    30,
      31,     0,     0,    32,     0,     0,     1,  -104,     2,     3,
       4,     5,     6,     0,     0,     7,  -103,  -103,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,    20,     0,     0,
       0,     0,     0,    26,    27,    67,     0,     0,     0,     0,
      29,     0,     0,     0,     0,    30,    31,     0,     0,    32,
       0,     0,     1,  -103,     2,     3,     4,     5,     6,     0,
       0,     7,     0,     0,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    20,     0,     0,     0,     0,     0,    26,
      27,    67,     0,     0,     0,     0,    29,     0,     0,     0,
       0,    30,    31,     0,     0,    32,     0,     0,     1,  -108,
       2,     3,     4,     5,     6,     0,     0,     7,     0,     0,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,    20,
       0,     0,     0,     0,     0,    26,    27,    67,     0,     0,
       0,     1,    29,     2,     3,     4,     5,    30,    31,     0,
       0,    32,     0,     0,     0,  -107,     0,     0,     0,     0,
       0,     0,     0,     0,   -70,     0,     0,     0,     0,     0,
       0,    19,    20,   -70,   -70,   -70,   -70,   -70,    26,    27,
      67,     0,     0,     0,     0,    29,     0,     0,     0,     0,
      30,    31,     0,     0,    32,     0,  -204,     1,   -70,     2,
       3,     4,     5,     6,     0,     0,     7,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,     0,    16,    17,
      18,     0,     0,     0,     0,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
       0,    29,     0,     0,     0,     0,    30,    31,    -3,     1,
      32,     2,     3,     4,     5,     6,     0,     0,     7,     0,
       0,     8,     9,    10,    11,    12,    13,    14,    15,     0,
      16,    17,    18,     0,     0,     0,     0,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,     0,    29,     0,     0,     0,     0,    30,    31,
       0,     1,    32,     2,     3,     4,     5,     6,     0,     0,
       7,     0,     0,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     1,     0,     2,     3,     4,
       5,    19,    20,     0,     0,     0,     0,     0,    26,    27,
      67,     0,     0,    14,    15,    29,     0,     0,   133,     0,
      30,    31,     0,     0,    32,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     0,     0,     0,     1,    29,
       2,     3,     4,     5,    30,    31,     0,     0,    32,     0,
       0,     0,     0,     0,     0,     1,     0,     2,     3,     4,
       5,     0,     0,     0,     0,     0,     0,     0,    19,    20,
       0,     0,     0,     0,     0,    26,    27,    67,     0,     0,
       0,     0,    29,     0,     0,    19,    20,    30,    31,  -204,
       0,    32,    26,    27,    67,     0,     0,     0,     1,    29,
       2,     3,     4,     5,    30,    31,   133,     0,    32,     0,
       0,     0,     0,     0,     0,    21,    22,    23,    24,    25,
       0,     0,   216,     0,     0,     0,     0,     0,    19,    20,
       0,     0,     0,     0,   242,    26,    27,    93,     0,     0,
       0,     0,    29,     0,     0,     0,     0,    30,    31,     0,
       0,    32
};

static const yytype_int16 yycheck[] =
{
       1,     0,   155,     1,     1,    18,     1,   153,    19,    20,
      11,     1,     1,   166,     1,   168,     1,     0,    29,    30,
       1,     1,     1,     1,     1,     1,     1,   292,     1,     1,
      31,    32,   250,   251,   252,    34,    29,    30,    40,     1,
       1,     1,     1,     1,    51,    49,     1,     1,     0,    42,
      43,    49,    49,    51,    49,    59,    54,    55,     1,     1,
      52,    59,    59,    55,    59,    52,    55,    57,    69,    70,
      71,    72,    73,   219,    59,    74,    75,    52,    59,    59,
      59,    59,    59,    59,    85,    86,    59,    59,     1,     1,
       1,    52,     1,    76,    77,    96,    97,    59,    99,    59,
      59,    59,    85,    86,    59,    59,     1,     1,   109,   110,
     121,   122,   123,    96,    97,    58,    58,   187,   188,   189,
     133,   191,   192,   193,   389,   390,   391,   392,   393,   394,
       1,   284,   285,     1,     1,     1,     1,     1,     1,    40,
     139,    52,   141,    56,    56,    58,    58,    56,    13,    58,
       1,     1,    40,   152,   153,    25,     0,   158,     1,     1,
       1,    56,    56,    58,    58,   166,   167,    11,    12,   152,
     153,   154,   155,     1,     1,    41,    13,     1,    41,    27,
      28,    26,     1,   166,     3,   168,    57,     1,    56,    56,
      58,    58,    57,    57,     1,   196,   197,   198,   199,   200,
     201,    52,    52,   204,     1,   206,   207,   208,   209,    52,
      52,    52,     1,   283,    56,    56,   286,   287,   399,   400,
     219,    40,     1,    51,   294,    52,   227,   228,    52,   299,
     300,   449,   450,   451,   452,   305,   219,     1,    52,     1,
       1,    40,     1,     1,    51,   426,   427,    40,   429,   430,
      86,     3,    40,     1,    49,    52,    40,   258,   259,     1,
      96,    97,    52,    52,    59,     1,   249,   250,   251,   252,
     253,   254,    51,   454,   455,    49,    52,    25,    26,    27,
      28,    29,    30,    31,    32,    59,    52,    51,    40,    51,
      51,   292,    51,    41,    42,    43,    44,    45,    46,    47,
      48,   284,   285,    51,    52,    53,    54,    55,    56,    51,
      58,    59,     1,    49,     1,     1,     0,   318,   319,   320,
     321,   322,   323,   324,   325,     1,    44,    45,   329,   330,
     313,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,    40,   400,   344,   115,   116,   117,   118,    31,    32,
      34,    40,   422,   423,   424,    46,    47,    48,   359,   360,
      49,    59,    49,    49,   365,     8,     9,   350,   426,   427,
      11,    12,    52,    49,    59,   169,   170,    52,   361,    74,
      75,   113,   114,   453,   119,   120,    40,    52,   389,   390,
     391,   392,   393,   394,    55,    59,   397,     0,     1,    59,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    40,    22,
      23,    24,    59,    59,    59,    58,    40,    52,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    55,    55,
      55,    52,    45,     1,    57,   446,    52,    50,    51,    24,
      59,    54,    59,    55,    57,    58,     1,    58,    33,    34,
      35,    36,    37,    59,    59,    40,   449,   450,   451,   452,
     471,     0,     1,    59,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    59,    22,    23,    24,    59,    59,    59,    59,
      57,    57,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    51,    57,    57,    52,    45,    52,    52,    52,
      52,    50,    51,    59,    52,    54,    52,    52,    57,    58,
       0,     1,    55,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    59,    22,    23,    24,    40,    59,    59,    59,    59,
      59,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    54,     1,    77,   112,    45,   254,    75,    -1,    -1,
      50,    51,    -1,    -1,    54,    -1,    -1,    57,    58,     0,
       1,   111,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    50,
      51,    -1,    -1,    54,    -1,     0,     1,    58,     3,     4,
       5,     6,     7,    -1,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,
      -1,    -1,    57,    58,     0,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,    -1,
      -1,    57,    58,     0,     1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    10,    -1,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    49,    50,    51,    52,    -1,    54,    -1,     0,
       1,    58,     3,     4,     5,     6,     7,    -1,    -1,    10,
      -1,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    50,
      51,    -1,    -1,    54,    -1,    -1,    57,    58,     0,     1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    10,    -1,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    50,    51,
      -1,    -1,    54,    -1,    -1,    57,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    51,
      52,    53,    54,    55,    56,    -1,    58,    59,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,     1,
      -1,    -1,    -1,    40,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    51,    -1,    53,    54,    55,    -1,
      -1,    -1,    59,    25,    26,    27,    28,    29,    30,    31,
      32,     1,    -1,     3,     4,     5,     6,    -1,    40,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    51,
      -1,    53,    54,    -1,    -1,    -1,    -1,    59,    -1,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      50,    51,    -1,    -1,    54,    -1,    -1,    -1,     1,    59,
       3,     4,     5,     6,     7,    -1,    -1,    10,    -1,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    50,    51,    -1,
      -1,    54,    -1,    -1,     1,    58,     3,     4,     5,     6,
       7,    -1,    -1,    10,    -1,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    50,    51,    -1,    -1,    54,    -1,    -1,
       1,    58,     3,     4,     5,     6,     7,    -1,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      33,    34,    35,    36,    37,    -1,    -1,    40,    -1,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    50,
      51,    -1,    -1,    54,    -1,    -1,     1,    58,     3,     4,
       5,     6,     7,    -1,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,
      -1,    -1,     1,    58,     3,     4,     5,     6,     7,    -1,
      -1,    10,    -1,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    -1,    -1,     1,    58,
       3,     4,     5,     6,     7,    -1,    -1,    10,    -1,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,
      -1,     1,    45,     3,     4,     5,     6,    50,    51,    -1,
      -1,    54,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      50,    51,    -1,    -1,    54,    -1,     0,     1,    58,     3,
       4,     5,     6,     7,    -1,    -1,    10,    -1,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    50,    51,     0,     1,
      54,     3,     4,     5,     6,     7,    -1,    -1,    10,    -1,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    50,    51,
      -1,     1,    54,     3,     4,     5,     6,     7,    -1,    -1,
      10,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    -1,    -1,    19,    20,    45,    -1,    -1,    24,    -1,
      50,    51,    -1,    -1,    54,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,     1,    45,
       3,     4,     5,     6,    50,    51,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    31,    32,    50,    51,    52,
      -1,    54,    38,    39,    40,    -1,    -1,    -1,     1,    45,
       3,     4,     5,     6,    50,    51,    24,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    -1,    -1,    52,    38,    39,    40,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    50,    51,    -1,
      -1,    54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,    10,    13,    14,
      15,    16,    17,    18,    19,    20,    22,    23,    24,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    45,
      50,    51,    54,    61,    62,    63,    66,    67,    68,    69,
      70,    73,    74,    77,    78,    80,    87,    88,    89,    90,
      92,    93,    94,    97,    98,    99,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   111,   112,    40,    97,     1,
      51,    51,     1,    51,     1,    51,     1,    57,    64,   112,
      97,     1,    59,     1,    59,     1,    51,     1,    51,    40,
      40,    40,    67,    40,   107,   107,     1,    51,    53,    54,
     107,   107,    97,    97,     0,    63,    40,     1,    59,     1,
      49,    25,    26,    27,    28,    29,    30,    42,    43,    44,
      45,    46,    47,    48,    31,    32,    52,    55,    97,    97,
      97,    97,    97,    24,    66,    77,    91,    77,    91,    65,
     112,    65,    13,     1,    59,    72,    97,   110,   112,   110,
      40,    40,     1,    57,     1,    51,    40,    53,    54,   110,
     110,    40,    97,     1,    52,     1,     1,    49,    51,    54,
      55,    59,    97,    97,   102,   103,   104,   104,   105,   105,
     105,   105,   106,   106,   107,   107,   107,    52,     1,    52,
      52,    52,     1,    52,    67,    40,    59,    59,     1,    59,
       1,    59,    58,    63,     1,    58,     1,    51,     1,    56,
      52,     1,    52,    52,     1,    52,    40,    66,    75,    76,
     112,    75,    66,    95,    96,   112,    95,     1,    49,    40,
      97,    52,     1,    52,    55,     3,    40,    49,    71,    95,
      97,    97,    52,    95,     3,    40,    71,     1,    71,    64,
      64,     1,    64,     1,    57,    64,    64,    64,     1,    49,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      59,    59,     1,    59,    59,    59,    59,    40,    58,    75,
       1,    58,    40,    52,     1,    56,     1,    52,    97,    97,
      55,    40,    57,    55,    52,    59,     1,    59,     1,     1,
      52,     1,    55,    55,     8,     9,    79,   112,    79,    79,
     112,    79,    81,    82,   112,    81,    97,    97,    59,    59,
      59,     1,    59,    59,     1,    59,    52,     1,    52,     1,
      49,    59,    59,    59,     1,    59,    64,    95,    95,    64,
      64,    59,     1,    59,     1,    72,    49,    59,    64,    64,
       1,    64,    49,    59,     1,    49,    59,    49,    59,     1,
      51,     1,     7,    64,    58,    11,    12,    83,    84,    86,
     112,     1,    58,    97,    97,    97,    97,    97,    97,    97,
      97,    59,    59,     1,    59,    97,    97,    97,    58,    57,
      57,    57,     1,    57,    57,    97,    97,    51,    97,     1,
      41,    52,    52,    52,    52,     1,    52,    52,    52,     1,
      52,    59,     1,    59,    55,    59,    72,    72,    72,    72,
      72,    72,    52,     1,    52,    97,     1,    41,    73,    85,
      85,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,   100,    58,    58,    58,    58,     1,    58,    58,    64,
      64,     1,    64,    52,    85,    85,    73,    40,    59,    59,
      59,    59,    59,     1,    59,    59,    79,    79,    79,    79,
      64,    54,    97,     1
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
        case 13:

/* Line 1455 of yacc.c  */
#line 104 "parser.y"
    {  // Falta '}'
        agregarError(1, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 109 "parser.y"
    {  // Falta '{'
        agregarError(2, yylineno );
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    {  // Falta '='
        agregarError(8, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    {  // Falta '='
        agregarError(8, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    {  // Falta '['
        agregarError(6, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 178 "parser.y"
    {  // Falta ']'
        agregarError(7, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 183 "parser.y"
    {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    {  // Falta '='
        agregarError(8, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 194 "parser.y"
    {
        agregarError(6, yylineno); // Se esperaba '[' y se encontró ']'
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 199 "parser.y"
    {
        agregarError(6, yylineno); // Se esperaba '[' y se encontró ']'
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    {  // Falta '['
        agregarError(6, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 209 "parser.y"
    {  // Falta ']'
        agregarError(7, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 214 "parser.y"
    {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    {
        agregarError(1, yylineno ); //falta  '}' cierre
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 224 "parser.y"
    {
        agregarError(2, yylineno ); //falta  '}' cierre
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 229 "parser.y"
    {
        agregarError(6, yylineno); // Se esperaba '[' y se encontró ']'
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 234 "parser.y"
    {
        agregarError(6, yylineno); // Se esperaba '['
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 250 "parser.y"
    {
        agregarError(11, yylineno ); //falta  ':' 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 265 "parser.y"
    {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 274 "parser.y"
    {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 279 "parser.y"
    {
        agregarError(1, yylineno ); //falta  '}' cierre
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 284 "parser.y"
    {
        agregarError(2, yylineno ); //falta  '{' cierre
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 298 "parser.y"
    {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 304 "parser.y"
    {  // Falta '='
        agregarError(8, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 309 "parser.y"
    {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 318 "parser.y"
    {  // Falta ';'  comprobar usando todo ya que puede causar conflicto, sino eliminar  
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 324 "parser.y"
    {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 329 "parser.y"
    {
        agregarError(3, yylineno ); //falta  '(' abrir
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 334 "parser.y"
    {
        agregarError(4, yylineno ); //falta  ')' cierre
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 340 "parser.y"
    {
        agregarError(3, yylineno ); //falta  '(' abrir
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 345 "parser.y"
    {
        agregarError(4, yylineno ); //falta  ')' cierre
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 360 "parser.y"
    {  // Falta '('
        agregarError(3, yylineno);
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 365 "parser.y"
    {  // Falta ')'
        agregarError(4, yylineno);
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 370 "parser.y"
    {  // Falta bloque
        agregarError(1, yylineno);  // Reutilizamos "falta '}'" como indicador de bloque incompleto
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 380 "parser.y"
    {  // Falta '('
        agregarError(3, yylineno);
        yyerrok; numErroresSintacticos++;
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 384 "parser.y"
    {  // Falta ')'
        agregarError(4, yylineno);
        yyerrok; numErroresSintacticos++;
    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 388 "parser.y"
    {  // Falta bloque
        agregarError(1, yylineno);
        yyerrok; numErroresSintacticos++;
    ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 393 "parser.y"
    {
        yyerror("ERROR SINTACTICO: se esperaba 'sinosi', no 'sino si'");
        agregarError(9, yylineno);
        yyerrok; 
        numErroresSintacticos++;
    ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 399 "parser.y"
    {  // Falta bloque
        agregarError(1, yylineno);
        yyerrok; numErroresSintacticos++;
    ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 408 "parser.y"
    {
        agregarError(1, yylineno ); //falta  '}' cierre
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 413 "parser.y"
    {
        agregarError(2, yylineno ); //falta  '{' cierre
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 436 "parser.y"
    {  // Falta ':'
        agregarError(10, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 450 "parser.y"
    {  // Falta ':'
        agregarError(10, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 460 "parser.y"
    {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 475 "parser.y"
    {
        agregarError(3, yylineno ); //falta  '(' abrir
        yyerrok;
        numErroresSintacticos++;
        //fprintf(stderr, "   : '(' de abertura. Linea: %d - %d - %d \n", yyerrok, yylineno, numErroresSintacticos);
    ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 481 "parser.y"
    {
        agregarError(4, yylineno ); //falta  ')' cierre
        yyerrok;
        numErroresSintacticos++;
        //fprintf(stderr, "   : ')' de abertura. Linea: %d - %d - %d \n", yyerrok, yylineno, numErroresSintacticos);
    ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 491 "parser.y"
    {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 496 "parser.y"
    {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 501 "parser.y"
    {
        agregarError(3, yylineno ); //falta  '(' abrir
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 506 "parser.y"
    {
        agregarError(4, yylineno ); //falta  ')' cierre
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 512 "parser.y"
    {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 517 "parser.y"
    {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 522 "parser.y"
    {
        agregarError(3, yylineno ); //falta  '(' abrir
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 527 "parser.y"
    {
        agregarError(4, yylineno ); //falta  ')' cierre
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 536 "parser.y"
    {  // Falta '='
        agregarError(8, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 545 "parser.y"
    {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 550 "parser.y"
    {
        agregarError(3, yylineno ); //falta  '(' abrir
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 555 "parser.y"
    {
        agregarError(4, yylineno ); //falta  ')' cierre
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 564 "parser.y"
    {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 573 "parser.y"
    {
        agregarError(3, yylineno ); //falta  '(' abrir
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 578 "parser.y"
    {
        agregarError(2, yylineno); // Falta llave de apertura {
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 583 "parser.y"
    {
        agregarError(4, yylineno ); //falta  ')' cierre
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 589 "parser.y"
    {
        agregarError(3, yylineno ); //falta  '(' abrir
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 594 "parser.y"
    {
        agregarError(4, yylineno ); //falta  ')' cierre
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 599 "parser.y"
    {
        agregarError(2, yylineno); // Falta llave de apertura {
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 609 "parser.y"
    {
        agregarError(11, yylineno ); //falta  ')' cierre
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 628 "parser.y"
    {  // Falta '='
        agregarError(8, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 639 "parser.y"
    {  // Falta '['
        agregarError(6, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 644 "parser.y"
    {  // Falta ']'
        agregarError(7, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 707 "parser.y"
    {
        agregarError(3, yylineno ); //falta  '(' abrir
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 712 "parser.y"
    {
        agregarError(4, yylineno ); //falta  ')' cierre
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 718 "parser.y"
    {  // Falta '['
        agregarError(6, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 723 "parser.y"
    {  // Falta ']'
        agregarError(7, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 730 "parser.y"
    {
        agregarError(3, yylineno ); //falta  '(' abrir
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 735 "parser.y"
    {
        agregarError(4, yylineno ); //falta  ')' cierre
        yyerrok;
        numErroresSintacticos++;
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2932 "parser.tab.c"
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
#line 793 "parser.y"

void yyerror(const char *msg) {
    errores_sintacticos++;
    // // Si el mensaje es el que pone Bison por defecto
    // if (strcmp(msg, "syntax error") == 0) {
    //     fprintf(stderr, "ERROR SINTACTICO: Se encontro un error inesperado en la linea %d\n", yylineno);
    // } else {
    //     fprintf(stderr, "ERROR SINTACTICO: %s (linea %d)\n", msg, yylineno);
    // }
}
int errorYaRegistrado(int tipoError, int linea) {
    int i;
    for ( i = 0; i < numErroresSintacticos; i++) {
        if (listaErrores[i].tipoError == tipoError && listaErrores[i].linea == linea) {
            return 1; // ya existe
        }
    }
   // fprintf(stderr, "   Entro: i: ", i);
    return 0;
}

void agregarError(int tipoError, int linea) {
    if (numErroresSintacticos >= MAX_ERRORES) return;
    if (errorYaRegistrado(tipoError, linea)) return;

    listaErrores[numErroresSintacticos].tipoError = tipoError;
    listaErrores[numErroresSintacticos].linea = linea;
    numErroresSintacticos++;
}

void mostrarErrores() {
    for (int i = 0; i < numErroresSintacticos; i++) {
        switch (listaErrores[i].tipoError) {
            case 1:
                fprintf(stderr, "   Error sintactico: falta simbolo '}' de cierre. Linea:  %d\n", listaErrores[i].linea);
                break;
            case 2:
                fprintf(stderr, "   Error sintactico: falta simbolo '{ ' de abertura. Linea: %d\n", listaErrores[i].linea);
                break;
            case 3:
                fprintf(stderr, "   Error sintactico: falta simbolo '(' de abertura. Linea: %d\n", listaErrores[i].linea);
                break;
            case 4:
                fprintf(stderr, "   Error sintactico: falta simbolo ')' de cierre. Linea: %d\n", listaErrores[i].linea);
                break;
            case 5:
                fprintf(stderr, "   Error sintactico: falta simbolo ';' de cierre. Linea::  %d\n", listaErrores[i].linea);
                break;
            case 6:
                fprintf(stderr, "   Error sintactico: falta simbolo '[' de abertura. Linea:  %d\n", listaErrores[i].linea);
                break;
            case 7:
                fprintf(stderr, "   Error sintactico: falta simbolo ']' de cierre. Linea:  %d\n", listaErrores[i].linea);
                break;
            case 8:
                fprintf(stderr, "   Error sintactico: falta simbolo '=' de asignacion. Linea:  %d\n", listaErrores[i].linea);
                break;
           case 9:
                fprintf(stderr, "   Error sintactico: se uso 'sino si' en lugar de 'sinosi'. Linea: %d\n", listaErrores[i].linea);
                break;
            case 10:
                fprintf(stderr, "   Error sintactico: falta simbolo ':' de asignacion. Linea:  %d\n", listaErrores[i].linea);
                break;
            case 11:
                fprintf(stderr, "   Error sintactico: falta simbolo ',' de asignacion. Linea:  %d\n", listaErrores[i].linea);
                break;
                /*default: //error cuando no se puede identificar el error
                fprintf(stderr, "   Error sintactico desconocido perros %d\n", listaErrores[i].linea);
                break;*/
        }
    }
}
