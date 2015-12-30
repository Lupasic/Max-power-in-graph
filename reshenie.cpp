#include "reshenie.h"
#include <algorithm>
#include "IntersectionFinderTest.h"
#include "IntervalIntersectionFinder.h"
#include "GeometryPrimitives.h"
#include "GraphNode.h"
#include "Graph.h"
#include "GreedyIndependentSetFinding.h"
#include "Poisk_peresech.h"
#include "Point2D.h"

int flag=0;

using namespace std;

GraphNode *findGraphNodeByIndex(int);
vector<GraphNode *> graph;

Reshenie::Reshenie()
{
}

Reshenie::Reshenie(vector<Ellips> lines)
{
    //создание графа
    for(std::vector<Ellips>::iterator it = lines.begin(); it != lines.end(); ++it)

    {
        GraphNode *nd = new GraphNode((*it).getIndex());
        graph.push_back(nd);
    }

    //Находим пересечения
    for(std::vector<Ellips >::iterator it = lines.begin(); it != lines.end(); ++it)
    {
        Ellips line = *it;
        GraphNode *firstNode = findGraphNodeByIndex(line.getIndex());
        for(std::vector<Ellips >::iterator it2(it+1); it2 != lines.end(); ++it2)
        {
            Ellips line2 = *it2;
            Poisk_peresech *f = new Poisk_peresech(&line, &line2);
            bool result =f->peresechenie();

            if(result == true)
            {
                GraphNode *secondNode = findGraphNodeByIndex(line2.getIndex());
                if(secondNode != NULL)
                {
                    firstNode->insertLink(secondNode);
                    secondNode->insertLink(firstNode);
                }
            }

            delete f;
        }

    }
    cout << "---GRAPH:---" << endl;
    text.append("<h3 align=\"center\">Список смежности графа:\n</h3>");

    this->printGraphInfo(graph);
    this->GetText(graph);

    flag=1;
    this->graph_nodes= this->max_independent;
    this->max_independent.clear();

    cout << "---END---" << endl;

    cout << "---MAX INDEPENDENT SET:---" << endl;
    text.append("<h3 align=\"center\">Максимально независимое множество:\n</h3>");
    MaxIndependentSetFinder *setFinder = new GreedyIndependentSetFinding();
    vector<GraphNode *> independentSet = setFinder->find();
    this->printGraphInfo(independentSet);
    this->GetText(independentSet);

    cout << "---END---";

}

GraphNode *findGraphNodeByIndex(int index)
{
    vector<GraphNode *>::iterator it = find_if(graph.begin(), graph.end(), [index] (GraphNode *nd) { return index == nd->getIndex();});
    if(it != graph.end())
        return *it;
    return NULL;
}

void Reshenie::printGraphInfo(vector<GraphNode *> gr)
{
    QString strr;
    for(vector<GraphNode *>::iterator it = gr.begin(); it != gr.end(); ++it)
    {
        GraphNode *nd1 = *it;
        cout << "Node " << nd1->getIndex() << ":" << endl;
        vector<GraphNode *> linked = nd1->getLinkedNodes();
        for(vector<GraphNode *>::iterator it2 = linked.begin(); it2 != linked.end(); ++it2)
        {
            GraphNode *nd2 = *it2;
            cout << "\t" << "\t" << nd2->getIndex() << endl;
            nd1->link_points.push_back(nd2->getIndex());
        }
        this->max_independent.push_back(nd1);
        cout << endl;
    }

}

void Reshenie::ClearGraph()
{
    graph.clear();
}


void Reshenie::GetText(vector<GraphNode *> gr)
{
    QString strr;
    for(vector<GraphNode *>::iterator it = gr.begin(); it != gr.end(); ++it)
    {
        GraphNode *nd1 = *it;
        strr = "<h4>Вершина " + strr.number(nd1->getIndex()) + " : </h4>";
        text.append(strr);


        vector<GraphNode *> linked = nd1->getLinkedNodes();
        for(vector<GraphNode *>::iterator it2 = linked.begin(); it2 != linked.end(); ++it2)
        {
            GraphNode *nd2 = *it2;
            strr=strr.number(nd2->getIndex());
            text.append(strr);

        }
    }
if(flag==1)
{
 strr = "<h3> Максимальная мощность: <p align=\"center\" style=\"color:#0000ff\" >" + strr.number(gr.size()) + "</p></h3>";
 text.append(strr);
 flag=0;
}
}
