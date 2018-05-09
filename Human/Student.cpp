#include "Student.h"

void Student::setMark(double mk)
{
    if(mk<2 || mk>6) mk = 2;
    mark = mk;
}
void Student::setFn(long f)
{
    if(f<81000) f = 81000;
    fn = f;
}

Student::Student(const char* nm, const char* br, long f, double mk): Person(nm, br)
{
    setFn(f);
    setMark(mk);
}


