#pragma once

#include <iostream>

template <typename T>
class Set
{

friend std::ostream& operator<<(std::ostream& out, const Set<T>& s)
{
    for(int i=0;i<s.getSetSize();++i)
    {
        out<<(T)s[i]<<"\n";
    }
    out<<"\n";
    return out;
}

public:
    Set(int cap = 2);
    Set(const Set&);
    Set& operator=(const Set&);
    virtual ~Set();

    void copy(const Set&);
    void destroy();

    int getSetCapacity() const {return capacity;}
    int getSetSize() const {return size;}

    void insert(const T&);
    void remove(const T&);

    bool isEmpty();

    const void print();

    const T& operator[](unsigned int idx) const;

    bool has(const T&) const;
private:
    T** objects;
    int capacity;
    int size;

    void resizeUp();
    void resizeDown();
};

template <typename T>
void Set<T>::destroy()
{
    if (objects!=nullptr)
    {
        size=0;
        delete objects;
    }
}

template <typename T>
void Set<T>::copy(const Set<T>& b)
{
    if(this->objects!=nullptr) destroy();
    this->objects = new T*[b.getSetSize()];
    for(size_t i=0;i<b.getSetSize();++i)
    {
        this->objects[i] = b.objects[i];
    }
    this->size = b.getSetSize();
    this->capacity = b.getSetCapacity();

}

template <typename T>
Set<T>::Set(int cap)
{
    if(cap<5) cap=5;
    capacity=5;
    T** obj = new T*[cap];
    size = 0;
    objects = obj;
}

template <typename T>
Set<T>::Set(const Set<T>& b)
{
    this->copy(b);
}

template <typename T>
Set<T>& Set<T>::operator=(const Set<T>& b)
{
    if(this!=&b)
        this->copy(b);
    return *this;
}

template <typename T>
Set<T>::~Set()
{
    destroy();
}

template <typename T>
void Set<T>::resizeUp()
{
    T** temp = new T*[this->getSetSize()];
    for(size_t i = 0; i<this->getSetSize(); ++i)
    {
        temp[i] = this->objects[i];
    }
    destroy();
    objects = new T*[this->capacity*2];
    for(size_t i = 0; i<this->getSetSize(); ++i)
    {
        this->objects[i] = temp[i];
    }
    this->capacity*=2;
}

template <typename T>
void Set<T>::resizeDown()
{
    for(int i=capacity/2;i<=capacity;++i)
    {
        delete this->objects[i];
    }
    capacity=capacity/2;
}

template <typename T>
void Set<T>::insert(const T& b)
{
    if(this->has(b)) return;
    if(size==capacity) resizeUp();
    objects[size] = new T(b);
    ++size;
}

template <typename T>
bool Set<T>::isEmpty()
{
    return (size==0);
}

template <typename T>
const T& Set<T>::operator[](unsigned int idx) const
{
    if(idx<size)
        return *objects[idx];
    T a;
    return a;
}

template <typename T>
const void Set<T>::print()
{
    std::cout<<*this;
}

template <typename T>
bool Set<T>::has(const T& obj) const
{
    for(int i=0;i<this->getSetSize();++i)
        if(*this->objects[i]==obj) return true;
    return false;
}

template <typename T>
void Set<T>::remove(const T& obj)
{
    if(!this->has(obj)) return;
    int j=0;
    for(int i=0;i<this->getSetSize();++i)
        if(*this->objects[i]==obj) j=i;

    for(int i=j;i<this->getSetSize()-1;++i)
    {
        this->objects[i] = this->objects[i+1];
    }
    size--;
    if(size<capacity/2) resizeDown();
}

