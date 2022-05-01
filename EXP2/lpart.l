%{
#include "y.tab.h"
%}
%%
a	{return 'a';}
b	{return 'b';}
[\n] {return '\n';}
[ \t] {;}
%%
