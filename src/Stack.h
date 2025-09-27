#pragma once

template <class T>
class Stack
{
public:
	Stack() { obj = LinkedList<T>(); }
	bool isEmpty()const { return (obj.isEmpty()); }
	void push(const T& value)
	{
		obj.insertAtEnd(value);
	}
	T pop()
	{
		return(obj.removeFromEnd());
	}
	void display()const
	{
		obj.display();
	}
	void reverse(); //Reverse the Stack
	
	~Stack()
	{
		obj.~LinkedList();
	}
private:
	LinkedList<T> obj;
};

#include "Stack.tpp"
