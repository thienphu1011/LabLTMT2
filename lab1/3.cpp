#include <iostream>
#include <cmath>

using namespace std;

class Mortgage {
private:
    double loan;
    double rate;
    double years;

public:
    Mortgage() {
        loan = 0.0;
        rate = 0.0;
        years = 0;
    }

    void setLoan(double l) {
        loan = l;
    }

    void setRate(double r) {
        rate = r;
    }

    void setYears(double y) {
        years = y;
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
    double y;

    cout << "Enter loan amount: ";
    cin >> l;
    while (l < 0) {
        cout << "Invalid loan amount. Please enter a positive value: ";
        cin >> l;
    }
    myMortgage.setLoan(l);

    cout << "Enter annual interest rate: ";
    cin >> r;
    while (r < 0) {
        cout << "Invalid interest rate. Please enter a positive value: ";
        cin >> r;
    }

    myMortgage.setRate(r);

    cout << "Enter number of years: ";
    cin >> y;
    while (y < 0 || y == 0) {
        cout << "Invalid number of years. Please enter a positive value and year cannot be zero: ";
        cin >> y;
        
    }

    myMortgage.setYears(y);

    cout << "Monthly Payment: $" << myMortgage.getMonthlyPayment() << endl;
    cout << "Total Amount Paid: $" << myMortgage.getTotalPaid() << endl;

    return 0;
}