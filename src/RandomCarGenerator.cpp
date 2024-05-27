#include "../headers/RandomCarGenerator.h"

namespace rndm {
    unsigned int RandomCarGenerator::generateNumberOfCars(unsigned int minValue, unsigned int maxValue) {
        unsigned int valueRange = std::rand() % (maxValue - minValue + 1);
        return minValue + valueRange;
    }
//
//    [[maybe_unused]] std::vector<Car *> &RandomCarGenerator::generateCarVector(unsigned int numberOfCars) {
//        std::vector<Car *> cars;
//        for (unsigned int i = 1; i <=
//                                 numberOfCars; i++) {
//            cars.push_back(new Car(generatePosition(), "color"));
//        }
//        return cars;
//    }

     void RandomGenerator::setAvailablePositions(std::vector<int> &positions) {
        this->availablePositions = positions;
    }

    bool RandomCarGenerator::isCarPositionAvailable(int position, int directionPosition, std::set<int> &usedCarPositions) {
        return position != directionPosition && !usedCarPositions.contains(position);
    }

    int RandomCarGenerator::generateCarPosition(int directionPosition, std::set<int> &usedCarPositions) {
        int pos = rndm::RandomGenerator::generatePosition();
        while (!isCarPositionAvailable(pos, directionPosition, usedCarPositions)) {
            pos = rndm::RandomGenerator::generatePosition();
        }

        usedCarPositions.insert(pos);
        return pos;
    }

} // rndm