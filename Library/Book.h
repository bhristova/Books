#ifndef BOOK_H_
#define BOOK_H_

#include <iostream>
#include <cstring>

enum Genre { horror, fantasy, adventure, mythology, scifi, dystopian, unknown};

class Author;

class Book
{
friend std::ostream& operator<<(std::ostream& out, const Book& b)
{
    std::cout<<"Title: "<<b.getTitle()<<"\nPages: "<<b.getPages()<<"\nYear: "<<b.getYear()<<"\n"<<"Genre: "<<b.getGenre()<<"\nPrice: "<<b.getPrice()<<"\n";
    return out;
}

friend std::istream& operator>>(std::istream& in, Book& b)
{
    char ttl[100];
    int pgs;
    int y;
    char gchar[100];
    Genre ggenre;
    double prc;

    std::cout<<"Input title of book: ";
    std::cin.getline(ttl,100);
    std::cout<<"Input count of pages in book: ";
    in>>pgs;
    std::cout<<"Input year of publishing: ";
    in>>y;
    std::cin.ignore();
    std::cout<<"Input genre of book: ";
    in>>gchar;
    std::cout<<"Input price of book: ";
    in>>prc;

    if (!strcmp(gchar,"horror")) ggenre = horror;
    if (!strcmp(gchar,"fantasy")) ggenre = fantasy;
    if (!strcmp(gchar,"adventure")) ggenre = adventure;
    if (!strcmp(gchar,"mythology")) ggenre = mythology;
    if (!strcmp(gchar,"scifi")) ggenre = scifi;
    if (!strcmp(gchar,"dystopian")) ggenre = dystopian;
    else ggenre = unknown;

    b.setTitle(ttl);
    b.setPages(pgs);
    b.setYear(y);
    b.setAuthor(nullptr);
    b.setGenre(ggenre);
    b.setPrice(prc);

    return in;
}

public:
    Book(const char* t = "", int pg = 1, int yr = 1000, Author* a = NULL, const Genre& g = unknown, double pr = 0.0);
    Book(const Book&);
    Book& operator=(const Book&);
    ~Book();

    void setTitle(const char* t);
    void setPages(int pg);
    void setYear(int yr);
    void setAuthor(Author* a);
    void setGenre(const Genre& g);
    void setPrice(double pr);

    const char* getTitle() const {return title;}
    int getPages() const {return pages;}
    int getYear() const {return year;}
    Author* getAuthor() const {return author;}
    Genre getGenre() const {return genre;}
    double getPrice() const {return price;}

    const void print();

    bool operator<(const Book& p) const;
    bool operator>(const Book& p) const;
    bool operator<=(const Book& p) const;
    bool operator>=(const Book& p) const;
    bool operator!=(const Book& p) const;
    bool operator==(const Book& p) const;

    operator bool() const;
    bool operator!() const;

private:
    char* title;
    int pages;
    int year;
    Author* author;
    Genre genre;
    double price;
};

#endif // BOOK_H_
