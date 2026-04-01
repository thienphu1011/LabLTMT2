#include <iostream>

using namespace std;

class Population {
private:
    int population;
    int births;
    int deaths;

public:
    Population(int p, int b, int d) {
        if (p < 1) {
            population = 1;
        } else {
            population = p;
        }

        if (b < 0) {
            births = 0;
        } else {
            births = b;
        }

        if (d < 0) {
            deaths = 0;
        } else {
            deaths = d;
        }
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
    cout << "Enter population, births, and deaths: ";
    cin >> p >> b >> d;

    Population pop(p, b, d);

    cout << "Birth Rate: " << pop.getBirthRate() << endl;
    cout << "Death Rate: " << pop.getDeathRate() << endl;

    return 0;
}