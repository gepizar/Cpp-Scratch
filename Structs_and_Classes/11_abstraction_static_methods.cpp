#include <cassert>
#include <cmath>
#include <stdexcept>

/* 
 * A Static method define the implementation of Volume to calculate the volume
 * of the sphere and work without ever actually initialize an object of type
 * Sphere.
 */

class Sphere {
  public:
    static float Volume(int radius) {
      return pi_ * 4/3 * pow(radius,3);
    }

  private:
    static float constexpr pi_{3.14159};
};

// Test
int main(void) {
  assert(abs(Sphere::Volume(5) - 523.6) < 1);
}
