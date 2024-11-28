#ifndef FACULTY_H
#define FACULTY_H

struct Faculty {
    int id;
    const char *name[50];
    const char *department[50];
    int age;
    const char *qualification[20];
};

void insertFaculty(int id, const char *name, const char *department,int age, const char *qualification);
void deleteFaculty(int id);
void updateFaculty(int id);
void displayFacultyDetails();
void sortFacultiesByID();
void sortFacultiesByName();

extern struct Faculty *faculties;
extern int facultyCount;

#endif

