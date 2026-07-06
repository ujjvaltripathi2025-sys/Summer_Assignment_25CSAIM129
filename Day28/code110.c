#include <stdio.h>
#include <string.h>

struct Account 
{
    int accountNumber;
    char name[50];
    float balance;
};

struct Account bank[100];
int accountCount = 0;

void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();

int main() 
{
    int choice;

    do 
    {
        printf("\n=================================");
        printf("\n--- BANK ACCOUNT SYSTEM ---");
        printf("\n=================================");
        printf("\n1. Create New Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Check Balance");
        printf("\n5. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                printf("\nExiting the program. Thank you!\n");
                break;
            default:
                printf("\nInvalid Choice! Please enter a number between 1 and 5.\n");
        }
    } 
    while (choice != 5);

    return 0;
}

void createAccount() 
{
    struct Account newAcc;

    if (accountCount >= 100) 
    {
        printf("\nBank database full! Cannot create more accounts.\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &newAcc.accountNumber);
    getchar();

    printf("Enter Account Holder Name: ");
    fgets(newAcc.name, 50, stdin);
    newAcc.name[strcspn(newAcc.name, "\n")] = '\0';

    printf("Enter Initial Deposit Amount: ");
    scanf("%f", &newAcc.balance);

    bank[accountCount] = newAcc;
    accountCount++;

    printf("\nAccount created successfully!\n");
}

void depositMoney() 
{
    int accNum, i, found = 0;
    float amount;

    if (accountCount == 0) 
    {
        printf("\nBank database empty.\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    for (i = 0; i < accountCount; i++) 
    {
        if (bank[i].accountNumber == accNum) 
        {
            found = 1;
            printf("Account Holder: %s", bank[i].name);
            printf("\nCurrent Balance: %.2f", bank[i].balance);
            
            printf("\n\nEnter amount to deposit: ");
            scanf("%f", &amount);

            if (amount <= 0) 
            {
                printf("\nInvalid amount! Deposit failed.\n");
            } 
            else 
            {
                bank[i].balance += amount;
                printf("\nSuccess! New Balance: %.2f\n", bank[i].balance);
            }
            break;
        }
    }

    if (!found) 
    {
        printf("\nAccount number %d not found.\n", accNum);
    }
}

void withdrawMoney() 
{
    int accNum, i, found = 0;
    float amount;

    if (accountCount == 0) 
    {
        printf("\nBank database empty.\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    for (i = 0; i < accountCount; i++) 
    {
        if (bank[i].accountNumber == accNum) 
        {
            found = 1;
            printf("Account Holder: %s", bank[i].name);
            printf("\nCurrent Balance: %.2f", bank[i].balance);
            
            printf("\n\nEnter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount <= 0) 
            {
                printf("\nInvalid amount! Withdrawal failed.\n");
            } 
            else if (amount > bank[i].balance) 
            {
                printf("\nError: Insufficient balance!\n");
            } 
            else 
            {
                bank[i].balance -= amount;
                printf("\nSuccess! New Balance: %.2f\n", bank[i].balance);
            }
            break;
        }
    }

    if (!found) 
    {
        printf("\nAccount number %d not found.\n", accNum);
    }
}

void checkBalance() 
{
    int accNum, i, found = 0;

    if (accountCount == 0) 
    {
        printf("\nBank database empty.\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    for (i = 0; i < accountCount; i++) 
    {
        if (bank[i].accountNumber == accNum) 
        {
            printf("\n--- Account Details ---");
            printf("\nAccount Number: %d", bank[i].accountNumber);
            printf("\nAccount Holder: %s", bank[i].name);
            printf("\nCurrent Balance: %.2f\n", bank[i].balance);
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("\nAccount number %d not found.\n", accNum);
    }
}