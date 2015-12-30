#include <iostream>
#include "Point2D.h"

Point2D::Point2D()
{
    this->x  = 0;
    this->y = 0;
}

Point2D::Point2D(double _x, double _y)
{
    this->x  = _x;
    this->y = _y;
}

void Point2D::print()
{
    std::cout << '(' << this->x << ';' << this->y << ")";
}
