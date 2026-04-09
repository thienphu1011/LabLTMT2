#include <iostream>

using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

    bool isLeapYear(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

public:
    class InvalidDay {};
    class InvalidMonth {};

    Date(int m, int d, int y) {
        if (m < 1 || m > 12) {
            throw InvalidMonth();
        }

        int maxDays = 31;
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            maxDays = 30;
        } else if (m == 2) {
            if (isLeapYear(y)) {
                maxDays = 29;
            } else {
                maxDays = 28;
            }
        }

        if (d < 1 || d > maxDays) {
            throw InvalidDay();
        }

        month = m;
        day = d;
        year = y;
    }

    void printFormat1() {
        cout << month << "/" << day << "/" << year << "\n";
    }
};

int main() {
    int m, d, y;

    while (true) {
        cin >> m >> d >> y;

        try {
            Date myDate(m, d, y);
            myDate.printFormat1();
            break; 
        }
        catch (Date::InvalidDay) {
            cout << "Error: Invalid day for the given month and year. Please try again.\n";
        }
        catch (Date::InvalidMonth) {
            cout << "Error: The month must be between 1 and 12. Please try again.\n";
        }
    }

    return 0;
}