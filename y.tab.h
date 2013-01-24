/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
     AND = 258,
     OR = 259,
     CLASS = 260,
     IF = 261,
     THEN = 262,
     ELSE = 263,
     END = 264,
     WHILE = 265,
     DO = 266,
     DEF = 267,
     LEQ = 268,
     GEQ = 269,
     STRING = 270,
     FLOAT = 271,
     INT = 272,
     ID = 273,
     FOR = 274,
     TO = 275,
     RETURN = 276,
     IN = 277,
     NEQ = 278,
     EQ = 279
   };
#endif
/* Tokens.  */
#define AND 258
#define OR 259
#define CLASS 260
#define IF 261
#define THEN 262
#define ELSE 263
#define END 264
#define WHILE 265
#define DO 266
#define DEF 267
#define LEQ 268
#define GEQ 269
#define STRING 270
#define FLOAT 271
#define INT 272
#define ID 273
#define FOR 274
#define TO 275
#define RETURN 276
#define IN 277
#define NEQ 278
#define EQ 279




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 29 "parse.y"

  int nombre;
  char *chaine;
  struct mix{int nombre;
  char *chaine;
}mix;


/* Line 2068 of yacc.c  */
#line 107 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


