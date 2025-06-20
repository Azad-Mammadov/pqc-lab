//module;

export module employee;

import <string>;
import <iostream>;
import <vector>;
import <stdexcept>;

//import std;


namespace Records 
{
    const int DefaultStartingSalary {30000};
    export const int DefaultRaiseAndDemeritAmount {1000};

    export class Employee
    {

        public:
            Employee(const std::string& firstName,
                     const std::string& lastName);

            void promote(int raiseAmount = DefaultRaiseAndDemeritAmount);
            void demote(int demeritAmount = DefaultRaiseAndDemeritAmount);
            void hire();
            void fire();
            void display() const;
            
            // Getters and Setters
            void setFirstName(const std::string& firstName);
            const std::string& getFirstName() const;

            void setLastName(const std::string& lastName);
            const std::string& getLastName() const;

            void setEmployeeNumber(int mployeeNumber);
            int getEmployeeNumber() const;

            void setSalary(int newSalary);
            int getSalary() const;

            bool isHired() const;

        private:
            std::string m_firstName;
            std::string m_lastName;
            int m_employeeNumber{-1};
            int m_salary{DefaultStartingSalary};
            bool m_hired{false};
    };
} // namespace Records