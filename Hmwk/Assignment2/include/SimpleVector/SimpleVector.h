// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range
   
   int top;

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);

   void push(const T&);
   void pull();
   int isEmpty() const  { return top == -1; }
   int isFull() const   { return top == arraySize - 1; }
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arraySize = s;
   // Allocate memory for the array.
   try
   {
      aptr = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 10;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   std::cout << "The Copy Constructor was looped through" << endl;
   // Copy the array size.
   arraySize = obj.arraySize;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// push function. Delivers the enter item onto the top  *
// of the stack. Returns a binary flag to determine the *
// outcome (successful or not).                         *
//*******************************************************
template <class T>
void SimpleVector<T>::push(const T& item)
{
   arraySize+=1;
   T *temp = new T[arraySize];

   for(int count = 0; count < arraySize; count++){
      if(count == arraySize-1){
         temp[count] = item;
         cout << "aptr[" << count << "] = " << aptr[count] << endl;
         cout << "temp[" << count << "] = " << temp[count] << endl;
      }
      else{
         *(temp + count) = aptr[count];
         cout << "aptr[" << count << "] = " << aptr[count] << endl;
         cout << "temp[" << count << "] = " << temp[count] << endl;

      }
   }
   delete [] aptr;

   aptr = new T[arraySize];
   for(int count = 0; count < arraySize; count++){
      aptr[count] = temp[count];
   }
   delete [] temp;


}

template <class T>
void SimpleVector<T>::pull()
{
   if((arraySize-1) == 0){
      cout << "Array already at 1 , cannot pull anymore" << endl;
   }
   else{
      arraySize-=1;
      T *temp = new T[arraySize];

      for(int count = 0; count < arraySize; count++){
         temp[count] = aptr[count];
      }

      delete [] aptr;
      aptr = new T[arraySize];

      for(int count = 0; count < arraySize; count++){
         aptr[count] = temp[count];
      }   

      delete [] temp;

   }
}
//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}
#endif