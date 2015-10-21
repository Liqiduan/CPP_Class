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
    list<int> a,b(5,10);
    list<int> c(b.begin()->next(),b.end());

    int i=0;
    for(i=0;i<5;++i)
    {
        a.append(i);
    }

    a.resize(10);
    b.resize(2);

    dump(a);
    dump(b);
    dump(c);

    cout<<a.size()<<' '<<b.size()<<' '<<c.size()<<endl;

    a.assign();
    b.assign(5,1);
    c.assign(b.begin(),b.end());

    dump(a);
    dump(b);
    dump(c);

    cout<<a.size()<<' '<<b.size()<<' '<<c.size()<<endl;




    return 0;
}
