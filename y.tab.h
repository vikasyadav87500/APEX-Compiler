
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

extern YYSTYPE yylval;


