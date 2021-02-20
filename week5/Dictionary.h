//
//  Dictionary.h
//  CSC234 ClassW5
//
//  Created by Elita Danilyuk on 2/22/21.
//

#pragma once
#include "Word.h"

class Dictionary{
public:
    Dictionary(); // no-parameter constructor
    Dictionary(string newWord);
    void add(string);
    void print();
    
private:
    bool addNext(string);
    Word* root; //references first element of linked list
};
