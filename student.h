#ifndef STUDENT_H
#define STUDENT_H

struct Student {
    int id;
    char name[50];
    int age;
    char contactNumber[15];
};

void insertStudent(int id, const char *name, int age, const char *contactNumber);
void deleteStudent(int id);
void updateStudent(int id);
void displayStudentDetails();
void sortStudentsByID();
void sortStudentsByName();

extern struct Student *students;
extern int studentCount;

#endif
