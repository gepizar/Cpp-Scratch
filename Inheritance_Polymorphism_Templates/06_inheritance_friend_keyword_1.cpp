/* Friends
 * In C++, friend classes provide an alternative inheritance mechanism to 
 * derived classes. The main difference between classical inheritance and friend 
 * inheritance is that a friend class can access private members of the base 
 * class, which isn't the case for classical inheritance. In classical 
 * inheritance, a derived class can only access public and protected members of 
 * the base class.
 */


#include <cassert>

class Heart {
private:
    int rate_{80};
    friend class Human;
};

class Human {
public:
    Heart heart; 
    void Excercise() {heart.rate_ = 150; }
    int HeartRate() {return heart.rate_; }
};

int main() {
    Human human; 
    assert(human.HeartRate() == 80);
    human.Excercise();
    assert(human.HeartRate() == 150); 
}

