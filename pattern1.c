#include<stdio.h>

void pattern(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
                printf("%d",j);
            printf("\n");
        }

}

void main()
{   int k;
    printf("Enter the value \n");
    scanf("%d",&k);
    pattern(k);
}
