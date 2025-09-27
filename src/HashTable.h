#pragma once
template <typename T>
class HashTable
{
public:
	HashTable(const int& hashTableSize = 0);
	~HashTable() { delete[] listArr; listArr = nullptr; }

	int hashFuncation(const T& value);
	void insert(const T& value);
	void insertArray(const T*, const int& size);
	bool search(const T& value);
	void display()const;

private:
	int t;
	LinkedList<T>* listArr;
	int size;
};

#include "HashTable.tpp"
