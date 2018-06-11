#include <iostream>
#include <cstring>

#include "BookContainer.h"
#include "Reader.h"
#include "Author.h"
#include "Set.h"
#include "Community.h"

class Author;

using std::cout;

int main()
{
    Author a1("Ray Bradbury", 546, "American", 98);
    Author* a1p = &a1;

    Author a2("Douglas Adams", 234, "English", 66);
    Author* a2p = &a2;

    Author a3("J. R. R. Tolkien", 105, "English", 126);
    Author* a3p = &a3;

    int n=6;
    Book a("Tales from the Crypt", 340, 1964, a1p, horror, 24.99);
    Book b("The Hitchhiker's Guide to the Galaxy", 799, 1986, a2p, scifi, 34.95);
    Book c("The Lord Of The Rings", 1085, 1955, a3p, fantasy, 49.00);
    Book d("From the Dust Returned", 213, 2001, a1p, fantasy, 15.49);
    Book e("The Silmarillion", 618, 1977, a3p, fantasy, 19.90);

    a1.writeBook(a);
    a1.writeBook(d);

    a2.writeBook(b);

    a3.writeBook(c);
    a3.writeBook(d);

    std::cout<<a1<<"\n";

    BookContainer books;
    books.insert(a);
    books.insert(b);
    books.insert(c);
    books.insert(d);
    books.insert(e);

    std::cout<<"*** Books:\n"<<books<<"\n***\n";

    Reader r1("Anna", "Bulgarian", 22);
    Reader r2("Emma", "English", 30);
    Reader r3("John", "Irish", 26);
    r1.readBook(a);
    r1.readBook(b);

    r2.readBook(a);
    r2.readBook(d);

    r3.readBook(b);
    r3.readBook(c);
    r3.readBook(e);

    std::cout<<"\nReader #1's reading rank is "<<r1.getReadingRank()<<
               "\nReader #2's reading rank is "<<r2.getReadingRank()<<
               "\nReader #3's reading rank is "<<r3.getReadingRank()<<"\n";

    Community com;
    com.insert(r1);
    com.insert(r2);
    com.insert(r3);

    std::cout<<"\n***Community:\n"<<com<<"\n***\n";

    com.remove(r1);

    std::cout<<"\n*** Community after reader one's removal: \n"<<com<<"***\n";

    std::cout<<"Whole community's reading rank is "<<com.getReadingRank()<<"\n";

    return 0;
}

