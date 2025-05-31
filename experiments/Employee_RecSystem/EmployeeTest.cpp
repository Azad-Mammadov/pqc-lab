#include <iostream>
import employee;

using namespace std;
using namespace Records;

int main()
{
    cout << "Testing the Employee class." << endl;
    
    // Create a new employee
    Employee emp("John", "Doe");
    emp.setEmployeeNumber(1);
    emp.hire();
    
    // Test the employee
    emp.display();
    emp.promote();
    emp.display();
    
    return 0;
}

