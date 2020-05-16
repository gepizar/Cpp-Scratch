#include <cassert>

// Declare class Rectangle
class Rectangle; 

// Define class Square as friend of Rectangle
class Square {

// Add public constructor to Square, initialize side
public:
    Square(int side) : side_(side) {}

private: 
    // Add private attribute side to Square
    int side_;
    // Add friend class Rectangle
    friend class Rectangle;

};

// Define class Rectangle
class Rectangle {
// Add public functions to Rectangle: area() and convert()
public:
    Rectangle(const Square& square);
    int Area() const; 

private: 
    int width_{0};
    int height_{0};
};

// Define a Rectangle constructor that takes a Square
Rectangle::Rectangle(const Square& square) : width_(square.side_), height_(square.side_) {}

// Define Area() to compute area of Rectangle
int Rectangle::Area() const {
    return width_ * height_;
}


// Update main() to pass the tests
int main()
{
    Square square(4);
    Rectangle rectangle(square);
    assert(rectangle.Area() == 16); 
}