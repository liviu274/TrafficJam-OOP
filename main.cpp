#include "headers/Car.h"
#include "headers/Direction.h"
#include "headers/Game.h"
#include "headers/RandomGenerator.h"
#include <iostream>

#define CARS_MAX = 4
#define DIRECTIONS_MAX = 4

//   POSITION MAPPING:
//   UP -> 1   |   RIGHT -> 2   |   DOWN -> 3   |   LEFT -> 4



int main() {
    rndm::RandomGenerator::init();

    Game game{};
    game.initGame(1);
    std::cout << game;
    return 0;
}
