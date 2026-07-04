#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int secret_number,guess,attempts;
    char choice;

    do 
    {
        attempts = 0;
        
        printf("=========================================\n");
        printf("        SET UP THE GUESSING GAME         \n");
        printf("=========================================\n");
        
        printf("Player 1, enter a secret number (1-100): ");
        scanf("%d",&secret_number);

        system("cls || clear"); 

        printf("=========================================\n");
        printf("   WELCOME TO THE NUMBER GUESSING GAME   \n");
        printf("=========================================\n");
        printf("Player 2, the number has been set between 1 and 100.\n");
        printf("Can you guess what it is?\n\n");

        do 
        {
            printf("Enter your guess: ");
            scanf("%d",&guess);
            attempts++;

            if (guess > secret_number) 
            {
                printf("Too high! Try a lower number.\n\n");
            } 
            else if (guess < secret_number) 
            {
                printf("Too low! Try a higher number.\n\n");
            } 
            else 
            {
                printf("\nCongratulations! You guessed it right!\n");
                printf("Total attempts taken: %d\n", attempts);
            }
        } 
        while (guess != secret_number);

        printf("\nDo you want to Play Another game? (yes/No): ");
        scanf(" %c", &choice);
        while (getchar() != '\n')
        {

        } 

    }
    while (choice == 'y' || choice == 'Y');

    printf("\nThank you for playing. Goodbye!\n");
    printf("=========================================\n");
    return 0;
}