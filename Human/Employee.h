#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "Person.h"

class Employee: virtual public Person
{
friend std::ostream& operator<<(std::ostream& out, const Employee& e)
{
    out<<(Person)e;
    out<<"Position: "<<e.getPosition()<<"\nSalary: "<<e.getSalary()<<"\n";
    return out;
}

public:
    Employee(const char* nm = "", const char* br = "20000101", const char* pos = "", double sal = 500);
    Employee(const Employee&);
    Employee& operator=(const Employee&);
    ~Employee();

    const char* getPosition() const {return position;}
    const double getSalary() const {return salary;}

    void setPosition(const char*);
    void setSalary(double);
private:
    char* position;
    double salary;
};

#endif // EMPLOYEE_H_
