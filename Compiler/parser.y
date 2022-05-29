%{


	int yylex();
	void yyerror(const char *s);

	#include "semanticAnalyzer.h"
	#include "WritingQuadruples.h"



	char* currentName;
	float data_float;
	char data_char;
	short data_bool;
	int currentScope = 0;
	int currentDataTypeNumber;
	int yylineno;
	int found = 0;
	struct entry* currentEntry = NULL;
	extern struct entry** mainTable;
	struct table* tableList;


	int yylex(void);
	#define maxLinesToParse 256
	extern FILE * yyin;
    FILE * f1;
	int lineCount=0;
	char outputMessages [maxLinesToParse][maxLinesToParse];
	int rightHandSide = 0;
	int isDeclaration = 0; 

	
	bool findEntry(char* myEntry);
	struct entry * insert( char *name, int value, char character, short boolean, int data_type, struct entry** mainTable);
	struct entry * YaccInsert(char* currentName,double number, char character, short boolean, int typeNumber,struct entry ** mainTable);
	void printInFile(char message[maxLinesToParse]);
	void type_check(int,int,int);
%}





%start program


%code requires {
    struct node {
        float value;
		char char_value;
		short bool_value;
        int type;
    };
}

%union
	{
		struct node node;
		float float_type;
		char char_type;
		short bool_type;
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














%type <entry> IDETIFIER LHS
%type <node> ValueTypeAll Expression ValueTypeLetter ValueTypeNumber 

%type <data_type> FunctionCallExp DataType VarDeclaration OneLineDeclaration VAL_INTEGER VAL_FLOAT
%type <float_type> ArithmeticExp
%type <bool_type> RelationalExp LogicalExp
 /* %type <char_type>   */















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
					| Function Starter
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
					| Return Starter
					| '{' {currentScope = CreateTable();} Statement '}' {currentScope = ExitingTable();} Starter							
					| BREAK ';' Starter
					| CONTINUE ';' Starter
					|
					;

OneLineDeclaration	: AssignExp ',' OneLineDeclaration
					| AssignExp ';' 							
					| LHS ',' OneLineDeclaration          
					| LHS ';'	
					;

VarDeclaration		: DataType OneLineDeclaration 			{	
																if(currentEntry!= NULL){	
																	isDeclaration = 0; 
																	printInFile("Variable Defined succefully\n");
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
					| LHS 																{rightHandSide=1; isDeclaration=0;
																						if($1 != NULL){
																							$$.type = $1->data_type; $$.char_value = $1->char_value; $$.bool_value = $1->bool_value; 
																						}}																			
					;

ArithmeticExp		: Expression '+' Expression 										{ type_check($1.type, $3.type,0); $$ = $1.value + $3.value;

																							write_arithmetic("ADD", currentName, $1.value, $3.value);

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

RelationalExp		: Expression OP_EQUALITY Expression{$$ = $1.bool_value == $3.bool_value; write_arithmetic("EQ", currentName, $1.bool_value, $3.bool_value);}
					| Expression OP_INEQUALITY Expression{$$ = $1.bool_value != $3.bool_value; write_arithmetic("NEQ", currentName, $1.bool_value, $3.bool_value);}
					| Expression OP_GREATER_OR_EQUAL Expression{ $$ = $1.bool_value >= $3.bool_value; write_arithmetic("GEQ", currentName, $1.bool_value, $3.bool_value);}
					| Expression OP_LESS_OR_EQUAL Expression{ $$ = $1.bool_value <= $3.bool_value; write_arithmetic("LEQ", currentName, $1.bool_value, $3.bool_value);}
					| Expression OP_GREATER_THAN Expression{ $$ = $1.bool_value > $3.bool_value; write_arithmetic("GRT", currentName, $1.bool_value, $3.bool_value);}
					| Expression OP_LESS_THAN Expression{$$ = $1.bool_value < $3.bool_value; write_arithmetic("LSS", currentName, $1.bool_value, $3.bool_value);}

					;	

LogicalExp			: Expression OP_LOGICAL_OR Expression{$$ = $1.bool_value || $3.bool_value; write_arithmetic("OR", currentName, $1.bool_value, $3.bool_value);}
					| Expression OP_LOGICAL_AND Expression{$$ = $1.bool_value && $3.bool_value; write_arithmetic("AND", currentName, $1.bool_value, $3.bool_value);}
					| OP_LOGICAL_NOT Expression{$$ = !($2.bool_value); write_mov("NOT", currentName, $2.bool_value, "-");}
					;




AssignExp			: LHS AssignOperator Expression 	 						{ 	rightHandSide = 0;
																					// found = findEntry(currentName);
																					// printf("found %d\n", found);
																					if($1 != NULL)
																						{
																							$1->value = $3.value;
																							$1->char_value = $3.char_value;
																							$1->bool_value = $3.bool_value;

																							if($3.type == 0){
																								type_check($1->data_type, $3.type,3);
																							}
																							else{
																								type_check($1->data_type, $3.type,1);
																							}

																							// printf("found %s\n", currentName);
																						}
																					else{
																							$1 = NULL;
																							yyerror("Error: Variable not declared yet");
																							// printf("not found %s\n", currentName);
																						}
																				}			
					;



LHS 				: IDETIFIER 													{
																					if(isDeclaration==1 && rightHandSide==0){
																						currentEntry = YaccInsert(currentName,0, '\0', 0,  currentDataTypeNumber,tableList[currentScope].symbolTable);
																						$1 = currentEntry;
																						isDeclaration = 0;
																						$$ = $1;
																						write_mov("MOV", currentName,  currentEntry->value, "-");

																					}
																					else{
																						currentEntry = searchReturnEntry(currentName);
																						if(currentEntry!=NULL)
																						{	$1 = currentEntry;
																							$$ = $1;
																						}
																						else{
																							$1 = NULL;
																							$$ = $1;
																						}

																					}
																					}

					;					

Assign  			: AssignExp ';' {printInFile("Assigned succefully\n");}
					;

AssignOperator		: '='											{rightHandSide = 1;}
					| OP_PLUS_EQUAL 								{rightHandSide = 1;}
					| OP_MINUS_EQUAL								{rightHandSide = 1;}
					| OP_MULTIPLY_EQUAL								{rightHandSide = 1;}
					| OP_DIVIDE_EQUAL								{rightHandSide = 1;}
					| OP_MODULO_EQUAL								{rightHandSide = 1;}
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

Function			: DataType IDETIFIER '(' {currentScope = CreateTable();} Parameters ')' '{'   Statement '}'  {currentScope = ExitingTable(); printInFile("Function constructed successfully\n");}
					;


 /* If conditon */
Condition			: IF '(' Expression ')' '{' Statement '}'    %prec THEN
					| IF '(' Expression ')' '{'  Statement '}'    ELSE '{'   Statement '}' 
					| IF '(' Expression ')' '{'  Statement '}'   ELSE Condition
    				;


 /* loops */
WhileLoop			: WHILE '(' Expression ')' '{' {currentScope = CreateTable();} Statement '}' {currentScope = ExitingTable();} 				{ printInFile("While Loop constructed successfully\n");}
					;

DoWhileLoop			: DO '{' {currentScope = CreateTable();} Statement '}' {currentScope = ExitingTable();} WHILE '(' Expression ')' ';' 		{printf("do while reached\n"); printInFile("Do while Loop constructed successfully\n");}
					;


ForLoopInit			: VarDeclaration 
 					| Assign 
					;

ForLoop				: FOR {currentScope = CreateTable();} '(' ForLoopInit Expression ';' Expression')' '{'  Statement '}'     {currentScope = ExitingTable();  printInFile("For Loop constructed successfully\n");}
					;

SwitchValueTypes	: VAL_INTEGER
					| VAL_CHAR
					;

Case				: CASE SwitchValueTypes ':' Statement Case
					| DEFAULT ':' Statement
					|
					;

SwitchCase			: SWITCH '(' IDETIFIER ')' '{'    {currentScope = CreateTable();}     Case '}'   	{ currentScope = ExitingTable();  printInFile("Switch case constructed successfully\n");}
					;


Parameters			: DataType LHS ',' DataType LHS 
					| DataType LHS
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
					| VAL_FLOAT									{ 	$$.value = data_float; $$.type = FLOAT;} 								
					;

ValueTypeLetter		: VAL_BOOLEAN								{ 	$$.bool_value = data_bool;  $$.type = BOOLEAN;} 
					| VAL_CHAR									{ 	$$.char_value = data_char;  $$.type = CHARACTER;} 
					| VAL_STRING								
					;

ValueTypeAll		: ValueTypeNumber 									
					| ValueTypeLetter
					;


DataType			: INTEGER 									{isDeclaration=1; currentDataTypeNumber = INTEGER; $$ = INTEGER;}
					| FLOAT										{isDeclaration=1; currentDataTypeNumber = FLOAT; $$ = FLOAT;}
					| CHARACTER									{isDeclaration=1; currentDataTypeNumber = CHARACTER; $$ = CHARACTER;}
					| STRING									{isDeclaration=1; currentDataTypeNumber = STRING; $$ = STRING;}
					| BOOLEAN									{isDeclaration=1; currentDataTypeNumber = BOOLEAN; $$ = BOOLEAN;}
					| VOID										{isDeclaration=1; currentDataTypeNumber = VOID; $$ = VOID;}
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
			case 3: yyerror("Error: Type mismatch, variable no longer exists"); break;
		}
	}
}


bool findEntry(char* myEntryName){
	bool find = searchInCurrentAndParent(myEntryName);
	if(find)
	{
		return true;
	}
	else{
		yyerror("Error: Could not find variable");
		return false;
	}
}

struct entry * YaccInsert(char* currentName,double number, char character, short boolean, int typeNumber,struct entry ** mainTable){
	currentEntry = insert(currentName,number, character, boolean, typeNumber,mainTable);
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


int main(void) {
	fopen("WriteQuadruple.txt", "w");
	mainTable = Initialize();
    yyin = fopen("test1.txt", "r");
	f1=fopen("output.txt","w");
   if(!yyparse())
	{
		printf("\nParsing complete\n");
		for(int i=0; i<lineCount ; i++)
			fprintf(f1,outputMessages[i]);
		printTableData(tableList);	
		printf("current scope index is %d\n",currentScope);
		struct entry* test = searchReturnEntry("y");
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
