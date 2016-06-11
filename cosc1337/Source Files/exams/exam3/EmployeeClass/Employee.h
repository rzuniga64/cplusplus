#include <iostream>

using namespace std;

class Employee {
public:
    Employee(string name);
    string getName() const;
    virtual void display(ostream & out = cout) const;
    virtual void readWageInfo() {};
    virtual double weeklyWages() {return 0;};
protected:
    string name;
};

ostream & operator<<(ostream & out, const Employee & e);

class SalariedEmployee : public Employee {
public:
    SalariedEmployee(string name);
    void display(ostream & out = cout) const;
    void readWageInfo();
    double weeklyWages();
protected:
    double annualSalary;
};

class HourlyEmployee : public Employee {
public:
    HourlyEmployee(string name);
    void display(ostream & out = cout) const;
    void readWageInfo();
    double weeklyWages();
protected:
    double hourlyRate;
    int hoursPerWeek;
};
