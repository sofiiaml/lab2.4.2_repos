//TakenBook.cpp
#include "TakenBook.h"
bool TakenBook::operator ==(const TakenBook& tb) {
	return book == tb.book && datev == tb.datev && datep == tb.datep && isGiven == tb.isGiven;
}
TakenBook::TakenBook() {
}
TakenBook::TakenBook(Book book, string datev, string datep) {
	this->book = book;
	this->datev = datev;
	this->datep = datep;
	isGiven = false;
}
TakenBook::TakenBook(const TakenBook& tb ) {
	this->book = tb.book;
	this->datev = tb.datev;
	this->datep = tb.datep;
	this->isGiven = tb.isGiven;
}
TakenBook::operator string() const {
	string str = "Book: " + string(book) + " datev: " + datev + " datep: " + datep + " is given: " + to_string(isGiven);
	return str;
}
TakenBook& TakenBook::operator=(const TakenBook& tb) {
	this->book = Book(tb.book);
	this->datev = tb.datev;
	this->datep = tb.datep;
	this->isGiven = tb.isGiven;
	return *this;
}
ostream& operator<<(ostream& out, const TakenBook& tb) {
	out << "Book: " << tb.book << endl;
	out << "Date vydachi: " << tb.datev << endl;
	out << "Date povern: " << tb.datep << endl;
	out << "Is given:" << tb.isGiven << endl;
	return out;
}
istream& operator>>(istream& in, TakenBook& tb) {
	cout << "Book: "; in>> tb.book;
	cout << "Date vydachi: ";in>>tb.datev;
	cout << "Date povern: "; in>> tb.datep;
	cout << "Is given:"; in>> tb.isGiven;
	return in;
}