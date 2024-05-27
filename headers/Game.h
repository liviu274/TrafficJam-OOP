#ifndef OOP_GAME_H
#define OOP_GAME_H

#include "Direction.h"
#include "RandomGenerator.h"
#include "RandomCarGenerator.h"
#include "MapPosition.h"
#include <set>


class Game {
private:
    std::vector<Direction *> directions;
    [[maybe_unused]] int numberOfInitialisedCars = 0;
    [[maybe_unused]] unsigned int numberOfCars;

    std::set<int> usedCarPositions;
    std::set<int> usedDirectionPositions;

//    Private functions


public:
// Constructors


// Initializers

    void initGame(int numberOfDirections);

// Getters
    [[nodiscard]] unsigned int getNumberOfCars() const;

    [[nodiscard]] const std::vector<Direction *> &getDirections() const;


// Ostream
    friend std::ostream &operator<<(std::ostream &os, Game &game);
};


#endif //OOP_GAME_H
