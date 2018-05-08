#include <iostream>
#include <cstring>

#include "Book.h"

using std::cout;

void Book::setTitle(const char* t)
{
    if(!t) t="";
    int sz = strlen(t) + 1;
    if(!title) delete[] title;
    title = new char[sz];
    strcpy(title, t);
}

void Book::setPages(int pg)
{
    if(pg<=0) pg=1;
    pages = pg;
}

void Book::setYear(int yr)
{
    if(yr<1000) yr = 1000;
    year = yr;
}

void Book::setAuthor(const Author& a)
{
    author = a;
}

void Book::setGenre(const Genre& g)
{
    if(!g) genre = unknown;
    else genre = g;

}

void Book::setPrice(double pr)
{
    if(pr<0) pr=0;
    price = pr;
}

Book::Book(const char* t, int pg, int yr, const Author& a, const Genre& g, double pr)
{
    setTitle(t);
    setPages(pg);
    setYear(yr);
    setAuthor(a);
    setGenre(g);
    setPrice(pr);
}

Book::Book(const Book& b): Book(b.getTitle(), b.getPages(), b.getYear(), b.getAuthor(), b.getGenre(), b.getPrice()) {}

Book& Book::operator=(const Book& b)
{
    if(this != &b)
    {
        setTitle(b.getTitle());
        setPages(b.getPages());
        setYear(b.getYear());
        setAuthor(b.getAuthor());
        setGenre(b.getGenre());
        setPrice(b.getPrice());
    }
    return *this;
}
Book::~Book()
{
    delete[] title;
}

void Book::print()
{
    std::cout<<*this;
}

bool Book::operator<(const Book& p) const
{
    return (strcmp(p.getTitle(),this->getTitle())<0 && this->getPages()<p.getPages() && this->getYear()<p.getYear()
            && this->getAuthor()<p.getAuthor() && this->getGenre()<p.getGenre() && this->getPrice()<p.getPrice());
}

bool Book::operator>(const Book& p) const
{
    return (strcmp(p.getTitle(),this->getTitle())>0 && this->getPages()>p.getPages() && this->getYear()>p.getYear()
            && this->getAuthor()>p.getAuthor() && this->getGenre()>p.getGenre() && this->getPrice()>p.getPrice());
}

bool Book::operator==(const Book& p) const
{
    return (!strcmp(p.getTitle(),this->getTitle()) && this->getPages()==p.getPages() && this->getYear()==p.getYear()
            && this->getAuthor()==p.getAuthor() && this->getGenre()==p.getGenre() && this->getPrice()==p.getPrice());
}

bool Book::operator<=(const Book& p) const
{
    return (*this<p && *this==p);
}

bool Book::operator>=(const Book& p) const
{
    return (*this>p && *this==p);
}

bool Book::operator!=(const Book& p) const
{
    return !(*this==p);
}

Book::operator bool() const
{
    Book temp;
    return temp!=*this;
}

bool Book::operator!() const
{
    return(!bool(*this));
}

