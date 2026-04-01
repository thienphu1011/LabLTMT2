#include <iostream>
#include <cmath>

using namespace std;

class Mortgage {
private:
    double loan;
    double rate;
    int years;

public:
    Mortgage() {
        loan = 0.0;
        rate = 0.0;
        years = 0;
    }

    void setLoan(double l) {
        if (l < 0) {
            loan = 0;
        } else {
            loan = l;
        }
    }

    void setRate(double r) {
        if (r < 0) {
            rate = 0;
        } else {
            rate = r;
        }
    }

    void setYears(int y) {
        if (y < 0) {
            years = 0;
        } else {
            years = y;
        }
    }

    double getMonthlyPayment() {
        double monthlyRate = rate / 12.0;
        double term = pow((1 + monthlyRate), (12 * years));
        double payment = (loan * monthlyRate * term) / (term - 1);
        return payment;
    }

    double getTotalPaid() {
        return getMonthlyPayment() * 12 * years;
    }
};

int main() {
    Mortgage myMortgage;
    double l, r;
    int y;

    cout << "Enter loan amount: ";
    cin >> l;
    myMortgage.setLoan(l);

    cout << "Enter annual interest rate: ";
    cin >> r;
    myMortgage.setRate(r);

    cout << "Enter number of years: ";
    cin >> y;
    myMortgage.setYears(y);

    cout << "Monthly Payment: $" << myMortgage.getMonthlyPayment() << endl;
    cout << "Total Amount Paid: $" << myMortgage.getTotalPaid() << endl;

    return 0;
}