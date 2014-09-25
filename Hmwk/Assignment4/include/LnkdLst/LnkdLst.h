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
    void append(int);
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

#endif	/* LNKDLST_H */

