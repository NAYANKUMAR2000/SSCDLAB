%{
#include<stdio.h>
//#include<ctype.h>
#include<string.h>
%}
%token id digit  //named token
%left '+''-'      
%left '*''/'
%left '^'
%right'='
%nonassoc UMINUS
%%
S:id {push();}'='E {pop();}
E:E'+' {push();}T {pop3();}
   |E'-' {push();}T {pop3();}
   |T
   ;
T:T'*' {push();}F {pop3();}
   |T'/' {push();}F {pop3();}
   |T'^'{push();}F {pop3();}
   |F
   ;
F:id {push();}
  |digit {push();}
  |'('E')'
  |'-' {push();}F {pop2();} %prec UMINUS
  ;
%%
#include"lex.yy.c"
char stack[10][10],var[10]="\0",temp[10]="\0";
int top=0,charlength;
char i='0';
//FILE *yyin,*fp2;
FILE *fp1,*fp2;
char op[2];


char line_buffer[100], Instruction[5][3];
int main(int argc, char *argv[])
{
	yyin=fopen("data.txt","r");
	fp1=fopen("input.txt","w");	
	fp2=fopen("output.txt","w");
	yyparse();
	yylex();
	fclose(yyin);
	fclose(fp1);
	yyin=fopen("input.txt","r");
	assembly();
	fclose(yyin);
	fclose(fp2);
	return 0;
}

yyerror(char *s)
{
 	printf("%s\n",s);
}

push()
{
	top++;
	strcpy(stack[top],yytext);
}

pop3()
{
	printf("t%c=%s%s%s\n",i,stack[top-2],stack[top-1],stack[top]);
	fprintf(fp1,"t%c = %s %s %s\n",i,stack[top-2],stack[top-1],stack[top]);
	top=top-2;
	temp[0]=i;
	strcpy(var,"t");
	strcat(var,temp);
	strcpy(stack[top],var);
	i++;
}

pop()
{
	printf("%s=%s\n",stack[top-1],stack[top]);
	fprintf(fp1,"%s = %s\n",stack[top-1],stack[top]);
}

pop2()
{
	printf("t%c=%s%s",i,stack[top-1],stack[top]);
	fprintf(fp1,"t%c = %s%s\n",i,stack[top-1],stack[top]);
	top--;
	temp[0]=i;
	strcpy(var,"t");
	strcat(var,temp);
	strcpy(stack[top],var);
	i++;
}
assembly()
{
char line[100],operand[3][3];
int i,j,k,count,l;
count=1;
while(fgets(line, sizeof(line), yyin)!=NULL)
	{
  		i=0;
		j=0;
		k=0;
		operand[0][0]='\0';
		op[0]='\0';
		while(line[i]!='\0')
		{
		    if((line[i]=='+')||(line[i]=='-')||(line[i]=='*')||(line[i]=='/'))
		     {	
		    		op[0]=line[i];  	
			  	op[1]='\0';
		    		operand[k][j]='\0';
		    		k++;
		    		j=0;
		    		i++;
		    	}
		    else if(line[i]=='=')
			  {
			     operand[k][j]='\0';
			     k++;
			     j=0;
			  	i++;
			  }		    	
			if(line[i]!=' ')
			  {
			  	operand[k][j] = line[i];
				i++;
				j++;			
			  }
			else 
			  {
				  i++;	
			  }			
		}
		operand[k][j]='\0';
		//printf("%d: %s = %s %s %s\n",count,operand[0],operand[1],op,operand[2]);
		count++; 		
		if(strcmp(op,"+")==0)
		{
			fprintf(fp2,"MOV R0,%s\n",operand[1]);
			fprintf(fp2,"ADD R0,%s",operand[2]);
			fprintf(fp2,"MOV %s,R0\n",operand[0]);			
		}
		else if(strcmp(op,"*")==0)
		{
			fprintf(fp2,"MOV R0,%s\n",operand[1]);
			fprintf(fp2,"MUL R0,%s",operand[2]);
			fprintf(fp2,"MOV %s,R0\n",operand[0]);
		}
		else if(strcmp(op,"-")==0)
		{
			if(operand[1][0]=='\0')
				{
					fprintf(fp2,"MOV R0,-%s",operand[2]);
					fprintf(fp2,"MOV %s,R0\n", operand[0]);
				}
			else {
					fprintf(fp2,"MOV R0,%s\n",operand[1]);
					fprintf(fp2,"SUB R0,%s",operand[2]);
					fprintf(fp2,"MOV %s,R0\n",operand[0]);
				}		
		}
		else if(strcmp(op,"/")==0)
		{
			fprintf(fp2,"MOV R0,%s\n",operand[1]);
			fprintf(fp2,"DIV R0,%s",operand[2]);
			fprintf(fp2,"MOV %s,R0\n",operand[0]);
		}
		else if(operand[2][0]=='\0')
		{
			fprintf(fp2,"MOV R0,%s",operand[1]);
			fprintf(fp2,"MOV %s,R0\n",operand[0]);
		}	
	}
}
