#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Marksheet {
    int rollNumber;
    char name[50];       
    int mathMarks;
    int scienceMarks;
    int englishMarks;
    int totalMarks;
    float percentage;
    char grade;
};

void addMarksheetRecord();
void displayAllMarksheets();
void searchMarksheetRecord();
void deleteMarksheetRecord();

const char* FILE_NAME = "marksheets.dat";

int main() {
    int choice;

    while (1) {
        printf("\n=== MARKSHEET GENERATION SYSTEM ===");
        printf("\n1. Add Student Marks");
        printf("\n2. Display All Marksheets");
        printf("\n3. Search and Print Marksheet by Roll No.");
        printf("\n4. Delete Marksheet Record");
        printf("\n5. Exit");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMarksheetRecord();
                break;
            case 2:
                displayAllMarksheets();
                break;
            case 3:
                searchMarksheetRecord();
                break;
            case 4:
                deleteMarksheetRecord();
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

void addMarksheetRecord() {
    FILE *file = fopen(FILE_NAME, "ab"); 
    if (file == NULL) {
        printf("\nError opening file!");
        return;
    }

    struct Marksheet m;
    printf("\nEnter Roll Number: ");
    scanf("%d", &m.rollNumber);
    getchar(); 

    printf("Enter Student Name: ");
    fgets(m.name, sizeof(m.name), stdin);
    m.name[strcspn(m.name, "\n")] = 0; 

    printf("Enter Mathematics Marks (out of 100): ");
    scanf("%d", &m.mathMarks);

    printf("Enter Science Marks (out of 100): ");
    scanf("%d", &m.scienceMarks);

    printf("Enter English Marks (out of 100): ");
    scanf("%d", &m.englishMarks);

    m.totalMarks = m.mathMarks + m.scienceMarks + m.englishMarks;
    m.percentage = m.totalMarks / 3.0f;

    if (m.percentage >= 85) m.grade = 'A';
    else if (m.percentage >= 70) m.grade = 'B';
    else if (m.percentage >= 50) m.grade = 'C';
    else if (m.percentage >= 33) m.grade = 'D';
    else m.grade = 'F';

    fwrite(&m, sizeof(struct Marksheet), 1, file);
    fclose(file);

    printf("\nMarksheet record added and graded successfully!\n");
}

void displayAllMarksheets() {
    FILE *file = fopen(FILE_NAME, "rb"); 
    if (file == NULL) {
        printf("\nNo records found. Add a record first!");
        return;
    }

    struct Marksheet m;
    printf("\n-----------------------------------------------------------------------------");
    printf("\n%-8s %-15s %-6s %-6s %-6s %-7s %-7s %-5s", "Roll No", "Name", "Math", "Sci", "Eng", "Total", "Perc%", "Grade");
    printf("\n-----------------------------------------------------------------------------");

    while (fread(&m, sizeof(struct Marksheet), 1, file) == 1) {
        printf("\n%-8d %-15s %-6d %-6d %-6d %-7d %-7.2f %-5c", 
               m.rollNumber, m.name, m.mathMarks, m.scienceMarks, m.englishMarks, m.totalMarks, m.percentage, m.grade);
    }
    printf("\n-----------------------------------------------------------------------------\n");
    fclose(file);
}

void searchMarksheetRecord() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records found!");
        return;
    }

    int searchRoll, found = 0;
    struct Marksheet m;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &searchRoll);

    while (fread(&m, sizeof(struct Marksheet), 1, file) == 1) {
        if (m.rollNumber == searchRoll) {
            printf("\n==========================================");
            printf("\n            OFFICIAL MARKSHEET            ");
            printf("\n==========================================");
            printf("\nRoll Number : %d", m.rollNumber);
            printf("\nStudent Name: %s", m.name);
            printf("\n------------------------------------------");
            printf("\nSubject          Maximum Marks   Obtained ");
            printf("\n------------------------------------------");
            printf("\nMathematics      100             %d", m.mathMarks);
            printf("\nScience          100             %d", m.scienceMarks);
            printf("\nEnglish          100             %d", m.englishMarks);
            printf("\n------------------------------------------");
            printf("\nTotal Marks      300             %d", m.totalMarks);
            printf("\nPercentage                       %.2f%%", m.percentage);
            printf("\nFinal Grade                      %c", m.grade);
            printf("\nResult                           %s", (m.grade == 'F') ? "FAIL" : "PASS");
            printf("\n==========================================\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nMarksheet record for Roll Number %d not found.\n", searchRoll);
    }
    fclose(file);
}

void deleteMarksheetRecord() {
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
    struct Marksheet m;

    printf("\nEnter Roll Number to delete marksheet record: ");
    scanf("%d", &deleteRoll);

    while (fread(&m, sizeof(struct Marksheet), 1, file) == 1) {
        if (m.rollNumber == deleteRoll) {
            found = 1;
        } else {
            fwrite(&m, sizeof(struct Marksheet), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);             
        rename("temp.dat", FILE_NAME); 
        printf("\nMarksheet record deleted successfully!\n");
    } else {
        remove("temp.dat");            
        printf("\nMarksheet record for Roll Number %d not found.\n", deleteRoll);
    }
}