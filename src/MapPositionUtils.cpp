//
// Created by Liviu on 27/05/2024.
//

#include "../headers/MapPositionUtils.h"


std::string MapPositionUtils::to_string(MapPosition position) {
    switch (position) {
        case MapPosition::UP: return "UP";
        case MapPosition::RIGHT: return "RIGHT";
        case MapPosition::LEFT:  return "LEFT";
        case MapPosition::DOWN:  return "DOWN";
        default: return "Unknown";
    }
}
