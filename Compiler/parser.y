%{
	int yylex();
	void yyerror(const char *s);
	#include <stdlib.h>
	#include <stdio.h>
%}

%union {int int_type; char var[32];}
%start program

/* Keywords tokens*/
%token IF ELSE FOR WHILE DO SWITCH CASE BREAK CONTINUE RETURN SEMICOLON

/*Data types tokens*/
%token INTEGER CHARACTER FLOAT STRING DOUBLE BOOLEAN CONSTANT VOID

/* Variables/Values*/
%token VAL_INTEGER VAL_FLOAT VAL_DOUBLE VAL_STRING VAL_CHAR VAL_BOOLEAN
%token <var> IDETIFIER;

/*Short assignment operators*/
%token OP_INCREMENT OP_DECREMENT

%right '='
%left OP_LESS_OR_EQUAL OP_GREATER_OR_EQUAL OP_LESS_THAN OP_GREATER_THAN 
%left OP_LOGICAL_AND OP_LOGICAL_OR OP_EQUALITY OP_INEQUALITY
%left '+' '-'
%left '*' '/' '%'
%left UMINUS


/*Grammars are written in UpperCamelCase*/

%%
program 			: Starter program
    				| Starter
					;

Starter 			: {printf("empty file");} | Assign |DataType |Logic
					;

Assign  			: IDETIFIER '=' Expression ';' {printf("Assigned succefully");}
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

Logic				: AssignLogic ';' {printf("Logic operators detected");}
					;

AssignLogic			: AssignLogic OP_EQUALITY AssignLogic  
					| AssignLogic OP_LOGICAL_OR AssignLogic
					| AssignLogic OP_LOGICAL_AND AssignLogic
					| Expression
					; 



/*ValueTypeLetter		: VAL_BOOLEAN
					| VAL_CHAR
					| VAL_STRING
					;

ValueTypeAll		: ValueTypeNumber
					| ValueTypeLetter
					;*/

DataType			: INTEGER
					| FLOAT
					| CHARACTER
					| STRING
					| BOOLEAN
					| VOID
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