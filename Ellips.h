//Эллипс

#ifndef _Ellips_
#define _Ellips_
#include <Point2D.h>

class Ellips: public Point2D
{
private:
    int index; //индекс Эллипса
    double a; //ширина
    double b; // высота
    double c; // фокальное расстояние
    double f1; // от 1 фокуса до точки
    double f2; // от 2 фокуса до точки
public:
    Ellips();
    Ellips(int, double ,double, double, double); // x, y, ширина, высота
    double getX() {return x;}
    double getY() {return y;}
    double getA() { return a; }
    double getB() { return b; }
    double getC() { return c; }
    double getF1() { return f1; }
    double getF2() { return f2; }
    int getIndex() {return this->index;}
    void setF1(double m, double n);
    void setF2(double m, double n);
    void print();
};

#endif //_Ellips_
