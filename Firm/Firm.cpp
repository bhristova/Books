#include <iostream>
#include <cstring>
#include "Firm.h"

void Firm::setName(const char* nm)
{
    if(!nm) nm="";
    int sz = strlen(nm) + 1;
    delete[] name;
    name = new char[sz];
    strcpy(name,nm);
}

void Firm::setCapacity(int cap)
{
    if(cap<10) cap=10;
    capacity = cap;
}

Firm::Firm(const char* nm, int cap)
{
    setName(nm);
    setCapacity(cap);
    size = 0;
    employees = new Employee[cap];
}

Firm::Firm(const Firm& f)
{
    setCapacity(f.getCapacity());
    size = f.getSize();
    setName(f.getName());
    employees = new Employee[size];
    for(size_t i =0;i<size;++i)
    {
        employees[i] = f.employees[i];
    }
}
Firm& Firm::operator=(const Firm& f)
{
    if(this!=&f)
    {
        setCapacity(f.getCapacity());
        size = f.getSize();
        setName(f.getName());
        delete[] employees;
        employees = new Employee[size];
        for(size_t i =0;i<size;++i)
        {
            employees[i] = f.employees[i];
        }
    }
    return *this;
}
Firm::~Firm()
{
    delete name;
    delete[] employees;
}

void Firm::resize()
{
    int a=0;
    if(getSize()==0) a = 1; else a = getSize();
    Employee* temp = new Employee[a*2];
    for(size_t i=0;i<getSize();++i)
    {
        temp[i] = this->employees[i];
    }
    if(getSize()>0) delete[] this->employees;
    this->employees = temp;
    size*=2;
}

void Firm::remove(int pos)
{
    for(int i=pos;i<getSize();++i)
    {
        employees[i] = employees[i+1];
    }
}

void Firm::addEmployee(const Employee& e)
{
    int i=this->getSize();
    this->employees[i] = e;
    size++;
}

void Firm::print() const
{
    std::cout<<"Name of firm: "<<getName()<<std::endl<<"Capacity: "<<getCapacity()<<std::endl<<std::endl;
    for(size_t i=0;i<getSize();++i)
        this->employees[i].print();
}

void Firm::fireEmployee(const char* nm)
{
    for(size_t i=0;i<getSize();++i)
    {
        if(!strcmp(nm,employees[i].getName()))
        {
            int j=i;
            this->remove(i);
            size--;
            return;
        }
    }
}

void Firm::raiseSalary()
{
    for(size_t i=0;i<getSize();++i)
    {
        employees[i].setSalary(employees[i].getSalary() + employees[i].getSalary()*0.10);
    }
}





