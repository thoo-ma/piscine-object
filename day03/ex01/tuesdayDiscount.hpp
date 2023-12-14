#ifndef TUESDAY_DISCOUNT_HPP
#define TUESDAY_DISCOUNT_HPP

#include "command.hpp"

class TuesdayDiscountCommand: public Command {

    public:

    int get_total_price() {
        if (date.day == Tuesday)
            return Command::get_total_price() * 0.9;
        return Command::get_total_price();
    }

};

#endif // TUESDAY_DISCOUNT_HPP