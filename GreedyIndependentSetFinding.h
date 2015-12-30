//Жадный алгоритм поиска независимого множества
#ifndef __LineIntersection__GreedyIndependentSetFinding__
#define __LineIntersection__GreedyIndependentSetFinding__

#include <stdio.h>
#include "MaxIndependentSetFinder.h"
class GreedyIndependentSetFinding : public MaxIndependentSetFinder
{
public:
    GreedyIndependentSetFinding();
    ~GreedyIndependentSetFinding();
    virtual vector<GraphNode *> find();
private:
    vector<GraphNode *> findSetRecursively(vector<GraphNode *>);
};
#endif /* defined(__LineIntersection__GreedyIndependentSetFinding__) */
