#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "faculty.h"

struct Faculty *faculties = NULL;
int facultyCount=0;

void insertFaculty(int id, const char *name, const char *department,int age, const char *qualification) {
    faculties = realloc(faculties, (facultyCount + 1) * sizeof(struct Faculty));
    if (faculties == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    faculties[facultyCount].id = id;
    strcpy(faculties[facultyCount].name, name);
    strcpy(faculties[facultyCount].department, department);
    faculties[facultyCount].age=age;
    strcpy(faculties[facultyCount].qualification, qualification);
    facultyCount++;
    printf("Faculty added successfully!\n");
}

void deleteFaculty(int id) {
    for (int i = 0; i < facultyCount; i++) {
        if (faculties[i].id == id) {
            for (int j = i; j < facultyCount - 1; j++) {
                faculties[j] = faculties[j + 1];
            }
            facultyCount--;
            faculties = realloc(faculties, facultyCount * sizeof(struct Faculty));
            printf("Faculty deleted successfully!\n");
            return;
        }
    }
    printf("Faculty not found!\n");
}

void updateFaculty(int id) {
    for (int i = 0; i < facultyCount; i++) {
        if (faculties[i].id == id) {
            printf("Enter new name: ");
            scanf(" %[^\n]", faculties[i].name);
            printf("Enter new department: ");
            scanf(" %[^\n]", faculties[i].department);
            printf("Faculty updated successfully!\n");
            return;
        }
    }
    printf("Faculty not found!\n");
}

void displayFacultyDetails() {
    printf("\nFaculty Details:\n");
    for (int i = 0; i < facultyCount; i++) {
        printf("ID: %d, Name: %s, Department: %s,Age: %d,Qualification: %s\n",
               faculties[i].id, faculties[i].name, faculties[i].department,faculties[i].age,faculties[i].qualification);
    }
}

void sortFacultiesByID() {
    for (int i = 0; i < facultyCount - 1; i++) {
        for (int j = i + 1; j < facultyCount; j++) {
            if (faculties[i].id > faculties[j].id) {
                struct Faculty temp = faculties[i];
                faculties[i] = faculties[j];
                faculties[j] = temp;
            }
        }
    }
    printf("Faculties sorted by ID.\n");
    displayFacultyDetails();
}

void sortFacultiesByName() {
    for (int i = 0; i < facultyCount - 1; i++) {
        for (int j = i + 1; j < facultyCount; j++) {
            if (strcmp(faculties[i].name, faculties[j].name) > 0) {
                struct Faculty temp = faculties[i];
                faculties[i] = faculties[j];
                faculties[j] = temp;
            }
        }
    }
    printf("Faculties sorted by Name.\n");
    displayFacultyDetails();
}
