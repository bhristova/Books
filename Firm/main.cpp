#include <iostream>
#include "Firm.h"

int main()
{
    Firm f("Azkaban", 20);
    Employee a("Anna", Date(23,11,2004), "boss", 2039.55);
    Employee b("Billy", Date(11,05,2014), "cleaner", 999.03);
    Employee c("Cecille", Date(07,07,2015), "programmer", 1378.88);

    Employee d;
    d=a;
    f.addEmployee(a);
    f.addEmployee(b);
    f.addEmployee(c);
    f.addEmployee(d);

    f.print();

    f.fireEmployee("Cecille");
    f.print();
    f.raiseSalary();
    f.print();
    return 0;
}
