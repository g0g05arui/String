#ifndef STRING_DEF
#define STRING_DEF
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
class String{
private:
    char *s;
    int _size,_capacity;
public:
    String();
    String(int);
    String(int,char);
    String(const String&);
    String(const char *aux);
    void push_back(char);
    int size();
    int capacity();
    void insert(int,char);
    void insert(int,String);
    void insert(int,char *);
    void erase(int);
    void erase(int,int);
    void pop_back();
    void pop_front();
    char & operator [](int);
    void reserve(int);
    char *c_str();
    typedef  char* iterator;
    iterator begin();
    iterator end();
};

#include "string.hpp"
#endif // STRING_DEF
