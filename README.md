- The language lex and yacc recognizes in this project follows most of the `C`/`C++` languages.

- The language does not support any block statements without using of **curly braces** `{}`.

Example:

*supported*
```
for(int i = 0; i < 5; ++i) { <statements> }
```

*unsupported*
```
for(int i = 0; i < 5; ++i) <statement>
```

*and the same applies for other block statements.*


