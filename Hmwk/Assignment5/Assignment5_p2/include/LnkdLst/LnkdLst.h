/* 
 * File:   LnkdLst.h
 * Author: Dr. Mark E. Lehr
 * Created on September 18, 2014, 3:09 PM
 */

#ifndef LNKDLST_H
#define	LNKDLST_H

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class LnkdLst {
public:
    LnkdLst(int);
    // LnkdLst(const LnkdLst &);
    void append(int);
    void prepend(int);
    void first();
    void last();
    void insertBefore(int,int);
    void insertAfter(int,int);
    string toString();
    virtual ~LnkdLst();
private:
    struct Node{
         int data;
         Node *next;
    };
    Node *head;
    // Node *worker;
};
// LnkdLst::LnkdLst(const LnkdLst &obj){
    
// }
#endif	/* LNKDLST_H */

