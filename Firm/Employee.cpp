#include <cstring>
#include <iostream>
#include <iomanip>

#include "Employee.h"

Employee::Employee(const char* n, const Date& d, const char* p, double s)
	: hiredOn(d) , salary(0)
{
	this->setName(n);
	this->setPosition(p);
	this->setSalary(s);
}

Employee::Employee(const Employee& e)
{
    delete[] this;
    this->setName(e.getName());
    this->setHiredOn(e.getHiredOn());
    this->setPosition(e.getPosition());
    this->setSalary(e.getSalary());
}

void Employee::setName(const char* n)
{
	strcpy(this->name, n);
}

void Employee::setSalary(double s)
{
	if (s > 0)
	{
		this->salary = s;
	}
}

void Employee::setPosition(const char* p)
{
	strcpy(position, p);
}

void Employee::setHiredOn(const Date& d)
{
	this->hiredOn = d;
}

void Employee::print() const
{
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Hired on: "; this->hiredOn.print();
	std::cout << "Position: " << this->position << std::endl;
	std::cout << "Salary: " << std::setiosflags(std::ios::fixed) << std::setprecision(2) << this->salary << std::endl;
}
