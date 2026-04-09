#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Employee {
private:
    string name;
    int idNumber;
    string department;
    string position;

public:
    Employee(string n, int id, string dept, string pos) {
        name = n;
        idNumber = id;
        department = dept;
        position = pos;
    }

    Employee(string n, int id) {
        name = n;
        idNumber = id;
        department = "";
        position = "";
    }

    Employee() {
        name = "";
        idNumber = 0;
        department = "";
        position = "";
    }

    void setName(string n) { name = n; }
    void setIdNumber(int id) { idNumber = id; }
    void setDepartment(string dept) { department = dept; }
    void setPosition(string pos) { position = pos; }

    string getName() const { return name; }
    int getIdNumber() const { return idNumber; }
    string getDepartment() const { return department; }
    string getPosition() const { return position; }
};

class ShiftSupervisor : public Employee {
private:
    double annualSalary;
    double annualBonus;

public:
    ShiftSupervisor() : Employee() {
        annualSalary = 0.0;
        annualBonus = 0.0;
    }

    ShiftSupervisor(string n, int id, string dept, string pos, double salary, double bonus) 
        : Employee(n, id, dept, pos) {
        annualSalary = salary;
        annualBonus = bonus;
    }

    void setAnnualSalary(double salary) { annualSalary = salary; }
    void setAnnualBonus(double bonus) { annualBonus = bonus; }

    double getAnnualSalary() const { return annualSalary; }
    double getAnnualBonus() const { return annualBonus; }
};

int main() {
    ShiftSupervisor supervisors[] = {
        ShiftSupervisor("Phu", 47899, "Manufacturing", "Shift Supervisor", 75000.0, 8500.0),
        ShiftSupervisor("John", 12345, "Sales", "Shift Supervisor", 65000.0, 5000.0),
        ShiftSupervisor("Anna", 81774, "Engineering", "Shift Supervisor", 82000.0, 9500.0)
    };

    cout << "Shift Supervisor Details:\n\n";
    cout << left << setw(20) << "Name" 
         << setw(12) << "ID Number" 
         << setw(20) << "Department" 
         << setw(20) << "Position" 
         << setw(16) << "Annual Salary" 
         << "Annual Bonus" << "\n";
    cout << string(98, '-') << "\n";

    cout << fixed << setprecision(2);
    for (const ShiftSupervisor& s : supervisors) {
        cout << left << setw(20) << s.getName()
             << setw(12) << s.getIdNumber()
             << setw(20) << s.getDepartment()
             << setw(20) << s.getPosition();
        cout << '$' << setw(15) << s.getAnnualSalary();
        cout << '$' << s.getAnnualBonus() << "\n";
    }

    return 0;
}