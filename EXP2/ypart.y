%{
#include<stdio.h>
#include<stdlib.h>
%}
//%token av bv
%%
S:A B'\n' {printf("Successful Grammar\n");exit(0);}
 ;
A:'a'A	{printf("A->aA\n");}
 |'a'	{printf("A->a\n");}
 ;
B:'b'	{printf("B->b\n");}
 ;
%%
#include"lex.yy.c"
main()
{
printf("Enter A String:");
yyparse();
yylex();
}
int yyerror()
{
printf("The given string is wrong \n");
exit(0);
}

