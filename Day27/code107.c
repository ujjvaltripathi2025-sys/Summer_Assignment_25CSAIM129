#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SalaryRecord {
    int empId;
    char name[50]; 
    float basicSalary;
    float allowance;
    float deductions;
    float netSalary;
};

void addSalaryRecord();
void displayAllSalaries();
void searchSalaryRecord();
void deleteSalaryRecord();

const char* FILE_NAME = "salaries.dat";

int main() {
    int choice;

    while (1) {
        printf("\n=== SALARY MANAGEMENT SYSTEM ===");
        printf("\n1. Add Salary Record");
        printf("\n2. Display All Salary Slips");
        printf("\n3. Search Salary Record by Emp ID");
        printf("\n4. Delete Salary Record");
        printf("\n5. Exit");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSalaryRecord();
                break;
            case 2:
                displayAllSalaries();
                break;
            case 3:
                searchSalaryRecord();
                break;
            case 4:
                deleteSalaryRecord();
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

void addSalaryRecord() {
    FILE *file = fopen(FILE_NAME, "ab"); 
    if (file == NULL) {
        printf("\nError opening file!");
        return;
    }

    struct SalaryRecord s;
    printf("\nEnter Employee ID: ");
    scanf("%d", &s.empId);
    getchar(); 

    printf("Enter Employee Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; 

    printf("Enter Basic Salary: ");
    scanf("%f", &s.basicSalary);

    printf("Enter Allowance Amount: ");
    scanf("%f", &s.allowance);

    printf("Enter Deductions Amount: ");
    scanf("%f", &s.deductions);

    s.netSalary = (s.basicSalary + s.allowance) - s.deductions;

    fwrite(&s, sizeof(struct SalaryRecord), 1, file);
    fclose(file);

    printf("\nSalary record added and computed successfully!\n");
}

void displayAllSalaries() {
    FILE *file = fopen(FILE_NAME, "rb"); 
    if (file == NULL) {
        printf("\nNo records found. Add a record first!");
        return;
    }

    struct SalaryRecord s;
    printf("\n-----------------------------------------------------------------------------");
    printf("\n%-8s %-15s %-12s %-10s %-10s %-12s", "ID", "Name", "Basic", "Allow.", "Deduct.", "Net Salary");
    printf("\n-----------------------------------------------------------------------------");

    while (fread(&s, sizeof(struct SalaryRecord), 1, file) == 1) {
        printf("\n%-8d %-15s %-12.2f %-10.2f %-10.2f %-12.2f", 
               s.empId, s.name, s.basicSalary, s.allowance, s.deductions, s.netSalary);
    }
    printf("\n-----------------------------------------------------------------------------\n");
    fclose(file);
}

void searchSalaryRecord() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records found!");
        return;
    }

    int searchId, found = 0;
    struct SalaryRecord s;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    while (fread(&s, sizeof(struct SalaryRecord), 1, file) == 1) {
        if (s.empId == searchId) {
            printf("\n--- SALARY SLIP FOUND ---");
            printf("\nEmployee ID:    %d", s.empId);
            printf("\nEmployee Name:  %s", s.name);
            printf("\nBasic Salary:   INR %.2f", s.basicSalary);
            printf("\nAllowances:     INR %.2f", s.allowance);
            printf("\nDeductions:     INR %.2f", s.deductions);
            printf("\n-------------------------");
            printf("\nNet Paid Salary:INR %.2f\n", s.netSalary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nSalary record for Employee ID %d not found.\n", searchId);
    }
    fclose(file);
}

void deleteSalaryRecord() {
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
    struct SalaryRecord s;

    printf("\nEnter Employee ID to delete salary record: ");
    scanf("%d", &deleteId);

    while (fread(&s, sizeof(struct SalaryRecord), 1, file) == 1) {
        if (s.empId == deleteId) {
            found = 1;
        } else {
            fwrite(&s, sizeof(struct SalaryRecord), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);             
        rename("temp.dat", FILE_NAME); 
        printf("\nSalary record deleted successfully!\n");
    } else {
        remove("temp.dat");            
        printf("\nSalary record for Employee ID %d not found.\n", deleteId);
    }
}