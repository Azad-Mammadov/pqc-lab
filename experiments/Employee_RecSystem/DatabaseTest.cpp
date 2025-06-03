// #include <iostream>
// #include <string>
// #include <stdexcept>
import database;


using namespace std;
using namespace Records;

int main()
{
    try {
        // Create a Database object
        Database myDB;

        // Add employees with error checking
        Employee& emp1 = myDB.addEmployee("Greg", "Wallis");
        if (!emp1.getEmployeeNumber()) {
            throw runtime_error("Failed to add employee Greg Wallis");
        }
        emp1.fire();

        Employee& emp2 = myDB.addEmployee("Marc", "White");
        if (!emp2.getEmployeeNumber()) {
            throw runtime_error("Failed to add employee Marc White");
        }
        emp2.setSalary(100000);

        Employee& emp3 = myDB.addEmployee("John", "Doe");
        if (!emp3.getEmployeeNumber()) {
            throw runtime_error("Failed to add employee John Doe");
        }
        emp3.setSalary(10000);
        emp3.promote();

        // Display all employees with headers
        cout << "\nAll Employees:" << endl;
        cout << "===================" << endl;
        myDB.displayAll();

        cout << "\nCurrent Employees:" << endl;
        cout << "===================" << endl;
        myDB.displayCurrent();

        cout << "\nFormer Employees:" << endl;
        cout << "===================" << endl;
        myDB.displayFormer();

        return 0;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}