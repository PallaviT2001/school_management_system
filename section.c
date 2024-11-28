#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "section.h"
#include "student.h"

struct Section *sections = NULL;
int sectionCount = 0;

void insertSection(int studentID, int section_id, const char *section_name) {
    extern struct Student *students;
    extern int studentCount;

    sections = realloc(sections, (sectionCount + 1) * sizeof(struct Section));
    if (sections == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == studentID) {
            sections[sectionCount].studentDetails = &students[i];
            sections[sectionCount].section_id = section_id;
            strcpy(sections[sectionCount].section_name, section_name);
            sectionCount++;
            printf("Section record added successfully!\n");
            return;
        }
    }

    printf("Student with ID %d not found!\n", studentID);
}

void displaySectionDetails() {
    printf("\nSection Details:\n");
    for (int i = 0; i < sectionCount; i++) {
        printf("Section ID: %d, Section Name: %s\n", sections[i].section_id, sections[i].section_name);
        printf("Student ID: %d, Name: %s, Age: %d\n",
               sections[i].studentDetails->id,
               sections[i].studentDetails->name,
               sections[i].studentDetails->age);
    }
}
