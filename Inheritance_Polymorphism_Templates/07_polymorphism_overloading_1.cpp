/* 
 * The overloading is happening in the Drink function (Function overloading). 
 * The parameter type is allowing us to switch to different versions of the 
 * function depending on the argument. Very simple example and the inputs can 
 * also be used.
 * 
 * In C++, you can write two (or more) versions of a function with the same 
 * name. This is called "overloading". Overloading requires that we leave the 
 * function name the same, but we modify the function signature. For example, we 
 * might define the same function name with multiple different configurations of 
 * input arguments.
 */

#include <cassert>
#include <string>

class Water {};
class Alcohol {};
class Coffee {};
class Soda {};

class Human {
public: 
    std::string condition{"happy"};
    void Drink(Water water) {condition = "hydrated"; }
    void Drink(Alcohol alcohol) {condition = "impaired"; }
    void Drink(Coffee coffe) {condition = "alert"; }
    void Drink(Soda soda) {condition = "cavities"; }
};

int main() {
    Human human;
    assert(human.condition == "happy");
    human.Drink(Water());
    assert(human.condition == "hydrated");
    human.Drink(Alcohol());
    assert(human.condition == "impaired");
    human.Drink(Coffee());
    assert(human.condition == "alert");
    human.Drink(Soda());
    assert(human.condition == "cavities");
}