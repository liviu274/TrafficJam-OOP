#include <iostream>
#include <deque>
#include <array>
#include <vector>
#include <set>
#include <algorithm>


//   POSITION MAPPING:
//   UP -> 1   |   RIGHT -> 2   |   DOWN -> 3   |   LEFT -> 4

class Car
{
private:
    int position;
    std::string color;
public:
    Car(int position = 1, const std::string &color = "red") : position(position), color(color) {
        std::cout << "this is the car constructor\n";
    }

    Car(const Car& other) : position{other.position}, color{other.color} {
        std::cout << "Copy Constrtuctor for car\n";
    }

    Car operator=(const Car& other) {
        position = other.position;
        color = other.color;

        std::cout << "operator= constructor";
        return *this;
    }

    auto getPosition() const {
        return position;
    }

    const std::string &getColor() const {
        return color;
    }

    friend std::ostream &operator<<(std::ostream &os, const Car &car) {
        os << "position: " << car.position << " color: " << car.color;
        return os;
    }

    virtual ~Car() {
        std::cout<<"this is the distructor\n";
    }
};

class Direction
{
private:

    // Every direction has a car queue allocated
    // Direction is the local root
    // We'll arrange the cars in preferred order for a BFS in the order of traffic priority

    int position;
    std::vector <Car> cars;
    std::deque <Car> priority_cars;

public:
    explicit Direction(int position) : position(position) {
        std:: cout << "this is the init constructor for the direction\n";
    }

    auto setCars(const std::vector<Car> &cars_) {    // checks the input for duplicates before validation
        std::set<int> s;
        for (auto const &car : cars_) {
            auto pos = car.getPosition();
            if (s.contains(pos) || pos == this->position)
            {
                std::cout << "Invalid input (duplicate in cars positions found)\n";
                return;
            }
            else
                s.insert(pos);
        }
        Direction::cars = cars_;
        std::cout << "set cars succeeded\n";
    }

    void priorityOrder(){
        std::sort(this->cars.begin(), this->cars.end(), [](Car const &car1, Car const &car2) {
            return car1.getPosition() < car2.getPosition();});
        for(auto const &car : this->cars)
            priority_cars.push_back(car);
    }


    auto getCars() const {
        return cars;
    }

    int getPosition() const {
        return position;
    }

    friend std::ostream &operator<<(std::ostream &os, const Direction &direction) {
        os << "position: " << direction.position;
        return os;
    }
};

class Game
{
    //all the game logic;
private:

    Direction direction;


public:

    explicit Game(const Direction &direction) : direction(direction) {
        std::cout << "game constructor";
    }

//    const Direction &getDirection() const {
//        return direction;
//    }

    friend std::ostream &operator<<(std::ostream &os, const Game &game) {
        os << "car: ";
        for (auto el : game.direction.getCars())
            os << el.getPosition() << " " << el.getColor() << "\n";
        os << "direction position: " << game.direction.getPosition();
        return os;
    }
};


int main() {
    Car car1{1, "blue"};
    std::cout << "the car color is " << car1.getColor() << std::endl;
    std::cout << car1 << std::endl;
    Direction direction1(3);
    direction1.setCars({car1});
    Car car2{};
    car2 = car1;
    std::cout << car2 << std::endl;

    direction1.setCars({car1, car2});
    std::cout << direction1 << std::endl;  // should return input error

    direction1.setCars({Car(2, "green"), car1});
    direction1.priorityOrder();
    std::cout << direction1 << std::endl;
    Game game{direction1};
    std::cout << game;
    return 0;
}
