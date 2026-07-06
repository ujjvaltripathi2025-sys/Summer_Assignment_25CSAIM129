#include <stdio.h>   
#include <string.h>  

struct Book 
{
    int bookId;
    char title[50];
    char author[50];
    float price;
    int isIssued; 
};

struct Book library[100];
int bookCount = 0;

void addBook();
void displayBooks();
void searchBook();
void issueBook();

int main() 
{
    int choice;

    do 
    {
        printf("\n=================================");
        printf("\n--- LIBRARY MANAGEMENT SYSTEM ---");
        printf("\n=================================");
        printf("\n1. Add New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search Book by ID");
        printf("\n4. Issue / Return Book");
        printf("\n5. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                issueBook();
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

void addBook() 
{
    struct Book newBook;

    if (bookCount >= 100) 
    {
        printf("\nLibrary space full! Cannot add more books.\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &newBook.bookId);
    getchar(); 

    printf("Enter Book Title: ");
    fgets(newBook.title, 50, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; 

    printf("Enter Author Name: ");
    fgets(newBook.author, 50, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; 

    printf("Enter Book Price: ");
    scanf("%f", &newBook.price);

    newBook.isIssued = 0; 

    library[bookCount] = newBook;
    bookCount++;

    printf("\nBook added successfully!\n");
}

void displayBooks() 
{
    int i;

    if (bookCount == 0) 
    {
        printf("\nNo books available in the library yet.\n");
        return;
    }

    printf("\n%-10s %-25s %-25s %-10s %-10s", "Book ID", "Title", "Author", "Price", "Status");
    printf("\n---------------------------------------------------------------------------------");
    
    for (i = 0; i < bookCount; i++) 
    {
        printf("\n%-10d %-25s %-25s %-10.2f %-10s", 
               library[i].bookId, 
               library[i].title, 
               library[i].author, 
               library[i].price, 
               (library[i].isIssued == 1) ? "Issued" : "Available");
    }
    printf("\n");
}

void searchBook() 
{
    int sId, i, found = 0;

    if (bookCount == 0) 
    {
        printf("\nLibrary database empty.\n");
        return;
    }

    printf("\nEnter Book ID to search: ");
    scanf("%d", &sId);

    for (i = 0; i < bookCount; i++) 
    {
        if (library[i].bookId == sId) 
        {
            printf("\n--- Book Found ---");
            printf("\nID: %d", library[i].bookId);
            printf("\nTitle: %s", library[i].title);
            printf("\nAuthor: %s", library[i].author);
            printf("\nPrice: %.2f", library[i].price);
            printf("\nStatus: %s\n", (library[i].isIssued == 1) ? "Issued" : "Available");
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("\nBook with ID %d not found in records.\n", sId);
    }
}

void issueBook() 
{
    int sId, i, found = 0, action;

    if (bookCount == 0) 
    {
        printf("\nLibrary database empty.\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &sId);

    for (i = 0; i < bookCount; i++) 
    {
        if (library[i].bookId == sId) 
        {
            found = 1;
            printf("\nBook details: %s by %s", library[i].title, library[i].author);
            printf("\nCurrent Status: %s", (library[i].isIssued == 1) ? "Issued" : "Available");
            
            printf("\n\nSelect operation (1: Issue, 2: Return): ");
            scanf("%d", &action);

            if (action == 1) 
            {
                if (library[i].isIssued == 1) 
                {
                    printf("\nError: This book is already issued out to someone else!\n");
                } 
                else 
                {
                    library[i].isIssued = 1;
                    printf("\nSuccess: Book issued successfully.\n");
                }
            } 
            else if (action == 2) 
            {
                if (library[i].isIssued == 0) 
                {
                    printf("\nError: This book is already resting inside the library!\n");
                } 
                else 
                {
                    library[i].isIssued = 0;
                    printf("\nSuccess: Book returned safely.\n");
                }
            } 
            else 
            {
                printf("\nInvalid Selection operation cancelled.\n");
            }
            break;
        }
    }

    if (!found) 
    {
        printf("\nBook with ID %d does not exist.\n", sId);
    }
}