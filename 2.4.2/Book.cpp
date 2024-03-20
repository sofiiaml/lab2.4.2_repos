//Book.cpp
#include "Book.h"
Book::Book() {
}
Book::Book(string author, string name, int year, string publisher, int price) {
	this->author = author;
	this->name = name;
	this->year = year;
	this->publisher = publisher;
	this->price = price;
}
Book::Book(const Book& book) {
	this->author = book.author;
	this->name = book.name;
	this->year = book.year;
	this->publisher = book.publisher;
	this->price = book.price;
}
ostream& operator<<(ostream& out, const Book& book) {
	out << "author: " << book.author << endl;
	out << "name: " << book.name << endl;
	out << "year: " << book.year << endl;
	out << "publsher: " << book.publisher << endl;
	out << "price: " << book.price << endl;
	out << endl;
	return out;
}
istream& operator>>(istream& in, Book& book) {
	cout << "author: ";in >> book.author;
	cout << "name: ";in>>book.name;
	cout << "year: "; in >> book.year;
	cout << "publsher: "; in >> book.publisher;
	cout << "price: "; in >> book.price;
	return in;
}
Book::operator string() const {
	string str = " ";
	str+= "author: " + author + "\n";
	str+= "name: " + name + "\n";
	str+= "year: " + to_string(year) + "\n";
	str += "publsher: " + publisher + "\n";
	str += "price: " + to_string(price) + "\n";
	return str;
}
bool Book::operator==(const Book& book) {
	return author == book.author && name == book.name && year == book.year && publisher == book.publisher && price == book.price;
}
Book& Book::operator=(const Book& b) {
	this->author = b.author;
	this->name = b.name;
	this->year = b.year;
	this->publisher = b.publisher;
	this->price = b.price;
	return *this;
}