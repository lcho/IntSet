/** @file intset.h 
    @brief The IntSet Header File
    @details Top Down Design method and constructor initialization
    @author Lance Cho
    @author Terence Schumacher
    @description 
    @class IntSet
    

*/

#ifndef __INTSET_H
#define __INTSET_H
#include <iostream>

using namespace std;

class IntSet{
    
    
    // overloaded <<:
    //    prints all values in the set
    friend ostream& operator<<(ostream&, const IntSet&);
    
    // overloaded >>: takes any values except negative numbers
    //    input operator stops if number is invalid (negative numbers)
    friend istream& operator>>(istream&, IntSet&);
    
    
public:
    //Constructor
    IntSet(int = -1, int = -1, int = -1, int = -1, int = -1);
   
    //Arithmetic operators
    IntSet operator+(const IntSet &) const;   // add 2 sets
    IntSet operator-(const IntSet &) const;   // subtract 2 sets
    IntSet operator*(const IntSet &) const;   // multiply 2 sets
    IntSet operator=(const IntSet &) const;   // sets a set
    
    // boolean comparison operators
    bool operator==(const IntSet &) const;      // is object == parameter?
    bool operator!=(const IntSet &) const;      // is object != parameter?

    //assignment operators
    IntSet operator+=(const IntSet &) const;         //current object += parameter
    IntSet operator-=(const IntSet &) const;         //current object -= parameter
    IntSet operator*=(const IntSet &) const;         //current object *= parameter
    
    //basic functions
    bool insert(int);                       // instert value into set
    bool remove(int);                       // remove value from set
    bool isEmpty();               // check set for values
    bool isInSet(int);               // check number in set
   
private:
    int size;
    bool* set;
};


#endif
