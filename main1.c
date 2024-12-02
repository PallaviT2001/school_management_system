#include "fileoperation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"
#include "student.h"
#include "faculty.h"
#include "fees.h"
#include "section.h"

enum MainMenuChoice {
    STUDENT_OPERATIONS = 1,
    FACULTY_OPERATIONS,
    FEES_OPERATIONS,
    SECTION_OPERATIONS,
    EXIT_PROGRAM
};

enum StudentMenuChoice{
    INSERT_STUDENT = 1,
    DELETE_STUDENT,
    UPDATE_STUDENT_DETAILS,
    DISPLAY_STUDENTS,
    SORT_STUDENTS_BY_ID,
    SORT_STUDENTS_BY_NAME,
    TOTAL_STUDENT_COUNT,
    SAVE_STUDENT,
    EXIT_STUDENT
};

enum FacultyMenuChoice{
    INSERT_FACULTY = 1,
    DELETE_FACULTY,
    UPDATE_FACULTY_DETAILS,
    DISPLAY_FACULTIES,
    SORT_FACULTIES_BY_ID,
    SORT_FACULTIES_BY_NAME,
    TOTAL_FACULTY_COUNT,
    SAVE_FACULTY,
    EXIT_FACULTY
};

enum FeesMenuChoice {
    INSERT_FEES_RECORD = 1,
    DISPLAY_FEES_RECORDS,
    SAVE_FEES,
    EXIT_FEES
};

enum SectionMenuChoice {
    INSERT_SECTION = 1,
    DISPLAY_SECTIONS,
    SAVE_SECTION,
    EXIT_SECTION
};

int mainprogram()
{
    if (!adminLogin()) {
        return 1;
    }
    int choice;
    loadStudentsFromFile("students.txt");
    loadFacultyData("faculties.txt");
    loadFeesFromFile("fees.txt");
    loadSectionsFromFile("section.txt");

    while (1) {
        printf("--- Select Operation ---\n");
        printf("1. Perform Student Operations\n");
        printf("2. Perform Faculty Operations\n");
        printf("3. Perform Fees Operations\n");
        printf("4. Perform Section Operations\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case STUDENT_OPERATIONS: {
            int studentChoice;
            printf("--- Student Operations ---\n");
            printf("1. Insert Student\n");
            printf("2. Delete Student\n");
            printf("3. Update Student Details\n");
            printf("4. Display Students\n");
            printf("5. Sort and Display Students by ID\n");
            printf("6. Sort and Display Students by Name\n");
            printf("7. Total Student Count\n");
            printf("8. save to file\n");
            printf("9. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &studentChoice);

            switch (studentChoice){
            case INSERT_STUDENT:
            {
                int id, age;
                char name[50], contactNumber[15];
                printf("Enter student ID: ");
                scanf("%d", &id);
                printf("Enter student name: ");
                scanf(" %[^\n]", name);
                printf("Enter student age: ");
                scanf("%d", &age);
                printf("Enter student contact number: ");
                scanf(" %[^\n]", contactNumber);
                insertStudent(id, name, age, contactNumber);
                break;
            }
            case DELETE_STUDENT: {
                int id;
                printf("Enter student ID to delete: ");
                scanf("%d", &id);
                deleteStudent(id);
                saveStudentsToFile("students.txt");
                break;
            }
            case UPDATE_STUDENT_DETAILS: {
                int id;
                printf("Enter student ID to update: ");
                scanf("%d", &id);
                updateStudent(id);
                saveStudentsToFile("students.txt");
                break;
            }
            case DISPLAY_STUDENTS:
                displayStudentDetails();
                break;
            case SORT_STUDENTS_BY_ID:
                sortStudentsByID();
                break;
            case SORT_STUDENTS_BY_NAME:
                sortStudentsByName();
                break;
            case TOTAL_STUDENT_COUNT:
                printf("Total student count: %d\n", studentCount);
                break;
            case SAVE_STUDENT:
                saveStudentsToFile("students.txt");
                break;
            case EXIT_STUDENT:
                printf("Program exited!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
            }
            break;
        }

        case FACULTY_OPERATIONS: {
            int facultyChoice;
            printf("\n--- Faculty Operations ---\n");
            printf("1. Insert Faculty\n");
            printf("2. Delete Faculty\n");
            printf("3. Update Faculty Details\n");
            printf("4. Display Faculties\n");
            printf("5. Sort and Display Faculties by ID\n");
            printf("6. Sort and Display Faculties by Name\n");
            printf("7. Total Faculty Count\n");
            printf("8. Save to file\n");
            printf("9. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &facultyChoice);

            switch (facultyChoice) {
            case INSERT_FACULTY: {
                int id, age;
                char name[50], department[50], qualification[20];
                printf("Enter faculty ID: ");
                scanf("%d", &id);
                printf("Enter faculty name: ");
                scanf(" %[^\n]", name);
                printf("Enter faculty department: ");
                scanf(" %[^\n]", department);
                printf("Enter faculty age: ");
                scanf("%d", &age);
                printf("Enter faculty qualification: ");
                scanf(" %[^\n]", qualification);
                insertFaculty(id, name, department, age, qualification);
                break;
            }
            case DELETE_FACULTY: {
                int id;
                printf("Enter faculty ID to delete: ");
                scanf("%d", &id);
                deleteFaculty(id);
                saveFacultyData("faculties.txt");
                break;
            }
            case UPDATE_FACULTY_DETAILS: {
                int id;
                printf("Enter faculty ID to update: ");
                scanf("%d", &id);
                updateFaculty(id);
                saveFacultyData("faculties.txt");
                break;
            }
            case DISPLAY_FACULTIES:
                displayFacultyDetails();
                break;
            case SORT_FACULTIES_BY_ID:
                sortFacultiesByID();
                break;
            case SORT_FACULTIES_BY_NAME:
                sortFacultiesByName();
                break;
            case TOTAL_FACULTY_COUNT:
                printf("Total faculty count: %d\n", facultyCount);
                break;
            case SAVE_FACULTY:
                saveFacultyData("faculties.txt");
                break;
            case EXIT_FACULTY:
                printf("Program exited!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
            }
            break;
        }

        case FEES_OPERATIONS: {
            int feesChoice;
            printf("\n--- Fees Operations ---\n");
            printf("1. Insert Fees Record\n");
            printf("2. Display Fees Records\n");
            printf("3. Save to file\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &feesChoice);

            switch (feesChoice) {
            case INSERT_FEES_RECORD: {
                int studentID, receipt_number;
                float paid_amount;
                printf("Enter student ID: ");
                scanf("%d", &studentID);
                printf("Enter receipt number: ");
                scanf("%d", &receipt_number);
                printf("Enter paid amount: ");
                scanf("%f", &paid_amount);
                insertFees(studentID, receipt_number, paid_amount);
                break;
            }
            case DISPLAY_FEES_RECORDS:
                displayFeesDetails();
                break;
            case SAVE_FEES:
                saveFeesToFile("fees.txt");
                break;
            case EXIT_FEES:
                printf("Program exited!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
            }
            break;
        }

        case SECTION_OPERATIONS: {
            int sectionChoice;
            printf("\n--- Section Operations ---\n");
            printf("1. Insert Section Record\n");
            printf("2. Display Sections\n");
            printf("3. Save to file\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &sectionChoice);

            switch (sectionChoice) {
            case INSERT_SECTION: {
                int studentID, section_id;
                char section_name[20];
                printf("Enter student ID: ");
                scanf("%d", &studentID);
                printf("Enter section ID: ");
                scanf("%d", &section_id);
                printf("Enter section name: ");
                scanf(" %[^\n]", section_name);
                insertSection(studentID, section_id, section_name);
                break;
            }
            case DISPLAY_SECTIONS:
                displaySectionDetails();
                break;
            case SAVE_SECTION:
                saveSectionsToFile("section.txt");
                break;
            case EXIT_SECTION:
                printf("Program exited!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
            }
            break;
        }

        case EXIT_PROGRAM:
            printf("Program exited!\n");
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
