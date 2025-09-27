#pragma once
class Employee
{
public:
	Employee(string Ename = "EmloyeeName") :id(assignID() )
	{
		name = Ename;
	};
	Employee(const Employee& one):id(one.id)
	{
		name = one.name;
	}
	void display()const
	{
		cout << "Name :" << name << endl;
		cout << "EmployeeID :" << id << endl;
	}
	static int assignID()
	{
		static int num = 0;
		return ++num;
	}
	int getId()const { return id; }
	void read(istream& in);
	void write(ostream& out)const;
	const Employee& operator =(const Employee& two);
private:
	string name;
	int id;

};
ostream& operator <<(ostream& out, const Employee& a);
istream& operator >> (istream& in, Employee& a);
void employeeCopy(Employee* one, const Employee* two, const int& size);