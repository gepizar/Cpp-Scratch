/* 
 * Allow to define abstract classes
 * http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-glossary
 * Look for Abstract class.
 * 
 * This approach declares an interface at the base level, but delegates the 
 * implementation of the interface to the derived classes.
 * 
 * The virtual function cannot be instantiated. Instead, only classes that 
 * derive from the abstract class and override the pure virtual function can be 
 * instantiated.
 * 
 * When a new class inherites the virtual function, it is obligated to override
 * the functions in order to compile.
 */

#include <iostream>
#include <cassert>
#include <cmath>

#define PI 3.14159

class Shape {
public: 
    Shape() {}
    virtual double Area() const = 0;
    virtual double Perimeter() const = 0; 
};

class Rectangle : public Shape {
public:
    Rectangle(double length, double width) : length_(length), width_(width) {
        Validate(); 
    };

    /* Rectangle rectangle(a, b) can only be instantiated if Area() and 
     * Perimeter() are overrided.
     * 
     * The key word override it not mandatory but allow the compiler and future
     * user to remember that this specific function is overrided.
     */

    
    double Area() const override {
        return length_ * width_;
    }

    double Perimeter() const override {
        return 2 * (length_ + width_);
    }


private: 
    double length_;
    double width_;
    void Validate() {
        if (length_ <= 0 || width_ <= 0)
            throw std::invalid_argument("Must be positive.");
    }
};

class Circle : public Shape {
public: 
    Circle(double radius) : radius_(radius) {
        Validate(); 
    }
    double Area() const {
        return pow(radius_, 2) * PI;
    }

    double Perimeter() const {
        return 2 * PI * radius_;
    }
    
private: 
    double radius_;
    void Validate() {
        if (radius_ <= 0)
            throw std::invalid_argument("Must be positive.");
    }
    
};


int main() {
    // Abstract functions can't be instantiated.
    // Shape shape; 
    
    Rectangle rectangle(8, 2);
    assert(rectangle.Area() == 16);
    assert(rectangle.Perimeter() == 20);

    double epsilon = 0.1; // useful for floating point equality

    // Test circle
    Circle circle(12.31);
    assert(abs(circle.Perimeter() - 77.35) < epsilon);
    assert(abs(circle.Area() - 476.06) < epsilon);
}