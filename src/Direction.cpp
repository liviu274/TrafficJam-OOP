#include <set>
#include <algorithm>
#include "../headers/Direction.h"


Direction::Direction(int position) : position(position) {
    std::cout << "This is the direction constructor\n";
}

Direction::~Direction() {
    std::cout << "This is the direction destructor";
}

//void Direction::setCars(const std::vector<Car> &cars_) {
//    /// @param cars_ a vector of Car objects
//
//    std::set<int> s;
//    for (auto const &car : cars_) {
//        auto pos = car.getPosition();
//        if (s.contains(pos) || pos == this->position)
//        {
//            std::cout << "Invalid input (duplicate in cars positions found)\n";
//            return;
//        }
//        else
//            s.insert(pos);
//    }
//    Direction::cars = cars_;
//    std::cout << "set cars succeeded\n";
//}

std::vector<Car*> &Direction::getCars() {
    return this->cars;
}

int Direction::getPosition() const {
    return position;
}

//   Class functionalities

void Direction::priorityOrder() {
    std::sort(this->cars.begin(), this->cars.end(), [](const Car* car1, const Car* car2) {
        return car1->getPosition() < car2->getPosition();});
    for(auto const &car : this->cars)
        priority_cars.push_back(car);
}

void Direction::addCar(int carPosition, const std::string &color) {
    this->cars.push_back(new Car(carPosition, color));
}

std::ostream &operator<<(std::ostream &os, const Direction &direction) {
    os << "position: " << direction.position;
    return os;
}
