//
//  main.cpp
//  CSC234 Class Week 1
//
//  Created by Elita Danilyuk on 1/22/21.
//

#include <iostream>

void Power (int& x, int& y, int& result){
    result = 1;
    while (y>0){
        result = result *x;
        y--;
    }
}

int main()
{
    int age;
    
    std::cout << "Enter your age: ";
    std::cin >> age;
    
    std::cout << age;
    
    //look at Cplusplus site and look at some methods
    
    cout << Power(&1, &5, &3);
    
}

/*6. six
 12. void function would not have return statement
 10. Encapsulation is compounding data into smaller pieces, allowing those segments to be protected/hidden
 11. In and out*/
