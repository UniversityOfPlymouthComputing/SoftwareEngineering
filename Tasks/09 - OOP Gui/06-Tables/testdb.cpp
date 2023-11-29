#include "testdb.h"
using namespace std;

void createTestDB(string fileName)
{
    //Does the file exist?
    ifstream ip(fileName);
    if (ip.is_open()) {
        cout << fileName << " exists" << endl;
        ip.close();
        return;
    }

    //Create some test data
    cout << "Creating starter database for testing" << endl;
    ofstream op(fileName);
    op << TESTSTR;
    op.close();
}
