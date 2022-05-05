%{
	int yylex();
	void yyerror(const char *s);
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#define maxLinesToParse 256
	extern FILE * yyin;
    FILE * f1;
	int lineCount=0;
	char outputMessages [maxLinesToParse][maxLinesToParse];
	void printInFile(char message[maxLinesToParse]);
%}

%union {int int_type; char var[32];}
%start program

/* Keywords tokens*/
%token IF ELSE FOR WHILE DO SWITCH CASE DEFAULT BREAK CONTINUE RETURN SEMICOLON 

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

Starter 			: {printInFile("empty file\n");} 
					| Statement
					/* | Assign 
					| DataType 
					| Function 
					| VarDeclaration 
					| Condition
					| WhileLoop
					| DoWhileLoop 
					| ForLoop
					| SwitchCase
					| Increment
					| Decrement
					| FunctionCall */
					;
					
Statement			: VarDeclaration Statement
					| Condition Statement
					| WhileLoop Statement
					| DoWhileLoop Statement
					| ForLoop Statement
					| SwitchCase Statement
					| Expression Statement
					| Assign Statement
					|
					;

VarDeclaration		: DataType IDETIFIER ';' {printInFile("Variable Defined succefully\n");}
					| DataType Assign
					;



Expression			: Expression '+' Expression
					| Expression '-' Expression
					| Expression '*' Expression
					| Expression '/' Expression
					| Expression '%' Expression
					| Expression OP_EQUALITY Expression
					| Expression OP_INEQUALITY Expression
					| Expression OP_GREATER_OR_EQUAL Expression
					| Expression OP_LESS_OR_EQUAL Expression
					| Expression OP_GREATER_THAN Expression
					| Expression OP_LESS_THAN Expression
					| Expression OP_LOGICAL_OR Expression
					| Expression OP_LOGICAL_AND Expression
					| '(' Expression ')'
					| ValueTypeNumber
					| AssignExp
					| IDETIFIER
					;

AssignExp			: IDETIFIER '=' Expression
					;

Assign  			: IDETIFIER '=' Expression ';' {printInFile("Assigned succefully\n");}
					;
/* 
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
					; */

Increment			: OP_INCREMENT IDETIFIER {printInFile("Prefix increment detected\n");}
					| IDETIFIER OP_INCREMENT {printInFile("Postfix increment detected\n");}
					;

Decrement			: OP_DECREMENT IDETIFIER {printInFile("Prefix decrement detected\n");}
					| IDETIFIER OP_DECREMENT {printInFile("Postfix decrement detected\n");}
					;


/* Logic				: AssignLogic {printInFile("Logic operators detected\n");}
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
					; */




 /* Any 'Assign' written below is to be changed to a block of statements */

Function			: DataType IDETIFIER '(' Parameters ')' '{' Statement '}' {printInFile("Function constructed successfully\n");}
					;


 /* If conditon */
Condition			: Mif {printInFile("MIf constructed successfully\n");}
					| Uif {printInFile("UIf constructed successfully\n");}
					;

Mif					: IF '(' Expression ')' '{' Statement '}' ELSE Mif
					| '{' Assign '}'
					;

Uif					: IF '(' Expression ')' '{' Statement '}'
					| IF '(' Expression ')' '{' Statement '}' ELSE Condition
					;

 /* loops */
WhileLoop			: WHILE '(' Expression ')' '{' Statement '}' {printInFile("While Loop constructed successfully\n");}
					;

DoWhileLoop			: DO '{' Statement '}' WHILE '(' Expression ')' ';' {printInFile("Do while Loop constructed successfully\n");}
					;


ForLoopInit			: VarDeclaration
					| Assign
					;

ForLoop				: FOR '(' ForLoopInit Expression ';' Expression ')' '{' Statement '}' {printInFile("For Loop constructed successfully\n");}
					;

SwitchValueTypes	: VAL_INTEGER
					| VAL_CHAR
					;

Case				: CASE SwitchValueTypes ':' Statement Case
					| DEFAULT ':' Statement
					|
					;

SwitchCase			: SWITCH '(' IDETIFIER ')' '{' Case '}'	{printInFile("Switch case constructed successfully\n");}
					;


Parameters			: DataTypeNoVoid IDETIFIER ',' DataTypeNoVoid IDETIFIER 
					| DataTypeNoVoid IDETIFIER
					| VOID
					|
					;

Arguments			: Expression ',' Arguments
					| Expression
					;


FunctionCall		: IDETIFIER '(' Arguments ')' ';' 

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

DataTypeNoVoid		: INTEGER
					| FLOAT
					| CHARACTER
					| STRING
					| BOOLEAN
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
	char errorString[256];
	strcpy(errorString,s);
	printInFile(errorString);
}

void printInFile(char message[maxLinesToParse]){
	strcpy(outputMessages[lineCount],message);
	lineCount++;
}


int main(void) {
    yyin = fopen("test.txt", "r");
	f1=fopen("output.txt","w");
   if(!yyparse())
	{
		printf("\nParsing complete\n");
		for(int i=0; i<lineCount ; i++)
			fprintf(f1,outputMessages[i]);
	}
	else
	{
		for(int i=0; i<lineCount ; i++)
			fprintf(f1,outputMessages[i]);
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