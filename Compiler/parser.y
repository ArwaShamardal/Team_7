%{
	int yylex();
	void yyerror(const char *s);
	#include <stdlib.h>
	#include <stdio.h>
%}

%union {int int_type; char var[32];}
%start Starter

/* Keywords tokens*/
%token IF ELSE FOR WHILE DO SWITCH CASE BREAK CONTINUE RETURN SEMICOLON

/*Data types tokens*/
%token INTEGER CHARACTER FLOAT STRING DOUBLE BOOLEAN CONSTANT VOID

/* Variables/Values*/
%token VAL_INTEGER VAL_FLOAT
%token <var> VARIABLE;

%right OP_EQUAL
%left '+' '-'
%left '*' '/' '%'
%left UMINUS



%%
Starter : | Assign;
Assign : VARIABLE OP_EQUAL Exp SEMICOLON {printf("%s was entered \n",atoi($1));};
Exp: VARIABLE | Digit;
Digit: VAL_INTEGER ;
%%

/* {printf(" %d parser",VAL_INTEGER);} */

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