/* ================================
    File:       main.cpp
    Developer:  Albert Carrete
    Date:       09-12-14
=================================== */
#include "triangular/Triangular.h"
//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    
    srand(static_cast<unsigned int>(time(0)));

    Triangular <float> tri;
    tri.FillTriangularArray(9.0,0.0); // Max and min random values
    tri.PrintTriangularArray();

    Triangular <int> tri2;
    tri2.FillTriangularArray(9,0);
    tri2.PrintTriangularArray();


    //Exit stage right
    return 0;
}
