//Debt.h
#pragma once
#include <vector>;
#include "TakenBook.h"
class Debt {
private:
	vector <TakenBook> debtbooks;
public:
	vector <TakenBook> getDebtbooks() { return debtbooks; };
	void setDebtbooks(vector <TakenBook> debtbooks) { this->debtbooks = debtbooks; }
	operator string() const;
	bool operator ==(const Debt& d);
	Debt& operator=(const Debt& d);
	friend ostream& operator<<(ostream& out, const Debt& d);
	friend istream& operator>>(istream&, Debt&);
	TakenBook& operator[](int index);
};
