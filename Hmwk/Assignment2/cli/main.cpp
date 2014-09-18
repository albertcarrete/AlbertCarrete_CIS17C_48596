// Albert's Triangular Array
#include "SimpleVector/SimpleVector.h"

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {

	int size = 10;
	float value = 2.2;
	SimpleVector<float> simvec(size);
	cout << simvec.size() << endl;
	cout << simvec.getElementAt(8) << endl;

	simvec.push(value);
	cout << simvec.size() << endl;
	cout << simvec.getElementAt(8) << endl;
	cout << simvec.getElementAt(10) << endl;

	simvec.pull();
	simvec.pull();
	simvec.pull();

	cout << simvec.size() << endl;


	// cout << simvec.getElementAt(2) << endl;

	return 0;
}