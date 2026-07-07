#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int choice, i, j, length1, length2, match;
    char str1[200], str2[100];

    while (1) 
    {
        printf("\n=== STRING OPERATIONS MENU ===\n");
        printf("1. Find String Length\n");
        printf("2. Copy String\n");
        printf("3. Concatenate (Join) Strings\n");
        printf("4. Compare Two Strings\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        getchar(); 

        if (choice == 5) 
        {
            printf("Exiting program. Goodbye!\n");
            exit(0);
        }

        switch (choice) 
        {
            case 1:
                printf("Enter a string: ");
                scanf("%[^\n]", str1);
                
                length1 = 0;
                while (str1[length1] != '\0') 
                {
                    length1++;
                }
                printf("Length of the string: %d\n", length1);
                break;

            case 2:
                printf("Enter source string to copy: ");
                scanf("%[^\n]", str1);
                
                i = 0;
                while (str1[i] != '\0') 
                {
                    str2[i] = str1[i];
                    i++;
                }
                str2[i] = '\0';
                printf("Destination string after copy: %s\n", str2);
                break;

            case 3:
                printf("Enter first string: ");
                scanf("%[^\n]", str1);
                getchar(); 
                printf("Enter second string: ");
                scanf("%[^\n]", str2);
                
                i = 0;
                while (str1[i] != '\0') 
                {
                    i++;
                }
                
                j = 0;
                while (str2[j] != '\0') 
                {
                    str1[i] = str2[j];
                    i++;
                    j++;
                }
                str1[i] = '\0';
                printf("Concatenated string: %s\n", str1);
                break;

            case 4:
                printf("Enter first string: ");
                scanf("%[^\n]", str1);
                getchar(); 
                printf("Enter second string: ");
                scanf("%[^\n]", str2);
                
                i = 0;
                match = 1;
                while (str1[i] != '\0' || str2[i] != '\0') 
                {
                    if (str1[i] != str2[i]) 
                    {
                        match = 0;
                        break;
                    }
                    i++;
                }
                
                if (match == 1) 
                {
                    printf("Strings are equal.\n");
                } 
                else 
                {
                    printf("Strings are not equal.\n");
                }
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}