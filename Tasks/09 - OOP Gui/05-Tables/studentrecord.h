#ifndef STUDENTRECORD_H
#define STUDENTRECORD_H
#include <iostream>
#include <vector>

//Basic data structure for a record
struct Record {
    int SID;        //Student ID
    std::string name;    //Student Name
    std::vector<std::string> enrollments;
    std::vector<float> grades;
    std::string phone;
};

void printRecord(Record& r);

#endif // STUDENTRECORD_H
