#include <cassert>
#include <stdexcept>


class Pyramid {
    public:
        Pyramid(int length, int width, int height) 
                : length_(length), width_(width), height_(height) { 
            Validate();
        }
        int Length() const {return length_; }
        void Length(int length);
        int Width() const {return width_; }
        void Width(int width);
        int Height() const {return height_; }
        void Height(int height); 
        float Volume() const; 

    private:
        int length_;
        int width_;
        int height_;
        void Validate();
};

void Pyramid::Validate() {
    if (length_ <= 0 || width_ <= 0 || height_ <= 0) {
        throw std::invalid_argument("Negative Dimension");
    }
}

void Pyramid::Length(int length) {
    length_ = length;
    Validate();
}

void Pyramid::Width(int width) {
    width_ = width;
    Validate();
}

void Pyramid::Height(int height) {
    height_ = height;
    Validate();
}

float Pyramid::Volume() const {
    return Length() * Width() * Height() / 3.0;
}

// Test
int main() {
  Pyramid pyramid(4, 5, 6);
  assert(pyramid.Length() == 4);
  assert(pyramid.Width() == 5);
  assert(pyramid.Height() == 6);
  assert(pyramid.Volume() == 40);

  bool caught{false};
  try {
    Pyramid invalid(-1, 2, 3);
  } catch (...) {
    // https://es.cppreference.com/w/cpp/language/try_catch
    // esto se ejecuta si f() lanza std::string o int o cualquier otro tipo no relacionado
    caught = true;
  }
  assert(caught);
}