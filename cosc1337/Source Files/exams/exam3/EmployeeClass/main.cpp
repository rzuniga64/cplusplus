#include "Employee.h"
#include <vector>

int main() {
    string name;
    vector<Employee*> employees;
    char type;
    
    cout << "Enter employee's name (leave blank when done): ";
    getline(cin, name);
    
    while(name.length() > 0) {
        cout << "Enter employee type (h/s): ";
        cin >> type;
        cin.ignore();
        
        if (toupper(type) == 'S')
            employees.push_back(new SalariedEmployee(name));
        else if (toupper(type) == 'H')
            employees.push_back(new HourlyEmployee(name));
        else
            cout << "Invalid employee type." << endl;
        cout << "Enter employee's name (leave blank when done): ";
        getline(cin, name);
    }
    
    cout << endl << "Reading wage info for employees..." << endl;
    for (int i=0; i<employees.size(); i++) {
        employees[i]->readWageInfo();
    }
    
    cout << endl << "Displaying employees..." << endl;
    for (int i=0; i<employees.size(); i++) {
        cout << *employees[i];
		cout << ", weekly wages: $" << employees[i]->weeklyWages() << endl;
    }
    
    system("PAUSE");
    return 0;
}
