#ifndef SECTION_H
#define SECTION_H
#include "student.h"

struct Section {
    struct Student *studentDetails;
    int section_id;
    const char *section_name[20];
};

void insertSection(int studentID, int section_id, const char *section_name);
void displaySectionDetails();

extern struct Section *sections;
extern int sectionCount;

#endif
