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
%token VAL_INTEGER VAL_FLOAT VAL_DOUBLE
%token <var> VARIABLE;

%right '='
%left '+' '-'
%left '*' '/' '%'
%left UMINUS



%%
Starter 			: {printf("empty file");} | Assign
					;

Assign  			: VARIABLE '=' Expression ';' {printf("Assigned succefully");}
					;

Expression			: Expression '+' Term
					| Expression '-' Term
					| Term
					;

Term 				: Term '*' Factor 
					| Term '/' Factor
					| Term '%' Factor
					| Factor
					;
					
Factor				: '(' Expression ')'
					| Number
					| VARIABLE
					;

Number				: VAL_INTEGER 
					| VAL_FLOAT
					;
%%

/* {printf(" %d parser",VAL_INTEGER);}
	

 */

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