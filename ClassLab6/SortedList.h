//
//  SortedList.hpp
//  ClassLab6.0
//
//  Created by Elita Danilyuk on 4/21/21.
//

#pragma once
#include "List.h"
#include <iostream>
using namespace std;

class SortedList : public List {
public:
    SortedList();
    void Delete(ItemType item, int &listLength);
    void Insert(ItemType item);
    void resizeListLength(int &listLength);
};
