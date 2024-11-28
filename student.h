#ifndef STUDENT_H
#define STUDENT_H

struct Student {
    int id;
    const char *name[20];
    int age;
};

void insertStudent(int id, const char *name, int age);
void deleteStudent();
void updateStudent();
void displayStudentDetails();
void sortStudentsByID();
void sortStudentsByName();

extern struct Student *students;
extern int studentCount;

#endif
