#ifndef EMPLOYEE_MANAGER_HPP
#define EMPLOYEE_MANAGER_HPP

#include <set>
#include <iostream>
#include "employee.hpp"

class EmployeeManager {

    private:

    std::set<Employee *> _employees;

    public:

    void addEmployee(Employee * employee) {
        _employees.insert(employee);
    }

    void removeEmployee(Employee * employee) {
        _employees.erase(employee);
    }

    void executeWorkday() {
        for (std::set<Employee *>::iterator it = _employees.begin(); it != _employees.end(); it++)
            (*it)->executeWorkday();
    }

    void calculatePayroll() {
        for (std::set<Employee *>::iterator it = _employees.begin(); it != _employees.end(); it++) {
            int daysOfWork = (*it)->officeHours / (*it)->hoursPerDay;
            int totalPayroll = (*it)->hourlyValue * (*it)->officeHours;
            std::cout << "Employee " << *it << ": " << totalPayroll << " (" << daysOfWork << " days of work at " << (*it)->hourlyValue << "$ per hour)" << std::endl;
        }
    }

};

#endif // EMPLOYEE_MANAGER_HPP