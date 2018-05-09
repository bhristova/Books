#ifndef PROFESSOR_H_
#define PROFESSOR_H_

#include "Student.h"

class Professor: virtual public Person
{
friend std::ostream& operator<<(std::ostream& out, const Professor& p)
{
    out<<(Person)p;
    out<<"Subject: "<<p.getSubject()<<"\n";
    return out;
}

public:
    Professor(const char* nm = "", const char* br = "20000101", const char* subj = "");
    Professor(const Professor&);
    Professor& operator=(const Professor&);
    ~Professor();

    const char* getSubject() const {return subject;}
    const int getSize() const {return size;}
    const Student& getStudent(int i) const {return students[i];}

    void setSubject(const char*);

    void addStudent(const Student&);

private:
    char* subject;
    Student* students;
    int size;
    int capacity;

    void resize();
};

#endif // PROFESSOR_H_
