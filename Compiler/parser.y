%{
	int yylex();
	void yyerror(const char *s);
	#include <stdlib.h>
	#include <stdio.h>
%}

%union {int int_type; char variable[32];}
%start Starter

/* Keywords tokens*/
%token IF ELSE FOR WHILE DO SWITCH CASE BREAK CONTINUE RETURN 

/*Data types tokens*/
%token INTEGER CHARACTER FLOAT STRING DOUBLE BOOLEAN CONSTANT VOID

/* Variables/Values*/
%token VAL_INTEGER VAL_FLOAT
%token <variable> VARIABLE;

%right '='
%left '+' '-'
%left '*' '/' '%'
%left UMINUS



%%
Starter : Digit
Digit: VAL_INTEGER {printf(" %d parser",VAL_INTEGER);}
%%
/* Assign : VARIABLE '=' VARIABLE ';'{printf("%s = %s was entered \n", $1,$3);}*/
void yyerror (char const *s) {
	fprintf (stderr, "%s\n", s);
}

int main (void)
{
	int a=1;
	while(1){
		yyparse ();
	}
  	return 0;
}