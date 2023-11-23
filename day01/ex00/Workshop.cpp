#include <algorithm>

#include "Workshop.hpp"
#include "Worker.hpp"

void Workshop::addWorker(Worker * worker, std::string caller) {
    if (caller == "joinWorkshop") {
        std::cout << "Added worker " << worker << " to workshop " << this << std::endl;
        _workers.push_back(worker);
    }
    else if (!worker)
        return;
    else if (!worker->hasTool())
        std::cout << "Worker " << worker << " cannot join workshop " << this << ": has no tool" << std::endl;
    else if (std::find(_workers.begin(), _workers.end(), worker) != _workers.end())
        std::cout << "Worker " << worker << " already in workshop " << this << std::endl;
    else {
        _workers.push_back(worker);
        worker->joinWorkshop(this);
    }
}

void Workshop::removeWorker(Worker * worker) {
    if (!worker)
        return;
    std::vector<Worker *>::iterator it = std::find(_workers.begin(), _workers.end(), worker);
    if (it != _workers.end()) {
        _workers.erase(it);
        std::cout << "Released worker " << worker << " from workshop " << this << std::endl;
    } else {
        std::cout << "Worker " << worker << " not in workshop " << this << std::endl;
    }
}

void Workshop::executeWorkDay() {
    std::cout << "Workday at workshop " << this << std::endl;
    for (std::vector<Worker *>::iterator it = _workers.begin(); it != _workers.end(); it++)
        (*it)->work();
}
