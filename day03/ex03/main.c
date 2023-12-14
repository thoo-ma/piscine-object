#include "employee.hpp"
#include "employeeManager.hpp"

int main() {

    EmployeeManager manager;

    TempWorker worker(10);
    ContractEmployee employee(12);
    Apprentice apprentice(8);

    manager.addEmployee(&worker);
    manager.addEmployee(&employee);
    manager.addEmployee(&apprentice);

    for (int i = 0; i < 50; i++)
        manager.executeWorkday();
    manager.calculatePayroll();

    return 0;
}