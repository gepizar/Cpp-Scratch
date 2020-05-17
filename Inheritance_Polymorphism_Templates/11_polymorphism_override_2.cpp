/*
 * Specifying a function as override is good practice, as it empowers the 
 * compiler to verify the code, and communicates the intention of the code to 
 * future users.
 */

#include <cmath>
#include <cassert>

#define PI 3.14159

class VehicleModel {
public:
    virtual void Move(double v, double phi) = 0;
};

class ParticleModel : public VehicleModel {
public:
    void Move(double v, double phi) override {
        theta += phi;
        x += v * cos(theta);
        y += v * sin(theta);
    }
    
    double x {0};
    double y {0};
    double theta {0};
};

class BicycleModel : public ParticleModel {
public: 
    void Move(double v, double phi) override {
        theta += v/L_ * tan(phi); 
        x += v * cos(theta); 
        y += v * sin(theta); 
    }

private: 
    double L_{1}; 
};

int main() {
  // Test function overriding
  ParticleModel particle;
  BicycleModel bicycle;
  particle.Move(10, PI / 9);
  bicycle.Move(10, PI / 9);
  assert(particle.x != bicycle.x);
  assert(particle.y != bicycle.y);
  assert(particle.theta != bicycle.theta);
}