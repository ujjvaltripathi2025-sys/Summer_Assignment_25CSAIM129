#include <stdio.h>
#include <string.h>

int main() {
    int maxEmployees = 100;
    
    int employeeIDs[100];
    char employeeNames[100][50];
    float employeeSalaries[100];
    
    int employeeCount = 0;
    int choice;

    while (1) {
        printf("\n=== EMPLOYEE MANAGEMENT SYSTEM ===\n");
        printf("1. Add Employee Record\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (employeeCount >= maxEmployees) {
                    printf("\nError: Employee database is full!\n");
                    break;
                }
                
                printf("\nEnter Unique Employee ID: ");
                scanf("%d", &employeeIDs[employeeCount]);
                
                getchar(); 
                printf("Enter Employee Name: ");
                fgets(employeeNames[employeeCount], 50, stdin);
                employeeNames[employeeCount][strcspn(employeeNames[employeeCount], "\n")] = '\0';
                
                printf("Enter Monthly Salary: ");
                scanf("%f", &employeeSalaries[employeeCount]);
                
                employeeCount++;
                printf("\nEmployee record added successfully!\n");
                break;

            case 2:
                if (employeeCount == 0) {
                    printf("\nNo employee records found in the database.\n");
                    break;
                }
                
                printf("\n------------------------------------------------------------\n");
                printf("%-15s %-30s %-15s\n", "Employee ID", "Name", "Salary (INR)");
                printf("------------------------------------------------------------\n");
                for (int i = 0; i < employeeCount; i++) {
                    printf("%-15d %-30s %-15.2f\n", employeeIDs[i], employeeNames[i], employeeSalaries[i]);
                }
                printf("------------------------------------------------------------\n");
                break;

            case 3:
                if (employeeCount == 0) {
                    printf("\nDatabase is empty. Nothing to search.\n");
                    break;
                }
                
                int searchID;
                int found = 0;
                printf("\nEnter Employee ID to search: ");
                scanf("%d", &searchID);
                
                for (int i = 0; i < employeeCount; i++) {
                    if (employeeIDs[i] == searchID) {
                        printf("\nEmployee Record Found!");
                        printf("\nEmployee ID : %d", employeeIDs[i]);
                        printf("\nName        : %s", employeeNames[i]);
                        printf("\nSalary      : Rs. %.2f\n", employeeSalaries[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("\nEmployee with ID %d not found in the system.\n", searchID);
                }
                break;

            case 4:
                printf("\nExiting Employee Management System. Goodbye!\n");
                return 0;

            default:
                printf("\nInvalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}