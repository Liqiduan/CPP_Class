#ifndef LIST_H
#define LIST_H

#define NULL 0
template <typename T>
class node
{
public:
    node();

    bool operator == (const node<T>& other) const;
    bool operator >  (const node<T>& other) const;
    bool operator >= (const node<T>& other) const;
    bool operator <  (const node<T>& other) const;
    bool operator <= (const node<T>& other) const;
    bool operator != (const node<T>& other) const;

    node<T>*  operator ++();
//private:
    T data;
    node<T>* prev;
    node<T>* next;

    //friend class list<T>;
};

template<typename T>
class list
{
public:
        list();
        list(int n,T t);
        list(node<T>* q1,node<T>* q2);
        virtual ~list();

        void assign();
        void assign(int n,T t);
        void assign(node<T>* q1,node<T>* q2);

        bool operator == (const list<T>& other) const;
        bool operator >  (const list<T>& other) const;
        bool operator >= (const list<T>& other) const;
        bool operator <  (const list<T>& other) const;
        bool operator <= (const list<T>& other) const;
        bool operator != (const list<T>& other) const;

        node<T>* begin();
        const node<T>& begin() const;
        node<T>* end();
        const node<T>& end() const;

        bool empty();
        void clear();
        int size();
        void swap(list& other);

        node<T>* insert(node<T> *current, T value);
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

        void splice(node<T>* current, list& other);
        void splice(node<T> *current, list& other, node<T> *t);
        void splice(node<T> *current, list& other, node<T> *q1, node<T> *q2);

        list& operator=(const list& other);
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
    next=NULL;
    prev=NULL;
}
template <class T>
bool node<T>::operator == (const node<T>& other) const
{
    return (this.data == other.data)?true:false;
}
template <class T>
bool node<T>::operator >  (const node<T>& other) const
{
    return (this.data > other.data)?true:false;
}
template <class T>
bool node<T>::operator >= (const node<T>& other) const
{
    return (this.data >= other.data)?true:false;
}
template <class T>
bool node<T>::operator <  (const node<T>& other) const
{
    return (this.data < other.data)?true:false;
}
template <class T>
bool node<T>::operator <= (const node<T>& other) const
{
    return (this.data <= other.data)?true:false;
}
template <class T>
bool node<T>::operator != (const node<T>& other) const
{
    return (this.data != other.data)?true:false;
}
template <class T>
node<T>* node<T>::operator ++ ()
{
    if(this!=NULL)
    {
        this=this.next;
    }
    return this;
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
    _end=new node<T>;
    _head=_end;

   int i=0;
   for(i=0;i<n;++i)
   {
       append(t);
   }
}

template <class T>
list<T>::list(node<T>* q1,node<T>* q2)
{
    #ifdef COUNT
     count=0;
     #endif // COUNT
    _end=new node<T>;
    _head=_end;

    while(q1!=q2)
    {
        append(q1);
        ++q1;
        #ifdef COUNT
        ++count;
        #endif // COUNT
    }
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
}
template <class T>
void list<T>::assign(int n,T t)
{
}
template <class T>
void list<T>::assign(node<T>* q1,node<T>* q2)
{
}

template <class T>
list<T>& list<T>::operator=(const list& other)
{
}

template <class T>
bool list<T>::operator == (const list<T>& other) const
{
}
template <class T>
bool list<T>::operator >  (const list<T>& other) const
{
}
template <class T>
bool list<T>::operator >= (const list<T>& other) const
{
}
template <class T>
bool list<T>::operator <  (const list<T>& other) const
{
}
template <class T>
bool list<T>::operator <= (const list<T>& other) const
{
}
template <class T>
bool list<T>::operator != (const list<T>& other) const
{
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
}
template <class T>
int list<T>::size()
{
}
template <class T>
void list<T>::swap(list& other)
{
}

template <class T>
node<T>* list<T>::insert(node<T> *current, T value)
{
}
template <class T>
void list<T>::insert(node<T> *current, int num, T value)
{
}
template <class T>
void list<T>::insert(node<T> *current, node<T> *q1, node<T> *q2)
{
}

template <class T>
node<T>* list<T>::erase(node<T> *current)
{
}
template <class T>
node<T>* list<T>::erase(node<T> *q1, node<T> *q2)//[q1,q2)
{
}

template <class T>
void list<T>::resize(int n)
{
}

template <class T>
void list<T>::push_back(T t)
{
    node<T>* p=new node<T>;

    p->data=t;
    p->next=_end;
    p->prev=_end->prev;

    if(_end!=_head)
    {
        _end->prev->next=p;
    }
    else
    {
        _head=p;
    }
    _end->prev=p;
}
template <class T>
void list<T>::push_front(T t)
{
}

template <class T>
T list<T>::pop_back()
{
}
template <class T>
T list<T>::pop_front()
{
}

template <class T>
void list<T>::splice(node<T>* current, list& other)
{
}
template <class T>
void list<T>::splice(node<T> *current, list& other, node<T> *t)
{
}
template <class T>
void list<T>::splice(node<T> *current, list& other, node<T> *q1, node<T> *q2)
{
}

#endif // LIST_H
