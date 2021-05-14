#include <iostream>
#include "ColoradoTrail.h"
using namespace std;

namespace CSC234 {
	ColoradoTrail::ColoradoTrail() {

	}

	ColoradoTrail* ColoradoTrail::makeGame() {
		return new ColoradoTrail;
	}

	void ColoradoTrail::start() {
		run();
	}

	void ColoradoTrail::run() {
		cout << "Welcome to the Colorado Trail" << endl;
	}
}
