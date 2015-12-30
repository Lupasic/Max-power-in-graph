#include <iostream>
#include "Ellips.h"
#include <cmath>
using namespace std;

Ellips::Ellips()
{
    this->index = 0;
    this->x = 0;
    this->y = 0;
    this->a = 0;
    this->b = 0;
    this->c = 0;
    this->f1 = 0;
    this->f2 = 0;
}

Ellips::Ellips(int i, double x1,double y1, double x2,double y2)
{
    this->index = i;
    this->x = x1;
    this->y = y1;
    this->a = x2;
    this->b = y2;
    if(x2 >= y2)
        this->c = this->a*(sqrt(1-((pow(this->b,2)/pow(this->a,2)))));
    else
        this->c = this->b*(sqrt(1-((pow(this->a,2)/pow(this->b,2)))));
    this->f1 = 0;
    this->f2 = 0;
}

void Ellips::setF1(double n, double m)
{
    if(this->b > this->a)
    {
        double p=-m,k=n;
    this->f1 = sqrt(pow(p-((-this->y)+this->c),2)+pow(k-this->x,2));
    }
  else
    this->f1 = sqrt(pow(n-(this->x+this->c),2)+pow(m-this->y,2));

}

void Ellips::setF2(double n, double m)
{
    if(this->b > this->a)
    {
        double p=-m, k=n;
  this->f2 = sqrt(pow(p-((-this->y)-this->c),2)+pow(k-this->x,2));
    }
        else
    this->f2 = sqrt(pow(n-(this->x-this->c),2)+pow(m-this->y,2));
}

void Ellips::print()
{
    cout << "( Горизонт" <<endl << this->a << "; Вертикаль" <<endl << this->b << "Фокальное расстояние " <<endl << this->c  << ")";
}
