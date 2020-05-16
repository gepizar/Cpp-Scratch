/* Instructions

    Define a class Animal.
    Define 3 member variables: color, name, age.
    Define a derived class Snake that inherits from the base class Animal.
    Create a member variable length for the Snake class.
    Create a derived class Cat that inherits from the base class Animal.
    Create a member variable height for the Cat class.
    Create MakeSound() member functions for each of the derived classes.
    In the main() function instantiate Snake and Cat objects. Initialize both their unique and derived attributes. Program them to make a sound.
 */

#include <iostream>
#include <string> 

class Animal {
public:
    std::string color;
    std::string name;
    int age; 
};

class Snake : public Animal {
public: 
    int length;
    void MakeSound() const {std::cout << "Tzzzzzz\n"; }
};

class Cat : public Animal {
public: 
    int height;
    void MakeSound() const {std::cout << "Miaaau\n"; }
};

int main() {
    Snake snake;
    Cat cat; 
    snake.length = 5; 
    cat.height = 1; 
    cat.age = 10; 
    cat.name = "Lucifer";

    cat.MakeSound();
    snake.MakeSound();

    std::cout << cat.age << " " << cat.name << "\n"; 
}