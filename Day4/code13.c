#include<stdio.h>
int main()
{
    int n,i,f1,f2,f3;
    printf("Enter Number of Terms:");
    scanf("%d",&n);

    f1=0;
    f2=1;
    printf("%d\t%d",f1,f2);

    for(i=1;i<=n-2;i++)
    {
        f3=f1+f2;
        printf("\t%d",f3);

        f1=f2;
        f2=f3;
    }
    return 0;
}