#include <stdio.h>
#include <string.h>
int compress(char [],char []);
int main()
{
    char s1[100];
    char s2[100];
    
    printf("Enter String to Compress:");
    scanf("%s",s1);
    
    compress(s1,s2);
    
    printf("Resulting String: %s\n",s2);
    
    return 0;
}

int compress(char str[],char result[])
{
    int len = strlen(str);
    int i = 0;
    int j = 0;
    
    while (i < len)
    {
        int count = 1;
        while (i < len - 1 && str[i] == str[i + 1])
        {
            count++;
            i++;
        }
        
        result[j++] = str[i];
        j += sprintf(&result[j], "%d", count);
        
        i++;
    }
    result[j] = '\0';
    
    if (strlen(result) >= len)
    {
        strcpy(result,str);
        return 0;
    }
    
    return 1;
}