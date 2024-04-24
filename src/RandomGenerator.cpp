#include "../headers/RandomGenerator.h"

void rndm::RandomGenerator::generateSeed() {
    std::srand(std::time(nullptr));
}

void rndm::RandomGenerator::init() {
    generateSeed();
}

int rndm::RandomGenerator::generatePosition() {
    return 1 + std::rand() % 4;
}




