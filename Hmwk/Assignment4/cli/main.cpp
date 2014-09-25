/* ===============================================
 * File:        main.cpp
 * Developer:   Albert Carrete
 * Date:        September 23, 2014
 * ==============================================*/

/* ==== System Libraries ==== */
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/* ==== User Libraries ==== */
#include "LnkdLst/LnkdLst.h"

int main(int argc, char** argv) {
    //Create a linked list
    LnkdLst list(0);
    //Append 3 more chains
    int clinks = 3;
    for(int i = 1; i <= clinks; i++){
        list.append(i);
    }
    //Print the data
    cout<<list.toString()<<endl;
    //Exit stage right!
    std::cout << "End of Program" << std::endl;

    return 0;
}