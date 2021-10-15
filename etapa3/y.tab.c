/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "parser.y"

    #include "hash.h"
    #include "ast.h"
    #include <stdlib.h>
    int yyerror();
    int getLineNumber();
    int yylex();
    AST *mainAST;
    

#line 81 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    KW_CHAR = 258,
    KW_INT = 259,
    KW_FLOAT = 260,
    KW_DATA = 261,
    KW_IF = 262,
    KW_ELSE = 263,
    KW_UNTIL = 264,
    KW_COMEFROM = 265,
    KW_READ = 266,
    KW_PRINT = 267,
    KW_RETURN = 268,
    OPERATOR_LE = 269,
    OPERATOR_GE = 270,
    OPERATOR_EQ = 271,
    OPERATOR_DIF = 272,
    OPERATOR_RANGE = 273,
    TK_IDENTIFIER = 274,
    LIT_INTEGER = 275,
    LIT_CHAR = 276,
    LIT_STRING = 277,
    TOKEN_ERROR = 278
  };
#endif
/* Tokens.  */
#define KW_CHAR 258
#define KW_INT 259
#define KW_FLOAT 260
#define KW_DATA 261
#define KW_IF 262
#define KW_ELSE 263
#define KW_UNTIL 264
#define KW_COMEFROM 265
#define KW_READ 266
#define KW_PRINT 267
#define KW_RETURN 268
#define OPERATOR_LE 269
#define OPERATOR_GE 270
#define OPERATOR_EQ 271
#define OPERATOR_DIF 272
#define OPERATOR_RANGE 273
#define TK_IDENTIFIER 274
#define LIT_INTEGER 275
#define LIT_CHAR 276
#define LIT_STRING 277
#define TOKEN_ERROR 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "parser.y"

    HASH_NODE *symbol;
    AST *ast;

#line 184 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   281

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

#define YYUNDEFTOK  2
#define YYMAXUTOK   278


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    26,     2,
      41,    42,    32,    30,    43,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    36,
      24,    37,    25,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,    28,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,    27,    35,    29,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    87,    87,    91,    95,    99,   100,   101,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   119,   120,   121,
     124,   125,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   157,   158,   163,   164,   165,   168,
     169,   173,   174,   178,   179,   185,   186,   187,   191,   192,
     197,   203,   204,   210,   211,   212,   213,   214,   215,   219,
     220,   223,   227,   228,   229,   235,   236,   240,   244,   245,
     246,   247
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_CHAR", "KW_INT", "KW_FLOAT",
  "KW_DATA", "KW_IF", "KW_ELSE", "KW_UNTIL", "KW_COMEFROM", "KW_READ",
  "KW_PRINT", "KW_RETURN", "OPERATOR_LE", "OPERATOR_GE", "OPERATOR_EQ",
  "OPERATOR_DIF", "OPERATOR_RANGE", "TK_IDENTIFIER", "LIT_INTEGER",
  "LIT_CHAR", "LIT_STRING", "TOKEN_ERROR", "'<'", "'>'", "'&'", "'|'",
  "'^'", "'~'", "'+'", "'-'", "'*'", "'/'", "'{'", "'}'", "';'", "'='",
  "'['", "']'", "':'", "'('", "')'", "','", "$accept", "program",
  "data_decl", "decl_block", "cmd_list", "cmd", "flow_control", "block",
  "expression", "expression_list", "functioncall", "parameterslist",
  "parameter", "functionlist", "function", "parameterslist_init",
  "parameter_init", "declist", "dec", "litlist", "range_values",
  "literal_withstring", "literal", "identifier", "type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    60,    62,    38,   124,    94,   126,
      43,    45,    42,    47,   123,   125,    59,    61,    91,    93,
      58,    40,    41,    44
};
# endif

#define YYPACT_NINF (-109)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-82)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,   -21,    18,  -109,    34,     5,  -109,  -109,  -109,  -109,
      -1,    -4,   -24,  -109,     5,     1,  -109,    34,     8,    40,
    -109,    40,  -109,    29,  -109,    79,    67,  -109,    86,    69,
     106,    90,    44,     2,  -109,    94,    40,  -109,  -109,   107,
      53,   108,   110,   129,    73,  -109,   107,    19,   125,    40,
      40,    44,   127,   130,   136,    52,    52,  -109,  -109,   134,
     141,  -109,  -109,   119,  -109,   143,   107,  -109,   150,  -109,
      44,    52,    52,    52,  -109,  -109,  -109,  -109,    52,    52,
      88,  -109,  -109,   203,   241,  -109,   115,    52,    52,  -109,
    -109,  -109,    44,  -109,   128,   148,   241,   105,   168,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    57,  -109,  -109,   241,   201,  -109,   195,
     195,  -109,   248,   248,   248,   248,   248,   248,   248,   105,
      84,    84,  -109,  -109,  -109,   221,  -109,  -109,  -109,  -109,
     104,  -109,  -109,   151,   181,  -109,  -109,  -109,    68,   149,
      52,   195,   153,  -109,   241,  -109,  -109
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,    81,    54,     1,    80,    78,    79,
       0,     0,     0,     3,    54,     0,     4,    81,     0,     0,
      53,     0,    61,    71,    75,     0,     0,    77,     0,     0,
       0,     0,     0,    81,    71,     0,     0,    76,    63,     0,
       0,     0,     0,    67,     0,    56,     0,    81,     0,     0,
       0,    70,     0,     0,     0,     0,     0,    21,     7,     0,
       0,    13,    14,    16,    57,    59,     0,    60,    66,    64,
      70,     0,     0,     0,    39,    42,    41,    43,     0,     0,
      44,    10,    40,    22,    11,    20,     6,     0,     0,    15,
      58,    55,    70,    69,     0,     0,    12,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     5,     8,     0,    65,     0,
       0,    33,    34,    35,    36,    37,    28,    29,    31,    30,
      24,    25,    26,    27,    45,     0,    73,    72,    74,    47,
       0,    52,    51,     0,    17,    19,    23,    48,     0,     0,
       0,     0,    50,    46,     9,    18,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,  -109,  -109,   111,  -108,  -109,    45,   -52,    92,
    -109,    54,    61,   197,  -109,   147,   166,   202,  -109,   -30,
     190,  -109,   -17,   -19,    28
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,    59,    60,    61,    62,    80,    81,
      82,   149,   140,    13,    14,    48,    40,    10,    11,    69,
      25,   141,    70,    83,    12
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    26,    29,     1,    84,     7,     8,     9,     7,     8,
       9,   144,   145,     4,    18,    38,    19,    43,     6,    94,
      95,    96,     7,     8,     9,    63,    97,    98,    23,    24,
      67,    68,    17,    15,    16,   116,   117,     7,     8,     9,
      93,    21,    15,   155,    39,   -81,    89,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    27,
     135,    41,   118,    74,    37,    24,   114,    63,   -76,   -62,
     -68,    27,    75,    76,    77,    41,    27,   136,   137,   138,
      52,    78,    53,    54,    45,    55,    56,    27,   136,   137,
     138,    64,    27,    79,   142,    46,    47,    30,   154,   139,
      63,    63,    99,   100,   101,   102,    31,    44,    57,    58,
      33,    91,   103,   104,   105,   106,   109,   110,   107,   108,
     109,   110,    52,    32,    53,    54,    34,    55,    56,   142,
      36,   111,    63,    42,    27,   107,   108,   109,   110,    37,
      24,    44,    99,   100,   101,   102,   147,   148,    49,    44,
      50,    58,   103,   104,   105,   106,    87,    88,   107,   108,
     109,   110,    99,   100,   101,   102,    51,    66,    71,    85,
     119,    72,   103,   104,   105,   106,    73,    86,   107,   108,
     109,   110,    99,   100,   101,   102,    47,    92,   150,   151,
     120,   153,   103,   104,   105,   106,   148,   115,   107,   108,
     109,   110,    52,   134,    53,    54,   156,    55,    56,   152,
     121,    20,    90,    65,    27,    99,   100,   101,   102,    22,
      35,     0,     0,    37,    24,   103,   104,   105,   106,    44,
       0,   107,   108,   109,   110,    99,   100,   101,   102,     0,
     143,   112,     0,     0,   113,   103,   104,   105,   106,     0,
       0,   107,   108,   109,   110,    99,   100,   101,   102,     0,
     146,     0,     0,     0,     0,   103,   104,   105,   106,     0,
       0,   107,   108,   109,   110,   106,     0,     0,   107,   108,
     109,   110
};

static const yytype_int16 yycheck[] =
{
      19,    18,    21,     6,    56,     3,     4,     5,     3,     4,
       5,   119,   120,    34,    38,    32,    40,    36,     0,    71,
      72,    73,     3,     4,     5,    44,    78,    79,    20,    21,
      49,    50,    36,     5,    35,    87,    88,     3,     4,     5,
      70,    40,    14,   151,    42,    40,    63,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    19,
     112,    33,    92,    11,    20,    21,    83,    86,    39,    35,
      36,    19,    20,    21,    22,    47,    19,    20,    21,    22,
       7,    29,     9,    10,    39,    12,    13,    19,    20,    21,
      22,    46,    19,    41,   113,    42,    43,    18,   150,    42,
     119,   120,    14,    15,    16,    17,    39,    34,    35,    36,
      41,    66,    24,    25,    26,    27,    32,    33,    30,    31,
      32,    33,     7,    37,     9,    10,    20,    12,    13,   148,
      40,    43,   151,    39,    19,    30,    31,    32,    33,    20,
      21,    34,    14,    15,    16,    17,    42,    43,    40,    34,
      40,    36,    24,    25,    26,    27,    37,    38,    30,    31,
      32,    33,    14,    15,    16,    17,    37,    42,    41,    35,
      42,    41,    24,    25,    26,    27,    40,    36,    30,    31,
      32,    33,    14,    15,    16,    17,    43,    37,    37,     8,
      42,    42,    24,    25,    26,    27,    43,    86,    30,    31,
      32,    33,     7,   111,     9,    10,   152,    12,    13,   148,
      42,    14,    65,    47,    19,    14,    15,    16,    17,    17,
      30,    -1,    -1,    20,    21,    24,    25,    26,    27,    34,
      -1,    30,    31,    32,    33,    14,    15,    16,    17,    -1,
      39,    38,    -1,    -1,    41,    24,    25,    26,    27,    -1,
      -1,    30,    31,    32,    33,    14,    15,    16,    17,    -1,
      39,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
      -1,    30,    31,    32,    33,    27,    -1,    -1,    30,    31,
      32,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    45,    46,    34,    47,     0,     3,     4,     5,
      61,    62,    68,    57,    58,    68,    35,    36,    38,    40,
      57,    40,    61,    20,    21,    64,    66,    19,    67,    67,
      18,    39,    37,    41,    20,    64,    40,    20,    66,    42,
      60,    68,    39,    67,    34,    51,    42,    43,    59,    40,
      40,    37,     7,     9,    10,    12,    13,    35,    36,    48,
      49,    50,    51,    67,    51,    60,    42,    67,    67,    63,
      66,    41,    41,    40,    11,    20,    21,    22,    29,    41,
      52,    53,    54,    67,    52,    35,    36,    37,    38,    66,
      59,    51,    37,    63,    52,    52,    52,    52,    52,    14,
      15,    16,    17,    24,    25,    26,    27,    30,    31,    32,
      33,    43,    38,    41,    66,    48,    52,    52,    63,    42,
      42,    42,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    53,    52,    20,    21,    22,    42,
      56,    65,    67,    39,    49,    49,    39,    42,    43,    55,
      37,     8,    56,    42,    52,    49,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    47,    48,    48,    48,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    50,    50,    50,
      51,    51,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    53,    53,    54,    54,    54,    55,
      55,    56,    56,    57,    57,    58,    58,    58,    59,    59,
      60,    61,    61,    62,    62,    62,    62,    62,    62,    63,
      63,    64,    65,    65,    65,    66,    66,    67,    68,    68,
      68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     3,     2,     1,     3,     6,
       2,     2,     3,     1,     1,     2,     1,     5,     7,     5,
       3,     2,     1,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     3,     5,     3,     4,     3,
       0,     1,     1,     2,     0,     8,     6,     7,     3,     0,
       3,     3,     0,     5,     8,    10,     8,     6,     0,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
      yychar = yylex ();
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 87 "parser.y"
                    { (yyval.ast) = (yyvsp[0].ast);  mainAST = (yyval.ast);}
#line 1491 "y.tab.c"
    break;

  case 3:
#line 91 "parser.y"
                                        { (yyval.ast) = astCreate(AST_DATA,0,(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[0].ast),0); }
#line 1497 "y.tab.c"
    break;

  case 4:
#line 95 "parser.y"
                              { (yyval.ast) = astCreate(AST_DECL_BLOCK,0,(yyvsp[-1].ast),0,0,0); }
#line 1503 "y.tab.c"
    break;

  case 5:
#line 99 "parser.y"
                            { (yyval.ast) = astCreate(AST_LCMD,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1509 "y.tab.c"
    break;

  case 6:
#line 100 "parser.y"
                                { (yyval.ast) = astCreate(AST_LCMD,0,(yyvsp[-1].ast),0,0,0); }
#line 1515 "y.tab.c"
    break;

  case 7:
#line 101 "parser.y"
                        { (yyval.ast) = astCreate(AST_LCMD,0,0,0,0,0); }
#line 1521 "y.tab.c"
    break;

  case 8:
#line 106 "parser.y"
                                    { (yyval.ast) = astCreate(AST_ATTR,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1527 "y.tab.c"
    break;

  case 9:
#line 107 "parser.y"
                                                       { (yyval.ast) = astCreate(AST_VEC_ATTR,0,(yyvsp[-5].ast),(yyvsp[-3].ast),(yyvsp[0].ast),0); }
#line 1533 "y.tab.c"
    break;

  case 10:
#line 108 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_PRINT,0,(yyvsp[0].ast),0,0,0); }
#line 1539 "y.tab.c"
    break;

  case 11:
#line 109 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_RETURN,0,(yyvsp[0].ast),0,0,0); }
#line 1545 "y.tab.c"
    break;

  case 12:
#line 110 "parser.y"
                                      { (yyval.ast) = astCreate(AST_COMEFROM,0,(yyvsp[0].ast),0,0,0); }
#line 1551 "y.tab.c"
    break;

  case 13:
#line 111 "parser.y"
                                                     { (yyval.ast) = astCreate(AST_FLOW_CONTROL,0,(yyvsp[0].ast),0,0,0); }
#line 1557 "y.tab.c"
    break;

  case 14:
#line 112 "parser.y"
                                                     { (yyval.ast) = (yyvsp[0].ast); }
#line 1563 "y.tab.c"
    break;

  case 15:
#line 113 "parser.y"
                                                { (yyval.ast) = astCreate(AST_IDENLIT,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0); }
#line 1569 "y.tab.c"
    break;

  case 16:
#line 114 "parser.y"
                 { (yyval.ast) = astCreate(AST_IDEN,0,(yyvsp[0].ast),0,0,0); }
#line 1575 "y.tab.c"
    break;

  case 17:
#line 119 "parser.y"
                                    { (yyval.ast) = astCreate(AST_IF,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1581 "y.tab.c"
    break;

  case 18:
#line 120 "parser.y"
                                               { (yyval.ast) = astCreate(AST_IF_ELSE,0,(yyvsp[-4].ast),(yyvsp[-2].ast),(yyvsp[0].ast),0); }
#line 1587 "y.tab.c"
    break;

  case 19:
#line 121 "parser.y"
                                           { (yyval.ast) = astCreate(AST_UNTIL,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1593 "y.tab.c"
    break;

  case 20:
#line 124 "parser.y"
                        { (yyval.ast) = astCreate(AST_BLOCK,0,(yyvsp[-1].ast),0,0,0); }
#line 1599 "y.tab.c"
    break;

  case 21:
#line 125 "parser.y"
           {(yyval.ast) = astCreate(AST_BLOCK,0,0,0,0,0);}
#line 1605 "y.tab.c"
    break;

  case 22:
#line 132 "parser.y"
                { (yyval.ast) = astCreate(AST_IDEN,0,(yyvsp[0].ast),0,0,0); }
#line 1611 "y.tab.c"
    break;

  case 23:
#line 133 "parser.y"
                                        { (yyval.ast) = astCreate(AST_VEC_SYMBOL,0,(yyvsp[-3].ast),(yyvsp[-1].ast),0,0); }
#line 1617 "y.tab.c"
    break;

  case 24:
#line 134 "parser.y"
                                    { (yyval.ast) = astCreate(AST_ADD,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1623 "y.tab.c"
    break;

  case 25:
#line 135 "parser.y"
                                    { (yyval.ast) = astCreate(AST_SUB,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1629 "y.tab.c"
    break;

  case 26:
#line 136 "parser.y"
                                    { (yyval.ast) = astCreate(AST_MUL,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1635 "y.tab.c"
    break;

  case 27:
#line 137 "parser.y"
                                    { (yyval.ast) = astCreate(AST_DIV,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1641 "y.tab.c"
    break;

  case 28:
#line 138 "parser.y"
                                    { (yyval.ast) = astCreate(AST_LES,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1647 "y.tab.c"
    break;

  case 29:
#line 139 "parser.y"
                                    { (yyval.ast) = astCreate(AST_GRE,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1653 "y.tab.c"
    break;

  case 30:
#line 140 "parser.y"
                                    { (yyval.ast) = astCreate(AST_OR,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1659 "y.tab.c"
    break;

  case 31:
#line 141 "parser.y"
                                    { (yyval.ast) = astCreate(AST_AND,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1665 "y.tab.c"
    break;

  case 32:
#line 142 "parser.y"
                         { (yyval.ast) = astCreate(AST_NOT,0,(yyvsp[0].ast),0,0,0); }
#line 1671 "y.tab.c"
    break;

  case 33:
#line 143 "parser.y"
                                    { (yyval.ast) = astCreate(AST_PARENTHESIS,0,0,0,0,(yyvsp[-1].ast)); }
#line 1677 "y.tab.c"
    break;

  case 34:
#line 144 "parser.y"
                                                { (yyval.ast) = astCreate(AST_LE,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1683 "y.tab.c"
    break;

  case 35:
#line 145 "parser.y"
                                                { (yyval.ast) = astCreate(AST_GE,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1689 "y.tab.c"
    break;

  case 36:
#line 146 "parser.y"
                                                { (yyval.ast) = astCreate(AST_EQ,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1695 "y.tab.c"
    break;

  case 37:
#line 147 "parser.y"
                                                { (yyval.ast) = astCreate(AST_DIF,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1701 "y.tab.c"
    break;

  case 38:
#line 148 "parser.y"
                                            { (yyval.ast) = astCreate(AST_IDENLIT,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0); }
#line 1707 "y.tab.c"
    break;

  case 39:
#line 149 "parser.y"
                                            { (yyval.ast) = astCreate(AST_READ,0,0,0,0,0); }
#line 1713 "y.tab.c"
    break;

  case 40:
#line 150 "parser.y"
                                               { (yyval.ast) = astCreate(AST_FUNCTION_CALL,0,(yyvsp[0].ast),0,0,0); }
#line 1719 "y.tab.c"
    break;

  case 41:
#line 151 "parser.y"
                         { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1725 "y.tab.c"
    break;

  case 42:
#line 152 "parser.y"
                       { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1731 "y.tab.c"
    break;

  case 43:
#line 153 "parser.y"
                        { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1737 "y.tab.c"
    break;

  case 44:
#line 157 "parser.y"
                                            { (yyval.ast) = astCreate(AST_EXP_LIST,0,(yyvsp[0].ast),0,0,0); }
#line 1743 "y.tab.c"
    break;

  case 45:
#line 158 "parser.y"
                                            { (yyval.ast) = astCreate(AST_EXP_LIST,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1749 "y.tab.c"
    break;

  case 46:
#line 163 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_FUNCTION_CALL,0,(yyvsp[-4].ast),(yyvsp[-2].ast),(yyvsp[-1].ast),0); }
#line 1755 "y.tab.c"
    break;

  case 47:
#line 164 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_FUNCTION_CALL,0,(yyvsp[-2].ast),0,0,0); }
#line 1761 "y.tab.c"
    break;

  case 48:
#line 165 "parser.y"
                                      { (yyval.ast) = astCreate(AST_FUNCTION_CALL,0,(yyvsp[-3].ast),(yyvsp[-1].ast),0,0); }
#line 1767 "y.tab.c"
    break;

  case 49:
#line 168 "parser.y"
                                                             { (yyval.ast) = astCreate(AST_PARAMETER_LIST,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0); }
#line 1773 "y.tab.c"
    break;

  case 50:
#line 169 "parser.y"
        { (yyval.ast) = 0; }
#line 1779 "y.tab.c"
    break;

  case 51:
#line 173 "parser.y"
                           { (yyval.ast) = astCreate(AST_PARAMETER,0,(yyvsp[0].ast),0,0,0); }
#line 1785 "y.tab.c"
    break;

  case 52:
#line 174 "parser.y"
                            { (yyval.ast) = astCreate(AST_PARAMETER,0,(yyvsp[0].ast),0,0,0); }
#line 1791 "y.tab.c"
    break;

  case 53:
#line 178 "parser.y"
                                            { (yyval.ast) = astCreate(AST_FUNC_LIST,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0); }
#line 1797 "y.tab.c"
    break;

  case 54:
#line 179 "parser.y"
                                            {(yyval.ast) = 0;}
#line 1803 "y.tab.c"
    break;

  case 55:
#line 185 "parser.y"
                                                                            { (yyval.ast) = astCreate(AST_FUNC,(yyvsp[-7].ast),(yyvsp[-5].ast),(yyvsp[-3].ast),(yyvsp[-2].ast),(yyvsp[0].ast)); }
#line 1809 "y.tab.c"
    break;

  case 56:
#line 186 "parser.y"
                                              { (yyval.ast) = astCreate(AST_FUNC,(yyvsp[-5].ast),(yyvsp[-3].ast),(yyvsp[0].ast),0,0); }
#line 1815 "y.tab.c"
    break;

  case 57:
#line 187 "parser.y"
                                                         { (yyval.ast) = astCreate(AST_FUNC,(yyvsp[-6].ast),(yyvsp[-4].ast),(yyvsp[-2].ast),(yyvsp[0].ast),0); }
#line 1821 "y.tab.c"
    break;

  case 58:
#line 191 "parser.y"
                                                                            { (yyval.ast) = astCreate(AST_PARAMETER_LIST,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0); }
#line 1827 "y.tab.c"
    break;

  case 59:
#line 192 "parser.y"
                                     { (yyval.ast) = 0; }
#line 1833 "y.tab.c"
    break;

  case 60:
#line 197 "parser.y"
                             { (yyval.ast) = astCreate(AST_PARAMETER,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1839 "y.tab.c"
    break;

  case 61:
#line 203 "parser.y"
                      { (yyval.ast) = astCreate(AST_DEC_LIST,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0);}
#line 1845 "y.tab.c"
    break;

  case 62:
#line 204 "parser.y"
                    {(yyval.ast)=0;}
#line 1851 "y.tab.c"
    break;

  case 63:
#line 210 "parser.y"
                                            { (yyval.ast) = astCreate(AST_VAR_DEC,0,(yyvsp[-4].ast),(yyvsp[-2].ast),(yyvsp[0].ast),0); }
#line 1857 "y.tab.c"
    break;

  case 64:
#line 211 "parser.y"
                                                      { (yyval.ast) = astCreate(AST_VEC_DEC,(yyvsp[-7].ast),(yyvsp[-5].ast),(yyvsp[-2].ast),(yyvsp[0].ast),0); }
#line 1863 "y.tab.c"
    break;

  case 65:
#line 212 "parser.y"
                                                                                         { (yyval.ast) = astCreate(AST_VEC_DEC_RANGE,(yyvsp[-9].ast),(yyvsp[-7].ast),(yyvsp[-5].ast),(yyvsp[-2].ast),(yyvsp[0].ast)); }
#line 1869 "y.tab.c"
    break;

  case 66:
#line 213 "parser.y"
                                                                                  { (yyval.ast) = astCreate(AST_VEC_DEC_RANGE,(yyvsp[-7].ast),(yyvsp[-5].ast),(yyvsp[-3].ast),(yyvsp[0].ast),0); }
#line 1875 "y.tab.c"
    break;

  case 67:
#line 214 "parser.y"
                                            { (yyval.ast) = astCreate(AST_VEC_DEC,(yyvsp[-5].ast),(yyvsp[-3].ast),(yyvsp[0].ast),0,0);}
#line 1881 "y.tab.c"
    break;

  case 68:
#line 215 "parser.y"
      {(yyval.ast)=0;}
#line 1887 "y.tab.c"
    break;

  case 69:
#line 219 "parser.y"
                        { (yyval.ast) = astCreate(AST_LIT_LIST,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0);}
#line 1893 "y.tab.c"
    break;

  case 70:
#line 220 "parser.y"
                        {(yyval.ast) = 0;}
#line 1899 "y.tab.c"
    break;

  case 71:
#line 223 "parser.y"
                      { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1905 "y.tab.c"
    break;

  case 72:
#line 227 "parser.y"
                        { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1911 "y.tab.c"
    break;

  case 73:
#line 228 "parser.y"
                        { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1917 "y.tab.c"
    break;

  case 74:
#line 229 "parser.y"
                        { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1923 "y.tab.c"
    break;

  case 75:
#line 235 "parser.y"
                        { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1929 "y.tab.c"
    break;

  case 76:
#line 236 "parser.y"
                        { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1935 "y.tab.c"
    break;

  case 77:
#line 240 "parser.y"
                        { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1941 "y.tab.c"
    break;

  case 78:
#line 244 "parser.y"
                      { (yyval.ast) = astCreate(AST_INT,0,0,0,0,0); }
#line 1947 "y.tab.c"
    break;

  case 79:
#line 245 "parser.y"
                    { (yyval.ast) = astCreate(AST_FLOAT,0,0,0,0,0); }
#line 1953 "y.tab.c"
    break;

  case 80:
#line 246 "parser.y"
                    { (yyval.ast) = astCreate(AST_CHAR,0,0,0,0,0); }
#line 1959 "y.tab.c"
    break;

  case 81:
#line 247 "parser.y"
                { (yyval.ast) = 0; }
#line 1965 "y.tab.c"
    break;


#line 1969 "y.tab.c"

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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 250 "parser.y"

int yyerror() {
    fprintf(stderr, "Syntax error at line %d \n", getLineNumber());
    exit(3);
}
