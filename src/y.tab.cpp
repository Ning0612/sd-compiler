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
  YYSYMBOL_if_prefix = 90,                 /* if_prefix  */
  YYSYMBOL_opt_else = 91,                  /* opt_else  */
  YYSYMBOL_92_4 = 92,                      /* $@4  */
  YYSYMBOL_if_stmt = 93,                   /* if_stmt  */
  YYSYMBOL_loop_stmt = 94,                 /* loop_stmt  */
  YYSYMBOL_for_simple_opt = 95,            /* for_simple_opt  */
  YYSYMBOL_for_simple_item = 96,           /* for_simple_item  */
  YYSYMBOL_assign_no_semi = 97,            /* assign_no_semi  */
  YYSYMBOL_return_stmt = 98,               /* return_stmt  */
  YYSYMBOL_expression = 99,                /* expression  */
  YYSYMBOL_const_lit = 100,                /* const_lit  */
  YYSYMBOL_func_call = 101,                /* func_call  */
  YYSYMBOL_proc_call = 102,                /* proc_call  */
  YYSYMBOL_arg_list_opt = 103,             /* arg_list_opt  */
  YYSYMBOL_arg_list = 104,                 /* arg_list  */
  YYSYMBOL_type_spec = 105                 /* type_spec  */
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
#define YYLAST   508

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  218

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
     400,   419,   438,   445,   448,   451,   454,   457,   461,   499,
     514,   530,   529,   548,   556,   561,   565,   569,   573,   585,
     586,   587,   591,   592,   611,   630,   636,   639,   642,   645,
     651,   690,   707,   721,   730,   739,   748,   757,   766,   775,
     784,   793,   802,   811,   820,   829,   838,   847,   856,   859,
     862,   865,   868,   876,   907,   915,   927,   931,   935,   939,
     948,   986,  1016,  1017,  1021,  1036,  1055,  1056,  1057,  1058
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
  "statement", "simple_stmt", "assign_stmt", "lvalue", "if_prefix",
  "opt_else", "$@4", "if_stmt", "loop_stmt", "for_simple_opt",
  "for_simple_item", "assign_no_semi", "return_stmt", "expression",
  "const_lit", "func_call", "proc_call", "arg_list_opt", "arg_list",
  "type_spec", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-103)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -103,     4,   140,  -103,  -103,  -103,  -103,  -103,     0,    32,
    -103,  -103,  -103,  -103,    16,     5,    36,   -28,   -41,  -103,
      32,    21,    96,    32,    45,  -103,    22,    25,  -103,    60,
      96,    39,  -103,  -103,  -103,  -103,    96,    96,    96,    66,
      66,    96,   -31,   430,  -103,  -103,    50,    56,  -103,    49,
      32,  -103,   286,    96,  -103,  -103,   459,  -103,  -103,  -103,
     164,  -103,  -103,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    53,  -103,  -103,  -103,
     430,    58,    61,  -103,   470,   470,   470,   470,   470,   470,
      43,    43,  -103,  -103,  -103,   459,   445,  -103,    14,  -103,
      96,    14,    63,   168,    69,    78,    80,    96,    96,    96,
      66,    83,    66,    66,  -103,  -103,  -103,  -103,  -103,  -103,
      79,    14,  -103,  -103,  -103,  -103,    26,   168,  -103,  -103,
    -103,    86,    45,   430,    81,    96,   128,    96,    73,   119,
     307,   328,   349,   102,    96,   103,   104,    14,  -103,  -103,
      96,   105,   106,    98,  -103,  -103,   194,   109,   217,    96,
      96,    66,    66,    66,    55,    57,  -103,  -103,   108,  -103,
    -103,  -103,  -103,   110,  -103,  -103,   111,   370,  -103,  -103,
    -103,  -103,  -103,    96,   168,   430,   430,  -103,  -103,  -103,
      96,  -103,  -103,    73,    96,    96,  -103,  -103,  -103,   168,
     240,  -103,   430,  -103,   391,   412,  -103,   115,    73,   114,
    -103,   -40,    96,   168,   263,  -103,   168,  -103
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,   108,   107,   106,   109,     0,     0,
       4,     5,     6,     7,     0,     0,     0,    14,     0,    12,
      20,     0,     0,    20,     0,    11,     0,    21,    22,     0,
       0,    49,    96,    97,    99,    98,     0,     0,     0,     0,
       0,     0,    93,    15,    94,    95,     0,    14,    13,     0,
       0,    24,     0,   102,    87,    86,    85,    49,    88,    89,
       0,    90,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,    23,    10,
     104,     0,   103,    92,    78,    80,    81,    82,    77,    79,
      72,    73,    74,    75,    76,    83,    84,    16,    27,   100,
       0,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,     0,     0,    47,    25,    31,     8,     9,    38,
       0,    28,    30,    32,    33,    39,     0,     0,    34,    35,
      36,     0,     0,   105,     0,     0,     0,     0,    59,     0,
       0,     0,     0,     0,   102,     0,     0,    27,    19,    29,
       0,     0,     0,    53,    37,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,    62,     0,    71,
      40,    41,    42,     0,    45,    46,     0,     0,    43,    44,
      51,    54,    50,     0,     0,    63,    64,    65,    68,    69,
       0,    66,    67,     0,     0,     0,   101,    26,    48,     0,
       0,    55,    70,    61,     0,     0,    52,     0,    59,     0,
      56,     0,     0,     0,     0,    57,     0,    58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -103,  -103,  -103,  -103,  -103,   162,   165,  -103,   142,  -103,
    -103,  -103,   146,  -103,   120,  -103,  -103,   -92,  -103,    64,
    -102,  -103,  -103,   -37,  -103,  -103,  -103,  -103,  -103,   -34,
     -18,  -103,  -103,   -22,  -103,  -103,  -103,    33,  -103,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    10,   116,   117,   118,    18,    19,    13,
     101,    98,    26,    27,    28,   119,   147,   120,   121,   122,
     123,   124,   125,    42,   127,   181,   199,   128,   129,   165,
     166,   167,   130,    80,    44,    45,   131,    81,    82,   132
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,   136,    58,    59,     3,    24,   193,    25,    52,   134,
     213,    22,    61,    62,    54,    55,    56,     4,     5,    60,
       6,    23,     7,    15,   102,   153,   103,   104,   105,   106,
     107,     9,   108,   109,   110,     4,     5,   111,     6,    17,
       7,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    20,   176,    14,   112,   113,    21,
      30,   126,   114,    16,   126,   150,   126,   115,    47,   151,
     152,    50,    49,   143,    29,   145,   146,    29,   133,    71,
      72,    73,   201,    51,   126,   140,   141,   142,    53,    57,
     126,   159,   160,   161,   190,    22,    57,   206,   191,   192,
      76,   164,    77,   193,    29,   194,    97,   100,    99,   180,
     126,   215,   135,   156,   217,   158,   162,   163,   137,    31,
      32,    33,    34,    35,   187,   188,   189,   138,   177,   139,
      36,    37,   144,   148,   154,   155,    38,   185,   186,    39,
      40,   157,   168,     4,     5,    41,     6,   126,     7,     8,
     172,   174,   175,   178,   179,   195,   164,     9,   183,   212,
     196,   200,   126,   210,    11,   197,    48,    12,   202,    46,
      78,   164,   204,   205,   211,   203,   126,   173,   102,   126,
     103,   104,   105,   106,   107,   149,   108,   109,   110,     0,
     214,   111,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,     0,    74,    75,     0,     0,     0,
       0,   112,   113,     0,    83,     0,   114,     0,     0,     0,
       0,   115,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,     0,    74,    75,     0,     0,     0,
       0,     0,     0,     0,   182,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     0,     0,    74,    75,
       0,     0,     0,     0,     0,     0,     0,   184,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,    74,    75,     0,     0,     0,     0,     0,     0,     0,
     207,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     0,     0,    74,    75,     0,     0,     0,     0,
       0,     0,     0,   216,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,    74,    75,     0,
       0,     0,     0,     0,    79,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     0,     0,    74,    75,
       0,     0,     0,     0,     0,   169,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,     0,    74,
      75,     0,     0,     0,     0,     0,   170,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,     0,
      74,    75,     0,     0,     0,     0,     0,   171,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,    74,    75,     0,     0,     0,     0,     0,   198,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,     0,    74,    75,     0,     0,     0,     0,     0,   208,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,    74,    75,     0,     0,   209,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,    74,    75,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,    74,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73
};

static const yytype_int16 yycheck[] =
{
      22,   103,    39,    40,     0,    46,    46,    48,    30,   101,
      50,    39,    43,    44,    36,    37,    38,     3,     4,    41,
       6,    49,     8,    23,    10,   127,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     3,     4,    23,     6,    23,
       8,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    49,   147,     2,    43,    44,    23,
      39,    98,    48,     9,   101,    39,   103,    53,    23,    43,
      44,    46,    50,   110,    20,   112,   113,    23,   100,    36,
      37,    38,   184,    23,   121,   107,   108,   109,    49,    23,
     127,    18,    19,    20,    39,    39,    23,   199,    43,    44,
      50,   138,    53,    46,    50,    48,    53,    46,    50,    11,
     147,   213,    49,   135,   216,   137,    43,    44,    49,    23,
      24,    25,    26,    27,   161,   162,   163,    49,   150,    49,
      34,    35,    49,    54,    48,    54,    40,   159,   160,    43,
      44,    13,    23,     3,     4,    49,     6,   184,     8,     9,
      48,    48,    48,    48,    48,    47,   193,    17,    49,    45,
      50,   183,   199,    48,     2,    54,    24,     2,   190,    23,
      50,   208,   194,   195,   208,   193,   213,   144,    10,   216,
      12,    13,    14,    15,    16,   121,    18,    19,    20,    -1,
     212,    23,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    41,    42,    -1,    -1,    -1,
      -1,    43,    44,    -1,    50,    -1,    48,    -1,    -1,    -1,
      -1,    53,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    41,    42,    -1,
      -1,    -1,    -1,    -1,    48,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    41,    42,
      -1,    -1,    -1,    -1,    -1,    48,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    41,
      42,    -1,    -1,    -1,    -1,    -1,    48,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      41,    42,    -1,    -1,    -1,    -1,    -1,    48,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    48,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    48,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    41,    42,    -1,    -1,    45,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    41,    42,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    41,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    67,    68,     0,     3,     4,     6,     8,     9,    17,
      69,    71,    72,    75,   105,    23,   105,    23,    73,    74,
      49,    23,    39,    49,    46,    48,    78,    79,    80,   105,
      39,    23,    24,    25,    26,    27,    34,    35,    40,    43,
      44,    49,    89,    99,   100,   101,    78,    23,    74,    50,
      46,    23,    99,    49,    99,    99,    99,    23,    89,    89,
      99,    43,    44,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    41,    42,    50,    53,    80,    48,
      99,   103,   104,    50,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    53,    77,    50,
      46,    76,    10,    12,    13,    14,    15,    16,    18,    19,
      20,    23,    43,    44,    48,    53,    70,    71,    72,    81,
      83,    84,    85,    86,    87,    88,    89,    90,    93,    94,
      98,   102,   105,    99,    83,    49,    86,    49,    49,    49,
      99,    99,    99,    89,    49,    89,    89,    82,    54,    85,
      39,    43,    44,    86,    48,    54,    99,    13,    99,    18,
      19,    20,    43,    44,    89,    95,    96,    97,    23,    48,
      48,    48,    48,   103,    48,    48,    83,    99,    48,    48,
      11,    91,    50,    49,    50,    99,    99,    89,    89,    89,
      39,    43,    44,    46,    48,    47,    50,    54,    48,    92,
      99,    86,    99,    96,    99,    99,    86,    50,    48,    45,
      48,    95,    45,    50,    99,    86,    50,    86
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    66,    67,    68,    68,    69,    69,    69,    70,    70,
      71,    72,    73,    73,    74,    74,    76,    75,    77,    75,
      78,    78,    79,    79,    80,    82,    81,    83,    83,    84,
      84,    85,    85,    86,    86,    86,    86,    86,    86,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    88,    89,
      90,    92,    91,    91,    93,    94,    94,    94,    94,    95,
      95,    95,    96,    96,    96,    96,    96,    96,    96,    96,
      97,    98,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,   100,   100,   100,   100,
     101,   102,   103,   103,   104,   104,   105,   105,   105,   105
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       6,     3,     1,     3,     1,     3,     0,     9,     0,     9,
       0,     1,     1,     3,     2,     0,     4,     0,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     1,     4,     1,
       4,     0,     3,     0,     3,     5,     7,     9,    10,     0,
       1,     3,     1,     2,     2,     2,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     0,     1,     1,     3,     1,     1,     1,     1
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
#line 1409 "src/y.tab.cpp"
    break;

  case 10: /* const_decl: CONST type_spec ID ASSIGN expression SEMICOLON  */
#line 130 "src/p3_parser.y"
                                                   {
        std::string id = *(yyvsp[-3].sval); delete (yyvsp[-3].sval);
        ExprInfo value = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
        tryDeclareConstant(ctx->symTab, id, (yyvsp[-4].type), value, yylineno);
    }
#line 1419 "src/y.tab.cpp"
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
#line 1463 "src/y.tab.cpp"
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
#line 1507 "src/y.tab.cpp"
    break;

  case 14: /* var_init: ID  */
#line 224 "src/p3_parser.y"
                             { (yyval.var_init_) = new VarInit(*(yyvsp[0].sval), ctx->nowType); delete (yyvsp[0].sval); }
#line 1513 "src/y.tab.cpp"
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
#line 1535 "src/y.tab.cpp"
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
#line 1565 "src/y.tab.cpp"
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
#line 1593 "src/y.tab.cpp"
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
#line 1627 "src/y.tab.cpp"
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
#line 1643 "src/y.tab.cpp"
    break;

  case 20: /* param_list_opt: %empty  */
#line 336 "src/p3_parser.y"
                {
        (yyval.symbol_list) = new std::vector<Symbol>();
    }
#line 1651 "src/y.tab.cpp"
    break;

  case 21: /* param_list_opt: param_list  */
#line 339 "src/p3_parser.y"
                 {
        (yyval.symbol_list) = (yyvsp[0].symbol_list);
    }
#line 1659 "src/y.tab.cpp"
    break;

  case 22: /* param_list: param  */
#line 345 "src/p3_parser.y"
            {
        (yyval.symbol_list) = new std::vector<Symbol>;
        (yyval.symbol_list)->push_back(*(yyvsp[0].symbol));
        delete (yyvsp[0].symbol);
    }
#line 1669 "src/y.tab.cpp"
    break;

  case 23: /* param_list: param_list COMMA param  */
#line 350 "src/p3_parser.y"
                             {
        (yyval.symbol_list) = (yyvsp[-2].symbol_list);
        (yyval.symbol_list)->push_back(*(yyvsp[0].symbol));
        delete (yyvsp[0].symbol);
    }
#line 1679 "src/y.tab.cpp"
    break;

  case 24: /* param: type_spec ID  */
#line 358 "src/p3_parser.y"
                   {
        std::string id = *(yyvsp[0].sval); delete (yyvsp[0].sval);
        (yyval.symbol) = new Symbol(id, (yyvsp[-1].type), false);
    }
#line 1688 "src/y.tab.cpp"
    break;

  case 25: /* $@3: %empty  */
#line 366 "src/p3_parser.y"
             {
        ctx->symTab.enterScope();
    }
#line 1696 "src/y.tab.cpp"
    break;

  case 26: /* block: LBRACE $@3 block_items_opt RBRACE  */
#line 368 "src/p3_parser.y"
                             {
        ctx->symTab.leaveScope();
    }
#line 1704 "src/y.tab.cpp"
    break;

  case 40: /* simple_stmt: PRINT expression SEMICOLON  */
#line 400 "src/p3_parser.y"
                                 {
        ExprInfo expr = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
        if (expr.isValid) checkPrint(expr, yylineno);

        ctx->fileContent.push_back("        getstatic java.io.PrintStream java.lang.System.out\n");
        if (expr.isConst) {
            emitConst(expr, ctx);
        } else {
            ctx->fileContent.push_back("        swap");
        }

        switch (expr.type->base) {
            case BK_Int: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(int)"); break;
            case BK_Float: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(float)"); break;
            case BK_Bool: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(boolean)"); break;
            case BK_String: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(java.lang.String)"); break;
            default: SemanticError("unsupported type for println", yylineno);
        }
    }
#line 1728 "src/y.tab.cpp"
    break;

  case 41: /* simple_stmt: PRINTLN expression SEMICOLON  */
#line 419 "src/p3_parser.y"
                                   {
        ExprInfo expr = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
        if (expr.isValid) checkPrint(expr, yylineno);

        ctx->fileContent.push_back("        getstatic java.io.PrintStream java.lang.System.out\n");
        if (expr.isConst) {
            emitConst(expr, ctx);
        } else {
            ctx->fileContent.push_back("        swap");
        }

        switch (expr.type->base) {
            case BK_Int: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(int)"); break;
            case BK_Float: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(float)"); break;
            case BK_Bool: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(boolean)"); break;
            case BK_String: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(java.lang.String)"); break;
            default: SemanticError("unsupported type for println", yylineno);
        }
    }
#line 1752 "src/y.tab.cpp"
    break;

  case 42: /* simple_stmt: READ lvalue SEMICOLON  */
#line 438 "src/p3_parser.y"
                            {
        Symbol* sym = (yyvsp[-1].symbol);
        ExprInfo *exprPtr = (sym != nullptr) ? sym->getExprInfo() : makeInvalidExpr();
        ExprInfo expr = *exprPtr; delete exprPtr;
        if (expr.isValid) checkRead(expr, yylineno);
        SemanticError("read statement not supported in code generation", yylineno);
    }
#line 1764 "src/y.tab.cpp"
    break;

  case 43: /* simple_stmt: lvalue INC SEMICOLON  */
#line 445 "src/p3_parser.y"
                           {
        if ((yyvsp[-2].symbol) != nullptr) delete checkIncDecValid(true, false, (yyvsp[-2].symbol), ctx, yylineno);
     }
#line 1772 "src/y.tab.cpp"
    break;

  case 44: /* simple_stmt: lvalue DEC SEMICOLON  */
#line 448 "src/p3_parser.y"
                           {
        if ((yyvsp[-2].symbol) != nullptr) delete checkIncDecValid(false, false, (yyvsp[-2].symbol), ctx, yylineno);
     }
#line 1780 "src/y.tab.cpp"
    break;

  case 45: /* simple_stmt: INC lvalue SEMICOLON  */
#line 451 "src/p3_parser.y"
                           {
        if ((yyvsp[-1].symbol) != nullptr) delete checkIncDecValid(true, false, (yyvsp[-1].symbol), ctx, yylineno);
     }
#line 1788 "src/y.tab.cpp"
    break;

  case 46: /* simple_stmt: DEC lvalue SEMICOLON  */
#line 454 "src/p3_parser.y"
                           {
        if ((yyvsp[-1].symbol) != nullptr) delete checkIncDecValid(false, false, (yyvsp[-1].symbol), ctx, yylineno);
    }
#line 1796 "src/y.tab.cpp"
    break;

  case 48: /* assign_stmt: lvalue ASSIGN expression SEMICOLON  */
#line 461 "src/p3_parser.y"
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
#line 1835 "src/y.tab.cpp"
    break;

  case 49: /* lvalue: ID  */
#line 499 "src/p3_parser.y"
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
#line 1851 "src/y.tab.cpp"
    break;

  case 50: /* if_prefix: IF LPAREN expression RPAREN  */
#line 515 "src/p3_parser.y"
      {
          ExprInfo expr = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
          if (expr.isValid) checkBoolExpr("if", expr, yylineno);
          if (expr.isConst) emitConst(expr, ctx);

          /* 先預設 false-label */
          ctx->fileContent.push_back("        ifeq LFalse" + std::to_string(ctx->ifFalseLabelCounter));
          ctx->ifFalseLabels.push_back(ctx->ifFalseLabelCounter);
          ctx->ifFalseLabelCounter++;
      }
#line 1866 "src/y.tab.cpp"
    break;

  case 51: /* $@4: %empty  */
#line 530 "src/p3_parser.y"
      {
        /* 這裡放你原本 $@4 的動作：從 then 區塊跳到 exit */
        ctx->fileContent.push_back("        goto LExit" + std::to_string(ctx->ifExitLabelCounter));
        ctx->ifExitLabels.push_back(ctx->ifExitLabelCounter);
        ctx->ifExitLabelCounter++;

        ctx->fileContent.push_back("LFalse" + std::to_string(ctx->ifFalseLabels.back()) + ":");
        ctx->ifFalseLabels.pop_back();
        ctx->fileContent.push_back("        nop");

      }
#line 1882 "src/y.tab.cpp"
    break;

  case 52: /* opt_else: ELSE $@4 statement  */
#line 542 "src/p3_parser.y"
      {
        ctx->fileContent.push_back("LExit" + std::to_string(ctx->ifExitLabels.back()) + ":");
        ctx->ifExitLabels.pop_back();
        ctx->fileContent.push_back("        nop");
      }
#line 1892 "src/y.tab.cpp"
    break;

  case 53: /* opt_else: %empty  */
#line 548 "src/p3_parser.y"
      {
        ctx->fileContent.push_back("LFalse" + std::to_string(ctx->ifFalseLabels.back()) + ":");
        ctx->ifFalseLabels.pop_back();
        ctx->fileContent.push_back("        nop");
      }
#line 1902 "src/y.tab.cpp"
    break;

  case 55: /* loop_stmt: WHILE LPAREN expression RPAREN statement  */
#line 561 "src/p3_parser.y"
                                              { 
        ExprInfo expr = *(yyvsp[-2].expr_info); delete (yyvsp[-2].expr_info);
        if (expr.isValid) checkBoolExpr("while", expr, yylineno); 
    }
#line 1911 "src/y.tab.cpp"
    break;

  case 56: /* loop_stmt: DO statement WHILE LPAREN expression RPAREN SEMICOLON  */
#line 565 "src/p3_parser.y"
                                                            {
        ExprInfo expr = *(yyvsp[-2].expr_info); delete (yyvsp[-2].expr_info);
        if (expr.isValid) checkBoolExpr("do while", expr, yylineno);
    }
#line 1920 "src/y.tab.cpp"
    break;

  case 57: /* loop_stmt: FOR LPAREN for_simple_opt SEMICOLON expression SEMICOLON for_simple_opt RPAREN statement  */
#line 569 "src/p3_parser.y"
                                                                                              {
        ExprInfo expr = *(yyvsp[-4].expr_info); delete (yyvsp[-4].expr_info);
        if (expr.isValid) checkBoolExpr("for", expr, yylineno);
    }
#line 1929 "src/y.tab.cpp"
    break;

  case 58: /* loop_stmt: FOREACH LPAREN ID COLON expression DOT DOT expression RPAREN statement  */
#line 573 "src/p3_parser.y"
                                                                            {
        ExprInfo from = *(yyvsp[-5].expr_info); ExprInfo to = *(yyvsp[-2].expr_info); delete (yyvsp[-5].expr_info); delete (yyvsp[-2].expr_info);
        std::string id = *(yyvsp[-7].sval); delete (yyvsp[-7].sval);
        if (from.isValid && to.isValid) {
            checkForeachRange(from, to, yylineno);
        }
        checkForeachIndex(ctx->symTab.lookup(id), yylineno);
    }
#line 1942 "src/y.tab.cpp"
    break;

  case 63: /* for_simple_item: PRINT expression  */
#line 592 "src/p3_parser.y"
                         {
        ExprInfo expr = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);
        if (expr.isValid) checkPrint(expr, yylineno);

        ctx->fileContent.push_back("        getstatic java.io.PrintStream java.lang.System.out\n");
        if (expr.isConst) {
            emitConst(expr, ctx);
        } else {
            ctx->fileContent.push_back("        swap");
        }

        switch (expr.type->base) {
            case BK_Int: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(int)"); break;
            case BK_Float: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(float)"); break;
            case BK_Bool: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(boolean)"); break;
            case BK_String: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.print(java.lang.String)"); break;
            default: SemanticError("unsupported type for println", yylineno);
        }
    }
#line 1966 "src/y.tab.cpp"
    break;

  case 64: /* for_simple_item: PRINTLN expression  */
#line 611 "src/p3_parser.y"
                          {
        ExprInfo expr = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);
        if (expr.isValid) checkPrint(expr, yylineno);

        ctx->fileContent.push_back("        getstatic java.io.PrintStream java.lang.System.out\n");
        if (expr.isConst) {
            emitConst(expr, ctx);
        } else {
            ctx->fileContent.push_back("        swap");
        }

        switch (expr.type->base) {
            case BK_Int: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(int)"); break;
            case BK_Float: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(float)"); break;
            case BK_Bool: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(boolean)"); break;
            case BK_String: ctx->fileContent.push_back("        invokevirtual void java.io.PrintStream.println(java.lang.String)"); break;
            default: SemanticError("unsupported type for println", yylineno);
        }
    }
#line 1990 "src/y.tab.cpp"
    break;

  case 65: /* for_simple_item: READ lvalue  */
#line 630 "src/p3_parser.y"
                   {
        Symbol* sym = (yyvsp[0].symbol);
        ExprInfo *exprPtr = (sym != nullptr) ? sym->getExprInfo() : makeInvalidExpr();
        ExprInfo expr = *exprPtr; delete exprPtr;
        if (expr.isValid) checkRead(expr, yylineno);
    }
#line 2001 "src/y.tab.cpp"
    break;

  case 66: /* for_simple_item: lvalue INC  */
#line 636 "src/p3_parser.y"
                 {
        if ((yyvsp[-1].symbol) != nullptr) delete checkIncDecValid(true, false, (yyvsp[-1].symbol), ctx, yylineno);
     }
#line 2009 "src/y.tab.cpp"
    break;

  case 67: /* for_simple_item: lvalue DEC  */
#line 639 "src/p3_parser.y"
                 {
        if ((yyvsp[-1].symbol) != nullptr) delete checkIncDecValid(false, false, (yyvsp[-1].symbol), ctx, yylineno);
     }
#line 2017 "src/y.tab.cpp"
    break;

  case 68: /* for_simple_item: INC lvalue  */
#line 642 "src/p3_parser.y"
                 {
        if ((yyvsp[0].symbol) != nullptr) delete checkIncDecValid(true, false, (yyvsp[0].symbol), ctx, yylineno);
     }
#line 2025 "src/y.tab.cpp"
    break;

  case 69: /* for_simple_item: DEC lvalue  */
#line 645 "src/p3_parser.y"
                 {
        if ((yyvsp[0].symbol) != nullptr) delete checkIncDecValid(false, false, (yyvsp[0].symbol), ctx, yylineno);
    }
#line 2033 "src/y.tab.cpp"
    break;

  case 70: /* assign_no_semi: lvalue ASSIGN expression  */
#line 651 "src/p3_parser.y"
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
#line 2073 "src/y.tab.cpp"
    break;

  case 71: /* return_stmt: RETURN expression SEMICOLON  */
#line 690 "src/p3_parser.y"
                                  {
        ExprInfo expr = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
        ctx->returnsExpr.push_back(std::make_pair(expr, yylineno));

        if (expr.isConst) emitConst(expr, ctx);

        switch (ctx->funcType->base) {
            case BK_Int: ctx->fileContent.push_back("        ireturn"); break;
            case BK_Float: ctx->fileContent.push_back("        freturn"); break;
            case BK_Bool: ctx->fileContent.push_back("        ireturn"); break;
            default: SemanticError("unsupported return type", yylineno);
        }
    }
#line 2091 "src/y.tab.cpp"
    break;

  case 72: /* expression: expression PLUS expression  */
#line 707 "src/p3_parser.y"
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
#line 2110 "src/y.tab.cpp"
    break;

  case 73: /* expression: expression MINUS expression  */
#line 721 "src/p3_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = numericOpResult(OPSUB, lhs, rhs, ctx, yylineno);
        }
    }
#line 2124 "src/y.tab.cpp"
    break;

  case 74: /* expression: expression MUL expression  */
#line 730 "src/p3_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = numericOpResult(OPMUL, lhs, rhs, ctx, yylineno);
        }
    }
#line 2138 "src/y.tab.cpp"
    break;

  case 75: /* expression: expression DIV expression  */
#line 739 "src/p3_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = numericOpResult(OPDIV, lhs, rhs, ctx, yylineno);
        }
    }
#line 2152 "src/y.tab.cpp"
    break;

  case 76: /* expression: expression MOD expression  */
#line 748 "src/p3_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = numericOpResult(OPMOD, lhs, rhs, ctx, yylineno);
        }
    }
#line 2166 "src/y.tab.cpp"
    break;

  case 77: /* expression: expression LT expression  */
#line 757 "src/p3_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = relOpResult(OPLT, lhs , rhs, ctx, yylineno);
        }
    }
#line 2180 "src/y.tab.cpp"
    break;

  case 78: /* expression: expression LE expression  */
#line 766 "src/p3_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = relOpResult(OPLE, lhs , rhs, ctx, yylineno);
        }
    }
#line 2194 "src/y.tab.cpp"
    break;

  case 79: /* expression: expression GT expression  */
#line 775 "src/p3_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = relOpResult(OPGT, lhs , rhs, ctx, yylineno);
        }
    }
#line 2208 "src/y.tab.cpp"
    break;

  case 80: /* expression: expression GE expression  */
#line 784 "src/p3_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = relOpResult(OPGE, lhs , rhs, ctx, yylineno);
        }
    }
#line 2222 "src/y.tab.cpp"
    break;

  case 81: /* expression: expression EQ expression  */
#line 793 "src/p3_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = eqOpResult(true, lhs, rhs, ctx, yylineno);
        }
    }
#line 2236 "src/y.tab.cpp"
    break;

  case 82: /* expression: expression NEQ expression  */
#line 802 "src/p3_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = eqOpResult(false, lhs, rhs, ctx, yylineno);
        }
    }
#line 2250 "src/y.tab.cpp"
    break;

  case 83: /* expression: expression AND expression  */
#line 811 "src/p3_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = boolOpResult(true, lhs , rhs, ctx, yylineno);
        }   
    }
#line 2264 "src/y.tab.cpp"
    break;

  case 84: /* expression: expression OR expression  */
#line 820 "src/p3_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = boolOpResult(false, lhs , rhs, ctx, yylineno);
        }
    }
#line 2278 "src/y.tab.cpp"
    break;

  case 85: /* expression: NOT expression  */
#line 829 "src/p3_parser.y"
                                    {
        ExprInfo expr = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);
        if(!expr.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = notOpResult(expr, ctx, yylineno);
        }
    }
#line 2292 "src/y.tab.cpp"
    break;

  case 86: /* expression: MINUS expression  */
#line 838 "src/p3_parser.y"
                                    {
        ExprInfo expr = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);
        if(!expr.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = unaryOpResult(true, expr, ctx, yylineno);
        }
    }
#line 2306 "src/y.tab.cpp"
    break;

  case 87: /* expression: PLUS expression  */
#line 847 "src/p3_parser.y"
                                    {
        ExprInfo expr = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);
        if(!expr.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }
        else{
            (yyval.expr_info) = unaryOpResult(false, expr, ctx, yylineno);
        }
    }
#line 2320 "src/y.tab.cpp"
    break;

  case 88: /* expression: INC lvalue  */
#line 856 "src/p3_parser.y"
                                {
        (yyval.expr_info) = checkIncDecValid(true, true, (yyvsp[0].symbol), ctx, yylineno);
     }
#line 2328 "src/y.tab.cpp"
    break;

  case 89: /* expression: DEC lvalue  */
#line 859 "src/p3_parser.y"
                                {
        (yyval.expr_info) = checkIncDecValid(false, true, (yyvsp[0].symbol), ctx, yylineno);
     }
#line 2336 "src/y.tab.cpp"
    break;

  case 90: /* expression: lvalue INC  */
#line 862 "src/p3_parser.y"
                               {
        (yyval.expr_info) = checkIncDecValid(true, true, (yyvsp[-1].symbol), ctx, yylineno);
     }
#line 2344 "src/y.tab.cpp"
    break;

  case 91: /* expression: lvalue DEC  */
#line 865 "src/p3_parser.y"
                               {
        (yyval.expr_info) = checkIncDecValid(false, true, (yyvsp[-1].symbol), ctx, yylineno);
    }
#line 2352 "src/y.tab.cpp"
    break;

  case 92: /* expression: LPAREN expression RPAREN  */
#line 868 "src/p3_parser.y"
                                     { 
        if (!(yyvsp[-1].expr_info)->isValid) {
            delete (yyvsp[-1].expr_info);
            (yyval.expr_info) = makeInvalidExpr();
        }else{
            (yyval.expr_info) = (yyvsp[-1].expr_info);
        }
    }
#line 2365 "src/y.tab.cpp"
    break;

  case 93: /* expression: lvalue  */
#line 876 "src/p3_parser.y"
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
#line 2401 "src/y.tab.cpp"
    break;

  case 94: /* expression: const_lit  */
#line 907 "src/p3_parser.y"
                                     { 
        if (!(yyvsp[0].expr_info)->isValid) {
            delete (yyvsp[0].expr_info);
            (yyval.expr_info) = makeInvalidExpr();
        }else{
            (yyval.expr_info) = (yyvsp[0].expr_info);
        }
    }
#line 2414 "src/y.tab.cpp"
    break;

  case 95: /* expression: func_call  */
#line 915 "src/p3_parser.y"
                                     { 
        if (!(yyvsp[0].expr_info)->isValid) {
            delete (yyvsp[0].expr_info);
            (yyval.expr_info) = makeInvalidExpr();
        }else{
            (yyval.expr_info) = (yyvsp[0].expr_info);
        }
    }
#line 2427 "src/y.tab.cpp"
    break;

  case 96: /* const_lit: INT_LIT  */
#line 927 "src/p3_parser.y"
                  { 
        (yyval.expr_info) = new ExprInfo(ctx->typePool.make(BK_Int), true);
        (yyval.expr_info)->setInt((yyvsp[0].ival));
    }
#line 2436 "src/y.tab.cpp"
    break;

  case 97: /* const_lit: REAL_LIT  */
#line 931 "src/p3_parser.y"
                  {
        (yyval.expr_info) = new ExprInfo(ctx->typePool.make(BK_Float), true);
        (yyval.expr_info)->setFloat((yyvsp[0].fval));
    }
#line 2445 "src/y.tab.cpp"
    break;

  case 98: /* const_lit: BOOL_LIT  */
#line 935 "src/p3_parser.y"
                  {
        (yyval.expr_info) = new ExprInfo(ctx->typePool.make(BK_Bool), true);
        (yyval.expr_info)->setBool((yyvsp[0].bval));
    }
#line 2454 "src/y.tab.cpp"
    break;

  case 99: /* const_lit: STRING_LIT  */
#line 939 "src/p3_parser.y"
                  { 
        (yyval.expr_info) = new ExprInfo(ctx->typePool.make(BK_String), true);
        (yyval.expr_info)->setString(*(yyvsp[0].sval));
        delete (yyvsp[0].sval);
    }
#line 2464 "src/y.tab.cpp"
    break;

  case 100: /* func_call: ID LPAREN arg_list_opt RPAREN  */
#line 948 "src/p3_parser.y"
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
#line 2505 "src/y.tab.cpp"
    break;

  case 101: /* proc_call: ID LPAREN arg_list_opt RPAREN  */
#line 986 "src/p3_parser.y"
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
#line 2537 "src/y.tab.cpp"
    break;

  case 102: /* arg_list_opt: %empty  */
#line 1016 "src/p3_parser.y"
                 { (yyval.expr_info_list) = new std::vector<ExprInfo>();}
#line 2543 "src/y.tab.cpp"
    break;

  case 103: /* arg_list_opt: arg_list  */
#line 1017 "src/p3_parser.y"
               { (yyval.expr_info_list) = (yyvsp[0].expr_info_list); }
#line 2549 "src/y.tab.cpp"
    break;

  case 104: /* arg_list: expression  */
#line 1021 "src/p3_parser.y"
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
#line 2569 "src/y.tab.cpp"
    break;

  case 105: /* arg_list: arg_list COMMA expression  */
#line 1036 "src/p3_parser.y"
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
#line 2589 "src/y.tab.cpp"
    break;

  case 106: /* type_spec: INT_TOK  */
#line 1055 "src/p3_parser.y"
                 { (yyval.type) = ctx->typePool.make(BK_Int); ctx->nowType = (yyval.type); }
#line 2595 "src/y.tab.cpp"
    break;

  case 107: /* type_spec: FLOAT_TOK  */
#line 1056 "src/p3_parser.y"
                     { (yyval.type) = ctx->typePool.make(BK_Float); ctx->nowType = (yyval.type); }
#line 2601 "src/y.tab.cpp"
    break;

  case 108: /* type_spec: BOOL_TOK  */
#line 1057 "src/p3_parser.y"
                     { (yyval.type) = ctx->typePool.make(BK_Bool);  ctx->nowType = (yyval.type); }
#line 2607 "src/y.tab.cpp"
    break;

  case 109: /* type_spec: STRING_TOK  */
#line 1058 "src/p3_parser.y"
                 { (yyval.type) = ctx->typePool.make(BK_String); ctx->nowType = (yyval.type);}
#line 2613 "src/y.tab.cpp"
    break;


#line 2617 "src/y.tab.cpp"

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

#line 1061 "src/p3_parser.y"
 

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
