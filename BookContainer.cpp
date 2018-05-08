#include "BookContainer.h"

void BookContainer::copy(const BookContainer& b)
{
    if(this->books) delete[] this->books;
    this->books = new Book[b.getSize()];
    for(size_t i=0;i<b.getSize();++i)
    {
        this->books[i] = b.books[i];
    }
    this->size = b.getSize();
    this->capacity = b.getCapacity();

}

BookContainer::BookContainer(int cap)
{
    if(cap<2) cap=2;
    capacity=2;
    books = new Book[cap];
    size = 0;
}

BookContainer::BookContainer(const BookContainer& b)
{
    this->copy(b);
}

BookContainer& BookContainer::operator=(const BookContainer& b)
{
    if(this!=&b)
        this->copy(b);
    return *this;
}

BookContainer::~BookContainer()
{
    delete[] books;
}

void BookContainer::resizeUp()
{
    Book* temp = new Book[this->getSize()];
    for(size_t i = 0; i<this->getSize(); ++i)
    {
        temp[i] = this->books[i];
    }
    delete[] this->books;
    this->books = new Book[this->capacity*2];
    for(size_t i = 0; i<this->getSize(); ++i)
    {
        this->books[i] = temp[i];
    }
    this->capacity*=2;
}

void BookContainer::insert(const Book& b)
{
    if(size==capacity) resizeUp();
    books[size] = b;
    ++size;
}

bool BookContainer::isEmpty()
{
    return (size==0);
}

Book& BookContainer::operator[](unsigned int idx)
{
    if(idx<size) return books[idx];
    Book a;
    return a;
}
