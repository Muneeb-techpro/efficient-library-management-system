#pragma once


class Library
{
public:

	Library(const int& _bookNum = 0, const Book* _bookArr = nullptr, const int& _employeeNum = 0, const Employee* _employeeArr = nullptr);

	void setBookNum(const int& a);
	void setBookArr(const Book* a);
	void setEmployeeNum(const int& a);
	void setEmployeeArr(const Employee* a);

	int getBookNum()const { return bookNum; }
	Book* getBookArr()const;
	int getEmployeeNum()const { return employeeNum; }
	Employee* getEmployeeArr()const;
	string* getBookNames();
	int* getEmployeesIds();

	void read(istream& in);
	void write(ostream& out)const;

	bool isPresent(const string& bookName)const; //Check book present in Library record or not

	void borrowBookRecord()const;
	
	void bookBorrowing(const string& bookName); // if book Present in Library then it assign to student
	void bookReturning(); // Book successfully received from student
	void undoBookBorrowing(); //if you want to un-assign book which has recently assigned to student

	void undoBookReturning(); //if you want undo receving the book which recently received by Lab.
	~Library();

private:
	int bookNum; // Number of Books in Library
	Book* bookArr; //Array of Books
	int employeeNum;  // Number of Employees in Library
	Employee* employeeArr; //Array of Employees
	Queue<string> queue;
	Stack<string> stack1;
	Stack<string> stack2;
};
ostream& operator <<(ostream& out, const Library& a);
istream& operator >> (istream& in, Library& a);