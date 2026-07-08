#include <stdio.h>
#include <string.h>

int main() {
    int maxBooks = 100;
    
    int bookIDs[100];
    char bookTitles[100][100];
    float bookPrices[100];
    
    int bookCount = 0;
    int choice;

    while (1) {
        printf("\n=== MINI LIBRARY SYSTEM ===\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (bookCount >= maxBooks) {
                    printf("\nError: Library inventory is full!\n");
                    break;
                }
                
                printf("\nEnter Unique Book ID: ");
                scanf("%d", &bookIDs[bookCount]);
                
                getchar(); 
                printf("Enter Book Title: ");
                fgets(bookTitles[bookCount], 100, stdin);
                bookTitles[bookCount][strcspn(bookTitles[bookCount], "\n")] = '\0';
                
                printf("Enter Book Price: ");
                scanf("%f", &bookPrices[bookCount]);
                
                bookCount++;
                printf("\nBook added to inventory successfully!\n");
                break;

            case 2:
                if (bookCount == 0) {
                    printf("\nNo books found in the library database.\n");
                    break;
                }
                
                printf("\n------------------------------------------------------------\n");
                printf("%-10s %-35s %-10s\n", "Book ID", "Title", "Price (INR)");
                printf("------------------------------------------------------------\n");
                for (int i = 0; i < bookCount; i++) {
                    printf("%-10d %-35s %-10.2f\n", bookIDs[i], bookTitles[i], bookPrices[i]);
                }
                printf("------------------------------------------------------------\n");
                break;

            case 3:
                if (bookCount == 0) {
                    printf("\nLibrary inventory is empty. Nothing to search.\n");
                    break;
                }
                
                int searchID;
                int found = 0;
                printf("\nEnter Book ID to search: ");
                scanf("%d", &searchID);
                
                for (int i = 0; i < bookCount; i++) {
                    if (bookIDs[i] == searchID) {
                        printf("\nBook Found!");
                        printf("\nBook ID    : %d", bookIDs[i]);
                        printf("\nTitle      : %s", bookTitles[i]);
                        printf("\nPrice      : Rs. %.2f\n", bookPrices[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("\nBook with ID %d not found in the system.\n", searchID);
                }
                break;

            case 4:
                printf("\nExiting Library System. Goodbye!\n");
                return 0;

            default:
                printf("\nInvalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}