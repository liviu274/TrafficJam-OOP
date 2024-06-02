#include "headers/Car.h"
#include "headers/Direction.h"
#include "headers/Game.h"
#include "headers/RandomGenerator.h"
#include "headers/InitGame.h"

#include <iostream>
#include <memory>
#define CARS_MAX = 4
#define DIRECTIONS_MAX = 4

//   POSITION MAPPING:
//   UP -> 1   |   RIGHT -> 2   |   DOWN -> 3   |   LEFT -> 4



int main() {
    rndm::RandomGenerator::init();
    Game game(nullptr);
    std::cout << game;
    return 0;
}
