#ifndef FIRM_H_
#define FIRM_H_

#include "Employee.h"

class Firm
{
public:
    Firm(const char* nm = "", int cap = 2);
    Firm(const Firm&);
    Firm& operator=(const Firm&);
    ~Firm();

    const char* getName() const {return name;}
    int getSize() const {return size;}
    int getCapacity() const {return capacity;}

    void setName(const char* nm);
    void setCapacity(int cap);

    void print() const;

    void addEmployee(const Employee&);
    void fireEmployee(const char* nm);

    void raiseSalary();
private:
    char* name;
    Employee* employees;
    int size;
    int capacity;

    void resize();
    void remove(int);
};

#endif // FIRM_H_
