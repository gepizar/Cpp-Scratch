/*
 * Templates enable generic programming by generalizing a function to apply to 
 * any class. Specifically, templates use types as parameters so that the same 
 * implementation can operate on different data types. 
 */
#include <cassert>
#include <string>

template <typename T> 
T Max(T a, T b) {
    return a > b ? a : b; 
}

int main() {
    assert(Max<int>(2, 4) == 4);
    assert(Max<double>(-1.0, -2.3) == -1.0); 
    assert(Max<char>('a', 'b') == 'b');
}

/* 
 * For example, you might need a function to accept many different data types. 
 * The function acts on those arguments, perhaps dividing them or sorting them 
 * or something else. Rather than writing and maintaining the multiple function 
 * declarations, each accepting slightly different arguments, you can write one 
 * function and pass the argument types as parameters. At compile time, the 
 * compiler then expands the code using the types that are passed as parameters.
 * 
 * 
 * We use the keyword template to specify which function is generic. Generic 
 * code is the term for code that is independent of types. It is mandatory to 
 * put the template<> tag before the function signature, to specify and mark 
 * that the declaration is generic.
 * 
 * Besides template, the keyword typename (or, alternatively, class) specifies 
 * the generic type in the function prototype. The parameters that follow 
 * typename (or class) represent generic types in the function declaration.
 */


/* VECTORS
 * 
 * In order to instantiate a templatized class, use a templatized constructor, 
 * for example: Sum<double>(20.0, 13.7). You might recognize this form as the 
 * same form used to construct a vector. That's because vectors are indeed a 
 * generic class!
 */