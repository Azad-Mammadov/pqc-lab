export module database;
#include <iostream>
#include <string>
#include <vector>

import employee;

namespace Records 
{
    const int FirstEmployeeNumber {1000};

    export class Database
    {
        public:
            // Adds an employee to the database
            Employee& addEmployee(const std::string& firstName, const std::string& lastName);

            // Gets an employee from the database by employee number
            Employee& getEmployee(int employeeNumber);
            // Gets an employee from the database by first and last name
            Employee& getEmployee(const std::string& firstName, const std::string& lastName);

            // Displays all employees in the database
            void displayAll() const;
            // Displays all current employees in the database
            void displayCurrent() const;
            // Displays all former employees in the database
            void displayFormer() const;

        private:
            // Stores all employees in the database
            std::vector<Employee> m_employees;
            // Stores the next employee number to be assigned
            int m_nextEmployeeNumber {FirstEmployeeNumber};     
    };
}