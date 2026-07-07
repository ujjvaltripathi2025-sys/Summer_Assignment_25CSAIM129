#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int arr[100];
    int size = 0;
    int choice, element, position, i;

    while (1) 
    {
        printf("\n=== ARRAY OPERATIONS MENU ===\n");
        printf("1. Insert an Element\n");
        printf("2. Delete an Element\n");
        printf("3. Display Array\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        if (choice == 4) 
        {
            printf("Exiting program. Goodbye!\n");
            exit(0);
        }

        switch (choice) 
        {
            case 1:
                if (size >= 100) 
                {
                    printf("Error: Array is full (Overflow)!\n");
                    break;
                }
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter position (0 to %d): ", size);
                scanf("%d", &position);

                if (position < 0 || position > size) 
                {
                    printf("Invalid position!\n");
                } 
                else 
                {
                    for (i = size - 1; i >= position; i--) 
                    {
                        arr[i + 1] = arr[i];
                    }
                    arr[position] = element;
                    size++;
                    printf("Element inserted successfully.\n");
                }
                break;

            case 2:
                if (size == 0) 
                {
                    printf("Error: Array is empty (Underflow)!\n");
                    break;
                }
                printf("Enter position to delete (0 to %d): ", size - 1);
                scanf("%d", &position);

                if (position < 0 || position >= size) 
                {
                    printf("Invalid position!\n");
                } 
                else 
                {
                    element = arr[position];
                    for (i = position; i < size - 1; i++) 
                    {
                        arr[i] = arr[i + 1];
                    }
                    size--;
                    printf("Deleted element: %d\n", element);
                }
                break;

            case 3:
                if (size == 0) 
                {
                    printf("Array is empty.\n");
                } 
                else 
                {
                    printf("Array elements: ");
                    for (i = 0; i < size; i++) 
                    {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}