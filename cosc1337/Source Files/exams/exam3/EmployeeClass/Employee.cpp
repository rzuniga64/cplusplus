#include "Employee.h"

Employee::Employee(string name) {
    this->name = name;
}

string Employee::getName() const {
    return name;
}

void Employee::display(ostream & out) const {
    out << name;
}

ostream & operator<<(ostream & out, const Employee & e) {
    e.display(out);
    return out;
}

SalariedEmployee::SalariedEmployee(string name) : Employee(name) {
}

void SalariedEmployee::display(ostream & out) const {
    Employee::display();
    cout << ", annual salary: " << annualSalary;
}

void SalariedEmployee::readWageInfo() {
    cout << "Enter annual salary for " << name << ": $";
    cin >> annualSalary;
}

double SalariedEmployee::weeklyWages() {
    return annualSalary / 52;
}

HourlyEmployee::HourlyEmployee(string name) : Employee(name) {
}

void HourlyEmployee::display(ostream & out) const {
    Employee::display();
    cout << ", hourly rate: $" << hourlyRate << ", hours per week: " << hoursPerWeek;
}

void HourlyEmployee::readWageInfo() {
    cout << "Enter the hourly rate for " << name << ": $";
    cin >> hourlyRate;
    cout << "Enter the number of hours worked per week: ";
    cin >> hoursPerWeek;
}

double HourlyEmployee::weeklyWages() {
    return hourlyRate * hoursPerWeek;
}
