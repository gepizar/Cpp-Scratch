#include <cassert>
#include <cmath>
#include <stdexcept>

/*
 * Add a mutator for the radius
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
        float const pi_{3.14159};
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

