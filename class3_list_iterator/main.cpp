#include <iostream>
#include "list.h"

using namespace std;

template<class T>
void dump(list<T> a)
{
    typename list<T>::iterator b;
    b=a.begin();
    while(b!=a.end())
    {
        cout<<*b<<' ';
        b++;
    }
    cout<<endl;
}

class A
{
public:
    int a;
    A()
    {

    }
    A(int b):a(b)
    {

    }
};

int main()
{
    list<int> a(10,10);
    cout<<*(++a.begin());
    a.insert(a.begin(),8);
    a.insert(a.end(),7);
    a.append(10);
    dump(a);
}
