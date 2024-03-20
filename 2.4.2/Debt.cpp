//Debt.cpp
#include "Debt.h"
Debt::operator string() const {
	string str = "Debt:\n";
	for (TakenBook tb : debtbooks) {
		str += string(tb) + "\n";
	}
	return str;
}
bool Debt::operator ==(const Debt& d) {
	vector<TakenBook> books;
	for (TakenBook tb : debtbooks) {
		books.push_back(tb);

	}
	for (TakenBook tb : d.debtbooks) {
		bool inVector = false;
		for (TakenBook tb2 : books) {
			if (tb2 == tb) {
				inVector = true;
				break;
			}
		}
		if (!inVector) {
			books.push_back(tb);
		}
	}
	return debtbooks.size() == books.size() && d.debtbooks.size() == books.size();
}
Debt& Debt::operator=(const Debt& d) {
	debtbooks.clear();
	for (TakenBook tb : d.debtbooks) {
		debtbooks.push_back(TakenBook(tb));
	}
	return *this;
}
ostream& operator<<(ostream& out, const Debt& d) {
	for (TakenBook tb : d.debtbooks) {
		out << tb << endl;
	}
	return out;
}
istream& operator>>(istream& in, Debt& d) {
	d.debtbooks.clear();
	int size;
	cout << "Amount of books: ";in >> size;
	
	for (int i = 0;i < size;i++) {
		TakenBook tb;
		in >> tb;
		d.debtbooks.push_back(tb);
	}
	return in;
}
TakenBook& Debt::operator[](int index) {
	return debtbooks[index];
}