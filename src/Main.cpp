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
#include "HashTable.h"
#include "BST.h"



int main()
{
	
	Library one;

	cout << "==================================================================================" << endl;
	cout << "                             Library Management System                            " << endl;
	cout << "==================================================================================" << endl << endl;

	cout << "Loading data from file (DataFile.txt)..." << endl;
	ifstream fin("DataFile.txt");
	if (fin) {
		fin >> one;
		cout << "Data loaded successfully!" << endl;
	}
	else {
		cout << "Could not open DataFile.txt. Please check the file." << endl;
		return 1;
	}
	
	cout << one;
	cout << endl << endl << endl;

	                // ------------------- Book Borrowing -------------------
	cout << endl;
	cout << "==================================================================================" << endl;
	cout << "                    1. Performing Book Borrowing Operations                       " << endl;
	cout << "==================================================================================" << endl;

	one.bookBorrowing("Dracula");
	one.bookBorrowing("Dune");
	one.bookBorrowing("Emma");
	one.bookBorrowing("JaneEyre");
	one.bookBorrowing("Hamlet");    // should fail gracefully
	one.bookBorrowing("Anthem");
	cout << "Current Borrowed Books : " << endl;
	one.borrowBookRecord();
	cout << endl << endl << endl;



	cout << "==================================================================================" << endl;
	cout << "                  2. Performing Book Returning Operations                         " << endl;
	cout << "==================================================================================" << endl;
	one.bookReturning();
	one.bookReturning();
	one.bookReturning();
	cout << "Current Borrowed Books : " << endl;
	one.borrowBookRecord();
	cout << endl << endl << endl;



	cout << "==================================================================================" << endl;
	cout << "                      3. Undoing Book Returning Operations                        " << endl;
	cout << "==================================================================================" << endl;
	one.undoBookReturning();
	one.undoBookReturning();
	cout << "Current Borrowed Books : " << endl;
	one.borrowBookRecord();
	cout << endl << endl << endl;



	cout << "==================================================================================" << endl;
	cout << "                 4. Book Searching using Binary Search Tree (BST)                 " << endl;
	cout << "==================================================================================" << endl;
	int bookNumber = one.getBookNum();
	BST<string> tree;
	tree.insertArray(one.getBookNames(),one.getBookNum());
	string searchBook = "Dracula";
	if (tree.search(searchBook))
		cout << "Book: "<<searchBook<<" Found!" << endl;
	else
		cout << "Book: " << searchBook << " did not Found!" << endl;

	searchBook = "Shogun";
	if (tree.search(searchBook))
		cout << "Book: " << searchBook << " Found!" << endl;
	else
		cout << "Book: " << searchBook << " did not Found!" << endl;
	cout << endl << endl << endl;



	cout << "==================================================================================" << endl;
	cout << "            5. We will perform Employee Searching using Hash Table                " << endl;
	cout << "==================================================================================" << endl;

		int empId = 14;

		const int hashTableSize = 10;
		HashTable<int> table(hashTableSize);

		int employeeNumber = one.getEmployeeNum();
		int* employeeIdArray = one.getEmployeesIds();
		table.insertArray(employeeIdArray, employeeNumber);
	

		if (table.search(empId))
			cout << "Employee ID: "<< empId<<" Found in record" << endl;
		else
			cout << "Employee ID: " << empId << " Not Found in record" << endl;
		empId = 789;
		if (table.search(empId))
			cout << "Employee ID: " << empId << " Found in record" << endl;
		else
			cout << "Employee ID: " << empId << " Not Found in record" << endl;
	
	cout << endl;

	cout << "==================================================================================" << endl;
	cout << "                          Program Terminiated Successfully                        " << endl;
	cout << "==================================================================================" << endl;

	return 0;
}


