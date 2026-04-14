#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int day, month, year;

    bool isLeap(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int getDaysInMonth(int m, int y) const {
        if (m == 2) return isLeap(y) ? 29 : 28;
        if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
        return 31;
    }

    string monthName(int m) const {
        string months[] = { "January","February","March","April","May","June",
                            "July","August","September","October","November","December" };
        return months[m - 1];
    }

public:
    Date(int d = 1, int m = 1, int y = 2000) {
        day = d; month = m; year = y;
    }

    
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

    
    int dayOfYear() const {
        int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        int total = day;

        for (int i = 1; i < month; i++) {
            total += days[i];
            if (i == 2 && isLeap(year)) total++;
        }
        return total;
    }

    int operator-(const Date& other) const {
        if (year == other.year)
            return dayOfYear() - other.dayOfYear();

        int days = 0;

        int daysOtherYear = other.isLeap(other.year) ? 366 : 365;
        days += daysOtherYear - other.dayOfYear();

        for (int y = other.year + 1; y < year; y++) {
            days += isLeap(y) ? 366 : 365;
        }

        // phần đầu năm this
        days += dayOfYear();

        return days;
    }

    
    friend ostream& operator<<(ostream& out, const Date& d) {
        out << d.monthName(d.month) << " " << d.day << ", " << d.year;
        return out;
    }

    
    friend istream& operator>>(istream& in, Date& d) {
    int m, dy, yr;

    
    do {
        cout << "Enter year (> 0): ";
        in >> yr;
    } while (yr <= 0);

    
    do {
        cout << "Enter month (1-12): ";
        in >> m;
    } while (m < 1 || m > 12);

    int maxDays;
    if (m == 2)
        maxDays = ((yr % 4 == 0 && yr % 100 != 0) || (yr % 400 == 0)) ? 29 : 28;
    else if (m == 4 || m == 6 || m == 9 || m == 11)
        maxDays = 30;
    else
        maxDays = 31;

    
    do {
        cout << "Enter day (1-" << maxDays << "): ";
        in >> dy;
    } while (dy < 1 || dy > maxDays);

    d.day = dy;
    d.month = m;
    d.year = yr;

    return in;
    }
};

int main() {
    Date d1, d2;

    cout << "Enter Date 1:\n";
    cin >> d1;

    cout << "Enter Date 2:\n";
    cin >> d2;

    cout << "\nDate 1: " << d1 << endl;
    cout << "Date 2: " << d2 << endl;

    cout << "Days between: " << (d1 - d2) << endl;

    cout << "\nPrefix ++: " << ++d1 << endl;
    cout << "Postfix ++: " << d1++ << " -> " << d1 << endl;

    cout << "\nPrefix --: " << --d2 << endl;
    cout << "Postfix --: " << d2-- << " -> " << d2 << endl;

    return 0;
}
