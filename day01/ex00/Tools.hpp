#ifndef TOOL_HPP
#define TOOL_HPP

#include <iostream>

class Worker;

struct Tool {
    unsigned int numberOfUses;
    Worker * user;
    virtual void use() = 0;
    Tool();
};

struct Shovel: Tool {
    void use();
};

struct Hammer: Tool {
    void use();
};

#endif /* TOOL_HPP */