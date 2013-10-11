/**
 @file intset.cpp
 
 */

#include "intset.h"


IntSet::IntSet(int value1, int value2, int value3, int value4, int value5){
    
    int values[] = {value1, value2, value3, value4, value5};
    int max = 0;
    for (int counter = 0; counter < 5; counter++){
        if (values[counter] > max){
            max = values[counter];
        }
        
        // for testting - please remove
        // cout << max << endl;
    }
    
    set = new bool[max+1];
    size = max+1;
    for(int counter=0; counter < size; counter++){
        set[counter] = false;
        // cout << set[counter] << endl;
    }
    for(int counter=0; counter < 5; counter++){
        if (values[counter] >= 0){
            set[ values[counter] ] = true;
        }
        
    }
    
    /*  for testing
     for(int counter=0; counter < size; counter++){
     cout << set[counter] << " ";
     }
     */
    
    
    
    
    /* not needed - please remove
     number = value < 0 ? 0: value;
     
     bool set[SIZE];
     for (int i = 0; i < sizeof(set); i++) {
     
     set[i] = false;
     }
     */
}


//----------------------------------------------------------------------------
// getSize()
// returns the private data 'size' of the IntSet
int IntSet::getSize() const {
    return size;
}


//----------------------------------------------------------------------------
// operator+
// overloaded +: addition of 2 IntSets
IntSet IntSet::operator+(const IntSet & add) const{
    IntSet addition (-1);
    // A+B = adds all numbers in both sets
    if (size  > add.getSize()){
        for(int index = 0; index <= add.getSize(); index++){
            
            if(add.set[index]== true){
                set[index] = true;
            }
        }
        addition.size = size;
        addition.set = set;
    }else{
        for(int index = 0; index <= size; index++){
            if(set[index]== true){
                add.set[index] = true;
            }
        }
        addition.size = add.getSize();
        addition.set = add.set;
    }
    return addition;
}



//----------------------------------------------------------------------------
// operator-
// overloaded -: addition of 2 IntSets
IntSet IntSet::operator-(const IntSet & sub) const{
    IntSet subtraction (-1);
    for(int index = 0; index <= sub.getSize(); index++){
        
        if(set[index] == true && sub.set[index]== true){
            set[index] = false;
        }
    }
    subtraction.size = size;
    subtraction.set = set;
    
    return subtraction;
}


//----------------------------------------------------------------------------
// operator*
// overloaded *: multiplication of 2 Rationals, current object and parameter
IntSet IntSet::operator*(const IntSet & m) const{
    int tempSize = 0;
    bool * temp;
    IntSet intersect (-1);
    
    // A*B = goes inside this if statement if A's size is bigger
    if (size  > m.getSize()){
        for(int index = m.getSize()-1; index >= 0; index--){
            if(set[index]==true && m.set[index]==true){
                tempSize = index + 1;
                break;
            }
        }
        temp = new bool [tempSize];
        for (int index = 0; index < tempSize; index++){
            temp[index] = false;
            if( set[index] == true && m.set[index] == true){
                temp[index] = true;
            }
            //cout << temp[index];
        }
    }else{  // A*B = goes inside this else statement if A's size is smaller
        
        for(int index = size-1; index >= 0; index--){
            if(set[index]==true && m.set[index]==true){
                tempSize = index + 1;
                break;
            }
        }
        temp = new bool [tempSize];
        for (int index = 0; index < tempSize; index++){
            temp[index] = false;
            if( set[index] == true && m.set[index] == true){
                temp[index] = true;
            }
            
            // for testing - please remove
            // cout << temp[index];
        }
        
    }
    
    intersect.size = tempSize;
    intersect.set = temp;
    
    return intersect;
}




// Insert() method
// insert(): inserts the value into the set
void IntSet::insert(int number){
    
    if (number >= 0){
        if (number > size){
            size = number;
            set[number] = true;
        }
        
    }
}


//----------------------------------------------------------------------------
// operator<<
// overloaded <<: prints the set

ostream& operator<<(ostream &output, const IntSet& s) {
    output << "{ ";
    for (int counter = 0; counter < s.size; counter++){
        output << s.set[counter] << " ";
    }
    output << "}";
    return output;
}




//----------------------------------------------------------------------------
// operator>>
// overloaded >>:  Not Yet Done
istream& operator>>(istream &input, IntSet &s){
    while(!input.eof()) {
        int temp = 0;
        input >> temp;
        if (temp < 0){
            break;
        }
        s.set[temp] = true;
    }
    return input;
}

