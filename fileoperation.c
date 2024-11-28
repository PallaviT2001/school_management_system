#include "fileoperation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "faculty.h"
#include "fees.h"
#include "section.h"

void saveStudentsToFile(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file for saving!\n");
        return;
    }
    fwrite(&studentCount, sizeof(int), 1, file);

    if (studentCount > 0) {
        fwrite(students, sizeof(struct Student), studentCount, file);
    }

    fclose(file);
}

void loadStudentsFromFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("No existing data file found. Starting fresh.\n");
        return;
    }

    fread(&studentCount, sizeof(int), 1, file);

    if (studentCount > 0) {
        students = malloc(studentCount * sizeof(struct Student));
        if (students == NULL) {
            printf("Memory allocation failed while loading data!\n");
            fclose(file);
            exit(1);
        }
        fread(students, sizeof(struct Student), studentCount, file);
    }

    fclose(file);
    printf("Student data loaded successfully from file.\n");
}


void saveFacultyData(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Unable to open file for saving data.\n");
        return;
    }

    fwrite(&facultyCount, sizeof(int), 1, file);
    fwrite(faculties, sizeof(struct Faculty), facultyCount, file);

    fclose(file);
    printf("Faculty data saved successfully!\n");
}

void loadFacultyData(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Unable to open file for loading data.\n");
        return;
    }

    fread(&facultyCount, sizeof(int), 1, file);
    faculties = realloc(faculties, facultyCount * sizeof(struct Faculty));

    fread(faculties, sizeof(struct Faculty), facultyCount, file);

    fclose(file);
    printf("Faculty data loaded successfully!\n");
}


void saveFeesToFile(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    fwrite(&feesCount, sizeof(int), 1, file);
    for (int i = 0; i < feesCount; i++) {
        fwrite(&feesRecords[i].receipt_number, sizeof(int), 1, file);
        fwrite(&feesRecords[i].paid_amount, sizeof(float), 1, file);
        fwrite(feesRecords[i].studentDetails, sizeof(struct Student), 1, file);
    }
    fclose(file);
    printf("Fees records saved successfully to %s.\n", filename);
}
void loadFeesFromFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }
    fread(&feesCount, sizeof(int), 1, file);
    feesRecords = realloc(feesRecords, feesCount * sizeof(struct Fees));
    if (feesRecords == NULL) {
        printf("Memory allocation failed!\n");
        fclose(file);
        return;
    }
    for (int i = 0; i < feesCount; i++) {
        fread(&feesRecords[i].receipt_number, sizeof(int), 1, file);
        fread(&feesRecords[i].paid_amount, sizeof(float), 1, file);
        feesRecords[i].studentDetails = malloc(sizeof(struct Student));
        fread(feesRecords[i].studentDetails, sizeof(struct Student), 1, file);
    }
    fclose(file);
    printf("Fees records loaded successfully from %s.\n", filename);
}

void saveSectionsToFile(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    fwrite(&sectionCount, sizeof(int), 1, file);
    for (int i = 0; i < sectionCount; i++) {
        fwrite(&sections[i].section_id, sizeof(int), 1, file);
        fwrite(sections[i].section_name, sizeof(char), 50, file);
        fwrite(sections[i].studentDetails, sizeof(struct Student), 1, file);
    }
    fclose(file);
    printf("Sections saved successfully to %s.\n", filename);
}
void loadSectionsFromFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }
    fread(&sectionCount, sizeof(int), 1, file);
    sections = realloc(sections, sectionCount * sizeof(struct Section));
    if (sections == NULL) {
        printf("Memory allocation failed!\n");
        fclose(file);
        return;
    }
    for (int i = 0; i < sectionCount; i++) {
        fread(&sections[i].section_id, sizeof(int), 1, file);
        fread(sections[i].section_name, sizeof(char), 50, file);
        sections[i].studentDetails = malloc(sizeof(struct Student));
        fread(sections[i].studentDetails, sizeof(struct Student), 1, file);
    }
    fclose(file);
    printf("Sections loaded successfully from %s.\n", filename);
}



