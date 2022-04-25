%{
	int yylex();
	void yyerror(const char *s);
	#include <stdlib.h>
	#include <stdio.h>
%}


%union {int int_type;}

/* Keywords tokens*/
%token IF ELSE FOR WHILE DO SWITCH CASE BREAK CONTINUE RETURN 

/* Data types tokens*/
%token INTEGER CHARACTER FLOAT STRING DOUBLE BOOLEAN CONSTANT VOID

%token T_BoolConstant

%%
builder: INTEGER;
%%

void yyerror (char const *s) {
	fprintf (stderr, "%s\n", s);
}