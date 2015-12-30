//Интерфейс для классов поиска пересечений
#ifndef __LineIntersection__IntersectionFinder__
#define __LineIntersection__IntersectionFinder__

#include <stdio.h>

class IntersectionFinder
{
public:
    virtual ~IntersectionFinder();
    virtual bool find() = 0;
};

#endif /* defined(__LineIntersection__IntersectionFinder__) */
