#include <iostream>
#include "list.h"

using std::cin;
using std::cout;
using std::endl;


template<class T>
void dump(list<T> list)
{
    node<T>* p=list.begin();
    while(p!=list.end())
    {
        cout<<p->data<<' ';
        ++p;
    }
    cout<<endl;
}
int main()
{
    list<int> a;
    a.push_back(10);
    dump(a);
    return 0;
}
