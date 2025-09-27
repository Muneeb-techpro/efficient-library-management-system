#include<iostream>
#include<fstream>
#include<string>
#include <iomanip>
using namespace std;

#include "Date.h"
#include "Book.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Employee.h"
#include "Library.h"
Library::Library(const int& _bookNum , const Book* _bookArr , const int& _employeeNum, const Employee* _employeeArr)
{
	setBookNum(_bookNum);
	if (bookNum == 0)
		bookArr = nullptr;

	setBookArr(_bookArr);
	setEmployeeNum(_employeeNum);
	if (employeeNum == 0)
		employeeArr = nullptr;
	setEmployeeArr(_employeeArr);
}
void Library::setBookNum(const int& a)
{
	if (a > 0)
		bookNum = a;
	else
		bookNum = 0;
}
void Library::setBookArr(const Book* a)
{
	bookCopy(bookArr, a, bookNum);
}
void Library::setEmployeeNum(const int& a)
{
	if (a > 0)
		employeeNum = a;
	else
		employeeNum = 0;
}
void Library::setEmployeeArr(const Employee* a)
{
	employeeCopy(employeeArr, a, employeeNum);
}
ostream& operator <<(ostream& out, const Library& a)
{
	a.write(out);
	return out;
}
istream& operator >> (istream& in, Library& a)
{
	a.read(in);
	return in;
}
void Library::read(istream& in)
{
	in >> bookNum;
	setBookNum(bookNum);
	bookArr = new Book[bookNum];
	for (int i = 0; i < bookNum; i++)
		in >> bookArr[i];

	in >> employeeNum;
	setEmployeeNum(employeeNum);
	employeeArr = new Employee[employeeNum];
	for (int i = 0; i < employeeNum; i++)
		in >> employeeArr[i];

}
void Library::write(ostream& out)const
{
	out << "Total Book in Library :" << bookNum << endl;
	out<<"-----------------------------------------------------------------"<<endl;
	out << left << setw(20) << "Name"<< left << setw(15) << "Author"<< left << setw(15) << "\tPublishibg" << right << '\t'<< "Pages" <<endl;
	out<<"-----------------------------------------------------------------"<<endl;
	for (int i = 0; i < bookNum; i++)
		out << bookArr[i] << endl;

	out << endl << endl;
	out << "Total Employee in Library :" << employeeNum << endl;
	out << "E_Name" << "\t\t" << "E_ID" << endl;
	for (int i = 0; i < employeeNum; i++)
		out << employeeArr[i] << endl;
}
Book* Library::getBookArr()const
{
	int bookNumber = getBookNum();
	Book* bookArray = new Book[bookNumber];
	for (int i = 0; i < bookNumber; i++)
		bookArray[i] = bookArr[i];
	return bookArray;
}
Employee* Library::getEmployeeArr()const
{
	int employeeNumber = getEmployeeNum();
	Employee* employeeArray = new Employee[employeeNumber];
	for (int i = 0; i < employeeNumber; i++)
		employeeArray[i] = employeeArr[i];
	return employeeArray;
}

bool Library::isPresent(const string& bookName)const 
{
	for (int i = 0; i < bookNum; i++)
		if (bookName == bookArr[i].getName())
			return 1;
	return 0;
}
void Library::borrowBookRecord()const
{
	if (queue.isEmpty())
		cout << "No book has been borrowed by student" << endl;
	else
		queue.display();
}
string* Library::getBookNames()
	{
		string* bookNames = new string[bookNum];
		for (int i = 0; i < bookNum; i++)
			bookNames[i] = bookArr[i].getName();

		return bookNames;
	}
	int* Library::getEmployeesIds()
	{
		int* employeeIds = new int[employeeNum];
		for (int i = 0; i < employeeNum;i++)
			employeeIds[i] = employeeArr[i].getId();

		return employeeIds;
	}

void Library::bookBorrowing(const string& bookName) // if book Present in Library then it assign to student
	{if (isPresent(bookName))
		{
			cout << "Book borrowed successfully: \"" << bookName << "\"" << endl;
			queue.enqueue(bookName);
		}
		else
		{
			cout << "Book not available in the library: \"" << bookName << "\"" << endl;
		}
	}
	void Library::bookReturning() // Book successfully received from student
	{
		if (!queue.isEmpty())
		{
			cout << "Book returned successfully: \"" << queue.front() << "\"" << endl;
			stack2.push(queue.dequeue());
		}
	}
	void Library::undoBookBorrowing() //if you want to un-assign book which has recently assigned to student
	{
		while (!queue.isEmpty())
			stack1.push(queue.dequeue());
		stack1.pop();
		stack1.reverse();

		while (!stack1.isEmpty())
			queue.enqueue(stack1.pop());
	}
	void Library::undoBookReturning() //if you want undo receving the book which recently received by Lab.
	{
		while (!queue.isEmpty())
			stack1.push(queue.dequeue());

		queue.enqueue(stack2.pop());
		stack1.reverse();

		while (!stack1.isEmpty())
			queue.enqueue(stack1.pop());
	}
	Library::~Library()
	{
		delete[] bookArr;
		delete[] employeeArr;
		bookArr = nullptr;
		employeeArr = nullptr;
	}
