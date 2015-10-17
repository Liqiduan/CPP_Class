#include "list.h"

list()
{
}
list(int n,T t)
{
}
list(node<T>* q1,node<T>* q2)
{
}
virtual ~list()
{
}

void assign()
{
}
void assign(int n,T t)
{
}
void assign(node<T>* q1,node<T>* q2)
{
}

list& operator=(const list& other){
}

bool operator == (const list<T>& other) const
{
}
bool operator >  (const list<T>& other) const
{
}
bool operator >= (const list<T>& other) const
{
}
bool operator <  (const list<T>& other) const
{
}
bool operator <= (const list<T>& other) const
{
}
bool operator != (const list<T>& other) const
{
}

list* begin()
{
}
const list& begin() const
{
}
list* end()
{
}
const list& end() const
{
}

bool empty()
{
}
void clear()
{
}
int size()
{
}
void swap(list& other)
{
}

node<T>* insert(node<T> *current, T value)
{
}
void insert(node<T> *current, int num, T value)
{
}
void insert(node<T> *current, node<T> *q1, node<T> *q2)
{
}

node<T>* erase(node<T> *current)
{
}
node<T>* erase(node<T> *q1, node<T> *q2)//[q1,q2)
{
}

void resize(int n)
{
}

void push_back(T t)
{
}
void push_front(T t)
{
}
inline void append(T t) { this.push_back(t)}
{
}

T pop_back()
{
}
T pop_front()
{
}

void splice(node<T>* current, list& other)
{
}
void splice(node<T> *current, list& other, node<T> *t)
{
}
void splice(node<T> *current, list& other, node<T> *q1, node<T> *q2)
{
}





