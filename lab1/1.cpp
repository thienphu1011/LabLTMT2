#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int month;
    int day;
    int year;
    string monthNames[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

public:
    Date(int m, int d, int y) {
        if (m < 1 || m > 12) {
            month = 1;
        } else {
            month = m;
        }

        if (d < 1 || d > 31) {
            day = 1;
        } else {
            day = d;
        }

        year = y;
    }

    void printFormat1() {
        cout << month << "/" << day << "/" << year << endl;
    }

    void printFormat2() {
        cout << monthNames[month - 1] << " " << day << ", " << year << endl;
    }

    void printFormat3() {
        cout << day << " " << monthNames[month - 1] << " " << year << endl;
    }
};

int main() {
    int m, d, y;
    cout << "Enter month, day, year: ";
    cin >> m >> d >> y;

    Date myDate(m, d, y);

    cout << "\nOutput:\n";
    myDate.printFormat1();
    myDate.printFormat2();
    myDate.printFormat3();

    return 0;
}