#include <iostream>
#include "command.hpp"
#include "tuesdayDiscount.hpp"
#include "packageReductionDiscount.hpp"

void log(Command c, TuesdayDiscountCommand tdc, PackageReductionDiscountCommand prdc) {
    std::cout << "Total price for Command: " << c.get_total_price() << std::endl;
    std::cout << "Total price for TuesdayDiscountCommand: " << tdc.get_total_price() << std::endl;
    std::cout << "Total price for PackageReductionDiscountCommand: " << prdc.get_total_price() << std::endl;
}

int main() {

    {
        std::cout << "== command on a Tuesday (below 150) ==" << std::endl;
        Article article; article.price = 100;
        Command c; c.articles.push_back(article);
        TuesdayDiscountCommand tdc; tdc.articles.push_back(article);
        PackageReductionDiscountCommand prdc; prdc.articles.push_back(article);
        prdc.date.day = tdc.date.day = c.date.day = Tuesday;
        log(c, tdc, prdc);
    }

    {
        std::cout << "== command on a Tuesday (above 150) ==" << std::endl;
        Article article; article.price = 160;
        Command c; c.articles.push_back(article);
        TuesdayDiscountCommand tdc; tdc.articles.push_back(article);
        PackageReductionDiscountCommand prdc; prdc.articles.push_back(article);
        prdc.date.day = tdc.date.day = c.date.day = Tuesday;
        log(c, tdc, prdc);
    }

    {
        std::cout << "== command on a Wednesday (below 150) ==" << std::endl;
        Article article; article.price = 100;
        Command c; c.articles.push_back(article);
        TuesdayDiscountCommand tdc; tdc.articles.push_back(article);
        PackageReductionDiscountCommand prdc; prdc.articles.push_back(article);
        prdc.date.day = tdc.date.day = c.date.day = Wednesday;
        log(c, tdc, prdc);
    }

    {
        std::cout << "== command on a Wednesday (above 150) ==" << std::endl;
        Article article; article.price = 160;
        Command c; c.articles.push_back(article);
        TuesdayDiscountCommand tdc; tdc.articles.push_back(article);
        PackageReductionDiscountCommand prdc; prdc.articles.push_back(article);
        prdc.date.day = tdc.date.day = c.date.day = Wednesday;
        log(c, tdc, prdc);
    }

    return 0;
}