%{
    #include <stdio.h>
    #include <stdlib.h>
%}

%%

"int"         { printf("Keyword: int\n"); }
[a-zA-Z]+     { printf("Identifier: %s\n", yytext); }
[0-9]+        { printf("Integer: %s\n", yytext); }
"="           { printf("Operator: =\n"); }
";"           { printf("Semicolon: ;\n"); }
"+"           { printf("Operator: +\n"); }
"-"           { printf("Operator: -\n"); }
"*"           { printf("Operator: *\n"); }
"/"           { printf("Operator: /\n"); }
"("           { printf("Left Parenthesis: (\n"); }
")"           { printf("Right Parenthesis: )\n"); }
[ \t\n]+      { /* Ignore whitespace */ }
.             { printf("Unknown character: %s\n", yytext); }

%%

int main() {
    printf("Enter an expression like: int a = b / c;\n> ");
    yylex();  // Start Lexical analysis
    return 0;
}

int yywrap() {
    return 1;
}
