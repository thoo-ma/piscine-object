#ifndef PACKAGE_REDUCTION_DISCOUNT_HPP
#define PACKAGE_REDUCTION_DISCOUNT_HPP

#include "command.hpp"

class PackageReductionDiscountCommand: public Command {

    public:

    int get_total_price() {
        int total_price = Command::get_total_price();
        if (total_price > 150)
            total_price -= 10;
        return total_price;
    }

};

#endif // PACKAGE_REDUCTION_DISCOUNT_HPP