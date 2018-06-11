#include "BookContainer.h"
#include "Author.h"

void BookContainer::sort(bool (*compareBooks)(const Book& book1, const Book& book2))
{
    BookContainer temp;
    for(size_t i=0; i<this->getSetSize()-1; ++i)
    {
        Book max = this[0][i];
        for(size_t j=i+1; j<this->getSetSize(); ++j)
            {
                if(compareBooks(this[0][j], max) && i!=j) ///if max is smaller in the current context of the function than the current book
                {
                    max = this[0][j];
                }
            }
        temp.insert(max);
    }
    while(!this->isEmpty())
    {
        this->destroy();
    }
    for(size_t i=0;i<temp.getSetSize();++i)
    {
        this->insert(temp[i]);
    }
}

BookContainer BookContainer::booksByAuthor(const Author* author)
{
    BookContainer authorBooks;
    int br=0;
    for(size_t i=0; i<this->getSetSize(); ++i)
    {
        if(this[0][i].getAuthor()->areTheSame(author)) { authorBooks.insert(this[0][i]); ++br;}
    }
    return authorBooks;
}

