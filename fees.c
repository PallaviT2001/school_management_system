#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fees.h"
#include "student.h"

struct Fees *feesRecords = NULL;
int feesCount = 0;

void insertFees(int studentID, int receipt_number, float paid_amount) {
    feesRecords = realloc(feesRecords, (feesCount + 1) * sizeof(struct Fees));
    if (feesRecords == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == studentID) {
            feesRecords[feesCount].studentDetails = &students[i];
            feesRecords[feesCount].receipt_number = receipt_number;
            feesRecords[feesCount].paid_amount = paid_amount;
            feesCount++;
            printf("Fees record added successfully!\n");
            return;
        }
    }
    printf("Student with ID %d not found!\n", studentID);
}

void displayFeesDetails() {
    printf("\nFees Details:\n");
    for (int i = 0; i < feesCount; i++) {
        printf("Receipt Number: %d, Paid Amount: %.2f\n", feesRecords[i].receipt_number, feesRecords[i].paid_amount);
        printf("Student ID: %d, Name: %s, Age: %d\n",
               feesRecords[i].studentDetails->id,
               feesRecords[i].studentDetails->name,
               feesRecords[i].studentDetails->age);
    }
}
