%{
#include<stdio.h>
%}

%%
[0-9]+ {printf("this is a digit");}
%%

int main(){
	yylex();
	return 0;
}

int yywrap(){
	return 1;
}