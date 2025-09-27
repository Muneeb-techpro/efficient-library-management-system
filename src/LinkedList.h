#pragma once
template <class T>
struct Node
{
	Node(const T& a) { data = a; next = nullptr; back = nullptr; }
	T data;
	Node* next;
	Node* back;
};
template <class T>
class LinkedList
{
public:
	LinkedList() { head = nullptr; num = 0; }
	bool isEmpty()const { return (head == nullptr); }
	T front()const { if (!isEmpty())return (head->data); else return NULL; }
	T back()const;
	void insertAtFront(const T& value);
	void insertAtEnd(const T& value);
	T removeFromFront();
	T removeFromEnd();
	void display()const;
	bool search(const T& value)const;
	void displayReverse()const;
	void destroyLL();
	int size() { return num; }
	~LinkedList();
private:
	Node<T>* head;
	int num;
};

#include "LinkedList.tpp" // include implementations