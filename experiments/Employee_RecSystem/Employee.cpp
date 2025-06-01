#include <iostream>
#include <string>
module;
//module employee;
import employee;





using namespace std;

namespace Records
{
    Employee::Employee(const std::string& firstName, const std::string& lastName)
        : m_firstName(firstName), m_lastName(lastName) {}

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
        cout << "Employee: " << getLastName() << ", " << getFirstName() << endl;
        cout << "-----------------------------" << endl;
        cout << (isHired() ? "Current Employee" : "Former Employee") << endl;
        cout << "Employee Number: " << getEmployeeNumber() << endl;
        cout << "Salary: $" << getSalary() << endl;
        cout << endl;
    }

    void Employee::setFirstName(const string& firstName) {m_firstName = firstName; }
    const string& Employee::getFirstName() const { return m_firstName; }

    // Set the last name of the employee
    void Employee::setLastName(const string& lastName) {m_lastName = lastName; }
    const string& Employee::getLastName() const { return m_lastName; }

    void Employee::setEmployeeNumber(int newEmployeeNumber) {m_employeeNumber = newEmployeeNumber; }
    int Employee::getEmployeeNumber() const { return m_employeeNumber; }

    void Employee::setSalary(int salary) {m_salary = salary;}
    int Employee::getSalary() const { return m_salary; }

    bool Employee::isHired() const { return m_hired;}

}
