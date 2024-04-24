
// Only use case scenarios for generating random Car std::vector

#ifndef OOP_RANDOMCARGENERATOR_H
#define OOP_RANDOMCARGENERATOR_H

#include "RandomGenerator.h"
#include "Car.h"
#include <vector>

namespace rndm {

    class RandomCarGenerator : private RandomGenerator {
    private:

    public:
//        Constructors
        RandomCarGenerator() = default;
//        Destructors
        ~RandomCarGenerator() override = default;

//        Generatr functios
       static unsigned int generateNumberOfCars(unsigned int minValue, unsigned int maxValue);
       static std::vector<Car*> &generateCarVector(unsigned int numberOfCars);
    };




} // rndm

#endif //OOP_RANDOMCARGENERATOR_H
