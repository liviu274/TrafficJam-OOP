#ifndef OOP_DIRECTION_H
#define OOP_DIRECTION_H

#include <iostream>
#include "Car.h"
#include <cstdlib>
#include <vector>
#include <deque>
#include <memory>

//#pragma once
class Direction {

private:
    int position;
    std::vector <std::shared_ptr<Car>> cars;
    std::deque  <std::shared_ptr<Car>> priority_cars;

    // Every direction has a car queue allocated
    // Direction is the local root
    // We'll arrange the cars in preferred order for a BFS in the order of traffic priority

public:
//    Constructors
    explicit Direction(int position);
//    Destructors
    virtual ~Direction();

//    Setters
//    void setCars(const std::vector<Car> &cars_);

//    Getters
    [[nodiscard]] const std::vector<std::shared_ptr<Car>> &getCars() const;

    [[nodiscard]] int getPosition() const;

//    Extra
//    Class functionalities
    void priorityOrder();
    void addCar(int position, const std::string &color);


//    Print
    friend std::ostream &operator<<(std::ostream &os, const Direction &direction);
};


#endif //OOP_DIRECTION_H
