#ifndef OOP_GAME_H
#define OOP_GAME_H


#include "InitGame.h"
#include "RandomGenerator.h"
#include "RandomCarGenerator.h"
#include "MapPosition.h"
#include "MapPositionUtils.h"

#include <memory>

class Game {
private:
    gameUtils::InitGame *initGame;

    unsigned int numberOfCars;
    std::vector<std::shared_ptr<Direction>> directions;

    //    Setters
    void setNumberOfCars();
    void setDirections();

//    Private functions


public:
// Constructors
    explicit Game(gameUtils::InitGame *initGame_);

    virtual ~Game();



// Getters
    [[nodiscard]] unsigned int getNumberOfCars() const;
    [[nodiscard]] const std::vector<std::shared_ptr<Direction>> &getDirections() const;

//    Initialise
void init();

// Ostream
    friend std::ostream &operator<<(std::ostream &os, Game &game);
};


#endif //OOP_GAME_H
