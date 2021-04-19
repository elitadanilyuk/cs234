#pragma once
#include "Casino.h"

// Header file for class Yahtzee
namespace CSC234 {
	class Yahtzee : public Casino {
	public:
		void start();
		~Yahtzee();
		static Yahtzee* makeGame();
	};
}