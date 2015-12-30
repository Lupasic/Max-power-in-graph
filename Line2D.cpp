#include "Line2D.h"

Line2D::Line2D(int i, Point2D *_p1, Point2D *_p2)
{
    this->index = i;
    this->p1 = _p1;
    this->p2 = _p2;
}
Line2D::~Line2D()
{
    p1 = NULL;
    p2 = NULL;
}

Point2D *Line2D::getOriginPoint()
{
    return this->p1;
}

Point2D *Line2D::getFinalPoint()
{
    return this->p2;
}
int Line2D::getIndex()
{
    return this->index;
}
