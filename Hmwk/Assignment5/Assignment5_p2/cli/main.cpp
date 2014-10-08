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
// #include "LnkdLst/LnkdLst.h"
#include "LinkedList/LinkedList.h"

int main(int argc, char** argv) {

    LinkedList<int> list;
    list.Append(4);
    list.Append(7);
    list.Append(6);
    cout << "Head = " << list.First() << std::endl;
    cout << "Tail = " << list.Last() << std::endl;
    list.Extract(4);
    cout << "Head = " << list.First() << std::endl;
    cout << "Tail = " << list.Last() << std::endl;
    list.Prepend(10);
    cout << "Head = " << list.First() << std::endl;
    cout << "Tail = " << list.Last() << std::endl;
    std::cout << "End of Program" << std::endl;

    return 0;
}