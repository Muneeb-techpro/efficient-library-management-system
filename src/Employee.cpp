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

void Employee::read(istream& in)
{
	in >> name;
}
void Employee::write(ostream& out)const
{
	out << name << "\t\t" << id;
}
ostream& operator <<(ostream& out, const Employee& a)
{
	a.write(out);
	return out;
}
istream& operator >> (istream& in, Employee& a)
{
	a.read(in);
	return in;
}
void employeeCopy(Employee* one, const Employee* two, const int& size)
{
	for (int i = 0; i < size; i++)
		one[i] = two[i];
}
const Employee& Employee::operator =(const Employee& two)
{
	if (this == &two)
		return *this;
	name = two.name;
	id = two.id;
	return *this;
}