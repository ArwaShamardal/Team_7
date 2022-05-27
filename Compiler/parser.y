%{


	int yylex();
	void yyerror(const char *s);
	#include "semanticAnalyzer.h"

	#define maxLinesToParse 256
	extern FILE * yyin;
    FILE * f1;
	int lineCount=0;
	char outputMessages [maxLinesToParse][maxLinesToParse];
	void printInFile(char message[maxLinesToParse]);
%}




%start program

%union
	{
		int data_type;
		struct entry* entry;
	}

/* Keywords tokens*/
%token IF ELSE FOR WHILE DO SWITCH CASE DEFAULT BREAK CONTINUE RETURN SEMICOLON 

/*Data types tokens*/
%token INTEGER CHARACTER FLOAT STRING DOUBLE BOOLEAN CONSTANT VOID

/* Variables/Values*/

%token VAL_INTEGER VAL_FLOAT VAL_DOUBLE VAL_STRING VAL_CHAR VAL_BOOLEAN
%token IDETIFIER














%type <entry> IDETIFIER

%type <data_type> ArithmeticExp Expression FunctionCallExp DataType VarDeclaration OneLineDeclaration















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


%nonassoc THEN
%nonassoc ELSE

/*Grammars are written in UpperCamelCase*/

%%
program 			: Starter
					;

Starter 			: Statement 
					| Function 
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

OneLineDeclaration	: AssignExp ',' OneLineDeclaration
					| AssignExp ';' 
					| IDETIFIER ',' OneLineDeclaration
					| IDETIFIER ';' {printEntry($1);}
					;

VarDeclaration		: DataType OneLineDeclaration 			{	
																printf("type number is : %d", $1 );
																printInFile("Variable Defined succefully\n");
															}
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

ArithmeticExp		: Expression '+' Expression 			{ printf(" %d\n", $1);} 						
					| Expression '-' Expression
					| Expression '*' Expression
					| Expression '/' Expression
					| Expression '%' Expression
					| '-' Expression %prec OP_LOGICAL_NOT	/* Let its precedence equate ! operator regarding the precedence table */
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


 /* Any 'Assign' written below is to be changed to a block of statements */

Function			: DataType IDETIFIER '(' Parameters ')' '{' Statement '}' {printInFile("Function constructed successfully\n");}
					;


 /* If conditon */
Condition			: IF '(' Expression ')' '{' Statement '}' %prec THEN
					| IF '(' Expression ')' '{' Statement '}' ELSE '{' Statement '}'
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

DataTypeNoVoid		: INTEGER {printf(" ss \n");}
					| FLOAT
					| DOUBLE
					| CHARACTER
					| STRING
					| BOOLEAN
					;

DataType			: INTEGER 									{$$ = INTEGER;}
					| FLOAT										{$$ = FLOAT;}
					| CHARACTER									{$$ = CHARACTER;}
					| STRING									{$$ = STRING;}
					| BOOLEAN									{$$ = BOOLEAN;}
					| VOID										{$$ = VOID;}
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
    yyin = fopen("test1.txt", "r");
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