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

%union {
	int int_type;
	float float_type;
	double double_type;
	char* string_type;	/* or char[MAX] */
	char char_type;
	short bool_type;	/* C doesn't support bool data type */
	char var[32];
}
%start Starter

/* Keywords tokens*/
%token IF ELSE FOR WHILE DO SWITCH CASE BREAK CONTINUE RETURN SEMICOLON

/*Data types tokens*/
%token INTEGER CHARACTER FLOAT STRING DOUBLE BOOLEAN CONSTANT VOID

/* Variables/Values*/
%token <int_type>VAL_INTEGER
%token <float_type>VAL_FLOAT
%token <double_type>VAL_DOUBLE
%token <string_type>VAL_STRING
%token <char_type>VAL_CHAR
%token <bool_type>VAL_BOOLEAN
%token <var> IDETIFIER;

/*Short assignment operators*/
%token OP_INCREMENT OP_DECREMENT			/* ++ -- */

 /* Precedence and associativity */
%right OP_ADD_ASSIGN OP_SUB_ASSIGN OP_MUL_ASSIGN OP_DIV_ASSIGN OP_MOD_ASSIGN	/* += -= *= /= %= */
%right '='
%left OP_LOGICAL_OR							/* || */
%left OP_LOGICAL_AND						/* && */
%left OP_EQUALITY OP_INEQUALITY				/* == != */
%left OP_LESS_OR_EQUAL OP_GREATER_OR_EQUAL OP_LESS_THAN OP_GREATER_THAN 		/* <= >= < > */
%left '+' '-'
%left '*' '/' '%'
%right UMINUS								/* Unary minus (-) */

%left '(' ')'	 							/* Not sure */


/*Grammars are written in UpperCamelCase*/

%%

Starter 			: {printInFile("empty file\n");} | Assign
					;

Assign  			: IDETIFIER '=' ValueTypeAll ';' {printInFile("Assigned succefully\n");}
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
		/* return 0; */
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