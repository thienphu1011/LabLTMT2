#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int month;
    int day;
    int year;
    static const int daysPerMonth[13];

    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int getDaysInMonth(int m, int y) const {
        if (m == 2 && isLeapYear(y)) return 29;
        return daysPerMonth[m];
    }

    int toDays() const {
        int totalDays = day;
        for (int y = 1; y < year; ++y) {
            totalDays += isLeapYear(y) ? 366 : 365;
        }
        for (int m = 1; m < month; ++m) {
            totalDays += getDaysInMonth(m, year);
        }
        return totalDays;
    }

public:
    Date(int m = 1, int d = 1, int y = 1900) : month(m), day(d), year(y) {}

    Date& operator++() {
        day++;
        if (day > getDaysInMonth(month, year)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        return *this;
    }

    Date operator++(int) {
        Date temp = *this;
        ++(*this);
        return temp;
    }

    Date& operator--() {
        day--;
        if (day < 1) {
            month--;
            if (month < 1) {
                month = 12;
                year--;
            }
            day = getDaysInMonth(month, year);
        }
        return *this;
    }

    Date operator--(int) {
        Date temp = *this;
        --(*this);
        return temp;
    }

    int operator-(const Date& right) const {
        return this->toDays() - right.toDays();
    }

    friend ostream& operator<<(ostream& strm, const Date& obj) {
        string months[] = { "", "January", "February", "March", "April", "May", "June", 
                            "July", "August", "September", "October", "November", "December" };
        strm << months[obj.month] << " " << obj.day << ", " << obj.year;
        return strm;
    }

    friend istream& operator>>(istream& strm, Date& obj) {
        int m, d, y;
        char slash1, slash2;
        strm >> m >> slash1 >> d >> slash2 >> y;

        if (m >= 1 && m <= 12) {
            int maxDays = obj.daysPerMonth[m];
            if (m == 2 && obj.isLeapYear(y)) {
                maxDays = 29;
            }
            if (d >= 1 && d <= maxDays) {
                obj.month = m;
                obj.day = d;
                obj.year = y;
            }
        }
        return strm;
    }
};

const int Date::daysPerMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
    Date d1(4, 10, 2014);
    Date d2(4, 18, 2014);
    
    cout << d2 - d1 << "\n";
    
    Date d3;
    cin >> d3;
    cout << d3 << "\n";
    
    d3++;
    cout << d3 << "\n";
    
    --d3;
    cout << d3 << "\n";

    return 0;
}