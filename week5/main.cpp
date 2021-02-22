//#include <iostream>
//#include <cstddef>
//
//using namespace std;
//
//typedef int* IntPtr;
//typedef char* CharPtr;
//
////Basic Pointer Manipulations
////Program to demonstrate pointers and dynamic variables.
//int main()
//{
//    int numRows, numCols;
//    CharPtr* m;
//
//    cout << "please enter number of row and columns: ";
//    cin >> numRows >> numCols;
//    m = new CharPtr[numRows];
//
//    for (int i = 0; i < numRows; i++) {
//        m[i] = new char[numCols];
//        for (int j = 0; j < numCols; j++)
//            m[i][j] = '.';
//    }
//
//    for (int i = 1; i < numCols+1; i++) {
//        printf(" :  %d ", i);
//    }
//    printf(" :\n");
//
//    for (int i = 0; i < numRows; i++) {
//        printf("%d: ", i+1);
//        for (int j = 0; j < numCols; j++){
//            printf(" %c ", m[i][j]);
//            printf(" : ");
//        }
//        cout << endl;
////        printf("---------------\n");
//    }
//
//    for (int i = 0; i < numRows; i++)
//        delete[] m[i];        // there must be one call to delete for each row that created an array.
//    delete[] m;               // then we delete the delete the array itself (can be optional)
//
//    return 0;
//}
//
////CARD GAME PART 1 DUE SUNDAY, BONUS FOR 2D ARRAY


//
//  Word.cpp
//  CSC234 ClassW5
//
//  Created by Elita Danilyuk on 2/19/21.
//
#include <iostream>
#include <string>
using namespace std;

struct Word{
    string s;
    Word* next;
};

void printDictionary(Word*);

int main(){
    Word* myDictionary = NULL;
    Word* myWordPtr1;
    Word* myWordPtr2;
    
    myWordPtr1 = new Word;
    myWordPtr1 ->s = "gobbledygook"; // Dictionary.add("gobbledygook");
    myDictionary = myWordPtr1;
    myWordPtr1 ->next = NULL;
    
    myWordPtr2 = new Word;
    myWordPtr2 ->s = "aardvark";
    myWordPtr2 ->next = NULL;
    myWordPtr1 ->next = myWordPtr2;
    
    printDictionary(myDictionary); // myDitionary.print();
}
