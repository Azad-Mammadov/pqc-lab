//import database;
// import <string>;
// import <iostream>;
#include <iostream>
#include <string>
import employee;

using namespace std;

int main()
{
    HR::Employee new_employee{
        .firstname = 'J',  // Single character literal for char field
        .lastname = 'D',   // Single character literal for char field
        .employeeNumber = 1,
        .salary = 50000
    };

    cout << "Employee Name: " << new_employee.firstname << " " << new_employee.lastname << "\n";
    cout << "Employee Number: " << new_employee.employeeNumber << "\n";
    cout << "Salary: " << new_employee.salary << endl;

    return 0;
}