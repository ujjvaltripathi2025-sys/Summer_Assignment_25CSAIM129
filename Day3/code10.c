#include<stdio.h>
int main()
{
    int i,n,prime;

    for(n=100;n<=500;n++)
    {
        prime=1;
        for(i=2;i<=n/2;i++)
        {
            if(n%i==0)
            {
                prime=0;
                break;
            }
        }
        if(prime==1)
        {
            printf("%d\t",n);
        }
    }
    return 0;

}