#include "GraphNode.h"
#include <algorithm>
GraphNode::GraphNode(int i)
{
    this->index = i;
}
GraphNode::~GraphNode()
{
    linked.clear();
}
int GraphNode::getIndex() { return this->index; }
void GraphNode::insertLink(GraphNode *n)
{
    linked.push_back(n);
}
vector<GraphNode *> GraphNode::getLinkedNodes()
{
    return this->linked;
}

bool GraphNode::isLinkedWith(int i)
{
    if(i == getIndex())
        return true;
    return (find_if(linked.begin(), linked.end(), [i] (GraphNode *nd) { return nd->getIndex() == i; }) != linked.end());
}

