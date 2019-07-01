#include<stdio.h>

void pattern3(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
        {for(j=1;j<=i;j++)
            printf("%d",j);
         for(j=i;j>=1;j--)
            printf("%d",j);
         printf("\n");
        }


}

void main()
{   int k;
    printf("Enter the value \n");
    scanf("%d",&k);
    pattern3(k);
}
