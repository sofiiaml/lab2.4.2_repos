//Book.h
#pragma once
#include <iostream>
#include <string>
using namespace std;
class Book {
private:
	string author;
	string name;
	int year;
	string publisher;
	int price;
public:
	Book();
	Book(string author, string name, int year, string publisher, int price);
	Book(const Book& book);
	string getAuthor() { return author; }
	string getName() { return name; }
	int getYear() { return year; }
	string getPublisher() { return publisher; }
	int getPrice() { return price; }
	void setAuthor(string author) { this->author = author; }
	void setName(string name) { this->name = name; }
	void setYear(int year) { this->year = year; }
	void setPublisher(string publisher) { this->publisher = publisher; }
	void setPrice(int price) { this->price - price; }
	friend ostream& operator<<(ostream&, const Book&);
	friend istream& operator>>(istream&, Book&);
	operator string() const;
	bool operator==(const Book&);
	Book& operator=(const Book& b);
};