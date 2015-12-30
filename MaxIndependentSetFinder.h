//Поиск максимальной мощности

#ifndef __LineIntersection__MaxIndependentSetFinder__
#define __LineIntersection__MaxIndependentSetFinder__

#include <stdio.h>
#include "Graph.h"
using namespace std;
class MaxIndependentSetFinder
{
private:
public:
    virtual ~MaxIndependentSetFinder();
    virtual vector<GraphNode *> find() = 0;
};
#endif /* defined(__LineIntersection__MaxIndependentSetFinder__) */
