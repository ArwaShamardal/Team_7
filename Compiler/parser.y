%{


	int yylex();
	void yyerror(const char *s);
	#include "semanticAnalyzer.h"
	#include "WritingQuadruples.h"

	char* currentName;
	float data_float;
	int currentScope = 0;
	int currentDataTypeNumber;
	int yylineno;
	struct entry* currentEntry = NULL;
	extern struct entry** mainTable;
	struct table* tableList;


	int yylex(void);
	#define maxLinesToParse 256
	extern FILE * yyin;
    FILE * f1;
	FILE * f2;
	int lineCount=0;
	char outputMessages [maxLinesToParse][maxLinesToParse];
	int isLeftSide = 0;
	int isDeclaration = 0; 

	

	struct entry * insert( char *name, int value, int data_type, struct entry** mainTable);
	struct entry * YaccInsert(char* currentName,double number,int typeNumber,struct entry ** mainTable);
	void printInFile(char message[maxLinesToParse]);
	void type_check(int,int,int);
	/* void WriteQuadruple(char *); */
%}





%start program


%code requires {
    struct node {
        float value;
        int type;
    };
}

%union
	{
		struct node node;
		float float_type;
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
%type <node> ValueTypeAll Expression ValueTypeLetter ValueTypeNumber 

%type <data_type> FunctionCallExp DataType VarDeclaration OneLineDeclaration VAL_INTEGER VAL_FLOAT
%type <float_type> ArithmeticExp















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
					| '{' Statement '}' Starter							
					| BREAK ';' Starter
					| CONTINUE ';' Starter
					|
					;

OneLineDeclaration	: AssignExp ',' OneLineDeclaration
					| AssignExp ';' 							
					| IDETIFIER ',' OneLineDeclaration          
					| IDETIFIER ';' 							{ 	currentEntry = YaccInsert(currentName,0,currentDataTypeNumber,mainTable);
																}
					;

VarDeclaration		: DataType OneLineDeclaration 			{	
																if(currentEntry!= NULL) {	
																	isDeclaration = 1; 
																	/* write_declaration("MOV", currentName, "-", "-"); */


																	printf("Variable Defined succefully\n");
																}
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

ArithmeticExp		: Expression '+' Expression 										{ type_check($1.type, $3.type,0); $$ = $1.value + $3.value;

																							write_arithmetic("ADD", currentName, $1.value, $3.value);

																						// WriteQuadruple("ADD "); WriteQuadruple(currentName);
																						//   char* text1;
																						  //gcvt($1.value, 6, text1);

																						  //itoa(7, text1,10);
																						   //sprintf(text1, "%f", $1.value);
																						//   printf("the text 1 value is: %s" ,text1);
																						 //WriteQuadruple(text1);


																						  //WriteQuadruple(text2); WriteQuadruple("\n");
																						 }																			
					| Expression '-' Expression											{ 
																							type_check($1.type, $3.type,0); $$ = $1.value - $3.value;
																							write_arithmetic("SUB", currentName, $1.value, $3.value);
																						}						
					| Expression '*' Expression											{ 
																							type_check($1.type, $3.type,0); $$ = $1.value * $3.value;
																							write_arithmetic("MUL", currentName, $1.value, $3.value);
																						}
					| Expression '/' Expression											{
																							 type_check($1.type, $3.type,0); $$ = $1.value / $3.value;
																							 write_arithmetic("DIV", currentName, $1.value, $3.value);
																						}
					| Expression '%' Expression											{ 
																							type_check($1.type, $3.type,0); $$ = fmod($1.value,$3.value);
																							write_arithmetic("MOD", currentName, $1.value, $3.value);
																						}
					| '-' Expression %prec OP_LOGICAL_NOT								{$$ = -($2.value); write_mov("NEG", currentName, $2.value, "-");}			
					;

RelationalExp		: Expression OP_EQUALITY Expression									{write_arithmetic("EQ", currentName, $1.value, $3.value);}
					| Expression OP_INEQUALITY Expression								{write_arithmetic("NEQ", currentName, $1.value, $3.value);}
					| Expression OP_GREATER_OR_EQUAL Expression							{write_arithmetic("GEQ", currentName, $1.value, $3.value);}
					| Expression OP_LESS_OR_EQUAL Expression							{write_arithmetic("LEQ", currentName, $1.value, $3.value);}
					| Expression OP_GREATER_THAN Expression								{write_arithmetic("GRT", currentName, $1.value, $3.value);}
					| Expression OP_LESS_THAN Expression								{write_arithmetic("LSS", currentName, $1.value, $3.value);}
					;	

LogicalExp			: Expression OP_LOGICAL_OR Expression
					| Expression OP_LOGICAL_AND Expression
					| OP_LOGICAL_NOT Expression
					;




AssignExp			: IDETIFIER '=' Expression 	 								{ 	
																					if(isDeclaration){												
																						printf("before mov");
																						currentEntry = YaccInsert(currentName,0,currentDataTypeNumber,mainTable);
																						currentEntry->value = $3.value;
																						$1 = currentEntry;
																						isDeclaration = 0;
																						write_mov("MOV", currentName,  currentEntry->value, "-");
																					}	
																				}			
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
WhileLoop			: WHILE '(' Expression ')' '{' Statement '}' 				{ printInFile("While Loop constructed successfully\n");}
					;

DoWhileLoop			: DO '{' Statement '}' WHILE '(' Expression ')' ';' 		{printf("do while reached\n"); printInFile("Do while Loop constructed successfully\n");}
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

ValueTypeNumber		: VAL_INTEGER 								{ 	$$.value = $1; $$.type = INTEGER; }																			
					| VAL_FLOAT									{ 	$$.value = data_float; $$.type = FLOAT;
																	
																} 								
					;

ValueTypeLetter		: VAL_BOOLEAN							
					| VAL_CHAR									
					| VAL_STRING								
					;

ValueTypeAll		: ValueTypeNumber 									
					| ValueTypeLetter
					;

DataTypeNoVoid		: INTEGER 									{currentDataTypeNumber = INTEGER; }
					| FLOAT										{currentDataTypeNumber = FLOAT;}
					| CHARACTER									{currentDataTypeNumber = CHARACTER;}
					| STRING									{currentDataTypeNumber = STRING;}
					| BOOLEAN									{currentDataTypeNumber = BOOLEAN;}
					;

DataType			: INTEGER 									{currentDataTypeNumber = INTEGER; $$ = INTEGER;}
					| FLOAT										{currentDataTypeNumber = FLOAT; $$ = FLOAT;}
					| CHARACTER									{currentDataTypeNumber = CHARACTER; $$ = CHARACTER;}
					| STRING									{currentDataTypeNumber = STRING; $$ = STRING;}
					| BOOLEAN									{currentDataTypeNumber = BOOLEAN; $$ = BOOLEAN;}
					| VOID										{currentDataTypeNumber = VOID; $$ = VOID;}
					;

%%

void type_check(int left, int right, int flag){
	if(left != right)
	{	
		switch(flag)
		{
			case 0: yyerror("Error: Type mismatch in arithmetic expression"); break;
			case 1: yyerror("Error: Type mismatch in assignment expression"); break;
			case 2: yyerror("Error: Type mismatch in logical expression"); break;
		}
	}
}

struct entry * YaccInsert(char* currentName,double number,int typeNumber,struct entry ** mainTable){
	currentEntry = insert(currentName,number,typeNumber,mainTable);
	if(currentEntry == NULL){
		yyerror("Error: Variable already declared in this scope");
	}
}

void yyerror (char const *s) {
	int value = yylineno + 1;
	printf ("%s in line number : %d\n", s, value);
	char errorString[256];
	strcpy(errorString,s);
	printInFile(errorString);
}

void printInFile(char message[maxLinesToParse]){
	strcpy(outputMessages[lineCount],message);
	lineCount++;
}

/* void WriteQuadruple(char* name )
{
	f2=fopen("WriteQuadruple.txt","a");
    fprintf(f2,name);
    fprintf(f2," ");

} */

int main(void) {
	fopen("WriteQuadruple.txt", "w");
	mainTable = Initialize();
    yyin = fopen("expressions.txt", "r");
	f1=fopen("output.txt","w");
	/* f2=fopen("WriteQuadruple.txt","w"); */
   if(!yyparse())
	{
		printf("\nParsing complete\n");
		for(int i=0; i<lineCount ; i++)
			fprintf(f1,outputMessages[i]);
		printTableData(tableList);	
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
