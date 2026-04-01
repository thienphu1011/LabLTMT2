#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

public:
    class InvalidDay {};
    class InvalidMonth {};

    Date(int m, int d, int y) {
        if (m < 1 || m > 12) {
            throw InvalidMonth();
        }
        if (d < 1 || d > 31) {
            throw InvalidDay();
        }
        month = m;
        day = d;
        year = y;
    }

    void print() {
        cout << month << "/" << day << "/" << year << "\n";
    }
};

int main() {
    int m, d, y;
    cin >> m >> d >> y;

    try {
        Date myDate(m, d, y);
        myDate.print();
    }
    catch (Date::InvalidDay) {
        cout << "Error: Invalid Day\n";
    }
    catch (Date::InvalidMonth) {
        cout << "Error: Invalid Month\n";
    }

    return 0;
}