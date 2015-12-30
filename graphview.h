// Виджет постройки графа

#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H
#define offsetX 50
#define offsetY 50

#include <QBrush>
#include <QPen>
#include <QWidget>
#include <QtGui>
#include <QVector>
#include <QPoint>
#include "reshenie.h"



class GraphView : public QWidget
{
    Q_OBJECT
public:
    explicit GraphView(QWidget *parent = 0);
    void paintgraph(QPainter *painter);

protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:
    void slotB(vector<GraphNode *> p,vector<GraphNode *> m) {
        srand(time(0));
        QPoint point;
        graph_nodesGra = p;
        max_independentGra = m;
        for(unsigned int i=0; i< graph_nodesGra.size();i++)
        {


          point.setX(width()/(graph_nodesGra.size()+10) * i + std::rand()%(2*offsetX));
          point.setY(height()/(graph_nodesGra.size()+10) * i + std::rand()%(2*offsetY));
            graph_points.append(point);
        }
        update();
       }

    void SlotDelete()
            {
            graph_nodesGra.clear();
            graph_points.clear();
            max_independentGra.clear();
            update();
            }


private:
       vector<GraphNode *> graph_nodesGra;
       vector<GraphNode *> max_independentGra;
       QVector<QPoint>   graph_points;
};

#endif // GRAPHVIEW_H
