#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <cstring>

class Person
{
friend std::ostream& operator<<(std::ostream& out, const Person& p)
{
    std::cout<<"Name: "<<p.getName()<<"\nNationality: "<<p.getNat()<<"\nAge: "<<p.getAge()<<"\n";
    return out;
}

friend std::istream& operator>>(std::istream& in, Person& p)
{
    char nm[100];
    char nt[100];
    int ag;

    std::cout<<"Input name of person: ";
    std::cin.getline(nm,100);
    std::cout<<"Input nationality of person: ";
    in>>nt;
    std::cout<<"Input age of reader: ";
    in>>ag;

    p.setName(nm);
    p.setNat(nt);
    p.setAge(ag);

    return in;
}

public:
    Person(const char* nm="Untitled", const char* nt = "Unknown", int ag = 20);
    Person(const Person&);
    Person& operator=(const Person&);
    ~Person();

    void setName(const char*);
    void setNat(const char*);
    void setAge(int age);

    const char* getName() const {return name;}
    const char* getNat() const {return nat;}
    int getAge() const {return age;}

    const virtual void print();

    bool operator<(const Person& p) const;
    bool operator>(const Person& p) const;
    bool operator<=(const Person& p) const;
    bool operator>=(const Person& p) const;
    bool operator!=(const Person& p) const;
    bool operator==(const Person& p) const;

private:
    char* name;
    char* nat;
    int age;
};

#endif // PERSON_H_
