#include<stdio.h>
int main()
{
char ch;
int l,c,n,k,i,C[2020],m,j,maxc[20][20],alloc[20][20],sum=0,avail[20],need[20][20],p[20];
printf("\nHOW MANY PROCESSES ARE INVOLVED:");
scanf("%d",&n);
printf("\nNUMBER OF RESOURCES TYPE:");
scanf("%d",&m);
for(i=0;i<m;i++)
{
printf("\n AVAILABILITY OF RESOURCES OF TYPE R%d:",i);
scanf("%d",&C[i]);
}
 
for(i=0;i<n;i++)
 {
 for(j=0;j<m;j++)
  {
  printf("\nENTER THE MAX.CLAIM OF PROCESS P%d FOR RESOURCE TYPE R%d:",i,j);
  scanf("%d",&maxc[i][j]);
  }
 }


repeat:

for(i=0;i<n;i++)
 {
 for(j=0;j<m;j++)
  {
  printf("\nCURRENT ALLOCATION OF PROCESS P%d FOR RESOURCE TYPE R%d:",i,j);
  scanf("%d",&alloc[i][j]);
  }
 }

printf("\nTHE RESOURCES INITIALLY AVAILABLE\n");
for(i=0;i<m;i++)
{
 printf("%d\t",C[i]);
}
printf("\n\n"); 

printf("MAXIMUM CLAIM OF EACH PROCESSES ON EACH RESOURCES\n");
for(i=0;i<n;i++)
{
 for(j=0;j<m;j++)
  {
  printf("%d\t",maxc[i][j]);
  }
 printf("\n");
}
printf("\n");
printf("CURRENT ALLOCATION STATUS OF EACH PROCESSES\n");
for(i=0;i<n;i++)
{
 for(j=0;j<m;j++)
  {
  printf("%d\t",alloc[i][j]);
  }
 printf("\n");
}
printf("\n\n");

printf("CURRENT AVAILABILITY OF EACH RESOURCES\n");
for(i=0;i<m;i++)
 {
 sum=0;
 for(j=0;j<n;j++)
  {
   sum=sum+alloc[j][i];
  }
 avail[i]=C[i]-sum;
 printf("%d\t",avail[i]);
 }
printf("\n\n");

for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
  need[i][j]=maxc[i][j]-alloc[i][j];
  }
 }
c=0;
for(i=0;i<n;i++)
 {
 p[i]=0;
 }
for(l=0;l<n;l++)
 {
  for(i=0;i<n;i++)
  {
   j=0;
   do
    {
    if(j==m)
      {
       if(p[i]==0)
        {
   	c=c+1;
   	printf("\n\n");
 	printf("SELECT PROCESS:%d\t",i);
  	p[i]=1;
   	j=j+1;
   	for(k=0;k<m;k++)
    	  {
    	  avail[k]=avail[k]+alloc[i][k];
          alloc[i][k]=0;
         // maxc[i][k]=0;
          }
        printf("\nTHE AVAILABILITY OF EACH PROCESS AFTER THE EXECUTION OF PROCESS %d\n",i);
        for(k=0;k<m;k++)
         {
         printf("%d\t",avail[k]);
         } 
       }
      else
        break;
     }
    else
     {
     j=j+1;
     }
   }while((avail[j-1]>=need[i][j-1])&&(j<=m));
 // printf("\n");
  }
// printf("\n");
 }
if(c!=n)
 {
 printf("\n");
 printf("THE SYSTEM IS IN UNSAFE STATE");
 }
else
 {
 printf("\nTHE SYSTEM IS IN SAFE STATE IF THE PROCESSES SELECTED IN THE ABOVE LISTED ORDER\n");
 }
 printf("\nDo you want to Continue(Y/N)");
 scanf("%s",&ch);
 if((ch=='Y')||(ch=='y'))
  goto repeat;
 return 0;
}
