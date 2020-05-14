#include <cassert>
#include <stdexcept>

class Student {
    public:
        Student(std::string name, int grade, float gpa) 
                : name_(name), grade_(grade), gpa_(gpa) {
            Validate();
        }
        std::string Name() const {return name_; }
        void Name(std::string name);
        int Grade() const {return grade_; }
        void Grade(int grade);
        float GPA() const {return gpa_; }
        void GPA(float gpa);

    private:
        std::string name_;
        int grade_;
        float gpa_;
        void Validate(); 

};

void Student::Name(std::string name) {
    name_ = name;
}
void Student::Grade(int grade) {
    grade_ = grade;
    Validate();
} 
void Student::GPA(float gpa) {
    gpa_ = gpa;
    Validate();
}
void Student::Validate() {
    if (Grade() < 0 || Grade() > 12)
        throw std::invalid_argument("Invalid grade");
    if (GPA() < 0.0 || GPA() > 4.0)
        throw std::invalid_argument("Invalid GPA");
}

// Test
int main() {
    Student student("Mr. G", 9, 3.9);
    assert(student.Name() == "Mr. G");

    bool myexcept1 {false};
    bool myexcept2 {false};

    try {
        student.Grade(-100);
    }
    catch(...) {
        // Accept everything
        myexcept1 = true;
    }
    assert(myexcept1);

    try
    {
        student.GPA(4.5);
    }
    catch(...)
    {
        myexcept2 = true;
    }
    assert(myexcept2);
}