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
            month = m;
            day = d;
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
    
    cout << "Enter year: ";
    cin >> y;
    while (y < 1) {
        cout << "Invalid year. Please enter a positive value: ";
        cin >> y;
    }
    
    cout << "Enter month: ";
    cin >> m;
    while (m < 1 || m > 12) {
        cout << "Invalid month. Please enter a value between 1 and 12: ";
        cin >> m;
    }
    int maxDays = 31; 
    
    if (m == 2) {
        bool isLeapYear = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        if (isLeapYear) {
            maxDays = 29;
        } else {
            maxDays = 28;
        }
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        maxDays = 30;
    }
    cout << "Enter day: ";
    cin >> d;
    
    while (d < 1 || d > maxDays) {
        cout << "Invalid day. Month " << m << " in year " << y 
             << " has a maximum of " << maxDays << " days. Please enter again: ";
        cin >> d;
    }
    
    Date myDate(m, d, y);
    cout << "\nOutput:\n";
    myDate.printFormat1();
    myDate.printFormat2();
    myDate.printFormat3();

    return 0;
}