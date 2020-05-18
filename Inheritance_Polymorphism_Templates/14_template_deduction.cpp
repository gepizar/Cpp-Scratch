/*
 * Template deduction is when the compiler determines the type for a template 
 * without us having to specify it.
 */

#include <cassert>
#include <string>
#include <vector>

template <typename T> 
T Max(T a, T b) {
    return a > b ? a : b; 
}

int main() {
    // assert(Max<int>(2, 4) == 4);
    // assert(Max<double>(-1.0, -2.3) == -1.0); 
    // assert(Max<char>('a', 'b') == 'b');

    // deduction:
    assert(Max(2, 4) == 4);
    assert(Max(-1.0, -2.3) == -1.0); 
    assert(Max('a', 'b') == 'b');

    // We can use deduction in std::vector because is a template. But only when 
    // compiled using c++17
    // g++ -std=c++17 14_template_deduction.cpp

    std::vector<int> v1{1, 2, 3};
    // std::vector v2{1, 2, 3};

}

/* 
 * Deduction occurs when you instantiate an object without explicitly 
 * identifying the types. Instead, the compiler "deduces" the types. This can be 
 * helpful for writing code that is generic and can handle a variety of inputs.
 * 
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rt-deduce
 */