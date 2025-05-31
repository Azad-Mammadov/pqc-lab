import database;
#include <iostream>
#include <string>

using namespace std;
using namespace Records;

int main()
{
    // Create a Database object
    Database myDB;
    // Add an employee to the database and assign a reference to emp1
    Employee& emp1 {myDB.addEmployee("Greg", "Wallis")};
    // Fire the employee
    emp1.fire();

    // Add an employee to the database and assign a reference to emp2
    Emplotee& emp2 {myDB.addEmployee("Marc", "White")};
    // Set the salary of the employee
    emp2.setSalary(100000);

    // Add an employee to the database and assign a reference to emp3
    Employee& emp3 {myDB.addEmployee("John", "Doe")};
    // Set the salary of the employee
    emp3.setSalary(10000);
    // Promote the employee
    emp3.promote();

    // Display all employees in the database
    std::cout << "All Employees:\n===================";
    myDB.displayAll();

    // Display current employees in the database
    std::cout << "\nCurrent Employees:\n===================";
    myDB.displayCurrent();

    // Display former employees in the database
    std::cout << "\nFormer Employees:\n===================";
    myDB.displayFormer();
    return 0;
}