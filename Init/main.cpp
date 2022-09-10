#include<iostream>
using namespace std;

class Book
{
	char* name;
	int pages;
	static int count;
public:
	Book(const char* n);
	Book(const char* n, int p);
	void Print();
	~Book();
	static int GetCount();
	static void SetCount(int);


};
Book::Book(const char* n) {
	count++;
	pages = 0;
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}
Book::Book(const char* n, int p) : Book(n) {
	pages = p;
}
void::Book::Print() {
	cout << name << endl;
	cout << pages << endl;
}
Book::~Book() {
	count--;
	delete[]name;
}
int Book::GetCount() {
	return count;
}
void Book::SetCount(int newCount) {
	count = newCount;
}
int Book::count = 0;

class Student
{
	char* name;
	const double step;// !!
	Book book; //!!!
	static int count;
public:
	Student();
	Student(const char* n, double st, const char* bookName, int bookPages);
	~Student();
	void Print();
	static int GetCount();
	static void SetCount(int);
};
Student::Student() :step(0), book(nullptr, 0)
{
	count++;
	name = nullptr;
}
Student::Student(const char* n, double st, const char* bookName, int bookPages) :step(st), book(bookName, bookPages) {
	count++;
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}
Student::~Student() {
	count--;
	if (name != nullptr)delete[]name;

}
void Student::Print() {
	cout << name << endl;
	cout << step << endl;
	book.Print();

}
int Student::GetCount() {
	return count;
}
void Student::SetCount(int newCount) {
	count = newCount;
}
int Student::count = 0;


// показать использование объектом в функции main
int main()
{
	Book book1("Book", 50);
	Book book2("Boo2");
	book1.Print();
	cout << "Number of objects in class Book - " << Book::GetCount();
	cout << endl << endl;
	Student student1("Tom", 10.20, "Book_Name", 420);
	cout << "Number of objects in class Student - " << Student::GetCount() << endl;
	student1.Print();

	return 0;
}