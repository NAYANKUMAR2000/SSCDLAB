%{
#include<stdio.h>
int sl=0;
int ml=0;
%}
%%
"/*"[a-zA-Z0-9' '\t\n%d",&();]+"*/" 	ml++;
"//".*	sl++;
%%
main()
{
yyin=fopen("a.c","r");
yyout=fopen("b.c","w");
yylex();
fclose(yyin);
fclose(yyout);
printf("\nNumber of Single line comments are = %d\n",sl);
printf("\nNumber of multiline comments are =%d\n",ml);
}
