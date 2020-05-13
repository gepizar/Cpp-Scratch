#include <iostream>
#include <cassert>

class Date {
public:
    Date(int day, int month, int year);
    int Day() const {return day_; }
    void Day(int day);
    int Month() const {return month_; }
    void Month(int month);
    int Year() const {return year_; }
    void Year(int y);
    
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
    if (y % 4 != 0) {
        return false;
    }
    else if (y % 100 != 0) {
        return true;
    }
    else if (y % 400 != 0) {
        return false;
    }
    else {
        return true;
    }
}

int Date::DaysInMonth(int m, int y) const {
    if (m == 2) {
        return LeapYear(y) ? 29 : 28; 
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    }
    else {
        return 31;
    }
}



int main() {

    Date date(29, 2, 2016);
    assert(date.Day() == 29);
    assert(date.Month() == 2);
    assert(date.Year() == 2016);
        
    Date date2(29, 2, 2019);
    assert(date2.Day() != 29);
    assert(date2.Month() == 2);
    assert(date2.Year() == 2019);
}