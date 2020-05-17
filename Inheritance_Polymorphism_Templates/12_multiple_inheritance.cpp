#include <cassert>
#include <iostream>

class Car {
public: 
    std::string Drive() { return "I'm driving!"; }
};

class Boat {
public: 
    std::string Cruise() { return "I'm cruising!"; }
}; 

class AmphibiousCar : public Car, public Boat {};

int main() {
    Car car; 
    Boat boat; 
    AmphibiousCar duck;

    assert(duck.Drive() == car.Drive());
    assert(duck.Cruise() == boat.Cruise()); 
}

/* 
 * If you have class Animal and another class Pet, then you can construct a 
 * class Dog, which inherits from both of these base classes. In doing this, you 
 * are able to incorporate attributes of multiple base classes.
 * 
 * C.135: Use multiple inheritance to represent multiple distinct interfaces
 * http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c135-use-multiple-inheritance-to-represent-multiple-distinct-interfaces
 * 
 * C.136: Use multiple inheritance to represent the union of implementation 
 * attributes
 * http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c136-use-multiple-inheritance-to-represent-the-union-of-implementation-attributes
 */