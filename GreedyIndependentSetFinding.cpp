#include "GreedyIndependentSetFinding.h"
#include <algorithm>
GreedyIndependentSetFinding::GreedyIndependentSetFinding() {}
GreedyIndependentSetFinding::~GreedyIndependentSetFinding() {}

vector<GraphNode *> GreedyIndependentSetFinding::find()
{
    vector<GraphNode *> result;

    vector<GraphNode *> startInput;     //для

    for(vector<GraphNode *>::iterator it = graph.begin(); it != graph.end(); ++it)
    {
        startInput.clear();
        startInput.push_back(*it);
        vector<GraphNode *> independentSet = findSetRecursively(startInput);
        if(independentSet.size() > result.size())
            result = independentSet;
    }
    return result;
}
vector<GraphNode *> GreedyIndependentSetFinding::findSetRecursively(vector<GraphNode *> initialSet)
{
    for(vector<GraphNode *>::iterator it = graph.begin(); it != graph.end(); ++it)
    {
        bool linked = false;
        for(vector<GraphNode *>::iterator it2 = initialSet.begin(); it2 != initialSet.end(); ++it2)
        {
            if((*it2)->isLinkedWith((*it)->getIndex()))
            {
               linked = true;
                break;
            }
        }
        if(linked)
            continue;
        vector<GraphNode *> newInitialSet(initialSet);
        newInitialSet.push_back(*it);
        return findSetRecursively(newInitialSet);
    }
    return initialSet;
}
