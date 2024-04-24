//
// Created by Liviu on 03/04/2024.
//

#ifndef OOP_CAR_H
#define OOP_CAR_H

#include <iostream>

//#pragma once
class Car{

private:
    int position;
    std::string color;


public:
//    Constructors
    Car() = default;
    Car(int position, std::string color);
    Car(const Car& other);
    Car& operator=(const Car& other);

//    Destructors

    virtual ~Car();

//    Getters
    [[nodiscard]] int getPosition() const;
    [[nodiscard]] const std::string &getColor() const;

//    Friend function
    friend std::ostream &operator<<(std::ostream &os, const Car &car);
};


#endif //OOP_CAR_H
