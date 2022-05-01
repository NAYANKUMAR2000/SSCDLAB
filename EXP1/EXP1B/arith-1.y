%{
#include<stdio.h>
int i;
%}
%token num
%left '+''-'
%left '*''/'
%right '^'
%nonassoc UMINUS
%%
S:E {printf("THE ANSWER IS=%d\n",$$);}
 ; 
E:E'+'E {$$=$1 + $3;}
 |E'-'E {$$=$1 - $3;}
 |E'*'E {$$=$1 * $3;}
 |E'/'E {$$=$1 / $3;}
 |'-'E %prec UMINUS {$$= -$2;}
 |'('E')' {$$=$2;}
 |E'^'E {
 		if($3==0)
			$$=1;
		else
		  {
			$$=1;
			for(i=1;i<=$1;i++)
				$$=$$*$3;
		  }
	    }
 |num {$$=$1;}
 ;
%%
#include"lex.yy.c"
#include<stdio.h>
int main()
{
printf("ENTER THE EXPRESSION TO EVALUATE:");
yyparse();
yylex();
return 1;
}
yyerror(char *s)
{
	printf("\nerror\n");
}
