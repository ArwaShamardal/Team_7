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
%token OP_INCREMENT OP_DECREMENT /* Precedence check */

 /* Precedence and associativity */
%right OP_PLUS_EQUAL OP_MINUS_EQUAL OP_MULTIPLY_EQUAL OP_DIVIDE_EQUAL OP_MODULO_EQUAL	/* += -= *= /= %= */
%right '='
%left OP_LOGICAL_OR							/* || */
%left OP_LOGICAL_AND						/* && */
%left OP_EQUALITY OP_INEQUALITY				/* == != */
%left OP_LESS_OR_EQUAL OP_GREATER_OR_EQUAL OP_LESS_THAN OP_GREATER_THAN 		/* <= >= < > */
%left '+' '-'
%left '*' '/' '%'
%right OP_LOGICAL_NOT
 /* %right UMINUS */
%left '(' ')'	 		


/*Grammars are written in UpperCamelCase*/

%%
program 			: Starter program
    				| Starter
					;

Starter 			: {printInFile("empty file\n");} 
					| Statement Starter
					| Function Starter
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
					
Statement			: VarDeclaration Starter
					| Assign Starter
					| FunctionCall Starter
					| Condition Starter
					| WhileLoop Starter
					| DoWhileLoop Starter
					| ForLoop Starter
					| SwitchCase Starter
					| Increment Starter
					| Decrement Starter
					| ArithmeticAssign Starter
					| Return Starter
					| BREAK ';' Starter
					| CONTINUE ';' Starter
					| 
					;

VarDeclaration		: DataType IDETIFIER ';' {printInFile("Variable Defined succefully\n");}
					| DataType Assign
					| CONSTANT VarDeclaration
					;


Expression			: ArithmeticExp
					| FunctionCallExp
					| RelationalExp
					| LogicalExp
					| '(' Expression ')'
					| ValueTypeAll
					| AssignExp
					| IncrementExp
					| DecrementExp
					| ArithmeticAssignExp
					| IDETIFIER
					;

ArithmeticExp		: Expression '+' Expression
					| Expression '-' Expression
					| Expression '*' Expression
					| Expression '/' Expression
					| Expression '%' Expression
					| '-' Expression
					;

RelationalExp		: Expression OP_EQUALITY Expression
					| Expression OP_INEQUALITY Expression
					| Expression OP_GREATER_OR_EQUAL Expression
					| Expression OP_LESS_OR_EQUAL Expression
					| Expression OP_GREATER_THAN Expression
					| Expression OP_LESS_THAN Expression
					;	

LogicalExp			: Expression OP_LOGICAL_OR Expression
					| Expression OP_LOGICAL_AND Expression
					| OP_LOGICAL_NOT Expression
					;




AssignExp			: IDETIFIER '=' Expression
					;

Assign  			: AssignExp ';' {printInFile("Assigned succefully\n");}
					;

ArithmeticAssignExp : IDETIFIER OP_PLUS_EQUAL Expression
					| IDETIFIER OP_MINUS_EQUAL Expression
					| IDETIFIER OP_MULTIPLY_EQUAL Expression
					| IDETIFIER OP_DIVIDE_EQUAL Expression
					| IDETIFIER OP_MODULO_EQUAL Expression
					;

ArithmeticAssign 	: ArithmeticAssignExp ';'
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
IncrementExp		: OP_INCREMENT IDETIFIER {printInFile("Prefix increment Exp detected\n");}
					| IDETIFIER OP_INCREMENT {printInFile("Postfix increment Exp detected\n");}
					;

DecrementExp		: OP_DECREMENT IDETIFIER {printInFile("Prefix decrement Exp detected\n");}
					| IDETIFIER OP_DECREMENT {printInFile("Postfix decrement Exp detected\n");}
					;

Increment			: IncrementExp ';' {printInFile("increment detected\n");}
					;

Decrement			: DecrementExp ';' {printInFile("decrement detected\n");}
					;

Return				: RETURN Expression ';'
					| RETURN ';'
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
					| '{' Statement '}'
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
					|
					;


FunctionCallExp		: IDETIFIER '(' Arguments ')'
FunctionCall		: FunctionCallExp ';'

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
					| DOUBLE
					| CHARACTER
					| STRING
					| BOOLEAN
					;

DataType			: INTEGER
					| FLOAT
					| DOUBLE
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