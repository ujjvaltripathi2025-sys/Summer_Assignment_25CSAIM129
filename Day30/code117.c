#include <stdio.h>
#include <string.h>

int main() {
    int maxStudents = 50;
    
    int rollNumbers[50];
    char names[50][50];
    float marks[50];
    
    int studentCount = 0;
    int choice;

    while (1) {
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (studentCount >= maxStudents) {
                    printf("\nError: System database is full!\n");
                    break;
                }
                
                printf("\nEnter Roll Number: ");
                scanf("%d", &rollNumbers[studentCount]);
                
                getchar(); 
                printf("Enter Student Name: ");
                fgets(names[studentCount], 50, stdin);
                
                names[studentCount][strcspn(names[studentCount], "\n")] = '\0';
                
                printf("Enter Percentage/Marks: ");
                scanf("%f", &marks[studentCount]);
                
                studentCount++;
                printf("\nRecord added successfully!\n");
                break;

            case 2:
                if (studentCount == 0) {
                    printf("\nNo student records found to display.\n");
                    break;
                }
                
                printf("\n--------------------------------------------------\n");
                printf("%-10s %-25s %-10s\n", "Roll No", "Name", "Marks (%)");
                printf("--------------------------------------------------\n");
                for (int i = 0; i < studentCount; i++) {
                    printf("%-10d %-25s %-10.2f\n", rollNumbers[i], names[i], marks[i]);
                }
                printf("--------------------------------------------------\n");
                break;

            case 3:
                if (studentCount == 0) {
                    printf("\nDatabase empty. Nothing to search.\n");
                    break;
                }
                
                int searchRoll;
                int found = 0;
                printf("\nEnter Roll Number to search: ");
                scanf("%d", &searchRoll);
                
                for (int i = 0; i < studentCount; i++) {
                    if (rollNumbers[i] == searchRoll) {
                        printf("\nRecord Found!");
                        printf("\nRoll Number : %d", rollNumbers[i]);
                        printf("\nName        : %s", names[i]);
                        printf("\nMarks       : %.2f%%\n", marks[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("\nRecord with Roll Number %d not found.\n", searchRoll);
                }
                break;

            case 4:
                printf("\nExiting Student Record System. Goodbye!\n");
                return 0;

            default:
                printf("\nInvalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}