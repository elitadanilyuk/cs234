//
//  Dictionary.cpp
//  CSC234 ClassW5
//
//  Created by Elita Danilyuk on 2/22/21.
//

#include <string>
#include "Dictionary.h"

Dictionary::Dictionary(){};

// Dictionary() general description
// Pre:
// Post:
Dictionary::Dictionary(string newWord){
    root = new Word;
    root ->s = "aardvark";
    root ->next = NULL;
};

// Dictionary() general description
// Pre:
// Post:
void Dictionary::add(string newWord){
    if (root == NULL) {
        root = new Word;
        root ->s = "aardvark";
        root ->next = NULL;
    }
    else{
        addNext(newWord);
    }
}

// Dictionary() general description
// Pre:
// Post:
void print(){
    
}

// Dictionary() general description
// Pre:
// Post:
bool Dictionary::addNext(<#string#> newWord){
    //logic find end of list
    //append new element
    Word* foo = root;
    
    while (foo->next != NULL) {
        foo = foo->next;
    }
    
    foo->next = new Word; //append new Word to list
    
    foo = foo->next;
    foo->s = newWord;
    foo->next = NULL;
    return true;
}
