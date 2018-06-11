#include "Person.h"

void Person::setName(const char* nm)
{
    if(!nm) nm="";
    int sz = strlen(nm) + 1;
    delete[] name;
    name = new char[sz];
    strcpy(name,nm);
}

void Person::setNat(const char* nt)
{
    if(!nt) nt="";
    int sz = strlen(nt) + 1;
    delete[] nat;
    nat = new char[sz];
    strcpy(nat,nt);
}

void Person::setAge(int ag)
{
    if(ag<20) ag=20;
    age = ag;
}

Person::Person(const char* nm, const char* nt, int ag): name(nullptr), nat(nullptr)
{
    setName(nm);
    setNat(nt);
    setAge(ag);
}

Person::Person(const Person& p): Person(p.getName(), p.getNat(), p.getAge()) {}

Person& Person::operator=(const Person& p)
{
    if(this != &p)
    {
        setName(p.getName());
        setNat(p.getNat());
        setAge(p.getAge());
    }
    return *this;
}

Person::~Person()
{
    delete[] name;
    delete[] nat;
}

const void Person::print()
{
    std::cout<<*this;
}

bool Person::operator<(const Person& p) const
{
    return (strcmp(p.getName(),this->getName())<0 && strcmp(p.getNat(),this->getNat())<0 && this->getAge()<p.getAge());
}

bool Person::operator>(const Person& p) const
{
    return (strcmp(p.getName(),this->getName())>0 && strcmp(p.getNat(),this->getNat())>0 && this->getAge()>p.getAge());
}

bool Person::operator==(const Person& p) const
{
    return (!strcmp(p.getName(),this->getName()) && !strcmp(p.getNat(),this->getNat()) && this->getAge()==p.getAge());
}

bool Person::operator<=(const Person& p) const
{
    return (*this<p || p==*this);
}

bool Person::operator>=(const Person& p) const
{
    return (*this>p || p==*this);
}

bool Person::operator!=(const Person& p) const
{
    return (!(p==*this));
}
