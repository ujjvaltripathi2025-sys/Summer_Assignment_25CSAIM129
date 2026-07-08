#include <stdio.h>
#include <string.h>

void displayMenu() {
    printf("\n=== INVENTORY MANAGEMENT SYSTEM ===\n");
    printf("1. Add New Item\n");
    printf("2. View All Items\n");
    printf("3. Search Item by Product Code\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
}

void addItem(int codes[], char names[][50], int stocks[], int *count, int maxLimit) {
    if (*count >= maxLimit) {
        printf("\nError: Inventory database is full!\n");
        return;
    }
    
    printf("\nEnter Unique Product Code: ");
    scanf("%d", &codes[*count]);
    
    getchar();
    printf("Enter Product Name: ");
    fgets(names[*count], 50, stdin);
    names[*count][strcspn(names[*count], "\n")] = '\0';
    
    printf("Enter Stock Quantity: ");
    scanf("%d", &stocks[*count]);
    
    (*count)++;
    printf("\nItem added to inventory successfully!\n");
}

void viewAllItems(int codes[], char names[][50], int stocks[], int count) {
    if (count == 0) {
        printf("\nNo items found in the inventory.\n");
        return;
    }
    
    printf("\n------------------------------------------------------------\n");
    printf("%-15s %-30s %-15s\n", "Product Code", "Item Name", "Stock Qty");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-15d %-30s %-15d\n", codes[i], names[i], stocks[i]);
    }
    printf("------------------------------------------------------------\n");
}

void searchItem(int codes[], char names[][50], int stocks[], int count) {
    if (count == 0) {
        printf("\nInventory is empty. Nothing to search.\n");
        return;
    }
    
    int searchCode;
    int found = 0;
    printf("\nEnter Product Code to search: ");
    scanf("%d", &searchCode);
    
    for (int i = 0; i < count; i++) {
        if (codes[i] == searchCode) {
            printf("\nItem Record Found!");
            printf("\nProduct Code : %d", codes[i]);
            printf("\nItem Name    : %s", names[i]);
            printf("\nStock Qty    : %d\n", stocks[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nProduct with Code %d not found in the system.\n", searchCode);
    }
}

int main() {
    int maxItems = 100;
    int productCodes[100];
    char productNames[100][50];
    int productStocks[100];
    int itemCount = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(productCodes, productNames, productStocks, &itemCount, maxItems);
                break;
            case 2:
                viewAllItems(productCodes, productNames, productStocks, itemCount);
                break;
            case 3:
                searchItem(productCodes, productNames, productStocks, itemCount);
                break;
            case 4:
                printf("\nExiting Inventory System. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}