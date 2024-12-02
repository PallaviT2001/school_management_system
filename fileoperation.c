#include "fileoperation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "faculty.h"
#include "fees.h"
#include "section.h"

void saveStudentsToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for saving!\n");
        return;
    }
    fprintf(file, "%d\n", studentCount);
    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "%d %s %d %s\n", students[i].id, students[i].name, students[i].age,students[i].contactNumber);
    }
    fclose(file);
    printf("Student data saved successfully to %s.\n", filename);
}

void loadStudentsFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("No existing data file found. Starting fresh.\n");
        return;
    }

    fscanf(file, "%d", &studentCount);
    if (studentCount > 0) {
        students = malloc(studentCount * sizeof(struct Student));
        if (students == NULL) {
            perror("Memory allocation failed while loading data!\n");
            fclose(file);
            exit(1);
        }
        for (int i = 0; i < studentCount; i++) {
            fscanf(file, "%d %s %d %s", &students[i].id, students[i].name, &students[i].age,students[i].contactNumber);
        }
    }

    fclose(file);
    printf("Student data loaded successfully from file.\n");
}

void saveFacultyData(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Unable to open file for saving data.\n");
        return;
    }

    fprintf(file, "%d\n", facultyCount);
    for (int i = 0; i < facultyCount; i++) {
        fprintf(file, "%d %s %s %d %s\n", faculties[i].id, faculties[i].name, faculties[i].department,
                faculties[i].age, faculties[i].qualification);
    }
    fclose(file);
    printf("Faculty data saved successfully to %s.\n", filename);
}

void loadFacultyData(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open file for loading data.\n");
        return;
    }

    fscanf(file, "%d", &facultyCount);
    faculties = realloc(faculties, facultyCount * sizeof(struct Faculty));
    for (int i = 0; i < facultyCount; i++) {
        fscanf(file, "%d %s %s %d %s", &faculties[i].id, faculties[i].name, faculties[i].department,
               &faculties[i].age, faculties[i].qualification);
    }

    fclose(file);
    printf("Faculty data loaded successfully from %s.\n", filename);
}

void saveFeesToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing!\n");
        return;
    }
    fprintf(file, "%d\n", feesCount);
    for (int i = 0; i < feesCount; i++) {
        fprintf(file, "%d %f %d %s\n", feesRecords[i].receipt_number, feesRecords[i].paid_amount,
                feesRecords[i].studentDetails->id, feesRecords[i].studentDetails->name);
    }
    fclose(file);
    printf("Fees records saved successfully to %s.\n", filename);
}

void loadFeesFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading!\n");
        return;
    }
    fscanf(file, "%d", &feesCount);
    feesRecords = realloc(feesRecords, feesCount * sizeof(struct Fees));
    for (int i = 0; i < feesCount; i++) {
        feesRecords[i].studentDetails = malloc(sizeof(struct Student));
        if (feesRecords[i].studentDetails == NULL) {
            perror("Memory allocation failed for studentDetails in feesRecords!");
            fclose(file);
            exit(1);
        }
        fscanf(file, "%d %f %d %s", &feesRecords[i].receipt_number,
               &feesRecords[i].paid_amount,
               &feesRecords[i].studentDetails->id,
               feesRecords[i].studentDetails->name);

    }
    fclose(file);
    printf("Fees records loaded successfully from %s.\n", filename);
}

void saveSectionsToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing!\n");
        return;
    }
    fprintf(file, "%d\n", sectionCount);
    for (int i = 0; i < sectionCount; i++) {
        fprintf(file, "%d %s %d %s\n", sections[i].section_id, sections[i].section_name,
                sections[i].studentDetails->id, sections[i].studentDetails->name);
    }
    fclose(file);
    printf("Sections saved successfully to %s.\n", filename);
}

void loadSectionsFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading!\n");
        return;
    }

    fscanf(file, "%d", &sectionCount);
    struct Section *temp = realloc(sections, sectionCount * sizeof(struct Section));
    if (temp == NULL) {
        perror("Memory reallocation failed for sections!");
        fclose(file);
        exit(1);
    }
    sections = temp;

    for (int i = 0; i < sectionCount; i++) {
        sections[i].studentDetails = malloc(sizeof(struct Student));
        if (sections[i].studentDetails == NULL) {
            perror("Memory allocation failed for studentDetails in sections!");
            fclose(file);
            exit(1);
        }
        fscanf(file, "%d %s %d %s", &sections[i].section_id,
               sections[i].section_name,
               &sections[i].studentDetails->id,
               sections[i].studentDetails->name);
    }

    fclose(file);
    printf("Sections loaded successfully from %s.\n", filename);
}

