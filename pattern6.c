#include<stdio.h>
c=1;
void pattern(n)
{
    int i,j;
    for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
                spacefun(i,n,c);
                printf("%d",j);
            printf("\n");
        }

}
void spacefun(int i,int n,int c)
{
    int p,q;
    p=(n-i)*c;
    for(q=1;q<=p;q++)
        printf("-");
}
void main()
{   int k;
    printf("Enter the value \n");
    scanf("%d",&k);
    pattern(k);
}
