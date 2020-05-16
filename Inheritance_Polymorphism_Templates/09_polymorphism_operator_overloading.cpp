/* 
 * In this exercise you'll see how to achieve polymorphism with operator 
 * overloading. You can choose any operator from the ASCII table and give it 
 * your own set of rules!
 *
 * Operator overloading can be useful for many things. Consider the + operator. 
 * We can use it to add ints, doubles, floats, or even std::strings. 
 * 
 * https://en.cppreference.com/w/cpp/language/operators
 */

#include <assert.h>

// TODO: Define Point class
  // TODO: Define public constructor
  // TODO: Define + operator overload
  // TODO: Declare attributes x and y

class Point {
public: 
    Point(int x, int y) : x(x), y(y) {}
    Point operator+(Point p) {
        Point pout(x + p.x, y + p.y); 
        return pout;
    }

    int x;
    int y;
        
};

// Test in main()
int main() {
  Point p1(10, 5), p2(2, 4);
  Point p3 = p1 + p2; // An example call to "operator +";
  assert(p3.x == p1.x + p2.x);
  assert(p3.y == p1.y + p2.y);
}