
#include <cassert>
#include <cmath>
#include <stdexcept>

/*
 * Class members can be declared static, which means that the member belongs to 
 * the entire class, instead of to a specific instance of the class. More 
 * specifically, a static member is created only once and then shared by all 
 * instances (i.e. objects) of the class. That means that if the static member 
 * gets changed, either by a user of the class or within a member function of 
 * the class itself, then all members of the class will see that change the next
 * time they access the static member.
 * 
 * It can be used to know the number of objtects of a class, for example using a
 * static int counter
 * 
 * Declare pi_ as static
 */

class Sphere {
    public:
        Sphere(int radius) : radius_(radius),  volume_(pi_ * 4/3 * pow(radius_,3)) {
            Validate();
        } 
        int Radius() const {return radius_; }
        float Volume() const {return volume_; }

        void Radius(int radius);
        

    private:
        // static float const pi_{3.14159}; // Error
        // Error: 'constexpr' needed for in-class initialization 
        static float constexpr pi_{3.14159};
        int radius_;
        float volume_;
        void Validate();

};

void Sphere::Validate() {
    if (Radius() <= 0) 
        throw std::invalid_argument("Invalid radius, must be positive");
}

void Sphere::Radius(int radius) {
    radius_ = radius;
    Validate();
    volume_ = pi_ * 4/3 * pow(radius_,3);
}


// Test
int main(void) {
  Sphere sphere(5);
  assert(sphere.Radius() == 5);
  assert(abs(sphere.Volume() - 523.6) < 1);

  sphere.Radius(3);
  assert(sphere.Radius() == 3);
  assert(abs(sphere.Volume() - 113.1) < 1);

  bool caught{false};
  try {
    sphere.Radius(-1);
  } catch (...) {
    caught = true;
  }
  assert(caught);
}

