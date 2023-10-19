#include <iostream>
using namespace std;

void Butler(void);

int main(void) {

	Butler();
	cout << "Now again" << endl;
	Butler();
	return EXIT_SUCCESS;
}

void Butler(void)
{
	static int bellRings = 0;
	bellRings++;
    cout << "You called " << bellRings << " times?" << endl;
}

