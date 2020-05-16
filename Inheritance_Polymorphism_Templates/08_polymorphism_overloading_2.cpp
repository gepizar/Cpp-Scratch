#include <iostream>

// TODO: Write hello() function
void hello() {
    std::cout << "Hello, World!\n"; 
}
// TODO: Overload hello() three times
class Human {};
class Monkey {};
class President {}; 

void hello(Human human) {
    std::cout << "Hello, Human!\n";
}

void hello(Monkey monkey) {
    std::cout << "Hello, Monkey!\n"; 
}

void hello(President president) {
    std::cout << "Hello, President!\n";
}
// TODO: Call hello() from main()

int main() {
    hello();
    hello(Human());
    hello(Monkey());
    hello(President());
}