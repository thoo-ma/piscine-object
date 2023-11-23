#ifndef WORKER_HPP
#define WORKER_HPP

#include <vector>
#include <iostream>

struct Tool;
class Workshop;

struct Position {
    int x , y, z;
    Position();
};

struct Statistic {
    int level, exp;
    Statistic();
};

class Worker {

    private:

    Tool * _tool;
    std::vector<Workshop *> _workshops;

    public:

    Worker();
    Position position;
    Statistic statistic;
    void getTool(Tool * tool);
    void removeTool();
    void joinWorkshop(Workshop * workshop, std::string caller = __builtin_FUNCTION());
    // void leaveWorkshop(Workshop * workshop);
    void work();
    bool hasTool();
};

#endif /* WORKER_HPP */