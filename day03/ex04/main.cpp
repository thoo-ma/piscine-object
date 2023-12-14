#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>

#include "ILogger.hpp"

int main() {

    std::ofstream file("log.txt", std::ios::app);

    {
        // without header
        std::vector<ILogger *> loggers;
        Logger logger1(std::cout);
        Logger logger2(std::clog);
        Logger logger3(std::cerr);
        Logger logger4(file);
        loggers.push_back(&logger1);
        loggers.push_back(&logger2);
        loggers.push_back(&logger3);
        loggers.push_back(&logger4);
        for (std::vector<ILogger *>::iterator it = loggers.begin(); it != loggers.end(); it++)
            (*it)->write("this is a test");
    }

    {
        // with string header
        std::vector<ILogger *> loggers;
        std::string s = "header";
        Logger logger1(std::cout, s);
        Logger logger2(std::clog, s);
        Logger logger3(std::cerr, s);
        Logger logger4(file, s);
        loggers.push_back(&logger1);
        loggers.push_back(&logger2);
        loggers.push_back(&logger3);
        loggers.push_back(&logger4);
        for (std::vector<ILogger *>::iterator it = loggers.begin(); it != loggers.end(); it++)
            (*it)->write("this is a test");
    }

    {
        // with time header
        std::vector<ILogger *> loggers;
        time_t tmm = time(0);
        char* dt = ctime(&tmm);
        Logger logger1(std::cout, dt);
        Logger logger2(std::clog, dt);
        Logger logger3(std::cerr, dt);
        Logger logger4(file, dt);
        loggers.push_back(&logger1);
        loggers.push_back(&logger2);
        loggers.push_back(&logger3);
        loggers.push_back(&logger4);
        for (std::vector<ILogger *>::iterator it = loggers.begin(); it != loggers.end(); it++)
            (*it)->write("this is a test");
    }

    return 0;
}