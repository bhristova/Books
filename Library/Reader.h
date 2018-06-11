#ifndef READER_H_
#define READER_H_

#include <iostream>

#include "Person.h"
#include "BookContainer.h"
#include "ReadingRankable.h"

class Reader: public Person, public ReadingRankable
{
friend std::ostream& operator<<(std::ostream& out, const Reader& r)
{
    std::cout<<(Person)r<<"Books read: \n";
    for(int i=0;i<r.readBooks.getSetSize();++i)
        std::cout<<r.readBooks[i]<<"\n";
    return out;
}

public:
    Reader(const char* nm = "Untitled", const char* nt = "Unknown", int ag = 20): Person(nm,nt,ag) {}

    void readBook(Book& b);

    int getReadBooksCount() const {return readBooks.getSetSize();}

    virtual int getReadingRank() const
    {
        int sum=0;
        for(size_t i=0;i<this->readBooks.getSetSize();++i)
            sum+=this->readBooks[i].getPages();
        return sum;
    }

private:
    BookContainer readBooks;
};


#endif // READER_H_
