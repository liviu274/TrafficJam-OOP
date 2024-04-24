//
// Created by Liviu on 10/04/2024.
//

#include "../headers/Game.h"

#include <iostream>

// PRIVATE


bool Game::isCarPositionAvalable(int position, int directionPosition) {
    return position != directionPosition && this->usedCarPositions.contains(position);
}

int Game::generateCarPosition(int directionPosition) {
    int pos = rndm::RandomGenerator::generatePosition();
    while (!isCarPositionAvalable(pos, directionPosition))
        pos = rndm::RandomGenerator::generatePosition();

    this->usedCarPositions.insert(pos);
}

// PUBLIC

void Game::initGame(int numberOfDirections) {
    for (int cnt = 1; cnt <= numberOfDirections; cnt++){
        this->directions.push_back(new Direction(int(MapPosition::foo)));
    }

    for (auto const &direction : directions){
        direction->addCar(generateCarPosition(direction->getPosition()),
                          "testColor");
    }
}



//std::ostream &operator<<(std::ostream &os, Game &game){
//    os << "car: ";
//    for (const auto& el : game.direction.getCars())
//        os << el.getPosition() << " " << el.getColor() << "\n";
//    os << "direction position: " << game.direction.getPosition();
//    return os;
//}
