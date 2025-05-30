
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


    void Employee::demote(int demeritAmount)
    {
        setSalary(getSalary() - demeritAmount);
    }

    void Employee::hire() {m_hired = true; }
    void Employee::fire() {m_hired = false; }

    void Employee::display() const
    {
        println("Employee: {}, {}", getLastName(), getFirstName());
        println("-----------------------------");
        println("{}",isHired() ? "Current Employee" : "FormerEmployee");
        println("Employee Number: {}", getEmployeeNumber());
        println("Salary: ${}", getSalary());
        println("");
    }

    void Employee::setFirstName(const string& firstName) {m_}


}
