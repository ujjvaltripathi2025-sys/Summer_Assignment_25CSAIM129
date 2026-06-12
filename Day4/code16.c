#include<stdio.h>
int main()
{
    int num1,num2,n,i,sum,d;
    printf("Enter Starting Limit:");
    scanf("%d",&num1);

    printf("Enter Ending Limit:");
    scanf("%d",&num2);

    printf("Armstrong Number in the given range are : \n");
    for(i=num1;i<=num2;i++)
    {
        n=i;
        sum=0;

        while(n>0)
        {
            d=n%10;
            sum=sum+(d*d*d);
            n=n/10;
        }
        if(sum==i)
        {
            printf("%d\t",i);
        }
    }
    return 0;
    

}