#include <cassert>
#include <cmath>
#include <stdexcept>

class Sphere {
    public:
        Sphere(int radius) : radius_(radius),  volume_(pi_ * 4/3 * pow(radius_,3)) {
            Validate();
        } 
        int Radius() const {return radius_; }
        float Volume() const {return volume_; }

    private:
        float const pi_{3.14159};
        int const radius_;
        float const volume_;
        void Validate();

};

void Sphere::Validate() {
    if (Radius() <= 0) 
        throw std::invalid_argument("Invalid radius, must be positive");
}


int main(void) {
  Sphere sphere(5);
  assert(sphere.Radius() == 5);
  assert(abs(sphere.Volume() - 523.6) < 1);
}

