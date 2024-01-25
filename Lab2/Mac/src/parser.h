/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    STRING = 258,                  /* STRING  */
    D_ORG = 259,                   /* D_ORG  */
    D_BYTE = 260,                  /* D_BYTE  */
    D_WORD = 261,                  /* D_WORD  */
    D_SKIP = 262,                  /* D_SKIP  */
    D_EQU = 263,                   /* D_EQU  */
    D_SET = 264,                   /* D_SET  */
    D_MAC = 265,                   /* D_MAC  */
    D_DBIT = 266,                  /* D_DBIT  */
    D_END = 267,                   /* D_END  */
    D_DSEG = 268,                  /* D_DSEG  */
    D_ISEG = 269,                  /* D_ISEG  */
    D_BSEG = 270,                  /* D_BSEG  */
    D_CSEG = 271,                  /* D_CSEG  */
    D_XSEG = 272,                  /* D_XSEG  */
    ACALL = 273,                   /* ACALL  */
    ADD = 274,                     /* ADD  */
    ADDC = 275,                    /* ADDC  */
    AJMP = 276,                    /* AJMP  */
    ANL = 277,                     /* ANL  */
    CALL = 278,                    /* CALL  */
    CJNE = 279,                    /* CJNE  */
    CLR = 280,                     /* CLR  */
    CPL = 281,                     /* CPL  */
    DA = 282,                      /* DA  */
    DEC = 283,                     /* DEC  */
    DIV = 284,                     /* DIV  */
    DJNZ = 285,                    /* DJNZ  */
    INC = 286,                     /* INC  */
    D_INCLUDE = 287,               /* D_INCLUDE  */
    JB = 288,                      /* JB  */
    JBC = 289,                     /* JBC  */
    JC = 290,                      /* JC  */
    JMP = 291,                     /* JMP  */
    JNB = 292,                     /* JNB  */
    JNC = 293,                     /* JNC  */
    JNZ = 294,                     /* JNZ  */
    JZ = 295,                      /* JZ  */
    LCALL = 296,                   /* LCALL  */
    LJMP = 297,                    /* LJMP  */
    MOV = 298,                     /* MOV  */
    MOVC = 299,                    /* MOVC  */
    MOVX = 300,                    /* MOVX  */
    NOP = 301,                     /* NOP  */
    MUL = 302,                     /* MUL  */
    ORL = 303,                     /* ORL  */
    POP = 304,                     /* POP  */
    PUSH = 305,                    /* PUSH  */
    RET = 306,                     /* RET  */
    RETI = 307,                    /* RETI  */
    RL = 308,                      /* RL  */
    RLC = 309,                     /* RLC  */
    RR = 310,                      /* RR  */
    RRC = 311,                     /* RRC  */
    SETB = 312,                    /* SETB  */
    SJMP = 313,                    /* SJMP  */
    SUBB = 314,                    /* SUBB  */
    SWAP = 315,                    /* SWAP  */
    XCH = 316,                     /* XCH  */
    XCHD = 317,                    /* XCHD  */
    XRL = 318,                     /* XRL  */
    AB = 319,                      /* AB  */
    A = 320,                       /* A  */
    C = 321,                       /* C  */
    PC = 322,                      /* PC  */
    DPTR = 323,                    /* DPTR  */
    BITPOS = 324,                  /* BITPOS  */
    R0 = 325,                      /* R0  */
    R1 = 326,                      /* R1  */
    R2 = 327,                      /* R2  */
    R3 = 328,                      /* R3  */
    R4 = 329,                      /* R4  */
    R5 = 330,                      /* R5  */
    R6 = 331,                      /* R6  */
    R7 = 332,                      /* R7  */
    USING = 333,                   /* USING  */
    AR0 = 334,                     /* AR0  */
    AR1 = 335,                     /* AR1  */
    AR2 = 336,                     /* AR2  */
    AR3 = 337,                     /* AR3  */
    AR4 = 338,                     /* AR4  */
    AR5 = 339,                     /* AR5  */
    AR6 = 340,                     /* AR6  */
    AR7 = 341,                     /* AR7  */
    VALUE = 342,                   /* VALUE  */
    SYMBOL = 343,                  /* SYMBOL  */
    CONTROL = 344,                 /* CONTROL  */
    HIGH = 345,                    /* HIGH  */
    LOW = 346,                     /* LOW  */
    NOT = 347,                     /* NOT  */
    D_AT = 348,                    /* D_AT  */
    D_DS = 349,                    /* D_DS  */
    D_BIT = 350,                   /* D_BIT  */
    D_DATA = 351,                  /* D_DATA  */
    D_XDATA = 352,                 /* D_XDATA  */
    D_IDATA = 353,                 /* D_IDATA  */
    D_CODE = 354,                  /* D_CODE  */
    MOD = 355,                     /* MOD  */
    D_SEG = 356,                   /* D_SEG  */
    D_RSEG = 357,                  /* D_RSEG  */
    PUBLIC = 358,                  /* PUBLIC  */
    EXTERN = 359,                  /* EXTERN  */
    OVERL = 360,                   /* OVERL  */
    IF = 361,                      /* IF  */
    IFDEF = 362,                   /* IFDEF  */
    IFNDEF = 363,                  /* IFNDEF  */
    ENDIF = 364,                   /* ENDIF  */
    ELSE = 365,                    /* ELSE  */
    ERROR = 366,                   /* ERROR  */
    OR = 367,                      /* OR  */
    AND = 368,                     /* AND  */
    XOR = 369,                     /* XOR  */
    SHR = 370,                     /* SHR  */
    SHL = 371,                     /* SHL  */
    C_GT = 372,                    /* C_GT  */
    C_LT = 373,                    /* C_LT  */
    C_GE = 374,                    /* C_GE  */
    C_LE = 375,                    /* C_LE  */
    C_EQ = 376,                    /* C_EQ  */
    C_NE = 377                     /* C_NE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
