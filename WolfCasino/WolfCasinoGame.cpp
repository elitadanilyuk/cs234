#include <iostream>
#include <windows.h>
#include "Casino.h"
using namespace std;

using namespace CSC234;
	int main(int argc, char* argv[]) {

		if (argc > 1) {
			cout << "Welcome to the Wolf Casino.  You have chosen to play: " << argv[1] << std::endl;
			cout << "Getting game ready." << endl;
			Sleep(3000);
			Casino::play(argv[1]); //static function call
		}
		else
			std::cout << "Usage: WolfCasinoGame game_to_play" << std::endl;


	}