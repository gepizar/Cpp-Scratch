#include <iostream>
#include <string>

class Animal {
public:
    void Talk() const {std::cout << "Talk\n"; }
};

class Human : public Animal {
public:
    void Talk(std::string content) const {std::cout << content << "\n"; }
};

class Baby : private Human {
public:
    void Cry() const {Talk("Waaaa!"); }
};

int main() {
    Human human; 
    human.Talk("Hello World!");
    Baby baby; 
    baby.Cry();
    // baby.Talk("I want pizza! ");
    /* Baby class don't have access to method Talk() publicly because it's 
     * defined in Human and Human is inheritated as private.
     */

}