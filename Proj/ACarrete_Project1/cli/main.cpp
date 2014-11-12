//Execution begins here

// #include "helloworld/Hello.h"
// #include "SDL/SDL.h"
#include "Handler/AUDHandler.h"
#include <cstdlib>
#include <iostream>
#include <stdint.h>

using namespace std;

int main(int argc, char** argv)
{	
	int16_t sixteen_bit; 
	cout << numeric_limits<int16_t>::max() << endl;
	cout << numeric_limits<int16_t>::min() << endl;
	sixteen_bit = 40923;

	cout << sixteen_bit << endl;

	AUDHandler aud;
	aud.init();
	return 0;
}