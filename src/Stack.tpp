#include<iostream>
using namespace std;
#include "LinkedList.h"
#include "Stack.h"

template <class T>
void Stack<T>::reverse() //Reverse the Stack
{
		Stack<T> myStack;
		while (!obj.isEmpty())
			myStack.push(obj.removeFromFront());

		while (!myStack.isEmpty())
			obj.insertAtEnd(myStack.pop());
}