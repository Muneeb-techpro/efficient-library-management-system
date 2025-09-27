#include<iostream>
#include<fstream>
#include<string>
#include <iomanip>

using namespace std;
#include "Date.h"
#include "Book.h"

ostream& operator <<(ostream& out, const Book& a)
{
	a.write(out);
	return out;
}
istream& operator >> (istream& in, Book& a)
{
	a.read(in);
	return in;
}
void Book::read(istream& in)
{
	in >> name >> author >> pubDate >> pages;
}
void Book::write(ostream& out)const
{
	//out << name<<'\t' <<'\t'<< author << '\t' << pubDate << '\t' << pages;
	//out << '\t' << author << '\t' << pubDate << '\t' << pages;


	out << left << setw(20) << name
        << left << setw(15) << author
        << left << setw(5) << pubDate
        << right << '\t'<< pages ;
}
void bookCopy(Book* one, const Book* two, int size)
{
	for (int i = 0; i < size; i++)
		one[i] = two[i];
}

