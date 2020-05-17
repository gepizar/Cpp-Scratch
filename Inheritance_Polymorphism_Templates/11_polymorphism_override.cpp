/*
 * "Overriding" a function occurs when:
 * 
 * 1.   A base class declares a virtual function.
 * 2.   A derived class overrides that virtual function by defining its own 
 *      implementation with an identical function signature (i.e. the same 
 *      function name and argument types).
 * 
 * http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#glossary
 * override: defining a function in a derived class with the same name and 
 * argument types as a virtual function in the base class, thus making the 
 * function callable through the interface defined by the base class.
 */

#include <string>
#include <cassert>

class Animal {
public:
    virtual std::string Talk() const = 0;
};

class Cat : public Animal {
public:
    std::string Talk() const;    
};

std::string Cat::Talk() const {return "Meow"; }

class Lion : public Cat {
public: 
    std::string Talk() const; 
};

std::string Lion::Talk() const { return "Roar"; }


int main() {
    Cat cat; 
    assert(cat.Talk() == "Meow"); 

    Lion lion;
    assert(lion.Talk() == "Roar"); 
}

/*
 * Function Hiding
 * 
 * Function hiding is closely related, but distinct from, overriding.
 * 
 * A derived class hides a base class function, as opposed to overriding it, if 
 * the base class function is not specified to be virtual.
 * 
 * 
 * 
 * In this example, Cat is the base class and Lion is the derived class. Both 
 * Cat and Lion have Talk() member functions.
 * When an object of type Lion calls Talk(), the object will run Lion::Talk(), 
 * not Cat::Talk().
 * In this situation, Lion::Talk() is hiding Cat::Talk(). If Cat::Talk() were 
 * virtual, then Lion::Talk() would override Cat::Talk(), instead of hiding it. 
 * Overriding requires a virtual function in the base class.
 * 
 * The distinction between overriding and hiding is subtle and not terribly 
 * significant, but in certain situations hiding can lead to bizarre errors, 
 * particularly when the two functions have slightly different function
 *  signatures.
 * 
 * Strange Inheritance: 
 * https://isocpp.org/wiki/faq/strange-inheritance
 */