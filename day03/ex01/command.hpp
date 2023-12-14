#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <vector>

enum Day {
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

struct Date {
    Day day;
};

class Client {};

class Article {
    public:
    int price;
};

class Command {

    public:

    int id;
    Date date;
    Client client;
    std::vector<Article> articles;

    int get_total_price() {
        int total_price = 0;
        for (std::vector<Article>::iterator it = articles.begin(); it != articles.end(); it++)
            total_price += it->price;
        return total_price;
    }

};

#endif // COMMAND_HPP