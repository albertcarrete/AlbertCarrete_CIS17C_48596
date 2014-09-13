/* ================================
    File:       Triangular.h
    Developer:  Albert Carrete
    Date:       09-12-14
=================================== */
#ifndef TRIANGULAR_H
#define TRIANGULAR_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

template <class T> 
class Triangular
{
public:
	Triangular();
    Triangular(int,int);
	~Triangular();
	void FillTriangularArray(T,T);
	void PrintTriangularArray();

private:
    int rows_, cols_;
    int * columnArray;
    T maxr, minr;
    T ** triangularArray;
};
/* Constructor
==========================*/
template <class T>
Triangular<T>::Triangular(){
    rows_ = 5;
    cols_ = 5;
}
template <class T>
Triangular<T>::Triangular(int rows, int cols){
    rows_ = rows;
    cols_ = cols;
}
/* Deconstructor
==========================*/
template <class T>
Triangular<T>::~Triangular(){
        delete []columnArray;

        for(int row=0; row < rows_; row++){
            delete []triangularArray[row];
        }
        //Destroy row pointers
        delete []triangularArray;
}
/* Fill Array
==========================*/
template <class T>
void Triangular<T>::FillTriangularArray(T maxr, T minr){

	columnArray = new int [cols_];
	// Create our column array
	for(int col = 0; col < cols_; col++){
        columnArray[col] = rand()%cols_+1;
    }

    // Create triangular array
    triangularArray = new T* [rows_];
    for(int row = 0; row < rows_; row++){
        triangularArray[row] = new T [columnArray[row]];
    }

    //Fill triangular array
    for(int row=0;row<rows_;row++){
        for(int col=0;col<columnArray[row];col++){
            triangularArray[row][col] = minr + static_cast <T> (rand()) /( static_cast <T> (RAND_MAX/(maxr-minr)));
            // triangularArray[row][col]=rand()%90+10;
        }
    }
}
/* Print Array
==========================*/
template <class T>
void Triangular<T>::PrintTriangularArray(){
    for(int row=0; row < rows_; row++){
        for(int col=0;col<columnArray[row];col++){
            std::cout << std::fixed << std::setprecision(2) << triangularArray[row][col] << " ";
            // std::cout << triangularArray[row][col]<<" ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

#endif 