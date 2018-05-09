#include <cstring>

#include "Employee.h"

void Employee::setPosition(const char* p)
{
    if(!p) p="";
    int sz = strlen(p) + 1;
    if(!position) delete[] position;
    position = new char[sz];
    strcpy(position, p);
}

void Employee::setSalary(double s)
{
    if(s<500) s=500;
    salary=s;
}

Employee::Employee(const char* nm, const char* br, const char* pos, double sal): Person(nm, br)
{
    setPosition(pos);
    setSalary(sal);
}

Employee::Employee(const Employee& e): Person(e.getName(), e.getBirth())
{
    setPosition(e.getPosition());
    setSalary(e.getSalary());
}

Employee& Employee::operator=(const Employee& e)
{
    if(this!=&e)
    {
        Person(e.getName(), e.getBirth());
        setPosition(e.getPosition());
        setSalary(e.getSalary());
    }
    return *this;
}

Employee::~Employee()
{
    delete[] position;
}


