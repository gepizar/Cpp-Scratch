#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> shared1(new int);
    std::cout << "shared pointer count = " << shared1.use_count() << std::endl;

    {
        std::shared_ptr<int> shared2 = shared1; 
        std::cout << "shared pointer count = " << shared1.use_count() << std::endl;
        
    }

    std::cout << "shared pointer count = " << shared1.use_count() << std::endl;

    // My example.

    std::shared_ptr<int> myShared1 = std::make_shared<int>(); 
    std::cout << "My shared pointer count = " << myShared1.use_count() << std::endl;

    {
        std::shared_ptr<int> myShared2 = myShared1; 
        std::cout << "My shared pointer count = " << myShared1.use_count() << std::endl;
        
    }

    std::cout << "My shared pointer count = " << myShared1.use_count() << std::endl;

    return 0; 
     
}