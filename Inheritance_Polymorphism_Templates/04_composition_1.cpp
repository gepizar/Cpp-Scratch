#include <cassert>
#include <vector>

class Wheel {
public:
    Wheel() : diameter(50) {}
    float diameter;
};

class Car {
public:
    Car() : wheels(4, Wheel()) {}
    std::vector<Wheel> wheels;
};

int main() {
    Car car; 
    assert(car.wheels.size() == 4); 
}

