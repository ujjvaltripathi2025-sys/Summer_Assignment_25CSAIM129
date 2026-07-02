#include <stdio.h>
#include <string.h>

int main()
{
    char str[100],max_char;
    int i,j,current_count,max_count;

    printf("Enter the String: ");
    scanf("%s",str);

    max_count = 0;
    max_char = str[0];

    for(i = 0;str[i] != '\0';i++)
    {
        current_count = 0;

        for(j = 0;str[j] != '\0';j++)
        {
            if(str[i] == str[j])
            {
                current_count++;
            }
        }

        if(current_count > max_count)
        {
            max_count = current_count;
            max_char = str[i];
        }
    }

    printf("The Maximum Occurring Character is = %c in Word = %s",max_char,str);
    return 0;
}