//import database;
// import <string>;
// import <iostream>;
#include <iostream>
#include <string>
#include <array>
import employee;

using namespace std;

    void Print (const HR::Employee& new_employee)
    {
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
    }

int main()
{

    std::array<HR::Employee, 3> employees;

    employees[0] = HR::Employee{
        .firstname = 'J',  // Single character literal for char field
        .lastname = 'D',   // Single character literal for char field
        .employeeNumber = 1,
        .salary = 50000,
        .empRang = HR::title::Manager
    };


    employees[1] = HR::Employee{
        .firstname = 'A',  // Single character literal for char field
        .lastname = 'B',   // Single character literal for char field
        .employeeNumber = 2,
        .salary = 60000,
        .empRang = HR::title::Senior
    };

    employees[2] = HR::Employee{
        .firstname = 'C',  // Single character literal for char field
        .lastname = 'E',   // Single character literal for char field
        .employeeNumber = 3,
        .salary = 70000,
        .empRang = HR::title::Junior
    };
   



    for (const auto& emp : employees) {
        Print(emp);
        cout << "-----------------------------\n";
    }
    return 0;
}