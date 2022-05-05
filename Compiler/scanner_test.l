
%{
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
// #include "y.tab.h"
// void yyerror(const char *s);
int count = 0;
%}



/* Regular expressions */
letter			[a-zA-Z]
digit			[0-9]
skip_char 		[ \t\r\f\v]+
variable 		(_|{letter})({letter}|{digit}|_)*
/*{0,31}*/
comment        	\/\/.*

integer_val 	[1-9]{digit}*
float_val		({digit}*[.])?{digit}+
string_val		\"[^("|\')]*\"$
char_val		\'([^'\\]|\\.)?\'
bool_val		"true"|"false"|"1"|"0"
/*double_val		({digit}+[.])?{digit}+ */


/*** Tokens format
/***	1- Capitalized letters
/***	2- Seperated by _ if needed
/***	3- No abbreviations except for type identifier (e.g VAL_ , OP_ ,  etc.)
/*** "//".*"//"      {printf("%s comment was entered \n", yytext);}
/*  */
%%
int 			{printf("Keyword | int: %s", yytext);}
float 			{printf("Keyword | float: %s", yytext);}
char			{printf("Keyword | char: %s", yytext);}
string 			{printf("Keyword | string: %s", yytext);}
double 			{printf("Keyword | double: %s", yytext);}
bool 			{printf("Keyword | bool: %s", yytext);}
void 			{printf("Keyword | void: %s", yytext);}
if 				{printf("Keyword | if: %s", yytext);}
else 			{printf("Keyword | else: %s", yytext);}
for 			{printf("Keyword | for: %s", yytext);}
while 			{printf("Keyword | while: %s", yytext);}
do 				{printf("Keyword | do: %s", yytext);}
switch 			{printf("Keyword | switch: %s", yytext);}
case 			{printf("Keyword | case: %s", yytext);}
const 			{printf("Keyword | const: %s", yytext);}
break 			{printf("Keyword | break: %s", yytext);}
continue		{printf("Keyword | continue: %s", yytext);}
return			{printf("Keyword | return: %s", yytext);}
<<EOF>>			{printf("Keyword | EOF: %s", yytext);}



";"				{ printf("Semicolon: %s", yytext); }
","				{ printf("comma: %s", yytext); }
"("				{ printf("Open bracket: %s", yytext); }
")"				{ printf("closed bracket: %s", yytext); }
"{"				{ printf("open curly: %s", yytext); }
"}"				{ printf("closed curly: %s", yytext); }
":"				{ printf("colon: %s", yytext); }

"++"			{ printf("Increment: %s", yytext); }
"--"			{ printf("Decrement: %s", yytext); }

"+="            { printf("Plus equal: %s", yytext);; }
"-="            { printf("minus equal: %s", yytext);; }
"*="            { printf("times equal: %s", yytext);; }
"/="            { printf("Div equal: %s", yytext);; }
"%="            { printf("Mod equal: %s", yytext);; }

"<="			{ printf("less than or equal: %s", yytext); }
">="			{ printf("greater than or equal: %s", yytext); }
"<"				{ printf("less than: %s", yytext); }
">"				{ printf("greater than: %s", yytext); }
"=="			{ printf("equal: %s", yytext); }
"!="			{ printf("not equal: %s", yytext); }
"&&"			{ printf("and: %s", yytext); }
"||"			{ printf("or: %s", yytext); }

"="				{printf("assign: %s", yytext);}
"+"				{printf("plus: %s", yytext);}
"-"				{printf("minus: %s", yytext);}
"*"				{printf("times: %s", yytext);}
"/"				{printf("div: %s", yytext);}
"%"				{printf("modulo: %s", yytext);}




{bool_val}      {printf("Boolean Literal: %s", yytext);}
{variable}		{printf("Identifier: %s", yytext);}
{integer_val}	{printf("Integer Literal: %s", yytext);}
{float_val}		{printf("Float Literal: %s", yytext);}
{string_val}	{printf("String Literal: %s", yytext);}
{char_val}		{printf("Char Literal: %s", yytext);}

{comment}       {printf("Comment: %s", yytext);};


{skip_char}		{printf("Whitespace: %s", yytext);};

.				{printf("Invalid char: %s", yytext);}
%%

int yywrap(){}

int main() {yylex(); return 0;}