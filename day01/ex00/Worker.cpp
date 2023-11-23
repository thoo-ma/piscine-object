#include <algorithm>

#include "Worker.hpp"
#include "Tools.hpp"
#include "Workshop.hpp"

Position::Position() {
    x = y = z = 0;
}

Statistic::Statistic() {
    level = exp = 0;
}

Worker::Worker(): _tool(NULL) {
}

void Worker::getTool(Tool * tool) {
    if (!tool)
        return;
    if (tool->user) {
        if (tool->user == this) {
            std::cout << "Worker " << this << " already has that tool" << std::endl;
            return;
        }
        tool->user->removeTool();
    }
    _tool = tool;
    tool->user = this;
    std::cout << "Worker " << this << " had a new tool" << std::endl;
}

void Worker::removeTool() {
    if (_tool) {
        _tool->user = NULL;
        _tool = NULL;
        std::cout << "Worker " << this << " removed his tool" << std::endl;
    }
}

void Worker::joinWorkshop(Workshop * workshop, std::string caller) {
    if (caller == "addWorker") {
        _workshops.push_back(workshop);
        std::cout << "Added worker " << this << " to workshop " << workshop << std::endl;
    }
    else if (!workshop)
        return;
    else if (!_tool)
        std::cout << "Worker " << this << " cannot join workshop " << workshop << ": has no tool" << std::endl;
    else if (std::find(_workshops.begin(), _workshops.end(), workshop) != _workshops.end())
        std::cout << "Worker " << this << " already in workshop " << workshop << std::endl;
    else {
        _workshops.push_back(workshop);
        workshop->addWorker(this);
    }
}

void Worker::work() {
    if (!_tool)
        std::cout << "Worker " << this << " cannot work: has no tool" << std::endl;
    else if (!_workshops.size())
        std::cout << "Worker " << this << " cannot work: not in any workshop" << std::endl;
    else {
        std::cout << "worker " << this << ":" << std::endl;
        _tool->use();
    }
}

bool Worker::hasTool() {
    return _tool ? true : false;
}
