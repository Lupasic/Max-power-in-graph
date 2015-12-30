#include "graphview.h"
#include <QPainter>
#define RANGE_SETKA 50


GraphView::GraphView(QWidget *parent) : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

}


void GraphView::paintgraph(QPainter *painter)
{
    QString strr;
     painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
     for(unsigned int z=0; z<graph_nodesGra.size(); z++)
     {
  painter->drawText(graph_points[z],strr.number(z+1));
  painter->drawPoint(graph_points[z]);
  for(unsigned int p=0;p< graph_nodesGra[z]->link_points.size(); p++)
  {
  painter->drawLine(graph_points[z],graph_points[(graph_nodesGra[z]->link_points[p])-1]);
  }

     }
      painter->setPen(QPen(Qt::red, 10, Qt::SolidLine, Qt::RoundCap));
     for(unsigned int z=0; z< max_independentGra.size(); z++)
        painter->drawPoint(graph_points[max_independentGra[z]->getIndex()-1]);

     update();
}


void GraphView::paintEvent(QPaintEvent * /* event */)
{

    QPainter painter(this);


paintgraph(&painter);

}
