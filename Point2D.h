#ifndef POINT2D_H
#define POINT2D_H
class Point2D
{
protected:
    double x;
    double y;
public:
    Point2D();
    Point2D(double, double);
    double getX() { return this->x; }
    double getY() { return this->y; }
    void setX(int _x) { this->x = _x; }
    void setY(int _y) { this->y = _y; }
    void print();
};
#endif
