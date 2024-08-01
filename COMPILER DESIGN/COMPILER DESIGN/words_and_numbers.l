%{
#include <stdio.h>
%}

%%
[0-9]+          { printf("Number: %s\n", yytext); }
[A-Za-z]+       { printf("Word: %s\n", yytext); }
[ \t\n]+        { }
.               { }
%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
