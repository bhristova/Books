#include <iostream>
#include <cstring>

#include "BookContainer.h"

using std::cout;

int main()
{
    int n=6;
    Author ath1("Ray Bradbury", 546, "American");
    Author ath2("Ray Bradbury", 546, "American");
    Book a("Tales from the Crypt", 340, 1964, Author("Ray Bradbury", 546, "American"), horror, 24.99);
    Book b("The Hitchhiker's Guide to the Galaxy", 799, 1986, Author("Douglas Adams", 234, "English"), scifi, 34.95);
    Book c("The Lord Of The Rings", 1085, 1955, Author("J. R. R. Tolkien", 105, "English"), fantasy, 49.00);
    Book d("From the Dust Returned", 213, 2001, Author("Ray Bradbury", 546, "American"), fantasy, 15.49);
    Book e("The Silmarillion", 618, 1977, Author("J. R. R. Tolkien", 105, "English"), fantasy, 19.90);
    Book f("Fahrenheit 451", 487, 1953, Author("Ray Bradbury", 546, "American"), dystopian, 22.30);

    Book* books = new Book[n];

    books[0] = a; books[1] = b; books[2] = c; books[3] = d; books[4] = e; books[5] = f;

    for(size_t i=0;i<n;++i)
    {
        cout<<books[i]<<"\n";
    }

    Book p;
    cout<<"!p: "<<!p<<"\n\n";

    BookContainer bc(4);
    bc.insert(a);
    bc.insert(b);

    cout<<bc;

    delete[] books;
}
