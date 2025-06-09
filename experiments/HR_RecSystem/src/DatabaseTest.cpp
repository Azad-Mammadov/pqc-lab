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
        .salary = 50000,
        .empRang = HR::title::Manager
    };

    cout << "Employee Name: " << new_employee.firstname << " " << new_employee.lastname << "\n";
    cout << "Employee Number: " << new_employee.employeeNumber << "\n";
    cout << "Salary: " << new_employee.salary << "\n";
        switch (new_employee.empRang)  // Using the enum class title
        {
            using enum HR::title;

        case Intern:
            cout << "Employee Rank: Intern\n";
            break;
        case Junior:
            cout << "Employee Rank: Junior\n";
            break;
        case Senior:
            cout << "Employee Rank: Senior\n";
            break;
        case Manager:
            cout << "Employee Rank: Manager\n";
            break;
        case Director:
            cout << "Employee Rank: Director\n";
            break;

        default:
            break;
        }

    return 0;
}