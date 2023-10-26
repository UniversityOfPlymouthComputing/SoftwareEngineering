// FirstOOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;


class Person
{
private:
    string _name;
    unsigned int _age;
public:
    Person(string personName, unsigned int age)
    {
        _name = personName;
        _age = age;
    }

    void display() {
        cout << _name << " is " << _age << " years old" << endl;
    }

    void operator<<(string newName)
    {
        _name = newName;
    }
    
};


int main()
{
    Person p1("Sam", 33);
    p1.display();
    Person p2("Les", 51);
    p2.display();

    p1 << "Yoda";
    p1.display();
}
