#include <stdio.h>
int main() 
{
    int age;
    char choice;

    printf("=========================================\n");
    printf("       VOTING ELIGIBILITY SYSTEM         \n");
    printf("=========================================\n");

    do {
        printf("\nEnter your age: ");
        if (scanf("%d", &age) != 1) 
        {
            printf("Error: Invalid numeric input.\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (age < 0 || age > 120) 
        {
            printf("Invalid Age! Please enter a realistic age between 0 and 120.\n");
        } 
        else if (age >= 18) 
        {
            printf("Status: ELIGIBLE to vote!\n");
            printf("Remember, your vote is your voice.\n");
        } 
        else 
        {
            printf("Status: NOT ELIGIBLE to vote.\n");
            printf("You need to wait %d more year(s) to vote.\n", 18 - age);
        }

        printf("\nDo you want to check another citizen? (yes/No): ");
        scanf(" %c",&choice);
        while (getchar() != '\n'); 

    } 
    while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using the Voting System. Goodbye!\n");
    printf("=========================================\n");
    return 0;
}