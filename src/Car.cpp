#include <iostream>
#include <utility>
#include "../headers/Car.h"


Car::Car(int position, std::string color) : position(position), color(std::move(color)) {
    std::cout << "this is the car constructor\n";
}

Car::Car(const Car& other) : position{other.position}, color{other.color} {
    std::cout << "Copy Constrtuctor for car\n";
}

Car &Car::operator=(const Car &other) {
    this->position = other.position;
    this->color = other.color;

    std::cout << "This is the operator= constructor\n";
    return *this;
}

Car::~Car() {
    std::cout << "Car destructor\n";
}

int Car::getPosition() const {
    return this->position;
}

const std::string &Car::getColor() const {
    return color;
}

std::ostream& operator<<(std::ostream &os, const Car &car){
    os << "position: " << car.position << " color: " << car.color;
    return os;
}


