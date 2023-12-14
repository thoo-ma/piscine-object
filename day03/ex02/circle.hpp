#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#define _USE_MATH_DEFINES
#include <cmath>
#include "shape.hpp"

class Circle: Shape {

    private:

    float _radius;

    public:

    Circle(float radius): _radius(radius) {}

    float area() {
        return _radius * _radius * M_PI;
    }

    float perimeter() {
        return 2 * _radius * M_PI;
    }

};

#endif // CIRCLE_HPP