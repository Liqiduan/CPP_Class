#include <iostream>
#include "list.h"

using std::cin;
using std::cout;
using std::endl;


template<class T>
void dump(list<T>& list)
{
    node<T>* p=list.begin();
    while(p!=list.end())
    {
        cout<<p->data<<' ';
        p=p->next();
    }
    cout<<endl;
}
int main()
{
    list<int> a(5,10),b(5,10);
    a.append(1);

    dump(b);
    cout<<(a > b);
    return 0;
}
