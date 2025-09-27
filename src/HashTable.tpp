#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#include "Date.h"
#include "Book.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Employee.h"
#include "Library.h"
#include "HashTable.h"

template <typename T>
HashTable<T>::HashTable(const int& hashTableSize)
{
	size = hashTableSize;
	listArr = new LinkedList<T>[size];
}

template <typename T>
int HashTable<T>::hashFuncation(const T& value)
{
	return (value % size);
}

template <typename T>
void HashTable<T>::insert(const T& value)
{
	int index = hashFuncation(value);
	listArr[index].insertAtEnd(value);
}

template <typename T>
bool HashTable<T>::search(const T& value)
{
	int index = hashFuncation(value);
	return listArr[index].search(value);
}

template <typename T>
void HashTable<T>::display()const
{
	for (int i = 0; i < size; i++)
	{
		if (!listArr[i].isEmpty())
		{
			cout << "Index Number :" << i << "  List Data : ";
			listArr[i].display();
			//cout << endl;
		}
	}
}

template <typename T>
void HashTable<T>::insertArray(const T* arr, const int& size)
{
	if (size == 0)
		return;
	for (int i = 0; i < size; i++)
	{
		insert(arr[i]);
	}

}

