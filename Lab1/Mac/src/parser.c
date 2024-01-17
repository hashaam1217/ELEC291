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
#line 22 "parser.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a51.h"

#define YYSTYPE union ystack

static unsigned char kmask[]={
	0x01, 0x02, 0x04, 0x08,	0x10, 0x20, 0x40, 0x80,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01};

static unsigned char bytebuf[0x4000]; /* used by dumplist() */
struct symbol * label_symbol = NULL;

char symexp[0x100];
char tmpexp[0x100];

char optc51[0x1000]=" ";
extern char MapFile[PATH_MAX];

int printf_float=0;

static int bytecount;
int RegisterBank=0;

int IF_Flag[0x100];
int IF_Level;
char IF_Value[0x1000];
int IF_Count;
int force_EOF;
int hash_warning_enable=1; // Just after adding this feature I found two bugs in old code!
extern int linetest;

void yyerror(char *s);
int makeop(struct opcode * op, struct mode *m, int add);
char *padline(char *line);
void dumplist(char *txt, int show);
void genbyte(int b);
void genstr(char *s);
void genword(unsigned long w);
void BadRegUse(char * x);
void objbyte(int b);
void objstr(char *s);
void objword(unsigned long w);
void set_str1(struct mode *m, union ystack *y);
void set_str2(struct mode *m, union ystack *y);
void NoObjectFileError (char * x);

/* ------------------------ G R A M M E R ----------------------------- */


#line 125 "parser.c"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STRING = 3,                     /* STRING  */
  YYSYMBOL_D_ORG = 4,                      /* D_ORG  */
  YYSYMBOL_D_BYTE = 5,                     /* D_BYTE  */
  YYSYMBOL_D_WORD = 6,                     /* D_WORD  */
  YYSYMBOL_D_SKIP = 7,                     /* D_SKIP  */
  YYSYMBOL_D_EQU = 8,                      /* D_EQU  */
  YYSYMBOL_D_SET = 9,                      /* D_SET  */
  YYSYMBOL_D_MAC = 10,                     /* D_MAC  */
  YYSYMBOL_D_DBIT = 11,                    /* D_DBIT  */
  YYSYMBOL_D_END = 12,                     /* D_END  */
  YYSYMBOL_D_DSEG = 13,                    /* D_DSEG  */
  YYSYMBOL_D_ISEG = 14,                    /* D_ISEG  */
  YYSYMBOL_D_BSEG = 15,                    /* D_BSEG  */
  YYSYMBOL_D_CSEG = 16,                    /* D_CSEG  */
  YYSYMBOL_D_XSEG = 17,                    /* D_XSEG  */
  YYSYMBOL_ACALL = 18,                     /* ACALL  */
  YYSYMBOL_ADD = 19,                       /* ADD  */
  YYSYMBOL_ADDC = 20,                      /* ADDC  */
  YYSYMBOL_AJMP = 21,                      /* AJMP  */
  YYSYMBOL_ANL = 22,                       /* ANL  */
  YYSYMBOL_CALL = 23,                      /* CALL  */
  YYSYMBOL_CJNE = 24,                      /* CJNE  */
  YYSYMBOL_CLR = 25,                       /* CLR  */
  YYSYMBOL_CPL = 26,                       /* CPL  */
  YYSYMBOL_DA = 27,                        /* DA  */
  YYSYMBOL_DEC = 28,                       /* DEC  */
  YYSYMBOL_DIV = 29,                       /* DIV  */
  YYSYMBOL_DJNZ = 30,                      /* DJNZ  */
  YYSYMBOL_INC = 31,                       /* INC  */
  YYSYMBOL_D_INCLUDE = 32,                 /* D_INCLUDE  */
  YYSYMBOL_JB = 33,                        /* JB  */
  YYSYMBOL_JBC = 34,                       /* JBC  */
  YYSYMBOL_JC = 35,                        /* JC  */
  YYSYMBOL_JMP = 36,                       /* JMP  */
  YYSYMBOL_JNB = 37,                       /* JNB  */
  YYSYMBOL_JNC = 38,                       /* JNC  */
  YYSYMBOL_JNZ = 39,                       /* JNZ  */
  YYSYMBOL_JZ = 40,                        /* JZ  */
  YYSYMBOL_LCALL = 41,                     /* LCALL  */
  YYSYMBOL_LJMP = 42,                      /* LJMP  */
  YYSYMBOL_MOV = 43,                       /* MOV  */
  YYSYMBOL_MOVC = 44,                      /* MOVC  */
  YYSYMBOL_MOVX = 45,                      /* MOVX  */
  YYSYMBOL_NOP = 46,                       /* NOP  */
  YYSYMBOL_MUL = 47,                       /* MUL  */
  YYSYMBOL_ORL = 48,                       /* ORL  */
  YYSYMBOL_POP = 49,                       /* POP  */
  YYSYMBOL_PUSH = 50,                      /* PUSH  */
  YYSYMBOL_RET = 51,                       /* RET  */
  YYSYMBOL_RETI = 52,                      /* RETI  */
  YYSYMBOL_RL = 53,                        /* RL  */
  YYSYMBOL_RLC = 54,                       /* RLC  */
  YYSYMBOL_RR = 55,                        /* RR  */
  YYSYMBOL_RRC = 56,                       /* RRC  */
  YYSYMBOL_SETB = 57,                      /* SETB  */
  YYSYMBOL_SJMP = 58,                      /* SJMP  */
  YYSYMBOL_SUBB = 59,                      /* SUBB  */
  YYSYMBOL_SWAP = 60,                      /* SWAP  */
  YYSYMBOL_XCH = 61,                       /* XCH  */
  YYSYMBOL_XCHD = 62,                      /* XCHD  */
  YYSYMBOL_XRL = 63,                       /* XRL  */
  YYSYMBOL_AB = 64,                        /* AB  */
  YYSYMBOL_A = 65,                         /* A  */
  YYSYMBOL_C = 66,                         /* C  */
  YYSYMBOL_PC = 67,                        /* PC  */
  YYSYMBOL_DPTR = 68,                      /* DPTR  */
  YYSYMBOL_BITPOS = 69,                    /* BITPOS  */
  YYSYMBOL_R0 = 70,                        /* R0  */
  YYSYMBOL_R1 = 71,                        /* R1  */
  YYSYMBOL_R2 = 72,                        /* R2  */
  YYSYMBOL_R3 = 73,                        /* R3  */
  YYSYMBOL_R4 = 74,                        /* R4  */
  YYSYMBOL_R5 = 75,                        /* R5  */
  YYSYMBOL_R6 = 76,                        /* R6  */
  YYSYMBOL_R7 = 77,                        /* R7  */
  YYSYMBOL_USING = 78,                     /* USING  */
  YYSYMBOL_AR0 = 79,                       /* AR0  */
  YYSYMBOL_AR1 = 80,                       /* AR1  */
  YYSYMBOL_AR2 = 81,                       /* AR2  */
  YYSYMBOL_AR3 = 82,                       /* AR3  */
  YYSYMBOL_AR4 = 83,                       /* AR4  */
  YYSYMBOL_AR5 = 84,                       /* AR5  */
  YYSYMBOL_AR6 = 85,                       /* AR6  */
  YYSYMBOL_AR7 = 86,                       /* AR7  */
  YYSYMBOL_VALUE = 87,                     /* VALUE  */
  YYSYMBOL_SYMBOL = 88,                    /* SYMBOL  */
  YYSYMBOL_CONTROL = 89,                   /* CONTROL  */
  YYSYMBOL_HIGH = 90,                      /* HIGH  */
  YYSYMBOL_LOW = 91,                       /* LOW  */
  YYSYMBOL_NOT = 92,                       /* NOT  */
  YYSYMBOL_D_AT = 93,                      /* D_AT  */
  YYSYMBOL_D_DS = 94,                      /* D_DS  */
  YYSYMBOL_D_BIT = 95,                     /* D_BIT  */
  YYSYMBOL_D_DATA = 96,                    /* D_DATA  */
  YYSYMBOL_D_XDATA = 97,                   /* D_XDATA  */
  YYSYMBOL_D_IDATA = 98,                   /* D_IDATA  */
  YYSYMBOL_D_CODE = 99,                    /* D_CODE  */
  YYSYMBOL_MOD = 100,                      /* MOD  */
  YYSYMBOL_D_SEG = 101,                    /* D_SEG  */
  YYSYMBOL_D_RSEG = 102,                   /* D_RSEG  */
  YYSYMBOL_PUBLIC = 103,                   /* PUBLIC  */
  YYSYMBOL_EXTERN = 104,                   /* EXTERN  */
  YYSYMBOL_OVERL = 105,                    /* OVERL  */
  YYSYMBOL_IF = 106,                       /* IF  */
  YYSYMBOL_IFDEF = 107,                    /* IFDEF  */
  YYSYMBOL_IFNDEF = 108,                   /* IFNDEF  */
  YYSYMBOL_ENDIF = 109,                    /* ENDIF  */
  YYSYMBOL_ELSE = 110,                     /* ELSE  */
  YYSYMBOL_ERROR = 111,                    /* ERROR  */
  YYSYMBOL_112_ = 112,                     /* '+'  */
  YYSYMBOL_113_ = 113,                     /* '-'  */
  YYSYMBOL_114_ = 114,                     /* '*'  */
  YYSYMBOL_115_ = 115,                     /* '/'  */
  YYSYMBOL_116_ = 116,                     /* '%'  */
  YYSYMBOL_117_ = 117,                     /* '|'  */
  YYSYMBOL_118_ = 118,                     /* '&'  */
  YYSYMBOL_119_ = 119,                     /* '^'  */
  YYSYMBOL_OR = 120,                       /* OR  */
  YYSYMBOL_AND = 121,                      /* AND  */
  YYSYMBOL_XOR = 122,                      /* XOR  */
  YYSYMBOL_123_ = 123,                     /* '>'  */
  YYSYMBOL_124_ = 124,                     /* '<'  */
  YYSYMBOL_125_ = 125,                     /* '='  */
  YYSYMBOL_126_ = 126,                     /* '!'  */
  YYSYMBOL_SHR = 127,                      /* SHR  */
  YYSYMBOL_SHL = 128,                      /* SHL  */
  YYSYMBOL_129_ = 129,                     /* '~'  */
  YYSYMBOL_C_GT = 130,                     /* C_GT  */
  YYSYMBOL_C_LT = 131,                     /* C_LT  */
  YYSYMBOL_C_GE = 132,                     /* C_GE  */
  YYSYMBOL_C_LE = 133,                     /* C_LE  */
  YYSYMBOL_C_EQ = 134,                     /* C_EQ  */
  YYSYMBOL_C_NE = 135,                     /* C_NE  */
  YYSYMBOL_136_ = 136,                     /* ':'  */
  YYSYMBOL_137_n_ = 137,                   /* '\n'  */
  YYSYMBOL_138_ = 138,                     /* '('  */
  YYSYMBOL_139_ = 139,                     /* ')'  */
  YYSYMBOL_140_ = 140,                     /* ','  */
  YYSYMBOL_141_ = 141,                     /* '$'  */
  YYSYMBOL_142_ = 142,                     /* '@'  */
  YYSYMBOL_143_ = 143,                     /* '#'  */
  YYSYMBOL_YYACCEPT = 144,                 /* $accept  */
  YYSYMBOL_program = 145,                  /* program  */
  YYSYMBOL_linelist = 146,                 /* linelist  */
  YYSYMBOL_line = 147,                     /* line  */
  YYSYMBOL_linerest = 148,                 /* linerest  */
  YYSYMBOL_control = 149,                  /* control  */
  YYSYMBOL_directive = 150,                /* directive  */
  YYSYMBOL_conditional = 151,              /* conditional  */
  YYSYMBOL_defexpr = 152,                  /* defexpr  */
  YYSYMBOL_undefsym = 153,                 /* undefsym  */
  YYSYMBOL_publist = 154,                  /* publist  */
  YYSYMBOL_extlist_code = 155,             /* extlist_code  */
  YYSYMBOL_extlist_bit = 156,              /* extlist_bit  */
  YYSYMBOL_extlist_data = 157,             /* extlist_data  */
  YYSYMBOL_extlist_idata = 158,            /* extlist_idata  */
  YYSYMBOL_extlist_xdata = 159,            /* extlist_xdata  */
  YYSYMBOL_blist = 160,                    /* blist  */
  YYSYMBOL_wlist = 161,                    /* wlist  */
  YYSYMBOL_expr = 162,                     /* expr  */
  YYSYMBOL_instr = 163,                    /* instr  */
  YYSYMBOL_two_op1 = 164,                  /* two_op1  */
  YYSYMBOL_two_op2 = 165,                  /* two_op2  */
  YYSYMBOL_two_op3 = 166,                  /* two_op3  */
  YYSYMBOL_two_op4 = 167,                  /* two_op4  */
  YYSYMBOL_two_op5 = 168,                  /* two_op5  */
  YYSYMBOL_two_op6 = 169,                  /* two_op6  */
  YYSYMBOL_single_op1 = 170,               /* single_op1  */
  YYSYMBOL_single_op2 = 171,               /* single_op2  */
  YYSYMBOL_three_op1 = 172,                /* three_op1  */
  YYSYMBOL_rel = 173,                      /* rel  */
  YYSYMBOL_rel2 = 174,                     /* rel2  */
  YYSYMBOL_bit = 175,                      /* bit  */
  YYSYMBOL_reg = 176,                      /* reg  */
  YYSYMBOL_areg = 177,                     /* areg  */
  YYSYMBOL_regi = 178,                     /* regi  */
  YYSYMBOL_data8 = 179,                    /* data8  */
  YYSYMBOL_data16 = 180,                   /* data16  */
  YYSYMBOL_addr11 = 181,                   /* addr11  */
  YYSYMBOL_addr16 = 182,                   /* addr16  */
  YYSYMBOL_relative = 183                  /* relative  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  233
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1954

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  144
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  280
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  507

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   377


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     137,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   126,     2,   143,   141,   116,   118,     2,
     138,   139,   114,   112,   140,   113,     2,   115,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   136,     2,
     124,   125,   123,     2,   142,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   119,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   117,     2,   129,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   120,   121,   122,
     127,   128,   130,   131,   132,   133,   134,   135
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   202,   202,   207,   208,   212,   244,   286,   311,   338,
     357,   365,   371,   377,   382,   389,   402,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   435,
     598,   627,   633,   641,   655,   677,   683,   691,   697,   705,
     711,   719,   729,   740,   746,   760,   774,   782,   790,   798,
     806,   814,   822,   831,   840,   849,   860,   871,   882,   893,
     904,   915,   926,   937,   948,   959,   979,   984,   989,   994,
     999,  1004,  1019,  1044,  1069,  1093,  1105,  1117,  1125,  1136,
    1151,  1158,  1168,  1175,  1182,  1189,  1199,  1206,  1213,  1220,
    1231,  1238,  1245,  1252,  1262,  1269,  1276,  1283,  1293,  1300,
    1307,  1314,  1324,  1343,  1353,  1372,  1385,  1404,  1428,  1443,
    1450,  1458,  1466,  1474,  1482,  1490,  1498,  1506,  1514,  1522,
    1530,  1538,  1546,  1566,  1586,  1594,  1602,  1610,  1618,  1626,
    1634,  1642,  1650,  1658,  1666,  1674,  1682,  1690,  1698,  1706,
    1714,  1722,  1730,  1738,  1746,  1820,  1834,  1836,  1838,  1840,
    1842,  1844,  1846,  1848,  1850,  1852,  1854,  1856,  1858,  1860,
    1862,  1866,  1868,  1870,  1872,  1874,  1876,  1878,  1880,  1925,
    1959,  1961,  1963,  1965,  1967,  1969,  1971,  1973,  1975,  1981,
    1983,  1985,  1990,  2000,  2010,  2012,  2014,  2016,  2018,  2020,
    2022,  2024,  2026,  2028,  2030,  2032,  2034,  2036,  2038,  2040,
    2042,  2044,  2046,  2048,  2050,  2052,  2054,  2062,  2068,  2080,
    2086,  2097,  2105,  2118,  2126,  2134,  2145,  2158,  2166,  2179,
    2185,  2197,  2205,  2213,  2227,  2235,  2241,  2253,  2261,  2280,
    2303,  2311,  2340,  2346,  2352,  2360,  2369,  2375,  2381,  2399,
    2413,  2423,  2433,  2446,  2469,  2490,  2515,  2558,  2559,  2560,
    2561,  2562,  2563,  2564,  2565,  2569,  2570,  2571,  2572,  2573,
    2574,  2575,  2576,  2580,  2592,  2611,  2616,  2634,  2649,  2676,
    2704
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
  "\"end of file\"", "error", "\"invalid token\"", "STRING", "D_ORG",
  "D_BYTE", "D_WORD", "D_SKIP", "D_EQU", "D_SET", "D_MAC", "D_DBIT",
  "D_END", "D_DSEG", "D_ISEG", "D_BSEG", "D_CSEG", "D_XSEG", "ACALL",
  "ADD", "ADDC", "AJMP", "ANL", "CALL", "CJNE", "CLR", "CPL", "DA", "DEC",
  "DIV", "DJNZ", "INC", "D_INCLUDE", "JB", "JBC", "JC", "JMP", "JNB",
  "JNC", "JNZ", "JZ", "LCALL", "LJMP", "MOV", "MOVC", "MOVX", "NOP", "MUL",
  "ORL", "POP", "PUSH", "RET", "RETI", "RL", "RLC", "RR", "RRC", "SETB",
  "SJMP", "SUBB", "SWAP", "XCH", "XCHD", "XRL", "AB", "A", "C", "PC",
  "DPTR", "BITPOS", "R0", "R1", "R2", "R3", "R4", "R5", "R6", "R7",
  "USING", "AR0", "AR1", "AR2", "AR3", "AR4", "AR5", "AR6", "AR7", "VALUE",
  "SYMBOL", "CONTROL", "HIGH", "LOW", "NOT", "D_AT", "D_DS", "D_BIT",
  "D_DATA", "D_XDATA", "D_IDATA", "D_CODE", "MOD", "D_SEG", "D_RSEG",
  "PUBLIC", "EXTERN", "OVERL", "IF", "IFDEF", "IFNDEF", "ENDIF", "ELSE",
  "ERROR", "'+'", "'-'", "'*'", "'/'", "'%'", "'|'", "'&'", "'^'", "OR",
  "AND", "XOR", "'>'", "'<'", "'='", "'!'", "SHR", "SHL", "'~'", "C_GT",
  "C_LT", "C_GE", "C_LE", "C_EQ", "C_NE", "':'", "'\\n'", "'('", "')'",
  "','", "'$'", "'@'", "'#'", "$accept", "program", "linelist", "line",
  "linerest", "control", "directive", "conditional", "defexpr", "undefsym",
  "publist", "extlist_code", "extlist_bit", "extlist_data",
  "extlist_idata", "extlist_xdata", "blist", "wlist", "expr", "instr",
  "two_op1", "two_op2", "two_op3", "two_op4", "two_op5", "two_op6",
  "single_op1", "single_op2", "three_op1", "rel", "rel2", "bit", "reg",
  "areg", "regi", "data8", "data16", "addr11", "addr16", "relative", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-291)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-112)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     689,  -291,  1608,   310,    60,  1608,  1608,  -291,   -84,   -78,
     -76,   -71,   -52,  1608,   -30,   -30,  1608,  1332,  1608,   146,
     318,   318,   -22,  1243,   -16,  1452,  1169,  1608,  1608,  1608,
      50,  1608,  1608,  1608,  1608,  1608,  1608,  1134,    14,   -57,
    -291,     7,  1332,  1530,  1530,  -291,  -291,    17,    35,    44,
      69,   318,  1608,   -30,    74,   -30,   -30,  1356,  -291,  -291,
    -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,  1530,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
     -61,  -291,  1608,    26,    56,   316,    60,  -291,  -291,  -291,
    -291,  -291,   149,   562,  -291,  -291,    16,    18,  -291,    79,
      21,  -291,  -291,  1608,  1608,  1608,  1608,  1608,  1608,  -291,
    -291,  1778,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,    20,  1778,  -291,  -291,  -291,    22,  1778,  -291,  -291,
     942,  1608,  1608,  1608,  1608,  1608,  1778,  -291,    29,  -291,
    -291,  -291,    30,  -291,  -291,  -291,    31,  1778,  -291,    42,
    -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,   301,  -291,
      43,  -291,  -291,   407,  -291,  -291,  -291,  -291,  -291,   301,
    -291,  -291,  -291,  -291,  -291,    45,    46,  -291,  -291,  -291,
      47,  -291,  1778,  -291,   -55,  -291,  -291,  -291,  -291,  -291,
    -291,  -291,    54,    55,   301,  -291,  -291,  -291,    57,   -46,
      59,    62,    51,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,  -291,  -291,   942,  -291,  -291,    68,     8,    23,    34,
      52,    58,  -291,  -291,  -291,  -291,  -291,  -291,  1267,  -291,
    1608,  1530,    60,  1530,    60,   323,   816,  -291,   113,   113,
     113,  1819,   113,  1638,  1608,  1608,  1608,  1608,  1608,  1608,
    1608,  1608,  1608,  1608,  1608,  1544,  1339,  1602,    85,  1608,
    1608,  1608,  1608,  1608,  1608,  1608,  1608,   423,    60,  -291,
     108,  -291,  -291,  -291,  -291,  -291,  1428,  1550,   -60,  1515,
    -291,    72,    11,  -291,  -291,  1608,  1608,  1608,   101,   102,
    1608,    13,    88,  1025,    95,   990,    97,   109,   110,   147,
    -291,   153,   198,   198,   198,   198,   198,  -291,  1778,  -291,
    -291,  -291,  -291,  -291,  -291,  -291,   132,   184,   186,   192,
    -291,  1608,  1608,  -291,  -291,  1800,  1800,  1819,  1819,  1819,
     553,   553,   553,   677,   677,   677,  1608,  1608,    99,  1608,
    1608,  1608,    99,  1608,   228,  1608,   113,   113,  -291,  -291,
    -291,  -291,  -291,  -291,  -291,  -291,  -291,   301,  1530,  -291,
    -291,  1608,  1608,  -291,  -291,  1530,  1530,   159,   157,  1530,
    1778,  -291,  1778,  -291,  -291,   233,   237,  -291,    60,  1060,
    -291,  1530,  -291,   238,  -291,   301,  -291,  -291,   -10,   207,
     240,   241,  -291,  -291,   171,   -80,   176,   -49,  -115,   175,
     177,   -70,   183,   178,   188,   -43,  -291,  -291,  -291,  -291,
     942,   942,    99,   228,    99,    99,   228,   228,   228,  -291,
    -291,  -291,  -291,  -291,   185,  1608,  1530,   187,  -291,  -291,
    -291,  -291,  1530,  -291,  -291,  -291,  -291,   216,   219,   220,
    -291,  -291,  -291,  -291,  1608,  -291,   198,  1608,  -291,   198,
    1608,   198,  -291,  1608,   198,  -291,  1608,  -291,   198,  -291,
    -291,  1608,  -291,   194,  1608,  -291,    40,   272,   274,  1778,
     205,  1778,   206,  1666,   -66,  1694,   -58,  1778,   210,  -291,
    1608,  -291,  -291,  -291,  -291,  -291,  1608,  1608,  1608,  1608,
    1608,  -291,  1778,  1778,  1722,  1750,  1778
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,    38,     0,     0,     0,     0,     0,    87,    41,    45,
      47,    43,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     156,     0,     0,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     0,    30,    31,    32,    33,    34,    35,    36,    37,
      89,    39,     0,     0,     0,     0,     0,    83,    84,    86,
      85,    16,     0,     0,     4,    10,     0,     0,    13,     0,
       0,   155,   154,     0,     0,     0,     0,     0,     0,   118,
      40,    88,   115,   265,   266,   267,   268,   269,   270,   271,
     272,    51,   274,   275,   114,   277,    52,   276,   117,    53,
       0,     0,     0,     0,     0,     0,   278,   157,     0,   159,
     160,   158,     0,   164,   165,   166,     0,   279,   179,     0,
     257,   258,   259,   260,   261,   262,   263,   264,     0,   201,
       0,   246,   247,   256,   189,   248,   190,   174,   242,     0,
     173,   243,   244,   175,   205,     0,     0,   172,   171,   202,
       0,   204,   280,   196,     0,   178,   203,   197,   198,   199,
     195,   194,     0,     0,     0,   206,   207,   208,     0,     0,
       0,     0,     0,   180,   167,   168,   169,   193,   192,   183,
     184,   185,   186,   191,   200,   161,   187,   170,   188,   162,
     163,    56,    14,     0,    75,    90,    76,     0,     0,     0,
       0,     0,    82,     1,     3,    11,    12,    54,     0,    55,
       0,     0,     0,     0,     0,     0,     0,    15,   121,   122,
     123,   120,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       0,    42,    46,    48,    44,    50,     0,     0,     0,     0,
     273,     0,     0,   255,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     0,     0,     0,     0,     0,     0,    64,    65,    62,
      63,    61,    57,    59,    58,    60,    73,    69,    67,    71,
      66,     0,     0,     9,   119,   135,   134,   131,   132,   133,
     125,   127,   129,   126,   128,   130,     0,     0,   150,     0,
       0,     0,   146,     0,   140,     0,   137,   139,   151,   147,
     153,   149,   141,   145,   113,   112,   116,     0,     0,   217,
     218,     0,     0,   223,   221,     0,     0,     0,     0,     0,
     254,   227,   253,   228,   226,     0,     0,   239,     0,     0,
     229,     0,   230,     0,   240,     0,   232,   233,     0,     0,
       0,     0,    91,    89,    96,     0,   100,     0,    92,     0,
       0,    92,     0,     0,    92,     0,    74,    70,    68,    72,
       0,     0,   136,   152,   144,   138,   148,   142,   143,   219,
     220,   224,   225,   222,     0,     0,     0,     0,   176,   177,
     238,   235,     0,   236,   231,   241,   234,     0,     0,     0,
     214,   213,   216,   215,     0,    81,     0,     0,    78,     0,
       0,     0,    79,     0,     0,    80,     0,    77,     0,     7,
       5,     0,   249,     0,     0,   237,     0,     0,     0,    97,
      98,   101,   102,    93,    94,    93,    94,    93,    94,   250,
       0,   251,   211,   209,   212,   210,     0,     0,     0,     0,
       0,   252,    99,   103,    95,    95,    95
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -291,  -291,  -291,   250,  -110,  -291,  -291,  -291,    33,     6,
    -291,  -204,  -291,  -291,  -291,  -291,  -291,  -291,    -2,  -291,
     426,    19,   308,    67,  -291,  -291,   331,    -9,  -291,  -290,
    -291,     9,    28,   128,   -59,    49,   -85,   351,    32,    12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    92,    93,    94,    95,    96,    97,    98,   110,   280,
     226,   409,   405,   407,   413,   410,   121,   126,   122,   100,
     139,   144,   145,   179,   174,   197,   170,   164,   159,   383,
     381,   165,   290,   123,   291,   146,   128,   137,   148,   183
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     111,   232,   127,   111,   111,   374,    99,   384,   201,   131,
     298,   136,   166,   299,   136,   132,   147,   133,   163,   163,
     279,   460,   134,   304,  -108,   163,   163,   182,   147,   163,
     182,   182,   182,   147,   147,   138,   180,   180,   129,   130,
     180,   135,   213,   167,   187,   188,   189,   160,   173,   163,
     182,   171,   124,   175,   171,   447,   196,   448,   449,   455,
     456,   205,   185,   125,   214,   198,   463,   190,   191,  -104,
     498,   203,   172,  -110,   176,   172,   220,   222,   499,   200,
     111,  -106,   209,   375,   127,   202,   199,   237,   238,   239,
     458,   459,   207,   208,   305,   181,   467,   468,   186,    99,
     210,   248,   249,   250,   251,   252,   253,   492,   493,   211,
     294,   412,   415,   310,   224,   223,   237,   238,   239,   308,
     221,   150,   151,   152,   153,   154,   155,   156,   157,   111,
     111,   111,   111,   111,   212,   302,   333,   101,   102,   216,
     103,   104,   105,   309,   225,   472,   312,   101,   102,   233,
     103,   104,   105,   235,   379,   236,   388,   323,   247,   325,
     277,   313,   278,   106,   281,   282,   283,   284,   285,   286,
     287,   288,   314,   106,   240,   241,   242,   243,   244,   107,
     245,   489,   289,   292,   491,   295,   296,   297,   108,   107,
     315,   109,   184,   366,   300,   301,   316,   303,   108,   306,
     501,   109,   307,   240,   241,   242,   243,   244,   311,   245,
     355,   149,   378,   385,   386,   246,   150,   151,   152,   153,
     154,   155,   156,   157,   267,   268,   269,   270,   389,   271,
     272,   273,   274,   275,   276,   393,   318,   416,   163,   398,
     127,   402,   127,   271,   272,   273,   274,   275,   276,   321,
     400,   399,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   348,   352,   354,   319,   356,   357,   358,
     359,   360,   361,   362,   363,   450,   127,   150,   151,   152,
     153,   154,   155,   156,   157,   163,   403,   401,   158,   417,
     322,   418,   324,   380,   382,   382,   373,   419,   163,   435,
     436,   438,   439,   440,   445,   452,   453,   454,   429,   387,
     469,   470,   457,   112,   369,   461,   462,   465,   404,   406,
     408,   411,   414,   464,   466,   471,   365,   474,   476,   111,
     111,   477,   478,   396,   490,   370,   446,   494,   377,   495,
     451,   496,   497,   234,   422,   423,   500,   424,   425,   426,
     206,   427,   392,   428,   397,   269,   270,   178,   271,   272,
     273,   274,   275,   276,   420,   421,   320,   141,     0,   163,
     163,   150,   151,   152,   153,   154,   155,   156,   157,     0,
     431,   432,     0,   161,   162,     0,   127,     0,     0,   113,
     114,   115,   116,   117,   118,   119,   120,   101,   102,     0,
     103,   104,   105,     0,     0,   101,   102,     0,   103,   104,
     105,   227,   228,   229,   230,   231,     0,   430,   326,   327,
     328,   329,   330,   106,   433,   434,   364,     0,   437,     0,
       0,   106,     0,   382,     0,     0,     0,     0,   443,   107,
     444,   140,     0,   143,     0,     0,     0,   107,   108,     0,
       0,   109,   479,     0,     0,   481,   108,     0,   483,   109,
       0,   485,   480,   195,   487,   482,     0,   484,   204,   382,
     486,     0,   382,     0,   488,     0,   293,     0,     0,   215,
       0,   217,   218,   219,     0,   473,     0,     0,   382,     0,
       0,   475,     0,     0,   502,   503,   504,   505,   506,     0,
       0,     0,   113,   114,   115,   116,   117,   118,   119,   120,
     101,   102,     0,   103,   104,   105,     0,     0,     0,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   106,   271,   272,   273,
     274,   275,   276,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,   108,    -2,     1,   109,     0,     2,     3,     4,     5,
       0,     0,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     0,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
      80,    81,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,     0,    86,    87,
      88,    89,    90,   262,   263,   264,   265,   266,   267,   268,
     269,   270,     0,   271,   272,   273,   274,   275,   276,     0,
       1,     0,     0,     2,     3,     4,     5,     0,     0,    91,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,     0,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,    80,    81,     0,
       0,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,    83,    84,    85,     0,    86,    87,    88,    89,    90,
     265,   266,   267,   268,   269,   270,     0,   271,   272,   273,
     274,   275,   276,     0,     0,     0,     0,     1,     0,     0,
       2,     3,     4,     5,     0,     0,    91,   331,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     0,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     0,    80,    81,     0,     0,     0,     0,
     332,     0,     0,     0,     0,     0,     0,     0,    83,    84,
      85,     0,    86,    87,    88,    89,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,     2,     3,     4,     5,
       0,     0,     0,    91,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     0,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,     0,    86,    87,
      88,    89,    90,     0,     0,   374,   394,     0,     0,     0,
     150,   151,   152,   153,   154,   155,   156,   157,     0,   113,
     114,   115,   116,   117,   118,   119,   120,   101,   102,    91,
     103,   104,   105,     0,     0,     0,     0,     0,     0,     0,
     390,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   113,   114,   115,   116,   117,   118,
     119,   120,   101,   102,     0,   103,   104,   105,     0,   107,
       0,     0,     0,     0,     0,   441,     0,     0,   108,     0,
       0,   109,   395,   375,     0,     0,     0,     0,   106,   113,
     114,   115,   116,   117,   118,   119,   120,   101,   102,     0,
     103,   104,   105,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,   108,     0,     0,   109,     0,   391,     0,
       0,     0,     0,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,   108,   138,
     192,   109,   193,   442,   150,   151,   152,   153,   154,   155,
     156,   157,     0,   113,   114,   115,   116,   117,   118,   119,
     120,   101,   102,     0,   103,   104,   105,     0,     0,     0,
       0,     0,     0,     0,   168,     0,     0,   177,     0,   150,
     151,   152,   153,   154,   155,   156,   157,   106,   113,   114,
     115,   116,   117,   118,   119,   120,   101,   102,     0,   103,
     104,   105,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,   108,     0,     0,   109,   194,     0,     0,     0,
       0,     0,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,   108,   168,     0,
     109,   169,     0,   150,   151,   152,   153,   154,   155,   156,
     157,     0,   113,   114,   115,   116,   117,   118,   119,   120,
     101,   102,   317,   103,   104,   105,     0,   150,   151,   152,
     153,   154,   155,   156,   157,     0,   113,   114,   115,   116,
     117,   118,   119,   120,   101,   102,   106,   103,   104,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
     106,   108,     0,     0,   109,   169,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,   138,   142,     0,
       0,     0,     0,     0,     0,   108,     0,     0,   109,     0,
       0,   113,   114,   115,   116,   117,   118,   119,   120,   101,
     102,   138,   103,   104,   105,     0,   101,   102,     0,   103,
     104,   105,     0,     0,     0,   113,   114,   115,   116,   117,
     118,   119,   120,   101,   102,   106,   103,   104,   105,     0,
       0,     0,   106,     0,     0,     0,     0,     0,     0,     0,
       0,   107,   349,   350,   351,     0,     0,     0,   107,   106,
     108,     0,     0,   109,     0,     0,     0,   108,     0,     0,
     109,     0,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,   109,   150,   151,
     152,   153,   154,   155,   156,   157,     0,   113,   114,   115,
     116,   117,   118,   119,   120,   101,   102,     0,   103,   104,
     105,     0,   150,   151,   152,   153,   154,   155,   156,   157,
       0,   113,   114,   115,   116,   117,   118,   119,   120,   101,
     102,   106,   103,   104,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,   106,   108,     0,     0,   109,
     367,   368,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,     0,   109,   113,   114,   115,   116,   117,   118,
     119,   120,   101,   102,     0,   103,   104,   105,     0,   113,
     114,   115,   116,   117,   118,   119,   120,   101,   102,     0,
     103,   104,   105,     0,     0,     0,     0,     0,   106,     0,
       0,   101,   102,     0,   103,   104,   105,   101,   102,     0,
     103,   104,   105,   106,   107,     0,     0,     0,     0,     0,
       0,     0,     0,   108,     0,     0,   109,   106,   376,   107,
       0,     0,     0,   106,     0,   371,     0,   346,   108,   347,
       0,   109,     0,   107,     0,     0,   372,     0,     0,   107,
       0,     0,   108,     0,     0,   109,     0,     0,   108,   101,
     102,   109,   103,   104,   105,   101,   102,     0,   103,   104,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   106,     0,     0,     0,     0,
       0,   106,     0,     0,     0,     0,     0,   353,     0,     0,
       0,   107,     0,     0,     0,     0,     0,   107,     0,     0,
     108,     0,     0,   109,     0,     0,   108,     0,     0,   109,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,     0,   271,   272,
     273,   274,   275,   276,     0,     0,     0,   334,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,     0,   271,   272,   273,   274,
     275,   276,     0,     0,     0,  -109,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,     0,   271,   272,   273,   274,   275,   276,
       0,     0,     0,  -105,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,     0,   271,   272,   273,   274,   275,   276,     0,     0,
       0,  -111,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,     0,
     271,   272,   273,   274,   275,   276,     0,     0,     0,  -107,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,     0,   271,   272,
     273,   274,   275,   276,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,     0,
     271,   272,   273,   274,   275,   276,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,     0,   271,
     272,   273,   274,   275,   276
};

static const yytype_int16 yycheck[] =
{
       2,    86,     4,     5,     6,    65,     0,   297,    65,    93,
      65,    13,    21,    68,    16,    93,    18,    93,    20,    21,
     130,   136,    93,    69,   139,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    65,    27,    28,     5,     6,
      31,    93,    51,    65,    32,    33,    34,    19,    64,    51,
      52,    23,     3,    25,    26,    65,    37,    67,    68,   139,
     140,    42,    30,     3,    52,    37,   136,    35,    36,   139,
     136,    64,    23,   139,    25,    26,    57,   138,   136,    65,
      82,   139,    65,   143,    86,   142,    37,     8,     9,    10,
     139,   140,    43,    44,   140,    28,   139,   140,    31,    93,
      65,   103,   104,   105,   106,   107,   108,    67,    68,    65,
     169,   315,   316,   223,    88,    82,     8,     9,    10,    68,
      71,    70,    71,    72,    73,    74,    75,    76,    77,   131,
     132,   133,   134,   135,    65,   194,   246,    87,    88,    65,
      90,    91,    92,   202,    88,   435,   138,    87,    88,     0,
      90,    91,    92,   137,   143,   137,   143,   242,   137,   244,
     140,   138,   140,   113,   131,   132,   133,   134,   135,   140,
     140,   140,   138,   113,    95,    96,    97,    98,    99,   129,
     101,   471,   140,   140,   474,   140,   140,   140,   138,   129,
     138,   141,   142,   278,   140,   140,   138,   140,   138,   140,
     490,   141,   140,    95,    96,    97,    98,    99,   140,   101,
     125,    65,   140,   112,   112,   136,    70,    71,    72,    73,
      74,    75,    76,    77,   125,   126,   127,   128,   140,   130,
     131,   132,   133,   134,   135,   140,   238,   105,   240,   142,
     242,    88,   244,   130,   131,   132,   133,   134,   135,   240,
     140,   142,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   238,   269,   270,   271,
     272,   273,   274,   275,   276,    68,   278,    70,    71,    72,
      73,    74,    75,    76,    77,   287,    88,   140,   142,   105,
     241,   105,   243,   295,   296,   297,   287,   105,   300,   140,
     143,    68,    65,   388,    66,    65,    65,   136,   367,   300,
     420,   421,   136,     3,   286,   140,   139,   139,   312,   313,
     314,   315,   316,   140,   136,   140,   277,   140,   112,   331,
     332,   112,   112,   305,   140,   286,   395,    65,   289,    65,
     399,   136,   136,    93,   346,   347,   136,   349,   350,   351,
      42,   353,   303,   355,   305,   127,   128,    26,   130,   131,
     132,   133,   134,   135,   331,   332,   238,    16,    -1,   371,
     372,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     371,   372,    -1,    65,    66,    -1,   388,    -1,    -1,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      90,    91,    92,    -1,    -1,    87,    88,    -1,    90,    91,
      92,    95,    96,    97,    98,    99,    -1,   368,    95,    96,
      97,    98,    99,   113,   375,   376,     3,    -1,   379,    -1,
      -1,   113,    -1,   435,    -1,    -1,    -1,    -1,   389,   129,
     391,    15,    -1,    17,    -1,    -1,    -1,   129,   138,    -1,
      -1,   141,   454,    -1,    -1,   457,   138,    -1,   460,   141,
      -1,   463,   456,    37,   466,   459,    -1,   461,    42,   471,
     464,    -1,   474,    -1,   468,    -1,    69,    -1,    -1,    53,
      -1,    55,    56,    57,    -1,   436,    -1,    -1,   490,    -1,
      -1,   442,    -1,    -1,   496,   497,   498,   499,   500,    -1,
      -1,    -1,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    90,    91,    92,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   113,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,     0,     1,   141,    -1,     4,     5,     6,     7,
      -1,    -1,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    89,    -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   102,   103,   104,    -1,   106,   107,
     108,   109,   110,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,   130,   131,   132,   133,   134,   135,    -1,
       1,    -1,    -1,     4,     5,     6,     7,    -1,    -1,   137,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    89,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   102,   103,   104,    -1,   106,   107,   108,   109,   110,
     123,   124,   125,   126,   127,   128,    -1,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,     1,    -1,    -1,
       4,     5,     6,     7,    -1,    -1,   137,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    89,    -1,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
     104,    -1,   106,   107,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,    -1,     4,     5,     6,     7,
      -1,    -1,    -1,   137,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   102,   103,   104,    -1,   106,   107,
     108,   109,   110,    -1,    -1,    65,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   137,
      90,    91,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    90,    91,    92,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,   138,    -1,
      -1,   141,   142,   143,    -1,    -1,    -1,    -1,   113,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      90,    91,    92,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,    -1,    -1,   141,    -1,   143,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    65,
      66,   141,    68,   143,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    90,    91,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,   113,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    90,
      91,    92,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,   141,   142,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    65,    -1,
     141,   142,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    65,    90,    91,    92,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,   113,    90,    91,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   138,    -1,    -1,   141,   142,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,    65,    66,    -1,
      -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,   141,    -1,
      -1,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    65,    90,    91,    92,    -1,    87,    88,    -1,    90,
      91,    92,    -1,    -1,    -1,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,   113,    90,    91,    92,    -1,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   123,   124,   125,    -1,    -1,    -1,   129,   113,
     138,    -1,    -1,   141,    -1,    -1,    -1,   138,    -1,    -1,
     141,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    -1,    -1,   141,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    90,    91,
      92,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,   113,    90,    91,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,   138,    -1,    -1,   141,
     142,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,    -1,   141,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    90,    91,    92,    -1,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      90,    91,    92,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,    87,    88,    -1,    90,    91,    92,    87,    88,    -1,
      90,    91,    92,   113,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,    -1,    -1,   141,   113,   143,   129,
      -1,    -1,    -1,   113,    -1,   115,    -1,   123,   138,   125,
      -1,   141,    -1,   129,    -1,    -1,   126,    -1,    -1,   129,
      -1,    -1,   138,    -1,    -1,   141,    -1,    -1,   138,    87,
      88,   141,    90,    91,    92,    87,    88,    -1,    90,    91,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,   125,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
     138,    -1,    -1,   141,    -1,    -1,   138,    -1,    -1,   141,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,   139,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,   139,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,   139,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,   139,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
     130,   131,   132,   133,   134,   135,    -1,    -1,    -1,   139,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,   130,   131,
     132,   133,   134,   135,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
     130,   131,   132,   133,   134,   135,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,   130,
     131,   132,   133,   134,   135
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,     5,     6,     7,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      88,    89,    94,   102,   103,   104,   106,   107,   108,   109,
     110,   137,   145,   146,   147,   148,   149,   150,   151,   153,
     163,    87,    88,    90,    91,    92,   113,   129,   138,   141,
     152,   162,     3,    79,    80,    81,    82,    83,    84,    85,
      86,   160,   162,   177,   179,     3,   161,   162,   180,   152,
     152,    93,    93,    93,    93,    93,   162,   181,    65,   164,
     164,   181,    66,   164,   165,   166,   179,   162,   182,    65,
      70,    71,    72,    73,    74,    75,    76,    77,   142,   172,
     176,    65,    66,   162,   171,   175,   171,    65,    65,   142,
     170,   176,   179,    64,   168,   176,   179,    68,   170,   167,
     175,   167,   162,   183,   142,   182,   167,   183,   183,   183,
     182,   182,    66,    68,   142,   164,   165,   169,   176,   179,
      65,    65,   142,    64,   164,   165,   166,   179,   179,    65,
      65,    65,    65,   171,   183,   164,    65,   164,   164,   164,
     165,   179,   138,   152,    88,    88,   154,    95,    96,    97,
      98,    99,   180,     0,   147,   137,   137,     8,     9,    10,
      95,    96,    97,    98,    99,   101,   136,   137,   162,   162,
     162,   162,   162,   162,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   130,   131,   132,   133,   134,   135,   140,   140,   148,
     153,   152,   152,   152,   152,   152,   140,   140,   140,   140,
     176,   178,   140,    69,   178,   140,   140,   140,    65,    68,
     140,   140,   178,   140,    69,   140,   140,   140,    68,   178,
     148,   140,   138,   138,   138,   138,   138,    65,   162,   176,
     177,   175,   179,   180,   179,   180,    95,    96,    97,    98,
      99,    11,    94,   148,   139,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   123,   125,   162,   123,
     124,   125,   162,   125,   162,   125,   162,   162,   162,   162,
     162,   162,   162,   162,     3,   179,   180,   142,   143,   176,
     179,   115,   126,   175,    65,   143,   143,   179,   140,   143,
     162,   174,   162,   173,   173,   112,   112,   175,   143,   140,
      65,   143,   179,   140,    66,   142,   176,   179,   142,   142,
     140,   140,    88,    88,   153,   156,   153,   157,   153,   155,
     159,   153,   155,   158,   153,   155,   105,   105,   105,   105,
     152,   152,   162,   162,   162,   162,   162,   162,   162,   178,
     179,   175,   175,   179,   179,   140,   143,   179,    68,    65,
     180,    65,   143,   179,   179,    66,   178,    65,    67,    68,
      68,   178,    65,    65,   136,   139,   140,   136,   139,   140,
     136,   140,   139,   136,   140,   139,   136,   139,   140,   148,
     148,   140,   173,   179,   140,   179,   112,   112,   112,   162,
     153,   162,   153,   162,   153,   162,   153,   162,   153,   173,
     140,   173,    67,    68,    65,    65,   136,   136,   136,   136,
     136,   173,   162,   162,   162,   162,   162
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   144,   145,   146,   146,   147,   147,   147,   147,   147,
     147,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   149,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   151,   151,   151,   151,   151,   151,   152,   153,
     154,   154,   155,   155,   155,   155,   156,   156,   156,   156,
     157,   157,   157,   157,   158,   158,   158,   158,   159,   159,
     159,   159,   160,   160,   160,   160,   161,   161,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   164,   164,   164,
     164,   165,   165,   166,   166,   166,   167,   168,   168,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   170,   170,   170,   170,   171,   171,   171,   172,
     172,   172,   172,   173,   174,   175,   175,   176,   176,   176,
     176,   176,   176,   176,   176,   177,   177,   177,   177,   177,
     177,   177,   177,   178,   179,   179,   180,   180,   181,   182,
     183
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     5,     3,     5,     3,     3,
       1,     2,     2,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     2,     2,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     3,
       4,     3,     4,     3,     4,     2,     2,     5,     5,     5,
       5,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     3,     5,     1,     3,     3,     5,
       1,     3,     3,     5,     1,     3,     3,     5,     1,     3,
       3,     5,     3,     3,     1,     1,     3,     1,     1,     3,
       2,     2,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     3,     4,     3,
       3,     3,     4,     4,     4,     3,     3,     3,     4,     3,
       3,     3,     4,     3,     1,     1,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     5,     5,     2,     2,
       2,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     7,
       7,     7,     7,     5,     5,     5,     5,     3,     3,     4,
       4,     3,     4,     3,     4,     4,     3,     3,     3,     3,
       3,     4,     3,     3,     4,     4,     4,     5,     4,     3,
       3,     4,     1,     1,     1,     2,     1,     1,     1,     5,
       6,     6,     7,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
  case 5: /* line: undefsym ':' D_DS defexpr linerest  */
#line 213 "parser.y"
                {
			if(yyvsp[-1].val.v<0)
			{
				error("size in DS directive can not be negative");
			}

			if ( ( (current_seg->type==DSEG) || (current_seg->type==ISEG) ) 
				  && (ObjectFile==0) && (current_seg->value<8) )
			{
				if(pass1) warning("DS directive overlaps register bank 0");
			}

			label_symbol=yyvsp[-4].sym;

			if ( (current_seg->type==DSEG) || (current_seg->type==ISEG) ||
				 (current_seg->type==XSEG) )
			{
				yyvsp[-4].sym->value = current_seg->value;
				yyvsp[-4].sym->flags = 0;
				current_seg->value+=yyvsp[-1].val.v;
				yyvsp[-4].sym->type = current_seg->type;
				yyvsp[-4].sym->size = yyvsp[-1].val.v;
				yyvsp[-4].sym->segment=current_seg;
			}
			else
			{
				error("DS directive works only in DSEG, ISEG, or XSEG");
			}
			bytecount = 0;
			yyval.value = 0;
		}
#line 1974 "parser.c"
    break;

  case 6: /* line: D_DS defexpr linerest  */
#line 245 "parser.y"
                {
			if(yyvsp[-1].val.v<0)
			{
				error("size in DS directive can not be negative");
			}

			if ( ( (current_seg->type==DSEG) || (current_seg->type==ISEG) ) 
				  && (ObjectFile==0) && (current_seg->value<8) )
			{
				if(pass1) warning("DS directive overlaps register bank 0");
			}

			if(label_symbol!=NULL)
			{
				if(current_seg->type==label_symbol->type)
				{
					if ( (current_seg->type==DSEG) || (current_seg->type==ISEG) ||
						 (current_seg->type==XSEG) )
					{
						current_seg->value+= yyvsp[-1].val.v;
						label_symbol->size += yyvsp[-1].val.v;
					}
					else
					{
						error("DS directive works only in DSEG, ISEG, or XSEG");
					}
				}
				else
				{
					current_seg->value+= yyvsp[-1].val.v;
					if(pass1) warning("DS directive without a preceding label");
				}
			}
			else
			{
				current_seg->value+= yyvsp[-1].val.v;
				if(pass1) warning("DS directive without a preceding label");
			}
			bytecount = 0;
			yyval.value = 0;
		}
#line 2020 "parser.c"
    break;

  case 7: /* line: undefsym ':' D_DBIT defexpr linerest  */
#line 287 "parser.y"
                {
			label_symbol=yyvsp[-4].sym;
			
			if(yyvsp[-1].val.v<0)
			{
				error("size in DBIT directive can not be negative");
			}
			if(current_seg->type!=BSEG)
			{
				error("DBIT directive works only in BSEG");
			}
			else
			{
				yyvsp[-4].sym->value = current_seg->value;
				yyvsp[-4].sym->flags = 0;
				current_seg->value+=yyvsp[-1].val.v;
				yyvsp[-4].sym->type = current_seg->type;
				yyvsp[-4].sym->size = yyvsp[-1].val.v;
				yyvsp[-4].sym->segment=current_seg;
			}
			bytecount = 0;
			yyval.value = 0;
		}
#line 2048 "parser.c"
    break;

  case 8: /* line: D_DBIT defexpr linerest  */
#line 312 "parser.y"
                {
			if(yyvsp[-1].val.v<0)
			{
				error("size in DBIT directive can not be negative");
			}
			if(label_symbol!=NULL)
			{
				if ( (label_symbol->type!=BSEG) || (current_seg->type!=BSEG) )
				{
					if(pass1) error("DBIT directive works only in BSEG");
				}
				else
				{
					current_seg->value+= yyvsp[-1].val.v;
					label_symbol->size += yyvsp[-1].val.v;
				}
			}
			else
			{
				current_seg->value+= yyvsp[-1].val.v;
				if(pass1) warning("DBIT directive without a preceding label");
			}
			bytecount = 0;
			yyval.value = 0;
		}
#line 2078 "parser.c"
    break;

  case 9: /* line: undefsym ':' linerest  */
#line 339 "parser.y"
                {
			label_symbol=yyvsp[-2].sym;
			if (abort_asap)
			{
				YYABORT;
			}

			yyvsp[-2].sym->type = current_seg->type;
			yyvsp[-2].sym->value = current_seg->value;
			yyvsp[-2].sym->segment = current_seg;
			yyvsp[-2].sym->size = 0;

			if(yyvsp[-2].sym->type==CSEG)
			{
				current_seg->value+=yyvsp[0].value;
				bytecount = 0;
			}
		}
#line 2101 "parser.c"
    break;

  case 10: /* line: linerest  */
#line 358 "parser.y"
        {
		current_seg->value+=yyvsp[0].value;
		bytecount = 0;
	}
#line 2110 "parser.c"
    break;

  case 11: /* linerest: control '\n'  */
#line 366 "parser.y"
        {
		yyval.value = yyvsp[-1].value;
		if( dashl && pass2 ) dumplist(yyvsp[0].str,1);
		symexp[0]=0; // start over with symbolic expression
	}
#line 2120 "parser.c"
    break;

  case 12: /* linerest: directive '\n'  */
#line 372 "parser.y"
        {
		yyval.value = yyvsp[-1].value;
		if( dashl && pass2 ) dumplist(yyvsp[0].str,1);
		symexp[0]=0; // start over with symbolic expression
	}
#line 2130 "parser.c"
    break;

  case 13: /* linerest: conditional  */
#line 378 "parser.y"
        {
		yyval.value = yyvsp[0].value;
		symexp[0]=0; // start over with symbolic expression
	}
#line 2139 "parser.c"
    break;

  case 14: /* linerest: SYMBOL '('  */
#line 383 "parser.y"
        {
		if( (yyvsp[-1].sym->type == UNDEF) && pass1)
				error("Undefined Macro: %s",yyvsp[-1].sym->name);
		seek_eol();
		symexp[0]=0; // start over with symbolic expression
	}
#line 2150 "parser.c"
    break;

  case 15: /* linerest: instr '\n'  */
#line 390 "parser.y"
        {
		if (current_seg->type!=CSEG)
		{
			//Switch to last used code segment
			if(pass1) warning("%s set as the active segment.\n", last_cseg->name);  
			current_seg=last_cseg;
		}
		yyval.value = yyvsp[-1].value;
		if( dashl && pass2 ) dumplist(yyvsp[0].str,1);
		symexp[0]=0; // start over with symbolic expression
		last_cseg=current_seg;
	}
#line 2167 "parser.c"
    break;

  case 16: /* linerest: '\n'  */
#line 403 "parser.y"
        {
		yyval.value = 0;
		if( dashl && pass2 ) dumplist(yyvsp[0].str,0);
		symexp[0]=0; // start over with symbolic expression
	}
#line 2177 "parser.c"
    break;

  case 17: /* linerest: AB  */
#line 408 "parser.y"
               { yyval.value = 0; BadRegUse("AB");   }
#line 2183 "parser.c"
    break;

  case 18: /* linerest: A  */
#line 409 "parser.y"
               { yyval.value = 0; BadRegUse("A");    }
#line 2189 "parser.c"
    break;

  case 19: /* linerest: C  */
#line 410 "parser.y"
               { yyval.value = 0; BadRegUse("C");    }
#line 2195 "parser.c"
    break;

  case 20: /* linerest: PC  */
#line 411 "parser.y"
               { yyval.value = 0; BadRegUse("PC");   }
#line 2201 "parser.c"
    break;

  case 21: /* linerest: DPTR  */
#line 412 "parser.y"
               { yyval.value = 0; BadRegUse("DPTR"); }
#line 2207 "parser.c"
    break;

  case 22: /* linerest: R0  */
#line 413 "parser.y"
               { yyval.value = 0; BadRegUse("R0");   }
#line 2213 "parser.c"
    break;

  case 23: /* linerest: R1  */
#line 414 "parser.y"
               { yyval.value = 0; BadRegUse("R1");   }
#line 2219 "parser.c"
    break;

  case 24: /* linerest: R2  */
#line 415 "parser.y"
               { yyval.value = 0; BadRegUse("R2");   }
#line 2225 "parser.c"
    break;

  case 25: /* linerest: R3  */
#line 416 "parser.y"
               { yyval.value = 0; BadRegUse("R3");   }
#line 2231 "parser.c"
    break;

  case 26: /* linerest: R4  */
#line 417 "parser.y"
               { yyval.value = 0; BadRegUse("R4");   }
#line 2237 "parser.c"
    break;

  case 27: /* linerest: R5  */
#line 418 "parser.y"
               { yyval.value = 0; BadRegUse("R5");   }
#line 2243 "parser.c"
    break;

  case 28: /* linerest: R6  */
#line 419 "parser.y"
               { yyval.value = 0; BadRegUse("R6");   }
#line 2249 "parser.c"
    break;

  case 29: /* linerest: R7  */
#line 420 "parser.y"
               { yyval.value = 0; BadRegUse("R7");   }
#line 2255 "parser.c"
    break;

  case 30: /* linerest: AR0  */
#line 421 "parser.y"
               { yyval.value = 0; BadRegUse("AR0");  }
#line 2261 "parser.c"
    break;

  case 31: /* linerest: AR1  */
#line 422 "parser.y"
               { yyval.value = 0; BadRegUse("AR1");  }
#line 2267 "parser.c"
    break;

  case 32: /* linerest: AR2  */
#line 423 "parser.y"
               { yyval.value = 0; BadRegUse("AR2");  }
#line 2273 "parser.c"
    break;

  case 33: /* linerest: AR3  */
#line 424 "parser.y"
               { yyval.value = 0; BadRegUse("AR3");  }
#line 2279 "parser.c"
    break;

  case 34: /* linerest: AR4  */
#line 425 "parser.y"
               { yyval.value = 0; BadRegUse("AR4");  }
#line 2285 "parser.c"
    break;

  case 35: /* linerest: AR5  */
#line 426 "parser.y"
               { yyval.value = 0; BadRegUse("AR5");  }
#line 2291 "parser.c"
    break;

  case 36: /* linerest: AR6  */
#line 427 "parser.y"
               { yyval.value = 0; BadRegUse("AR6");  }
#line 2297 "parser.c"
    break;

  case 37: /* linerest: AR7  */
#line 428 "parser.y"
               { yyval.value = 0; BadRegUse("AR7");  }
#line 2303 "parser.c"
    break;

  case 38: /* linerest: error  */
#line 430 "parser.y"
        {
		seek_eol();
	}
#line 2311 "parser.c"
    break;

  case 39: /* control: CONTROL  */
#line 436 "parser.y"
{
	if(strncasecmp(yyvsp[0].str, "INCLUDE", 7)==0)
	{
		push_include(yyvsp[0].str);
	}
	else if(strncasecmp(yyvsp[0].str, "MOD", 3)==0)
	{
	    push_include(yyvsp[0].str);
		dosyminit=0; //Don't use default symbol names
	}
	else if(strncasecmp(yyvsp[0].str, "NOMOD51", 7)==0)
	{
		dosyminit=0; //Don't use default symbol names
	}
	else if ( (strncasecmp(yyvsp[0].str, "NOLIST", 6)==0) || (strncasecmp(yyvsp[0].str, "NOPRINT", 7)==0) )
	{
		dashl=0;
	}
	else if(strncasecmp(yyvsp[0].str, "PRINTF_FLOAT", 12)==0)
	{
		printf_float=1;
	}
	else if ( (strncasecmp(yyvsp[0].str, "LIST", 4)==0) || (strncasecmp(yyvsp[0].str, "PRINT", 5)==0) )
	{
		dashl=1;
	}
	else if(strncasecmp(yyvsp[0].str, "OPTC51", 6)==0)
	{
		// The options are passed to the linker to verify proper
		// intermodule compatibility when compiling with C51.
		int j;

		if(pass1)
		{
			strncpy(optc51, &yyvsp[0].str[7], sizeof(optc51)-1);
			for(j=0; optc51[j]!=0; j++) // terminate string at first non-ASCII character
			{
				if( (optc51[j]<0x20) || (optc51[j]>0x7e) ) optc51[j]=0;
			}
		}

	}
	else if(strncasecmp(yyvsp[0].str, "ECHO", 4)==0)
	{
		if(pass2)
		{
			mesg_f("%s\n", &yyvsp[0].str[5]);
		}
	}
	else if(strncasecmp(yyvsp[0].str, "MESSAGE", 7)==0)
	{
		if(pass2)
		{
			mesg_f("%s\n", &yyvsp[0].str[8]);
		}
	}
	else if(strncasecmp(yyvsp[0].str, "ERROR", 5)==0)
	{
		if(pass2)
		{
			error("%s\n", &yyvsp[0].str[6]);
		}
	}
	else if(strncasecmp(yyvsp[0].str, "WARNING", 7)==0)
	{
		if(pass2)
		{
			warning("%s\n", &yyvsp[0].str[8]);
		}
	}
	else if(strncasecmp(yyvsp[0].str, "LINETEST", 8)==0)
	{
		linetest=atoi(&yyvsp[0].str[8]);
	}
	else if( (strncasecmp(yyvsp[0].str, "POUNDWARNING", 12)==0) || (strncasecmp(yyvsp[0].str, "PW", 2)==0) )
	{
		hash_warning_enable=1;
	}
	else if( (strncasecmp(yyvsp[0].str, "NOPOUNDWARNING", 14)==0) || (strncasecmp(yyvsp[0].str, "NPW", 3)==0) )
	{
		hash_warning_enable=0;
	}
	else if( (strncasecmp(yyvsp[0].str, "HASHWARNING", 11)==0) || (strncasecmp(yyvsp[0].str, "HW", 2)==0) )
	{
		hash_warning_enable=1;
	}
	else if( (strncasecmp(yyvsp[0].str, "NOHASHWARNING", 13)==0) || (strncasecmp(yyvsp[0].str, "NHW", 3)==0) )
	{
		hash_warning_enable=0;
	}
	else if(strncasecmp(yyvsp[0].str, "NAME", 4)==0)
	{
		//The module name
	}
	else if(strncasecmp(yyvsp[0].str, "DATE", 4)==0)
	{
	}
	else if(strncasecmp(yyvsp[0].str, "DEBUG", 5)==0)
	{
	}
	else if(strncasecmp(yyvsp[0].str, "PAGELENGTH", 10)==0)
	{
	}
	else if(strncasecmp(yyvsp[0].str, "NOTABS", 6)==0)
	{
	}
	else if(strncasecmp(yyvsp[0].str, "NOPAGING", 8)==0)
	{
	}
	else if(strncasecmp(yyvsp[0].str, "NOSYMBOLS", 9)==0)
	{
	}
	else if(strncasecmp(yyvsp[0].str, "XREF", 4)==0)
	{
	}
	else if(strncasecmp(yyvsp[0].str, "NOMACRO", 7)==0)
	{
	}
	else if(strncasecmp(yyvsp[0].str, "NOBUILTIN", 9)==0)
	{
	}
	else if(strncasecmp(yyvsp[0].str, "TITLE", 5)==0)
	{
	}
	else if(strncasecmp(yyvsp[0].str, "EJECT", 5)==0)
	{
	}
	else if(strncasecmp(yyvsp[0].str, "NOGEN", 5)==0)
	{
	}
	else if(strncasecmp(yyvsp[0].str, "GENONLY", 7)==0)
	{
	}
	else if(strncasecmp(yyvsp[0].str, "GEN", 3)==0)
	{
	}
	else if(strncasecmp(yyvsp[0].str, "NOCOND", 6)==0)
	{
	}
	else if(strncasecmp(yyvsp[0].str, "CONDONLY", 8)==0)
	{
	}
	else if(strncasecmp(yyvsp[0].str, "COND", 4)==0)
	{
	}
	else if(strncasecmp(yyvsp[0].str, "SAVE", 4)==0)
	{
	}
	else if(strncasecmp(yyvsp[0].str, "RESTORE", 7)==0)
	{
	}
	else
		if (pass1) warning("Ignored unknown control '$%s'.\n", yyvsp[0].str);

	free(yyvsp[0].str);
	yyval.value = 0;
	add_ch('\n'); //Very important!
}
#line 2474 "parser.c"
    break;

  case 40: /* directive: D_ORG defexpr  */
#line 599 "parser.y"
                {
			if(current_seg->flags&RELOCATABLE)
			{
				error("ORG directive is only allowed in absolute segments");
			}
			else
			{
				if(ObjectFile==0)
				{
					if(current_seg->value>(unsigned int)yyvsp[0].val.v)
					{
						error("ORG directive must use a value that is greater than the current segment counter.");
					}
				}
				current_seg->value=yyvsp[0].val.v;
				if( pass2 ) emitaddr(current_seg->value);
				bytecount = 0;
				yyval.value = 0;
				if( (ObjectFile==1) && pass2 )
				{
					if(current_seg->type==CSEG)
					{
						fprintf(fobj, "</CODE>\n\n");
						fprintf(fobj, "<CODE AT %04lX>\n", yyvsp[0].val.v);
					}
				}
			}
		}
#line 2507 "parser.c"
    break;

  case 41: /* directive: D_DSEG  */
#line 628 "parser.y"
                {
			label_symbol=NULL;
			current_seg=abs_dseg;
			yyval.value = 0;
		}
#line 2517 "parser.c"
    break;

  case 42: /* directive: D_DSEG D_AT defexpr  */
#line 634 "parser.y"
                {
			label_symbol=NULL;
			current_seg=abs_dseg;
			current_seg->value = yyvsp[0].val.v;
			bytecount = 0;
			yyval.value = 0;
		}
#line 2529 "parser.c"
    break;

  case 43: /* directive: D_CSEG  */
#line 642 "parser.y"
                {
			label_symbol=NULL;
			if( (ObjectFile==1) && pass2 && (current_seg!=abs_cseg) )
			{
				fprintf(fobj, "</CODE>\n\n");
				fprintf(fobj, "<CODE AT %04lX>\n", abs_cseg->value);
			}
			current_seg=abs_cseg;
			last_cseg=current_seg;
			if( pass2 ) emitaddr(current_seg->value);
			bytecount = 0;
			yyval.value = 0;
		}
#line 2547 "parser.c"
    break;

  case 44: /* directive: D_CSEG D_AT defexpr  */
#line 656 "parser.y"
                {
			label_symbol=NULL;
			if(ObjectFile==0)
			{
				if(current_seg->value>(unsigned int)yyvsp[0].val.v)
				{
					error("'CSEG at' directive must use a value that is greater than the current CSEG counter.");
				}
			}
			if( (ObjectFile==1) && pass2 )
			{
				fprintf(fobj, "</CODE>\n\n");
				fprintf(fobj, "<CODE AT %04lX>\n", yyvsp[0].val.v);
			}
			current_seg=abs_cseg;
			last_cseg=current_seg;
			current_seg->value = yyvsp[0].val.v;
			if( pass2 ) emitaddr(current_seg->value);
			bytecount = 0;
			yyval.value = 0;
	}
#line 2573 "parser.c"
    break;

  case 45: /* directive: D_ISEG  */
#line 678 "parser.y"
                {
			label_symbol=NULL;
			current_seg=abs_iseg;
			yyval.value = 0;
		}
#line 2583 "parser.c"
    break;

  case 46: /* directive: D_ISEG D_AT defexpr  */
#line 684 "parser.y"
                {
			label_symbol=NULL;
			current_seg=abs_iseg;
			current_seg->value = yyvsp[0].val.v;
			bytecount = 0;
			yyval.value = 0;
		}
#line 2595 "parser.c"
    break;

  case 47: /* directive: D_BSEG  */
#line 692 "parser.y"
                {
			label_symbol=NULL;
			current_seg=abs_bseg;
			yyval.value = 0;
		}
#line 2605 "parser.c"
    break;

  case 48: /* directive: D_BSEG D_AT defexpr  */
#line 698 "parser.y"
                {
			label_symbol=NULL;
			current_seg=abs_bseg;
			current_seg->value = yyvsp[0].val.v;
			bytecount = 0;
			yyval.value = 0;
		}
#line 2617 "parser.c"
    break;

  case 49: /* directive: D_XSEG  */
#line 706 "parser.y"
                {
			label_symbol=NULL;
			current_seg=abs_xseg;
			yyval.value = 0;
		}
#line 2627 "parser.c"
    break;

  case 50: /* directive: D_XSEG D_AT defexpr  */
#line 712 "parser.y"
                {
			label_symbol=NULL;
			current_seg=abs_xseg;
			current_seg->value = yyvsp[0].val.v;
			bytecount = 0;
			yyval.value = 0;
		}
#line 2639 "parser.c"
    break;

  case 51: /* directive: D_BYTE blist  */
#line 720 "parser.y"
                {
			if(current_seg->type!=CSEG)
			{
				if(pass1) warning("%s set as the active segment.\n", last_cseg->name);  
				current_seg=last_cseg;
			}
			yyval.value = yyvsp[0].value;
			last_cseg=current_seg;
		}
#line 2653 "parser.c"
    break;

  case 52: /* directive: D_WORD wlist  */
#line 730 "parser.y"
                {
			if(current_seg->type!=CSEG)
			{
				if(pass1) warning("%s set as the active segment.\n", last_cseg->name);  
				current_seg=last_cseg;
			}
			yyval.value = yyvsp[0].value;
			yyval.val.s=yyvsp[0].val.s;
			last_cseg=current_seg;
		}
#line 2668 "parser.c"
    break;

  case 53: /* directive: D_SKIP defexpr  */
#line 741 "parser.y"
                {
			current_seg->value+=yyvsp[0].val.v;
			yyval.value = yyvsp[0].val.v;
			if( pass2 )	emitaddr(current_seg->value);
		}
#line 2678 "parser.c"
    break;

  case 54: /* directive: undefsym D_EQU  */
#line 747 "parser.y"
                {
			if(pass1)
			{
				yyvsp[-1].sym->literal=yyvsp[0].str;
				yyvsp[-1].sym->type = EQU;
				yyvsp[-1].sym->value = 0;
			}
			else //pass2
			{
				free(yyvsp[0].str);
			}
			yyval.value = 0;
		}
#line 2696 "parser.c"
    break;

  case 55: /* directive: undefsym D_MAC  */
#line 761 "parser.y"
                {
			if(pass1)
			{
				yyvsp[-1].sym->literal=yyvsp[0].str;
				yyvsp[-1].sym->type = MAC;
				yyvsp[-1].sym->value = 0;
			}
			else //pass2
			{
				free(yyvsp[0].str);
			}
			yyval.value = 0;
		}
#line 2714 "parser.c"
    break;

  case 56: /* directive: USING data8  */
#line 775 "parser.y"
                {
			if(yyvsp[0].val.v<4)
				RegisterBank=yyvsp[0].val.v;
			else
				error("Register bank can only be set to 0, 1, 2, or 3");
			yyval.value = 0;
		}
#line 2726 "parser.c"
    break;

  case 57: /* directive: undefsym D_DATA data8  */
#line 783 "parser.y"
                {
			yyvsp[-2].sym->type = DSEG;
			yyvsp[-2].sym->segment = NULL;
			yyvsp[-2].sym->flags = CONSTANT; // These are not variables but constants
			yyvsp[-2].sym->value = yyvsp[0].val.v;
			yyval.value = 0;
		}
#line 2738 "parser.c"
    break;

  case 58: /* directive: undefsym D_IDATA data8  */
#line 791 "parser.y"
                {
			yyvsp[-2].sym->type = ISEG;
			yyvsp[-2].sym->segment = NULL;
			yyvsp[-2].sym->flags = CONSTANT; // These are not variables but constants
			yyvsp[-2].sym->value = yyvsp[0].val.v;
			yyval.value = 0;
		}
#line 2750 "parser.c"
    break;

  case 59: /* directive: undefsym D_XDATA data16  */
#line 799 "parser.y"
                {
			yyvsp[-2].sym->type = XSEG;
			yyvsp[-2].sym->segment = NULL;
			yyvsp[-2].sym->flags = CONSTANT; // These are not variables but constants
			yyvsp[-2].sym->value = yyvsp[0].val.v;
			yyval.value = 0;
		}
#line 2762 "parser.c"
    break;

  case 60: /* directive: undefsym D_CODE data16  */
#line 807 "parser.y"
                {
			yyvsp[-2].sym->type = CSEG;
			yyvsp[-2].sym->segment = NULL;
			yyvsp[-2].sym->flags = CONSTANT; // These are not variables but constants
			yyvsp[-2].sym->value = yyvsp[0].val.v;
			yyval.value = 0;
		}
#line 2774 "parser.c"
    break;

  case 61: /* directive: undefsym D_BIT bit  */
#line 815 "parser.y"
                {
			yyvsp[-2].sym->type = BSEG;
			yyvsp[-2].sym->segment = NULL;
			yyvsp[-2].sym->flags = CONSTANT; // These are not variables but constants
			yyvsp[-2].sym->value = yyvsp[0].val.v;
			yyval.value = 0;
		}
#line 2786 "parser.c"
    break;

  case 62: /* directive: undefsym D_SET reg  */
#line 823 "parser.y"
                {
			if(yyvsp[-2].sym->literal!=NULL) free(yyvsp[-2].sym->literal);
			yyvsp[-2].sym->literal=(char *)malloc(2+1);
			sprintf(yyvsp[-2].sym->literal, "R%ld", yyvsp[0].val.v);
			yyvsp[-2].sym->type = SET;
			yyvsp[-2].sym->value = 0;
			yyval.value = 0;
		}
#line 2799 "parser.c"
    break;

  case 63: /* directive: undefsym D_SET areg  */
#line 832 "parser.y"
                {
			if(yyvsp[-2].sym->literal!=NULL) free(yyvsp[-2].sym->literal);
			yyvsp[-2].sym->literal=(char *)malloc(3+1);
			sprintf(yyvsp[-2].sym->literal, "AR%ld", yyvsp[0].val.v);
			yyvsp[-2].sym->type = SET;
			yyvsp[-2].sym->value = 0;
			yyval.value = 0;
		}
#line 2812 "parser.c"
    break;

  case 64: /* directive: undefsym D_SET A  */
#line 841 "parser.y"
                {
			if(yyvsp[-2].sym->literal!=NULL) free(yyvsp[-2].sym->literal);
			yyvsp[-2].sym->literal=(char *)malloc(2);
			strcpy(yyvsp[-2].sym->literal, "A");
			yyvsp[-2].sym->type = SET;
			yyvsp[-2].sym->value = 0;
			yyval.value = 0;
		}
#line 2825 "parser.c"
    break;

  case 65: /* directive: undefsym D_SET expr  */
#line 850 "parser.y"
                {
			if(yyvsp[-2].sym->literal!=NULL)
			{
				free(yyvsp[-2].sym->literal);
				yyvsp[-2].sym->literal=NULL;
			}
			yyvsp[-2].sym->type = SET;
			yyvsp[-2].sym->value = yyvsp[0].val.v;
			yyval.value = 0;
		}
#line 2840 "parser.c"
    break;

  case 66: /* directive: undefsym D_SEG D_CODE  */
#line 861 "parser.y"
                {
			if(ObjectFile==0) { NoObjectFileError("SEGMENT"); YYABORT; }

			if(strlen(MapFile)==0) yyvsp[-2].sym->value=0;
			yyvsp[-2].sym->segment=NULL;
			yyvsp[-2].sym->type=CSEG;
			yyvsp[-2].sym->flags=SEGMENT|RELOCATABLE;
			yyvsp[-2].sym->size=0;
			yyval.value = 0;
		}
#line 2855 "parser.c"
    break;

  case 67: /* directive: undefsym D_SEG D_XDATA  */
#line 872 "parser.y"
                {
			if(ObjectFile==0) { NoObjectFileError("SEGMENT"); YYABORT; }

			if(strlen(MapFile)==0) yyvsp[-2].sym->value=0;
			yyvsp[-2].sym->segment=NULL;
			yyvsp[-2].sym->type=XSEG;
			yyvsp[-2].sym->flags=SEGMENT|RELOCATABLE;
			yyvsp[-2].sym->size=0;
			yyval.value = 0;
		}
#line 2870 "parser.c"
    break;

  case 68: /* directive: undefsym D_SEG D_XDATA OVERL  */
#line 883 "parser.y"
                {
			if(ObjectFile==0) { NoObjectFileError("SEGMENT"); YYABORT; }

			if(strlen(MapFile)==0) yyvsp[-3].sym->value=0;
			yyvsp[-3].sym->segment=NULL;
			yyvsp[-3].sym->type=XSEG;
			yyvsp[-3].sym->flags=SEGMENT|RELOCATABLE|OVERLAYABLE;
			yyvsp[-3].sym->size=0;
			yyval.value = 0;
		}
#line 2885 "parser.c"
    break;

  case 69: /* directive: undefsym D_SEG D_DATA  */
#line 894 "parser.y"
                {
			if(ObjectFile==0) { NoObjectFileError("SEGMENT"); YYABORT; }

			if(strlen(MapFile)==0) yyvsp[-2].sym->value=0;
			yyvsp[-2].sym->segment=NULL;
			yyvsp[-2].sym->type=DSEG;
			yyvsp[-2].sym->flags=SEGMENT|RELOCATABLE;
			yyvsp[-2].sym->size=0;
			yyval.value = 0;
		}
#line 2900 "parser.c"
    break;

  case 70: /* directive: undefsym D_SEG D_DATA OVERL  */
#line 905 "parser.y"
                {
			if(ObjectFile==0) { NoObjectFileError("SEGMENT"); YYABORT; }

			if(strlen(MapFile)==0) yyvsp[-3].sym->value=0;
			yyvsp[-3].sym->segment=NULL;
			yyvsp[-3].sym->type=DSEG;
			yyvsp[-3].sym->flags=SEGMENT|RELOCATABLE|OVERLAYABLE;
			yyvsp[-3].sym->size=0;
			yyval.value = 0;
		}
#line 2915 "parser.c"
    break;

  case 71: /* directive: undefsym D_SEG D_IDATA  */
#line 916 "parser.y"
                {
			if(ObjectFile==0) { NoObjectFileError("SEGMENT");  YYABORT; }

			if(strlen(MapFile)==0) yyvsp[-2].sym->value=0;
			yyvsp[-2].sym->segment=NULL;
			yyvsp[-2].sym->type=ISEG;
			yyvsp[-2].sym->flags=SEGMENT|RELOCATABLE;
			yyvsp[-2].sym->size=0;
			yyval.value = 0;
		}
#line 2930 "parser.c"
    break;

  case 72: /* directive: undefsym D_SEG D_IDATA OVERL  */
#line 927 "parser.y"
                {
			if(ObjectFile==0) { NoObjectFileError("SEGMENT"); YYABORT; }

			if(strlen(MapFile)==0) yyvsp[-3].sym->value=0;
			yyvsp[-3].sym->segment=NULL;
			yyvsp[-3].sym->type=ISEG;
			yyvsp[-3].sym->flags=SEGMENT|RELOCATABLE|OVERLAYABLE;
			yyvsp[-3].sym->size=0;
			yyval.value = 0;
		}
#line 2945 "parser.c"
    break;

  case 73: /* directive: undefsym D_SEG D_BIT  */
#line 938 "parser.y"
                {
			if(ObjectFile==0) { NoObjectFileError("SEGMENT"); YYABORT; }

			if(strlen(MapFile)==0) yyvsp[-2].sym->value=0;
			yyvsp[-2].sym->segment=NULL;
			yyvsp[-2].sym->type=BSEG;
			yyvsp[-2].sym->flags=SEGMENT|RELOCATABLE;
			yyvsp[-2].sym->size=0;
			yyval.value = 0;
		}
#line 2960 "parser.c"
    break;

  case 74: /* directive: undefsym D_SEG D_BIT OVERL  */
#line 949 "parser.y"
                {
			if(ObjectFile==0) { NoObjectFileError("SEGMENT"); YYABORT; }

			if(strlen(MapFile)==0) yyvsp[-3].sym->value=0;
			yyvsp[-3].sym->segment=NULL;
			yyvsp[-3].sym->type=BSEG;
			yyvsp[-3].sym->flags=SEGMENT|RELOCATABLE|OVERLAYABLE;
			yyvsp[-3].sym->size=0;
			yyval.value = 0;
		}
#line 2975 "parser.c"
    break;

  case 75: /* directive: D_RSEG SYMBOL  */
#line 960 "parser.y"
                {
			if(ObjectFile==0) { NoObjectFileError("RSEG"); YYABORT; }

			if(yyvsp[0].sym->type==UNDEF)
			{
				error("Undefined segment: %s", yyvsp[0].sym->name);
			}
			else
			{
				current_seg=yyvsp[0].sym;
				if((pass2)&&(current_seg->type==CSEG))
				{
					fprintf(fobj, "</CODE>\n\n");
					fprintf(fobj, "<CODE %s>\n", current_seg->name);
				}
				if(pass2) emitaddr(current_seg->value); // Warning: this must be erased!
				yyval.value = 0;
			}
		}
#line 2999 "parser.c"
    break;

  case 76: /* directive: PUBLIC publist  */
#line 980 "parser.y"
                {
			if(ObjectFile==0) { NoObjectFileError("PUBLIC"); YYABORT; }
			yyval.value = 0;
		}
#line 3008 "parser.c"
    break;

  case 77: /* directive: EXTERN D_CODE '(' extlist_code ')'  */
#line 985 "parser.y"
                {
			if(ObjectFile==0) { NoObjectFileError("EXTERN"); YYABORT; }
			yyval.value = 0;
		}
#line 3017 "parser.c"
    break;

  case 78: /* directive: EXTERN D_DATA '(' extlist_data ')'  */
#line 990 "parser.y"
                {
			if(ObjectFile==0) { NoObjectFileError("EXTERN"); YYABORT; }
			yyval.value = 0;
		}
#line 3026 "parser.c"
    break;

  case 79: /* directive: EXTERN D_XDATA '(' extlist_xdata ')'  */
#line 995 "parser.y"
                {
			if(ObjectFile==0) { NoObjectFileError("EXTERN"); YYABORT; }
			yyval.value = 0;
		}
#line 3035 "parser.c"
    break;

  case 80: /* directive: EXTERN D_IDATA '(' extlist_idata ')'  */
#line 1000 "parser.y"
                {
			if(ObjectFile==0) { NoObjectFileError("EXTERN"); YYABORT; }
			yyval.value = 0;
		}
#line 3044 "parser.c"
    break;

  case 81: /* directive: EXTERN D_BIT '(' extlist_bit ')'  */
#line 1005 "parser.y"
                {
			if(ObjectFile==0) { NoObjectFileError("EXTERN"); YYABORT; }
			yyval.value = 0;
		}
#line 3053 "parser.c"
    break;

  case 82: /* conditional: IF data16  */
#line 1020 "parser.y"
                {
			IF_Level++;
			if(IF_Level>sizeof(IF_Flag))
			{
				error("Too many nested IFs");
			}
			if(pass1)
			{
				IF_Flag[IF_Level]=yyvsp[0].val.v?1:0;
				IF_Value[IF_Count]=yyvsp[0].val.v?1:0;
				IF_Count++;
				if(IF_Count>sizeof(IF_Value))
				{
					error("Too many IFs");
				}
			}
			else // use the value saved in pass 1
			{
				IF_Flag[IF_Level]=IF_Value[IF_Count];
				IF_Count++;
			}
			yyval.value = 0;
		}
#line 3081 "parser.c"
    break;

  case 83: /* conditional: IFDEF  */
#line 1045 "parser.y"
                {
			IF_Level++;
			if(IF_Level>sizeof(IF_Flag))
			{
				error("Too many nested IFs");
			}
			if(pass1)
			{
				IF_Flag[IF_Level]=( yyvsp[0].val.v == 1 )?1:0;
				IF_Value[IF_Count]=( yyvsp[0].val.v == 1 )?1:0;
				IF_Count++;
				if(IF_Count>sizeof(IF_Value))
				{
					error("Too many IFDEFs");
				}
			}
			else // use the value saved in pass 1
			{
				IF_Flag[IF_Level]=IF_Value[IF_Count];
				IF_Count++;
			}
			yyval.value = 0;
		}
#line 3109 "parser.c"
    break;

  case 84: /* conditional: IFNDEF  */
#line 1070 "parser.y"
                {
			IF_Level++;
			if(IF_Level>sizeof(IF_Flag))
			{
				error("Too many nested IFs");
			}
			if(pass1)
			{
				IF_Flag[IF_Level]=( yyvsp[0].val.v == 1 )?0:1;
				IF_Value[IF_Count]=( yyvsp[0].val.v == 1 )?0:1;
				IF_Count++;
				if(IF_Count>sizeof(IF_Value))
				{
					error("Too many IFNDEFs");
				}
			}
			else // use the value saved in pass 1
			{
				IF_Flag[IF_Level]=IF_Value[IF_Count];
				IF_Count++;
			}
			yyval.value = 0;
		}
#line 3137 "parser.c"
    break;

  case 85: /* conditional: ELSE  */
#line 1094 "parser.y"
                {
			if(IF_Level==0)
			{
				error("foound ELSE without matching IF");
			}
			else
			{
				IF_Flag[IF_Level] = (IF_Flag[IF_Level]==0?1:0);
			}
			yyval.value = 0;
		}
#line 3153 "parser.c"
    break;

  case 86: /* conditional: ENDIF  */
#line 1106 "parser.y"
                {
			if(IF_Level==0)
			{
				error("found ENDIF without matching IF");
			}
			else
			{
				IF_Level--;
			}
			yyval.value = 0;
		}
#line 3169 "parser.c"
    break;

  case 87: /* conditional: D_END  */
#line 1118 "parser.y"
        {
		force_EOF=1;
		yyval.value = 0;
	}
#line 3178 "parser.c"
    break;

  case 88: /* defexpr: expr  */
#line 1126 "parser.y"
                {
			if( yyvsp[0].val.d == 0 )
				error("Expression is undefined in pass 1");
			if( !(isbit16(yyvsp[0].val.v)) )
				error("Value greater than 16-bits");
			yyval.value = yyvsp[0].val.v;
		}
#line 3190 "parser.c"
    break;

  case 89: /* undefsym: SYMBOL  */
#line 1137 "parser.y"
                {
			if( yyvsp[0].sym->type != SET )
			{ 
				// Only 'set' symbols are redefinable, all other generate an error
				if( yyvsp[0].sym->type != UNDEF && pass1)
					if(strncmp(yyvsp[0].sym->name, "C?", 2)) // Ignore badly generated C51 Debug symbols
						error("Attempt to redefine symbol: %s",yyvsp[0].sym->name);
			}
			yyvsp[0].sym->segment=current_seg;
			yyval.sym = yyvsp[0].sym;
		}
#line 3206 "parser.c"
    break;

  case 90: /* publist: SYMBOL  */
#line 1152 "parser.y"
        {
		if( yyvsp[0].sym->type == UNDEF && pass2)
			error("Undefined symbol: %s",yyvsp[0].sym->name);
		//Mark the symbol as public
		yyvsp[0].sym->flags=PUBLIC_SYM;
	}
#line 3217 "parser.c"
    break;

  case 91: /* publist: publist ',' SYMBOL  */
#line 1159 "parser.y"
        {
		if( yyvsp[0].sym->type == UNDEF && pass2)
			error("Undefined symbol: %s",yyvsp[0].sym->name);
		//Mark the symbol as public
		yyvsp[0].sym->flags=PUBLIC_SYM;
	}
#line 3228 "parser.c"
    break;

  case 92: /* extlist_code: undefsym  */
#line 1169 "parser.y"
        {
		yyvsp[0].sym->type = CSEG;
		yyvsp[0].sym->value = 0;
		yyvsp[0].sym->size = 1;
		yyvsp[0].sym->flags=EXTERN_SYM;
	}
#line 3239 "parser.c"
    break;

  case 93: /* extlist_code: undefsym ':' expr  */
#line 1176 "parser.y"
        {
		yyvsp[-2].sym->type = CSEG;
		yyvsp[-2].sym->value = 0;
		yyvsp[-2].sym->size = yyvsp[0].value;
		yyvsp[-2].sym->flags=EXTERN_SYM;
	}
#line 3250 "parser.c"
    break;

  case 94: /* extlist_code: extlist_code ',' undefsym  */
#line 1183 "parser.y"
        {
		yyvsp[0].sym->type = CSEG;
		yyvsp[0].sym->value = 0;
		yyvsp[0].sym->size = 1;
		yyvsp[0].sym->flags=EXTERN_SYM;
	}
#line 3261 "parser.c"
    break;

  case 95: /* extlist_code: extlist_code ',' undefsym ':' expr  */
#line 1190 "parser.y"
        {
		yyvsp[-2].sym->type = CSEG;
		yyvsp[-2].sym->value = 0;
		yyvsp[-2].sym->size = yyvsp[0].value;
		yyvsp[-2].sym->flags=EXTERN_SYM;
	}
#line 3272 "parser.c"
    break;

  case 96: /* extlist_bit: undefsym  */
#line 1200 "parser.y"
        {
		yyvsp[0].sym->type = BSEG;
		yyvsp[0].sym->value = 0;
		yyvsp[0].sym->size = 1;
		yyvsp[0].sym->flags=EXTERN_SYM;
	}
#line 3283 "parser.c"
    break;

  case 97: /* extlist_bit: undefsym ':' expr  */
#line 1207 "parser.y"
        {
		yyvsp[-2].sym->type = BSEG;
		yyvsp[-2].sym->value = 0;
		yyvsp[-2].sym->size = yyvsp[0].value;
		yyvsp[-2].sym->flags=EXTERN_SYM;
	}
#line 3294 "parser.c"
    break;

  case 98: /* extlist_bit: extlist_bit ',' undefsym  */
#line 1214 "parser.y"
        {
		yyvsp[0].sym->type = BSEG;
		yyvsp[0].sym->value = 0;
		yyvsp[0].sym->size = 1;
		yyvsp[0].sym->flags=EXTERN_SYM;
	}
#line 3305 "parser.c"
    break;

  case 99: /* extlist_bit: extlist_bit ',' undefsym ':' expr  */
#line 1221 "parser.y"
        {
		yyvsp[-2].sym->type = BSEG;
		yyvsp[-2].sym->value = 0;
		yyvsp[-2].sym->size = yyvsp[0].value;
		yyvsp[-2].sym->flags=EXTERN_SYM;
	}
#line 3316 "parser.c"
    break;

  case 100: /* extlist_data: undefsym  */
#line 1232 "parser.y"
        {
		yyvsp[0].sym->type = DSEG;
		yyvsp[0].sym->value = 0;
		yyvsp[0].sym->size = 1;
		yyvsp[0].sym->flags=EXTERN_SYM;
	}
#line 3327 "parser.c"
    break;

  case 101: /* extlist_data: undefsym ':' expr  */
#line 1239 "parser.y"
        {
		yyvsp[-2].sym->type = DSEG;
		yyvsp[-2].sym->value = 0;
		yyvsp[-2].sym->size = yyvsp[0].value;
		yyvsp[-2].sym->flags=EXTERN_SYM;
	}
#line 3338 "parser.c"
    break;

  case 102: /* extlist_data: extlist_data ',' undefsym  */
#line 1246 "parser.y"
        {
		yyvsp[0].sym->type = DSEG;
		yyvsp[0].sym->value = 0;
		yyvsp[0].sym->size = 1;
		yyvsp[0].sym->flags=EXTERN_SYM;
	}
#line 3349 "parser.c"
    break;

  case 103: /* extlist_data: extlist_data ',' undefsym ':' expr  */
#line 1253 "parser.y"
        {
		yyvsp[-2].sym->type = DSEG;
		yyvsp[-2].sym->value = 0;
		yyvsp[-2].sym->size = yyvsp[0].value;
		yyvsp[-2].sym->flags=EXTERN_SYM;
	}
#line 3360 "parser.c"
    break;

  case 104: /* extlist_idata: undefsym  */
#line 1263 "parser.y"
        {
		yyvsp[0].sym->type = ISEG;
		yyvsp[0].sym->value = 0;
		yyvsp[0].sym->size = 1;
		yyvsp[0].sym->flags=EXTERN_SYM;
	}
#line 3371 "parser.c"
    break;

  case 105: /* extlist_idata: undefsym ':' expr  */
#line 1270 "parser.y"
        {
		yyvsp[-2].sym->type = ISEG;
		yyvsp[-2].sym->value = 0;
		yyvsp[-2].sym->size = yyvsp[0].value;
		yyvsp[-2].sym->flags=EXTERN_SYM;
	}
#line 3382 "parser.c"
    break;

  case 106: /* extlist_idata: extlist_code ',' undefsym  */
#line 1277 "parser.y"
        {
		yyvsp[0].sym->type = ISEG;
		yyvsp[0].sym->value = 0;
		yyvsp[0].sym->size = 1;
		yyvsp[0].sym->flags=EXTERN_SYM;
	}
#line 3393 "parser.c"
    break;

  case 107: /* extlist_idata: extlist_code ',' undefsym ':' expr  */
#line 1284 "parser.y"
        {
		yyvsp[-2].sym->type = ISEG;
		yyvsp[-2].sym->value = 0;
		yyvsp[-2].sym->size = yyvsp[0].value;
		yyvsp[-2].sym->flags=EXTERN_SYM;
	}
#line 3404 "parser.c"
    break;

  case 108: /* extlist_xdata: undefsym  */
#line 1294 "parser.y"
        {
		yyvsp[0].sym->type = XSEG;
		yyvsp[0].sym->value = 0;
		yyvsp[0].sym->size = 1;
		yyvsp[0].sym->flags=EXTERN_SYM;
	}
#line 3415 "parser.c"
    break;

  case 109: /* extlist_xdata: undefsym ':' expr  */
#line 1301 "parser.y"
        {
		yyvsp[-2].sym->type = XSEG;
		yyvsp[-2].sym->value = 0;
		yyvsp[-2].sym->size = yyvsp[0].value;
		yyvsp[-2].sym->flags=EXTERN_SYM;
	}
#line 3426 "parser.c"
    break;

  case 110: /* extlist_xdata: extlist_code ',' undefsym  */
#line 1308 "parser.y"
        {
		yyvsp[0].sym->type = XSEG;
		yyvsp[0].sym->value = 0;
		yyvsp[0].sym->size = 1;
		yyvsp[0].sym->flags=EXTERN_SYM;
	}
#line 3437 "parser.c"
    break;

  case 111: /* extlist_xdata: extlist_code ',' undefsym ':' expr  */
#line 1315 "parser.y"
        {
		yyvsp[-2].sym->type = XSEG;
		yyvsp[-2].sym->value = 0;
		yyvsp[-2].sym->size = yyvsp[0].value;
		yyvsp[-2].sym->flags=EXTERN_SYM;
	}
#line 3448 "parser.c"
    break;

  case 112: /* blist: blist ',' data8  */
#line 1325 "parser.y"
                {
			if( pass2 )
			{
				if(ObjectFile)
				{
					if(yyvsp[0].val.s==1)
					{
						fprintf(fobj, "%s\n", yyvsp[0].val.rel);
					}
					else
					{
						objbyte(yyvsp[0].value);
					}
				}
				genbyte(yyvsp[0].value);
			}
			yyval.value = yyvsp[-2].value + 1;
		}
#line 3471 "parser.c"
    break;

  case 113: /* blist: blist ',' STRING  */
#line 1344 "parser.y"
                {
			yyval.value = yyvsp[-2].value + strlen(yyvsp[0].str);
			if( pass2 )
			{
				genstr(yyvsp[0].str);
				if(ObjectFile) objstr(yyvsp[0].str);
			}
			free(yyvsp[0].str);
		}
#line 3485 "parser.c"
    break;

  case 114: /* blist: data8  */
#line 1354 "parser.y"
                {
			if( pass2 )
			{
				if(ObjectFile)
				{
					if(yyvsp[0].val.s==1)
					{
						fprintf(fobj, "%s\n", yyvsp[0].val.rel);
					}
					else
					{
						objbyte(yyvsp[0].value);
					}
				}
				genbyte(yyvsp[0].value);
			}
			yyval.value = 1;
		}
#line 3508 "parser.c"
    break;

  case 115: /* blist: STRING  */
#line 1373 "parser.y"
                {
			yyval.value = strlen(yyvsp[0].str);
			if( pass2 )
			{
				genstr(yyvsp[0].str);
				if(ObjectFile) objstr(yyvsp[0].str);
			}
			free(yyvsp[0].str);
		}
#line 3522 "parser.c"
    break;

  case 116: /* wlist: wlist ',' data16  */
#line 1386 "parser.y"
                {
			if( pass2 )
			{
				if(ObjectFile)
				{
					if(yyvsp[0].val.s==1)
					{
						fprintf(fobj, "%s\n", yyvsp[0].val.rel);
					}
					else
					{
						objword(yyvsp[0].value);
					}
				}
				genword(yyvsp[0].value);
			}
			yyval.value = yyvsp[-2].value + 2;
		}
#line 3545 "parser.c"
    break;

  case 117: /* wlist: data16  */
#line 1405 "parser.y"
                {
			if( pass2 )
			{
				if(ObjectFile)
				{
					if(yyvsp[0].val.s==1)
					{
						fprintf(fobj, "%s\n", yyvsp[0].val.rel);
					}
					else
					{
						objword(yyvsp[0].value);
					}
				}
				genword(yyvsp[0].value);
			}
			yyval.value = 2;
		}
#line 3568 "parser.c"
    break;

  case 118: /* expr: '$'  */
#line 1429 "parser.y"
                {
			yyval.val.v = current_seg->value;
			yyval.val.d = 1;
			if(current_seg->flags&RELOCATABLE)
			{
				// There is a problem with relocatable expressions and the 'current program counter'
				// operator '$'.  This is because we don't know for what instruction the '$' was
				// generated, so when locating code we only know the position where the operator apperead
				// and that is what the linker is going to use.
				strcat(symexp,"$;");
				yyval.val.s = 1;
				yyval.val.k = 1;
			}
		}
#line 3587 "parser.c"
    break;

  case 119: /* expr: '(' expr ')'  */
#line 1444 "parser.y"
                {
			yyval.val.s = yyvsp[-1].val.s;
			yyval.val.v = yyvsp[-1].val.v;
			yyval.val.d = yyvsp[-1].val.d;
			yyval.val.k = yyvsp[-1].val.k;
		}
#line 3598 "parser.c"
    break;

  case 120: /* expr: '-' expr  */
#line 1451 "parser.y"
                {
			strcat(symexp,"0xFFFF;*;");
			yyval.val.s = yyvsp[0].val.s;
			yyval.val.v = -yyvsp[0].val.v;
			yyval.val.d = yyvsp[0].val.d;
			yyval.val.k = yyvsp[0].val.k;
		}
#line 3610 "parser.c"
    break;

  case 121: /* expr: HIGH expr  */
#line 1459 "parser.y"
                {
			strcat(symexp,"0x0008;>>;");
			yyval.val.s = yyvsp[0].val.s;
			yyval.val.v = ((yyvsp[0].val.v / 0x100) & 0xff);
			yyval.val.d = yyvsp[0].val.d;
			yyval.val.k = yyvsp[0].val.k;
		}
#line 3622 "parser.c"
    break;

  case 122: /* expr: LOW expr  */
#line 1467 "parser.y"
                {
			strcat(symexp,"0x00FF;&;");
			yyval.val.s = yyvsp[0].val.s;
			yyval.val.v = ((yyvsp[0].val.v % 0x100) & 0xff);
			yyval.val.d = yyvsp[0].val.d;
			yyval.val.k = yyvsp[0].val.k;
		}
#line 3634 "parser.c"
    break;

  case 123: /* expr: NOT expr  */
#line 1475 "parser.y"
                {
			strcat(symexp,"~;");
			yyval.val.s = yyvsp[0].val.s;
			yyval.val.v = (~yyvsp[0].val.v & 0xffff);
			yyval.val.d = yyvsp[0].val.d;
			yyval.val.k = yyvsp[0].val.k;
		}
#line 3646 "parser.c"
    break;

  case 124: /* expr: '~' expr  */
#line 1483 "parser.y"
                {
			strcat(symexp,"~;");
			yyval.val.s = yyvsp[0].val.s;
			yyval.val.v = (~yyvsp[0].val.v & 0xffff);
			yyval.val.d = yyvsp[0].val.d;
			yyval.val.k = yyvsp[0].val.k;
		}
#line 3658 "parser.c"
    break;

  case 125: /* expr: expr '|' expr  */
#line 1491 "parser.y"
                {
			strcat(symexp,"|;");
			yyval.val.s = yyvsp[-2].val.s | yyvsp[0].val.s;
			yyval.val.v = yyvsp[-2].val.v | yyvsp[0].val.v;
			yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-2].val.k | yyvsp[0].val.k;
		}
#line 3670 "parser.c"
    break;

  case 126: /* expr: expr OR expr  */
#line 1499 "parser.y"
                {
			strcat(symexp,"|;");
			yyval.val.s = yyvsp[-2].val.s | yyvsp[0].val.s;
			yyval.val.v = yyvsp[-2].val.v | yyvsp[0].val.v;
			yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-2].val.k | yyvsp[0].val.k;
		}
#line 3682 "parser.c"
    break;

  case 127: /* expr: expr '&' expr  */
#line 1507 "parser.y"
                {
			strcat(symexp,"&;");
			yyval.val.s = yyvsp[-2].val.s | yyvsp[0].val.s;
			yyval.val.v = yyvsp[-2].val.v & yyvsp[0].val.v;
			yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-2].val.k | yyvsp[0].val.k;
		}
#line 3694 "parser.c"
    break;

  case 128: /* expr: expr AND expr  */
#line 1515 "parser.y"
                {
			strcat(symexp,"&;");
			yyval.val.s = yyvsp[-2].val.s | yyvsp[0].val.s;
			yyval.val.v = yyvsp[-2].val.v & yyvsp[0].val.v;
			yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-2].val.k | yyvsp[0].val.k;
		}
#line 3706 "parser.c"
    break;

  case 129: /* expr: expr '^' expr  */
#line 1523 "parser.y"
                {
			strcat(symexp,"^;");
			yyval.val.s = yyvsp[-2].val.s | yyvsp[0].val.s;
			yyval.val.v = yyvsp[-2].val.v ^ yyvsp[0].val.v;
			yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-2].val.k | yyvsp[0].val.k;
		}
#line 3718 "parser.c"
    break;

  case 130: /* expr: expr XOR expr  */
#line 1531 "parser.y"
                {
			strcat(symexp,"^;");
			yyval.val.s = yyvsp[-2].val.s | yyvsp[0].val.s;
			yyval.val.v = yyvsp[-2].val.v ^ yyvsp[0].val.v;
			yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-2].val.k | yyvsp[0].val.k;
		}
#line 3730 "parser.c"
    break;

  case 131: /* expr: expr '*' expr  */
#line 1539 "parser.y"
                {
			strcat(symexp,"*;");
			yyval.val.s = yyvsp[-2].val.s | yyvsp[0].val.s;
			yyval.val.v = yyvsp[-2].val.v * yyvsp[0].val.v;
			yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-2].val.k | yyvsp[0].val.k;
		}
#line 3742 "parser.c"
    break;

  case 132: /* expr: expr '/' expr  */
#line 1547 "parser.y"
                {
			strcat(symexp,"/;");
			yyval.val.s = yyvsp[-2].val.s | yyvsp[0].val.s;
			yyval.val.k = yyvsp[-2].val.k | yyvsp[0].val.k;
			if((yyvsp[0].val.v!=0)&&(yyval.val.s==0))
			{
				yyval.val.v = yyvsp[-2].val.v / yyvsp[0].val.v;
				yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			}
			else if(yyval.val.s==1)
			{
				yyval.val.v = 1; // Relocatable symbolic expression: doesn't matter what I return!
				yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			}
			else
			{
				error("Divide by zero");
			}
		}
#line 3766 "parser.c"
    break;

  case 133: /* expr: expr '%' expr  */
#line 1567 "parser.y"
                {
			strcat(symexp,"%;");
			yyval.val.s = yyvsp[-2].val.s | yyvsp[0].val.s;
			yyval.val.k = yyvsp[-2].val.k | yyvsp[0].val.k;
			if((yyvsp[0].val.v!=0)&&(yyval.val.s==0))
			{
				yyval.val.v = yyvsp[-2].val.v % yyvsp[0].val.v;
				yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			}
			else if(yyval.val.s==1)
			{
				yyval.val.v = 1; // Relocatable symbolic expression: doesn't matter what I return!
				yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			}
			else
			{
				error("Divide by zero");
			}
		}
#line 3790 "parser.c"
    break;

  case 134: /* expr: expr '-' expr  */
#line 1587 "parser.y"
                {
			strcat(symexp,"-;");
			yyval.val.s = yyvsp[-2].val.s | yyvsp[0].val.s;
			yyval.val.v = yyvsp[-2].val.v - yyvsp[0].val.v;
			yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-2].val.k | yyvsp[0].val.k;
		}
#line 3802 "parser.c"
    break;

  case 135: /* expr: expr '+' expr  */
#line 1595 "parser.y"
                {
			strcat(symexp,"+;");
			yyval.val.s = yyvsp[-2].val.s | yyvsp[0].val.s;
			yyval.val.v = yyvsp[-2].val.v + yyvsp[0].val.v;
			yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-2].val.k | yyvsp[0].val.k;
		}
#line 3814 "parser.c"
    break;

  case 136: /* expr: expr '>' '>' expr  */
#line 1603 "parser.y"
                {
			strcat(symexp,">>;");
			yyval.val.s = yyvsp[-3].val.s | yyvsp[0].val.s;
			yyval.val.v = yyvsp[-3].val.v >> yyvsp[0].val.v;
			yyval.val.d = yyvsp[-3].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-3].val.k | yyvsp[0].val.k;
		}
#line 3826 "parser.c"
    break;

  case 137: /* expr: expr SHR expr  */
#line 1611 "parser.y"
                {
			strcat(symexp,">>;");
			yyval.val.s = yyvsp[-2].val.s | yyvsp[0].val.s;
			yyval.val.v = yyvsp[-2].val.v >> yyvsp[0].val.v;
			yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-2].val.k | yyvsp[0].val.k;
		}
#line 3838 "parser.c"
    break;

  case 138: /* expr: expr '<' '<' expr  */
#line 1619 "parser.y"
                {
			strcat(symexp,"<<;");
			yyval.val.s = yyvsp[-3].val.s | yyvsp[0].val.s;
			yyval.val.v = yyvsp[-3].val.v << yyvsp[0].val.v;
			yyval.val.d = yyvsp[-3].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-3].val.k | yyvsp[0].val.k;
		}
#line 3850 "parser.c"
    break;

  case 139: /* expr: expr SHL expr  */
#line 1627 "parser.y"
                {
			strcat(symexp,"<<;");
			yyval.val.s = yyvsp[-2].val.s | yyvsp[0].val.s;
			yyval.val.v = yyvsp[-2].val.v << yyvsp[0].val.v;
			yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-2].val.k | yyvsp[0].val.k;
		}
#line 3862 "parser.c"
    break;

  case 140: /* expr: expr '=' expr  */
#line 1635 "parser.y"
                {
			strcat(symexp,"=;");
			yyval.val.s = yyvsp[-2].val.s | yyvsp[0].val.s;
			yyval.val.v = (yyvsp[-2].val.v == yyvsp[0].val.v)?1:0;
			yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-2].val.k | yyvsp[0].val.k;
		}
#line 3874 "parser.c"
    break;

  case 141: /* expr: expr C_EQ expr  */
#line 1643 "parser.y"
                {
			strcat(symexp,"=;");
			yyval.val.s = yyvsp[-2].val.s | yyvsp[0].val.s;
			yyval.val.v = (yyvsp[-2].val.v == yyvsp[0].val.v)?1:0;
			yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-2].val.k | yyvsp[0].val.k;
		}
#line 3886 "parser.c"
    break;

  case 142: /* expr: expr '=' '=' expr  */
#line 1651 "parser.y"
                {
			strcat(symexp,"=;");
			yyval.val.s = yyvsp[-3].val.s | yyvsp[0].val.s;
			yyval.val.v = (yyvsp[-3].val.v == yyvsp[0].val.v)?1:0;
			yyval.val.d = yyvsp[-3].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-3].val.k | yyvsp[0].val.k;
		}
#line 3898 "parser.c"
    break;

  case 143: /* expr: expr '!' '=' expr  */
#line 1659 "parser.y"
                {
			strcat(symexp,"!=;");
			yyval.val.s = yyvsp[-3].val.s | yyvsp[0].val.s;
			yyval.val.v = (yyvsp[-3].val.v == yyvsp[0].val.v)?0:1;
			yyval.val.d = yyvsp[-3].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-3].val.k | yyvsp[0].val.k;
		}
#line 3910 "parser.c"
    break;

  case 144: /* expr: expr '<' '>' expr  */
#line 1667 "parser.y"
                {
			strcat(symexp,"!=;");
			yyval.val.s = yyvsp[-3].val.s | yyvsp[0].val.s;
			yyval.val.v = (yyvsp[-3].val.v == yyvsp[0].val.v)?0:1;
			yyval.val.d = yyvsp[-3].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-3].val.k | yyvsp[0].val.k;
		}
#line 3922 "parser.c"
    break;

  case 145: /* expr: expr C_NE expr  */
#line 1675 "parser.y"
                {
			strcat(symexp,"!=;");
			yyval.val.s = yyvsp[-2].val.s | yyvsp[0].val.s;
			yyval.val.v = (yyvsp[-2].val.v == yyvsp[0].val.v)?0:1;
			yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-2].val.k | yyvsp[0].val.k;
		}
#line 3934 "parser.c"
    break;

  case 146: /* expr: expr '<' expr  */
#line 1683 "parser.y"
                {
			strcat(symexp,"<;");
			yyval.val.s = yyvsp[-2].val.s | yyvsp[0].val.s;
			yyval.val.v = (yyvsp[-2].val.v < yyvsp[0].val.v)?1:0;
			yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-2].val.k | yyvsp[0].val.k;
		}
#line 3946 "parser.c"
    break;

  case 147: /* expr: expr C_LT expr  */
#line 1691 "parser.y"
                {
			strcat(symexp,"<;");
			yyval.val.s = yyvsp[-2].val.s | yyvsp[0].val.s;
			yyval.val.v = (yyvsp[-2].val.v < yyvsp[0].val.v)?1:0;
			yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-2].val.k | yyvsp[0].val.k;
		}
#line 3958 "parser.c"
    break;

  case 148: /* expr: expr '<' '=' expr  */
#line 1699 "parser.y"
                {
			strcat(symexp,"<=;");
			yyval.val.s = yyvsp[-3].val.s | yyvsp[0].val.s;
			yyval.val.v = (yyvsp[-3].val.v <= yyvsp[0].val.v)?1:0;
			yyval.val.d = yyvsp[-3].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-3].val.k | yyvsp[0].val.k;
		}
#line 3970 "parser.c"
    break;

  case 149: /* expr: expr C_LE expr  */
#line 1707 "parser.y"
                {
			strcat(symexp,"<=;");
			yyval.val.s = yyvsp[-2].val.s | yyvsp[0].val.s;
			yyval.val.v = (yyvsp[-2].val.v <= yyvsp[0].val.v)?1:0;
			yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-2].val.k | yyvsp[0].val.k;
		}
#line 3982 "parser.c"
    break;

  case 150: /* expr: expr '>' expr  */
#line 1715 "parser.y"
                {
			strcat(symexp,">;");
			yyval.val.s = yyvsp[-2].val.s | yyvsp[0].val.s;
			yyval.val.v = (yyvsp[-2].val.v > yyvsp[0].val.v)?1:0;
			yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-2].val.k | yyvsp[0].val.k;
		}
#line 3994 "parser.c"
    break;

  case 151: /* expr: expr C_GT expr  */
#line 1723 "parser.y"
                {
			strcat(symexp,">;");
			yyval.val.s = yyvsp[-2].val.s | yyvsp[0].val.s;
			yyval.val.v = (yyvsp[-2].val.v > yyvsp[0].val.v)?1:0;
			yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-2].val.k | yyvsp[0].val.k;
		}
#line 4006 "parser.c"
    break;

  case 152: /* expr: expr '>' '=' expr  */
#line 1731 "parser.y"
                {
			strcat(symexp,">=;");
			yyval.val.s = yyvsp[-3].val.s | yyvsp[0].val.s;
			yyval.val.v = (yyvsp[-3].val.v >= yyvsp[0].val.v)?1:0;
			yyval.val.d = yyvsp[-3].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-3].val.k | yyvsp[0].val.k;
		}
#line 4018 "parser.c"
    break;

  case 153: /* expr: expr C_GE expr  */
#line 1739 "parser.y"
                {
			strcat(symexp,">=;");
			yyval.val.s = yyvsp[-2].val.s | yyvsp[0].val.s;
			yyval.val.v = (yyvsp[-2].val.v >= yyvsp[0].val.v)?1:0;
			yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d;
			yyval.val.k = yyvsp[-2].val.k | yyvsp[0].val.k;
		}
#line 4030 "parser.c"
    break;

  case 154: /* expr: SYMBOL  */
#line 1747 "parser.y"
                {
			yyval.val.k = kmask[yyvsp[0].sym->type&0xf] | 0x01; // 0x01: means value comes from symbol.

			if( pass1 )
			{
				yyval.val.v = yyvsp[0].sym->value;
				yyval.val.d = (yyvsp[0].sym->type != UNDEF);
			}
			else
			{
				if( yyvsp[0].sym->type == UNDEF )
				{
					error("Undefined symbol %s", yyvsp[0].sym->name);
					yyval.val.v = 0;
				}
				yyval.val.d = 1;
			}
			
			if( yyvsp[0].sym->type != UNDEF )
			{
				if(yyvsp[0].sym->segment!=NULL) // Does this properly takes care of $1.sym->segment==NULL?  See below.
				{
					if (yyvsp[0].sym->segment->flags&RELOCATABLE) 
					{
						strcat(symexp,yyvsp[0].sym->name);
						strcat(symexp,";");
						yyval.val.v = yyvsp[0].val.v;
						if( (strlen(MapFile)>0) && pass2 )
						{
							yyval.val.v = yyvsp[0].sym->value;
							yyval.val.s = 0; // If loading symbols from mapfile, no symbolic expressions
						}
						else
						{
							yyval.val.s = 1; // Relocatable symbolic expression
						}
					}
					else
					{
						sprintf(tmpexp,"0x%04lX;",yyvsp[0].sym->value);
						strcat(symexp,tmpexp);
						yyval.val.v = yyvsp[0].sym->value;
						yyval.val.s = 0;
					}
				}
				else // For symbols without a parent segment (EQUs, on the fly externs, etc.)
				{
					if (yyvsp[0].sym->flags&EXTERN_SYM)
					{
						strcat(symexp,yyvsp[0].sym->name);
						strcat(symexp,";");
						yyval.val.v = 0;
						if( (strlen(MapFile)>0) && pass2 )
						{
							yyval.val.v = yyvsp[0].sym->value;
							yyval.val.s = 0; // If loading symbols from mapfile, no symbolic expressions
						}
						else
						{
							yyval.val.s = 1; // Relocatable symbolic expression
						}
					}
					else
					{
						sprintf(tmpexp,"0x%04lX;",yyvsp[0].sym->value);
						strcat(symexp,tmpexp);
						yyval.val.v = yyvsp[0].sym->value;
						yyval.val.s = 0;
					}
				}
			}

		}
#line 4108 "parser.c"
    break;

  case 155: /* expr: VALUE  */
#line 1821 "parser.y"
                {
			sprintf(tmpexp,"0x%04lX;",yyvsp[0].val.v);
			strcat(symexp,tmpexp);
			yyval.val.k = 0;
			yyval.val.s = 0;
			yyval.val.v = yyvsp[0].val.v; yyval.val.d=1;
		}
#line 4120 "parser.c"
    break;

  case 156: /* instr: NOP  */
#line 1835 "parser.y"
                { yyval.value = makeop(yyvsp[0].op,NULL,0); }
#line 4126 "parser.c"
    break;

  case 157: /* instr: ACALL addr11  */
#line 1837 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4132 "parser.c"
    break;

  case 158: /* instr: AJMP addr11  */
#line 1839 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4138 "parser.c"
    break;

  case 159: /* instr: ADD two_op1  */
#line 1841 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4144 "parser.c"
    break;

  case 160: /* instr: ADDC two_op1  */
#line 1843 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4150 "parser.c"
    break;

  case 161: /* instr: SUBB two_op1  */
#line 1845 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4156 "parser.c"
    break;

  case 162: /* instr: XRL two_op1  */
#line 1847 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4162 "parser.c"
    break;

  case 163: /* instr: XRL two_op2  */
#line 1849 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,4); }
#line 4168 "parser.c"
    break;

  case 164: /* instr: ANL two_op1  */
#line 1851 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4174 "parser.c"
    break;

  case 165: /* instr: ANL two_op2  */
#line 1853 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,4); }
#line 4180 "parser.c"
    break;

  case 166: /* instr: ANL two_op3  */
#line 1855 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,6); }
#line 4186 "parser.c"
    break;

  case 167: /* instr: ORL two_op1  */
#line 1857 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4192 "parser.c"
    break;

  case 168: /* instr: ORL two_op2  */
#line 1859 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,4); }
#line 4198 "parser.c"
    break;

  case 169: /* instr: ORL two_op3  */
#line 1861 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,6); }
#line 4204 "parser.c"
    break;

  case 170: /* instr: XCH two_op1  */
#line 1863 "parser.y"
                { if( get_md(yyvsp[0].mode) == 3 )
			error("Immediate mode is invalid");
		  yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4212 "parser.c"
    break;

  case 171: /* instr: INC single_op1  */
#line 1867 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4218 "parser.c"
    break;

  case 172: /* instr: INC DPTR  */
#line 1869 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,NULL,4); }
#line 4224 "parser.c"
    break;

  case 173: /* instr: DEC single_op1  */
#line 1871 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4230 "parser.c"
    break;

  case 174: /* instr: DA A  */
#line 1873 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,NULL,0); }
#line 4236 "parser.c"
    break;

  case 175: /* instr: DIV AB  */
#line 1875 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,NULL,0); }
#line 4242 "parser.c"
    break;

  case 176: /* instr: JMP '@' A '+' DPTR  */
#line 1877 "parser.y"
                { yyval.value = makeop(yyvsp[-4].op,NULL,0); }
#line 4248 "parser.c"
    break;

  case 177: /* instr: JMP '@' DPTR '+' A  */
#line 1879 "parser.y"
                { yyval.value = makeop(yyvsp[-4].op,NULL,0); }
#line 4254 "parser.c"
    break;

  case 178: /* instr: JMP addr16  */
#line 1881 "parser.y"
        {
		long offset;
		unsigned long address;
		static unsigned char ajmp[]= { 0x01 };
		static unsigned char ljmp[]= { 0x02 };
		static unsigned char sjmp[]= { 0x80 };
		static struct opcode opjmp[] = {
			{"ajmp",    AJMP,   ajmp  },
			{"ljmp",    LJMP,   ljmp  },
			{"sjmp",    SJMP,   sjmp  }
		};
		//if(ObjectFile) error("'JMP label' instruction is not allowed when compiling to an object file");
		if(ObjectFile==0)
		{
			if(pass1) warning("The 'jmp addr16' is deprecated.  Replaced with a 'ljmp addr16' instruction.");
			address=yyvsp[0].mode.byte2+(yyvsp[0].mode.byte1*0x100);
			offset = address - (current_seg->value+2);
			//if(pass2) printf("address=%04XH, current_seg->value+2=%04XH, offset is %d\n", address, current_seg->value+2, offset);
			//if( (offset <= 127) && (offset >= -128) && ($2.mode.str1[0]==0) && (address<=current_seg->value))
			//{  // SJMP
			//	$2.mode.mode=0;
			//	$2.mode.orval=0;
			//	$2.mode.size=1;
			//	$2.mode.byte1=offset;
			//	$$.value = makeop(&opjmp[2],&$2.mode,0);
			//}
			//else if( ( (address&0xF800) == ((current_seg->value+2)&0xF800) ) && ($2.mode.str1[0]==0) && (address<=current_seg->value) ) // Same page?
			//{  // AJMP
			//	$2.mode.mode=0;
			//	$2.mode.orval= (unsigned char) ((address&0x0700)>>3) ;
			//	$2.mode.size=1;
			//	$2.mode.byte1=address&0x00FF;
			//	$$.value = makeop(&opjmp[0],&$2.mode,0);
			//}
			//else
			//{  // LJMP
				yyval.value = makeop(&opjmp[1],&yyvsp[0].mode,0);
			//}
		}
		else // ObjectFile==1
		{  // LJMP
			yyval.value = makeop(&opjmp[1],&yyvsp[0].mode,0);
		}
	}
#line 4303 "parser.c"
    break;

  case 179: /* instr: CALL addr16  */
#line 1926 "parser.y"
        {
		long offset;
		unsigned long address;
		static unsigned char acall[]= { 0x11 };
		static unsigned char lcall[]= { 0x12 };
		static struct opcode opcall[] = {
			{"acall",    ACALL,   acall  },
			{"lcall",    LCALL,   lcall  }
		};
		//if(ObjectFile) error("'CALL label' instruction is not allowed when compiling to an object file");
		if(ObjectFile==0)
		{
			address=yyvsp[0].mode.byte2+(yyvsp[0].mode.byte1*0x100);
			offset = address - (current_seg->value+2);
			//if(pass2) printf("address=%04XH, current_seg->value+2=%04XH, offset is %d\n", address, current_seg->value+2, offset);
			if( ( (address&0xF800) == ((current_seg->value+2)&0xF800) ) && (yyvsp[0].mode.str1[0]==0) && (address<=current_seg->value) ) // Same page?
			{  // ACALL
				yyvsp[0].mode.mode=0;
				yyvsp[0].mode.orval= (unsigned char) ((address&0x0700)>>3) ;
				yyvsp[0].mode.size=1;
				yyvsp[0].mode.byte1=address&0x00FF;
				yyval.value = makeop(&opcall[0],&yyvsp[0].mode,0);
			}
			else
			{  // LCALL
				yyval.value = makeop(&opcall[1],&yyvsp[0].mode,0);
			}
		}
		else // ObjectFile==1
		{  // LCALL
			yyval.value = makeop(&opcall[1],&yyvsp[0].mode,0);
		}
	}
#line 4341 "parser.c"
    break;

  case 180: /* instr: MUL AB  */
#line 1960 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,NULL,0); }
#line 4347 "parser.c"
    break;

  case 181: /* instr: RET  */
#line 1962 "parser.y"
                { yyval.value = makeop(yyvsp[0].op,NULL,0); }
#line 4353 "parser.c"
    break;

  case 182: /* instr: RETI  */
#line 1964 "parser.y"
                { yyval.value = makeop(yyvsp[0].op,NULL,0); }
#line 4359 "parser.c"
    break;

  case 183: /* instr: RL A  */
#line 1966 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,NULL,0); }
#line 4365 "parser.c"
    break;

  case 184: /* instr: RLC A  */
#line 1968 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,NULL,0); }
#line 4371 "parser.c"
    break;

  case 185: /* instr: RR A  */
#line 1970 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,NULL,0); }
#line 4377 "parser.c"
    break;

  case 186: /* instr: RRC A  */
#line 1972 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,NULL,0); }
#line 4383 "parser.c"
    break;

  case 187: /* instr: SWAP A  */
#line 1974 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,NULL,0); }
#line 4389 "parser.c"
    break;

  case 188: /* instr: XCHD two_op1  */
#line 1976 "parser.y"
                {
			if( get_md(yyvsp[0].mode) != 2 )
				error("Invalid addressing mode");
			yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,-2);
		}
#line 4399 "parser.c"
    break;

  case 189: /* instr: CLR single_op2  */
#line 1982 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4405 "parser.c"
    break;

  case 190: /* instr: CPL single_op2  */
#line 1984 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4411 "parser.c"
    break;

  case 191: /* instr: SETB single_op2  */
#line 1986 "parser.y"
                {
			if( get_md(yyvsp[0].mode) == 0 ) error("Invalid addressing mode");
			yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,-1);
		}
#line 4420 "parser.c"
    break;

  case 192: /* instr: PUSH data8  */
#line 1991 "parser.y"
                {
			struct mode tmp;
			set_md(tmp,0);
			set_ov(tmp,0);
			set_sz(tmp,1);
			set_b1(tmp,yyvsp[0].value);
			set_str1(&tmp, &yyvsp[0]);
			yyval.value = makeop(yyvsp[-1].op,&tmp,0);
		}
#line 4434 "parser.c"
    break;

  case 193: /* instr: POP data8  */
#line 2001 "parser.y"
                {
		   struct mode tmp;
			set_md(tmp,0);
			set_ov(tmp,0);
			set_sz(tmp,1);
			set_b1(tmp,yyvsp[0].value);
			set_str1(&tmp, &yyvsp[0]);
			yyval.value = makeop(yyvsp[-1].op,&tmp,0);
		}
#line 4448 "parser.c"
    break;

  case 194: /* instr: LJMP addr16  */
#line 2011 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4454 "parser.c"
    break;

  case 195: /* instr: LCALL addr16  */
#line 2013 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4460 "parser.c"
    break;

  case 196: /* instr: JC relative  */
#line 2015 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4466 "parser.c"
    break;

  case 197: /* instr: JNC relative  */
#line 2017 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4472 "parser.c"
    break;

  case 198: /* instr: JNZ relative  */
#line 2019 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4478 "parser.c"
    break;

  case 199: /* instr: JZ relative  */
#line 2021 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4484 "parser.c"
    break;

  case 200: /* instr: SJMP relative  */
#line 2023 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4490 "parser.c"
    break;

  case 201: /* instr: CJNE three_op1  */
#line 2025 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4496 "parser.c"
    break;

  case 202: /* instr: JB two_op4  */
#line 2027 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4502 "parser.c"
    break;

  case 203: /* instr: JNB two_op4  */
#line 2029 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4508 "parser.c"
    break;

  case 204: /* instr: JBC two_op4  */
#line 2031 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4514 "parser.c"
    break;

  case 205: /* instr: DJNZ two_op5  */
#line 2033 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4520 "parser.c"
    break;

  case 206: /* instr: MOV two_op1  */
#line 2035 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
#line 4526 "parser.c"
    break;

  case 207: /* instr: MOV two_op2  */
#line 2037 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,4); }
#line 4532 "parser.c"
    break;

  case 208: /* instr: MOV two_op6  */
#line 2039 "parser.y"
                { yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,6); }
#line 4538 "parser.c"
    break;

  case 209: /* instr: MOVC A ',' '@' A '+' DPTR  */
#line 2041 "parser.y"
                { yyval.value = makeop(yyvsp[-6].op,NULL,0); }
#line 4544 "parser.c"
    break;

  case 210: /* instr: MOVC A ',' '@' DPTR '+' A  */
#line 2043 "parser.y"
                { yyval.value = makeop(yyvsp[-6].op,NULL,0); }
#line 4550 "parser.c"
    break;

  case 211: /* instr: MOVC A ',' '@' A '+' PC  */
#line 2045 "parser.y"
                { yyval.value = makeop(yyvsp[-6].op,NULL,1); }
#line 4556 "parser.c"
    break;

  case 212: /* instr: MOVC A ',' '@' PC '+' A  */
#line 2047 "parser.y"
                { yyval.value = makeop(yyvsp[-6].op,NULL,1); }
#line 4562 "parser.c"
    break;

  case 213: /* instr: MOVX A ',' '@' regi  */
#line 2049 "parser.y"
                { yyval.value = makeop(yyvsp[-4].op,NULL,yyvsp[0].value); }
#line 4568 "parser.c"
    break;

  case 214: /* instr: MOVX A ',' '@' DPTR  */
#line 2051 "parser.y"
                { yyval.value = makeop(yyvsp[-4].op,NULL,2); }
#line 4574 "parser.c"
    break;

  case 215: /* instr: MOVX '@' regi ',' A  */
#line 2053 "parser.y"
                { yyval.value = makeop(yyvsp[-4].op,NULL,yyvsp[-2].value+3); }
#line 4580 "parser.c"
    break;

  case 216: /* instr: MOVX '@' DPTR ',' A  */
#line 2055 "parser.y"
                { yyval.value = makeop(yyvsp[-4].op,NULL,5); }
#line 4586 "parser.c"
    break;

  case 217: /* two_op1: A ',' reg  */
#line 2063 "parser.y"
                {
			set_md(yyval.mode,0);
			set_ov(yyval.mode, yyvsp[0].value);
			set_sz(yyval.mode, 0);
		}
#line 4596 "parser.c"
    break;

  case 218: /* two_op1: A ',' data8  */
#line 2069 "parser.y"
                {
			if((yyvsp[0].val.k==0) && pass1 && hash_warning_enable)
			{
				warning("maybe '#' is missing with constant expression.");
			}
			set_md(yyval.mode,1);
			set_ov(yyval.mode,0);
			set_sz(yyval.mode,1);
			set_b1(yyval.mode,yyvsp[0].value);
			set_str1(&yyval.mode, &yyvsp[0]);
		}
#line 4612 "parser.c"
    break;

  case 219: /* two_op1: A ',' '@' regi  */
#line 2081 "parser.y"
                {
			set_md(yyval.mode,2);
			set_ov(yyval.mode,yyvsp[0].value);
			set_sz(yyval.mode,0);
		}
#line 4622 "parser.c"
    break;

  case 220: /* two_op1: A ',' '#' data8  */
#line 2087 "parser.y"
                {
			set_md(yyval.mode,3);
			set_ov(yyval.mode,0);
			set_sz(yyval.mode,1);
			set_b1(yyval.mode,yyvsp[0].value);
			set_str1(&yyval.mode, &yyvsp[0]);
		}
#line 4634 "parser.c"
    break;

  case 221: /* two_op2: data8 ',' A  */
#line 2098 "parser.y"
                {
			set_md(yyval.mode,0);
			set_ov(yyval.mode,0);
			set_sz(yyval.mode,1);
			set_b1(yyval.mode,yyvsp[-2].value);
			set_str1(&yyval.mode, &yyvsp[-2]);
		}
#line 4646 "parser.c"
    break;

  case 222: /* two_op2: data8 ',' '#' data8  */
#line 2106 "parser.y"
                {
			set_md(yyval.mode,1);
			set_ov(yyval.mode,0);
			set_sz(yyval.mode,2);
			set_b1(yyval.mode,yyvsp[-3].value);
			set_str1(&yyval.mode,&yyvsp[-3]);
			set_b2(yyval.mode,yyvsp[0].value);
			set_str2(&yyval.mode,&yyvsp[0]);
		}
#line 4660 "parser.c"
    break;

  case 223: /* two_op3: C ',' bit  */
#line 2119 "parser.y"
                {
			set_md(yyval.mode,0);
			set_ov(yyval.mode,0);
			set_sz(yyval.mode,1);
			set_b1(yyval.mode,yyvsp[0].value);
			set_str1(&yyval.mode,&yyvsp[0]);
		}
#line 4672 "parser.c"
    break;

  case 224: /* two_op3: C ',' '/' bit  */
#line 2127 "parser.y"
                {
			set_md(yyval.mode,1);
			set_ov(yyval.mode,0);
			set_sz(yyval.mode,1);
			set_b1(yyval.mode,yyvsp[0].value);
			set_str1(&yyval.mode,&yyvsp[0]);
		}
#line 4684 "parser.c"
    break;

  case 225: /* two_op3: C ',' '!' bit  */
#line 2135 "parser.y"
                {
			set_md(yyval.mode,1);
			set_ov(yyval.mode,0);
			set_sz(yyval.mode,1);
			set_b1(yyval.mode,yyvsp[0].value);
			set_str1(&yyval.mode,&yyvsp[0]);
		}
#line 4696 "parser.c"
    break;

  case 226: /* two_op4: bit ',' rel  */
#line 2146 "parser.y"
                {
			set_md(yyval.mode,0);
			set_ov(yyval.mode,0);
			set_sz(yyval.mode,2);
			set_b1(yyval.mode,yyvsp[-2].value);
			set_str1(&yyval.mode,&yyvsp[-2]);
			set_b2(yyval.mode,yyvsp[0].value);
			set_str2(&yyval.mode,&yyvsp[0]);
		}
#line 4710 "parser.c"
    break;

  case 227: /* two_op5: reg ',' rel2  */
#line 2159 "parser.y"
                {
			set_md(yyval.mode,0);
			set_ov(yyval.mode,yyvsp[-2].value);
			set_sz(yyval.mode,1);
			set_b1(yyval.mode,yyvsp[0].value);
			set_str1(&yyval.mode,&yyvsp[0]);
		}
#line 4722 "parser.c"
    break;

  case 228: /* two_op5: data8 ',' rel  */
#line 2167 "parser.y"
                {
			set_md(yyval.mode,1);
			set_ov(yyval.mode,0);
			set_sz(yyval.mode,2);
			set_b1(yyval.mode,yyvsp[-2].value);
			set_str1(&yyval.mode,&yyvsp[-2]);
			set_b2(yyval.mode,yyvsp[0].value);
			set_str2(&yyval.mode,&yyvsp[0]);
		}
#line 4736 "parser.c"
    break;

  case 229: /* two_op6: reg ',' A  */
#line 2180 "parser.y"
                {
			set_md(yyval.mode,0);
			set_ov(yyval.mode,yyvsp[-2].value);
			set_sz(yyval.mode,0);
		}
#line 4746 "parser.c"
    break;

  case 230: /* two_op6: reg ',' data8  */
#line 2186 "parser.y"
                {
			if((yyvsp[0].val.k==0) && pass1 && hash_warning_enable)
			{
				warning("maybe '#' is missing with constant expression.");
			}
			set_md(yyval.mode,1);
			set_ov(yyval.mode,yyvsp[-2].value);
			set_sz(yyval.mode,1);
			set_b1(yyval.mode,yyvsp[0].value);
			set_str1(&yyval.mode,&yyvsp[0]);
		}
#line 4762 "parser.c"
    break;

  case 231: /* two_op6: reg ',' '#' data8  */
#line 2198 "parser.y"
                {
			set_md(yyval.mode,2);
			set_ov(yyval.mode,yyvsp[-3].value);
			set_sz(yyval.mode,1);
			set_b1(yyval.mode,yyvsp[0].value);
			set_str1(&yyval.mode,&yyvsp[0]);
		}
#line 4774 "parser.c"
    break;

  case 232: /* two_op6: data8 ',' reg  */
#line 2206 "parser.y"
                {
			set_md(yyval.mode,3);
			set_ov(yyval.mode,yyvsp[0].value);
			set_sz(yyval.mode,1);
			set_b1(yyval.mode,yyvsp[-2].value);
			set_str1(&yyval.mode,&yyvsp[-2]);
		}
#line 4786 "parser.c"
    break;

  case 233: /* two_op6: data8 ',' data8  */
#line 2214 "parser.y"
                {
			if((yyvsp[0].val.k==0) && pass1 && hash_warning_enable)
			{
				warning("maybe '#' is missing with constant expression.");
			}
			set_md(yyval.mode,4);
			set_ov(yyval.mode,0);
			set_sz(yyval.mode,2);
			set_b1(yyval.mode,yyvsp[0].value);
			set_str1(&yyval.mode,&yyvsp[0]);
			set_b2(yyval.mode,yyvsp[-2].value);
			set_str2(&yyval.mode,&yyvsp[-2]);
		}
#line 4804 "parser.c"
    break;

  case 234: /* two_op6: data8 ',' '@' regi  */
#line 2228 "parser.y"
                {
			set_md(yyval.mode,5);
			set_ov(yyval.mode,yyvsp[0].value);
			set_sz(yyval.mode,1);
			set_b1(yyval.mode,yyvsp[-3].value);
			set_str1(&yyval.mode,&yyvsp[-3]);
		}
#line 4816 "parser.c"
    break;

  case 235: /* two_op6: '@' regi ',' A  */
#line 2236 "parser.y"
                {
			set_md(yyval.mode,6);
			set_ov(yyval.mode,yyvsp[-2].value);
			set_sz(yyval.mode,0);
		}
#line 4826 "parser.c"
    break;

  case 236: /* two_op6: '@' regi ',' data8  */
#line 2242 "parser.y"
                {
			if((yyvsp[0].val.k==0) && pass1 && hash_warning_enable)
			{
				warning("maybe '#' is missing with constant expression.");
			}
			set_md(yyval.mode,7);
			set_ov(yyval.mode,yyvsp[-2].value);
			set_sz(yyval.mode,1);
			set_b1(yyval.mode,yyvsp[0].value);
			set_str1(&yyval.mode,&yyvsp[0]);
		}
#line 4842 "parser.c"
    break;

  case 237: /* two_op6: '@' regi ',' '#' data8  */
#line 2254 "parser.y"
                {
			set_md(yyval.mode,8);
			set_ov(yyval.mode,yyvsp[-3].value);
			set_sz(yyval.mode,1);
			set_b1(yyval.mode,yyvsp[0].value);
			set_str1(&yyval.mode,&yyvsp[0]);
		}
#line 4854 "parser.c"
    break;

  case 238: /* two_op6: DPTR ',' '#' data16  */
#line 2262 "parser.y"
                {
			set_md(yyval.mode,9);
			set_ov(yyval.mode,0);
			set_sz(yyval.mode,2);
			set_b1(yyval.mode, (yyvsp[0].value & 0xff00) >> 8 );
			set_str1(&yyval.mode, &yyvsp[0]);
			set_b2(yyval.mode, (yyvsp[0].value & 0x00ff) );
			// There is a problem with the data16 production below.  For now, fix it here...
			if(yyvsp[0].val.s==1) // if 'data16' is a symbolic expression, the second string is blank.
			{
				yyval.mode.str2[0]=' ';
				yyval.mode.str2[1]=0;
			}
			else // if 'data16' is numeric, we need to print the lower 8-bits of the value
			{
				yyval.mode.str2[0]=0;
			}
		}
#line 4877 "parser.c"
    break;

  case 239: /* two_op6: C ',' bit  */
#line 2281 "parser.y"
                {
			set_md(yyval.mode,10);
			set_ov(yyval.mode,0);
			set_sz(yyval.mode,1);
			set_b1(yyval.mode,yyvsp[0].value);
			set_str1(&yyval.mode,&yyvsp[0]);
		}
#line 4889 "parser.c"
    break;

  case 240: /* two_op6: data8 ',' C  */
#line 2304 "parser.y"
                {
			set_md(yyval.mode,11);
			set_ov(yyval.mode,0);
			set_sz(yyval.mode,1);
			set_b1(yyval.mode,yyvsp[-2].value);
			set_str1(&yyval.mode,&yyvsp[-2]);
		}
#line 4901 "parser.c"
    break;

  case 241: /* two_op6: data8 BITPOS ',' C  */
#line 2312 "parser.y"
                {
			if( pass2 )
			{
				if(yyvsp[-3].val.s==1)
				{
					sprintf(yyval.mode.str1, "bit(%s%04lX;.;)", yyvsp[-3].val.rel, yyvsp[-2].value);
					yyval.mode.str2[0]=' ';
					yyval.mode.str2[1]=0;	
				}
				else
				{
					if( !isbit8(yyvsp[-3].value) )
						if(ObjectFile==0) error("Bit address exceeds 8-bits");
					if( isbmram(yyvsp[-3].value) )
						set_b1(yyval.mode, (yyvsp[-3].value-0x20)*8+ yyvsp[-2].value );
					else if( isbmsfr(yyvsp[-3].value) )
						set_b1(yyval.mode, yyvsp[-3].value + yyvsp[-2].value );
					else
						if(ObjectFile==0) error("Invalid bit addressable RAM location");
				}
			}
			set_md(yyval.mode,11);
			set_ov(yyval.mode,0);
			set_sz(yyval.mode,1);
		}
#line 4931 "parser.c"
    break;

  case 242: /* single_op1: A  */
#line 2341 "parser.y"
                {
			set_md(yyval.mode,0);
			set_ov(yyval.mode,0);
			set_sz(yyval.mode,0);
		}
#line 4941 "parser.c"
    break;

  case 243: /* single_op1: reg  */
#line 2347 "parser.y"
                {
			set_md(yyval.mode,1);
			set_ov(yyval.mode,yyvsp[0].value);
			set_sz(yyval.mode,0);
		}
#line 4951 "parser.c"
    break;

  case 244: /* single_op1: data8  */
#line 2353 "parser.y"
                {
			set_md(yyval.mode,2);
			set_ov(yyval.mode,0);
			set_sz(yyval.mode,1);
			set_b1(yyval.mode,yyvsp[0].value);
			set_str1(&yyval.mode,&yyvsp[0]);
		}
#line 4963 "parser.c"
    break;

  case 245: /* single_op1: '@' regi  */
#line 2361 "parser.y"
                {
			set_md(yyval.mode,3);
			set_ov(yyval.mode,yyvsp[0].value);
			set_sz(yyval.mode,0);
		}
#line 4973 "parser.c"
    break;

  case 246: /* single_op2: A  */
#line 2370 "parser.y"
                {
			set_md(yyval.mode,0);
			set_ov(yyval.mode,0);
			set_sz(yyval.mode,0);
		}
#line 4983 "parser.c"
    break;

  case 247: /* single_op2: C  */
#line 2376 "parser.y"
                {
			set_md(yyval.mode,1);
			set_ov(yyval.mode,0);
			set_sz(yyval.mode,0);
		}
#line 4993 "parser.c"
    break;

  case 248: /* single_op2: bit  */
#line 2382 "parser.y"
                {
			if((pass2)&&(yyvsp[0].val.s==1))
			{
				sprintf(yyval.mode.str1, "%s", symexp);
				yyval.mode.str2[0]=' ';
				yyval.mode.str2[1]=0;
				yyval.val.s=1;
			}
			set_md(yyval.mode,2);
			set_ov(yyval.mode,0);
			set_sz(yyval.mode,1);
			set_b1(yyval.mode,yyvsp[0].value);
			set_str1(&yyval.mode,&yyvsp[0]);
		}
#line 5012 "parser.c"
    break;

  case 249: /* three_op1: A ',' data8 ',' rel  */
#line 2400 "parser.y"
                {
			if((yyvsp[-2].val.k==0) && pass1 && hash_warning_enable)
			{
				warning("maybe '#' is missing with constant expression.");
			}
			set_md(yyval.mode,0);
			set_ov(yyval.mode,0);
			set_sz(yyval.mode,2);
			set_b1(yyval.mode,yyvsp[-2].value);
			set_str1(&yyval.mode,&yyvsp[-2]);
			set_b2(yyval.mode,yyvsp[0].value);
			set_str2(&yyval.mode,&yyvsp[0]);
		}
#line 5030 "parser.c"
    break;

  case 250: /* three_op1: A ',' '#' data8 ',' rel  */
#line 2414 "parser.y"
                {
			set_md(yyval.mode,1);
			set_ov(yyval.mode,0);
			set_sz(yyval.mode,2);
			set_b1(yyval.mode,yyvsp[-2].value);
			set_str1(&yyval.mode,&yyvsp[-2]);
			set_b2(yyval.mode,yyvsp[0].value);
			set_str2(&yyval.mode,&yyvsp[0]);
		}
#line 5044 "parser.c"
    break;

  case 251: /* three_op1: reg ',' '#' data8 ',' rel  */
#line 2424 "parser.y"
                {
			set_md(yyval.mode,2);
			set_ov(yyval.mode,yyvsp[-5].value);
			set_sz(yyval.mode,2);
			set_b1(yyval.mode,yyvsp[-2].value);
			set_str1(&yyval.mode,&yyvsp[-2]);
			set_b2(yyval.mode,yyvsp[0].value);
			set_str2(&yyval.mode,&yyvsp[0]);
		}
#line 5058 "parser.c"
    break;

  case 252: /* three_op1: '@' regi ',' '#' data8 ',' rel  */
#line 2434 "parser.y"
                {
			set_md(yyval.mode,3);
			set_ov(yyval.mode,yyvsp[-5].value);
			set_sz(yyval.mode,2);
			set_b1(yyval.mode,yyvsp[-2].value);
			set_str1(&yyval.mode,&yyvsp[-2]);
			set_b2(yyval.mode,yyvsp[0].value);
			set_str2(&yyval.mode,&yyvsp[0]);
		}
#line 5072 "parser.c"
    break;

  case 253: /* rel: expr  */
#line 2447 "parser.y"
                {
			long offset;

			if((pass2)&&(yyvsp[0].val.s==1))
			{
				sprintf(yyval.val.rel, "rel3(%s)", symexp);
				yyval.val.s=1;
			}
			else if( pass2 )
			{
				offset = yyvsp[0].val.v - (current_seg->value+3);
				if( offset > 127 || offset < -128 )
				   error("Relative offset exceeds -128 / +127");
				yyval.value = offset;
				yyval.val.s=0;
			}
			symexp[0]=0;
		}
#line 5095 "parser.c"
    break;

  case 254: /* rel2: expr  */
#line 2470 "parser.y"
                {
			long offset;
			if((pass2)&&(yyvsp[0].val.s==1))
			{
				sprintf(yyval.val.rel, "rel2(%s)", symexp);
				yyval.val.s=1;
			}
			else if( pass2 )
			{
				offset = yyvsp[0].val.v - (current_seg->value+2); /* different! */
				if( offset > 127 || offset < -128 )
				   error("Relative offset exceeds -128 / +127");
				yyval.value = offset;
				yyval.val.s=0;
			}
			symexp[0]=0;
		}
#line 5117 "parser.c"
    break;

  case 255: /* bit: expr BITPOS  */
#line 2491 "parser.y"
                {
			static unsigned char sn[0x100]="";
			if( pass2 )
			{
				if(yyvsp[-1].val.s==1)
				{
					sprintf(yyval.val.rel, "bit(%s%04lX;.;)", symexp, yyvsp[0].value);
					yyval.val.s=1;
				}
				else
				{
					if( !isbit8(yyvsp[-1].value) )
						if(ObjectFile==0) error("Bit address exceeds 8-bits");
					if( isbmram(yyvsp[-1].value) )
						yyval.value = (yyvsp[-1].value-0x20)*8+yyvsp[0].value;
					else if( isbmsfr(yyvsp[-1].value) )
						yyval.value = yyvsp[-1].value + yyvsp[0].value;
					else
						if(ObjectFile==0) error("Invalid bit addressable RAM location");
					yyval.val.s=0;
				}
			}
			symexp[0]=0;
		}
#line 5146 "parser.c"
    break;

  case 256: /* bit: expr  */
#line 2516 "parser.y"
                {
			//if((pass2)&&($1.val.s==1)&&isbmsfr($1.value))
			if((pass2)&&(yyvsp[0].val.s==1))
			{
				sprintf(yyval.val.rel, "bit(%s)", symexp);
				yyval.val.s=1;
			}
			else if( pass2 )
			{
				if( !isbit8(yyvsp[0].value) && (ObjectFile==0) )	error("Bit address exceeds 8-bits");
				yyval.value = yyvsp[0].value;
				yyval.val.s=0;

				if(ObjectFile==0)
				{
					if ( ((yyvsp[0].val.k&kmask[BSEG])==kmask[BSEG]) || (yyvsp[0].val.k==0) )
					{
						// The address of the bit is good
					}
					else
					{
						error("invalid bit address.");
					}
				}
			}
			symexp[0]=0;
		}
#line 5178 "parser.c"
    break;

  case 257: /* reg: R0  */
#line 2558 "parser.y"
             { yyval.value = 0; yyval.val.k=1; }
#line 5184 "parser.c"
    break;

  case 258: /* reg: R1  */
#line 2559 "parser.y"
             { yyval.value = 1; yyval.val.k=1; }
#line 5190 "parser.c"
    break;

  case 259: /* reg: R2  */
#line 2560 "parser.y"
             { yyval.value = 2; yyval.val.k=1; }
#line 5196 "parser.c"
    break;

  case 260: /* reg: R3  */
#line 2561 "parser.y"
             { yyval.value = 3; yyval.val.k=1; }
#line 5202 "parser.c"
    break;

  case 261: /* reg: R4  */
#line 2562 "parser.y"
             { yyval.value = 4; yyval.val.k=1; }
#line 5208 "parser.c"
    break;

  case 262: /* reg: R5  */
#line 2563 "parser.y"
             { yyval.value = 5; yyval.val.k=1; }
#line 5214 "parser.c"
    break;

  case 263: /* reg: R6  */
#line 2564 "parser.y"
             { yyval.value = 6; yyval.val.k=1; }
#line 5220 "parser.c"
    break;

  case 264: /* reg: R7  */
#line 2565 "parser.y"
             { yyval.value = 7; yyval.val.k=1; }
#line 5226 "parser.c"
    break;

  case 265: /* areg: AR0  */
#line 2569 "parser.y"
              { yyval.value = 0; yyval.val.k=1; }
#line 5232 "parser.c"
    break;

  case 266: /* areg: AR1  */
#line 2570 "parser.y"
              { yyval.value = 1; yyval.val.k=1; }
#line 5238 "parser.c"
    break;

  case 267: /* areg: AR2  */
#line 2571 "parser.y"
              { yyval.value = 2; yyval.val.k=1; }
#line 5244 "parser.c"
    break;

  case 268: /* areg: AR3  */
#line 2572 "parser.y"
              { yyval.value = 3; yyval.val.k=1; }
#line 5250 "parser.c"
    break;

  case 269: /* areg: AR4  */
#line 2573 "parser.y"
              { yyval.value = 4; yyval.val.k=1; }
#line 5256 "parser.c"
    break;

  case 270: /* areg: AR5  */
#line 2574 "parser.y"
              { yyval.value = 5; yyval.val.k=1; }
#line 5262 "parser.c"
    break;

  case 271: /* areg: AR6  */
#line 2575 "parser.y"
              { yyval.value = 6; yyval.val.k=1; }
#line 5268 "parser.c"
    break;

  case 272: /* areg: AR7  */
#line 2576 "parser.y"
              { yyval.value = 7; yyval.val.k=1; }
#line 5274 "parser.c"
    break;

  case 273: /* regi: reg  */
#line 2581 "parser.y"
                {
			if(yyvsp[0].val.v<2) yyval.value = yyvsp[0].val.v;
			else
			{
				yyval.value = 0;
				error("Invalid indirect register: @r%d", yyvsp[0].val.v);
			}
		}
#line 5287 "parser.c"
    break;

  case 274: /* data8: expr  */
#line 2593 "parser.y"
                {
			if((pass2)&&(yyval.val.s==1))
			{
				sprintf(yyval.val.rel,"data8(%s)", symexp);
				yyval.val.s=1;
			}
			else if( pass2 )
			{
				if(yyval.val.s==0)
				{
					if( !isbit8(yyvsp[0].val.v) && (ObjectFile==0) ) error("Expression greater than 8-bits");
				}
				yyval.value = yyvsp[0].val.v;// & 0xff; //Allow 16-bit data expression in object files.  They are truncated by the linker.
				yyval.val.s=0;
			}
			symexp[0]=0;
		}
#line 5309 "parser.c"
    break;

  case 275: /* data8: areg  */
#line 2612 "parser.y"
                { yyval.value = yyvsp[0].val.v+(8*RegisterBank); }
#line 5315 "parser.c"
    break;

  case 276: /* data16: expr  */
#line 2617 "parser.y"
                {
			if((pass2)&&(yyval.val.s==1))
			{
				sprintf(yyval.val.rel,"data16(%s)", symexp);
				yyval.val.s=1;
			}
			else
			{
				if( pass2 )
				{
					if( !isbit16(yyvsp[0].val.v)  && (ObjectFile==0) ) error("Expression greater than 16-bits");
				}
				yyval.value = yyvsp[0].val.v;
				yyval.val.s=0;
			}
			symexp[0]=0;
		}
#line 5337 "parser.c"
    break;

  case 277: /* data16: STRING  */
#line 2635 "parser.y"
                {
			if(strlen(yyvsp[0].str)!=2)
			{
				error("Invalid 16-bit string constant");
			}
			else
			{
				yyval.value = (yyvsp[0].str[0]*0x100)+yyvsp[0].str[1];
			}
			free(yyvsp[0].str);
		}
#line 5353 "parser.c"
    break;

  case 278: /* addr11: expr  */
#line 2650 "parser.y"
                {
			if((pass2)&&(yyvsp[0].val.s==1))
			{
				sprintf(yyval.mode.str1, "addr11(%s)", symexp);
				yyval.mode.str2[0]=' ';
				yyval.mode.str2[1]=0;
			}
			else
			{
				if( pass2 )
				{
					if( !isbit16(yyvsp[0].val.v)  )
						error("Address greater than 16-bits");
					if( ((unsigned long)(yyvsp[0].val.v & size11)) != ((current_seg->value+2) & size11) )
						error("Address outside current 2K page");
				}
				set_b1(yyval.mode,yyvsp[0].val.v&0x00ff);
			}
			set_md(yyval.mode,0);
			set_ov(yyval.mode, (yyvsp[0].val.v&0x0700)>>3 );
			set_sz(yyval.mode,1);
			symexp[0]=0;
		}
#line 5381 "parser.c"
    break;

  case 279: /* addr16: expr  */
#line 2677 "parser.y"
                {
			if((pass2)&&(yyvsp[0].val.s==1))
			{
				sprintf(yyval.mode.str1, "addr16(%s)", symexp);
				yyval.mode.str2[0]=' ';
				yyval.mode.str2[1]=0;
				yyval.val.s=1;
			}
			else
			{
				if( pass2 )
				{
					if( !isbit16(yyvsp[0].val.v)  ) error("Address greater than 16-bits");
				}
				set_b1(yyval.mode, yyvsp[0].val.v / 0x100 ); // Doesn't work on macOS / Linux
				set_b2(yyval.mode, (yyvsp[0].val.v & 0x00ff ) ); // Works
				yyval.val.v=yyvsp[0].val.v;
				//printf("addr16=%04lx, b1=%02x, b2=%02x\n", $1.val.v, get_b1($$.mode), get_b2($$.mode));
			}
			set_md(yyval.mode,0);
			set_ov(yyval.mode, 0 );
			set_sz(yyval.mode,2);
			symexp[0]=0;
		}
#line 5410 "parser.c"
    break;

  case 280: /* relative: expr  */
#line 2705 "parser.y"
                {
			long offset=0;
			if((pass2)&&(yyvsp[0].val.s==1))
			{
				sprintf(yyval.mode.str1, "rel2(%s)", symexp);
			}
			else
			{
				if( pass2 )
				{
					offset = yyvsp[0].val.v - (current_seg->value+2);
					if( offset>127 || offset<-128 )
					   error("Relative offset exceeds -128 / +127");
				}
				set_b1(yyval.mode,offset);
			}
			set_md(yyval.mode,0);
			set_ov(yyval.mode,0);
			set_sz(yyval.mode,1);
			symexp[0]=0;
		}
#line 5436 "parser.c"
    break;


#line 5440 "parser.c"

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

#line 2728 "parser.y"


/* ---------------------------------------------------------------------- */

void yyerror(char *s)
{
	error((const char *)"%s near \"%s\"", s, get_last_token());
	//error((const char *)"%s", s);
}

void set_str1(struct mode *m, union ystack *y)
{
	if(y->val.s==1)
	{
		strcpy(m->str1, y->val.rel);
	}
	else
		m->str1[0]=0;
}

void set_str2(struct mode *m, union ystack *y)
{
	if(y->val.s==1)
	{
		strcpy(m->str2, y->val.rel);
	}
	else
		m->str2[0]=0;
}

/* ----------------------------------------------------------------------
 * makeop:
 *	This function makes an opcode based on the instruction symbol table
 *	entry, and an addressing mode structure.
 *	This function is called from both passes, but
 *	only generates code in pass 2.
 *
 *	Resultant opcode bytes are passed to genbyte().
 *
 *	Returns the number of bytes that the instruction
 *	occupies.
 *
 */

int makeop(struct opcode * op, struct mode *m, int add)
{
	register unsigned int newop;

	if( m == NULL )
	{
		if(pass2)
		{
			genbyte(op->bytes[0+add]);
			if(ObjectFile) fprintf(fobj, "%02X\n", op->bytes[0+add]);
		}
		return(1);
	}

	if( pass2 )
	{
		//printf("byte 0 = %02x\n", newop);
		newop = op->bytes[ get_md(*m)+add ] | get_ov(*m);
		genbyte(newop);
		if(ObjectFile) fprintf(fobj, "%02X", newop); 
		
		if( get_sz(*m) > 0 )
		{ 
			//printf("byte 1 = %02x\n", get_b1(*m) & 0xff);
			genbyte( get_b1(*m) & 0xff );
			if(ObjectFile)
			{
				if (m->str1[0]!=0)
				{
					fprintf(fobj, " %s", m->str1);
				}
				else fprintf(fobj, " %02X", get_b1(*m)&0xff);
			}
		}
		if( get_sz(*m) > 1 )
		{
			//printf("byte 2 = %02x\n", get_b2(*m) & 0xff);
			genbyte( get_b2(*m) & 0xff );
			if(ObjectFile)
			{
				if (m->str2[0]!=0)
				{
					fprintf(fobj, " %s", m->str2);
				}
				else fprintf(fobj, " %02X", get_b2(*m)&0xff);
			}
		}
	}

	if((ObjectFile)&&(pass2)) fprintf(fobj, "\n");

	return( get_sz(*m)+1 );
}

/* ----------------------------------------------------------------------
 * padline:
 *	This routine returns a new string, which is equivalent to
 *	'line' except that all tabs have been expanded to spaces, and
 *	the total length has been truncated to 0x200 chars.
 */

char *padline(char *line)
{
	static char newline[0x200];
	char *p1;
	int pos=0,nxtpos;

	for(p1=line; pos<sizeof(newline)-1 && *p1; p1++ )
	{
		if( *p1 == '\t' )
		{
			nxtpos = pos+8-pos%8;
			while(pos<sizeof(newline)-1 && pos <= nxtpos)
				newline[pos++] = ' ';
		}
		else if ( ( *p1 != '\n' ) && ( *p1 != '\r' ) )
		{
			newline[pos++]= *p1;
		}
	}
	newline[pos] = '\0';
	return(newline);
}


/* ----------------------------------------------------------------------
 * dumplist:
 *	Outputs the current location counter, bytebuf[] array, and
 *	the string 'txt' to the listing file.
 *	This routine is called for every source line encountered in the
 *	source file. (Only in pass 2, and if listing is turned on).
 *
 */

void dumplist(char *txt, int show)
{
	int i,j,lc;
	int numnl, mylineno, prevnl;

	for(j=0, numnl=0; txt[j]!=0; j++)
	{
		if(txt[j]=='\n') numnl++;
	}
	if(numnl>1)
	{
		mylineno=lineno-numnl+1;
		fprintf(listing, "              %5d   ", mylineno++);
		prevnl=0;
		for(j=0; txt[j]!=0; j++)
		{
			if(txt[j]!='\n')
			{
				if(prevnl)
				{
					fprintf(listing, "\n              %5d   ", mylineno++);
					prevnl=0;
				}
				if(txt[j]!='\r') fprintf(listing, "%c", txt[j]);
			}
			else
			{
				prevnl=1;
			}
		}
		fprintf(listing, "\n");
		return;
	}

	lc=current_seg->value;

	if(show)
	{
		fprintf(listing, "%04X ", lc);
	}
	else
	{
		fprintf(listing, "%04X ", lc);
		//fprintf(listing, "     ");
	}

	for(i=0; i<4; i++ ) {
		if(i<bytecount)
		    fprintf(listing,"%02X",bytebuf[i]);
		else
		    fprintf(listing,"  ");
	}
	fprintf(listing," %5d   %s", lineno, padline(txt));

	for(j=0; i<bytecount; i++, j++)
	{
		if((j%4)==0) fprintf(listing, "\n     ");
		if(i<bytecount) fprintf(listing, "%02X",bytebuf[i]);
	}
	fprintf(listing, "\n");
}

/* ----------------------------------------------------------------------
 * gen* routines:
 *	Place information into the bytebuf[] array, and also
 *	call emitbyte with the byte.
 *
 */

void genbyte(int b)
{
	//printf("%02x\n", b);
	if( bytecount < sizeof(bytebuf) )
		bytebuf[bytecount++] = b;
	if(ObjectFile==0) emitbyte(b);
}

void genstr(char *s)
{
	while( *s )
		genbyte(*s++);
}

void genword(unsigned long w)
{
	genbyte( (w & 0xff00) >> 8 );
	genbyte( (w & 0x00ff) );
}

void objbyte(int b)
{
	fprintf(fobj, "%02X\n", b);
}

void objstr(char *s)
{
	int j;

	for(j=0; s[j]!=0; j++)
	{
		fprintf(fobj, "%02X", s[j]);
		if((j>0)&&(j%16==0)) fprintf(fobj, "\n");
		else fprintf(fobj, " ");
	}
	fprintf(fobj, "\n");
}

void objword(unsigned long w)
{
	fprintf(fobj, "%02lX ",  (w & 0xff00) >> 8 );
	fprintf(fobj, "%02lX\n", (w & 0x00ff) );
}

void BadRegUse(char * x)
{
	 error("Invalid use of predefined register '%s'", x);
	 seek_eol();
}

void NoObjectFileError (char * x)
{
	error("Directive '%s' not allowed for absolute compilation.\n", x);
}
