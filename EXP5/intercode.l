%{
#include "y.tab.h"
%}
%%
[0-9]+	{return digit;}
[a-zA-Z]+	{return id;}
[ \t] 	 ;
[\n]	{return 0;}
. {return yytext[0];}
%%
