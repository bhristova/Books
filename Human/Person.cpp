#include <cstring>

#include "Person.h"

bool Person::isDateValid(const char* br)
{
    for(size_t i=0; i<8; ++i)
    {
        if (br[i]-'0'<0 || br[i]-'0'>9) return false;
    }
    if(br[4]-'0'>1 || br[4]-'0'==1 && br[5]>2 || br[6]-'0'>3 || br[6]-'0'==3 && br[7]-'0'>1) return false;
    return true;
}

void Person::setName(const char* nm)
{
    if(!nm) nm="";
    int sz = strlen(nm) + 1;
    delete[] name;
    name = new char[sz];
    strcpy(name,nm);
}

void Person::setBirth(const char* br)
{
    if(!isDateValid(br)) br="20000101";
    strcpy(birth, br);
}

Person::Person(const char* nm, const char* br): name(nullptr)
{
    setName(nm);
    setBirth(br);
}
Person::Person(const Person& p): Person(p.getName(), p.getBirth()) {}

Person& Person::operator=(const Person& p)
{
    if(this!=&p)
    {
        setName(p.getName());
        setBirth(p.getBirth());
    }
    return *this;
}

Person::~Person()
{
    delete[] name;
}
