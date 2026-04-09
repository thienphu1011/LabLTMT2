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
    ShiftSupervisor supervisor("Phu", 47899, "Manufacturing", "Shift Supervisor", 75000.0, 8500.0);

    cout << "Shift Supervisor Details:\n";
    cout << "Name: " << supervisor.getName() << "\n";
    cout << "ID Number: " << supervisor.getIdNumber() << "\n";
    cout << "Department: " << supervisor.getDepartment() << "\n";
    cout << "Position: " << supervisor.getPosition() << "\n";
    
    cout << fixed << setprecision(2);
    cout << "Annual Salary: $" << supervisor.getAnnualSalary() << "\n";
    cout << "Annual Bonus: $" << supervisor.getAnnualBonus() << "\n";

    return 0;
}