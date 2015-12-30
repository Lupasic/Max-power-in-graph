#include <iostream>
#include "Poisk_peresech.h"
#include <stdlib.h>
#include <math.h>
#define RANGE 0.001
#define RANGE2 0.01

using namespace std;

int min(int a, int b)
{
    if(a<b)
        return a;
    else
        return b;
}

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

Poisk_peresech::Poisk_peresech(Ellips *first, Ellips *second)
{
    this->a = first;
    this->b = second;
    this->peresek=false;
double X[4];
double toch1=0 , toch2=0, A1=2*a->getA(), A2=2*b->getA(), Pipech1, Pipech2;
double i,j, d, e, m, n;

    if(((((b->getX()-b->getA())<=(a->getX()-a->getA())) && ((a->getX()-a->getA())<=(b->getX()+b->getA()))) && ((((b->getY()-b->getB())<=(a->getY()-a->getB())) && ((a->getY()-a->getB())<=(a->getY()+a->getB()))) || (((a->getY()-a->getB())<=(b->getY()-b->getB())) && ((b->getY()-b->getB())<=(b->getY()+b->getB()))))) ||
       ((((a->getX()-a->getA())<=(b->getX()-b->getA())) && ((b->getX()-b->getA())<=(a->getX()+a->getA()))) && ((((b->getY()-b->getB())<=(a->getY()-a->getB())) && ((a->getY()-a->getB())<=(a->getY()+a->getB()))) || (((a->getY()-a->getB())<=(b->getY()-b->getB())) && ((b->getY()-b->getB())<=(b->getY()+b->getB()))))) )
    {
// Прямоугольники пересеклись, далее проверка элипсов
        X[0]=max((a->getX()-a->getA()),(b->getX()-b->getA()));
        X[1]=min((a->getY()+a->getB()),(b->getY()+b->getB()));
        X[2]=min((a->getX()+a->getA()),(b->getX()+b->getA()));
        X[3]=max((a->getY()-a->getB()),(b->getY()-b->getB()));
        //Разбиваем на равномерную матрицу
        d = fabs(X[2]-X[0]);
        e= fabs(X[3]-X[1]);
        if(a->getA()<a->getB())
            A1=2*a->getB();
        if(b->getA()<b->getB())
            A2=2*b->getB();
        // рассчет на пересечение
        for ( i = 0; i <= e; i=i+RANGE)
        {
            if(this->peresek==true)
                break;
            m=X[3]+i;
            for ( j = 0; j <= d; j=j+RANGE)
            {
                n=X[0]+j;
                a->setF1(n,m);
                a->setF2(n,m);
                b->setF1(n,m);
                b->setF2(n,m);
                toch1=a->getF1()+a->getF2();
                toch2=b->getF1()+b->getF2();
                Pipech1 =fabs(toch1 - A1);
                Pipech2 =fabs(toch2 - A2);
                if((Pipech1 <= RANGE2) && (Pipech2 <= RANGE2))
                {
                    this->peresek = true;
                    break;
                }   
            }
        }
    }
}

