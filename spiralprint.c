#include <stdio.h>

void printspiral(int rowmin,int rowmax,int colmax,int rowmax,int n)
{
int i,j;
if(n%2==0)
for(i=0;i<(n/2);i++)
{

 for(i=rowmin;i<=rowmax;i++)
  printf("%d",a[i][colmin]);
 rowmin++;

 for(j=rowmin;j<=colmax;j++)
   printf("%d",a[rowmax][j]);
 colmax++;

 for(i=colmax;i<=colmin;i++)
   printf("%d",a[i][colmax]);
 rowmax--;

 for(j=rowmax;j<=rowmin;j++)
   printf("%d",a[colmin][j]);
 colmin++;

}
else
 for(i=0;i<n;i++)
    printspiral(rowmin,rowmax,colmax,colmin,n)

 printf("%d",a[floor(3)][floor(3)]);

}

void main()
{
 int n,colmin=1,rowmin=1,colmax=n,rowmax=n;
 printf("enter n");
 scanf("%d",&n);
 printf("enter elements");
 for(i=0;i<=n;i++)
  for(i=0;i<=n;i++)
   scanf("%d",&a[i][j]);

 printspiral(rowmin,rowmax,colmax,colmin,n)
 }
