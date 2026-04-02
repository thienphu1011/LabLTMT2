#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;
class Date
{
    private:
       int month;
       int day;
       int year;
       static bool isLeapYear(int year)
        {
           return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
       }
       static int daysInMonth(int month, int year)
    {
           switch (month)
        {
           case 2: return isLeapYear(year) ? 29 : 28;
           case 4: case 6: case 9: case 11: return 30;
           default: return 31;
       }
   }
    public:
       void setMonth(int m)
        {
           if (m >= 1 && m <= 12)
               month = m;
           else
            {
               cout << "You put in an invalid month!" << endl;
               exit(EXIT_FAILURE);
           }
       }
       void setDay(int d)
        {
           if (d >= 1 && d <= 31)
               day = d;
           else
            {
               cout << "You put in an invalid day!" << endl;
               exit(EXIT_FAILURE);
           }
       }
       void setYear(int y)
        {
           if (y >= 1)
               year = y;
           else
            {
               cout << "You put in an invalid year!" << endl;
               exit(EXIT_FAILURE);
           }
       }
       int getMonth() const { return month; }
       int getDay() const { return day; }
       int getYear() const { return year; }
       string getMonthName() const
        {
           switch (month)
            {
           case 1: return "January";
           case 2: return "February";
           case 3: return "March";
           case 4: return "April";
           case 5: return "May";
           case 6: return "June";
           case 7: return "July";
           case 8: return "August";
           case 9: return "September";
           case 10: return "October";
           case 11: return "November";
           case 12: return "December";
           default: return "Invalid";
           }
       }
       bool isValidDate() const
        {
           if (day < 1 || day > daysInMonth(month, year))
               return false;
           return true;
       }
       Date& operator++()
        {
           day++;
               if (day > daysInMonth(month, year))
            {
               day = 1;
               month++;
               if (month > 12)
                {
                   month = 1;
                   year++;
               }
           }
       return *this;
       }   
   Date operator++(int)
    {
       Date temp = *this;
       ++(*this);
       return temp;
   }
   Date& operator--()
    {
       day--;
       if (day < 1)
        {
           month--;
           if (month < 1)
            {
               month = 12;
               year--;
           }
           day = daysInMonth(month, year);
       }
       return *this;
   }
   Date operator--(int)
    {
       Date temp = *this;
       --(*this);
       return temp;
   }
   int operator-(const Date& other) const
    {
       auto toDays = [](int d, int m, int y)
        {
           int days = d;
           for (int i = 1; i < m; ++i)
               days += daysInMonth(i, y);
           for (int i = 1; i < y; ++i)
            	  days += isLeapYear(i) ? 366 : 365;
           return days;
       };
       return abs(toDays(day, month, year) - toDays(other.day, other.month, other.year));
   }
};
int main()
{
   Date now, other;
   int nowMonth, nowDay, nowYear;
   cout << "Enter today's date:" << endl;
   cout << "Month (1-12): ";
   cin >> nowMonth;
   cout << "Day: ";
   cin >> nowDay;
   cout << "Year: ";
   cin >> nowYear;
   now.setMonth(nowMonth);
   now.setDay(nowDay);
   now.setYear(nowYear);
   if (!now.isValidDate())
    {
       cout << "The date is invalid." << endl;
       return 1;
   }
   cout << "\nToday's date: " << now.getMonthName() << " " << now.getDay() << ", " << now.getYear() << endl;
   Date tomorrow = now;
   tomorrow++;
   cout << "Tomorrow's date: " << tomorrow.getMonthName() << " " << tomorrow.getDay() << ", " << tomorrow.getYear() << endl;
   Date yesterday = now;
   yesterday--;
   cout << "Yesterday's date: " << yesterday.getMonthName() << " " << yesterday.getDay() << ", " << yesterday.getYear() << endl;
   int otherMonth, otherDay, otherYear;
   cout << "\nEnter another date to find the difference:" << endl;
   cout << "Month (1-12): ";
   cin >> otherMonth;
   cout << "Day: ";
   cin >> otherDay;
   cout << "Year: ";
   cin >> otherYear;
   other.setMonth(otherMonth);
   other.setDay(otherDay);
   other.setYear(otherYear);
   if (!other.isValidDate())
    {
       cout << "The second date is invalid." << endl;
       return 1;
   }
   int diff = now - other;
   cout << "Number of days between the two dates: " << diff << " days" << endl;
   return 0;
}



