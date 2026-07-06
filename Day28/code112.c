#include <stdio.h>
#include <string.h>

struct Contact 
{
    int contactId;
    char name[50];
    char phone[50];
    char email[50];
};

struct Contact directory[100];
int contactCount = 0;

void addContact();
void displayContacts();
void searchContact();
void deleteContact();

int main() 
{
    int choice;

    do 
    {
        printf("\n=================================");
        printf("\n--- CONTACT MANAGEMENT SYSTEM ---");
        printf("\n=================================");
        printf("\n1. Add New Contact");
        printf("\n2. Display All Contacts");
        printf("\n3. Search Contact by ID");
        printf("\n4. Delete Contact");
        printf("\n5. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
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

void addContact() 
{
    struct Contact newContact;

    if (contactCount >= 100) 
    {
        printf("\nDirectory full! Cannot add more contacts.\n");
        return;
    }

    printf("\nEnter Contact ID: ");
    scanf("%d", &newContact.contactId);
    getchar();

    printf("Enter Contact Name: ");
    fgets(newContact.name, 50, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0';

    printf("Enter Phone Number: ");
    fgets(newContact.phone, 50, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0';

    printf("Enter Email Address: ");
    fgets(newContact.email, 50, stdin);
    newContact.email[strcspn(newContact.email, "\n")] = '\0';

    directory[contactCount] = newContact;
    contactCount++;

    printf("\nContact added successfully!\n");
}

void displayContacts() 
{
    int i;

    if (contactCount == 0) 
    {
        printf("\nNo contacts found in the directory.\n");
        return;
    }

    printf("\n%-10s %-25s %-20s %-25s", "ID", "Name", "Phone", "Email");
    printf("\n---------------------------------------------------------------------------------");
    
    for (i = 0; i < contactCount; i++) 
    {
        printf("\n%-10d %-25s %-20s %-25s", 
               directory[i].contactId, 
               directory[i].name, 
               directory[i].phone, 
               directory[i].email);
    }
    printf("\n");
}

void searchContact() 
{
    int searchId, i, found = 0;

    if (contactCount == 0) 
    {
        printf("\nContact directory empty.\n");
        return;
    }

    printf("\nEnter Contact ID to search: ");
    scanf("%d", &searchId);

    for (i = 0; i < contactCount; i++) 
    {
        if (directory[i].contactId == searchId) 
        {
            printf("\n--- Contact Found ---");
            printf("\nID: %d", directory[i].contactId);
            printf("\nName: %s", directory[i].name);
            printf("\nPhone: %s", directory[i].phone);
            printf("\nEmail: %s\n", directory[i].email);
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("\nContact with ID %d not found.\n", searchId);
    }
}

void deleteContact() 
{
    int searchId, i, j, found = 0;

    if (contactCount == 0) 
    {
        printf("\nNo contacts available to delete.\n");
        return;
    }

    printf("\nEnter Contact ID to delete: ");
    scanf("%d", &searchId);

    for (i = 0; i < contactCount; i++) 
    {
        if (directory[i].contactId == searchId) 
        {
            found = 1;
            for (j = i; j < contactCount - 1; j++) 
            {
                directory[j] = directory[j + 1];
            }
            contactCount--;
            printf("\nSuccess: Contact deleted successfully.\n");
            break;
        }
    }

    if (!found) 
    {
        printf("\nContact ID %d not found in records.\n", searchId);
    }
}