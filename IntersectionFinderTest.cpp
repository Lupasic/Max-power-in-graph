#include "IntersectionFinderTest.h"
#include "IntersectionFinder.h"
#include "IntervalIntersectionFinder.h"
#include <assert.h>
#include <iostream>
IntersectionFinderTest::IntersectionFinderTest(string t, bool expect, Point2D *_p10, Point2D *_p11, Point2D *_p20, Point2D *_p21)
{
    this->tag = t;
    this->expectation = expect;
    this->p10 = _p10;
    this->p11 = _p11;
    this->p20 = _p20;
    this->p21 = _p21;
}
IntersectionFinderTest::~IntersectionFinderTest()
{
    delete this->p10;
    delete this->p11;
    delete this->p20;
    delete this->p21;
}

void IntersectionFinderTest::test()
{
    //Первая проверка: пересечение отрезков из точек, заданных "как есть"
    cout << tag << ": starting…" << endl;
    Line2D *l1 = new Line2D(1, p10, p11);
    Line2D *l2 = new Line2D(2, p20, p21);
    IntersectionFinder *f = new IntervalIntersectionFinder(l1, l2);
    bool result = f->find();
    assert(result == expectation);
    cout << tag << " (test 1): passed" << endl;


    delete l1;
    delete l2;
    delete f;

    l1 = new Line2D(1, p10, p11);
    l2 = new Line2D(2, p21, p20);
    f = new IntervalIntersectionFinder(l1, l2);
    result = f->find();
    assert(result == expectation);
    cout << tag << " (test 2): passed" << endl;


    delete l1;
    delete l2;
    delete f;

    l1 = new Line2D(1, p11, p10);
    l2 = new Line2D(2, p21, p20);
    f = new IntervalIntersectionFinder(l1, l2);
    result = f->find();
    assert(result == expectation);
    cout << tag << " (test 3): passed" << endl;


    delete l1;
    delete l2;
    delete f;

    cout << tag << ": all tests completed" << endl;

}
