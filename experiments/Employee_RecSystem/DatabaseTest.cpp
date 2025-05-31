import database;
#include <iostream>
#include <string>

using namespace std;
using namespace Records;

int main()
{
    Database myDB;
    Employee& emp1 {myDB.addEmployee("Greg", "Wallis")};
    emp1.fire();

    Emplotee& emp2 {myDB.addEmployee("Marc", "White")};
    emp2.setSalary(100000);

    Employee& emp3 {myDB.addEmployee("John", "Doe")};
    emp3.setSalary(10000);
    emp3.promote();

    std::cout << "All Employees:\n===================";
    myDB.displayAll();

    std::cout << "\nCurrent Employees:\n===================";
    myDB.displayCurrent();

    std::cout << "\nFormer Employees:\n===================";
    myDB.displayFormer();
    return 0;
}