//Execution begins here

// #include "helloworld/Hello.h"
#include "SDL/SDL.h"
#include "Handler/AUDHandler.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{	
	AUDHandler aud;
	aud.init();
	return 0;
}