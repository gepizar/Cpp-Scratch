#include<iostream>

// File that creates a stack overflow.
// Program crash when the stack memory is full. 
// Aproximately 8mb
void stackoverflow(int &i)
{
    int s = i++; 
    std::cout<< s << ": stack bottom: " << &i << ", current: " << &s << "\n";
    stackoverflow(i);
}
int main()
{
    int i = 0;
    stackoverflow(i);
    
}