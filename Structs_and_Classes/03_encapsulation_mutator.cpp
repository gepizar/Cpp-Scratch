#include <string>
#include <cstring>
#include <iostream>

class Car {
    private: 
        int horsepower_;
        int weight_; 
        std::string brand_;

    public:
        void SetBrand(char*);
        std::string GetBrand() const;  


};

void Car::SetBrand(char* brand) {
    Car::brand_ = brand;
}

std::string Car::GetBrand() const {
    return brand_;
}


int main() {
    Car car;
    char brand[] = "Peugeot"; 
    car.SetBrand(brand);
    std::cout << car.GetBrand() << "\n";

}