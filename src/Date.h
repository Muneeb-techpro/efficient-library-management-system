#pragma once
class Date
{
public:
	Date(const int& _day = 1, const int& _month = 1, const int _year = 2000) :day(_day), month(_month), year(_year) {};
	void read(istream& in);
	void write(ostream& out) const ;
	~Date() {}
private:
	int day;
	int month;
	int year;
};

ostream& operator << (ostream& out, const Date& a);
istream& operator >> (istream& out, Date& a);
