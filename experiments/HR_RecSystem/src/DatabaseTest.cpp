//import database;
// import <string>;
// import <iostream>;
#include <iostream>
#include <string>
#include <vector>
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

    std::vector<HR::Employee> employees;

    HR::Employee employee_0{
        .firstname = 'J',  // Single character literal for char field
        .lastname = 'D',   // Single character literal for char field
        .employeeNumber = 1,
        .salary = 50000,
        .empRang = HR::title::Manager
    };
    employees.push_back(employee_0);


    HR::Employee employee_1{
        .firstname = 'A',  // Single character literal for char field
        .lastname = 'B',   // Single character literal for char field
        .employeeNumber = 2,
        .salary = 60000,
        .empRang = HR::title::Senior
    };
    employees.push_back(employee_1);

    HR::Employee employee_2{
        .firstname = 'C',  // Single character literal for char field
        .lastname = 'E',   // Single character literal for char field
        .employeeNumber = 3,
        .salary = 70000,
        .empRang = HR::title::Junior
    };
    employees.push_back(employee_2);

    for (const auto& emp : employees) {
        Print(emp);
        cout << "-----------------------------\n";
    }
    return 0;
}