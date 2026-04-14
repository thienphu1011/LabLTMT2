#include <iostream>
#include <string>
using namespace std;

class Date{
public:
    class InvalidDay{};
    class InvalidMonth{};
    
private:
    int month, day, year;
    static bool isLeapYear(int y){
        return (y % 400 == 0) || ( y % 4 == 0 && y % 100 != 0); 
    }
    static int daysInMonth(int m, int y){
        static const int base[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if (m == 2) return base[m-1] + (isLeapYear(y) ? 1 : 0);
        return base[m - 1];
    }
    static string monthName(int m){
        static const string names[12] = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };
        return names[m-1];
    }

public: 
   Date() : month(1), day(1), year(0) {}
   Date(int m, int d, int y) : month(1), day(1), year(0){
      setYear(y);
      setMonth(m);
      setDay(d);
   }
   void setMonth(int m){
    if (m < 1 || m > 12) throw InvalidMonth();
    month = m;
   }
   void setYear(int y){
    year = y;
   }
   void setDay(int d){
    if (d < 1 || d > 31) throw InvalidDay();
    int maxD = daysInMonth(month, year);
    if (d > maxD) throw InvalidDay();
    day = d;
   }
   void printDate() const{
    cout << month << "/" << day << "/" << year << "\n";
    cout << monthName(month) << " " << day << ", " << year << "\n";
    cout << day << " " << monthName(month) << " " << year << "\n";
   }
};

int main(){
    int d, m, y;
    Date present;

    try {
        cout << "Enter the month: ";
        cin >> m;
        present.setMonth(m);

        cout << "Enter the year: ";
        cin >> y;
        present.setYear(y);

        cout << "Enter the day: ";
        cin >> d;
        present.setDay(d);

        present.printDate();
    }
    catch (Date::InvalidMonth){
        cout << "InvalidMonth: month must be 1...12\n";
    }
    catch (Date::InvalidDay){
        cout << "InvalidDay: day is invalid\n";
    }
    return 0;
}
