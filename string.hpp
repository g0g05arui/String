#ifndef STRING_HPP
#define STRING_HPP
#include "string.h"
String::String()
{
    _size=_capacity=0;
    s=new char[1];
}
String::String(int __capacity)
{
    _capacity=__capacity;
    _size=0;
    s=new char[__capacity+1];
}
String::String(int __capacity,char x)
{
    _capacity=_size=__capacity;
    s=new char[_size+1];
    for(int i=0; i<_size; i++)
        s[i]=x;
}
int String::size()
{
    return _size;
}
int String::capacity()
{
    return _capacity;
}
char &String::operator [](int x)
{
    return s[x];
}
void String::pop_front()
{
    s++;
}
void String::pop_back()
{
    _size--;
}
void String::reserve(int x)
{
    char *aux;
    aux=new char [_capacity+x+1];
    _capacity+=x;
    for(int i=0; i<_size; i++)
        aux[i]=s[i];
    delete[]s;
    s=aux;
}
void String::push_back(char x)
{
    if(_size<_capacity)
        s[_size++]=x;
    else
    {
        reserve(_size);
        s[_size++]=x;
    }
}
void String::insert(int poz,char x)
{
    if(_size==_capacity)
        reserve(_capacity);
    char *aux=new char[_capacity+1];
    for(int i=0; i<poz; i++)
        aux[i]=s[i];
    aux[poz]=x;
    for(int i=poz+1; i<=_size; i++)
        aux[i]=s[i-1];
    delete []s;
    s=aux;
    _size++;
}
void String::insert(int poz,String sa)
{
    if(_size+sa.size()<_capacity)
        reserve(std::max(_size,sa.size()));
    char *aux=new char[_capacity+1];
    _size+=sa.size();
    for(int i=0; i<poz; i++)
        aux[i]=s[i];
    for(int i=0; i<sa.size(); i++)
        aux[i+poz]=sa[i];
    for(int i=poz; i<_size; i++)
        aux[i+sa.size()]=s[i];
    delete[]s;
    s=aux;
}
void String::insert(int poz,char *aux)
{
    String x(aux);
    insert(poz,x);
}
void String::erase(int poz)
{
    char *aux;
    aux=new char[_capacity];
    for(int i=0; i<poz; i++)
        aux[i]=s[i];
    for(int i=poz+1; i<_size; i++)
        aux[i-1]=s[i];
    delete[]s;
    s=aux;
    _size--;
}
void String::erase(int begin,int end)
{
    char *aux;
    aux=new char[_capacity];
    for(int i=0; i<begin; i++)
        aux[i]=s[i];
    for(int i=end; i<_size; i++)
        aux[i-1]=s[i];
    delete[]s;
    s=aux;
    _size--;
}
String::String(const String &aux)
{
    *this=aux;
}
String::String(const char *aux)
{
    _capacity=_size=strlen(aux);
    s=(char *)aux;
}
char * String::c_str(){
    return s;
}
void operator << (std::ofstream & aux,String s)
{
    aux<<s.c_str();
}
void operator << (std::ostream & aux,String s)
{
    aux<<s.c_str();
}
char *String::begin(){
    return &s[0];
}
char *String::end(){
    return &s[_size-1];
}
#endif // STRING_HPP
