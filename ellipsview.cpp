#include "ellipsview.h"
#include <QPainter>
#include <cmath>

#define RANGE_SETKA 50
#define POGR 0.1
#define POGR_ELLIPS 1

int fl=0;

void EllipsView::clearall()
{
    max_independentEl.clear();
    m_points.clear();
    fl=0;
}

EllipsView::EllipsView(QWidget *parent) : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

void EllipsView::paintellips(QPainter *painter)   // рисуем эллипсы
{
    double x = (width()/ 2);
    double y = (height() / 2);
    unsigned int z;
    double X,Y,A,B;

    painter->setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
    if(!m_points.isEmpty())
        painter->drawEllipse(m_points[0],fabs(m_points.last().x()-m_points[0].x()),fabs(-m_points.last().y()+ m_points[0].y()));
    for(z=0; z<lp.size(); z++)
    {
        X=x+lp[z].getX()*RANGE_SETKA - lp[z].getA()*RANGE_SETKA;
        Y=y-lp[z].getY()*RANGE_SETKA - lp[z].getB()*RANGE_SETKA;
        A=lp[z].getA()*2*RANGE_SETKA;
        B=lp[z].getB()*2*RANGE_SETKA;
        painter->drawEllipse(X,Y,A,B);
        update();
    }

}

void EllipsView::paintEvent(QPaintEvent * /* event */)
{
    int i,j;
    QPainter painter(this);
    int x = (width()/ 2);
    int y = (height() / 2);
    // Зарисовка сетки и линии пересечения [1]
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::red, 4, Qt::SolidLine, Qt::RoundCap));
    painter.drawLine(x,0,x,height());
    painter.drawLine(0,y,width(),y);

    painter.setPen(QPen(Qt::blue, 1, Qt::SolidLine, Qt::RoundCap));
    for(i=RANGE_SETKA;i < width();i=i+RANGE_SETKA)
    {
        painter.drawText(x+i,y,QString::number(i/RANGE_SETKA));
        painter.drawText(x-i,y,QString::number(-i/RANGE_SETKA));
        painter.drawLine(x+i,0,x+i,height());
        painter.drawLine(x-i,0,x-i,height());
        for(j=RANGE_SETKA;j < height();j=j+RANGE_SETKA)
        {
            painter.drawText(x,y-j,QString::number(j/RANGE_SETKA));
            painter.drawText(x,y+j,QString::number(-j/RANGE_SETKA));
            painter.drawLine(0,y+j,width(),y+j);
            painter.drawLine(0,y-j,width(),y-j);
        }
    }
    // /[1]

    paintellips(&painter); // рисовка эллипсов + резина
    if(row != -1)
        colorellips(&painter); // выделение эллипса из таблицы
    if(max_independentEl.empty() == false)
    {
        paintcolgraph(&painter); //раскраска максимально независимого множества
    }
    else
    {

    }
}

void EllipsView::mousePressEvent(QMouseEvent *event)
{
    Qt::MouseButton button = event->button();
    QPointF point= event->pos();
    update();
    if(m_points.size()==2 && button == Qt::LeftButton)
    {
        Ellips *p= new Ellips(lp.size()+1,(m_points[0].x()-width()/2)/RANGE_SETKA,(-m_points[0].y()+ height()/2)/RANGE_SETKA,fabs(m_points.last().x()-m_points[0].x())/RANGE_SETKA,fabs(-m_points.last().y()+ m_points[0].y())/RANGE_SETKA);
        m_points.clear();
        lp.push_back(*p);
        fl=0;
        emit sgFromEllips(*p);

        delete p;


        update();
    }
    if(button == Qt::MiddleButton)
    {
        double x,y;
        x = (point.x()-width()/2)/RANGE_SETKA;
        y = (-point.y()+ height()/2)/RANGE_SETKA;
        for(std::vector<Ellips>::iterator it = lp.begin(); it != lp.end(); ++it)
        {
            Ellips k= *it;
            if(((fabs((k.getX()+k.getA())-x)<POGR_ELLIPS) || fabs((k.getY()+k.getB())-y)<POGR_ELLIPS) || ((fabs((k.getX()-k.getA())-x)<POGR_ELLIPS) || fabs((k.getY()-k.getB())-y)<POGR_ELLIPS))
            {
                double focal;
                k.setF1(x,y);
                k.setF2(x,y);
                double toch=k.getF1()+k.getF2();
                if(k.getA()<k.getB())
                    focal =fabs(toch - 2*k.getB());
                else
                    focal =fabs(toch - 2*k.getA());
                if(focal <= POGR)
                {
                    this->row = k.getIndex()-1;
                    emit sendrow(this->row);
                    break;
                }
            }

        }
    }

    if(button == Qt::RightButton && m_points.size()<2) // удаление и очистка от выделения
    {
        this->row = -1;
        double x,y;
        x = (point.x()-width()/2)/RANGE_SETKA;
        y = (-point.y()+ height()/2)/RANGE_SETKA;
        for(std::vector<Ellips>::iterator it = lp.begin(); it != lp.end(); ++it)
        {
            Ellips k= *it;
            if(((fabs((k.getX()+k.getA())-x)<POGR_ELLIPS) || fabs((k.getY()+k.getB())-y)<POGR_ELLIPS) || ((fabs((k.getX()-k.getA())-x)<POGR_ELLIPS) || fabs((k.getY()-k.getB())-y)<POGR_ELLIPS))
            {
                double focal;
                k.setF1(x,y);
                k.setF2(x,y);
                double toch=k.getF1()+k.getF2();
                if(k.getA()<k.getB())
                    focal =fabs(toch - 2*k.getB());
                else
                    focal =fabs(toch - 2*k.getA());
                if(focal <= POGR)
                {
                    lp.erase(it);
                    emit delfromEllips(k.getIndex());
                    break;
                }
            }

        }


    }
}

void EllipsView::mouseMoveEvent(QMouseEvent *ev)
{
    QPointF point;
    point= ev->pos();
    if(fl==0)
    {
        m_points.append(point);
        fl=1;
        m_points.append(point);
    }
    m_points.last()=point;
    update();
}


void EllipsView::colorellips(QPainter *painter)
{
    double X,Y,A,B;
    double x = (width()/ 2);
    double y = (height() / 2);
    painter->setPen(QPen(Qt::red, 4, Qt::SolidLine, Qt::RoundCap));
    unsigned int z=this->row;
    X=x+lp[z].getX()*RANGE_SETKA - lp[z].getA()*RANGE_SETKA;
    Y=y-lp[z].getY()*RANGE_SETKA - lp[z].getB()*RANGE_SETKA;
    A=lp[z].getA()*2*RANGE_SETKA;
    B=lp[z].getB()*2*RANGE_SETKA;
    painter->drawEllipse(X,Y,A,B);
    update();
}

void EllipsView::paintcolgraph(QPainter *painter)
{
    int d=0, col=1,max;
    double X,Y,A,B;
    double x = (width()/ 2);
    double y = (height() / 2);
    max = max_independentEl.size();
    for(std::vector<GraphNode *>::iterator it = max_independentEl.begin(); it != max_independentEl.end(); ++it)
    {

        // QColor ra=(col/max*100,col/max*150,col/max*175,col/max*255);
        painter->setBrush(QBrush(((int)(255/max*col),(int)(255/max*col),(int)(255/max*col),(int)(255/max*col))));
        painter->setPen(QPen(Qt::black, 4, Qt::SolidLine, Qt::RoundCap));
        GraphNode *nd1 = *it;
        d=nd1->getIndex()-1;
        X=x+lp[d].getX()*RANGE_SETKA - lp[d].getA()*RANGE_SETKA;
        Y=y-lp[d].getY()*RANGE_SETKA - lp[d].getB()*RANGE_SETKA;
        A=lp[d].getA()*2*RANGE_SETKA;
        B=lp[d].getB()*2*RANGE_SETKA;
        painter->drawEllipse(X,Y,A,B);
        col++;
    }
}
