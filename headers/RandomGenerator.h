#ifndef OOP_RANDOMGENERATOR_H
#define OOP_RANDOMGENERATOR_H

#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

namespace rndm {


    class RandomGenerator {
    private:
        static void generateSeed();

    protected:

        std::vector <int> avalablePositions;

    public:
//    Constructors
        RandomGenerator() = default;
//    Destructors
        virtual ~RandomGenerator() = default;

//    Public functions
        static void init();
        static int generatePosition();

//     Pure virtual setters
        virtual void setAvalablePositions(std::vector <int> &positions);
    };

}
#endif //OOP_RANDOMGENERATOR_H
