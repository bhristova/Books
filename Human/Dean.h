#ifndef DEAN_H_
#define DEAN_H_

#include "Professor.h"
#include "Employee.h"

class Dean: public Professor, public Employee
{
friend std::ostream& operator<<(std::ostream& out, const Dean& p)
{
    out<<(Professor)p<<Employee(p);
    return out;
}
public:
    Dean(const char* nm = "", const char* br = "20000101", const char* subj = "", const char* pos = "", double sal = 500):
        Person(nm,br), Professor(nm,br,subj), Employee(nm,br,pos,sal) {}

};

#endif // DEAN_H_
