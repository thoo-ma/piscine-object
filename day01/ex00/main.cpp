#include "Tools.hpp"
#include "Worker.hpp"
#include "Workshop.hpp"

/// @todo add exceptions
/// @todo stream operator << for each class
/// @todo utility of Positon and Statistic ??
/// @todo bonus

int main() {

    {
        std::cout << "== Get tool owned by another worker ==" << std::endl;
        Shovel shovel;
        Worker worker, worker_bis;
        worker.getTool(&shovel);
        worker_bis.getTool(&shovel);
        std::cout << std::endl;
    }

    {
        std::cout << "== Get twice the same tool instance ==" << std::endl;
        Shovel shovel;
        Worker worker;
        worker.getTool(&shovel);
        worker.getTool(&shovel);
        std::cout << std::endl;
    }

    {
        std::cout << "== Add worker to workshop with no tool ==" << std::endl;
        Worker worker;
        Workshop workshop;
        workshop.addWorker(&worker);
        std::cout << std::endl;
    }

    {
        std::cout << "== Add twice the worker to workshop ==" << std::endl;
        Shovel shovel;
        Worker worker;
        Workshop workshop;
        worker.getTool(&shovel);
        workshop.addWorker(&worker);
        workshop.addWorker(&worker);
        std::cout << std::endl;
    }

    {
        std::cout << "== NULL ==" << std::endl;
        Worker worker;
        worker.getTool(NULL);
        Workshop workshop;
        workshop.removeWorker(NULL);
        workshop.addWorker(NULL);
        workshop.removeWorker(NULL);
        std::cout << std::endl;
    }

    {
        std::cout << "== Work with no tool ==" << std::endl;
        Worker worker;
        worker.work();
        std::cout << std::endl;
    }

    {
        std::cout << "== Join workshop with no tool ==" << std::endl;
        Worker worker;
        Workshop workshop;
        workshop.addWorker(&worker);
        std::cout << std::endl;
    }

    {
        std::cout << "== Work outside of workshop ==" << std::endl;
        Shovel shovel;
        Worker worker;
        worker.getTool(&shovel);
        worker.work();
        std::cout << std::endl;
    }

    {
        std::cout << "== Change tool ==" << std::endl;
        Worker worker;
        Shovel shovel;
        Hammer hammer, hammer_bis;
        worker.getTool(&shovel);
        worker.getTool(&hammer);
        worker.getTool(&hammer_bis);
        std::cout << std::endl;
    }

    {
        std::cout << "== Register to multiple workshops ==" << std::endl;
        Worker worker;
        Shovel shovel;
        Workshop workshop, workshop_bis;
        worker.getTool(&shovel);
        worker.joinWorkshop(&workshop);
        worker.joinWorkshop(&workshop_bis);
        std::cout << std::endl;
    }

    {

        std::cout << "== Workday ==" << std::endl;
        Worker worker, worker_bis;
        Shovel shovel, shovel_bis;
        Workshop workshop;
        worker.getTool(&shovel);
        worker_bis.getTool(&shovel_bis);
        workshop.addWorker(&worker);
        workshop.addWorker(&worker_bis);
        workshop.executeWorkDay();
        std::cout << std::endl;
    }

    return 0;
}