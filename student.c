#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

struct Student *students = NULL;
int studentCount = 0;

void insertStudent(int id, const char *name, int age, const char *contactNumber) {
    students = realloc(students, (studentCount + 1) * sizeof(struct Student));
    if (!students) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    students[studentCount].id = id;
    strncpy(students[studentCount].name, name, sizeof(students[studentCount].name) - 1);
    students[studentCount].name[sizeof(students[studentCount].name) - 1] = '\0';
    students[studentCount].age = age;
    strncpy(students[studentCount].contactNumber, contactNumber, sizeof(students[studentCount].contactNumber) - 1);
    students[studentCount].contactNumber[sizeof(students[studentCount].contactNumber) - 1] = '\0';
    studentCount++;
    printf("Student added successfully!\n");
}

void deleteStudent(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            students = realloc(students, studentCount * sizeof(struct Student));
            printf("Student deleted successfully!\n");
            return;
        }
    }
    printf("Student with ID %d not found!\n", id);
}

void updateStudent(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Enter new name: ");
            scanf(" %[^\n]", students[i].name);
            printf("Enter new age: ");
            scanf("%d", &students[i].age);
            printf("Enter new contact number: ");
            scanf(" %[^\n]", students[i].contactNumber);
            printf("Student updated successfully!\n");
            return;
        }
    }
    printf("Student with ID %d not found!\n", id);
}

void displayStudentDetails() {
    if (studentCount == 0) {
        printf("No students found!\n");
        return ;
    }
    else
    {
        printf("------Student Details:------\n");
        for (int i = 0; i < studentCount; i++) {
            printf("ID: %d, Name: %s, Age: %d, Contact Number: %s\n",
                   students[i].id, students[i].name, students[i].age, students[i].contactNumber);
        }
        return ;
    }
}

void sortStudentsByID() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = i + 1; j < studentCount; j++) {
            if (students[i].id > students[j].id) {
                struct Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Students sorted by ID.\n");
    displayStudentDetails();
}

void sortStudentsByName() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = i + 1; j < studentCount; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                struct Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Students sorted by Name.\n");
    displayStudentDetails();
}
