#include <stdio.h>
#include <stdlib.h>

struct Item 
{
    int id;
    char name[50];
    int quantity;
    double price;
};

int main() 
{
    struct Item inventory[100];
    int size = 0;
    int choice, searchId, found, i;

    while (1) 
    {
        printf("\n=== INVENTORY MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Item\n");
        printf("2. Display All Items\n");
        printf("3. Search Item by ID\n");
        printf("4. Update Stock Quantity\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice == 5) 
        {
            printf("Exiting system. Goodbye!\n");
            exit(0);
        }

        switch (choice) 
        {
            case 1:
                if (size >= 100) 
                {
                    printf("Error: Inventory storage is full!\n");
                    break;
                }
                printf("Enter Item ID: ");
                scanf("%d", &inventory[size].id);
                getchar(); 

                printf("Enter Item Name: ");
                scanf("%[^\n]", inventory[size].name);

                printf("Enter Quantity: ");
                scanf("%d", &inventory[size].quantity);

                printf("Enter Price per unit: ");
                scanf("%lf", &inventory[size].price);

                size++;
                printf("Item added successfully!\n");
                break;

            case 2:
                if (size == 0) 
                {
                    printf("Inventory is empty.\n");
                } 
                else 
                {
                    printf("\n-------------------------------------------------------------\n");
                    printf("%-10s %-25s %-10s %-10s\n", "ID", "Name", "Stock", "Price");
                    printf("-------------------------------------------------------------\n");
                    for (i = 0; i < size; i++) 
                    {
                        printf("%-10d %-25s %-10d %-10.2lf\n", 
                               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
                    }
                    printf("-------------------------------------------------------------\n");
                }
                break;

            case 3:
                if (size == 0) 
                {
                    printf("Inventory is empty.\n");
                    break;
                }
                printf("Enter Item ID to search: ");
                scanf("%d", &searchId);
                
                found = 0;
                for (i = 0; i < size; i++) 
                {
                    if (inventory[i].id == searchId) 
                    {
                        printf("\nItem Found!\n");
                        printf("ID: %d\nName: %s\nStock: %d\nPrice: %.2lf\n", 
                               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
                        found = 1;
                        break;
                    }
                }
                if (!found) 
                {
                    printf("Item with ID %d not found.\n", searchId);
                }
                break;

            case 4:
                if (size == 0) 
                {
                    printf("Inventory is empty.\n");
                    break;
                }
                printf("Enter Item ID to update stock: ");
                scanf("%d", &searchId);
                
                found = 0;
                for (i = 0; i < size; i++) 
                {
                    if (inventory[i].id == searchId) 
                    {
                        printf("Current stock for %s is %d. Enter new stock quantity: ", inventory[i].name, inventory[i].quantity);
                        scanf("%d", &inventory[i].quantity);
                        printf("Stock updated successfully!\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) 
                {
                    printf("Item with ID %d not found.\n", searchId);
                }
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}