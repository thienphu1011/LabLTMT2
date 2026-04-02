#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
class Calendar_date {
    private:
    int day;
    int month;
    int year;
    public:
    void setMonth(int);
    void setYear(int);
    void setDay(int);
    int getMonth() const;
    int getYear() const;
    int getDay() const;
   string getMonthname() const;
   bool isValidDate() const;
};
void Calendar_date::setMonth(int m) {
    if (m >=1 || m <= 12)
 	  month = m;
    else {
        cout<<"Invalid Month"<<endl;
        exit(EXIT_FAILURE);
    }
}
void Calendar_date::setDay(int d)  {
    if (d>=1 && d<=31)
 	   day = d;
    else {
        cout<<"Invalid Day"<<endl;
        exit(EXIT_FAILURE);
    }
}
void Calendar_date::setYear(int y) {
    if (y>1)
 	  year = y;
    else {
        cout<<"Invalid Year"<<endl;
        exit(EXIT_FAILURE);
    }
}


int Calendar_date::getMonth() const {
    return month;
}
int Calendar_date::getDay() const {
    return day;
}
int Calendar_date::getYear() const {
    return year;
}
string Calendar_date::getMonthname() const {
    switch (month) {
        case 1: return "January";
        case 2: return "Febuary";
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
bool Calendar_date::isValidDate() const {
    if ((month ==4 || month == 6 || month == 9 ||month == 11)&& day >30)
    return false;
    if (month == 2)
    {
        if ((year % 4 == 0))
        {
        if (day > 29)
        return false;
        }else
            {
                if (day >28)
                return false;
            }
    }
    return true;
}
int main()
{
    Calendar_date now;
    int nowMonth;
    int nowDay;
    int nowYear;
    cout << "This program will print out the date in 3 different ways" << endl;
    cout << "What is the month (in number)? " << endl;
    cin >> nowMonth;
    cout << "What is the day? " << endl;
    cin >> nowDay;
    cout << "What is the year? " << endl;
    cin >> nowYear;
    now.setMonth(nowMonth);
    now.setDay(nowDay);
    now.setYear(nowYear);
    if (now.isValidDate())
    cout <<"The date is valid"<<endl;
    else
    cout <<"The date is invalid"<<endl;
    exit(EXIT_FAILURE);
    cout << "Here is the first way of displaying the date:" << endl;
    cout <<now.getMonthname()<<"/"<<now.getDay()<<"/"<<now.getYear()<< endl;
    cout << "Here is the second way of displaying the date:" << endl;
    cout <<now.getMonthname()<<" "<<now.getDay()<<", "<<now.getYear()<< endl;
    cout << "Here is the third way of displaying the date:" << endl;
    cout <<now.getDay()<<" "<<now.getMonthname()<<" "<<now.getYear()<< endl;
    return 0;
}

