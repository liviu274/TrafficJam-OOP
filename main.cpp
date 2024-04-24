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

    Car car1{1, "blue"};
    std::cout << "the car color is " << car1.getColor() << std::endl;
    std::cout << car1 << std::endl;
    Direction direction1(3);
    direction1.setCars({car1});
    Car car2{};
    car2 = car1;
    std::cout << car2 << std::endl;

    direction1.setCars({car1, car2});
    std::cout << direction1 << std::endl;  // should return input error

    direction1.setCars({Car(2, "green"), car1});
    direction1.priorityOrder();
    std::cout << direction1 << std::endl;
    Game game{direction1};
    std::cout << game;
    return 0;
}
