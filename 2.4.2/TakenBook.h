//TakenBook.h
#pragma once
#include <iostream>
#include <string>
#include "Book.h"

using namespace std;
class TakenBook {
private:
	Book book;
	string datev;
	string datep;
	bool isGiven;
public:
	TakenBook();
	TakenBook(Book book, string datev, string datep);
	TakenBook(const TakenBook&);
	Book getBook() { return book;}
	string getDatev() { return datev; }
	string getDatep() {	return datep;}
	bool getIsGiven() { return isGiven; }
	void setIsGiven(bool isGiven) { this->isGiven = isGiven; }
	void setDatep(string datep) { this->datep = datep; }
	operator string() const;
	bool operator ==(const TakenBook& tb);
	TakenBook& operator=(const TakenBook& other);
	friend ostream& operator<<(ostream& out, const TakenBook& tb);
	friend istream& operator>>(istream&, TakenBook&);
};
