#pragma once
class Book
{
public:
	Book(const string& _name = "BookName", const string& _author = "AuthorName", const Date& _pubDate = Date(), const int& _pages = 100)
	{
		name = _name;
		author = _author;
		pubDate = _pubDate;
		pages = _pages;
	}
	void bookInfo()const
	{
		cout << "Name :" << name << endl;
		cout << "Author :" << author << endl;
		cout << "Publishing Date :" << pubDate << endl;
		cout << "Pages :" << pages << endl;
	}
	string getName()const { return name; }
	void read(istream& in);
	void write(ostream& out)const;
	
private:
	string name;
	string author;
	Date  pubDate; //Book  publishingDate;
	int pages;  // Total Book pages
};
ostream& operator <<(ostream& out, const Book& a);
istream& operator >> (istream& in, Book& a);
void bookCopy(Book* one, const Book* two, int size);