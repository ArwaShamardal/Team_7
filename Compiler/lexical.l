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
variable 		(_|{letter})({letter}|{digit}|_){0,31}
integer_val 	[1-9]{digit}*
float_val		({digit}+[.])?{digit}+


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

;				{return SEMICOLON;}
=				{return OP_EQUAL;}

{skip_char}			;

{variable}		{return VARIABLE;}

{integer_val}	{return VAL_INTEGER;}
{float_val}		{return VAL_FLOAT;}

.				{yyerror("invalid character");}
%%

int yywrap(){}