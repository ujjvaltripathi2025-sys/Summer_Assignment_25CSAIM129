#include<stdio.h>
int main()
{
    int num1,num2,LCM;
    printf("Enter Two Numbers:");
    scanf("%d%d",&num1,&num2);
    LCM=(num1>num2)?num1:num2;

    while(1)
    {
        if(LCM%num1==0 && LCM%num2==0)
        {
            printf("LCM of %d and %d is = %d\n",num1,num2,LCM);
            break;
        }
        LCM++;
    }
    return 0;
}