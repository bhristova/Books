#ifndef AUTHOR_H_
#define AUTHOR_H_

#include <iostream>

class Author
{
friend std::ostream& operator<<(std::ostream& out, const Author& a)
{
    std::cout<<"Name: "<<a.getName()<<"\nCount of books: "<<a.getCount()<<"\nNationality: "<<a.getNat()<<"\n";
    return out;
}

friend std::istream& operator>>(std::istream& in, Author& a)
{
    char nm[100];
    int cnt;
    char nt[100];

    std::cout<<"Input name of author: ";
    std::cin.getline(nm,100);
    std::cout<<"Input count of books by author: ";
    in>>cnt;
    std::cout<<"Input nationality of author: ";
    in>>nt;

    a.setName(nm);
    a.setCount(cnt);
    a.setNat(nt);

    return in;
}

public:
    Author(const char* nm = "Untitled", int c = 1, const char* nt = "Unknown");
    Author(const Author&);
    Author& operator=(const Author&);
    ~Author();

    void setName(const char*);
    void setCount(int);
    void setNat(const char*);

    const char* getName() const {return name;}
    int getCount() const {return count;}
    const char* getNat() const {return nat;}

    void print();

    bool operator<(const Author& p) const;
    bool operator>(const Author& p) const;
    bool operator<=(const Author& p) const;
    bool operator>=(const Author& p) const;
    bool operator!=(const Author& p) const;
    bool operator==(const Author& p) const;

private:
    char* name;
    int count;
    char* nat;
};

#endif // AUTHOR_H_
