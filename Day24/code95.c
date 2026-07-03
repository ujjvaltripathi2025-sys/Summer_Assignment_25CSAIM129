#include<stdio.h>
#include<string.h>

int longest(char[],char[]);

int main()
{
    char s1[100];
    char s2[100];
    
    printf("Enter a Sentence: ");
    fgets(s1,sizeof(s1),stdin);
    s1[strcspn(s1,"\n")]='\0';
    
    longest(s1,s2);
    
    printf("Longest Word is: %s\n",s2);
    
    return 0;
}

int longest(char str[],char result[])
{
    int i;
    int len=strlen(str);
    int max_len=0;
    int cur_len=0;
    int start=0;
    int pos=0;
    
    for(i=0;i<=len;i++)
    {
        if(str[i]==' '||str[i]=='\0')
        {
            if(cur_len>max_len)
            {
                max_len=cur_len;
                pos=start;
            }
            cur_len=0;
            start=i+1;
        }
        else
        {
            cur_len++;
        }
    }
    
    for(i=0;i<max_len;i++)
    {
        result[i]=str[pos+i];
    }
    result[max_len]='\0';
    
    return max_len;
}