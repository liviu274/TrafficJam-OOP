#include "../headers/RandomCarGenerator.h"

namespace rndm {
    unsigned int RandomCarGenerator::generateNumberOfCars(unsigned int minValue, unsigned int maxValue) {
        unsigned int valueRange = 1 + std::rand() % (maxValue - minValue + 1);
        return minValue + valueRange;
    }

    std::vector<Car*> &RandomCarGenerator::generateCarVector(unsigned int numberOfCars) {
        std::vector<Car*> cars;
        for (unsigned int i = 1; i <= numberOfCars; i++)
        {
            cars.push_back(new Car(generatePosition(), "color"));
        }
    }

    void rndm::RandomGenerator::setAvalablePositions(std::vector<int> &positions) {
        this->avalablePositions = positions;
    }

} // rndm