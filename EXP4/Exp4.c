#include<stdio.h>
#include<string.h>
int k=0,z=0,i=0,j=0,c=0;
char a[80],ac[20],stk[100],act[10];
void look();
void check();
int main()
{
printf("GRAMMAR is \n\tE->E+T/T \n\t T->T*F/F \n\t F->(E) \n\tF->id");
puts("\nenter input string ");
gets(a);
c=strlen(a);
strcpy(act,"SHIFT->");
puts("stack \t input \t action");
printf("\n$\t%s\tNULL",a);
for(k=0,i=0; j<c; k++,i++,j++)
{
if(a[j]=='i' && a[j+1]=='d')
{
stk[i]=a[j];
stk[i+1]=a[j+1];
stk[i+2]='\0';
a[j]=' ';

a[j+1]=' ';
printf("\n$%s\t%s$\t%sid",stk,a,act);
check();
}
else
{
stk[i]=a[j];
stk[i+1]='\0';
a[j]=' ';
printf("\n$%s\t%s$\t%ssymbols",stk,a,act);
check();
}
}
return 0;
}
void check()
{
strcpy(ac,"REDUCE TO F");
for(z=0; z<c; z++)
if(stk[z]=='i' && stk[z+1]=='d')
{
stk[z]='F';
stk[z+1]='\0';
printf("\n$%s\t%s$\t%s",stk,a,ac);
j++;
}
for(z=0; z<c; z++)
if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='T')
{strcpy(ac,"REDUCE TO E");
stk[z]='E';
stk[z+1]='\0';
stk[z+2]='\0';
printf("\n$%s\t%s$\t%s",stk,a,ac);
i=i-2;
}else
look();
for(z=0; z<c; z++)
if(stk[z]=='T' && stk[z+1]=='*' && stk[z+2]=='F')
{strcpy(ac,"REDUCE TO T");
stk[z]='T';
stk[z+1]='\0';
stk[z+1]='\0';
printf("\n$%s\t%s$\t%s",stk,a,ac);
i=i-2;
strcpy(ac,"REDUCE TO E");
stk[z]='E';
stk[z+1]='\0';
printf("\n$%s\t%s$\t%s",stk,a,ac);

}else
look();
for(z=0; z<c; z++)
if(stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')')
{strcpy(ac,"REDUCE TO F");
stk[z]='F';
stk[z+1]='\0';
stk[z+1]='\0';
printf("\n$%s\t%s$\t%s",stk,a,ac);
i=i-2;
}
look();
}
void look()
{
if(stk[z]=='F'&&stk[z+1]=='\0'&&a[j+1]=='\0')
{strcpy(ac,"REDUCE TO T");
stk[z]='T';
stk[z+1]='\0';
printf("\n$%s\t%s$\t%s",stk,a,ac);
strcpy(ac,"REDUCE TO E");
stk[z]='E';
stk[z+1]='\0';
printf("\n$%s\t%s$\t%s",stk,a,ac);
}

if(stk[z]=='F'&&a[j+1]=='*')
{strcpy(ac,"REDUCE TO T");
stk[z]='T';
stk[z+1]='\0';
printf("\n$%s\t%s$\t%s",stk,a,ac);
}// for(z=0,j=0;z<c;z++,j++)
if(stk[z]=='F'&&a[j+1]=='+')
{strcpy(ac,"REDUCE TO T");
stk[z]='T';
stk[z+1]='\0';
printf("\n$%s\t%s$\t%s",stk,a,ac);
strcpy(ac,"REDUCE TO E");
stk[z]='E';
stk[z+1]='\0';
printf("\n$%s\t%s$\t%s",stk,a,ac);

}
for(z=0;z<c;z++)
if(stk[z]=='E'&&stk[z+1]=='+'&&stk[z+2]=='F')
{strcpy(ac,"REDUCE TO T");
stk[z+2]='T';
//stk[z+1]='\0';
printf("\n$%s\t%s$\t%s",stk,a,ac);
check();
}
for(z=0;z<c;z++)
if(stk[z]=='('&&stk[z+1]=='E'&&stk[z+2]=='+'&&stk[z+3]=='F')
{strcpy(ac,"REDUCE TO T");
stk[z+2]='T';
//stk[z+1]='\0';
printf("\n$%s\t%s$\t%s",stk,a,ac);
check();
} for(z=0;z<c;z++)
if(stk[z]=='('&&stk[z+1]=='F'&&a[j+1]=='+')
{strcpy(ac,"REDUCE TO T");
stk[z]='(';
stk[z+1]='T';
printf("\n$%s\t%s$\t%s",stk,a,ac);
strcpy(ac,"REDUCE TO E");
stk[z]='(';
stk[z+1]='E';
printf("\n$%s\t%s$\t%s",stk,a,ac);
}for(z=0;z<c;z++)
if(stk[z]=='('&&stk[z+1]=='E'&&stk[z+2]=='+'&&stk[z+3]=='T'&&stk[z+4]==')')
{strcpy(ac,"REDUCE TO E");
stk[z]='(';
stk[z+1]='E';
stk[z+2]=')';
stk[z+3]='\0';
stk[z+4]='\0';
i=i-2;
printf("\n$%s\t%s$\t%s",stk,a,ac);
check();
}//for(z=0,j=0;z<c;j++,z++)
if(stk[z]=='F'&&stk[z+1]=='\0'&&a[j]=='\0')
{strcpy(ac,"REDUCE TO T");
stk[z]='T';
stk[z+1]='\0';
printf("\n$%s\t%s$\t%s",stk,a,ac);
}
}

