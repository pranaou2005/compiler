%{
#include<stdio.h>
%}

%%
^[7-9][0-9]{9} {printf("this is a valid number");}
[0-9]+ {printf("this is not a valid number");}
%%

int main(){
	yylex();
	return 0;
}

int yywrap(){
	return 1;
}