#ifndef LIST_H
#define LIST_H

#define DEBUG

#ifdef DEBUG
#include <stdio.h>
using namespace std;
#endif // DEBUG

template <class T>
class list_node
{
public:
    list_node();
    list_node(T a);
    ~list_node();

//private:
    T _data;
    list_node<T> *_next;
    list_node<T> *_prev;
};

template <class T>
class list_iter
{
public:
    list_iter<T> operator ++(int)
    {
        list_iter<T> temp=*this;
        this->_self=this->_self->_next;
        return temp;
    }
    list_iter<T> operator ++()
    {
        this->_self=this->_self->_next;
        return *this;
    }
    list_iter<T> operator --(int)
    {
        list_iter<T> temp=*this;
        this->_self=this->_self->_prev;
        return temp;
    }
    list_iter<T> operator --()
    {
        this->_self=this->_self->_prev;
        return *this;
    }
    T* operator ->() const
    {
        return &(this->_self->_data);
    }
    T& operator *()
    {
        return this->_self->_data;
    }
    bool operator !=(list_iter<T> other)
    {
        return (this->_self==other._self)?0:1;
    }
    bool operator ==(list_iter<T> other)
    {
        return (this->_self==other._self)?1:0;
    }
//private:
    list_node<T> *_self;

};

template <class T>
class list
{
public:
    typedef list_iter<T> iterator ;

    list()
    {
        _end._self=new list_node<T>;
        _head=_end;
    }
    list(int n)
    {
        _end._self=new list_node<T>;
        _head=_end;

        if(n==0)
        {
            return;
        }

        int i=0;
        list_node<T>* p=new list_node<T>;
        _head._self=p;

        for(i=1;i<n;i++)
        {
            p->_next=new list_node<T>;
            p->_next->_prev=p;
            p=p->_next;
        }
        p->_next=_end._self;
        _end._self->_prev=p;
    }
    list(int n,T t)
    {
        _end._self=new list_node<T>;
        _head=_end;

        if(n==0)
        {
            return;
        }

        int i=0;
        list_node<T>* p=new list_node<T>(t);
        _head._self=p;

        for(i=1;i<n;i++)
        {
            p->_next=new list_node<T>(t);
            p->_next->_prev=p;
            p=p->_next;
        }
        p->_next=_end._self;
        _end._self->_prev=p;
    }
    list(iterator q1,iterator q2)
    {
        list_node<T>* p=new list_node<T>;
        _head._self=p;

        while(q1!=q2)
        {
              p->_data=*q1;
            p->_next=new list_node<T>;
            p->_next->_prev=p;
            p=p->_next;
            ++q1;
        }
        _end._self=p;
    }

    ~list()
    {
        clear();
        delete _end._self;
    }

    void assign(int n);
    void assign(int n, T t);
    void assign(iterator q1, iterator q2);

    iterator begin()
    {
        return _head;
    }
    iterator end()
    {
        return _end;
    }
    void clear()
    {
        while(_head!=_end)
        {
            delete (_head++)._self;
        }
    }
    bool empty()
    {
        return (_head==_end)?1:0;
    }
    int size()
    {
        int count=0;
        iterator i=_head;
        while(i!=_end)
        {
            ++i;
            ++count;
        }
        return count;
    }

    iterator insert(iterator current, T t)
    {
        if(empty())
        {
            return current;
        }

        if(current==_head)
        {
            list_node<T>* p=new list_node<T>(t);
            p->_prev=current._self->_prev;
            p->_next=current._self;
            current._self->_prev=p;
            _head._self=p;
            return _head;
        }
        else
        {
            iterator temp;
            list_node<T>* p=new list_node<T>(t);
            p->_prev=current._self->_prev;
            p->_next=current._self;
            current._self->_prev=p;
            current._self->_prev->_next=p;
            temp._self=p;
            return temp;
        }
    }
    iterator append(T t)
    {
        if(_head==_end)
        {
            _head._self=new list_node<T>(t);
            _head._self->_next=_end._self;
            _end._self->_prev=_head._self;
        }
        else
        {
            _end._self->_data=t;
            _end._self->_next=new list_node<T>;
            _end._self->_next->_prev=_end._self;
            _end._self=_end._self->_next;
        }
    }
    iterator remove(iterator current)
    {
        if(current==_end)
        {
            return _end;
        }
        if(current==_head)
        {
            iterator temp;
            _head._self=current._self->_next;
            temp._self=current._self->_next;
            current._self->_next->_prev=current._self->_prev;
            delete current._self;
            return temp;
        }
        else
        {
            iterator temp;
            temp._self=current._self->_next;
            current._self->_prev->_next=current._self->_next;
            current._self->_next->_prev=current._self->_prev;
            delete current._self;
            return temp;
        }
    }

private:
    iterator _head;
    iterator _end;
};

template <class T>
list_node<T>::list_node():_data(),_next(NULL),_prev(NULL)
{
    #ifdef DEBUG
    static int count=0;
    ++count;
    cout<<"new a"<<count<<endl;
    #endif // debug
}

template <class T>
list_node<T>::list_node(T a):_data(a),_next(NULL),_prev(NULL)
{
    #ifdef DEBUG
    static int count=0;
    ++count;
    cout<<"new b"<<count<<endl;
    #endif // debug
}

template <class T>
list_node<T>::~list_node()
{
    #ifdef DEBUG
    static int count=0;
    ++count;
    cout<<"delete"<<count<<endl;
    #endif // debug
}





#endif // LIST_H
