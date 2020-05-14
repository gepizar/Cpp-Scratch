/*
 * Abstraction refers to the separation of a class's interface from the details 
 * of its implementation. The interface provides a way to interact with an 
 * object, while hiding the details and implementation of how the class works.
 * 
 * The user is able to interact with the Date class through the String() 
 * function, but the user does not need to know about the implementation 
 * of either Date or String().
 * 
 * For example, the user does not know, or need to know, that this object 
 * internally contains three int member variables. The user can just call the 
 * String() method to get data.

 * If the designer of this class ever decides to change how the data is stored
 * internally -- using a vector of ints instead of three separate ints, for 
 * example -- the user of the Date class will not need to know.
 */


#include <cassert>
#include <vector>
#include <string>
class Date {
public:
    Date(int day, int month, int year);
    int Day() const {return day_; }
    void Day(int day);
    int Month() const {return month_; }
    void Month(int month);
    int Year() const {return year_; }
    void Year(int y);
    std::string String() const; 
    
private:
    int day_{1};
    int month_{1};
    int year_{0};
    bool LeapYear(int y) const;
    int DaysInMonth(int m, int y) const;
};

Date::Date(int day, int month, int year) {
    Year(year);
    Month(month);
    Day(day);
}

// mutator: mutates day_
void Date::Day(int day) {
    if (day >= 1 && day <= DaysInMonth(Month(), Year())) {
        day_ = day;
    }
}

void Date::Month(int month) {
    if (month >= 1 && month <= 12) {
        month_ = month;
    }
}

void Date::Year(int year) {
    year_ = year;
}

bool Date::LeapYear(int y) const {
    if (y % 4 != 0) 
        return false;
    else if (y % 100 != 0) 
        return true;
    else if (y % 400 != 0) 
        return false;
    else 
        return true;
}

int Date::DaysInMonth(int m, int y) const {
    if (m == 2) 
        return LeapYear(y) ? 29 : 28; 
    else if (m == 4 || m == 6 || m == 9 || m == 11) 
        return 30;
    else 
        return 31;
}


std::string Date::String() const {
    std::vector<std::string> months{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
      return months[Month()-1] + " " + std::to_string(Day()) + ", " + std::to_string(Year());
}


// Test
int main() {
  Date date(29, 8, 1981);
  assert(date.String() == "August 29, 1981");
}