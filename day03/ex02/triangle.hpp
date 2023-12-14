#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <cmath>
#include "shape.hpp"

class Triangle: Shape {

    private:

    float _a, _b, _c;

    public:

    Triangle(float a, float b, float c): _a(a), _b(b), _c(c) {}

    float area() {
        float half_sum = perimeter() / 2;
        return std::sqrt(half_sum * (half_sum - _a) * (half_sum - _b) * (half_sum - _c));
    }

    float perimeter() {
        return _a + _b + _c;
    }

};

#endif // TRIANGLE_HPP