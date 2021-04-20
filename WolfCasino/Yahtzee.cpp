#include <iostream>
#include "Yahtzee.h"
using namespace std;

//class Yahtzee implementation file
namespace CSC234 {
	void Yahtzee::start() {
		cout << "Yahtzee funtion start() is not defined." << endl;
	}

	Yahtzee::~Yahtzee() {
		cout << "Yahtzee desctructor here" << endl;
	}

	Yahtzee* Yahtzee::makeGame() {
		cout << "Yahtzee makeGame() not defined" << endl;
		return new Yahtzee;
	}
}