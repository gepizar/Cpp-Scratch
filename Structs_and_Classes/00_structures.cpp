#include <cassert>
#include <iostream>

// Define simple structure
struct Date {
    int day;
    int month;
    int year;
};

// Public a private access modifiers specify wether we can access directly or inderectly to variables.
struct Date2 {
    public: 
        int Day() {return day; }
        void Day(int d) {
            if(d > 1) {
                day = d;
            }
        }

        int Month() {return month; }
        void Month(int m) {
            if (m > 1) {
                month = m;
            }
        }

        int Year() {return year; }
        void Year(int y) {
            if (y > 0) {
                year = y;
            }
        }
        

    private:
        int day {1};
        int month {1};
        int year {0};
        
};

// main
int main() {
    Date date;
    Date2 date2;
    // Initialize 
    date.day = 29;
    date.month = 8;
    date.year = 1981;

    date2.Day(29);
    date2.Month(8);
    date2.Year(1981);

    assert(date.day == 29);
    assert(date.month = 8);
    assert(date.year == 1981);

    std::cout << date.day << "/" << date.month << "/" << date.year << std::endl;
    std::cout << date2.Day() << "/" << date2.Month() << "/" << date2.Year() << std::endl;
}