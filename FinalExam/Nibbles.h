#pragma once
#include "Casino.h"

namespace CSC234 {

    class Nibbles : public Casino {

    public:
        // Constructors
        Nibbles();

        // Init
        static Nibbles* makeGame();

    private:

        void init();


    };

};// end namespace
