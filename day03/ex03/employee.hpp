#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>

class Employee {

    public:

    int hourlyValue;
    int officeHours;
    int hoursPerDay;

    Employee(int val): hourlyValue(val), officeHours(0), hoursPerDay(7) {}

    virtual void executeWorkday() = 0;
};

class TempWorker: public Employee {

    public:

    TempWorker(int hourlyValue): Employee(hourlyValue) {}

    void executeWorkday() {
        officeHours += hoursPerDay;
        std::cout << "Office day for TempWorker " << this << std::endl;
    }
};

class ContractEmployee: public Employee {

    public:

    bool offWork;
    int hoursOff;
    int consecutiveOfficeHours;
    int consecutiveOffHours;

    ContractEmployee(int hourlyValue): Employee(hourlyValue), offWork(false), hoursOff(0),
        consecutiveOfficeHours(280), consecutiveOffHours(35) {}

    /// @note one week off every two months
    /// (assuming four weeks months)
    void executeWorkday() {
        if (offWork == true) {
            hoursOff += hoursPerDay;
            std::cout << "Day off for ContractEmployee " << this << std::endl;
            if (hoursOff % consecutiveOffHours == 0)
                offWork = false;
        } else {
            officeHours += hoursPerDay;
            std::cout << "Office day for ContractEmployee " << this << std::endl;
            if (officeHours % consecutiveOfficeHours == 0)
                offWork = true;
        }
    }

};

class Apprentice: public Employee {

    public:

    bool atSchool;
    int schoolHours;
    int consecutiveSchoolHours;
    int consecutiveOfficeHours;

    Apprentice(int hourlyValue): Employee(hourlyValue), atSchool(false), schoolHours(0),
        consecutiveSchoolHours(35), consecutiveOfficeHours(105) {}

    /// @note 3 weeks at the office / 1 week at school
    void executeWorkday() {
        if (atSchool == false) {
            officeHours += hoursPerDay;
            std::cout << "School day for Apprentice " << this << std::endl;
            if (officeHours % consecutiveOfficeHours == 0)
                atSchool = true;
        } else {
            schoolHours += hoursPerDay;
            std::cout << "Office day for Apprentice " << this << std::endl;
            if (officeHours % consecutiveSchoolHours == 0)
                atSchool = false;
        }
    }

};

#endif // EMPLOYEE_HPP