#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

class Person
{
friend std::ostream& operator<<(std::ostream& out, const Person& p)
{
    out<<"Name: "<<p.getName()<<"\nDate of birth: "<<p.getBirth()<<"\n";
    return out;
}
public:
    Person(const char* nm = "", const char* br = "20000101");
    Person(const Person&);
    Person& operator=(const Person&);
    ~Person();

    const char* getName() const {return name;}
    const char* getBirth() const {return birth;}

    void setName(const char*);
    void setBirth(const char*);

private:
    char* name;
    char birth[9];

    bool isDateValid(const char*);
};


#endif // PERSON_H_
