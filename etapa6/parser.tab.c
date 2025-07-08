/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "asd.h"
#include "token.h"
#include "pilha_tabelas.h"
#include "tabela_simbolos.h"
#include "argumento.h"
#include "erros.h"
#include "utils.h"
#include "helpers_semantica.h"
#include "helpers_asm.h"
int yylex(void);
void yyerror (char const *mensagem);
int get_line_number();

extern asd_tree_t *arvore;
asd_tree_t* func_atual = NULL;
array_argumento_t args_atual;


#line 94 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_PR_AS = 3,                   /* TK_PR_AS  */
  YYSYMBOL_TK_PR_DECLARE = 4,              /* TK_PR_DECLARE  */
  YYSYMBOL_TK_PR_ELSE = 5,                 /* TK_PR_ELSE  */
  YYSYMBOL_TK_PR_IF = 6,                   /* TK_PR_IF  */
  YYSYMBOL_TK_PR_FLOAT = 7,                /* TK_PR_FLOAT  */
  YYSYMBOL_TK_PR_INT = 8,                  /* TK_PR_INT  */
  YYSYMBOL_TK_PR_IS = 9,                   /* TK_PR_IS  */
  YYSYMBOL_TK_PR_RETURN = 10,              /* TK_PR_RETURN  */
  YYSYMBOL_TK_PR_RETURNS = 11,             /* TK_PR_RETURNS  */
  YYSYMBOL_TK_PR_WHILE = 12,               /* TK_PR_WHILE  */
  YYSYMBOL_TK_PR_WITH = 13,                /* TK_PR_WITH  */
  YYSYMBOL_TK_OC_LE = 14,                  /* TK_OC_LE  */
  YYSYMBOL_TK_OC_GE = 15,                  /* TK_OC_GE  */
  YYSYMBOL_TK_OC_EQ = 16,                  /* TK_OC_EQ  */
  YYSYMBOL_TK_OC_NE = 17,                  /* TK_OC_NE  */
  YYSYMBOL_TK_ID = 18,                     /* TK_ID  */
  YYSYMBOL_TK_LI_INT = 19,                 /* TK_LI_INT  */
  YYSYMBOL_TK_LI_FLOAT = 20,               /* TK_LI_FLOAT  */
  YYSYMBOL_TK_ER = 21,                     /* TK_ER  */
  YYSYMBOL_22_ = 22,                       /* ','  */
  YYSYMBOL_23_ = 23,                       /* ';'  */
  YYSYMBOL_24_ = 24,                       /* '['  */
  YYSYMBOL_25_ = 25,                       /* ']'  */
  YYSYMBOL_26_ = 26,                       /* '('  */
  YYSYMBOL_27_ = 27,                       /* ')'  */
  YYSYMBOL_28_ = 28,                       /* '|'  */
  YYSYMBOL_29_ = 29,                       /* '&'  */
  YYSYMBOL_30_ = 30,                       /* '<'  */
  YYSYMBOL_31_ = 31,                       /* '>'  */
  YYSYMBOL_32_ = 32,                       /* '+'  */
  YYSYMBOL_33_ = 33,                       /* '-'  */
  YYSYMBOL_34_ = 34,                       /* '*'  */
  YYSYMBOL_35_ = 35,                       /* '/'  */
  YYSYMBOL_36_ = 36,                       /* '%'  */
  YYSYMBOL_37_ = 37,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_Programa = 39,                  /* Programa  */
  YYSYMBOL_Cria_tabela_global = 40,        /* Cria_tabela_global  */
  YYSYMBOL_Free_tabela_global = 41,        /* Free_tabela_global  */
  YYSYMBOL_Lista = 42,                     /* Lista  */
  YYSYMBOL_Elemento = 43,                  /* Elemento  */
  YYSYMBOL_Def_func = 44,                  /* Def_func  */
  YYSYMBOL_Cab_func = 45,                  /* Cab_func  */
  YYSYMBOL_Lista_params = 46,              /* Lista_params  */
  YYSYMBOL_Parametro = 47,                 /* Parametro  */
  YYSYMBOL_Tipo = 48,                      /* Tipo  */
  YYSYMBOL_Corpo_func = 49,                /* Corpo_func  */
  YYSYMBOL_Comando = 50,                   /* Comando  */
  YYSYMBOL_Bloco_func = 51,                /* Bloco_func  */
  YYSYMBOL_Empilha_tabela = 52,            /* Empilha_tabela  */
  YYSYMBOL_Desempilha_tabela = 53,         /* Desempilha_tabela  */
  YYSYMBOL_Bloco = 54,                     /* Bloco  */
  YYSYMBOL_Lista_com = 55,                 /* Lista_com  */
  YYSYMBOL_Dec_var = 56,                   /* Dec_var  */
  YYSYMBOL_Dec_var_com = 57,               /* Dec_var_com  */
  YYSYMBOL_Dec_var_com_atrib = 58,         /* Dec_var_com_atrib  */
  YYSYMBOL_Identificador = 59,             /* Identificador  */
  YYSYMBOL_Literal = 60,                   /* Literal  */
  YYSYMBOL_Atrib = 61,                     /* Atrib  */
  YYSYMBOL_Chama_func = 62,                /* Chama_func  */
  YYSYMBOL_Lista_args = 63,                /* Lista_args  */
  YYSYMBOL_Arg = 64,                       /* Arg  */
  YYSYMBOL_Retorno = 65,                   /* Retorno  */
  YYSYMBOL_Fluxo = 66,                     /* Fluxo  */
  YYSYMBOL_Fluxo_cond = 67,                /* Fluxo_cond  */
  YYSYMBOL_Fluxo_iter = 68,                /* Fluxo_iter  */
  YYSYMBOL_Expressao = 69,                 /* Expressao  */
  YYSYMBOL_T8 = 70,                        /* T8  */
  YYSYMBOL_T7 = 71,                        /* T7  */
  YYSYMBOL_T6 = 72,                        /* T6  */
  YYSYMBOL_T5 = 73,                        /* T5  */
  YYSYMBOL_T4 = 74,                        /* T4  */
  YYSYMBOL_T3 = 75,                        /* T3  */
  YYSYMBOL_T2 = 76,                        /* T2  */
  YYSYMBOL_T1 = 77                         /* T1  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   125

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  138

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   276


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,     2,     2,    36,    29,     2,
      26,    27,    34,    32,    22,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    23,
      30,     2,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    24,     2,    25,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    28,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    99,    99,   102,   103,   109,   112,   131,   134,   137,
     140,   157,   167,   175,   179,   182,   188,   189,   190,   194,
     197,   200,   203,   206,   209,   212,   215,   218,   221,   225,
     228,   231,   234,   253,   256,   263,   266,   278,   284,   289,
     294,   303,   320,   336,   342,   348,   349,   355,   356,   357,
     363,   370,   376,   379,   385,   388,   394,   395,   401,   407,
     408,   414,   420,   426,   432,   433,   439,   445,   446,   452,
     458,   464,   465,   471,   477,   483,   484,   485,   493,   498
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_PR_AS",
  "TK_PR_DECLARE", "TK_PR_ELSE", "TK_PR_IF", "TK_PR_FLOAT", "TK_PR_INT",
  "TK_PR_IS", "TK_PR_RETURN", "TK_PR_RETURNS", "TK_PR_WHILE", "TK_PR_WITH",
  "TK_OC_LE", "TK_OC_GE", "TK_OC_EQ", "TK_OC_NE", "TK_ID", "TK_LI_INT",
  "TK_LI_FLOAT", "TK_ER", "','", "';'", "'['", "']'", "'('", "')'", "'|'",
  "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "$accept",
  "Programa", "Cria_tabela_global", "Free_tabela_global", "Lista",
  "Elemento", "Def_func", "Cab_func", "Lista_params", "Parametro", "Tipo",
  "Corpo_func", "Comando", "Bloco_func", "Empilha_tabela",
  "Desempilha_tabela", "Bloco", "Lista_com", "Dec_var", "Dec_var_com",
  "Dec_var_com_atrib", "Identificador", "Literal", "Atrib", "Chama_func",
  "Lista_args", "Arg", "Retorno", "Fluxo", "Fluxo_cond", "Fluxo_iter",
  "Expressao", "T8", "T7", "T6", "T5", "T4", "T3", "T2", "T1", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-101)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-4)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      13,    22,     7,  -101,     6,  -101,  -101,    12,  -101,     5,
    -101,    35,    48,  -101,     7,  -101,    52,  -101,  -101,    34,
      34,  -101,     6,    31,    73,    37,    42,  -101,    62,  -101,
      44,  -101,  -101,  -101,     1,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,    10,  -101,    50,    73,  -101,  -101,    73,
      73,    73,    73,    47,  -101,  -101,    72,    66,    68,    28,
       2,    27,    67,  -101,  -101,    73,  -101,    62,  -101,  -101,
      73,    63,  -101,     6,    34,    71,    77,  -101,  -101,  -101,
      34,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    80,  -101,  -101,  -101,    82,    89,
    -101,   103,    91,   111,   102,    92,  -101,  -101,    68,    28,
       2,     2,    27,    27,    27,    27,    67,    67,  -101,  -101,
    -101,    92,    93,  -101,    73,  -101,     6,    34,    59,   112,
    -101,  -101,  -101,  -101,  -101,  -101,    92,  -101
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     1,     0,    37,     5,     0,     8,     0,
       9,     0,     0,     2,     0,     7,     0,    10,    18,     0,
       0,     6,     0,     0,     0,     0,    28,    27,    33,    19,
       0,    35,    20,    21,     0,    22,    23,    24,    25,    47,
      48,    17,    16,     0,    34,     0,     0,    38,    39,     0,
       0,     0,     0,    77,    78,    79,     0,    52,    54,    56,
      59,    64,    67,    71,    75,     0,    31,     0,    32,    26,
       0,     0,    12,     0,     0,     0,     0,    72,    73,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,    40,    42,     0,    44,
      45,     0,    14,     0,    34,     0,    76,    46,    53,    55,
      57,    58,    61,    60,    62,    63,    65,    66,    68,    69,
      70,     0,     0,    41,     0,    11,     0,     0,     0,    49,
      51,    30,    43,    13,    15,    36,     0,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -101,  -101,  -101,  -101,   105,  -101,  -101,  -101,    -6,  -101,
     -19,  -101,  -101,  -101,  -101,  -101,  -100,   -24,    16,  -101,
    -101,    -2,    -7,  -101,   -13,    -1,  -101,  -101,  -101,  -101,
    -101,   -18,  -101,    41,    43,     4,   -48,    -5,   -43,  -101
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    13,     6,     7,     8,     9,   101,   102,
      43,    17,    28,    18,    67,   122,    29,    30,    31,    32,
      33,    53,    54,    35,    55,    98,    99,    37,    38,    39,
      40,   100,    57,    58,    59,    60,    61,    62,    63,    64
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      11,    44,    12,    36,    68,   129,    56,    77,    78,    79,
      70,     4,    11,    -3,    34,    36,    85,    86,    10,    72,
      45,   130,     3,    73,     5,     5,    34,    71,    75,    16,
      10,    76,    87,    88,    14,    15,   137,   112,   113,   114,
     115,    41,    42,    95,    83,    84,    19,    94,   118,   119,
     120,    20,    96,    74,    36,   104,    22,    46,    23,    89,
      90,   107,    24,    65,    25,    34,    22,    66,    23,    69,
       5,   103,    24,    71,    25,    80,    26,    27,    47,    48,
       5,     5,    47,    48,   116,   117,    26,   110,   111,    49,
      97,     5,    47,    48,    81,    50,    51,    82,   105,    49,
      52,    91,    92,    93,   106,    50,    51,   121,   134,   123,
      52,   124,   125,   126,   127,   128,    26,   136,   131,    21,
     133,   135,   108,   132,   103,   109
};

static const yytype_uint8 yycheck[] =
{
       2,    20,     4,    16,    28,   105,    24,    50,    51,    52,
       9,     4,    14,     0,    16,    28,    14,    15,     2,     9,
      22,   121,     0,    13,    18,    18,    28,    26,    46,    24,
      14,    49,    30,    31,    22,    23,   136,    85,    86,    87,
      88,     7,     8,    67,    16,    17,    11,    65,    91,    92,
      93,     3,    70,     3,    67,    74,     4,    26,     6,    32,
      33,    80,    10,    26,    12,    67,     4,    25,     6,    25,
      18,    73,    10,    26,    12,     3,    24,    25,    19,    20,
      18,    18,    19,    20,    89,    90,    24,    83,    84,    26,
      27,    18,    19,    20,    28,    32,    33,    29,    27,    26,
      37,    34,    35,    36,    27,    32,    33,    27,   127,    27,
      37,    22,     9,    22,     3,    13,    24,     5,    25,    14,
     126,   128,    81,   124,   126,    82
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    39,    40,     0,     4,    18,    42,    43,    44,    45,
      56,    59,    59,    41,    22,    23,    24,    49,    51,    11,
       3,    42,     4,     6,    10,    12,    24,    25,    50,    54,
      55,    56,    57,    58,    59,    61,    62,    65,    66,    67,
      68,     7,     8,    48,    48,    59,    26,    19,    20,    26,
      32,    33,    37,    59,    60,    62,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    26,    25,    52,    55,    25,
       9,    26,     9,    13,     3,    69,    69,    76,    76,    76,
       3,    28,    29,    16,    17,    14,    15,    30,    31,    32,
      33,    34,    35,    36,    69,    55,    69,    27,    63,    64,
      69,    46,    47,    59,    48,    27,    27,    48,    71,    72,
      73,    73,    74,    74,    74,    74,    75,    75,    76,    76,
      76,    27,    53,    27,    22,     9,    22,     3,    13,    54,
      54,    25,    63,    46,    48,    60,     5,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    39,    40,    41,    42,    42,    43,    43,
      44,    45,    45,    46,    46,    47,    48,    48,    49,    50,
      50,    50,    50,    50,    50,    50,    51,    51,    52,    53,
      54,    54,    55,    55,    56,    57,    58,    59,    60,    60,
      61,    62,    62,    63,    63,    64,    65,    66,    66,    67,
      67,    68,    69,    70,    70,    71,    71,    72,    72,    72,
      73,    73,    73,    73,    73,    74,    74,    74,    75,    75,
      75,    75,    76,    76,    76,    76,    77,    77,    77,    77
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     0,     0,     3,     2,     1,     1,
       2,     6,     4,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     0,     0,
       5,     2,     2,     1,     4,     1,     6,     1,     1,     1,
       3,     4,     3,     3,     1,     1,     4,     1,     1,     5,
       7,     5,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     2,     2,     1,     3,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* Programa: Cria_tabela_global Lista Free_tabela_global  */
#line 99 "parser.y"
                                                      { 
    arvore = (yyvsp[-1].no);
}
#line 1519 "parser.tab.c"
    break;

  case 3: /* Programa: %empty  */
#line 102 "parser.y"
          { (yyval.no) = NULL; }
#line 1525 "parser.tab.c"
    break;

  case 4: /* Cria_tabela_global: %empty  */
#line 103 "parser.y"
                    {
    init_pilha_tabelas();
    tabela_simbolos_t* tabela = init_tabela();
    tabela->is_global = 1;
    push_pilha_tabelas(tabela);
}
#line 1536 "parser.tab.c"
    break;

  case 5: /* Free_tabela_global: %empty  */
#line 109 "parser.y"
                    {
    free_pilha_tabelas();
}
#line 1544 "parser.tab.c"
    break;

  case 6: /* Lista: Elemento ',' Lista  */
#line 112 "parser.y"
                          {
    if ((yyvsp[0].no) == NULL && (yyvsp[-2].no) != NULL) {
        // Lista pode ser NULL (dec var global), retorna só a função
        (yyval.no) = (yyvsp[-2].no);        
    }
    else if ((yyvsp[-2].no) == NULL && (yyvsp[0].no) != NULL) {
        // Elemento pode ser NULL, retorna só o resto da lista
        (yyval.no) = (yyvsp[0].no);
    }
    else if ((yyvsp[-2].no) == NULL && (yyvsp[0].no) == NULL) {
        (yyval.no) = NULL;
    }
    else {
        // Os dois existem, bota lista de filho do elemento
        asd_add_child((yyvsp[-2].no), (yyvsp[0].no));
        append_array_op_asm(&((yyvsp[-2].no)->valor.code), &((yyvsp[0].no)->valor.code));
        (yyval.no) = (yyvsp[-2].no);
    }
}
#line 1568 "parser.tab.c"
    break;

  case 7: /* Lista: Elemento ';'  */
#line 131 "parser.y"
                    { 
    (yyval.no) = (yyvsp[-1].no);
}
#line 1576 "parser.tab.c"
    break;

  case 8: /* Elemento: Def_func  */
#line 134 "parser.y"
                   { 
    (yyval.no) = (yyvsp[0].no);
}
#line 1584 "parser.tab.c"
    break;

  case 9: /* Elemento: Dec_var  */
#line 137 "parser.y"
                  { 
    (yyval.no) = NULL;
}
#line 1592 "parser.tab.c"
    break;

  case 10: /* Def_func: Cab_func Corpo_func  */
#line 140 "parser.y"
                              { 
    (yyval.no) = (yyvsp[-1].no);
    if ((yyvsp[0].no) != NULL) {
        tabela_simbolos_t* tabela_global = get_tabela_global();
        if(tabela_global != NULL)
        {
            for(int i = 0; i< tabela_global->tamanho_usado; i++)
            {
                if(tabela_global->itens[i].natureza == NAT_IDENTIFICADOR)   gera_var_global((yyval.no), tabela_global->itens[i].chave, i);
            }
        }
        asd_add_child((yyvsp[-1].no), (yyvsp[0].no));
        gera_main((yyval.no));
        append_array_op_asm(&((yyvsp[-1].no)->valor.code), &((yyvsp[0].no)->valor.code));
    }
    func_atual = NULL;
}
#line 1614 "parser.tab.c"
    break;

  case 11: /* Cab_func: Identificador TK_PR_RETURNS Tipo TK_PR_WITH Lista_params TK_PR_IS  */
#line 157 "parser.y"
                                                                            { 
    check_declared((yyvsp[-5].no));
    insere_funcao_tabela((yyvsp[-5].no)->valor, (yyvsp[-3].tipo_dado));
    func_atual = (yyvsp[-5].no);
    tabela_simbolos_t* tabela = init_tabela();
    push_pilha_tabelas(tabela);
    insere_params_func_tabela((yyvsp[-5].no)->valor.lexema, (yyvsp[-1].no));
    asd_free((yyvsp[-1].no));
    (yyval.no) = (yyvsp[-5].no);
}
#line 1629 "parser.tab.c"
    break;

  case 12: /* Cab_func: Identificador TK_PR_RETURNS Tipo TK_PR_IS  */
#line 167 "parser.y"
                                                    { 
    check_declared((yyvsp[-3].no));
    insere_funcao_tabela((yyvsp[-3].no)->valor, (yyvsp[-1].tipo_dado));
    func_atual = (yyvsp[-3].no);
    tabela_simbolos_t* tabela = init_tabela();
    push_pilha_tabelas(tabela);
    (yyval.no) = (yyvsp[-3].no);
}
#line 1642 "parser.tab.c"
    break;

  case 13: /* Lista_params: Parametro ',' Lista_params  */
#line 175 "parser.y"
                                         {
    asd_add_child((yyvsp[-2].no), (yyvsp[0].no));
    (yyval.no) = (yyvsp[-2].no);
}
#line 1651 "parser.tab.c"
    break;

  case 14: /* Lista_params: Parametro  */
#line 179 "parser.y"
                        {
    (yyval.no) = (yyvsp[0].no);
}
#line 1659 "parser.tab.c"
    break;

  case 15: /* Parametro: Identificador TK_PR_AS Tipo  */
#line 182 "parser.y"
                                       { 
    valor_t valor_param = (yyvsp[-2].no)->valor;
    valor_param.tipo_dado_inferido = (yyvsp[0].tipo_dado);
    (yyval.no) = asd_new(valor_param);
    asd_free((yyvsp[-2].no));
}
#line 1670 "parser.tab.c"
    break;

  case 16: /* Tipo: TK_PR_INT  */
#line 188 "parser.y"
                { (yyval.tipo_dado) = (yyvsp[0].tipo_dado); }
#line 1676 "parser.tab.c"
    break;

  case 17: /* Tipo: TK_PR_FLOAT  */
#line 189 "parser.y"
                  { (yyval.tipo_dado) = (yyvsp[0].tipo_dado); }
#line 1682 "parser.tab.c"
    break;

  case 18: /* Corpo_func: Bloco_func  */
#line 190 "parser.y"
                       {
    pop_pilha_tabelas();
    (yyval.no) = (yyvsp[0].no);
}
#line 1691 "parser.tab.c"
    break;

  case 19: /* Comando: Bloco  */
#line 194 "parser.y"
               { 
    (yyval.no) = (yyvsp[0].no);
}
#line 1699 "parser.tab.c"
    break;

  case 20: /* Comando: Dec_var_com  */
#line 197 "parser.y"
                     { 
    (yyval.no) = (yyvsp[0].no);
}
#line 1707 "parser.tab.c"
    break;

  case 21: /* Comando: Dec_var_com_atrib  */
#line 200 "parser.y"
                           {
    (yyval.no) = (yyvsp[0].no);
}
#line 1715 "parser.tab.c"
    break;

  case 22: /* Comando: Atrib  */
#line 203 "parser.y"
               {
    (yyval.no) = (yyvsp[0].no);
}
#line 1723 "parser.tab.c"
    break;

  case 23: /* Comando: Chama_func  */
#line 206 "parser.y"
                    {
    (yyval.no) = (yyvsp[0].no);
}
#line 1731 "parser.tab.c"
    break;

  case 24: /* Comando: Retorno  */
#line 209 "parser.y"
                 {
    (yyval.no) = (yyvsp[0].no);
}
#line 1739 "parser.tab.c"
    break;

  case 25: /* Comando: Fluxo  */
#line 212 "parser.y"
               {
    (yyval.no) = (yyvsp[0].no);
}
#line 1747 "parser.tab.c"
    break;

  case 26: /* Bloco_func: '[' Lista_com ']'  */
#line 215 "parser.y"
                              { 
    (yyval.no) = (yyvsp[-1].no);
}
#line 1755 "parser.tab.c"
    break;

  case 27: /* Bloco_func: '[' ']'  */
#line 218 "parser.y"
                    {
    (yyval.no) = NULL;
}
#line 1763 "parser.tab.c"
    break;

  case 28: /* Empilha_tabela: %empty  */
#line 221 "parser.y"
                {
    tabela_simbolos_t* tabela = init_tabela();
    push_pilha_tabelas(tabela);
}
#line 1772 "parser.tab.c"
    break;

  case 29: /* Desempilha_tabela: %empty  */
#line 225 "parser.y"
                   {
    pop_pilha_tabelas();
}
#line 1780 "parser.tab.c"
    break;

  case 30: /* Bloco: '[' Empilha_tabela Lista_com Desempilha_tabela ']'  */
#line 228 "parser.y"
                                                          { 
    (yyval.no) = (yyvsp[-2].no);
}
#line 1788 "parser.tab.c"
    break;

  case 31: /* Bloco: '[' ']'  */
#line 231 "parser.y"
               {
    (yyval.no) = NULL;
}
#line 1796 "parser.tab.c"
    break;

  case 32: /* Lista_com: Comando Lista_com  */
#line 234 "parser.y"
                             { 
    if ((yyvsp[0].no) == NULL && (yyvsp[-1].no) != NULL) {
        // Lista_com pode ser NULL, retorna só o Comando
        (yyval.no) = (yyvsp[-1].no);
    }
    else if ((yyvsp[-1].no) == NULL && (yyvsp[0].no) != NULL) {
        // Comando pode ser NULL, retorna só a Lista_com pra ligar com os de cima
        (yyval.no) = (yyvsp[0].no);
    }
    else if ((yyvsp[-1].no) == NULL && (yyvsp[0].no) == NULL) {
        (yyval.no) = NULL;
    }
    else {
        // Comando e Lista_com existem, bota Lista_com como filho e retorna o comando
        asd_add_child((yyvsp[-1].no), (yyvsp[0].no));
        append_array_op_asm(&((yyvsp[-1].no)->valor.code), &((yyvsp[0].no)->valor.code));
        (yyval.no) = (yyvsp[-1].no);
    }
}
#line 1820 "parser.tab.c"
    break;

  case 33: /* Lista_com: Comando  */
#line 253 "parser.y"
                   {
    (yyval.no) = (yyvsp[0].no);
}
#line 1828 "parser.tab.c"
    break;

  case 34: /* Dec_var: TK_PR_DECLARE Identificador TK_PR_AS Tipo  */
#line 256 "parser.y"
                                                   { 
    check_declared((yyvsp[-2].no));
    insere_variavel_tabela((yyvsp[-2].no)->valor, (yyvsp[0].tipo_dado));
    (yyval.no) = NULL;
    // Nem todo identificador vai virar um nó, nesses casos deletamos o nó que foi alocado
    asd_free((yyvsp[-2].no));
}
#line 1840 "parser.tab.c"
    break;

  case 35: /* Dec_var_com: Dec_var  */
#line 263 "parser.y"
                     { 
    (yyval.no) = NULL;
}
#line 1848 "parser.tab.c"
    break;

  case 36: /* Dec_var_com_atrib: TK_PR_DECLARE Identificador TK_PR_AS Tipo TK_PR_WITH Literal  */
#line 266 "parser.y"
                                                                                { 
    check_declared((yyvsp[-4].no));
    insere_variavel_tabela((yyvsp[-4].no)->valor, (yyvsp[-2].tipo_dado));
    valor_t valor = valor_simples("with");
    valor.tipo_dado_inferido = (yyvsp[-2].tipo_dado);
    valor.linha_token = (yyvsp[-4].no)->valor.linha_token;
    (yyvsp[-4].no)->valor.tipo_dado_inferido = (yyvsp[-2].tipo_dado);
    insere_literal_tabela((yyvsp[0].no)->valor, (yyvsp[0].no)->valor.tipo_dado_inferido);
    (yyval.no) = asd_create_and_add_2(valor, (yyvsp[-4].no), (yyvsp[0].no));
    inferencia_tipo_op_binaria((yyval.no), (yyvsp[-4].no), (yyvsp[0].no));
    //gera_store_lit($$, $2, $6);
}
#line 1865 "parser.tab.c"
    break;

  case 37: /* Identificador: TK_ID  */
#line 278 "parser.y"
                     {
    // Complicado fazer ações semanticas aqui, pois n se sabe se esse ID é de uma declaração ou de um uso
    (yyval.no) = asd_new(*(yyvsp[0].valor_lexico));
    free((yyvsp[0].valor_lexico)->lexema);
    free((yyvsp[0].valor_lexico));
}
#line 1876 "parser.tab.c"
    break;

  case 38: /* Literal: TK_LI_INT  */
#line 284 "parser.y"
                   { 
    (yyval.no) = asd_new(*(yyvsp[0].valor_lexico));
    free((yyvsp[0].valor_lexico)->lexema);
    free((yyvsp[0].valor_lexico));
}
#line 1886 "parser.tab.c"
    break;

  case 39: /* Literal: TK_LI_FLOAT  */
#line 289 "parser.y"
                     { 
    (yyval.no) = asd_new(*(yyvsp[0].valor_lexico));
    free((yyvsp[0].valor_lexico)->lexema);
    free((yyvsp[0].valor_lexico));
}
#line 1896 "parser.tab.c"
    break;

  case 40: /* Atrib: Identificador TK_PR_IS Expressao  */
#line 294 "parser.y"
                                        { 
    check_undeclared((yyvsp[-2].no));
    check_is_var((yyvsp[-2].no));
    valor_t valor = valor_simples("is");
    (yyval.no) = asd_create_and_add_2(valor, (yyvsp[-2].no), (yyvsp[0].no));
    set_tipo_da_tabela((yyvsp[-2].no), (yyvsp[-2].no)->valor.lexema);
    inferencia_tipo_op_binaria((yyval.no), (yyvsp[-2].no), (yyvsp[0].no));
    gera_store((yyval.no), (yyvsp[-2].no), (yyvsp[0].no));
}
#line 1910 "parser.tab.c"
    break;

  case 41: /* Chama_func: Identificador '(' Lista_args ')'  */
#line 303 "parser.y"
                                             {
    check_undeclared((yyvsp[-3].no));
    check_is_func((yyvsp[-3].no));
    set_tipo_da_tabela((yyvsp[-3].no), (yyvsp[-3].no)->valor.lexema);
    check_args((yyvsp[-3].no));
    // alocar espaço pra "call $1->valor.lexema"
    char* id_label = (char*) malloc(strlen((yyvsp[-3].no)->valor.lexema) + 1);
    strcpy(id_label, (yyvsp[-3].no)->valor.lexema);
    free((yyvsp[-3].no)->valor.lexema);
    (yyvsp[-3].no)->valor.lexema = (char*) malloc(strlen("call ") + strlen(id_label) + 1);
    (yyvsp[-3].no)->valor.lexema[0] = '\0';
    strcat((yyvsp[-3].no)->valor.lexema, "call ");
    strcat((yyvsp[-3].no)->valor.lexema, id_label);
    asd_add_child((yyvsp[-3].no), (yyvsp[-1].no));
    free(id_label);
    (yyval.no) = (yyvsp[-3].no);
}
#line 1932 "parser.tab.c"
    break;

  case 42: /* Chama_func: Identificador '(' ')'  */
#line 320 "parser.y"
                                  {
    check_undeclared((yyvsp[-2].no));
    check_is_func((yyvsp[-2].no));
    set_tipo_da_tabela((yyvsp[-2].no), (yyvsp[-2].no)->valor.lexema);
    check_args((yyvsp[-2].no));
    // alocar espaço pra "call $1->valor.lexema"
    char* id_label = (char*) malloc(strlen((yyvsp[-2].no)->valor.lexema) + 1);
    strcpy(id_label, (yyvsp[-2].no)->valor.lexema);
    free((yyvsp[-2].no)->valor.lexema);
    (yyvsp[-2].no)->valor.lexema = (char*) malloc(strlen("call ") + strlen(id_label) + 1);
    (yyvsp[-2].no)->valor.lexema[0] = '\0';
    strcat((yyvsp[-2].no)->valor.lexema, "call ");
    strcat((yyvsp[-2].no)->valor.lexema, id_label);
    free(id_label);
    (yyval.no) = (yyvsp[-2].no);
}
#line 1953 "parser.tab.c"
    break;

  case 43: /* Lista_args: Arg ',' Lista_args  */
#line 336 "parser.y"
                               {
    argumento_t arg = { (yyvsp[-2].no)->valor.tipo_dado_inferido };
    insere_item_array_argumento(&args_atual, arg);
    asd_add_child((yyvsp[-2].no), (yyvsp[0].no));
    (yyval.no) = (yyvsp[-2].no);
}
#line 1964 "parser.tab.c"
    break;

  case 44: /* Lista_args: Arg  */
#line 342 "parser.y"
                { 
    init_array_argumento(&args_atual);
    argumento_t arg = { (yyvsp[0].no)->valor.tipo_dado_inferido };
    insere_item_array_argumento(&args_atual, arg);
    (yyval.no) = (yyvsp[0].no);
}
#line 1975 "parser.tab.c"
    break;

  case 45: /* Arg: Expressao  */
#line 348 "parser.y"
               { (yyval.no) = (yyvsp[0].no); }
#line 1981 "parser.tab.c"
    break;

  case 46: /* Retorno: TK_PR_RETURN Expressao TK_PR_AS Tipo  */
#line 349 "parser.y"
                                              {
    valor_t valor = valor_simples("return");
    (yyval.no) = asd_create_and_add_1(valor, (yyvsp[-2].no));
    inferencia_tipo_return((yyval.no), (yyvsp[-2].no), (yyvsp[0].tipo_dado));
    gera_retorno((yyval.no), (yyvsp[-2].no));
}
#line 1992 "parser.tab.c"
    break;

  case 47: /* Fluxo: Fluxo_cond  */
#line 355 "parser.y"
                  { (yyval.no) = (yyvsp[0].no); }
#line 1998 "parser.tab.c"
    break;

  case 48: /* Fluxo: Fluxo_iter  */
#line 356 "parser.y"
                  { (yyval.no) = (yyvsp[0].no); }
#line 2004 "parser.tab.c"
    break;

  case 49: /* Fluxo_cond: TK_PR_IF '(' Expressao ')' Bloco  */
#line 357 "parser.y"
                                             {
    valor_t valor = valor_simples("if");
    (yyval.no) = asd_create_and_add_2(valor, (yyvsp[-2].no), (yyvsp[0].no));
    (yyval.no)->valor.tipo_dado_inferido = (yyvsp[-2].no)->valor.tipo_dado_inferido;
    //gera_if($$, $3, $5);
}
#line 2015 "parser.tab.c"
    break;

  case 50: /* Fluxo_cond: TK_PR_IF '(' Expressao ')' Bloco TK_PR_ELSE Bloco  */
#line 363 "parser.y"
                                                              {
    check_if_else((yyvsp[-2].no), (yyvsp[0].no));
    valor_t valor = valor_simples("if");
    (yyval.no) = asd_create_and_add_3(valor, (yyvsp[-4].no), (yyvsp[-2].no), (yyvsp[0].no));
    (yyval.no)->valor.tipo_dado_inferido = (yyvsp[-4].no)->valor.tipo_dado_inferido;
    //gera_if_else($$, $3, $5, $7);
}
#line 2027 "parser.tab.c"
    break;

  case 51: /* Fluxo_iter: TK_PR_WHILE '(' Expressao ')' Bloco  */
#line 370 "parser.y"
                                                {
    valor_t valor = valor_simples("while");
    (yyval.no) = asd_create_and_add_2(valor, (yyvsp[-2].no), (yyvsp[0].no));
    (yyval.no)->valor.tipo_dado_inferido = (yyvsp[-2].no)->valor.tipo_dado_inferido;
    //gera_while($$, $3, $5);
}
#line 2038 "parser.tab.c"
    break;

  case 52: /* Expressao: T8  */
#line 376 "parser.y"
              {
    (yyval.no) = (yyvsp[0].no);
}
#line 2046 "parser.tab.c"
    break;

  case 53: /* T8: T8 '|' T7  */
#line 379 "parser.y"
              {
    valor_t valor = valor_simples("|");
    (yyval.no) = asd_create_and_add_2(valor, (yyvsp[-2].no), (yyvsp[0].no));
    inferencia_tipo_op_binaria((yyval.no), (yyvsp[-2].no), (yyvsp[0].no));
    //gera_op_3("or", $$, $1, $3);
}
#line 2057 "parser.tab.c"
    break;

  case 54: /* T8: T7  */
#line 385 "parser.y"
       {
    (yyval.no) = (yyvsp[0].no);
}
#line 2065 "parser.tab.c"
    break;

  case 55: /* T7: T7 '&' T6  */
#line 388 "parser.y"
              {
    valor_t valor = valor_simples("&");
    (yyval.no) = asd_create_and_add_2(valor, (yyvsp[-2].no), (yyvsp[0].no));
    inferencia_tipo_op_binaria((yyval.no), (yyvsp[-2].no), (yyvsp[0].no));
    //gera_op_3("and", $$, $1, $3);
}
#line 2076 "parser.tab.c"
    break;

  case 56: /* T7: T6  */
#line 394 "parser.y"
       { (yyval.no) = (yyvsp[0].no); }
#line 2082 "parser.tab.c"
    break;

  case 57: /* T6: T6 TK_OC_EQ T5  */
#line 395 "parser.y"
                   {
    valor_t valor = valor_simples("==");
    (yyval.no) = asd_create_and_add_2(valor, (yyvsp[-2].no), (yyvsp[0].no));
    inferencia_tipo_op_binaria((yyval.no), (yyvsp[-2].no), (yyvsp[0].no));
    //gera_op_3("cmp_EQ", $$, $1, $3);
}
#line 2093 "parser.tab.c"
    break;

  case 58: /* T6: T6 TK_OC_NE T5  */
#line 401 "parser.y"
                   { 
    valor_t valor = valor_simples("!=");
    (yyval.no) = asd_create_and_add_2(valor, (yyvsp[-2].no), (yyvsp[0].no));
    inferencia_tipo_op_binaria((yyval.no), (yyvsp[-2].no), (yyvsp[0].no));
    //gera_op_3("cmp_NE", $$, $1, $3);
}
#line 2104 "parser.tab.c"
    break;

  case 59: /* T6: T5  */
#line 407 "parser.y"
       { (yyval.no) = (yyvsp[0].no); }
#line 2110 "parser.tab.c"
    break;

  case 60: /* T5: T5 TK_OC_GE T4  */
#line 408 "parser.y"
                   { 
    valor_t valor = valor_simples(">=");
    (yyval.no) = asd_create_and_add_2(valor, (yyvsp[-2].no), (yyvsp[0].no));
    inferencia_tipo_op_binaria((yyval.no), (yyvsp[-2].no), (yyvsp[0].no));
    //gera_op_3("cmp_GE", $$, $1, $3);
}
#line 2121 "parser.tab.c"
    break;

  case 61: /* T5: T5 TK_OC_LE T4  */
#line 414 "parser.y"
                   {
    valor_t valor = valor_simples("<=");
    (yyval.no) = asd_create_and_add_2(valor, (yyvsp[-2].no), (yyvsp[0].no));
    inferencia_tipo_op_binaria((yyval.no), (yyvsp[-2].no), (yyvsp[0].no));
    //gera_op_3("cmp_LE", $$, $1, $3);
}
#line 2132 "parser.tab.c"
    break;

  case 62: /* T5: T5 '<' T4  */
#line 420 "parser.y"
              {
    valor_t valor = valor_simples("<");
    (yyval.no) = asd_create_and_add_2(valor, (yyvsp[-2].no), (yyvsp[0].no));
    inferencia_tipo_op_binaria((yyval.no), (yyvsp[-2].no), (yyvsp[0].no));
    //gera_op_3("cmp_LT", $$, $1, $3);
}
#line 2143 "parser.tab.c"
    break;

  case 63: /* T5: T5 '>' T4  */
#line 426 "parser.y"
              {
    valor_t valor = valor_simples(">");
    (yyval.no) = asd_create_and_add_2(valor, (yyvsp[-2].no), (yyvsp[0].no));
    inferencia_tipo_op_binaria((yyval.no), (yyvsp[-2].no), (yyvsp[0].no));
    //gera_op_3("cmp_GT", $$, $1, $3);
}
#line 2154 "parser.tab.c"
    break;

  case 64: /* T5: T4  */
#line 432 "parser.y"
       { (yyval.no) = (yyvsp[0].no); }
#line 2160 "parser.tab.c"
    break;

  case 65: /* T4: T4 '+' T3  */
#line 433 "parser.y"
              { 
    valor_t valor = valor_simples("+");
    (yyval.no) = asd_create_and_add_2(valor, (yyvsp[-2].no), (yyvsp[0].no));
    inferencia_tipo_op_binaria((yyval.no), (yyvsp[-2].no), (yyvsp[0].no));
    //gera_op_3("add", $$, $1, $3);
}
#line 2171 "parser.tab.c"
    break;

  case 66: /* T4: T4 '-' T3  */
#line 439 "parser.y"
              {
    valor_t valor = valor_simples("-");
    (yyval.no) = asd_create_and_add_2(valor, (yyvsp[-2].no), (yyvsp[0].no));
    inferencia_tipo_op_binaria((yyval.no), (yyvsp[-2].no), (yyvsp[0].no));
    //gera_op_3("sub", $$, $1, $3);
}
#line 2182 "parser.tab.c"
    break;

  case 67: /* T4: T3  */
#line 445 "parser.y"
       { (yyval.no) = (yyvsp[0].no); }
#line 2188 "parser.tab.c"
    break;

  case 68: /* T3: T3 '*' T2  */
#line 446 "parser.y"
              { 
    valor_t valor = valor_simples("*");
    (yyval.no) = asd_create_and_add_2(valor, (yyvsp[-2].no), (yyvsp[0].no));
    inferencia_tipo_op_binaria((yyval.no), (yyvsp[-2].no), (yyvsp[0].no));
    //gera_op_3("mult", $$, $1, $3);
}
#line 2199 "parser.tab.c"
    break;

  case 69: /* T3: T3 '/' T2  */
#line 452 "parser.y"
               {
    valor_t valor = valor_simples("/");
    (yyval.no) = asd_create_and_add_2(valor, (yyvsp[-2].no), (yyvsp[0].no));
    inferencia_tipo_op_binaria((yyval.no), (yyvsp[-2].no), (yyvsp[0].no));
    //gera_op_3("div", $$, $1, $3);
}
#line 2210 "parser.tab.c"
    break;

  case 70: /* T3: T3 '%' T2  */
#line 458 "parser.y"
               {
    valor_t valor = valor_simples("%");
    (yyval.no) = asd_create_and_add_2(valor, (yyvsp[-2].no), (yyvsp[0].no));
    inferencia_tipo_op_binaria((yyval.no), (yyvsp[-2].no), (yyvsp[0].no));
    // Ignorar para e5
}
#line 2221 "parser.tab.c"
    break;

  case 71: /* T3: T2  */
#line 464 "parser.y"
       { (yyval.no) = (yyvsp[0].no); }
#line 2227 "parser.tab.c"
    break;

  case 72: /* T2: '+' T2  */
#line 465 "parser.y"
           {
    valor_t valor = valor_simples("+");
    (yyval.no) = asd_create_and_add_1(valor, (yyvsp[0].no));
    (yyval.no)->valor.tipo_dado_inferido = (yyvsp[0].no)->valor.tipo_dado_inferido;
    // O que essa operação faz??!
}
#line 2238 "parser.tab.c"
    break;

  case 73: /* T2: '-' T2  */
#line 471 "parser.y"
            {
    valor_t valor = valor_simples("-");
    (yyval.no) = asd_create_and_add_1(valor, (yyvsp[0].no));
    (yyval.no)->valor.tipo_dado_inferido = (yyvsp[0].no)->valor.tipo_dado_inferido;
    //gera_sub_unario($$, $2);
}
#line 2249 "parser.tab.c"
    break;

  case 74: /* T2: '!' T2  */
#line 477 "parser.y"
           {
    valor_t valor = valor_simples("!");
    (yyval.no) = asd_create_and_add_1(valor, (yyvsp[0].no));
    (yyval.no)->valor.tipo_dado_inferido = (yyvsp[0].no)->valor.tipo_dado_inferido;
    //gera_not_unario($$, $2);
}
#line 2260 "parser.tab.c"
    break;

  case 75: /* T2: T1  */
#line 483 "parser.y"
       { (yyval.no) = (yyvsp[0].no); }
#line 2266 "parser.tab.c"
    break;

  case 76: /* T1: '(' Expressao ')'  */
#line 484 "parser.y"
                      { (yyval.no) = (yyvsp[-1].no); }
#line 2272 "parser.tab.c"
    break;

  case 77: /* T1: Identificador  */
#line 485 "parser.y"
                  { 
    // Aqui o Identificador está sendo usando em uma expressão
    check_undeclared((yyvsp[0].no));
    check_is_var((yyvsp[0].no));
    set_tipo_da_tabela((yyvsp[0].no), (yyvsp[0].no)->valor.lexema);
    //gera_load_var($1);
    (yyval.no) = (yyvsp[0].no); 
}
#line 2285 "parser.tab.c"
    break;

  case 78: /* T1: Literal  */
#line 493 "parser.y"
            { 
    insere_literal_tabela((yyvsp[0].no)->valor, (yyvsp[0].no)->valor.tipo_dado_inferido);
    gera_lit((yyvsp[0].no));
    (yyval.no) = (yyvsp[0].no);
}
#line 2295 "parser.tab.c"
    break;

  case 79: /* T1: Chama_func  */
#line 498 "parser.y"
               { 
    (yyval.no) = (yyvsp[0].no); 
}
#line 2303 "parser.tab.c"
    break;


#line 2307 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 501 "parser.y"


void yyerror (char const *mensagem) {
    printf("Erro sintático: na linha %d, houve erro [ %s ]\n", get_line_number(), mensagem);
}
