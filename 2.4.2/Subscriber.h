//Subscriber.h
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include "TakenBook.h"
#include "Debt.h"

using namespace std;
class Subscriber {
private:
	string lastname;
	string number;
	vector <TakenBook> books;
public:
	Subscriber();
	Subscriber(string lastname, string number);
	Subscriber(const Subscriber&);
	string getLastname() { return lastname; }
	string getNumber() { return number; }
	vector<TakenBook> getBooks() { return books; }
	void setLastname(string lastname) { this->lastname = lastname; }
	void setNumber(string number) { this->number = number; }
	void setBooks(vector <TakenBook> books){this->books = books;}
	void AddBook(Book b, string datev, string datep);
	void AddBook(TakenBook tb);
	void DeleteBook(Book b, string datep);
	void FindBooks(string date);
	void FindBookByAuthor(string author);
	void FindBookByPublisher(string publisher);
	void FindBookByYear(int year);
	int PriceOfBooks(string date);
	Debt FindDebt(string date);
	Subscriber Union(Subscriber s);//злиття
	Subscriber Difference(Subscriber s);//різниця
	Subscriber Cross(Subscriber s);//перетин
	TakenBook operator[](int index);
	friend ostream& operator<<(ostream&, const Subscriber&);
	friend istream& operator>>(istream&, Subscriber&);
	operator string() const;
	bool operator==(const Subscriber&);
	Subscriber& operator=(const Subscriber& b);
};