//модель вершины графа

#ifndef __LineIntersection__GraphNode__
#define __LineIntersection__GraphNode__

#include <stdio.h>
#include <vector>
using namespace std;

class GraphNode
{
private:
    int index;
    vector<GraphNode *> linked;             //список смежности

public:
    GraphNode(int);
    ~GraphNode();

    int getIndex();
    void insertLink(GraphNode *);           //вставка в список смежности ссылки на новую вершину
    vector<GraphNode *> getLinkedNodes();   //получение списка смежности
    vector<int> link_points;                // получение индексов смежности
    bool isLinkedWith(int);                 //смежна ли текущая вершина с переданной на вход?
};

#endif /* defined(__LineIntersection__GraphNode__) */
