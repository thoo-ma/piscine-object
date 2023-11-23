#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP

#include <vector>
#include <iostream>

class Worker;

class Workshop {

    private:

    std::vector<Worker *> _workers;

    public:

    void addWorker(Worker * worker, std::string caller = __builtin_FUNCTION());
    void removeWorker(Worker * worker);
    void executeWorkDay();
};

#endif /* WORKSHOP_HPP */