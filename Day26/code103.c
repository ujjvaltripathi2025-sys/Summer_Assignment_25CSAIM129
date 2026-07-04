#include <stdio.h>
int main() 
{
    int choice;
    float balance = 5000.0;
    float amount;
    char next_action;

    printf("=========================================\n");
    printf("         AUTOMATED TELLER MACHINE        \n");
    printf("=========================================\n");

    do {
        printf("\n1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        if (scanf("%d",&choice) != 1) 
        {
            printf("Error: Invalid option selection.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) 
        {
            case 1:
                printf("\nCurrent Account Balance: $%.2f\n", balance);
                break;

            case 2:
                printf("\nEnter deposit amount: $");
                if (scanf("%f", &amount) != 1 || amount <= 0) 
                {
                    printf("Error: Invalid transaction amount.\n");
                    while (getchar() != '\n');
                } 
                else 
                {
                    balance += amount;
                    printf("Success: $%.2f deposited.\n",amount);
                    printf("New Balance: $%.2f\n",balance);
                }
                break;

            case 3:
                printf("\nEnter withdrawal amount: $");
                if (scanf("%f", &amount) != 1 || amount <= 0) 
                {
                    printf("Error: Invalid transaction amount.\n");
                    while (getchar() != '\n');
                } 
                else if (amount > balance) 
                {
                    printf("Transaction Failed: Insufficient funds.\n");
                } 
                else 
                {
                    balance -= amount;
                    printf("Success: $%.2f withdrawn.\n",amount);
                    printf("Remaining Balance: $%.2f\n",balance);
                }
                break;

            case 4:
                printf("\nThank you for using our ATM service. Goodbye!\n");
                printf("=========================================\n");
                return 0;

            default:
                printf("Invalid selection! Please choose an option from 1 to 4.\n");
        }

        printf("\nDo you want to perform another transaction? (yes/No): ");
        scanf(" %c",&next_action);
        while (getchar() != '\n');

    } 
    while (next_action == 'y' || next_action == 'Y');

    printf("\nThank you for using our ATM service. Goodbye!\n");
    printf("=========================================\n");
    return 0;
}