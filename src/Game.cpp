//
// Created by Liviu on 10/04/2024.
//

#include "../headers/Game.h"

#include <iostream>

// PRIVATE




// PUBLIC

void Game::initGame(int numberOfDirections) {
    for (int cnt = 1; cnt <= numberOfDirections; cnt++) {
        this->directions.push_back(new Direction(int(MapPosition::foo)));
    }

    for (const auto &direction: directions) {
        this->usedDirectionPositions.insert(direction->getPosition());
    }

    for (auto const &direction: directions) {
        numberOfCars = rndm::RandomCarGenerator::generateNumberOfCars(1, 3);
        std::cout << numberOfCars << "\n";
        for(unsigned int index = 1; index <= numberOfCars; index++)
        {
            direction->addCar(rndm::RandomCarGenerator::generateCarPosition(direction->getPosition(), this->usedCarPositions),
                              "fooColor");

        }
    }
}

unsigned int Game::getNumberOfCars() const {
    return numberOfCars;
}

const std::vector<Direction *> &Game::getDirections() const {
    return directions;
}

std::ostream &operator<<(std::ostream &os, Game &game){
    os << "Number of cars: " << game.getNumberOfCars() << "\n";

    for (const auto& direction : game.getDirections())
    {
        os << "car: ";
        for (auto& car : direction->getCars())
        {
            os << car->getPosition();
        }
        os << std::endl;
    }
    return os;
}
