#include<iostream>
using namespace std; 
#include "LinkedList.h"

template <class T>
T LinkedList<T>::back()const
{
	if (isEmpty())
		return T();

	Node<T>* current = head;
	while (current->next != nullptr)
	{
		current = current->next;
	}
	T temp = current->data;
	current = nullptr;
	return temp;
}
template <class T>
void LinkedList<T>::insertAtFront(const T& value)
{
	Node<T>* newNode = new Node<T>(value);
	if (isEmpty())
		head = newNode;
	else
	{
		head->back = newNode;
		newNode->next = head;
		head = newNode;
		newNode = nullptr;
	}
	num++;
}
template <class T>
void LinkedList<T>::insertAtEnd(const T& value)
{
	Node<T>* newNode = new Node<T>(value);
	if (isEmpty())
		head = newNode;
	else
	{
		Node<T>* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
		newNode->back = current;
		current = newNode = nullptr;
	}
	num++;
}
template <class T>
T LinkedList<T>::removeFromFront()
{
	if (isEmpty())
    return T();   
	if (head->next == nullptr)
	{
		T temp = head->data;
		delete head;
		head = nullptr;
		num--;
		return temp;
	}
	T temp = head->data;
	Node<T>* current = head;
	head = head->next;
	head->back = nullptr;
	delete current;
	current = nullptr;
	num--;
	return temp;
}
template <class T>
T LinkedList<T>::removeFromEnd()
{
	if (isEmpty())
		return T();
	if (head->next == nullptr)
	{
		T temp = head->data;
		delete head;
		head = nullptr;
		num--;
		return temp;
	}
	Node<T>* current = head;
	while (current->next->next != nullptr)
	{
		current = current->next;
	}
	T temp = current->next->data;
	delete current->next;
	current->next = nullptr;
	num--;
	return temp;
}
template <class T>
void LinkedList<T>::display()const
{
	if (isEmpty())
		cout << "My List is Empty" << endl;
	else
	{
		cout << "Data : ";
		Node<T>* current = head;
		while (current != nullptr)
		{
			cout << current->data;
			if (current->next != nullptr)
				cout << " -> ";
			current = current->next;
		}
		cout << endl;
	}
}
template <class T>
bool LinkedList<T>::search(const T& value)const
{
	if (isEmpty())
		return 0;
	
	Node<T>* current = head;
	while (current != nullptr)
	{
		if (current->data == value)
			return 1;
		current = current->next;
	}
	return 0;	
}

template <class T>
void LinkedList<T>::displayReverse()const
{
	if (isEmpty())
		cout << "My List is Empty" << endl;
	else
	{
		cout << "Tail to Head :";
		Node<T>* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}

		while (current != nullptr)
		{
			cout << current->data;
			if (current->back != nullptr)
				cout << "<-";
			current = current->back;
		}
		cout << endl;
	}
}
template <class T>
void LinkedList<T>::destroyLL()
{
	while (!isEmpty())
		removeFromFront();
}
template <class T>
LinkedList<T>::~LinkedList()
{
	while (!isEmpty())
		removeFromFront();
}
