#include "SpaceDogs.h"
namespace CSC234 {

	SpaceTrader::SpaceTrader() {

	}

	SpaceTrader::~SpaceTrader() {

	}

	SpaceTrader* SpaceTrader::makeGame() {
		return new SpaceTrader;
	}
}