%{
	int yylex();
	void yyerror(const char *s);
	#include <stdlib.h>
	#include <stdio.h>
	FILE * yyin;
    FILE * f1;
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



Logic				: AssignLogic {printf("Logic operators detected");}
					;

AssignLogic			: AssignLogic OP_EQUALITY AssignLogic
					| AssignLogic OP_INEQUALITY AssignLogic
					| AssignLogic OP_GREATER_OR_EQUAL AssignLogic
					| AssignLogic OP_LESS_OR_EQUAL AssignLogic
					| AssignLogic OP_GREATER_THAN AssignLogic
					| AssignLogic OP_LESS_THAN AssignLogic
					| AssignLogic OP_LOGICAL_OR AssignLogic
					| AssignLogic OP_LOGICAL_AND AssignLogic
					| ValueTypeAll
					| IDETIFIER
					| '(' Expression ')'
					; 

ValueTypeNumber		: VAL_INTEGER 
					| VAL_FLOAT
					;

ValueTypeLetter		: VAL_BOOLEAN
					| VAL_CHAR
					| VAL_STRING
					;

ValueTypeAll		: ValueTypeNumber
					| ValueTypeLetter
					;

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


int main(void) {
    yyin = fopen("test.txt", "r");
	f1=fopen("output.txt","w");
   if(!yyparse())
	{
		printf("\nParsing complete\n");
		fprintf(f1,"hello there");
	}
	else
	{
		fprintf(f1,"I can not parse");
		printf("\nParsing failed\n");
		return 0;
	}
	fclose(yyin);
	fclose(f1);
    return 0;
}

/*int main (void)
{
	int a=1;
	while(1){
		yyparse ();
	}
  	return 0;
}*/