#ifndef STUDENT_H_
#define STUDENT_H_

#include "Person.h"

class Student: virtual public Person
{
friend std::ostream& operator<<(std::ostream& out, const Student& s)
{
    out<<(Person)s;
    out<<"Faculty number: "<<s.getFn()<<"\nMark: "<<s.getMark()<<"\n";
    return out;
}

public:
    Student(const char* nm = "", const char* br = "20000101", long f = 81000, double mk = 2);

    void setMark(double mk);
    void setFn(long f);

    const long getFn() const {return fn;}
    const double getMark() const {return mark;}
private:
    long fn;
    double mark;
};

#endif // STUDENT_H_
