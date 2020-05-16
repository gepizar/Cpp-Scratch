// This example demonstrates the privacy levels
// between parent and child classes
#include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
    int wheels = 0;
    string color = "blue";
    
    void Print() const
    {
        std::cout << "This " << color << " vehicle has " << wheels << " wheels!\n";
    }
};

class Car : public Vehicle {
public:
    bool sunroof = false;
};

class Bicycle : protected Vehicle {
public:
    bool kickstand = true;
    void Wheels(int w) {
        wheels = w;
    }
};

class Scooter : private Vehicle {
public:
    bool electric = false;
    void Wheels(int w) {
        wheels = w;
    }
};

int main() 
{
    Car car;
    Bicycle bicycle;
    Scooter scooter;

    car.wheels = 4;
    // bicycle.wheels = 2; // innacsible because heicle is protected
    // scooter.wheels = 2; // innacsible because heicle is private
    bicycle.Wheels(2);
    scooter.Wheels(2);
    
};

/* Instructions
 * 1. Update the derived classes so that one has protected inheritance and one has private inheritance.
 * 2. Try to access a protected member from main(). Is it possible? 
 * 3. Try to access a private member from main(). Is it possible?
 * 4. Try to access a member of the base class from within the derived class that has protected inheritance. Is it 
 * possible?
 * 5. Try to access a member of the base class from within the derived class that has private inheritance. Is it 
 * possible?
 * 
 * 2. and 3.: is not possible to access directly to the member 
 * 4. and 5.: but defining a mutator inside the class it is.
 * 
 * The difference between protected and private is that protected can access to all the inheritance up but private just
 * to the last inheritance. 
 * 
 * In practice is more common public and private
 */