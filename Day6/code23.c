#include<stdio.h>
int main()
{
    int n,count=0,temp;
    printf("Enter the Number:");
    scanf("%d",&n);
    temp=n;

    while(n>0)
    {
        if(n&1)
        {
            count=count+1;
        }
        n=n>>1;
    }
    printf("Total Number of Set bits in %d is = %d\n",temp,count);
    return 0;
}