#ifndef AUTHOR_H_
#define AUTHOR_H_

#include <iostream>

#include "Reader.h"
#include "BookContainer.h"
#include "WritingRankable.h"

class Author: public Reader, public WritingRankable
{

friend std::ostream& operator<<(std::ostream& out, const Author& a)
{
    std::cout<<(Reader)a<<"Count: "<<a.getCount()<<"\n";
    return out;
}

friend std::istream& operator>>(std::istream& in, Author*& a)
{
    Reader p;
    std::cin>>p;

    int cnt;

    std::cout<<"Input count of books by author: ";
    in>>cnt;

    *a = Author(p.getName(), cnt, p.getNat(), p.getAge());

    return in;
}

public:
    Author(const char* nm="Untitled", int c = 1, const char* nt = "Unknown", int ag = 20): Reader(nm,nt,ag) { setCount(c);}

    void setCount(int);

    int getCount() const {return count;}

    void writeBook(Book& b);

    int getWrittenBooksCount() const {return writtenBooks.getSetSize();}

    const void print();

    bool areTheSame(const Author* a);

    virtual int getWritingRank() const
    {
        int sum=0;
        for(size_t i=0;i<this->writtenBooks.getSetSize();++i)
            sum+=this->writtenBooks[i].getPages();
        return sum;
    }

private:
    int count;

    BookContainer writtenBooks;
};

#endif // AUTHOR_H_
