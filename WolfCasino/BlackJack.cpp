//Created by Zach Keeler

#include <iostream>
#include "BlackJack.h"
using namespace std;

namespace CSC234 {
	void BlackJack::start() {
		cout << "BlackJack start()" << endl;
	}

	BlackJack::~BlackJack() {
		cout << "BlackJack desctructor" << endl;
	}

	BlackJack* BlackJack::makeGame() {
		cout << "BlackJack makeGame() called" << endl;
		return new BlackJack;
	}
}
