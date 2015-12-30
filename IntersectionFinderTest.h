//проверка правильности алгоритма пересечения отрезков

#ifndef __LineIntersection__IntersectionFinderTest__
#define __LineIntersection__IntersectionFinderTest__

#include <stdio.h>
#include "GeometryPrimitives.h"
#include <string>
using namespace std;
class IntersectionFinderTest
{
private:
    Point2D *p10;
    Point2D *p11;
    Point2D *p20;
    Point2D *p21;
    bool expectation;
    string tag;
public:
    IntersectionFinderTest(string, bool, Point2D *, Point2D *, Point2D *, Point2D *);
    ~IntersectionFinderTest();
    void test();

};

#endif /* defined(__LineIntersection__IntersectionFinderTest__) */
