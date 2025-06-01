#include <iostream>
#include <string>
#include <stdexcept>

module;
//module database;
import database;




using namespace std;

namespace Records
{
    // This function adds an employee to the database
    Employee& Database::addEmployee(const string& firstName, const string& lastName)
    {
        // Create a new employee object with the given first and last name
        Employee theEmployee {firstName, lastName};
        // Set the employee number to the next available number
        theEmployee.setEployeeNumber(m_nextEmployeeNumber++);
        // Hire the employee
        theEmployee.hire();
        // Add the employee to the list of employees
        m_employees.push_back(theEmployee);
        // Return a reference to the newly added employee
        return m_employees.back();
    }


    // This function returns an Employee object from the m_employees vector based on the employeeNumber parameter
    Employee& Database::getEmployee (int employeeNumber)
    {
        // Iterate through the m_employees vector
        for (auto& employee : m_employees)
        {
            // If the employeeNumber of the current employee matches the parameter, return the employee
            if (employee.getEmployeeNumber() == employeeNumber)
            {
                return employee;
            }
        }
        // If no employee is found, throw a logic_error exception
        throw logic_error("No Employee found");
    }

    void Database::displayAll() const
    {
        for (const auto& employee : m_employees) {employee.display();}
    }

    // This function displays the current employees in the database
    void Database::displayCurrent() const
    {
        // Loop through the employees in the database
        for (const auto& employee : m_employees)
        {
            // If the employee is hired, display their information
            if (employee.isHired()) { employee.display();}
        }
    }

    // This function displays all former employees in the database
    void Database::displayFormer() const
    {
        // Iterate through all employees in the database
        for (const auto& employee : m_employees)
        {
            if (!employee.isHired()) {employee.display();}
        }
    }
}