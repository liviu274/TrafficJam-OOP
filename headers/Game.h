#ifndef OOP_GAME_H
#define OOP_GAME_H

#include "Direction.h"
#include "RandomGenerator.h"
#include "MapPosition.h"
#include <set>




class Game {
private:
    std::vector<Direction*> directions;
    int initilisedCars = 0;

    std::set< int > usedCarPositions;

//    Private functions
    bool isCarPositionAvalable(int position, int directionPosition);
    int generateCarPosition(int directionPosition);

public:
// Constructors


// Initializers

void initGame(int numberOfDirections);


// Ostream
//    friend std::ostream &operator<<(std::ostream &os, Game &game);
};


#endif //OOP_GAME_H
