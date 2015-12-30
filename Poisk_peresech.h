//Поиск пересечения эллипсов
#ifndef _Poisk_peresech_
#define _Poisk_peresech_

#include "Ellips.h"

class Poisk_peresech
{
private:
    bool peresek;
    Ellips *a;
    Ellips *b;
public:
    Poisk_peresech(Ellips *, Ellips *);
    int peresechenie(){return this->peresek;}
};

#endif //_Poisk_peresech_
