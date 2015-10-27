#ifndef LIST_H
#define LIST_H

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
    list_iter operator ++();
    list_iter operator ++(int);
    list_iter operator --();
    list_iter operator --(int);

    T& operator *();
    list_node<T>* operator->() const
    {
        return (this->_self);
    }
    list_node<T>& operator *(int);
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
        _end=new iterator;
        _head=_end;
        _end._self=new list_node<T>;
    }
    list(int n)
    {
        _end=new iterator;
        _head=_end;
        _end._self=new list_node<T>;

        if(n==0)
        {
            return;
        }

        int i=0;
        list_node<T>* p=new list_node<T>;
        _head=p;

        for(i=1;i<n;i++)
        {
            p->_next=new list_node<T>;
            p->_next->_prev=p;
            p=p->_next;
        }
        p->_next=_end;
        _end->_prev=p;
    }
    list(int n,T t);
    list(iterator q1,iterator q2);

    ~list();

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
    void clear();
    bool empty();
    int size();

    iterator insert(iterator current, T t);
    iterator append(T t);
    iterator remove(T t);

private:
    iterator _head;
    iterator _end;
};

template <class T>
list_node<T>::list_node():_data(10),_next(NULL),_prev(NULL)
{
}

template <class T>
list_node<T>::list_node(T a):_data(a),_next(NULL),_prev(NULL)
{

}

template <class T>
list_node<T>::~list_node()
{
    #ifdef debug
    static int count=0;
    ++count;
    cout<<count<<endl;
    #endif // debug
}

template <class T>
list_iter<T> list_iter<T>::operator ++()
{
    list_iter<T> temp=*this;
    this->_self=this->_self->_next;
    return temp;
}
template <class T>
list_iter<T> list_iter<T>::operator ++(int)
{
    this->_self=this->_self->_next;
    return *this;
}
template <class T>
list_iter<T> list_iter<T>::operator --()
{
    list_iter<T> temp=*this;
    this->_self=this->_self->_prev;
    return temp;
}
template <class T>
list_iter<T> list_iter<T>::operator --(int)
{
    this->_self=this->_self->_prev;
    return *this;
}

template <class T>
T& list_iter<T>::operator *()
{
    return this->_self->_data;
}

#endif // LIST_H
