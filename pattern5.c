#include<stdio.h>

void pattern(int n)
{
    int i,j,k;
    for(i=1;i<=n;i++)
        {
            for(k=1;k<=3;k++)
                for(j=1;j<=i;j++)
                  printf("%d",j);

            for(k=1;k<=3;k++)
                for(j=i;j>=1;j--)
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
