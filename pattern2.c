#include<stdio.h>

void pattern1(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
        {
            for(j=n;j>=i;j--)
                printf("%d",j);
            printf("\n");
        }

}

void main()
{   int k;
    printf("Enter the value \n");
    scanf("%d",&k);
    pattern1(k);
}
