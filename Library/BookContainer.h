#ifndef BOOKCONTAINER_H_
#define BOOKCONTAINER_H_

#include "Book.h"
#include "Set.h"

class BookContainer: public Set<Book>
{
    void sort(bool (*compareBooks)(const Book& book1, const Book& book2));

    BookContainer booksByAuthor(const Author* author);
};

#endif // BOOKCONTAINER_H_
