//Поиск пересечений интервалов (по оси X)
#ifndef __LineIntersection__IntervalIntersectionFinder__
#define __LineIntersection__IntervalIntersectionFinder__

#include "IntersectionFinder.h"
#include "GeometryPrimitives.h"
#include <vector>

using namespace std;
class IntervalIntersectionFinder : public IntersectionFinder
{
private:
    Line2D *l1;                                 //что сравнивать
    Line2D *l2;                                 //с чем сравнивать
public:
    IntervalIntersectionFinder(Line2D *, Line2D *);
    ~IntervalIntersectionFinder();
    virtual bool find();
};

#endif /* defined(__LineIntersection__IntervalIntersectionFinder__) */
