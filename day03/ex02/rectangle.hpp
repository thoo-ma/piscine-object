#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle: Shape {

    private:

    float _length, _width;

    public:

    Rectangle(float length, float width): _length(length), _width(width) {}

    float area() {
        return _width * _length;
    }

    float perimeter() {
        return (_width + _length) * 2;
    }

};


#endif // RECTANGLE_HPP