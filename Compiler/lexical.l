/*** Definition Section has one variable
which can be accessed inside yylex()
and main() ***/
%{
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "y.tab.h"
void yyerror(const char *s);
int count = 0;
%}



/* Regular expressions */
letter			[a-zA-Z]
digit			[0-9]
skip_char 		[ \t\r\f\v]+
variable 		(_|{letter})({letter}|{digit}|_)*
/*{0,31}*/

integer_val 	[1-9]{digit}*
float_val		({digit}+[.])?{digit}+
string_val		\"[^("|\')]*\"$
char_val		\'.\'
bool_val		"true"|"false"|"1"|"0"
/*double_val		({digit}+[.])?{digit}+ */


/*** Tokens format
/***	1- Capitalized letters
/***	2- Seperated by _ if needed
/***	3- No abbreviations except for type identifier (e.g VAL_ , OP_ ,  etc.)
/*** "//".*"//"      {printf("%s comment was entered \n", yytext);}
/*  */
%%
int 			{return INTEGER;}
float 			{return FLOAT;}
char			{return CHARACTER;}
string 			{return STRING;}
double 			{return DOUBLE;}
bool 			{return BOOLEAN;}
void 			{return VOID;}
if 				{return IF;}
else 			{return ELSE;}
for 			{return FOR;}
while 			{return WHILE;}
do 				{return DO;}
switch 			{return SWITCH;}
case 			{return CASE;}
const 			{return CONSTANT;}
break 			{return BREAK;}
continue		{return CONTINUE;}
return			{return RETURN;}
<<EOF>>			{return 0;}



";"				{ return(';'); }
","				{ return(','); }
"("				{ return('('); }
")"				{ return(')'); }
"{"				{ return('{'); }
"}"				{ return('}'); }
":"				{ return(':'); }

"++"			{ return OP_INCREMENT; }
"--"			{ return OP_DECREMENT; }
"<="			{ return OP_LESS_OR_EQUAL; }
">="			{ return OP_GREATER_OR_EQUAL; }
"<"				{ return OP_LESS_THAN; }
">"				{ return OP_GREATER_THAN; }
"=="			{ return OP_EQUALITY; }
"!="			{ return OP_INEQUALITY; }
"&&"			{ return OP_LOGICAL_AND; }
"||"			{ return OP_LOGICAL_OR; }

"="				{return('=');}
"+"				{return('+');}
"-"				{return('-');}
"*"				{return('*');}
"/"				{return('/');}
"%"				{return('%');}




{bool_val}      {return VAL_BOOLEAN;}
{variable}		{return IDETIFIER;}
{integer_val}	{return VAL_INTEGER;}
{float_val}		{return VAL_FLOAT;}
{string_val}	{return VAL_STRING;}
{char_val}		{return VAL_CHAR;}


{skip_char}		;

.				{yyerror("invalid character");}
%%

int yywrap(){}