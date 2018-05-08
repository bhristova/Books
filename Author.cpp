#include <cstring>

#include "Author.h"

void Author::setName(const char* nm)
{
    if(!nm) nm="";
    int sz = strlen(nm) + 1;
    if(!name) delete[] name;
    name = new char[sz];
    strcpy(name,nm);
}

void Author::setCount(int c)
{
    if(c<=0) c=1;
    count = c;
}

void Author::setNat(const char* nt)
{
    if(!nt) nt="";
    int sz = strlen(nt) + 1;
    if(!nat) delete[] nat;
    nat = new char[sz];
    strcpy(nat,nt);
}

Author::Author(const char* nm, int c, const char* nt)
{
    setName(nm);
    setCount(c);
    setNat(nt);
}

Author::Author(const Author& a): Author(a.getName(), a.getCount(), a.getNat()) {}

Author& Author::operator=(const Author& a)
{
    if(this != &a)
    {
        setName(a.getName());
        setCount(a.getCount());
        setNat(a.getNat());
    }
    return *this;
}

Author::~Author()
{
    delete[] name;
    delete[] nat;
}

void Author::print()
{
    std::cout<<*this;
}

bool Author::operator<(const Author& p) const
{
    return (strcmp(p.getName(),this->getName())<0 && strcmp(p.getNat(),this->getNat())<0 && this->getCount()<p.getCount());
}

bool Author::operator>(const Author& p) const
{
    return (strcmp(p.getName(),this->getName())>0 && strcmp(p.getNat(),this->getNat())>0 && this->getCount()>p.getCount());
}

bool Author::operator==(const Author& p) const
{
    return (!strcmp(p.getName(),this->getName()) && !strcmp(p.getNat(),this->getNat()) && this->getCount()==p.getCount());
}

bool Author::operator<=(const Author& p) const
{
    return (*this<p || p==*this);
}

bool Author::operator>=(const Author& p) const
{
    return (*this>p || p==*this);
}

bool Author::operator!=(const Author& p) const
{
    return (!(p==*this));
}

