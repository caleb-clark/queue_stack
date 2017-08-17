#include "linked_list.h"
#include <iostream>

#ifndef STACK_H
#define STACK_H

template <class T>
class stack 
{
private:
	linked_list<T> ll;
public:
	T& top();
	void push(T t);
	T pop();
	void print();
};


template <class T>
T& stack<T>::top()
{
	return ll.front()->payload;

}

template <class T>
void stack<T>::push(T t)
{
	ll.push_front(t);
}

template <class T>
T stack<T>::pop()
{
	T tmp = ll.front()->payload;
	ll.pop_front();
	return tmp;
}

template <class T>
void stack<T>::print() 
{
	ll.print();
}

#endif