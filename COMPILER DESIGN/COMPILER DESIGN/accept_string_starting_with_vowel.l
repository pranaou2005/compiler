%{
#include <stdio.h>
%}

%%
^[AEIOUaeiou][a-zA-Z]* {
    printf("Valid string: %s\n", yytext);
}
^[^AEIOUaeiou]+ {printf("INVALID: %s",yytext);}
%%

int main(void) {
    printf("Enter a string: ");
    yylex();
    return 0;
}
int yywrap(){
    return 1;
}