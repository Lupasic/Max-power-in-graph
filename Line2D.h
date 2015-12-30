//Линия

#ifndef __LineIntersection__line2d__
#define __LineIntersection__line2d__

#include <stdio.h>
#include "Point2D.h"
class Line2D
{
private:
    int index;      //индекс линии
    Point2D *p1;
    Point2D *p2;
public:
    Line2D(int, Point2D *, Point2D *);
    ~Line2D();
    Point2D *getOriginPoint();
    Point2D *getFinalPoint();
    int getIndex();
};

#endif /* defined(__LineIntersection__line2d__) */
