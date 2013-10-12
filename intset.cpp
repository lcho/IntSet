/**
 @file intset.cpp
 
 */

#include "intset.h"
const int MAX_VALUE = 5;

IntSet::IntSet(int value1, int value2, int value3, int value4, int value5){
    
    int values[] = {value1, value2, value3, value4, value5};
    int max = 0;
    for (int counter = 0; counter < MAX_VALUE; counter++){
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
    for(int counter=0; counter < MAX_VALUE; counter++){
        if (values[counter] >= 0){
            set[ values[counter] ] = true;
        }
        
    }
    
    /*  for testing
     for(int counter=0; counter < size; counter++){
     cout << set[counter] << " ";
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
//              Boolean Comparison Operators
//----------------------------------------------------------------------------
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
// overloaded *: intersection of 2 IntSet objects, current object and parameter
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




//----------------------------------------------------------------------------
// Insert() method
// insert(): inserts the value into the set
bool IntSet::insert(int number){
    if (number >= 0){
        if (number > size){
            size = number+1;
            set[number] = true;
        }
        set[number] = true;
    }
    
    // returns 1 if true and 0 if false
    return set[number];
}



//----------------------------------------------------------------------------
// Remove() method
// remove(): removes the value from the set
bool IntSet::remove(int number){
    if (number >= 0){
        if (number > size){
            cout << "Number not in the set" << endl;
        }else{
            set[number] = false;
        }
    }else{
        set[number] = false;
    }
    
    return set[number];
}


//----------------------------------------------------------------------------
// isEmpty() method
// isEmpty(): returns a boolean value true if set is empty
bool IntSet::isEmpty() {
    for (int count = 0; count <= size; count++){
        if (set[count] == true){
            return false;
        }
    }
    return true;
}


//----------------------------------------------------------------------------
//              Overloaded Input & Output Operators
//----------------------------------------------------------------------------
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
 
 //  Should the user enter more values if there are already 5 values
 //  in the set? For now, the user is not limited to how many numbers
 //  he/she can input. User needs to type in a negative number to 
 //  get out of the input '>>' operator.
 
    for (int counter = 0; counter <= s.size; counter++) {
        int temp = 0;
        input >> temp;
        
        if (temp < 0){
            break;
        }
        
        if (temp > s.size){
            
            // For some reason some numbers were being flagged as true
            //  even if they are not in the set. This for-loop is the
            //  'trick' for now.
            for(int counter = s.size; counter <= temp; counter++){
                s.set[counter] = false;
            }
            //----end of for-loop trick
            
            s.size = temp+1;
            s.set[temp] = true;
        }else{
            s.set[temp] = true;
        }
    }
    
    // for testing - please remove afterwards
    cout << "After:" << endl;
    for(int counter=0; counter < s.size; counter++){
        cout << s.set[counter] << " ";
    }
    return input;
}

