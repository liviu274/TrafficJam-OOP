
// Only use case scenarios for generating random Car std::vector

#ifndef OOP_RANDOMCARGENERATOR_H
#define OOP_RANDOMCARGENERATOR_H

#include "RandomGenerator.h"
#include "Car.h"
#include <vector>
#include <set>

namespace rndm {

    class RandomCarGenerator : public RandomGenerator {
    private:

    public:
//        Constructors
        RandomCarGenerator() = default;

//        Destructors
        ~RandomCarGenerator() override = default;

//        Generatr functios
        static unsigned int generateNumberOfCars(unsigned int minValue, unsigned int maxValue);

        [[maybe_unused]] static std::vector<Car *> &generateCarVector(unsigned int numberOfCars);

        static bool isCarPositionAvailable(int position, int directionPosition, std::set<int> &usedCarPositions);

        static int generateCarPosition(int directionPosition, std::set<int> &usedCarPositions);
    };


} // rndm

#endif //OOP_RANDOMCARGENERATOR_H
