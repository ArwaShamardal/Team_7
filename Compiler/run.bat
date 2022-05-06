bison -dyv parser.y
flex lexical.l
gcc lex.yy.c y.tab.c -o compiler.exe
compiler.exe