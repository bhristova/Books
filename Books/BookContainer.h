#ifndef BOOKCONTAINER_H_
#define BOOKCONTAINER_H_

#include "Book.h"

class BookContainer
{
friend std::ostream& operator<<(std::ostream& out, const BookContainer& a)
{
    for(size_t i=0; i<a.getSize(); ++i)
    {
        out<<a.books[i]<<"\n\n";
    }
    return out;
}
public:
    BookContainer(int cap = 2);
    BookContainer(const BookContainer&);
    BookContainer& operator=(const BookContainer&);
    ~BookContainer();

    void copy(const BookContainer&);

    int getCapacity() const {return capacity;}
    int getSize() const {return size;}

    void insert(const Book&);

    bool isEmpty();

    Book& operator[](unsigned int idx);


private:
    Book* books;
    int capacity;
    int size;

    void resizeUp();
};

#endif // BOOKCONTAINER_H_
