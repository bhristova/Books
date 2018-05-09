#include <cstring>

#include "Professor.h"

void Professor::setSubject(const char* subj)
{
    if(!subj) subj="";
    int sz = strlen(subj) + 1;
    if(!subject) delete[] subject;
    subject = new char[sz];
    strcpy(subject, subj);
}

Professor::Professor(const char* nm, const char* br, const char* subj): Person(nm,br)
{
    setSubject(subj);
    capacity=10;
    size=0;
    students = new Student[capacity];
}

Professor::Professor(const Professor& p): Person(p.getName(), p.getBirth())
{
    setSubject(p.getSubject());
}

Professor& Professor::operator=(const Professor& p)
{
    if(this!=&p)
    {
        Person(p.getName(), p.getBirth());
        setSubject(p.getSubject());
    }
    return *this;
}

Professor::~Professor()
{
    delete[] subject;
}

void Professor::resize()
{
    Student* temp = new Student[capacity-1];
    for(int i=0;i<capacity;++i)
    {
        temp[i] = students[i];
    }
    delete[] students;
    students = new Student[capacity*2];
    for(int i=0;i<capacity;++i)
    {
        students[i] = temp[i];
    }
    ++size;
    capacity*=2;
}

void Professor::addStudent(const Student& s)
{
    if(size==capacity) resize();
    students[size] = s;
    ++size;
}





