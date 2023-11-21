#include <iostream>
using namespace std;

class SomeObject {
    private:
    int age;

    public:
    SomeObject(int myAge) {
        age = myAge;
    }
    int getAge() {
        return age;
    }
};

class Util {
    protected:
    string myName;
    SomeObject ageObj;

    public:
    Util(string name, int myAge) : ageObj(myAge) {
        myName = "Dr " + name;
        cout << myName << endl << ageObj.getAge() << endl;
    }
    string getName() {
        return myName;
    }
};

int main()
{
    Util p1("Sam", 45);
    cout << p1.getName() << endl;
    return 0;
}