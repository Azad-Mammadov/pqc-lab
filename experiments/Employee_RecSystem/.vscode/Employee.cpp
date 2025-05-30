
module employee;
#include <string>
#include <iostream>

using namespace std;

namespace Records
{
    Employee::Employee(const std::string& firstName, const std::string& lastName)
        : m_firstName(firstName), m_lastName(lastName) {}
{
}

    void Employee::promote(int raiseAmount)
    {
        setSalary(getSalary() + raiseAmount);
    }


    
}
