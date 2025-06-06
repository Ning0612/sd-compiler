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
#line 1 "src/p3_parser.y"

#include "SemanticAnalyzer.hpp"
#include "Context.hpp"
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string> 
#include <fstream>
#include <filesystem>

extern int  yylex();
extern int  yylineno;
extern FILE* yyin;

Context* ctx = nullptr;

void yyerror(const char* s){
    std::fprintf(stderr, "Syntax error @ line %d: %s\n", yylineno, s);
    std::exit(1);
}

#line 93 "src/y.tab.cpp"

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

#include "y.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BOOL_TOK = 3,                   /* BOOL_TOK  */
  YYSYMBOL_FLOAT_TOK = 4,                  /* FLOAT_TOK  */
  YYSYMBOL_DOUBLE_TOK = 5,                 /* DOUBLE_TOK  */
  YYSYMBOL_INT_TOK = 6,                    /* INT_TOK  */
  YYSYMBOL_CHAR_TOK = 7,                   /* CHAR_TOK  */
  YYSYMBOL_STRING_TOK = 8,                 /* STRING_TOK  */
  YYSYMBOL_VOID_TOK = 9,                   /* VOID_TOK  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_DO = 12,                        /* DO  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_FOR = 14,                       /* FOR  */
  YYSYMBOL_FOREACH = 15,                   /* FOREACH  */
  YYSYMBOL_RETURN = 16,                    /* RETURN  */
  YYSYMBOL_CONST = 17,                     /* CONST  */
  YYSYMBOL_PRINT = 18,                     /* PRINT  */
  YYSYMBOL_PRINTLN = 19,                   /* PRINTLN  */
  YYSYMBOL_READ = 20,                      /* READ  */
  YYSYMBOL_TRUE = 21,                      /* TRUE  */
  YYSYMBOL_FALSE = 22,                     /* FALSE  */
  YYSYMBOL_ID = 23,                        /* ID  */
  YYSYMBOL_INT_LIT = 24,                   /* INT_LIT  */
  YYSYMBOL_REAL_LIT = 25,                  /* REAL_LIT  */
  YYSYMBOL_STRING_LIT = 26,                /* STRING_LIT  */
  YYSYMBOL_BOOL_LIT = 27,                  /* BOOL_LIT  */
  YYSYMBOL_LE = 28,                        /* LE  */
  YYSYMBOL_GE = 29,                        /* GE  */
  YYSYMBOL_EQ = 30,                        /* EQ  */
  YYSYMBOL_NEQ = 31,                       /* NEQ  */
  YYSYMBOL_LT = 32,                        /* LT  */
  YYSYMBOL_GT = 33,                        /* GT  */
  YYSYMBOL_PLUS = 34,                      /* PLUS  */
  YYSYMBOL_MINUS = 35,                     /* MINUS  */
  YYSYMBOL_MUL = 36,                       /* MUL  */
  YYSYMBOL_DIV = 37,                       /* DIV  */
  YYSYMBOL_MOD = 38,                       /* MOD  */
  YYSYMBOL_ASSIGN = 39,                    /* ASSIGN  */
  YYSYMBOL_NOT = 40,                       /* NOT  */
  YYSYMBOL_AND = 41,                       /* AND  */
  YYSYMBOL_OR = 42,                        /* OR  */
  YYSYMBOL_INC = 43,                       /* INC  */
  YYSYMBOL_DEC = 44,                       /* DEC  */
  YYSYMBOL_DOT = 45,                       /* DOT  */
  YYSYMBOL_COMMA = 46,                     /* COMMA  */
  YYSYMBOL_COLON = 47,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 48,                 /* SEMICOLON  */
  YYSYMBOL_LPAREN = 49,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 50,                    /* RPAREN  */
  YYSYMBOL_LBRACK = 51,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 52,                    /* RBRACK  */
  YYSYMBOL_LBRACE = 53,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 54,                    /* RBRACE  */
  YYSYMBOL_BREAK = 55,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 56,                  /* CONTINUE  */
  YYSYMBOL_SWITCH = 57,                    /* SWITCH  */
  YYSYMBOL_CASE = 58,                      /* CASE  */
  YYSYMBOL_DEFAULT = 59,                   /* DEFAULT  */
  YYSYMBOL_EXTERN = 60,                    /* EXTERN  */
  YYSYMBOL_IFX = 61,                       /* IFX  */
  YYSYMBOL_UPLUS = 62,                     /* UPLUS  */
  YYSYMBOL_UMINUS = 63,                    /* UMINUS  */
  YYSYMBOL_POSTINC = 64,                   /* POSTINC  */
  YYSYMBOL_POSTDEC = 65,                   /* POSTDEC  */
  YYSYMBOL_YYACCEPT = 66,                  /* $accept  */
  YYSYMBOL_program = 67,                   /* program  */
  YYSYMBOL_global_decl_list = 68,          /* global_decl_list  */
  YYSYMBOL_global_decl = 69,               /* global_decl  */
  YYSYMBOL_local_decl = 70,                /* local_decl  */
  YYSYMBOL_const_decl = 71,                /* const_decl  */
  YYSYMBOL_var_decl = 72,                  /* var_decl  */
  YYSYMBOL_var_init_list = 73,             /* var_init_list  */
  YYSYMBOL_var_init = 74,                  /* var_init  */
  YYSYMBOL_func_decl = 75,                 /* func_decl  */
  YYSYMBOL_76_1 = 76,                      /* $@1  */
  YYSYMBOL_77_2 = 77,                      /* $@2  */
  YYSYMBOL_param_list_opt = 78,            /* param_list_opt  */
  YYSYMBOL_param_list = 79,                /* param_list  */
  YYSYMBOL_param = 80,                     /* param  */
  YYSYMBOL_block = 81,                     /* block  */
  YYSYMBOL_82_3 = 82,                      /* $@3  */
  YYSYMBOL_block_items_opt = 83,           /* block_items_opt  */
  YYSYMBOL_block_items = 84,               /* block_items  */
  YYSYMBOL_block_item = 85,                /* block_item  */
  YYSYMBOL_statement = 86,                 /* statement  */
  YYSYMBOL_simple_stmt = 87,               /* simple_stmt  */
  YYSYMBOL_assign_stmt = 88,               /* assign_stmt  */
  YYSYMBOL_lvalue = 89,                    /* lvalue  */
  YYSYMBOL_if_stmt = 90,                   /* if_stmt  */
  YYSYMBOL_91_4 = 91,                      /* $@4  */
  YYSYMBOL_if_condition = 92,              /* if_condition  */
  YYSYMBOL_loop_stmt = 93,                 /* loop_stmt  */
  YYSYMBOL_94_5 = 94,                      /* $@5  */
  YYSYMBOL_95_6 = 95,                      /* $@6  */
  YYSYMBOL_96_7 = 96,                      /* $@7  */
  YYSYMBOL_97_8 = 97,                      /* $@8  */
  YYSYMBOL_98_9 = 98,                      /* $@9  */
  YYSYMBOL_99_10 = 99,                     /* $@10  */
  YYSYMBOL_for_simple_opt = 100,           /* for_simple_opt  */
  YYSYMBOL_for_simple_item = 101,          /* for_simple_item  */
  YYSYMBOL_assign_no_semi = 102,           /* assign_no_semi  */
  YYSYMBOL_return_stmt = 103,              /* return_stmt  */
  YYSYMBOL_expression = 104,               /* expression  */
  YYSYMBOL_const_lit = 105,                /* const_lit  */
  YYSYMBOL_func_call = 106,                /* func_call  */
  YYSYMBOL_proc_call = 107,                /* proc_call  */
  YYSYMBOL_arg_list_opt = 108,             /* arg_list_opt  */
  YYSYMBOL_arg_list = 109,                 /* arg_list  */
  YYSYMBOL_type_spec = 110                 /* type_spec  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYLAST   499

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  223

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   320


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    91,    91,   111,   112,   117,   118,   119,   123,   124,
     130,   139,   143,   182,   224,   225,   246,   246,   293,   293,
     336,   339,   345,   350,   358,   366,   366,   374,   375,   379,
     380,   384,   385,   389,   390,   391,   392,   393,   394,   399,
     400,   446,   493,   500,   503,   506,   509,   512,   516,   554,
     569,   577,   577,   598,   649,   654,   649,   683,   683,   711,
     716,   721,   711,   752,   764,   765,   766,   770,   771,   816,
     862,   868,   871,   874,   877,   883,   922,   960,   974,   983,
     992,  1001,  1010,  1019,  1028,  1037,  1046,  1055,  1064,  1073,
    1082,  1091,  1100,  1109,  1112,  1115,  1118,  1121,  1129,  1160,
    1168,  1180,  1184,  1188,  1192,  1201,  1239,  1269,  1270,  1274,
    1289,  1308,  1309,  1310,  1311
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "BOOL_TOK",
  "FLOAT_TOK", "DOUBLE_TOK", "INT_TOK", "CHAR_TOK", "STRING_TOK",
  "VOID_TOK", "IF", "ELSE", "DO", "WHILE", "FOR", "FOREACH", "RETURN",
  "CONST", "PRINT", "PRINTLN", "READ", "TRUE", "FALSE", "ID", "INT_LIT",
  "REAL_LIT", "STRING_LIT", "BOOL_LIT", "LE", "GE", "EQ", "NEQ", "LT",
  "GT", "PLUS", "MINUS", "MUL", "DIV", "MOD", "ASSIGN", "NOT", "AND", "OR",
  "INC", "DEC", "DOT", "COMMA", "COLON", "SEMICOLON", "LPAREN", "RPAREN",
  "LBRACK", "RBRACK", "LBRACE", "RBRACE", "BREAK", "CONTINUE", "SWITCH",
  "CASE", "DEFAULT", "EXTERN", "IFX", "UPLUS", "UMINUS", "POSTINC",
  "POSTDEC", "$accept", "program", "global_decl_list", "global_decl",
  "local_decl", "const_decl", "var_decl", "var_init_list", "var_init",
  "func_decl", "$@1", "$@2", "param_list_opt", "param_list", "param",
  "block", "$@3", "block_items_opt", "block_items", "block_item",
  "statement", "simple_stmt", "assign_stmt", "lvalue", "if_stmt", "$@4",
  "if_condition", "loop_stmt", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10",
  "for_simple_opt", "for_simple_item", "assign_no_semi", "return_stmt",
  "expression", "const_lit", "func_call", "proc_call", "arg_list_opt",
  "arg_list", "type_spec", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-126)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -126,     4,   126,  -126,  -126,  -126,  -126,  -126,   -11,    32,
    -126,  -126,  -126,  -126,    -2,   -24,    16,   -26,   -41,  -126,
      32,    20,    76,    32,    48,  -126,    23,    30,  -126,    56,
      76,    33,  -126,  -126,  -126,  -126,    76,    76,    76,    58,
      58,    76,    25,   421,  -126,  -126,    34,    50,  -126,    39,
      32,  -126,   298,    76,  -126,  -126,   450,  -126,  -126,  -126,
     176,  -126,  -126,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    41,  -126,  -126,  -126,
     421,    45,    51,  -126,   461,   461,   461,   461,   461,   461,
      69,    69,  -126,  -126,  -126,   450,   436,  -126,    14,  -126,
      76,    14,    55,  -126,    59,    63,    65,    76,    76,    76,
      58,    66,    58,    58,  -126,  -126,  -126,  -126,  -126,  -126,
      72,    14,  -126,  -126,  -126,  -126,    22,  -126,   180,  -126,
    -126,    83,    48,   421,    85,    76,   180,  -126,  -126,   121,
     319,   340,   361,    97,    76,    98,   101,    14,  -126,  -126,
      76,   102,   105,   106,  -126,  -126,   206,   139,    76,   104,
     109,  -126,  -126,  -126,  -126,   107,  -126,  -126,   110,   382,
    -126,  -126,  -126,  -126,   111,   229,    76,    76,    58,    58,
      58,    94,     8,  -126,  -126,    76,  -126,  -126,  -126,   180,
      76,  -126,   421,   421,  -126,  -126,  -126,    76,  -126,  -126,
     104,  -126,   403,  -126,   252,   180,   421,  -126,    76,   113,
     117,  -126,   421,    76,  -126,   118,   275,   104,   180,   -40,
    -126,   180,  -126
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,   113,   112,   111,   114,     0,     0,
       4,     5,     6,     7,     0,     0,     0,    14,     0,    12,
      20,     0,     0,    20,     0,    11,     0,    21,    22,     0,
       0,    49,   101,   102,   104,   103,     0,     0,     0,     0,
       0,     0,    98,    15,    99,   100,     0,    14,    13,     0,
       0,    24,     0,   107,    92,    91,    90,    49,    93,    94,
       0,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,    23,    10,
     109,     0,   108,    97,    83,    85,    86,    87,    82,    84,
      77,    78,    79,    80,    81,    88,    89,    16,    27,   105,
       0,    27,     0,    57,     0,     0,     0,     0,     0,     0,
       0,    49,     0,     0,    47,    25,    31,     8,     9,    38,
       0,    28,    30,    32,    33,    39,     0,    34,     0,    35,
      36,     0,     0,   110,     0,     0,     0,    54,    59,     0,
       0,     0,     0,     0,   107,     0,     0,    27,    19,    29,
       0,     0,     0,    50,    37,    17,     0,     0,     0,    64,
       0,    76,    40,    41,    42,     0,    45,    46,     0,     0,
      43,    44,    51,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    65,    67,     0,   106,    26,    48,     0,
       0,    55,    68,    69,    70,    73,    74,     0,    71,    72,
       0,    60,     0,    52,     0,     0,    75,    66,     0,     0,
       0,    56,    61,     0,    58,     0,     0,    64,     0,     0,
      63,     0,    62
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,  -126,  -126,  -126,   157,   159,  -126,   145,  -126,
    -126,  -126,   147,  -126,   122,  -126,  -126,   -92,  -126,    52,
    -125,  -126,  -126,   -38,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,   -46,   -23,  -126,  -126,   -22,  -126,
    -126,  -126,    37,  -126,    68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    10,   116,   117,   118,    18,    19,    13,
     101,    98,    26,    27,    28,   119,   147,   120,   121,   122,
     123,   124,   125,    42,   127,   189,   128,   129,   158,   205,
     136,   159,   208,   215,   182,   183,   184,   130,    80,    44,
      45,   131,    81,    82,   132
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    58,    59,   153,     3,    24,   200,    25,    52,   134,
     221,   157,    15,    22,    54,    55,    56,     4,     5,    60,
       6,    17,     7,    23,   102,    20,   103,   104,   105,   106,
     107,     9,   108,   109,   110,     4,     5,   111,     6,    21,
       7,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,   200,   168,   201,   112,   113,    30,
     126,   150,   114,   126,   203,   151,   152,   115,    61,    62,
      14,    47,   143,    49,   145,   146,    50,    16,   133,    51,
     211,    57,    53,   126,    76,   140,   141,   142,    29,    22,
     126,    29,    77,   220,    97,    99,   222,   100,   126,    31,
      32,    33,    34,    35,   135,    71,    72,    73,   137,   126,
      36,    37,   138,   156,   139,   144,    38,   172,    29,    39,
      40,   181,   176,   177,   178,    41,   148,    57,   169,     4,
       5,   154,     6,   197,     7,     8,   175,   198,   199,   155,
     194,   195,   196,     9,   160,   164,   166,   179,   180,   167,
     170,   126,   174,   171,   192,   193,   185,   186,   213,    11,
     190,    12,   181,   202,   187,   214,   217,   126,   204,    48,
      46,   219,    78,   149,     0,   206,     0,   207,     0,   181,
     126,   165,     0,   126,     0,     0,   212,     0,     0,     0,
     102,   216,   103,   104,   105,   106,   107,     0,   108,   109,
     110,     0,     0,   111,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,    74,    75,     0,
       0,     0,     0,   112,   113,     0,    83,     0,   114,     0,
       0,     0,     0,   115,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,    74,    75,     0,
       0,     0,     0,     0,     0,     0,   173,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,     0,
      74,    75,     0,     0,     0,     0,     0,     0,     0,   191,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,    74,    75,     0,     0,     0,     0,     0,
       0,     0,   210,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,    74,    75,     0,     0,
       0,     0,     0,     0,     0,   218,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,     0,    74,
      75,     0,     0,     0,     0,     0,    79,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,     0,
      74,    75,     0,     0,     0,     0,     0,   161,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,    74,    75,     0,     0,     0,     0,     0,   162,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,     0,    74,    75,     0,     0,     0,     0,     0,   163,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,    74,    75,     0,     0,     0,     0,     0,
     188,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     0,     0,    74,    75,     0,     0,   209,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,     0,    74,    75,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,    74,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,    73
};

static const yytype_int16 yycheck[] =
{
      22,    39,    40,   128,     0,    46,    46,    48,    30,   101,
      50,   136,    23,    39,    36,    37,    38,     3,     4,    41,
       6,    23,     8,    49,    10,    49,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     3,     4,    23,     6,    23,
       8,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    46,   147,    48,    43,    44,    39,
      98,    39,    48,   101,   189,    43,    44,    53,    43,    44,
       2,    23,   110,    50,   112,   113,    46,     9,   100,    23,
     205,    23,    49,   121,    50,   107,   108,   109,    20,    39,
     128,    23,    53,   218,    53,    50,   221,    46,   136,    23,
      24,    25,    26,    27,    49,    36,    37,    38,    49,   147,
      34,    35,    49,   135,    49,    49,    40,    11,    50,    43,
      44,   159,    18,    19,    20,    49,    54,    23,   150,     3,
       4,    48,     6,    39,     8,     9,   158,    43,    44,    54,
     178,   179,   180,    17,    23,    48,    48,    43,    44,    48,
      48,   189,    13,    48,   176,   177,    47,    50,    45,     2,
      49,     2,   200,   185,    54,    48,    48,   205,   190,    24,
      23,   217,    50,   121,    -1,   197,    -1,   200,    -1,   217,
     218,   144,    -1,   221,    -1,    -1,   208,    -1,    -1,    -1,
      10,   213,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    -1,    -1,    23,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    41,    42,    -1,
      -1,    -1,    -1,    43,    44,    -1,    50,    -1,    48,    -1,
      -1,    -1,    -1,    53,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    41,
      42,    -1,    -1,    -1,    -1,    -1,    48,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      41,    42,    -1,    -1,    -1,    -1,    -1,    48,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    48,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    48,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      48,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    41,    42,    -1,    -1,    45,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    41,    42,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    41,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    67,    68,     0,     3,     4,     6,     8,     9,    17,
      69,    71,    72,    75,   110,    23,   110,    23,    73,    74,
      49,    23,    39,    49,    46,    48,    78,    79,    80,   110,
      39,    23,    24,    25,    26,    27,    34,    35,    40,    43,
      44,    49,    89,   104,   105,   106,    78,    23,    74,    50,
      46,    23,   104,    49,   104,   104,   104,    23,    89,    89,
     104,    43,    44,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    41,    42,    50,    53,    80,    48,
     104,   108,   109,    50,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,    53,    77,    50,
      46,    76,    10,    12,    13,    14,    15,    16,    18,    19,
      20,    23,    43,    44,    48,    53,    70,    71,    72,    81,
      83,    84,    85,    86,    87,    88,    89,    90,    92,    93,
     103,   107,   110,   104,    83,    49,    96,    49,    49,    49,
     104,   104,   104,    89,    49,    89,    89,    82,    54,    85,
      39,    43,    44,    86,    48,    54,   104,    86,    94,    97,
      23,    48,    48,    48,    48,   108,    48,    48,    83,   104,
      48,    48,    11,    50,    13,   104,    18,    19,    20,    43,
      44,    89,   100,   101,   102,    47,    50,    54,    48,    91,
      49,    50,   104,   104,    89,    89,    89,    39,    43,    44,
      46,    48,   104,    86,   104,    95,   104,   101,    98,    45,
      50,    86,   104,    45,    48,    99,   104,    48,    50,   100,
      86,    50,    86
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    66,    67,    68,    68,    69,    69,    69,    70,    70,
      71,    72,    73,    73,    74,    74,    76,    75,    77,    75,
      78,    78,    79,    79,    80,    82,    81,    83,    83,    84,
      84,    85,    85,    86,    86,    86,    86,    86,    86,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    88,    89,
      90,    91,    90,    92,    94,    95,    93,    96,    93,    97,
      98,    99,    93,    93,   100,   100,   100,   101,   101,   101,
     101,   101,   101,   101,   101,   102,   103,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   105,   105,   105,   105,   106,   107,   108,   108,   109,
     109,   110,   110,   110,   110
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       6,     3,     1,     3,     1,     3,     0,     9,     0,     9,
       0,     1,     1,     3,     2,     0,     4,     0,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     1,     4,     1,
       2,     0,     5,     4,     0,     0,     7,     0,     8,     0,
       0,     0,    12,    10,     0,     1,     3,     1,     2,     2,
       2,     2,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     2,     2,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     0,     1,     1,
       3,     1,     1,     1,     1
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
  case 2: /* program: global_decl_list  */
#line 91 "src/p3_parser.y"
                       {
        Symbol* mainFunc = ctx->symTab.lookup("main");
        if (mainFunc == nullptr) {
            SemanticError("missing main function", yylineno);
        }

        if (!mainFunc->type->isFunc()) {
            SemanticError("main function must be function", yylineno);
        }

        if (mainFunc->type->ret->base != BK_Void) {
            SemanticError("main function must be void", yylineno);
        }

        ctx->symTab.leaveScope();
        printf("\n");
    }
#line 1420 "src/y.tab.cpp"
    break;

  case 10: /* const_decl: CONST type_spec ID ASSIGN expression SEMICOLON  */
#line 130 "src/p3_parser.y"
                                                   {
        std::string id = *(yyvsp[-3].sval); delete (yyvsp[-3].sval);
        ExprInfo value = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
        tryDeclareConstant(ctx->symTab, id, (yyvsp[-4].type), value, yylineno);
    }
#line 1430 "src/y.tab.cpp"
    break;

  case 12: /* var_init_list: var_init  */
#line 143 "src/p3_parser.y"
              {
        VarInit varInit = *(yyvsp[0].var_init_); delete (yyvsp[0].var_init_);
        tryDeclareVarable(ctx->symTab, varInit, ctx->nowType, yylineno);
        
        if (ctx->symTab.getCurrentScopeIndex() == 0) {
            std::string declaration = "    field static ";
            switch (ctx->nowType->base) {
                case BK_Int: declaration += "int " + varInit.name + " = " + std::to_string((varInit.valueKind == VK_Int) ? varInit.iVal : int(varInit.fVal)) + ""; break;
                case BK_Float: declaration += "float " + varInit.name + " = " + std::to_string((varInit.valueKind == VK_Float) ? varInit.fVal : float(varInit.iVal)) + "f"; break;
                case BK_Bool: declaration += "int " + varInit.name + " = " + (varInit.iVal ? "1" : "0"); break;
                default: SemanticError("unsupported type for static variable", yylineno); break;
            }

            ctx->fileContent.insert(ctx->fileContent.begin() + 2, declaration);
        } else {
            int index = ctx->symTab.lookup(varInit.name)->index;
            switch (varInit.valueKind) {
                case VK_Int:
                    ctx->fileContent.push_back("        ldc " + std::to_string((varInit.valueKind == VK_Int) ? varInit.iVal : int(varInit.fVal)) + ""); break;
                case VK_Float:
                    ctx->fileContent.push_back("        ldc " + std::to_string((varInit.valueKind == VK_Float) ? varInit.fVal : float(varInit.iVal)) + "f"); break;
                case VK_Bool:
                    ctx->fileContent.push_back("        ldc " + std::string(varInit.iVal ? "1" : "0")); break;
                default:
                    SemanticError("unsupported type for local variable", yylineno); break;
            }

            switch (ctx->nowType->base) {
                case BK_Int:
                    ctx->fileContent.push_back("        istore " + std::to_string(index)); break;
                case BK_Float:
                    ctx->fileContent.push_back("        fstore " + std::to_string(index)); break;
                case BK_Bool:
                    ctx->fileContent.push_back("        istore " + std::to_string(index)); break;
                default:
                    SemanticError("unsupported type for local variable", yylineno); break;
            }
        }
    }
#line 1474 "src/y.tab.cpp"
    break;

  case 13: /* var_init_list: var_init_list COMMA var_init  */
#line 182 "src/p3_parser.y"
                                   {
        VarInit varInit = *(yyvsp[0].var_init_); delete (yyvsp[0].var_init_);
        tryDeclareVarable(ctx->symTab, varInit, ctx->nowType, yylineno);

        if (ctx->symTab.getCurrentScopeIndex() == 0) {
            std::string declaration = "    field static ";
            switch (ctx->nowType->base) {
                case BK_Int: declaration += "int " + varInit.name + " = " + std::to_string((varInit.valueKind == VK_Int) ? varInit.iVal : int(varInit.fVal)) + ""; break;
                case BK_Float: declaration += "float " + varInit.name + " = " + std::to_string((varInit.valueKind == VK_Float) ? varInit.fVal : float(varInit.iVal)) + "f"; break;
                case BK_Bool: declaration += "int " + varInit.name + " = " + (varInit.iVal ? "1" : "0"); break;
                default: SemanticError("unsupported type for static variable", yylineno); break;
            }

            ctx->fileContent.insert(ctx->fileContent.begin() + 2, declaration);
        } else {
            int index = ctx->symTab.lookup(varInit.name)->index;
            switch (varInit.valueKind) {
                case VK_Int:
                    ctx->fileContent.push_back("        ldc " + std::to_string((varInit.valueKind == VK_Int) ? varInit.iVal : int(varInit.fVal)) + ""); break;
                case VK_Float:
                    ctx->fileContent.push_back("        ldc " + std::to_string((varInit.valueKind == VK_Float) ? varInit.fVal : float(varInit.iVal)) + "f"); break;
                case VK_Bool:
                    ctx->fileContent.push_back("        ldc " + std::string(varInit.iVal ? "1" : "0")); break;
                default:
                    SemanticError("unsupported type for local variable", yylineno); break;
            }

            switch (ctx->nowType->base) {
                case BK_Int:
                    ctx->fileContent.push_back("        istore " + std::to_string(index)); break;
                case BK_Float:
                    ctx->fileContent.push_back("        fstore " + std::to_string(index)); break;
                case BK_Bool:
                    ctx->fileContent.push_back("        istore " + std::to_string(index)); break;
                default:
                    SemanticError("unsupported type for local variable", yylineno); break;
            }
        }
    }
#line 1518 "src/y.tab.cpp"
    break;

  case 14: /* var_init: ID  */
#line 224 "src/p3_parser.y"
                             { (yyval.var_init_) = new VarInit(*(yyvsp[0].sval), ctx->nowType); delete (yyvsp[0].sval); }
#line 1524 "src/y.tab.cpp"
    break;

  case 15: /* var_init: ID ASSIGN expression  */
#line 225 "src/p3_parser.y"
                             {
        std::string id = *(yyvsp[-2].sval); delete (yyvsp[-2].sval);
        ExprInfo expr = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);

        if (!expr.isValid) {
            (yyval.var_init_) = makeInvalidVar();
        }else{
            if (expr.type->isFunc()) {
                SemanticError("assignment from function", yylineno);
            }

            if (!expr.isConst) {
                SemanticError("assignment from non-constant", yylineno);
            }
            (yyval.var_init_) = new VarInit(id, expr);
        }
    }
#line 1546 "src/y.tab.cpp"
    break;

  case 16: /* $@1: %empty  */
#line 246 "src/p3_parser.y"
                                                       {
        ctx->returnsExpr.clear();
        ctx->funcType = (yyvsp[-5].type);

        std::string funcName = *(yyvsp[-4].sval); delete (yyvsp[-4].sval);
        std::vector<Symbol> paramList = *(yyvsp[-2].symbol_list); delete (yyvsp[-2].symbol_list);

        std::string declaration = "    method public static " + baseKindToJavaStr((yyvsp[-5].type)->base) + " " + funcName + "(";
        for (size_t i = 0; i < paramList.size(); ++i) {
            if (i > 0) declaration += ", ";
            declaration +=(paramList[i].type->base == BK_Int) ? "int" :
                           (paramList[i].type->base == BK_Float) ? "float" :
                           (paramList[i].type->base == BK_Bool) ? "int" :
                           (paramList[i].type->base == BK_String) ? "java.lang.String" : "unknown";
        }

        declaration += ")";

        ctx->fileContent.push_back(declaration);
        ctx->fileContent.push_back("    max_stack 15");
        ctx->fileContent.push_back("    max_locals 15");
        ctx->fileContent.push_back("    {");

        declareFunction(funcName, (yyvsp[-5].type), paramList, ctx->typePool, ctx->symTab, yylineno);
    }
#line 1576 "src/y.tab.cpp"
    break;

  case 17: /* func_decl: type_spec ID LPAREN param_list_opt RPAREN LBRACE $@1 block_items_opt RBRACE  */
#line 270 "src/p3_parser.y"
                             {
        if (ctx->returnsExpr.empty()) {
            SemanticError("missing return statement", yylineno);
        }

        for (auto& expr : ctx->returnsExpr) {
            if (!expr.first.isValid) {
                break;
            }

            if (!(yyvsp[-8].type)->isCompatibleWith(*expr.first.type)) {
                SemanticError("return type mismatch !", expr.second);
            }

            if (isConvertible((yyvsp[-8].type)->base, expr.first.type->base)) {
                SemanticWarning("implicit conversion from " + baseKindToStr(expr.first.type->base) + " to " + baseKindToStr((yyvsp[-8].type)->base), expr.second);
            }
        }

        ctx->fileContent.push_back("    }");
        ctx->fileContent.push_back("");
        ctx->symTab.leaveScope();
    }
#line 1604 "src/y.tab.cpp"
    break;

  case 18: /* $@2: %empty  */
#line 293 "src/p3_parser.y"
                                                      {
        ctx->returnsExpr.clear();

        std::string funcName = *(yyvsp[-4].sval); delete (yyvsp[-4].sval);
        std::vector<Symbol> paramList = *(yyvsp[-2].symbol_list); delete (yyvsp[-2].symbol_list);

        if (funcName == "main") {
            ctx->fileContent.push_back("    method public static void main(java.lang.String[])");
        }else {
            std::string declaration = "    method public static void " + funcName + "(";

            for (size_t i = 0; i < paramList.size(); ++i) {
                if (i > 0) declaration += ", ";
                declaration += (paramList[i].type->base == BK_Int) ? "int" :
                               (paramList[i].type->base == BK_Float) ? "float" :
                               (paramList[i].type->base == BK_Bool) ? "int" :
                               (paramList[i].type->base == BK_String) ? "java.lang.String" : "unknown";
            }
            declaration += ")";

            ctx->fileContent.push_back(declaration);
        }
        
        ctx->fileContent.push_back("    max_stack 15");
        ctx->fileContent.push_back("    max_locals 15");
        ctx->fileContent.push_back("    {");

        declareFunction(funcName, ctx->typePool.make(BK_Void), paramList, ctx->typePool, ctx->symTab, yylineno);
    }
#line 1638 "src/y.tab.cpp"
    break;

  case 19: /* func_decl: VOID_TOK ID LPAREN param_list_opt RPAREN LBRACE $@2 block_items_opt RBRACE  */
#line 321 "src/p3_parser.y"
                             {
        if (!ctx->returnsExpr.empty()) {
            SemanticError("void function should not return value", yylineno);
        }

        ctx->symTab.leaveScope();

        ctx->fileContent.push_back("       return");
        ctx->fileContent.push_back("    }");
        ctx->fileContent.push_back("");
    }
#line 1654 "src/y.tab.cpp"
    break;

  case 20: /* param_list_opt: %empty  */
#line 336 "src/p3_parser.y"
                {
        (yyval.symbol_list) = new std::vector<Symbol>();
    }
#line 1662 "src/y.tab.cpp"
    break;

  case 21: /* param_list_opt: param_list  */
#line 339 "src/p3_parser.y"
                 {
        (yyval.symbol_list) = (yyvsp[0].symbol_list);
    }
#line 1670 "src/y.tab.cpp"
    break;

  case 22: /* param_list: param  */
#line 345 "src/p3_parser.y"
            {
        (yyval.symbol_list) = new std::vector<Symbol>;
        (yyval.symbol_list)->push_back(*(yyvsp[0].symbol));
        delete (yyvsp[0].symbol);
    }
#line 1680 "src/y.tab.cpp"
    break;

  case 23: /* param_list: param_list COMMA param  */
#line 350 "src/p3_parser.y"
                             {
        (yyval.symbol_list) = (yyvsp[-2].symbol_list);
        (yyval.symbol_list)->push_back(*(yyvsp[0].symbol));
        delete (yyvsp[0].symbol);
    }
#line 1690 "src/y.tab.cpp"
    break;

  case 24: /* param: type_spec ID  */
#line 358 "src/p3_parser.y"
                   {
        std::string id = *(yyvsp[0].sval); delete (yyvsp[0].sval);
        (yyval.symbol) = new Symbol(id, (yyvsp[-1].type), false);
    }
#line 1699 "src/y.tab.cpp"
    break;

  case 25: /* $@3: %empty  */
#line 366 "src/p3_parser.y"
             {
        ctx->symTab.enterScope();
    }
#line 1707 "src/y.tab.cpp"
    break;

  case 26: /* block: LBRACE $@3 block_items_opt RBRACE  */
#line 368 "src/p3_parser.y"
                             {
        ctx->symTab.leaveScope();
    }
#line 1715 "src/y.tab.cpp"
    break;

  case 40: /* simple_stmt: PRINT expression SEMICOLON  */
#line 400 "src/p3_parser.y"
                                 {
        ExprInfo expr = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
        if (expr.isValid) checkPrint(expr, yylineno);
        ctx->fileContent.push_back("        getstatic java.io.PrintStream java.lang.System.out\n");

        if (expr.isConst) {
            switch (expr.type->base) {
                case BK_Int:
                    ctx->fileContent.push_back("        ldc " + std::to_string(expr.iVal));
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(int)");
                    break;
                case BK_Float:
                    ctx->fileContent.push_back("        ldc " + std::to_string(expr.fVal) + "f");
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(float)");
                    break;
                case BK_Bool:
                    ctx->fileContent.push_back("        ldc " + std::string(expr.bVal ? "1" : "0"));
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(boolean)");
                    break;
                case BK_String:
                    ctx->fileContent.push_back("        ldc \"" + expr.sVal + "\"");
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(java.lang.String)");
                    break;
                default:
                    SemanticError("unsupported type for print", yylineno);
            }
        } else {
            ctx->fileContent.push_back("        swap");
            switch (expr.type->base) {
                case BK_Int:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(int)");
                    break;
                case BK_Float:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(float)");
                    break;
                case BK_Bool:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(boolean)");
                    break;
                case BK_String:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(java.lang.String)");
                    break;
                default:
                    SemanticError("unsupported type for print", yylineno);
            }
        }
    }
#line 1766 "src/y.tab.cpp"
    break;

  case 41: /* simple_stmt: PRINTLN expression SEMICOLON  */
#line 446 "src/p3_parser.y"
                                   {
        ExprInfo expr = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
        if (expr.isValid) checkPrint(expr, yylineno);

        ctx->fileContent.push_back("        getstatic java.io.PrintStream java.lang.System.out\n");
        if (expr.isConst) {
            switch (expr.type->base) {
                case BK_Int:
                    ctx->fileContent.push_back("        ldc " + std::to_string(expr.iVal));
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(int)");
                    break;
                case BK_Float:
                    ctx->fileContent.push_back("        ldc " + std::to_string(expr.fVal) + "f");
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(float)");
                    break;
                case BK_Bool:
                    ctx->fileContent.push_back("        ldc " + std::string(expr.bVal ? "1" : "0"));
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(boolean)");
                    break;
                case BK_String:
                    ctx->fileContent.push_back("        ldc \"" + expr.sVal + "\"");
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(java.lang.String)");
                    break;
                default:
                    SemanticError("unsupported type for println", yylineno);
            }
        } else {
            ctx->fileContent.push_back("        swap");

            switch (expr.type->base) {
                case BK_Int:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(int)");
                    break;
                case BK_Float:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(float)");
                    break;
                case BK_Bool:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(boolean)");
                    break;
                case BK_String:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(java.lang.String)");
                    break;
                default:
                    SemanticError("unsupported type for println", yylineno);
            }
        }
    }
#line 1818 "src/y.tab.cpp"
    break;

  case 42: /* simple_stmt: READ lvalue SEMICOLON  */
#line 493 "src/p3_parser.y"
                            {
        Symbol* sym = (yyvsp[-1].symbol);
        ExprInfo *exprPtr = (sym != nullptr) ? sym->getExprInfo() : makeInvalidExpr();
        ExprInfo expr = *exprPtr; delete exprPtr;
        if (expr.isValid) checkRead(expr, yylineno);
        SemanticError("read statement not supported in code generation", yylineno);
    }
#line 1830 "src/y.tab.cpp"
    break;

  case 43: /* simple_stmt: lvalue INC SEMICOLON  */
#line 500 "src/p3_parser.y"
                           {
        if ((yyvsp[-2].symbol) != nullptr) delete checkIncDecValid(true, false, (yyvsp[-2].symbol), ctx, yylineno);
     }
#line 1838 "src/y.tab.cpp"
    break;

  case 44: /* simple_stmt: lvalue DEC SEMICOLON  */
#line 503 "src/p3_parser.y"
                           {
        if ((yyvsp[-2].symbol) != nullptr) delete checkIncDecValid(false, false, (yyvsp[-2].symbol), ctx, yylineno);
     }
#line 1846 "src/y.tab.cpp"
    break;

  case 45: /* simple_stmt: INC lvalue SEMICOLON  */
#line 506 "src/p3_parser.y"
                           {
        if ((yyvsp[-1].symbol) != nullptr) delete checkIncDecValid(true, false, (yyvsp[-1].symbol), ctx, yylineno);
     }
#line 1854 "src/y.tab.cpp"
    break;

  case 46: /* simple_stmt: DEC lvalue SEMICOLON  */
#line 509 "src/p3_parser.y"
                           {
        if ((yyvsp[-1].symbol) != nullptr) delete checkIncDecValid(false, false, (yyvsp[-1].symbol), ctx, yylineno);
    }
#line 1862 "src/y.tab.cpp"
    break;

  case 48: /* assign_stmt: lvalue ASSIGN expression SEMICOLON  */
#line 516 "src/p3_parser.y"
                                         {
        Symbol* sym = (yyvsp[-3].symbol);
        ExprInfo *exprPtr = (sym != nullptr) ? sym->getExprInfo() : makeInvalidExpr();
        ExprInfo target = *exprPtr; delete exprPtr;
        ExprInfo value = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
        if (target.isValid && value.isValid) {
            checkAssignment(target, value, yylineno);
            if (value.isConst) {
                switch (target.type->base) {
                    case BK_Int: ctx->fileContent.push_back("        ldc " + std::to_string(value.iVal)); break;
                    case BK_Float: ctx->fileContent.push_back("        ldc " + std::to_string(value.fVal) + "f"); break;
                    case BK_Bool: ctx->fileContent.push_back("        ldc " + std::string(value.bVal ? "1" : "0")); break;
                    case BK_String: ctx->fileContent.push_back("        ldc \"" + value.sVal + "\""); break;
                    default: break;
                }
            }

            if (sym->index == -1) {
                switch (target.type->base) {
                    case BK_Int: ctx->fileContent.push_back("        putstatic int " + sym->name); break;
                    case BK_Float: ctx->fileContent.push_back("        putstatic float " + sym->name); break;
                    case BK_Bool: ctx->fileContent.push_back("        putstatic int " + sym->name); break;
                    default: break;
                }
            } else {
                switch (target.type->base) {
                    case BK_Int: ctx->fileContent.push_back("        istore " + std::to_string(sym->index)); break;
                    case BK_Float: ctx->fileContent.push_back("        fstore " + std::to_string(sym->index)); break;
                    case BK_Bool: ctx->fileContent.push_back("        istore " + std::to_string(sym->index)); break;
                    default: break;                
                }
            }
        }
    }
#line 1901 "src/y.tab.cpp"
    break;

  case 49: /* lvalue: ID  */
#line 554 "src/p3_parser.y"
         {
        std::string id = *(yyvsp[0].sval); delete (yyvsp[0].sval);
        Symbol* symbol = ctx->symTab.lookup(id);

        if (symbol == nullptr) {
            SemanticError("undeclared identifier: " + id, yylineno);
            (yyval.symbol) = nullptr;
        } else {
            (yyval.symbol) = symbol;
        }
    }
#line 1917 "src/y.tab.cpp"
    break;

  case 50: /* if_stmt: if_condition statement  */
#line 569 "src/p3_parser.y"
                                       {
        // 處理 if-then 結束
        std::string labelEnd = ctx->pendingIfLabels.back();
        ctx->pendingIfLabels.pop_back();
        if (!labelEnd.empty()) {  // 只有非常數條件才需要標籤
            ctx->fileContent.push_back(labelEnd + ":");
        }
    }
#line 1930 "src/y.tab.cpp"
    break;

  case 51: /* $@4: %empty  */
#line 577 "src/p3_parser.y"
                                  {
        // 處理 then 分支結束，準備 else 分支
        std::string labelElse = ctx->pendingIfLabels.back();
        if (!labelElse.empty()) {  // 只有非常數條件才需要跳躍
            std::string labelEnd = "I" + std::to_string(ctx->ifLabelCounter++);
            ctx->pendingIfLabels.back() = labelEnd;
            
            ctx->fileContent.push_back("        goto " + labelEnd);
            ctx->fileContent.push_back(labelElse + ":");
        }
    }
#line 1946 "src/y.tab.cpp"
    break;

  case 52: /* if_stmt: if_condition statement ELSE $@4 statement  */
#line 587 "src/p3_parser.y"
                {
        // 處理 if-then-else 結束
        std::string labelEnd = ctx->pendingIfLabels.back();
        ctx->pendingIfLabels.pop_back();
        if (!labelEnd.empty()) {  // 只有非常數條件才需要標籤
            ctx->fileContent.push_back(labelEnd + ":");
        }
    }
#line 1959 "src/y.tab.cpp"
    break;

  case 53: /* if_condition: IF LPAREN expression RPAREN  */
#line 598 "src/p3_parser.y"
                                  {
        ExprInfo expr = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
        if (expr.isValid) {
            checkBoolExpr("if", expr, yylineno);
            
            if (expr.isConst) {
                // 常數條件：先載入常數值到棧中
                switch(expr.type->base) {
                    case BK_Bool:
                        ctx->fileContent.push_back("        ldc " + std::to_string(expr.getBool() ? 1 : 0));
                        break;
                    case BK_Int:
                        ctx->fileContent.push_back("        ldc " + std::to_string(expr.getInt()));
                        break;
                    case BK_Float:
                        ctx->fileContent.push_back("        ldc " + std::to_string(expr.getFloat()));
                        break;
                    case BK_String:
                        ctx->fileContent.push_back("        ldc \"" + expr.getString() + "\"");
                        break;
                    default:
                        break;
                }
                
                // 然後生成條件跳躍（即使是常數也要生成，因為可能有副作用）
                std::string labelFalse = "I" + std::to_string(ctx->ifLabelCounter++);
                ctx->fileContent.push_back("        ifeq " + labelFalse);
                ctx->pendingIfLabels.push_back(labelFalse);
                
                // 對常數條件發出警告
                if (expr.getBool()) {
                    SemanticWarning("condition is always true", yylineno);
                } else {
                    SemanticWarning("condition is always false", yylineno);
                }
            } else {
                // 非常數條件：expression 的值已經在棧頂了
                std::string labelFalse = "I" + std::to_string(ctx->ifLabelCounter++);
                ctx->fileContent.push_back("        ifeq " + labelFalse);
                ctx->pendingIfLabels.push_back(labelFalse);
            }
        } else {
            // 無效表達式，使用空標籤佔位
            ctx->pendingIfLabels.push_back("");
        }
    }
#line 2010 "src/y.tab.cpp"
    break;

  case 54: /* $@5: %empty  */
#line 649 "src/p3_parser.y"
                  {
       std::string labelBegin = "W" + std::to_string(ctx->whileLabelCounter++);
       std::string labelEnd = "W" + std::to_string(ctx->whileLabelCounter++);
       ctx->fileContent.push_back(labelBegin + ":");
       ctx->pendingWhileLabels.push_back({labelBegin, labelEnd});
   }
#line 2021 "src/y.tab.cpp"
    break;

  case 55: /* $@6: %empty  */
#line 654 "src/p3_parser.y"
                       {
       ExprInfo expr = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
       if (expr.isValid) {
           checkBoolExpr("while", expr, yylineno);
           std::string labelEnd = ctx->pendingWhileLabels.back().second;
           if (expr.isConst) {
               switch(expr.type->base) {
                   case BK_Bool:
                       ctx->fileContent.push_back("        ldc " + std::to_string(expr.getBool() ? 1 : 0));
                       break;
                   case BK_Int:
                       ctx->fileContent.push_back("        ldc " + std::to_string(expr.getInt()));
                       break;
                   case BK_Float:
                       ctx->fileContent.push_back("        ldc " + std::to_string(expr.getFloat()));
                       break;
                   default:
                       break;
               }
           }
           ctx->fileContent.push_back("        ifeq " + labelEnd);
       }
   }
#line 2049 "src/y.tab.cpp"
    break;

  case 56: /* loop_stmt: WHILE LPAREN $@5 expression RPAREN $@6 statement  */
#line 676 "src/p3_parser.y"
               {
       std::string labelBegin = ctx->pendingWhileLabels.back().first;
       std::string labelEnd = ctx->pendingWhileLabels.back().second;
       ctx->pendingWhileLabels.pop_back();
       ctx->fileContent.push_back("        goto " + labelBegin);
       ctx->fileContent.push_back(labelEnd + ":");
   }
#line 2061 "src/y.tab.cpp"
    break;

  case 57: /* $@7: %empty  */
#line 683 "src/p3_parser.y"
        {
       std::string labelBegin = "W" + std::to_string(ctx->whileLabelCounter++);
       ctx->fileContent.push_back(labelBegin + ":");
       ctx->pendingWhileLabels.push_back({labelBegin, ""});
   }
#line 2071 "src/y.tab.cpp"
    break;

  case 58: /* loop_stmt: DO $@7 statement WHILE LPAREN expression RPAREN SEMICOLON  */
#line 687 "src/p3_parser.y"
                                                        {
       ExprInfo expr = *(yyvsp[-2].expr_info); delete (yyvsp[-2].expr_info);
       if (expr.isValid) {
           checkBoolExpr("do while", expr, yylineno);
           std::string labelBegin = ctx->pendingWhileLabels.back().first;
           ctx->pendingWhileLabels.pop_back();
           if (expr.isConst) {
               switch(expr.type->base) {
                   case BK_Bool:
                       ctx->fileContent.push_back("        ldc " + std::to_string(expr.getBool() ? 1 : 0));
                       break;
                   case BK_Int:
                       ctx->fileContent.push_back("        ldc " + std::to_string(expr.getInt()));
                       break;
                   case BK_Float:
                       ctx->fileContent.push_back("        ldc " + std::to_string(expr.getFloat()));
                       break;
                   default:
                       break;
               }
           }
           ctx->fileContent.push_back("        ifne " + labelBegin);
       }
   }
#line 2100 "src/y.tab.cpp"
    break;

  case 59: /* $@8: %empty  */
#line 711 "src/p3_parser.y"
                {
       std::string labelCondition = "F" + std::to_string(ctx->forLabelCounter++);
       std::string labelUpdate = "F" + std::to_string(ctx->forLabelCounter++);
       std::string labelEnd = "F" + std::to_string(ctx->forLabelCounter++);
       ctx->pendingForLabels.push_back(std::make_tuple(labelCondition, labelUpdate, labelEnd));
   }
#line 2111 "src/y.tab.cpp"
    break;

  case 60: /* $@9: %empty  */
#line 716 "src/p3_parser.y"
                              {
       std::string labelCondition = std::get<0>(ctx->pendingForLabels.back());
       ctx->fileContent.push_back("        goto " + labelCondition);
       std::string labelUpdate = std::get<1>(ctx->pendingForLabels.back());
       ctx->fileContent.push_back(labelUpdate + ":");
   }
#line 2122 "src/y.tab.cpp"
    break;

  case 61: /* $@10: %empty  */
#line 721 "src/p3_parser.y"
                {
       ExprInfo expr = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);
       if (expr.isValid) {
           checkBoolExpr("for", expr, yylineno);
           std::string labelCondition = std::get<0>(ctx->pendingForLabels.back());
           std::string labelEnd = std::get<2>(ctx->pendingForLabels.back());
           ctx->fileContent.push_back(labelCondition + ":");
           if (expr.isConst) {
               switch(expr.type->base) {
                   case BK_Bool:
                       ctx->fileContent.push_back("        ldc " + std::to_string(expr.getBool() ? 1 : 0));
                       break;
                   case BK_Int:
                       ctx->fileContent.push_back("        ldc " + std::to_string(expr.getInt()));
                       break;
                   case BK_Float:
                       ctx->fileContent.push_back("        ldc " + std::to_string(expr.getFloat()));
                       break;
                   default:
                       break;
               }
           }
           ctx->fileContent.push_back("        ifeq " + labelEnd);
       }
   }
#line 2152 "src/y.tab.cpp"
    break;

  case 62: /* loop_stmt: FOR LPAREN $@8 for_simple_opt SEMICOLON $@9 expression $@10 SEMICOLON for_simple_opt RPAREN statement  */
#line 745 "src/p3_parser.y"
                                               {
       std::string labelUpdate = std::get<1>(ctx->pendingForLabels.back());
       std::string labelEnd = std::get<2>(ctx->pendingForLabels.back());
       ctx->pendingForLabels.pop_back();
       ctx->fileContent.push_back("        goto " + labelUpdate);
       ctx->fileContent.push_back(labelEnd + ":");
   }
#line 2164 "src/y.tab.cpp"
    break;

  case 63: /* loop_stmt: FOREACH LPAREN ID COLON expression DOT DOT expression RPAREN statement  */
#line 752 "src/p3_parser.y"
                                                                           {
       ExprInfo from = *(yyvsp[-5].expr_info); ExprInfo to = *(yyvsp[-2].expr_info); delete (yyvsp[-5].expr_info); delete (yyvsp[-2].expr_info);
       std::string id = *(yyvsp[-7].sval); delete (yyvsp[-7].sval);
       if (from.isValid && to.isValid) {
           checkForeachRange(from, to, yylineno);
       }
       checkForeachIndex(ctx->symTab.lookup(id), yylineno);
   }
#line 2177 "src/y.tab.cpp"
    break;

  case 68: /* for_simple_item: PRINT expression  */
#line 771 "src/p3_parser.y"
                         {
        ExprInfo expr = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);
        if (expr.isValid) checkPrint(expr, yylineno);

        if (expr.isConst) {
            switch (expr.type->base) {
                case BK_Int:
                    ctx->fileContent.push_back("        ldc " + std::to_string(expr.iVal));
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(int)");
                    break;
                case BK_Float:
                    ctx->fileContent.push_back("        ldc " + std::to_string(expr.fVal) + "f");
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(float)");
                    break;
                case BK_Bool:
                    ctx->fileContent.push_back("        ldc " + std::string(expr.bVal ? "1" : "0"));
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(boolean)");
                    break;
                case BK_String:
                    ctx->fileContent.push_back("        ldc \"" + expr.sVal + "\"");
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(java.lang.String)");
                    break;
                default:
                    SemanticError("unsupported type for print", yylineno);
            }
        } else {
            ctx->fileContent.push_back("        swap");
            switch (expr.type->base) {
                case BK_Int:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(int)");
                    break;
                case BK_Float:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(float)");
                    break;
                case BK_Bool:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(boolean)");
                    break;
                case BK_String:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(java.lang.String)");
                    break;
                default:
                    SemanticError("unsupported type for print", yylineno);
            }
        }
    }
#line 2227 "src/y.tab.cpp"
    break;

  case 69: /* for_simple_item: PRINTLN expression  */
#line 816 "src/p3_parser.y"
                          {
        ExprInfo expr = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);
        if (expr.isValid) checkPrint(expr, yylineno);

        ctx->fileContent.push_back("        getstatic java.io.PrintStream java.lang.System.out\n");
        if (expr.isConst) {
            switch (expr.type->base) {
                case BK_Int:
                    ctx->fileContent.push_back("        ldc " + std::to_string(expr.iVal));
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(int)");
                    break;
                case BK_Float:
                    ctx->fileContent.push_back("        ldc " + std::to_string(expr.fVal) + "f");
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(float)");
                    break;
                case BK_Bool:
                    ctx->fileContent.push_back("        ldc " + std::string(expr.bVal ? "1" : "0"));
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(boolean)");
                    break;
                case BK_String:
                    ctx->fileContent.push_back("        ldc \"" + expr.sVal + "\"");
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(java.lang.String)");
                    break;
                default:
                    SemanticError("unsupported type for println", yylineno);
            }
        } else {
            ctx->fileContent.push_back("        swap");
            switch (expr.type->base) {
                case BK_Int:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(int)");
                    break;
                case BK_Float:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(float)");
                    break;
                case BK_Bool:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(boolean)");
                    break;
                case BK_String:
                    ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(java.lang.String)");
                    break;
                default:
                    SemanticError("unsupported type for println", yylineno);
            }
        }
    }
#line 2278 "src/y.tab.cpp"
    break;

  case 70: /* for_simple_item: READ lvalue  */
#line 862 "src/p3_parser.y"
                   {
        Symbol* sym = (yyvsp[0].symbol);
        ExprInfo *exprPtr = (sym != nullptr) ? sym->getExprInfo() : makeInvalidExpr();
        ExprInfo expr = *exprPtr; delete exprPtr;
        if (expr.isValid) checkRead(expr, yylineno);
    }
#line 2289 "src/y.tab.cpp"
    break;

  case 71: /* for_simple_item: lvalue INC  */
#line 868 "src/p3_parser.y"
                 {
        if ((yyvsp[-1].symbol) != nullptr) delete checkIncDecValid(true, false, (yyvsp[-1].symbol), ctx, yylineno);
     }
#line 2297 "src/y.tab.cpp"
    break;

  case 72: /* for_simple_item: lvalue DEC  */
#line 871 "src/p3_parser.y"
                 {
        if ((yyvsp[-1].symbol) != nullptr) delete checkIncDecValid(false, false, (yyvsp[-1].symbol), ctx, yylineno);
     }
#line 2305 "src/y.tab.cpp"
    break;

  case 73: /* for_simple_item: INC lvalue  */
#line 874 "src/p3_parser.y"
                 {
        if ((yyvsp[0].symbol) != nullptr) delete checkIncDecValid(true, false, (yyvsp[0].symbol), ctx, yylineno);
     }
#line 2313 "src/y.tab.cpp"
    break;

  case 74: /* for_simple_item: DEC lvalue  */
#line 877 "src/p3_parser.y"
                 {
        if ((yyvsp[0].symbol) != nullptr) delete checkIncDecValid(false, false, (yyvsp[0].symbol), ctx, yylineno);
    }
#line 2321 "src/y.tab.cpp"
    break;

  case 75: /* assign_no_semi: lvalue ASSIGN expression  */
#line 883 "src/p3_parser.y"
                               {
        Symbol* sym = (yyvsp[-2].symbol);
        ExprInfo *exprPtr = (sym != nullptr) ? sym->getExprInfo() : makeInvalidExpr();
        ExprInfo target = *exprPtr; delete exprPtr;
        ExprInfo value = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);
        if (target.isValid && value.isValid) {
            checkAssignment(target, value, yylineno);

            if (value.isConst) {
                switch (target.type->base) {
                    case BK_Int: ctx->fileContent.push_back("        ldc " + std::to_string(value.iVal)); break;
                    case BK_Float: ctx->fileContent.push_back("        ldc " + std::to_string(value.fVal) + "f"); break;
                    case BK_Bool: ctx->fileContent.push_back("        ldc " + std::string(value.bVal ? "1" : "0")); break;
                    case BK_String: ctx->fileContent.push_back("        ldc \"" + value.sVal + "\""); break;
                    default: break;
                }
            }

            if (sym->index == -1) {
                switch (target.type->base) {
                    case BK_Int: ctx->fileContent.push_back("        putstatic int " + sym->name); break;
                    case BK_Float: ctx->fileContent.push_back("        putstatic float " + sym->name); break;
                    case BK_Bool: ctx->fileContent.push_back("        putstatic int " + sym->name); break;
                    default: break;
                }
            } else {
                switch (target.type->base) {
                    case BK_Int: ctx->fileContent.push_back("        istore " + std::to_string(sym->index)); break;
                    case BK_Float: ctx->fileContent.push_back("        fstore " + std::to_string(sym->index)); break;
                    case BK_Bool: ctx->fileContent.push_back("        istore " + std::to_string(sym->index)); break;
                    default: break;                
                }
            }
        }
    }
#line 2361 "src/y.tab.cpp"
    break;

  case 76: /* return_stmt: RETURN expression SEMICOLON  */
#line 922 "src/p3_parser.y"
                                  {
        ExprInfo expr = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
        ctx->returnsExpr.push_back(std::make_pair(expr, yylineno));

        if (expr.isConst) {
            switch (ctx->funcType->base) {
            case BK_Int:
                ctx->fileContent.push_back("        ldc " + std::to_string(expr.iVal));
                break;
            case BK_Float:
                ctx->fileContent.push_back("        ldc " + std::to_string(expr.fVal) + "f");
                break;
            case BK_Bool:
                ctx->fileContent.push_back("        ldc " + std::string(expr.bVal ? "1" : "0"));
                break;
            default:
                SemanticError("unsupported return type", yylineno);
            }
        }

        switch (ctx->funcType->base) {
        case BK_Int:
            ctx->fileContent.push_back("        ireturn");
            break;
        case BK_Float:
            ctx->fileContent.push_back("        freturn");
            break;
        case BK_Bool:
            ctx->fileContent.push_back("        ireturn");
            break;
        default:
            SemanticError("unsupported return type", yylineno);
        }
    }
#line 2400 "src/y.tab.cpp"
    break;

  case 77: /* expression: expression PLUS expression  */
#line 960 "src/p3_parser.y"
                                 {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }else {
            bool isStringConcat = (lhs.type->base == BK_String && rhs.type->base == BK_String);

            if (isStringConcat) {
                (yyval.expr_info) = concatStringResult(lhs, rhs, ctx->typePool, yylineno);
            } else {
                (yyval.expr_info) = numericOpResult(OPADD, lhs, rhs, ctx, yylineno);
            }
        }
    }
#line 2419 "src/y.tab.cpp"
    break;

  case 78: /* expression: expression MINUS expression  */
#line 974 "src/p3_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = numericOpResult(OPSUB, lhs, rhs, ctx, yylineno);
        }
    }
#line 2433 "src/y.tab.cpp"
    break;

  case 79: /* expression: expression MUL expression  */
#line 983 "src/p3_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = numericOpResult(OPMUL, lhs, rhs, ctx, yylineno);
        }
    }
#line 2447 "src/y.tab.cpp"
    break;

  case 80: /* expression: expression DIV expression  */
#line 992 "src/p3_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = numericOpResult(OPDIV, lhs, rhs, ctx, yylineno);
        }
    }
#line 2461 "src/y.tab.cpp"
    break;

  case 81: /* expression: expression MOD expression  */
#line 1001 "src/p3_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = numericOpResult(OPMOD, lhs, rhs, ctx, yylineno);
        }
    }
#line 2475 "src/y.tab.cpp"
    break;

  case 82: /* expression: expression LT expression  */
#line 1010 "src/p3_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = relOpResult(OPLT, lhs , rhs, ctx, yylineno);
        }
    }
#line 2489 "src/y.tab.cpp"
    break;

  case 83: /* expression: expression LE expression  */
#line 1019 "src/p3_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = relOpResult(OPLE, lhs , rhs, ctx, yylineno);
        }
    }
#line 2503 "src/y.tab.cpp"
    break;

  case 84: /* expression: expression GT expression  */
#line 1028 "src/p3_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = relOpResult(OPGT, lhs , rhs, ctx, yylineno);
        }
    }
#line 2517 "src/y.tab.cpp"
    break;

  case 85: /* expression: expression GE expression  */
#line 1037 "src/p3_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = relOpResult(OPGE, lhs , rhs, ctx, yylineno);
        }
    }
#line 2531 "src/y.tab.cpp"
    break;

  case 86: /* expression: expression EQ expression  */
#line 1046 "src/p3_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = eqOpResult(true, lhs, rhs, ctx, yylineno);
        }
    }
#line 2545 "src/y.tab.cpp"
    break;

  case 87: /* expression: expression NEQ expression  */
#line 1055 "src/p3_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = eqOpResult(false, lhs, rhs, ctx, yylineno);
        }
    }
#line 2559 "src/y.tab.cpp"
    break;

  case 88: /* expression: expression AND expression  */
#line 1064 "src/p3_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = boolOpResult(true, lhs , rhs, ctx, yylineno);
        }   
    }
#line 2573 "src/y.tab.cpp"
    break;

  case 89: /* expression: expression OR expression  */
#line 1073 "src/p3_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = boolOpResult(false, lhs , rhs, ctx, yylineno);
        }
    }
#line 2587 "src/y.tab.cpp"
    break;

  case 90: /* expression: NOT expression  */
#line 1082 "src/p3_parser.y"
                                    {
        ExprInfo expr = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);
        if(!expr.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = notOpResult(expr, ctx, yylineno);
        }
    }
#line 2601 "src/y.tab.cpp"
    break;

  case 91: /* expression: MINUS expression  */
#line 1091 "src/p3_parser.y"
                                    {
        ExprInfo expr = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);
        if(!expr.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = unaryOpResult(true, expr, ctx, yylineno);
        }
    }
#line 2615 "src/y.tab.cpp"
    break;

  case 92: /* expression: PLUS expression  */
#line 1100 "src/p3_parser.y"
                                    {
        ExprInfo expr = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);
        if(!expr.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = unaryOpResult(false, expr, ctx, yylineno);
        }
    }
#line 2629 "src/y.tab.cpp"
    break;

  case 93: /* expression: INC lvalue  */
#line 1109 "src/p3_parser.y"
                                {
        (yyval.expr_info) = checkIncDecValid(true, true, (yyvsp[0].symbol), ctx, yylineno);
     }
#line 2637 "src/y.tab.cpp"
    break;

  case 94: /* expression: DEC lvalue  */
#line 1112 "src/p3_parser.y"
                                {
        (yyval.expr_info) = checkIncDecValid(false, true, (yyvsp[0].symbol), ctx, yylineno);
     }
#line 2645 "src/y.tab.cpp"
    break;

  case 95: /* expression: lvalue INC  */
#line 1115 "src/p3_parser.y"
                               {
        (yyval.expr_info) = checkIncDecValid(true, true, (yyvsp[-1].symbol), ctx, yylineno);
     }
#line 2653 "src/y.tab.cpp"
    break;

  case 96: /* expression: lvalue DEC  */
#line 1118 "src/p3_parser.y"
                               {
        (yyval.expr_info) = checkIncDecValid(false, true, (yyvsp[-1].symbol), ctx, yylineno);
    }
#line 2661 "src/y.tab.cpp"
    break;

  case 97: /* expression: LPAREN expression RPAREN  */
#line 1121 "src/p3_parser.y"
                                     { 
        if (!(yyvsp[-1].expr_info)->isValid) {
            delete (yyvsp[-1].expr_info);
            (yyval.expr_info) = makeInvalidExpr();
        }else{
            (yyval.expr_info) = (yyvsp[-1].expr_info);
        }
    }
#line 2674 "src/y.tab.cpp"
    break;

  case 98: /* expression: lvalue  */
#line 1129 "src/p3_parser.y"
                                     {
        Symbol* sym = (yyvsp[0].symbol);
        ExprInfo *exprPtr = (sym != nullptr) ? sym->getExprInfo() : makeInvalidExpr();
        
        if (!exprPtr->isValid) {
            delete exprPtr;
            (yyval.expr_info) = makeInvalidExpr();
        }else{
            (yyval.expr_info) = exprPtr;
        }

        if(sym != nullptr) {
            if (sym->index == -1) {
                if (sym->type->base == BK_Int) {
                    ctx->fileContent.push_back("        getstatic int " + sym->name);
                } else if (sym->type->base == BK_Float) {
                    ctx->fileContent.push_back("        getstatic float " + sym->name);
                } else if (sym->type->base == BK_Bool) {
                    ctx->fileContent.push_back("        getstatic int " + sym->name);
                }
            } else {
                if (sym->type->base == BK_Int) {
                    ctx->fileContent.push_back("        iload " + std::to_string(sym->index));
                } else if (sym->type->base == BK_Float) {
                    ctx->fileContent.push_back("        fload " + std::to_string(sym->index));
                } else if (sym->type->base == BK_Bool) {
                    ctx->fileContent.push_back("        iload " + std::to_string(sym->index));
                }
            }
        }
    }
#line 2710 "src/y.tab.cpp"
    break;

  case 99: /* expression: const_lit  */
#line 1160 "src/p3_parser.y"
                                     { 
        if (!(yyvsp[0].expr_info)->isValid) {
            delete (yyvsp[0].expr_info);
            (yyval.expr_info) = makeInvalidExpr();
        }else{
            (yyval.expr_info) = (yyvsp[0].expr_info);
        }
    }
#line 2723 "src/y.tab.cpp"
    break;

  case 100: /* expression: func_call  */
#line 1168 "src/p3_parser.y"
                                     { 
        if (!(yyvsp[0].expr_info)->isValid) {
            delete (yyvsp[0].expr_info);
            (yyval.expr_info) = makeInvalidExpr();
        }else{
            (yyval.expr_info) = (yyvsp[0].expr_info);
        }
    }
#line 2736 "src/y.tab.cpp"
    break;

  case 101: /* const_lit: INT_LIT  */
#line 1180 "src/p3_parser.y"
                  { 
        (yyval.expr_info) = new ExprInfo(ctx->typePool.make(BK_Int), true);
        (yyval.expr_info)->setInt((yyvsp[0].ival));
    }
#line 2745 "src/y.tab.cpp"
    break;

  case 102: /* const_lit: REAL_LIT  */
#line 1184 "src/p3_parser.y"
                  {
        (yyval.expr_info) = new ExprInfo(ctx->typePool.make(BK_Float), true);
        (yyval.expr_info)->setFloat((yyvsp[0].fval));
    }
#line 2754 "src/y.tab.cpp"
    break;

  case 103: /* const_lit: BOOL_LIT  */
#line 1188 "src/p3_parser.y"
                  {
        (yyval.expr_info) = new ExprInfo(ctx->typePool.make(BK_Bool), true);
        (yyval.expr_info)->setBool((yyvsp[0].bval));
    }
#line 2763 "src/y.tab.cpp"
    break;

  case 104: /* const_lit: STRING_LIT  */
#line 1192 "src/p3_parser.y"
                  { 
        (yyval.expr_info) = new ExprInfo(ctx->typePool.make(BK_String), true);
        (yyval.expr_info)->setString(*(yyvsp[0].sval));
        delete (yyvsp[0].sval);
    }
#line 2773 "src/y.tab.cpp"
    break;

  case 105: /* func_call: ID LPAREN arg_list_opt RPAREN  */
#line 1201 "src/p3_parser.y"
                                    {
        Symbol* symbol = ctx->symTab.lookup(*(yyvsp[-3].sval));
        std::string funcName = *(yyvsp[-3].sval); delete (yyvsp[-3].sval);
        std::vector<ExprInfo> args = *(yyvsp[-1].expr_info_list); delete (yyvsp[-1].expr_info_list);

        if (symbol != nullptr) {
            if (symbol->type->base == BK_Void) {
                SemanticError("function " + funcName + " should not return value", yylineno);
                (yyval.expr_info) = makeInvalidExpr();
            }else{
                if (checkFuncCall(symbol, funcName, args, yylineno)){
                    (yyval.expr_info) = new ExprInfo(symbol->type->ret);
                    std::string call = "        invokestatic ";
                    call += symbol->type->ret->base == BK_Void ? "void " : baseKindToJavaStr(symbol->type->ret->base) + " ";
                    call += funcName + "(";
                    for (int i = 0; i < args.size(); ++i) {
                        if (i > 0) call += ", ";
                        switch (args[i].type->base) {
                            case BK_Int: call += "int"; break;
                            case BK_Float: call += "float"; break;
                            case BK_Bool: call += "int"; break;
                            default: SemanticError("unsupported argument type in function call", yylineno);
                        }
                    }
                    call += ")";
                    ctx->fileContent.push_back(call);

                }else{
                    (yyval.expr_info) = makeInvalidExpr();
                }
            }
        }else {
            SemanticError("undeclared function: " + funcName, yylineno);
            (yyval.expr_info) = makeInvalidExpr();
        }
    }
#line 2814 "src/y.tab.cpp"
    break;

  case 106: /* proc_call: ID LPAREN arg_list_opt RPAREN  */
#line 1239 "src/p3_parser.y"
                                    {
        Symbol* symbol = ctx->symTab.lookup(*(yyvsp[-3].sval));
        std::string funcName = *(yyvsp[-3].sval); delete (yyvsp[-3].sval);
        std::vector<ExprInfo> args = *(yyvsp[-1].expr_info_list); delete (yyvsp[-1].expr_info_list);
        if (symbol != nullptr){
            checkFuncCall(symbol, funcName, args, yylineno);
            if (symbol->type->base != BK_Void) {
                SemanticError("function " + funcName + " should get return value", yylineno);
            }else{
                std::string call = "        invokestatic ";
                call += "void " + funcName + "(";
                for (int i = 0; i < args.size(); ++i) {
                    if (i > 0) call += ", ";
                    switch (args[i].type->base) {
                        case BK_Int: call += "int"; break;
                        case BK_Float: call += "float"; break;
                        case BK_Bool: call += "int"; break;
                        default: SemanticError("unsupported argument type in function call", yylineno);
                    }
                }
                call += ")";
                ctx->fileContent.push_back(call);
            }
        }else{
            SemanticError("undeclared function: " + funcName, yylineno);
        }
    }
#line 2846 "src/y.tab.cpp"
    break;

  case 107: /* arg_list_opt: %empty  */
#line 1269 "src/p3_parser.y"
                 { (yyval.expr_info_list) = new std::vector<ExprInfo>();}
#line 2852 "src/y.tab.cpp"
    break;

  case 108: /* arg_list_opt: arg_list  */
#line 1270 "src/p3_parser.y"
               { (yyval.expr_info_list) = (yyvsp[0].expr_info_list); }
#line 2858 "src/y.tab.cpp"
    break;

  case 109: /* arg_list: expression  */
#line 1274 "src/p3_parser.y"
                 {
        if ((yyvsp[0].expr_info)->isConst) {
            switch ((yyvsp[0].expr_info)->type->base) {
                case BK_Int: ctx->fileContent.push_back("        ldc " + std::to_string((yyvsp[0].expr_info)->iVal)); break;
                case BK_Float: ctx->fileContent.push_back("        ldc " + std::to_string((yyvsp[0].expr_info)->fVal) + "f"); break;
                case BK_Bool: ctx->fileContent.push_back("        ldc " + std::string((yyvsp[0].expr_info)->bVal ? "1" : "0")); break;
                case BK_String: ctx->fileContent.push_back("        ldc \"" + (yyvsp[0].expr_info)->sVal + "\""); break;
                default: break;
            }
        }

        (yyval.expr_info_list) = new std::vector<ExprInfo>();
        (yyval.expr_info_list)->push_back(*(yyvsp[0].expr_info));
        delete (yyvsp[0].expr_info);
    }
#line 2878 "src/y.tab.cpp"
    break;

  case 110: /* arg_list: arg_list COMMA expression  */
#line 1289 "src/p3_parser.y"
                               {
        if ((yyvsp[0].expr_info)->isConst) {
            switch ((yyvsp[0].expr_info)->type->base) {
                case BK_Int: ctx->fileContent.push_back("        ldc " + std::to_string((yyvsp[0].expr_info)->iVal)); break;
                case BK_Float: ctx->fileContent.push_back("        ldc " + std::to_string((yyvsp[0].expr_info)->fVal) + "f"); break;
                case BK_Bool: ctx->fileContent.push_back("        ldc " + std::string((yyvsp[0].expr_info)->bVal ? "1" : "0")); break;
                case BK_String: ctx->fileContent.push_back("        ldc \"" + (yyvsp[0].expr_info)->sVal + "\""); break;
                default: break;
            }
        }

        (yyval.expr_info_list) = (yyvsp[-2].expr_info_list);
        (yyval.expr_info_list)->push_back(*(yyvsp[0].expr_info));
        delete (yyvsp[0].expr_info);
    }
#line 2898 "src/y.tab.cpp"
    break;

  case 111: /* type_spec: INT_TOK  */
#line 1308 "src/p3_parser.y"
                 { (yyval.type) = ctx->typePool.make(BK_Int); ctx->nowType = (yyval.type); }
#line 2904 "src/y.tab.cpp"
    break;

  case 112: /* type_spec: FLOAT_TOK  */
#line 1309 "src/p3_parser.y"
                     { (yyval.type) = ctx->typePool.make(BK_Float); ctx->nowType = (yyval.type); }
#line 2910 "src/y.tab.cpp"
    break;

  case 113: /* type_spec: BOOL_TOK  */
#line 1310 "src/p3_parser.y"
                     { (yyval.type) = ctx->typePool.make(BK_Bool);  ctx->nowType = (yyval.type); }
#line 2916 "src/y.tab.cpp"
    break;

  case 114: /* type_spec: STRING_TOK  */
#line 1311 "src/p3_parser.y"
                 { (yyval.type) = ctx->typePool.make(BK_String); ctx->nowType = (yyval.type);}
#line 2922 "src/y.tab.cpp"
    break;


#line 2926 "src/y.tab.cpp"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 1314 "src/p3_parser.y"
 

int main(int argc, char* argv[]) {
    // Check if the number of arguments is correct
    if (argc != 2) {
        std::puts("Usage: sd <source-file>");
        return 1;
    }

    // Try to open the input file
    if (!(yyin = std::fopen(argv[1], "r"))) {
        perror("open"); // Print system error message
        return 1;
    }

    std::filesystem::path p(argv[1]);
    std::string fileName = p.stem().string() + ".j";
    std::string baseName = p.stem().string();

    // Initialize semantic analysis context
    Context context;
    ctx = &context;

    ctx->fileContent.push_back("class " + baseName);
    ctx->fileContent.push_back("{");
    int result = yyparse();
    ctx->fileContent.push_back("}");

    std::ofstream outputFile(fileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    for (const auto& line : ctx->fileContent) {
        outputFile << line << "\n";
    }

    outputFile.close();

    if (SemanticWarning::hasWarning()) {
        SemanticWarning::printAllWarning();
    }
    
    if (SemanticError::hasError()) {
        SemanticError::printAllError();
        result += 2;
    }

    if (SemanticError::hasError() || result != 0) {
        std::filesystem::remove(fileName.c_str()); // Remove the output file if there are errors
    }

    return result;
}
