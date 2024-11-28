#ifndef FEES_H
#define FEES_H

struct Fees {
    struct Student *studentDetails;
    int receipt_number;
    float paid_amount;
};

void insertFees(int studentID, int receipt_number, float paid_amount);
void displayFeesDetails();

extern struct Fees *feesRecords;
extern int feesCount;

#endif
