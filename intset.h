/**
File: inset.h
  Project: lab2

  Creator: Terence Schumacher on 10/8/13.
  Copyright: (c) 2013 Terence Schumacher. All rights reserved.
*/

#ifndef __INTSET_H
#define __INTSET_H
#include <iostream>

using namespace std;

class IntSet{
    
    
    // overloaded <<: prints "DIVIDE BY ZERO ERROR!!!" if denominator is zero,
    //    prints whole numbers without denominator (as ints), otherwise uses '/'
    friend ostream& operator<<(ostream&, const IntSet&);
    
    // overloaded >>: takes 2 ints as numerator and denominator, does no
    //    error checking, standard C casting between floats, char, etc occurs
    friend istream& operator>>(istream&, IntSet&);
    
    
public:
    IntSet();
    IntSet(int = -1, int = -1, int = -1, int = -1, int = -1);
    
    // To grab the size of the IntSet
    int getSize() const;
    
    //Arithmetic operators
    IntSet operator+(const IntSet &) const;   // add 2 sets
    IntSet operator-(const IntSet &) const;   // subtract 2 sets
    IntSet operator*(const IntSet &) const;   // multiply 2 sets
    IntSet operator=(const IntSet &) const;   // sets a set
    
    // boolean comparison operators
    bool operator==(const IntSet &) const;      // is object == parameter?
    bool operator!=(const IntSet &) const;      // is object != parameter?

    IntSet& operator+=(const IntSet &);         //current object += parameter
    IntSet& operator-=(const IntSet &);         //current object -= parameter
    IntSet& operator*=(const IntSet &);         //current object *= parameter
    bool insert(int);
    bool remove(int);
    void isEmpty(IntSet set);
    void isInSet(int number);
   
private:
    int size;
    bool* set;
};


#endif
