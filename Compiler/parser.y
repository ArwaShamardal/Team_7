%{
	int yylex();
	void yyerror(const char *s);
	#include <stdlib.h>
	#include <stdio.h>
%}


%union { int int_type; }

%token INTEGER

%%
builder: INTEGER;
%%

void yyerror (char const *s) {
	fprintf (stderr, "%s\n", s);
}