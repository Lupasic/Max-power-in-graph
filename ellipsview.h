//Виджет Постройки эллипсов

#ifndef ELLIPSVIEW_H
#define ELLIPSVIEW_H
#include <QBrush>
#include <QPen>
#include <QWidget>
#include <QtGui>
#include <QVector>
#include <QPoint>
#include "Ellips.h"
#include <iostream>
#include "GraphNode.h"


class EllipsView : public QWidget
{
    Q_OBJECT
public:
    explicit EllipsView(QWidget *parent = 0);
    void paintellips(QPainter *painter);
    void colorellips(QPainter *painter);
    void paintcolgraph(QPainter *painter);
    std::vector<Ellips> lp; //хранит все эллипсы нарисованные в виджете
    void clearall();
    void setRow(int p){this->row = p;}

signals:
     void sgFromEllips(Ellips data); //Передача нарисованного эллипса в таблицу
     void delfromEllips(int index);
     void sendrow(int row);


public slots:
    void slotB(Ellips *data) {
        lp.push_back(*data);
        update();
       }
    void EllipsLook(int row)
    {
        this->row =row;
        update();
    }
    void slotRaskras(std::vector<GraphNode *> p)
    {
        max_independentEl = p;
        update();
    }

protected:
    void paintEvent(QPaintEvent *event);
   void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);

private:
  int row= -1;
    QVector<QPointF>  m_points;
    std::vector<GraphNode *> max_independentEl;
};
#endif // ELLIPSVIEW_H
