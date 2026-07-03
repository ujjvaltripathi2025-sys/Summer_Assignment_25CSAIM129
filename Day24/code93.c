#include <stdio.h>
#include <string.h>
int rotation(char [],char []);
int main()
{
    char s1[100],s2[100];
    int result;
    
    printf("Enter First String:");
    scanf("%s",s1);
    
    printf("Enter Second String:");
    scanf("%s",s2);
    
    result = rotation(s1,s2);
    
    if (result == 1)
    {
        printf("Strings are Rotations of each other");
    }
    else
    {
        printf("Strings are not Rotations");
    }
    
    return 0;
}

int rotation(char str1[],char str2[])
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char temp[200];
    
    if (len1 != len2)
    {
        return 0;
    }
    
    strcpy(temp,str1);
    strcat(temp,str1);
    
    if (strstr(temp,str2) != NULL)
    {
        return 1;
    }
    
    return 0;
}