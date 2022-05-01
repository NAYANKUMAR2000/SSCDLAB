letter [a-zA-Z]
digit [0-9]
%%
{digit}+("E"("+"|"-")?{digit}+)? printf("\n %s \t is realnumber",yytext);
{digit}+"."{digit}+("E"("+"|"-")?{digit}+)? printf("\n %s \t is a float number",yytext);
"if"|"else"|"int"|"float"|"switch"|"case"|"struct"|"char"|"return"|"for"|"do"|"while"|"void"|"printf"|"scanf" {printf("\n %s \t is a keyword",yytext);}
"\t"|"\b"|"\\n"|"\\t"|"\\a"|"\\b"|"\a" {printf("\n %s \t is an escape sequences",yytext);}
{letter}({letter}|{digit})* {printf("\n %s \t is an identifier",yytext);}
"["|"]"|"{"|"}"|"("|")"|"#"|"'"|"""|"\"|"\\"|";"|"," {printf("\n %s \t is a special character",yytext);}
"&&"|"<"|">"|"<="|">="|"+"|"="|"-"|"?"|"/"|"||"|"*"|"&"|"%" {printf("\n %s \t is an operator",yytext);}
"%d"|"%s"|"%c"|"%f"|"%e" {printf("\n %s \t is a format specifier",yytext);}
%%
int yywrap()
{
	return 1;
}
int main(int argc, char *argv[])
{
	yyin=fopen(argv[1],"r");
	yylex();
	fclose(yyin);
	return 0;
}
