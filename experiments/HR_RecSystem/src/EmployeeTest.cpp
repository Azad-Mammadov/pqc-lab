#include <iostream>
import employee;

using namespace std;
// using namespace HR;
// using namespace Records;


int main()
{
    cout << "Testing the Employee class." << endl;
    
    // Create a new employee
    // Employee emp("John", "Doe");
    // emp.setEmployeeNumber(1);
    // emp.hire();
    
    // // Test the employee
    // emp.display();
    // emp.promote();
    // emp.display();

    HR::Employee new_employee 
    {
        .firstname = 'J',
        .lastname = 'D',
        .employeeNumber = 1,
        .salary = 50000
    }

    cout << "Employee Name: " << new_employee.firstname << " " << new_employee.lastname << "\n";
    cout << "Employee Number: " << new_employee.employeeNumber << "\n";
    cout << "Salary: " << new_employee.salary << endl;
    
    return 0;
}

