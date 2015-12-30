#ifndef RESHENIE_H
#define RESHENIE_H
#include "Ellips.h"
#include <iostream>
#include <vector>
#include <QVector>
#include <QPoint>
#include <QtGui>
#include <GraphNode.h>

class Reshenie

{

private:
    void printGraphInfo(std::vector<GraphNode *> gr);
    void GetText(std::vector<GraphNode *> gr);
public:
    vector<GraphNode *> graph_nodes;
    vector<GraphNode *> max_independent;
    void ClearGraph();
   QVector<QString> text;

    Reshenie();
    Reshenie(std::vector<Ellips> lines);

};


#endif // RESHENIE_H
