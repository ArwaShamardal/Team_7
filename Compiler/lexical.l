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

/*** Rule Section has three rules, first rule (regex)
matches with capital letters, second rule
matches with any character except newline and
third rule does not take input after the enter***/
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