#include <iostream>
#include <cstring>

#include "Dean.h"

const Student& highestMark(const Professor& p)
{
    int j=0;
    double m = 2.0;
    for(int i=0;i<p.getSize();++i)
    {
        if (p.getStudent(i).getMark() > m) {j=i; m=p.getStudent(i).getMark();}
    }
    return p.getStudent(j);
}

bool isDeanAProf(const Professor* profs, const Dean& d, int sz)
{
    for(int i=0;i<sz;++i)
    {
        if(!strcmp(profs[i].getName(), d.getName()) && !strcmp(profs[i].getBirth(),d.getBirth()) && !strcmp(profs[i].getSubject(),d.getSubject())) return true;
    }
    return false;
}

int main()
{
    Person ana("Anna", "20002144");
    //std::cout<<ana;
    Student jenny("Jenny", "19970104", 81437, 5.50);
    //std::cout<<jenny;
    Student olive("Olive", "19970612", 81321, 4.48);
    Employee emma("Emma", "19961205", "architect", 993.77);
    ////std::cout<<emma;
    Professor p1("Smith", "19580412", "informatics");
    //std::cout<<p1;
    //p1.addStudent(jenny);
    //p1.addStudent(olive);
    //Student best = highestMark(p1);
    //std::cout<<best;
    Professor p2("Johnson", "19891112", "algebra");
    Professor profs[] = {p2, p1};
    int sz = 2;
    Dean d("Johnson", "19891112", "algebra", "Dean", 700);
    //std::cout<<isDeanAProf(profs,d,sz);
    return 0;
}
