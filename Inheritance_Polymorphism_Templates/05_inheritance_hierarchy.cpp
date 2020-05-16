/* Exercise: Class Hierarchy
 * Multi-level inheritance is term used for chained classes in an inheritance 
 * tree. Have a look at the example in the notebook below to get a feel for 
 * multi-level inheritance.
 */

#include <cassert>

// TODO: Declare Vehicle as the base class
class Vehicle {};

// TODO: Derive Car from Vehicle
class Car : public Vehicle {
public: 
    int wheels{4};
};

// TODO: Derive Sedan from Car
class Sedan : public Car {
public:
    bool trunk{true};
    int seats{4};
};

// TODO: Update main to pass the tests
int main() {
  Sedan sedan;
  assert(sedan.trunk == true);
  assert(sedan.seats == 4);
  assert(sedan.wheels == 4);
}
