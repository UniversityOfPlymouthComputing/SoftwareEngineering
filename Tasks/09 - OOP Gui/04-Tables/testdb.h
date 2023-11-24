#ifndef TESTDB_H
#define TESTDB_H

#include <iostream>
#include <fstream>

//Test data as a literal string
#define TESTSTR "#RECORD\n \
#SID\n \
    12345\n \
#NAME\n \
    Jo Kingly Blunt\n \
#ENROLLMENTS\n \
    COMP101 COMP102 COMP105 COMP110 COMP150\n \
#GRADES\n \
    54.0 67.5 33.1 78.4 47.1\n \
#PHONE\n \
    44-1234-567890\n \
\n\
#RECORD\n \
#SID\n \
    14351\n \
#NAME\n \
    Bee Hyve\n \
#ENROLLMENTS\n \
    COMP101 COMP102 COMP105 COMP110 COMP155 COMP165\n \
#GRADES\n \
    84.3 54.7 91.4 80.4 40.5 67.5\n \
\n\
#RECORD\n \
#NAME\n \
    Gee Rafferty\n \
#ENROLLMENTS\n \
    ELEC101 ELEC133 COMP101 PROJ101 GIT101\n \
#SID\n \
    15309\n \
#GRADES\n \
    95.0 37.5 55.0 65.5 0.0\n \
    "

//Functions

//Create a test database with filename `fileName`
void createTestDB(std::string fileName);

#endif // TESTDB_H
