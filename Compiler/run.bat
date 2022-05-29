bison -dyv parser.y
flex lexical.l
gcc -c -o lex.yy.o lex.yy.c
gcc -c -o y.tab.o y.tab.c
g++ -c -o WritingQuadruples.o WritingQuadruples.cpp

g++ -o compiler.exe lex.yy.o y.tab.o WritingQuadruples.o 
compiler.exe