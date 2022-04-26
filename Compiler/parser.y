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
%token VAL_INTEGER VAL_FLOAT VAL_DOUBLE VAL_STRING VAL_CHAR VAL_BOOLEAN
%token <var> IDETIFIER;

%right '='
%left '+' '-'
%left '*' '/' '%'
%left UMINUS


/*Grammars are written in UpperCamelCase*/

%%
Starter 			: {printf("empty file");} | Assign |DataType
					;

Assign  			: IDETIFIER '=' Expression ';' {printf("Assigned succefully");}
					;

DataType			: INTEGER
					| FLOAT
					| CHARACTER
					| STRING
					| BOOLEAN
					| VOID
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
					| ValueTypeNumber
					| IDETIFIER
					;

ValueTypeNumber		: VAL_INTEGER 
					| VAL_FLOAT
					;

/*ValueTypeLetter		: VAL_BOOLEAN
					| VAL_CHAR
					| VAL_STRING
					;

ValueTypeAll		: ValueTypeNumber
					| ValueTypeLetter
					;*/			
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