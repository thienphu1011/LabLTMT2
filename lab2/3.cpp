#include <iostream>
#include <iomanip>

using namespace std;

class DivSales {
private:
    double sales[4];
    static double totalCorporateSales;

public:
    DivSales() {
        for (int i = 0; i < 4; i++) {
            sales[i] = 0.0;
        }
    }

    void setSales(double q1, double q2, double q3, double q4) {
        sales[0] = q1;
        sales[1] = q2;
        sales[2] = q3;
        sales[3] = q4;
        totalCorporateSales += (q1 + q2 + q3 + q4);
    }

    double getSales(int quarter) const {
        if (quarter >= 0 && quarter <= 3) {
            return sales[quarter];
        }
        return 0.0;
    }

    static double getTotalCorporateSales() {
        return totalCorporateSales;
    }
};

double DivSales::totalCorporateSales = 0.0;

int main() {
    DivSales divisions[6];
    double q1, q2, q3, q4;

    for (int i = 0; i < 6; i++) {
        do {
            cin >> q1 >> q2 >> q3 >> q4;
        } while (q1 < 0 || q2 < 0 || q3 < 0 || q4 < 0);
        
        divisions[i].setSales(q1, q2, q3, q4);
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            cout << fixed << setprecision(2) << divisions[i].getSales(j) << " ";
        }
        cout << "\n";
    }

    cout << fixed << setprecision(2) << DivSales::getTotalCorporateSales() << "\n";

    return 0;
}