/* Author: Ellie Lash
*  Course: CSC234/601 C++
*  Assignment: Final Project / Game for Wolf Casino
*/
#pragma once
#include "Casino.h"

namespace CSC234
{
	class ColoradoTrail: public Casino {
	public:
		ColoradoTrail();
		static ColoradoTrail* makeGame();
		void start();
	private:
		void run();
	};
}