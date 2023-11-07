#include <iostream>
#include "Pets.h"
#include <vector>
using namespace std;


class MedicalCase {
public:

private:
    Pet _client;    //Composition - this needs parameters to be instantiated!
    int _vetID;
    float _bill;

public:
    // Constructor - note the initialisation list ensure _client is instantiated before the constructor runs 
    MedicalCase(string name, int age, int vid) : _client(name, age)
    {
        _vetID = vid;
        _bill = 0.0f;
        cout << "Case set up for " << _client.getName() << endl;
    }

    // Add a charge to the bill
    void addCharge(float cost) {
        if (cost > 0.0) {
            _bill += cost;
        }
    }

    // For a list of items
    void addCharge(vector<float> costs) {
        for (unsigned int n = 0; n < costs.size(); n++) {
            addCharge(costs[n]);
        }
    }

    //Generate a statement to send to the customer
    string generateStatement() {
        ostringstream str;  // Used to build a complex string
        str << endl;
        str << "Statement for " << _client.getName() << endl;
        str << "Age: " << _client.getAge() << endl;
        str << "Vet Assigned: " << _vetID << endl;
        str << "Total Outstanding: GBP" << _bill << endl << endl;
        return str.str();
    }
};


int main()
{
    //Encapsulate a new Pet inside a MedicalCase (using composition)
    MedicalCase case1("Tiddles", 13, 101);

    //Initial charge
    case1.addCharge(75.0f);
    cout << case1.generateStatement();

    //Batch of charges
    vector<float> charges;
    charges.push_back(225.0f);
    charges.push_back(100.0f);
    case1.addCharge(charges);
    
    cout << case1.generateStatement();
}





