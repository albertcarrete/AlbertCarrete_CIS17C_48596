//Execution begins here

#include "helloworld/Hello.h"

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;


void print(int);
int sum(int);
float FV(float,float,int);
void FutureValue(float,float,int);
int countdown(int);
int power(int,int);
int main(int argc, char const *argv[])
{	
	// print(10);
	countdown(20);
	cout << endl;

	cout << sum(4) << endl;

	// cout << FV(100.30,.20,10) << endl;
	cout << FV(10000.00,.05,10) << endl;
	FutureValue(10000.00,.05,10);
	cout << power(2,5) << endl;

	return 0;
}

int countdown(int y){
	cout << y << " ";
	if(y==1){
		return 1;
	}
	else{
		return countdown(y-1);
	}
}
void print(int p){
	if(p==0){
		return;
	}
	print(p-1);
	cout << p << " ";
	return;
}
int sum (int num){
	if(num==0){
		return 0;
	}
	return (sum(num-1)+(num));
}
int power(int base, int exp){
	if(exp>=1){
		return base * (power(base,exp - 1));
	}
	else{
		return 1;
	}
}
float FV(float pv, float ir, int years){
	if(years){
		return ((1+ir)*(FV(pv,ir,years-1)));
	}
	else{
		return pv;
	}
}
void FutureValue(float pv, float ir, int years){
	// float real = 0;
	// if(years>=1){
	// 	return (pv)
	// 	real = ((1+ir)*(FV(pv,ir,years-1)));
	// }
	// cout << real*(pv) << endl;
}