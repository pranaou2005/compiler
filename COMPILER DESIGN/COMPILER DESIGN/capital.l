%{
#include<stdio.h>
%}

%%
[A-Z]+ {printf("this is a capital letter");}
%%

int main(){
	yylex();
	return 0;
}

int yywrap(){
	return 1;
}