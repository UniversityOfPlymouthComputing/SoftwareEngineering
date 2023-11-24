#include "studentrecord.h"
using namespace std;

//Function to display a record in the terminal
void printRecord(Record& r)
{
    cout << "SID:" << endl;
    cout << "   " << r.SID << endl;
    cout << "NAME:" << endl;
    cout << "   " << r.name << endl;
    cout << "ENROLLMENTS:" << endl;
    cout << "   ";
    for (string& st : r.enrollments) {
        cout << st << " ";
    }
    cout << endl;
    cout << "GRADES:" << endl;
    cout << "   ";
    for (float g : r.grades) {
        cout << g << " ";
    }
    cout << endl;
    if (!r.phone.empty()) {
        cout << "PHONE:" << endl;
        cout << "   " << r.phone << endl;
    }
}
