///
///@file list.h
///@brief Achieve the basic function of list in STL
///
///@version 1.0
///@author liqiduan(lee.nju@live.com)
///@date 0:31 10/22/2015
///

///         START   HERE    ///
#ifndef LIST_H
#define LIST_H

///The macro CREATE_DESTORY_COUNT help you to see how many node has been create
///and how many of them has been destroy
#define CREATE_DESTORY_COUNT

///For debug
#ifdef CREATE_DESTORY_COUNT
#include <iostream>
using namespace std;
#endif // CREATE_DESTORY_COUNT

#define NULL 0

///class node<T>
///@brief class of will be used to create a list.
///
template <typename T>
class node
{
public:
    node();
    ~node();
    node<T>* next();

    bool operator == (const node<T>& other) const;
    bool operator >  (const node<T>& other) const;
    bool operator >= (const node<T>& other) const;
    bool operator <  (const node<T>& other) const;
    bool operator <= (const node<T>& other) const;
    bool operator != (const node<T>& other) const;

//private:
    T data;
    node<T>* _prev;
    node<T>* _next;

    //friend class list<T>;
};

///class list<T>
///@brief body of list
template<typename T>
class list
{
public:
        ///@brief create a list
        list();

        ///@brief create a list contain n elements with data T
        ///@param n: how many node will be create
        ///@param t: the data of each node
        list(int n,T t);

        ///@brief create a list copy another list from q1 to q2 [q1,q2)
        ///@param q1: start
        ///@param q2: end
        ///@note this function will do nothing if q1 or q2 is NULL
        list(node<T>* q1,node<T>* q2);

        ~list();

        ///@brief assign a list
        void assign();

        ///@brief assign a list contain n elements with data T
        ///@param n: how many node will be create
        ///@param t: the data of each node
        void assign(int n,T t);

        ///@brief assign a list copy another list from q1 to q2 [q1,q2)
        ///@param q1: start
        ///@param q2: end
        ///@note this function will do nothing if q1 or q2 is NULL
        void assign(node<T>* q1,node<T>* q2);

        bool operator == (const list<T>& other) const;
        bool operator >  (const list<T>& other) const;
        bool operator >= (const list<T>& other) const;
        bool operator <  (const list<T>& other) const;
        bool operator <= (const list<T>& other) const;
        bool operator != (const list<T>& other) const;

        ///@brief return the head of a list
        node<T>* begin();
        const node<T>& begin() const;

        ///@brief return the end of a list
        node<T>* end();
        const node<T>& end() const;

        ///@brief return if the list is empty or not
        ///@return true:empty
        ///@return false:nonempty
        bool empty();

        ///@brief clear all the node in list
        void clear();
        ///@brief return the size of list
        int size();
        ///@brief swap this and other
        void swap(list& other);

        ///@brief insert a node before current
        node<T>* insert(node<T> *current, T value);
        ///@brief insert n node with value before current
        void insert(node<T> *current, int num, T value);
        void insert(node<T> *current, node<T> *q1, node<T> *q2);

        node<T>* erase(node<T> *current);
        node<T>* erase(node<T> *q1, node<T> *q2);//[q1,q2)

        void resize(int n);

        void push_back(T t);
        void push_front(T t);
        inline void append(T t) { this->push_back(t);}

        T pop_back();
        T pop_front();

        void splice(node<T>* current, list<T>& other);
        void splice(node<T> *current, list<T>& other, node<T> *t);
        void splice(node<T> *current, list<T>& other, node<T> *q1, node<T> *q2);

        list& operator=(const list<T>& other);
    protected:
    private:
        node<T> *_head , *_end;
        #ifdef COUNT
        int count;
        #endif
};


template <class T>
node<T>::node()
{

    data=0;
    _next=NULL;
    _prev=NULL;

    #ifdef CREATE_DESTORY_COUNT
    static int count=0;
    count++;
    cout<<"new node "<<count<<endl;
    #endif // CREATE_DESTORY_COUNT
}
template <class T>
node<T>* node<T>::next()
{
    return this->_next;
}
template <class T>
node<T>::~node()
{
    #ifdef CREATE_DESTORY_COUNT
    static int count=0;
    count++;
    cout<<"destroy node "<<count<<endl;
    #endif // CREATE_DESTORY_COUNT
}

template <class T>
bool node<T>::operator == (const node<T>& other) const
{
    return (this->data == other.data)?true:false;
}
template <class T>
bool node<T>::operator >  (const node<T>& other) const
{
    return (this->data > other.data)?true:false;
}
template <class T>
bool node<T>::operator >= (const node<T>& other) const
{
    return (this->data >= other.data)?true:false;
}
template <class T>
bool node<T>::operator <  (const node<T>& other) const
{
    return (this->data < other.data)?true:false;
}
template <class T>
bool node<T>::operator <= (const node<T>& other) const
{
    return (this->data <= other.data)?true:false;
}
template <class T>
bool node<T>::operator != (const node<T>& other) const
{
    return (this->data != other.data)?true:false;
}



template <typename T>
list<T>::list()
{
    #ifdef COUNT
    count=0;
    #endif // COUNT

    _end= new node<T>;
    _head=_end;
}
template <class T>
list<T>::list(int n,T t)
{
    #ifdef COUNT
    count=n;
    #endif // COUNT
    node<T> *p,*p1;
    int i=0;

    _end=new node<T>;
    _head=_end;

    if(n==0)
    {
        return;
    }

    p=new node<T>;
    p->data=t;
    p1=p;
    _head=p;

    for(i=1;i<n;++i)
    {
       p=new node<T>;

       p->data=t;
       p->_prev=p1;
       p1->_next=p;

       p1=p;
    }

    p->_next=_end;
    _end->_prev=p;

}
template <class T>
list<T>::list(node<T>* q1,node<T>* q2)
{
    _end=new node<T>;
    _head=_end;

    if( (q1==NULL)||(q2==NULL) )
    {
        return;
    }

    node<T> *p,*p1;
    p=new node<T>;
    p->data=q1->data;
    p1=p;
    _head=p;
    q1=q1->_next;

    while(q1!=q2)
    {
       p=new node<T>;

       p->data=q1->data;
       p->_prev=p1;
       p1->_next=p;

       p1=p;
       q1=q1->_next;
    }

    p->_next=_end;
    _end->_prev=p;
}
template <class T>
list<T>::~list()
{
    clear();
    delete _end;
}
template <class T>
void list<T>::assign()
{
    clear();
}
template <class T>
void list<T>::assign(int n,T t)
{
    clear();

    node<T> *p,*p1;
    int i=0;

    if(n==0)
    {
        return;
    }

    p=new node<T>;
    p->data=t;
    p1=p;
    _head=p;

    for(i=1;i<n;++i)
    {
       p=new node<T>;

       p->data=t;
       p->_prev=p1;
       p1->_next=p;

       p1=p;
    }

    p->_next=_end;
    _end->_prev=p;

}
template <class T>
void list<T>::assign(node<T>* q1,node<T>* q2)
{

    if( (q1==NULL)||(q2==NULL) )
    {
        return;
    }

    clear();
    node<T> *p,*p1;
    p=new node<T>;
    p->data=q1->data;
    p1=p;
    _head=p;
    q1=q1->_next;

    while(q1!=q2)
    {
       p=new node<T>;

       p->data=q1->data;
       p->_prev=p1;
       p1->_next=p;

       p1=p;
       q1=q1->_next;
    }

    p->_next=_end;
    _end->_prev=p;
}

template <class T>
list<T>& list<T>::operator=(const list& other)
{
}

template <class T>
bool list<T>::operator == (const list<T>& other) const
{
    node<T> *p1,*p2;
    p1=_head;
    p2=other._head;

    while((p1!=_end)&&(p2!=other._end))
    {
        if(p1->data != p2->data)
        {
            return false;
        }
        p1=p1->_next;
        p2=p2->_next;
    }

    if( (p1==_end) && (p2==other._end))
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class T>
bool list<T>::operator >  (const list<T>& other) const
{
    node<T> *p1,*p2;
    int flag=0;
    p1=_head;
    p2=other._head;

    while((p1!=_end)&&(p2!=other._end))
    {
        if(p1->data < p2->data)
        {
            return false;
        }
        if(p1->data != p2->data)
        {
            flag=0;
        }

        p1=p1->_next;
        p2=p2->_next;
    }

    if((p2==other._end))
    {
        if((flag==1)&&(p1=_end))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}
template <class T>
bool list<T>::operator >= (const list<T>& other) const
{
    node<T> *p1,*p2;
    p1=_head;
    p2=other._head;

    while((p1!=_end)&&(p2!=other._end))
    {
        if(p1->data < p2->data)
        {
            return false;
        }

        p1=p1->_next;
        p2=p2->_next;
    }

    if((p2==other._end))
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class T>
bool list<T>::operator <  (const list<T>& other) const
{
    node<T> *p1,*p2;
    int flag=0;
    p1=_head;
    p2=other._head;

    while((p1!=_end)&&(p2!=other._end))
    {
        if(p1->data > p2->data)
        {
            return false;
        }
        if(p1->data != p2->data)
        {
            flag=0;
        }

        p1=p1->_next;
        p2=p2->_next;
    }

    if((p1==_end))
    {
        if((flag==1)&&(p2=_end))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}
template <class T>
bool list<T>::operator <= (const list<T>& other) const
{
        node<T> *p1,*p2;
    p1=_head;
    p2=other._head;

    while((p1!=_end)&&(p2!=other._end))
    {
        if(p1->data > p2->data)
        {
            return false;
        }

        p1=p1->_next;
        p2=p2->_next;
    }

    if((p2==other._end))
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class T>
bool list<T>::operator != (const list<T>& other) const
{
      node<T> *p1,*p2;
    p1=_head;
    p2=other._head;

    while((p1!=_end)&&(p2!=other._end))
    {
        if(p1->data != p2->data)
        {
            return false;
        }
        p1=p1->_next;
        p2=p2->_next;
    }

    if( (p1==_end) && (p2==other._end))
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <class T>
node<T>* list<T>::begin()
{
    return _head;
}
template <class T>
const node<T>& list<T>::begin() const
{
    return *_head;
}
template <class T>
node<T>* list<T>::end()
{
    return _end;
}
template <class T>
const node<T>& list<T>::end() const
{
    return *_end;
}

template <class T>
bool list<T>::empty()
{
    if(_head==_end)
    {
        return true;
    }
}
template <class T>
void list<T>::clear()
{
    node<T>* p=_head;

    while(p!=_end)
    {
        p=p->_next;
        delete p->_prev;
    }
    _head=_end;
}
template <class T>
int list<T>::size()
{
    node<T>* p=_head;
    int n=0;
    while(p!=_end)
    {
        p=p->_next;
        ++n;
    }
    return n;
}
template <class T>
void list<T>::swap(list& other)
{
    node<T> *p;

    p=_end;
    _end=other._end;
    other._end=p;

    p=_head;
    _head=other._head;
    other._head=p;
}

template <class T>
node<T>* list<T>::insert(node<T> *current, T value)
{
    if(current==NULL)
    {
        return NULL;
    }

    node<T> *p=new node<T>;

    p->data=value;
    p->_next=current;
    p->_prev=current->_prev;

    if(current->_prev!=NULL)
    {
        current->_prev->_next=p;
    }
    current->_prev=p;

    if(current==_head)
    {
        _head=p;
    }
}
template <class T>
void list<T>::insert(node<T> *current, int num, T value)
{
    if((current==NULL)||(num==0))
    {
        return ;
    }

    node<T> *p1,*p2,*h;
    int i;

    h=new node<T>;
    h->data=value;
    p2=h;

    for(i=1;i<num;++i)
    {
        p1=new node<T>;
        p1->data=value;
        p1->_prev=p2;
        p2->_next=p1;
        p2=p1;
    }

    if(current==_head)
    {
        _head=h;
    }
    else
    {
        current->_prev->_next=h;
    }

    h->_prev=current->_prev;
    current->_prev=p2;
    p2->_next=current;
}
template <class T>
void list<T>::insert(node<T> *current, node<T> *q1, node<T> *q2)
{
    if((current==NULL)||(q1==NULL)||(q2==NULL))
    {
        return ;
    }

    node<T> *p1,*p2,*h;
    int i;

    h=new node<T>;
    h->data=q1->data;
    p2=h;
    q1=q1->next();

    while(q1!=q2)
    {
        p1=new node<T>;
        p1->data=q1->data;
        p1->_prev=p2;
        p2->_next=p1;
        p2=p1;
        q1=q1->next();
    }

    if(current==_head)
    {
        _head=h;
    }
    else
    {
        current->_prev->_next=h;
    }

    h->_prev=current->_prev;
    current->_prev=p2;
    p2->_next=current;
}

template <class T>
node<T>* list<T>::erase(node<T> *current)
{
    if(NULL==current)
    {
        return NULL;
    }

    node<T> *p=current->_next;

    if(current->_prev!=NULL)
    {
        current->_prev->_next=current->_next;
    }
    else
    {
        _head=current->_next;
    }
    current->_next->_prev=current->_prev;

    delete current;
    return p;
}
template <class T>
node<T>* list<T>::erase(node<T> *q1, node<T> *q2)//[q1,q2)
{
    if((NULL==q1)||(NULL==q2))
    {
        return NULL;
    }

    if(q1->_prev!=NULL)
    {
        q1->_prev->_next=q2;
    }
    else
    {
        _head=q2;
    }
    q2->_prev=q1->_prev;

    node<T>* p;

    while(p!=q2)
    {
        p=q1->_next;
        delete q1;
        q1=p;
    }
    return q2;
}

template <class T>
void list<T>::resize(int n)
{
    if(n==0)
    {
        clear();
        return;
    }

    node<T> *p1,*p=_head;
    while((p!=_end)&&(n>0))
    {
        p=p->_next;
        --n;
    }

    if(p==_end)
    {
        p=p->_prev;
        while(n>0)
        {
            p1=new node<T>;
            p->_next=p1;
            p1->_prev=p;
            p=p1;
            --n;
        }
        p->_next=_end;
        _end->_prev=p;

    }
    else
    {
        p->_prev->_next=_end;
        _end->_prev=p->_prev;

        while(p!=_end)
        {
            p1=p;
            p=p->_next;
            delete p1;
        }
    }
}

template <class T>
void list<T>::push_back(T t)
{
    node<T>* p=new node<T>;

    p->data=t;
    p->_next=_end;
    p->_prev=_end->_prev;

    if(_end!=_head)
    {
        _end->_prev->_next=p;
    }
    else
    {
        _head=p;
    }
    _end->_prev=p;
}
template <class T>
void list<T>::push_front(T t)
{
    node<T> *p=new node<T>;
    p->data=t;
    p->_next=_head;

    _head->_prev=p;
    _head=p;
}

template <class T>
T list<T>::pop_back()
{
    T temp;
    node<T> *p;

    if(_head==_end)
    {
        return 0;
    }

    p=_end->_prev;
    temp=p->data;

    if(p->_prev!=NULL)
    {
        p->_prev->_next=_end;
        _end->_prev=p->_prev;
    }
    else
    {
        _head=_end;
        _end->_prev=NULL;
    }

    delete p;
    return temp;
}
template <class T>
T list<T>::pop_front()
{
    T temp;
    node<T>* p;

    if(_head==_end)
    {
        return 0;
    }

    p=_head;
    _head=_head->_next;
    _head->_prev=NULL;

    delete p;
    return temp;
}

template <class T>
void list<T>::splice(node<T>* current, list<T>& other)
{
    if(current==_head)
    {
        return;
    }

    current->_prev->_next=other._head;
    current->_prev=other._end->_prev;

    other._head->_prev=current->_prev;
    other._end->_prev->_next=current;

    other._end=new node<T>;
    other._head=other._end;
    return ;
}
template <class T>
void list<T>::splice(node<T> *current, list<T>& other, node<T> *t)
{
    if(current==_head)
    {
        return;
    }

    if(t->_prev==NULL)
    {
        other._head=t->_next;
    }
    else
    {
        t->_prev->_next=t->_next;
    }
    t->_next->_prev=t->_prev;

    current->_prev->_next=t;
    t->_prev=current->_prev;

    t->_next=current;
    current->_prev=t;
}
template <class T>
void list<T>::splice(node<T> *current, list<T>& other, node<T> *q1, node<T> *q2)
{
    if(current==_head)
    {
        return;
    }

    if(q1->_prev!=NULL)
    {
        q1->_prev->_next=q2;
    }
    else
    {
        other._head=q2;
    }


    current->_prev->_next=q1;
    current->_prev=q2->_prev;

    q1->_prev=current->_prev;
    q2->_prev->_next=current;

    q2->_prev=q1;
    return ;
}

#endif // LIST_H

///         END OF FILE     ///
