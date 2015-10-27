#include <iostream>
#include "list.h"

using namespace std;

template<class T>
void dump(list<T> a)
{
    list<T>::iterator b;
    b=a.head();
    while(b!=a.end())
    {
        cout<<b->_data<<' ';
    }
    cout<<endl;
}

int main()
{

    return 0;
}
