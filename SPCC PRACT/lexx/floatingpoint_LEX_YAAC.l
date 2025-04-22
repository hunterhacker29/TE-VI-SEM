%{
    #include <stdio.h>
    #include <stdlib.h>
%}
%%
[0-9]+.[0-9]+           { printf("FLOATING POINT: %s\n", yytext); }
[0-9]+                   { printf("INTEGER: %s\n", yytext); }
.                        { printf("INVALID INPUT: %s\n", yytext); }
%%
int main() {
    printf("Enter input: ");
    yylex();  
    return 0;
}
int yywrap() {
    return 1;
}
