#include <iostream>
#include "circle.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"

int main() {

    Circle c(10);
    std::cout << "Circle area: " << c.area() << std::endl;
    std::cout << "Circle perimeter: " << c.perimeter() << std::endl;

    Triangle t(4, 8, 10);
    std::cout << "Triangle area: " << t.area() << std::endl;
    std::cout << "Triangle perimeter: " << t.perimeter() << std::endl;

    Rectangle r(10.5, 2.5);
    std::cout << "Rectangle area: " << r.area() << std::endl;
    std::cout << "Rectangle perimeter: " << r.perimeter() << std::endl;

}