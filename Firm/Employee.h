#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "Date.h"

class Employee
{
	public:
		Employee(const char* n = "", const Date& = Date(1, 1, 2018), const char* p = "", double s = 0.0);
		Employee(const Employee&);

		const char* getName() const { return this->name; }
		void setName(const char*);

		Date getHiredOn() const { return this->hiredOn; }
		void setHiredOn(const Date&);

		const char* getPosition() const { return this->position; }
		void setPosition(const char*);

		double getSalary() const { return this->salary; }
		void setSalary(double);

		void print() const;

	private:
		char name[40];
		Date hiredOn;
		char position[20];
		double salary;
};

#endif

