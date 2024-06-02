//
// Created by Liviu on 28/05/2024.
//

#include "../headers/InitGame.h"

namespace gameUtils {
    InitGame::InitGame(unsigned int numberOfDirections) : numberOfDirections(numberOfDirections) {};

    void InitGame::execute() {
        for (unsigned int cnt = 1; cnt <= numberOfDirections; cnt++) {
            this->directions.push_back(std::make_shared<Direction>(int(MapPosition::foo)));
        }

        for (const auto &direction: directions) {
            this->usedDirectionPositions.insert(direction->getPosition());
        }

        for (auto const &direction: directions) {
            numberOfCars = rndm::RandomCarGenerator::generateNumberOfCars(2, 3);
            std::cout << numberOfCars << "\n";
            for(unsigned int index = 1; index <= numberOfCars; index++)
            {
                direction->addCar(rndm::RandomCarGenerator::generateCarPosition(direction->getPosition(), this->usedCarPositions),
                                  "fooColor");

            }
        }
    }

    unsigned int InitGame::getNumberOfCars() const {
        return numberOfCars;
    }

    const std::vector<std::shared_ptr<Direction>> &InitGame::getDirections() const {
        return directions;
    }
} // gameUtils