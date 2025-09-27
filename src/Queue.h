#pragma once
template <class T>
class Queue
{
public:
	Queue() { obj = LinkedList<T>(); }
	bool isEmpty()const { return (obj.isEmpty()); }
	void enqueue(const T& value) {obj.insertAtEnd(value);}
	T dequeue() { return(obj.removeFromFront()); }
	void display()const;
	
	T front()const { return (obj.front()); }
	~Queue()
	{
		obj.~LinkedList();
	}

private:
	LinkedList<T> obj;
};

#include "Queue.tpp"

