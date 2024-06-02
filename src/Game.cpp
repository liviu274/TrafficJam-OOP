//
// Created by Liviu on 10/04/2024.
//

#include "../headers/Game.h"

#include <iostream>

// Game class is considered a FACADE
// Subsystem will communicate to each other using a MEDIATOR

using namespace gameUtils;

// PRIVATE


// PUBLIC

Game::Game(InitGame *initGame_) {
    try{
        this->initGame = initGame_ ? throw std::invalid_argument("test") : new InitGame(1);
        init();
    }
    catch(std::invalid_argument &log){
        std::cout << "ERROR: " << log.what() << "\n";
    }
};

Game::~Game() {
    delete initGame;
}

// Setters

void Game::setDirections() {
    this->directions = this->initGame->getDirections();
}

const std::vector<std::shared_ptr<Direction>> &Game::getDirections() const {
    return directions;
}

// Getters

unsigned int Game::getNumberOfCars() const {
    return numberOfCars;
}

void Game::setNumberOfCars() {
    this->numberOfCars = this->initGame->getNumberOfCars();
}


// Initialise

void Game::init() {
    this->initGame->execute();
    setDirections();
    setNumberOfCars();
}

std::ostream &operator<<(std::ostream &os, Game &game){
    os << "Number of cars: " << game.getNumberOfCars() << "\n";

    for (const auto& direction : game.getDirections())
    {
        os << "car: ";
        for (auto& car : direction->getCars())
        {
            os << MapPositionUtils::to_string(MapPosition(car->getPosition()));
            os << " ";
        }
        os << std::endl;
    }
    return os;
}











