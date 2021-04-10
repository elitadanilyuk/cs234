#include <iostream>
#include "List.h"
#include "SortedList.h"

using namespace std;

int main(int argc, char* argv[]) {
	List tempList;
    int numItems = 10;
    
    if (numItems < MAX_LENGTH) {
        numItems = numItems;
    } else {
        numItems = MAX_LENGTH;
    }

	for(int i = 0; i < numItems; i++)
		tempList.Insert(rand() % 100);

	tempList.Reset();
	cout << tempList;

	cout <<endl;

	tempList.SelSort();

	tempList.Reset();
	for (int i = 0; i < numItems; i++)
		cout << tempList.GetNextItem() << " ";
	cout << endl << "\n\n";
    
    
    SortedList newTempList;
    for(int i = 0; i < numItems; i++)
        newTempList.Insert(rand() % 100);
    newTempList.Reset();
    cout << newTempList;

    cout <<endl;

    newTempList.Delete(12);
    numItems--;
    for (int i = 0; i < numItems; i++)
        cout << newTempList.GetNextItem() << " ";
    cout << endl;
}
