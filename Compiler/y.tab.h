
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
     IF = 258,
     ELSE = 259,
     FOR = 260,
     WHILE = 261,
     DO = 262,
     SWITCH = 263,
     CASE = 264,
     BREAK = 265,
     CONTINUE = 266,
     RETURN = 267,
     SEMICOLON = 268,
     INTEGER = 269,
     CHARACTER = 270,
     FLOAT = 271,
     STRING = 272,
     DOUBLE = 273,
     BOOLEAN = 274,
     CONSTANT = 275,
     VOID = 276,
     VAL_INTEGER = 277,
     VAL_FLOAT = 278,
     VAL_DOUBLE = 279,
     VAL_STRING = 280,
     VAL_CHAR = 281,
     VAL_BOOLEAN = 282,
     IDETIFIER = 283,
     OP_INCREMENT = 284,
     OP_DECREMENT = 285,
     OP_GREATER_THAN = 286,
     OP_LESS_THAN = 287,
     OP_GREATER_OR_EQUAL = 288,
     OP_LESS_OR_EQUAL = 289,
     OP_INEQUALITY = 290,
     OP_EQUALITY = 291,
     OP_LOGICAL_OR = 292,
     OP_LOGICAL_AND = 293,
     UMINUS = 294
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
#define BREAK 265
#define CONTINUE 266
#define RETURN 267
#define SEMICOLON 268
#define INTEGER 269
#define CHARACTER 270
#define FLOAT 271
#define STRING 272
#define DOUBLE 273
#define BOOLEAN 274
#define CONSTANT 275
#define VOID 276
#define VAL_INTEGER 277
#define VAL_FLOAT 278
#define VAL_DOUBLE 279
#define VAL_STRING 280
#define VAL_CHAR 281
#define VAL_BOOLEAN 282
#define IDETIFIER 283
#define OP_INCREMENT 284
#define OP_DECREMENT 285
#define OP_GREATER_THAN 286
#define OP_LESS_THAN 287
#define OP_GREATER_OR_EQUAL 288
#define OP_LESS_OR_EQUAL 289
#define OP_INEQUALITY 290
#define OP_EQUALITY 291
#define OP_LOGICAL_OR 292
#define OP_LOGICAL_AND 293
#define UMINUS 294




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 15 "parser.y"
int int_type; char var[32];


/* Line 1676 of yacc.c  */
#line 134 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


