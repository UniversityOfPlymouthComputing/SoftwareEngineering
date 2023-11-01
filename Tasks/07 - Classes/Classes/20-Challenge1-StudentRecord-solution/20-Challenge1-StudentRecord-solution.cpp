#include <iostream>
#include "StudentRecord.h"
using namespace std;

int main()
{
    cout << "Challenge 1\n";
    StudentRecord student1("Les", "Amigos", 12345);
    student1.display();
    

    //Test remaining member functions here
    student1.updateFirstName("Sam");
    string fullName = student1.getFullName();
    cout << fullName << endl;
    student1.display();

    student1.updateLastName("Smith");
    fullName = student1.getFullName();
    cout << fullName << endl;
    student1.display();

    int id = student1.getID();
    cout << id << endl;


}