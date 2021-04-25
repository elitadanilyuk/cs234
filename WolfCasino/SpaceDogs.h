#pragma once
#include "Casino.h"

/* Author: Irene Zaugg
Class: CSC234
Instructor: Robert Gilanyi

Runs SpaceDogs game, where the goal is to survive in deep space, eat treats,
and make friends and rivals at the Space Dog Park. Earn a "good boy/girl" rating
through trade and dog park actions. */

namespace CSC234 {

	class SpaceTrader: public Casino
	{
	public:
		SpaceTrader();
		~SpaceTrader();
		static SpaceTrader* makeGame();
	};
}

