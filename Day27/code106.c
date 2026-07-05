#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int empId;
    char name[50];
    char department[30];
    float salary;
};

void addEmployeeRecord();
void displayAllEmployees();
void searchEmployeeRecord();
void deleteEmployeeRecord();

const char* FILE_NAME = "employees.dat";

int main() {
    int choice;

    while (1) {
        printf("\n=== EMPLOYEE MANAGEMENT SYSTEM ===");
        printf("\n1. Add Employee Record");
        printf("\n2. Display All Employee Records");
        printf("\n3. Search Employee Record by ID");
        printf("\n4. Delete Employee Record");
        printf("\n5. Exit");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployeeRecord();
                break;
            case 2:
                displayAllEmployees();
                break;
            case 3:
                searchEmployeeRecord();
                break;
            case 4:
                deleteEmployeeRecord();
                break;
            case 5:
                printf("\nExiting system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addEmployeeRecord() {
    FILE *file = fopen(FILE_NAME, "ab"); 
    if (file == NULL) {
        printf("\nError opening file!");
        return;
    }

    struct Employee e;
    printf("\nEnter Employee ID: ");
    scanf("%d", &e.empId);
    getchar(); 

    printf("Enter Name: ");
    fgets(e.name, sizeof(e.name), stdin);
    e.name[strcspn(e.name, "\n")] = 0; 

    printf("Enter Department: ");
    fgets(e.department, sizeof(e.department), stdin);
    e.department[strcspn(e.department, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &e.salary);

    fwrite(&e, sizeof(struct Employee), 1, file);
    fclose(file);

    printf("\nRecord added successfully!\n");
}

void displayAllEmployees() {
    FILE *file = fopen(FILE_NAME, "rb"); 
    if (file == NULL) {
        printf("\nNo records found. Add a record first!");
        return;
    }

    struct Employee e;
    printf("\n--------------------------------------------------------------");
    printf("\n%-10s %-20s %-15s %-10s", "Emp ID", "Name", "Department", "Salary");
    printf("\n--------------------------------------------------------------");

    while (fread(&e, sizeof(struct Employee), 1, file) == 1) {
        printf("\n%-10d %-20s %-15s %-10.2f", e.empId, e.name, e.department, e.salary);
    }
    printf("\n--------------------------------------------------------------\n");
    fclose(file);
}

void searchEmployeeRecord() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records found!");
        return;
    }

    int searchId, found = 0;
    struct Employee e;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    while (fread(&e, sizeof(struct Employee), 1, file) == 1) {
        if (e.empId == searchId) {
            printf("\nRecord Found!");
            printf("\nEmployee ID: %d", e.empId);
            printf("\nName:        %s", e.name);
            printf("\nDepartment:  %s", e.department);
            printf("\nSalary:      %.2f\n", e.salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nRecord with Employee ID %d not found.\n", searchId);
    }
    fclose(file);
}

void deleteEmployeeRecord() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records found!");
        return;
    }

    FILE *tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("\nError processing request!");
        fclose(file);
        return;
    }

    int deleteId, found = 0;
    struct Employee e;

    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &deleteId);

    while (fread(&e, sizeof(struct Employee), 1, file) == 1) {
        if (e.empId == deleteId) {
            found = 1;
        } else {
            fwrite(&e, sizeof(struct Employee), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);             
        rename("temp.dat", FILE_NAME); 
        printf("\nRecord deleted successfully!\n");
    } else {
        remove("temp.dat");            
        printf("\nRecord with Employee ID %d not found.\n", deleteId);
    }
}