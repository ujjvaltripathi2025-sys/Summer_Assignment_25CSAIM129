#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student 
{
    int rollNumber;
    char name[50];
    char course[50];
    float gpa;
};

void addStudentRecord();
void displayAllRecords();
void searchStudentRecord();
void deleteStudentRecord();

const char* FILE_NAME = "students.dat";

int main() {
    int choice;

    while (1) {
        printf("\n=== STUDENT RECORD MANAGEMENT SYSTEM ===");
        printf("\n1. Add Student Record");
        printf("\n2. Display All Student Records");
        printf("\n3. Search Student Record by Roll No.");
        printf("\n4. Delete Student Record");
        printf("\n5. Exit");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudentRecord();
                break;
            case 2:
                displayAllRecords();
                break;
            case 3:
                searchStudentRecord();
                break;
            case 4:
                deleteStudentRecord();
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

void addStudentRecord() {
    FILE *file = fopen(FILE_NAME, "ab"); 
    if (file == NULL) {
        printf("\nError opening file!");
        return;
    }

    struct Student s;
    printf("\nEnter Roll Number: ");
    scanf("%d", &s.rollNumber);
    getchar(); 

    printf("Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; 

    printf("Enter Course: ");
    fgets(s.course, sizeof(s.course), stdin);
    s.course[strcspn(s.course, "\n")] = 0;

    printf("Enter GPA: ");
    scanf("%f", &s.gpa);

    fwrite(&s, sizeof(struct Student), 1, file);
    fclose(file);

    printf("\nRecord added successfully!\n");
}

void displayAllRecords() {
    FILE *file = fopen(FILE_NAME, "rb"); 
    if (file == NULL) {
        printf("\nNo records found. Add a record first!");
        return;
    }

    struct Student s;
    printf("\n--------------------------------------------------------------");
    printf("\n%-10s %-20s %-15s %-5s", "Roll No", "Name", "Course", "GPA");
    printf("\n--------------------------------------------------------------");

    while (fread(&s, sizeof(struct Student), 1, file) == 1) {
        printf("\n%-10d %-20s %-15s %-5.2f", s.rollNumber, s.name, s.course, s.gpa);
    }
    printf("\n--------------------------------------------------------------\n");
    fclose(file);
}

void searchStudentRecord() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records found!");
        return;
    }

    int searchRoll, found = 0;
    struct Student s;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &searchRoll);

    while (fread(&s, sizeof(struct Student), 1, file) == 1) {
        if (s.rollNumber == searchRoll) {
            printf("\nRecord Found!");
            printf("\nRoll Number: %d", s.rollNumber);
            printf("\nName:        %s", s.name);
            printf("\nCourse:      %s", s.course);
            printf("\nGPA:         %.2f\n", s.gpa);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nRecord with Roll Number %d not found.\n", searchRoll);
    }
    fclose(file);
}

void deleteStudentRecord() {
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

    int deleteRoll, found = 0;
    struct Student s;

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &deleteRoll);

    while (fread(&s, sizeof(struct Student), 1, file) == 1) {
        if (s.rollNumber == deleteRoll) {
            found = 1;
        } else {
            fwrite(&s, sizeof(struct Student), 1, tempFile);
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
        printf("\nRecord with Roll Number %d not found.\n", deleteRoll);
    }
}