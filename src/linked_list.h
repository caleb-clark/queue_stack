#include <iostream>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <class T>
struct node 
{

	node * next;
	node * prev;

	T payload;
	
	node(T t = T()) : payload(t)
	{
		next = NULL;
		prev = NULL;
	}
	node(const node& n)
	{
		next = NULL;
		prev = NULL;
		this->payload = n.payload;
	}



};

template <class T>
class linked_list
{
	friend class linked_list<T>;
	node<T> * head;
	node<T> * tail;
public:
	linked_list();
	~linked_list();
	linked_list(const linked_list<T>& ll);
	linked_list& operator=(const linked_list<T>& ll);

	node<T> * back();
	node<T> * front();
	void push_back(T t);
	void push_front(T t);
	void print();
	void pop_front();
	void pop_back();
	bool empty();

};
template <class T>
linked_list<T>::linked_list()
{
	head = new node<T>();
	tail = new node<T>();
	head->next = tail;
	tail->prev = head;
	head->prev = NULL;
	tail->next = NULL;
}
template <class T>
linked_list<T>::~linked_list()
{
	node<T> * tmp = head;
	node<T> * tmp2 = head;
	while (tmp != tail) {
		tmp2 = tmp->next;
		delete tmp;
		tmp = tmp2;
	}
	delete tmp;
}
template <class T>
linked_list<T>::linked_list(const linked_list<T>& ll)
{
	head = new node<T>();
	tail = new node<T>();
	head->next = tail;
	tail->prev = head;
	node<T> * tmp = &(ll.front());
	while (tmp != ll.tail) {
		push_back(new node<T>(tmp));
	}	

}
template <class T>
linked_list<T>& linked_list<T>::operator=(const linked_list<T>& ll)
{
	node<T> * tmp = head;
	node<T> * tmp2 = head;
	while (tmp != tail) {
		tmp2 = tmp->next;
		delete tmp;
		tmp = tmp2;
	}
	delete tmp;

	head = new node<T>();
	tail = new node<T>();
	head->next = tail;
	tail->prev = head;
	tmp = &(ll.front());
	while (tmp != ll.tail) {
		push_back(new node<T>(tmp));
	}	

}

template <class T>
node<T> * linked_list<T>::back()
{
	if (tail->prev != head) {
		return tail->prev;
	} else {
		return NULL;
	}
}

template <class T>
node<T> * linked_list<T>::front()
{
	if (head->next != tail) {
		return head->next;
	} else {
		return NULL;
	}
}

template <class T>
void linked_list<T>::push_back(T t)
{
	node<T> * tmp = tail->prev;
	tmp->next = new node<T>(t);
	tmp->next->prev = tmp;
	tmp->next->next = tail;
	tail->prev = tmp->next;
}

template <class T>
void linked_list<T>::push_front(T t)
{
	node<T> * tmp = head->next;
	head->next = new node<T>(t);
	head->next->next = tmp;
	head->next->prev = head;
	tmp->prev = head->next;
}

template <class T>
void linked_list<T>::pop_front()
{
	node<T> * tmp = head->next;
	if (tmp == tail) {
		return;
	}
	head->next = tmp->next;
	tmp->next->prev = head;
	delete tmp;
}

template <class T>
void linked_list<T>::pop_back()
{
	node<T> * tmp = tail->prev;
	if (tmp == head) {
		return;
	}
	tmp->prev->next = tail;
	tail->prev = tmp->prev;
	delete tmp;

}
template <class T>
bool linked_list<T>::empty()
{
	return head->next == tail;
}

template <class T>
void linked_list<T>::print()
{
	node<T> * tmp = head->next;
	if (empty()) {
		std::cout << "Empty list" << std::endl;
	}
	while (tmp != this->tail) {
		std::cout << tmp->payload;
		if (tmp != tail->prev) {
			std::cout << "->";
		}
		tmp = tmp->next;
	}
	std::cout << std::endl;
}



#endif