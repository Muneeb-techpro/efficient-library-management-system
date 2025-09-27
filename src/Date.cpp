#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#include "Date.h"


void Date::read(istream& in)
{
	//cout << "Enter the publishing Date of Book in format day/month/year i.e 23/5/2023" << endl;
	char one;
	in >> day >>one>> month>>one >> year;
}
void Date::write(ostream& out)const
{
    // Format with leading zeros (e.g. 10/09/1986)
    out << (day < 10 ? "" : "") << day << "/"
        << (month < 10 ? "" : "") << month << "/"
        << year;
}

ostream& operator << (ostream& out, const Date& a)
{
	a.write(out);
	return out;
}
istream& operator >> (istream& in, Date& a)
{
	a.read(in);
	return in;
}