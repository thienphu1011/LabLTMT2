#include <iostream>

using namespace std;

class Population {
private:
    int population;
    int births;
    int deaths;

public:
    Population(int p, int b, int d) {
            population = p;       
            births = b;
            deaths = d;
    }

    double getBirthRate() {
        return static_cast<double>(births) / population;
    }

    double getDeathRate() {
        return static_cast<double>(deaths) / population;
    }
};

int main() {
    int p, b, d;
    cout << "Enter population: ";
    cin >> p ;
    while (p < 1) {
        cout << "Invalid population. Population must be bigger than 1: ";
        cin >> p;
    }
    cout << "Enter births: ";
    cin >> b;
    while (b < 0) {
        cout << "Invalid births. Please enter a positive value: ";
        cin >> b;
    }
    cout << "Enter deaths: ";
    cin >> d;
    while (d < 0) {
        cout << "Invalid deaths. Please enter a positive value: ";
        cin >> d;
    }


    Population pop(p, b, d);

    cout << "Birth Rate: " << pop.getBirthRate() << endl;
    cout << "Death Rate: " << pop.getDeathRate() << endl;

    return 0;
}