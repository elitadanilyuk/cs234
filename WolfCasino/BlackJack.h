//Created by Zach Keeler

#pragma once
#include "Casino.h"

namespace CSC234 {
	class BlackJack : public Casino {
	public:
		void start();
		~BlackJack();
		static BlackJack* makeGame();
	};
}
