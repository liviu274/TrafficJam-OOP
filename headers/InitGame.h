//
// Created by Liviu on 28/05/2024.
//

#ifndef OOP_INITGAME_H
#define OOP_INITGAME_H

#include "Direction.h"
#include "RandomGenerator.h"
#include "RandomCarGenerator.h"
#include "MapPosition.h"
#include "MapPositionUtils.h"

#include <set>
#include <memory>

namespace gameUtils {

    class InitGame {
    private:
        unsigned int numberOfDirections;

        unsigned int numberOfCars;
        std::set<int> usedCarPositions;
        std::set<int> usedDirectionPositions;

        std::vector<std::shared_ptr<Direction>> directions; // for now we'll only use one direction
    public:
        explicit InitGame(unsigned int numberOfDirections);
        virtual ~InitGame() = default;

//        Getters
        unsigned int getNumberOfCars() const;
        const std::vector<std::shared_ptr<Direction>> &getDirections() const;

        void execute();
    };

} // gameUtils

#endif //OOP_INITGAME_H
