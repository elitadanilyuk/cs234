//
//  SortedList.cpp
//  ClassLab6.0
//
//  Created by Elita Danilyuk on 4/21/21.
//
#include <iostream>
#include "SortedList.h"

SortedList::SortedList(): List::List() {};

void SortedList::Insert(ItemType item){
    List::Insert(item);
    SelSort();
}

void SortedList::Delete(List::ItemType item, int &listLength){
    List::Delete(item);
    SelSort();
//    SortedList::resizeListLength(listLength);
}

void SortedList::resizeListLength(int &listLength){
    listLength--;
}
