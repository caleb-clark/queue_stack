#include "linked_list.h"

#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class queue
{
private:
	linked_list<T> ll;
public:
	void enqueue(T t);
	T dequeue();
	T& front();
	void print();
};

template <class T>
void queue<T>::enqueue(T t)
{
	ll.push_back(t);
}

template <class T>
T queue<T>::dequeue()
{
	T tmp = ll.front()->payload;
	ll.pop_front();
	return tmp;
}

template <class T>
T& queue<T>::front()
{
	return ll.front()->payload;
}

template <class T>
void queue<T>::print() 
{
	ll.print();
}


#endif