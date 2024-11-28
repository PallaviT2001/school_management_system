#include "fileoperation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "faculty.h"
#include "fees.h"
#include "section.h"

int main1() {
    int choice;
    const char *admin_username = "admin123";
    const char *admin_password = "123admin";

    char ad_username[20];
    char ad_password[20];

    printf("Enter admin id: ");
    scanf("%s", ad_username);

    printf("Enter admin password: ");
    scanf("%s", ad_password);

    if (strcmp(ad_username, admin_username) == 0 && strcmp(ad_password, admin_password) == 0) {

        printf("Login successful\n");
        loadStudentsFromFile("students.dat");
        loadFacultyData("faculty_data.bin");
        loadFeesFromFile("fees_records.dat");
        loadSectionsFromFile("section_records.dat");

        while (1) {
            printf("\n--- select operation---\n");
            printf("1. Perform student operations\n");
            printf("2. Perform faculty operations\n");
            printf("3. Perform fees operations\n");
            printf("4. Perform section operations\n");
            printf("5. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
            case 1: {
                int studentChoice;
                printf("\n--- Student Operations ---\n");
                printf("1. Insert Student\n");
                printf("2. Delete Student\n");
                printf("3. Update Student Details\n");
                printf("4. Display Students\n");
                printf("5. Sort and Display Students by ID\n");
                printf("6. Sort and Display Students by Name\n");
                printf("7. Total Student Count\n");
                printf("8. save data and Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &studentChoice);

                switch (studentChoice) {
                case 1: {
                    int id, age;
                    char name[50];
                    printf("Enter student ID: ");
                    scanf("%d", &id);
                    printf("Enter student name: ");
                    scanf(" %[^\n]", name);
                    printf("Enter student age: ");
                    scanf("%d", &age);
                    insertStudent(id, name, age);
                    break;
                }
                case 2: {
                    int id;
                    printf("Enter student ID to delete: ");
                    scanf("%d", &id);
                    deleteStudent(id);
                    break;
                }
                case 3: {
                    int id;
                    printf("Enter student ID to update: ");
                    scanf("%d", &id);
                    updateStudent(id);
                    break;
                }
                case 4:
                    displayStudentDetails();
                    break;
                case 5:
                    sortStudentsByID();
                    break;
                case 6:
                    sortStudentsByName();
                    break;
                case 7:
                    printf("Total student count: %d\n", studentCount);
                    break;
                case 8:
                    saveStudentsToFile("students.dat");
                    printf("Data saved successfully. Exiting...\n");
                    free(students);
                    exit(0);
                default:
                    printf("Invalid choice!\n");
                }
                break;
            }

            case 2: {
                int facultyChoice;
                printf("\n--- Faculty Operations ---\n");
                printf("1. Insert Faculty\n");
                printf("2. Delete Faculty\n");
                printf("3. Update Faculty Details\n");
                printf("4. Display Faculties\n");
                printf("5. Sort and Display Faculties by ID\n");
                printf("6. Sort and Display Faculties by Name\n");
                printf("7. Total Faculty Count\n");
                printf("8. save to file and exit\n");
                printf("Enter your choice: ");
                scanf("%d", &facultyChoice);

                switch (facultyChoice) {
                case 1: {
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
                case 2: {
                    int id;
                    printf("Enter faculty ID to delete: ");
                    scanf("%d", &id);
                    deleteFaculty(id);
                    break;
                }
                case 3: {
                    int id;
                    printf("Enter faculty ID to update: ");
                    scanf("%d", &id);
                    updateFaculty(id);
                    break;
                }
                case 4:
                    displayFacultyDetails();
                    break;
                case 5:
                    sortFacultiesByID();
                    break;
                case 6:
                    sortFacultiesByName();
                    break;
                case 7:
                    printf("Total faculty count: %d\n", facultyCount);
                    break;
                case 8:
                    saveFacultyData("faculty_data.bin");
                    printf("Exiting program. Data saved.\n");
                    exit(0);
                default:
                    printf("Invalid choice!\n");
                }
                break;
            }

            case 3: {
                int feesChoice;
                printf("\n--- Fees Operations ---\n");
                printf("1. Insert Fees Record\n");
                printf("2. Display Fees Records\n");
                printf("3. Save data to file and Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &feesChoice);

                switch (feesChoice) {
                case 1: {
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
                case 2:
                    displayFeesDetails();
                    break;
                case 3:
                    saveFeesToFile("fees_records.dat");
                    printf("Exiting program. Data saved.\n");
                    exit(0);
                default:
                    printf("Invalid choice!\n");
                }
                break;
            }

            case 4: {
                int sectionChoice;
                printf("\n--- Section Operations ---\n");
                printf("1. Insert Section\n");
                printf("2. Display Sections\n");
                printf("3. Save dats to file and Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &sectionChoice);

                switch (sectionChoice) {
                case 1: {
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
                case 2:
                    displaySectionDetails();
                    break;
                case 3:
                    saveSectionsToFile("section_records.dat");
                    printf("Exiting program. Data saved.\n");
                    exit(0);
                default:
                    printf("Invalid choice!\n");
                }
                break;
            }

            case 5:
                printf("Program exited!\n");
                exit(0);
            }
        }
    } else {
        printf("Invalid Admin ID or Password. Try again!\n");
        return 1;
    }
    return 0;
}
