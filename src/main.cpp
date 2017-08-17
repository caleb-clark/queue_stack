#include "queue.h"
#include "stack.h"
#include <iostream>


int main() 
{

	stack<int> s;
	queue<int> q;

	for (int i = 0; i < 10; i++) {
		s.push(i);
		s.print();
		q.enqueue(i);
		q.print();
		std::cout << "------------------------------------------------------------" << std::endl << std::endl;
	}

	for (int i = 0; i < 10; i++) {
		std::cout << "q: " << q.dequeue() << std::endl;
		std::cout << "s: " << s.pop() << std::endl;
		std::cout << std::endl << "--------------------------------------------------------------" << std::endl << std::endl;
	}

}