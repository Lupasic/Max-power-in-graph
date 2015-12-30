#include "IntervalIntersectionFinder.h"
#include <math.h>
IntervalIntersectionFinder::IntervalIntersectionFinder(Line2D *firstLine, Line2D *secondLine)
{
    this->l1 = firstLine;
    this->l2 = secondLine;
}
IntervalIntersectionFinder::~IntervalIntersectionFinder()
{
    this->l1 = NULL;
    this->l2 = NULL;
}

bool IntervalIntersectionFinder::find()
{
    //по сути, отрезок — это часть прямой y = kx + b
    //у нас есть "количество иксов за один игрек"

    int deltaX1 = l1->getFinalPoint()->getX() - l1->getOriginPoint()->getX();
    int deltaY1 = l1->getFinalPoint()->getY() - l1->getOriginPoint()->getY();

    int deltaX2 = l2->getFinalPoint()->getX() - l2->getOriginPoint()->getX();
    int deltaY2 = l2->getFinalPoint()->getY() - l2->getOriginPoint()->getY();

    double x10, x11, x20, x21, y10, y11, y20, y21;
    if(deltaX1 < 0)
    {
        x10 = l1->getFinalPoint()->getX();
        x11 = l1->getOriginPoint()->getX();
    }
    else
    {
        x10 = l1->getOriginPoint()->getX();
        x11 = l1->getFinalPoint()->getX();
    }

    if(deltaY1 < 0)
    {
        y10 = l1->getFinalPoint()->getY();
        y11 = l1->getOriginPoint()->getY();
    }
    else
    {
        y10 = l1->getOriginPoint()->getY();
        y11 = l1->getFinalPoint()->getY();
    }



    if(deltaX2 < 0)
    {
        x20 = l2->getFinalPoint()->getX();
        x21 = l2->getOriginPoint()->getX();
    }
    else
    {
        x20 = l2->getOriginPoint()->getX();
        x21 = l2->getFinalPoint()->getX();
    }

    if(deltaY2 < 0)
    {
        y20 = l2->getFinalPoint()->getY();
        y21 = l2->getOriginPoint()->getY();
    }
    else
    {
        y20 = l2->getOriginPoint()->getY();
        y21 = l2->getFinalPoint()->getY();
    }



    if(deltaX1 != 0 && deltaX2 != 0)
    {
        double k1 = (double) deltaY1 / (double)deltaX1;
        double k2 = (double) deltaY2 / (double) deltaX2;

        double b1 = (double)l1->getOriginPoint()->getY() - (double)k1*(double)l1->getOriginPoint()->getX();
        double b2 = (double)l2->getOriginPoint()->getY() - (double)k2*(double)l2->getOriginPoint()->getX();
        //решаем уравнение k1*x + b1 = k2*x + b2 -> x = (b2 - b1) / (k1 - k2), если прямые не параллельны
        if(k1 != k2)
        {
            double intX = (double) (b2 - b1) / (double) (k1 - k2);     //точка пересечения
            double intY = k1*intX + b1;

            //проверяем, лежит ли точка пересечения в проекции

            if(intX >= x10 && intX <= x11 && intX >= x20 && intX <= x21 && intY >= y10 && intY <= y11 && intY >= y20 && intY <= y21)
                return true;
            return false;
        }
        else
        {
            //если прямые параллельны (в том числе параллельны оси X), то они пересекаются только в том случае, если у них равный свободный член и пересекающиеся интервалы X/Y
            if(b1 != b2)
                return false;       //разные свободные члены
            if(x10 >= x20 && x10 <= x21)
                return true;
            if(x20 >= x10 && x20 <= x11)
                return true;
            return false;
        }

    }
    else if(deltaX1 == 0.0 && deltaX2 != 0.0)
    {
        //первый отрезок - прямая, параллельная оси Y; второй — параллелен оси X или kx + b
        double k2 = (double) deltaY2 / (double) deltaX2;
        double b2 = (double)l2->getOriginPoint()->getY() - (double)k2*(double)l2->getOriginPoint()->getX();

        double intY = k2*(double)x10 + b2;      //значение Y-координаты точки пересечения
        //если y лежит в обоих интервалах и x лежит в интервале описания второго отрезка, то пересекаются
        if(intY >= y10 && intY <= y11 && intY >= y20 && intY <= y21 && (x20 <= x10 && x10 <= x21))
            return true;
        return false;
    }
    else if(deltaX1 != 0.0 && deltaX2 == 0.0)
    {
        //то же самое, что выше, только x10 <-> x20 и т.д.
        double k1 = (double)deltaY1 / (double)deltaX1;
        double b1 = (double)l1->getOriginPoint()->getY() - (double)k1*(double)l1->getOriginPoint()->getX();

        double intY = k1*(double)x20 + b1;      //значение Y-координаты точки пересечения
        if(intY >= y10 && intY <= y11 && intY >= y20 && intY <= y21 && (x10 <= x20 && x20 <= x11))
            return true;
        return false;
    }
    else if(deltaX1 == 0.0 && deltaX2 == 0.0)
    {
        //обе прямые параллельны оси Y
        //если они определены на разных иксах — не пересекаются
        if(x10 != x20)
            return false;
        //если интервалы игреков пересекаются — пересекаются и отрезки
        if(y10 <= y20 && y20 <= y11 && y11 <= y21)
            return true;
        if(y20 <= y10 && y10 <= y21 && y21 <= y11)
            return true;
        return false;
    }

    return false;
}
