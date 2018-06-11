#include <cstring>

#include "Author.h"

void Author::setCount(int c)
{
    if(c<=0) c=1;
    count = c;
}
const void Author::print()
{
    std::cout<<*this;
}

void Author::writeBook(Book& b)
{
    writtenBooks.insert(b);
}

bool Author::areTheSame(const Author* a)
{
    return (a->getAge()==this->getAge() && a->getCount() == this->getCount() && (!strcmp(a->getName(),this->getName())) && (!strcmp(a->getNat(),this->getNat())) && a->getWrittenBooksCount() == this->getWrittenBooksCount());
}


