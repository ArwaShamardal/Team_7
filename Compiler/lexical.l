/*** Definition Section has one variable
which can be accessed inside yylex()
and main() ***/
%{
int count = 0;
%}

/*** Rule Section has three rules, first rule (regex)
matches with capital letters, second rule
matches with any character except newline and
third rule does not take input after the enter***/
%%
int | 
float |
char |
string |
double |
bool |
void |
if |
else |
for |
while |
do |
switch |
case |
const |
break |
continue |
true |
false |
exit {printf("%s was entered \n", yytext);}
\+ |
- |
\* |
\/ |
! |
> |
\< |
== |
!= |
>= |
\<= |
\|\| |
&& |
\{ |
\} |
\( |
\) |
\/\/ |
\[ |
\] |
\\t |
\\n |
[ ] |
; |
: |
, |
\. {printf("%s was entered \n", yytext);}
([0-9]*\.[0-9]+)|([0-9]+\.[0-9]+)|([1-9][0-9]*) {printf("%s was entered \n", yytext);}


%%

/*** Code Section prints the number of
capital letter present in the given input***/  // (C code)
int yywrap(){}
int main(){

// Explanation:
// yywrap() - wraps the above rule section
/* yyin - takes the file pointer
		which contains the input*/
/* yylex() - this is the main flex function
		which runs the Rule Section*/
// yytext is the text in the buffer

// Uncomment the lines below
// to take input from file
// FILE *fp;
// char filename[50];
// printf("Enter the filename: \n");
// scanf("%s",filename);
// fp = fopen(filename,"r");
// yyin = fp;

yylex();
printf("\nNumber of Capital letters "
	"in the given input - %d\n", count);

return 0;
}
