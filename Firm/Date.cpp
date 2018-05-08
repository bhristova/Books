#include <iostream>

#include "Date.h"

Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1900;
}

Date::Date(unsigned d, unsigned m, unsigned y)
{
	if (isValidDate(d, m, y))
	{
		this->day = d;
		this->month = m;
		this->year = y;
	}
	else
	{
		this->day = 1;
		this->month = 1;
		this->year = 1900;
	}
}

void Date::read()
{
	do
	{
		std::cout << "Day: "; std::cin >> this->day;
		std::cout << "Month: "; std::cin >> this->month;
		std::cout << "Year: "; std::cin >> this->year;
	}
	while (!isValidDate(this->day, this->month, this->year));
}

void Date::print() const
{
	std::cout << this->day << '.' << this->month << '.' << this->year << std::endl;
}

bool Date::isValidDate(unsigned short d, unsigned short m, unsigned short y)
{
	if (!y) return false;

	if (m < 1 || m > 12) return false;

	bool leapYear = (y % 4 == 0) && !(y % 100 == 0 && y % 400 != 0);

	unsigned maxDays;
	switch (m)
	{
		case 2: maxDays = 28 + leapYear; break;
		case 4:
		case 6:
		case 9:
		case 11: maxDays = 30; break;
		default:
			maxDays = 31;
			break;
	}

	return d > 0 && d <= maxDays;
}

unsigned Date::getDay() const
{
	return this->day;
}

void Date::setDay(unsigned newDay)
{
	if (isValidDate(newDay, this->month, this->year))
		this->day = newDay;
}

unsigned Date::getMonth() const
{
	return this->month;
}

void Date::setMonth(unsigned newMonth)
{
	if (isValidDate(this->day, newMonth, this->year))
		this->month = newMonth;
}

unsigned Date::getYear() const
{
	return this->year;
}

void Date::setYear(unsigned newYear)
{
	if (isValidDate(this->day, this->month, newYear))
		this->year = newYear;
}

bool Date::isEqual(const Date& other) const
{
	return this->day == other.day && this->month == other.month && this->year == other.year;
}

bool Date::isBefore(const Date& other) const
{
	if (this->year < other.year) return true;
	if (this->year > other.year) return false;

	if (this->month < other.month) return true;
	if (this->month > other.month) return false;

	return this->day < other.day;
}
