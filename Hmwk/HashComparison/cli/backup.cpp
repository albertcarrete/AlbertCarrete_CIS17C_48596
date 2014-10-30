//Execution begins here

#include "helloworld/Hello.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// look up trig identities
int main(int argc, char const *argv[])
{	
	Hello hello;

	int z = 0;
	string name[] = {
		"john", "bobby", "dear", 
        "test1", "catherine", "nomi", 
        "shinta", "martin", "abe","aaron", 
        "may", "zeno", "zack", "angeal", "gabby"	
    };

    int N = sizeof(name)/sizeof(name[0]);
    sort(name,name+N);

    for(int i = 0; i < N; i++){
    	cout << name[i] << endl;
    }
	return 0;
}
