
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

/* Line 1676 of yacc.c  */
#line 24 "parser.y"

		int data_type;
		struct entry* entry;
	


/* Line 1676 of yacc.c  */
#line 151 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


