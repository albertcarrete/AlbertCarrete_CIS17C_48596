/*
	Title:		Recursion
	Created by: Albert Carrete
	Date: 		November 4th 2014
*/

#include <iostream>

float FV(float,float,int);

int main(int argc, char const *argv[])
{	
	std::cout << "$" << FV(15300,.05,10) << std::endl;
	return 0;
}

float FV(float CF, float r, int t){
	if(t){
		return ((1+r)*(FV(CF,r,t-1)));
	}
	else{
		return CF;
	}
}

/*=============================================================
						DETAILS

	Create a sum function that has logN call like the
	max function from class. 

	Create a recursive savings function FV = PV * (1+i)^n
	Savings = (pv,i,n) where pv = present value i =
	interest rate %/year and n = number of years

==============================================================*/