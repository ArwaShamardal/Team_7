/*** Definition Section has one variable
which can be accessed inside yylex()
and main() ***/
%{
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "y.tab.h"
int yylex();
void yyerror(const char *s);
int count = 0;
%}

/* Regular expressions */
letter [a-zA-Z]
digit [0-9]
skip_char  [ \t\r\f\v]+
identifier (_|{letter})({letter}|{digit}|_){0,31}

%%
int 		{return INTEGER;}
float 		{return FLOAT;}
char		{return CHARACTER;}
string 		{return STRING;}
double 		{return DOUBLE;}
bool 		{return BOOLEAN;}
void 		{return VOID;}
if 			{return IF;}
else 		{return ELSE;}
for 		{return FOR;}
while 		{return WHILE;}
do 			{return DO;}
switch 		{return SWITCH;}
case 		{return CASE;}
const 		{return CONSTANT;}
break 		{return BREAK;}
continue	{return CONTINUE;}
return		{return RETURN;}
.		{yyerror("invalid character");}
%%

/*** Code Section prints the number of
capital letter present in the given input***/  // (C code)
int yywrap(){}
int main(){

// Explanation:
// yywrap() - wraps the above rule section
/* yyin - takes the file pointer
		which contains the input*/
/* yylex() - this is the main flex function
		which runs the Rule Section*/
// yytext is the text in the buffer

// Uncomment the lines below
// to take input from file
// FILE *fp;
// char filename[50];
// printf("Enter the filename: \n");
// scanf("%s",filename);
// fp = fopen(filename,"r");
// yyin = fp;

yylex();
printf("\nNumber of Capital letters "
	"in the given input - %d\n", count);

return 0;
}