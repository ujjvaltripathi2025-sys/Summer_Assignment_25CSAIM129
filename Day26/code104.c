#include <stdio.h>
int main() 
{
    int choice;
    int score = 0;
    char next_action;

    printf("=========================================\n");
    printf("             SPACE RECON QUIZ            \n");
    printf("=========================================\n");

    do 
    {
        score = 0;

        printf("\nQ1. Which planet is known as the Red Planet?\n");
        printf("1. Venus\n2. Mars\n3. Jupiter\n4. Saturn\n");
        printf("Enter your answer (1-4): ");
        if (scanf("%d", &choice) == 1 && choice == 2) 
        {
            score++;
        }

        printf("\nQ2. What is the name of the closest star to Earth?\n");
        printf("1. Proxima Centauri\n2. Sirius\n3. The Sun\n4. Polaris\n");
        printf("Enter your answer (1-4): ");
        if (scanf("%d", &choice) == 1 && choice == 3) 
        {
            score++;
        }

        printf("\nQ3. Which planet is the largest in our Solar System?\n");
        printf("1. Earth\n2. Neptune\n3. Saturn\n4. Jupiter\n");
        printf("Enter your answer (1-4): ");
        if (scanf("%d", &choice) == 1 && choice == 4) 
        {
            score++;
        }

        printf("\n=========================================\n");
        printf("               QUIZ RESULTS              \n");
        printf("=========================================\n");
        printf("Total Score: %d out of 3\n", score);
        
        if (score == 3) 
        {
            printf("Performance: Excellent! Astronaut material.\n");
        }
        else if (score == 2) 
        {
            printf("Performance: Good job! Nice knowledge.\n");
        } 
        else 
        {
            printf("Performance: Needs improvement.\n");
        }
        printf("=========================================\n");

        printf("\nDo you want to play another quiz? (yes/No): ");
        scanf(" %c",&next_action);
        while (getchar() != '\n');

    } 
    while (next_action == 'y' || next_action == 'Y');

    printf("\nThank you for playing. Goodbye!\n");
    printf("=========================================\n");
    return 0;
}