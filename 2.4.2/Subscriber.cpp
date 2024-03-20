//Subscriber.cpp
#include "Subscriber.h"
Subscriber::Subscriber() {
}
Subscriber::Subscriber(string lastname, string number) {
	this->lastname = lastname;
	this->number = number;
}
Subscriber::Subscriber(const Subscriber& s) {
	this->lastname = s.lastname;
	this->number = s.number;
	for (TakenBook tb : s.books) {
		this->books.push_back(TakenBook(tb));
	}
}
void Subscriber::AddBook(Book b, string datev, string datep) {
	TakenBook tb = TakenBook(b, datev, datep);
	books.push_back(tb);
}
void Subscriber::AddBook(TakenBook tb) {
	books.push_back(tb);
}
void Subscriber::DeleteBook(Book b, string datep) {
	for (TakenBook tb : books) {
		if (tb.getBook() == b) {
			tb.setIsGiven(true);
			break;
		}

	}
}
void Subscriber::FindBooks(string date) {
	int day = stoi(date.substr(0, 2));
	int month = stoi(date.substr(3, 2));
	int year = stoi(date.substr(6, 4));
	for (TakenBook tb : books) {
		if (!tb.getIsGiven()) {
			int day2 = stoi(tb.getDatep().substr(0, 2));
			int month2 = stoi(tb.getDatep().substr(3, 2));
			int year2 = stoi(tb.getDatep().substr(6, 4));
			if (year<year2||year==year2&&month<month2|| year == year2 && month == month2 && day<day2) {
				cout << tb.getBook();
			}
		}
	}
}
void Subscriber::FindBookByAuthor(string author) {
	for (TakenBook tb : books) {
		if (!tb.getIsGiven()) {
			
			if (tb.getBook().getAuthor()==author) {
				cout << tb.getBook();
			}
		}
	}
}
void Subscriber::FindBookByPublisher(string publisher) {
	for (TakenBook tb : books) {
		if (!tb.getIsGiven()) {

			if (tb.getBook().getPublisher() == publisher) {
				cout << tb.getBook();
			}
		}
	}
}
void Subscriber::FindBookByYear(int year) {
	for (TakenBook tb : books) {
		if (!tb.getIsGiven()) {

			if (tb.getBook().getYear() == year) {
				cout << tb.getBook();
			}
		}
	}
}
int Subscriber::PriceOfBooks(string date) {
	int day = stoi(date.substr(0, 2));
	int month = stoi(date.substr(3, 2));
	int year = stoi(date.substr(6, 4));
	int price = 0;
	for (TakenBook tb : books) {
		if (!tb.getIsGiven()) {
			int day2 = stoi(tb.getDatep().substr(0, 2));
			int month2 = stoi(tb.getDatep().substr(3, 2));
			int year2 = stoi(tb.getDatep().substr(6, 4));
			if (year < year2 || year == year2 && month < month2 || year == year2 && month == month2 && day < day2) {
				price+=tb.getBook().getPrice();
			}
		}
	}
	return price;
}
Debt Subscriber::FindDebt(string date) {
	int day = stoi(date.substr(0, 2));
	int month = stoi(date.substr(3, 2));
	int year = stoi(date.substr(6, 4));
	vector <TakenBook> tbooks;
	for (TakenBook tb : books) {
		if (!tb.getIsGiven()) {
			int day2 = stoi(tb.getDatep().substr(0, 2));
			int month2 = stoi(tb.getDatep().substr(3, 2));
			int year2 = stoi(tb.getDatep().substr(6, 4));
			if (year < year2 || year == year2 && month < month2 || year == year2 && month == month2 && day < day2) {
				tbooks.push_back(tb);
			}
		}
	}
	Debt d;
	d.setDebtbooks(tbooks);
	return d;
}
Subscriber Subscriber::Union(Subscriber s) {
	Subscriber s2(lastname, number);
	for (TakenBook tb : books) {
		s2.AddBook(tb);

	}
	for (TakenBook tb : s.books) {
		bool inVector = false;
		for (TakenBook tb2 : s2.books) {
			if (tb2 == tb) {
				inVector = true;
				break;
			}
		}
		if (!inVector) {
			s2.AddBook(tb);
		}
	}
	return s2;
}
Subscriber Subscriber::Difference(Subscriber s) {
	Subscriber s2(lastname, number);
	
	for (TakenBook tb : books) {
		bool inVector = false;
		for (TakenBook tb2 : s.books) {
			if (tb2 == tb) {
				inVector = true;
				break;
			}
		}
		if (!inVector) {
			s2.AddBook(tb);
		}
	}
	return s2;
}
Subscriber Subscriber::Cross(Subscriber s) {
	Subscriber s2(lastname, number);

	for (TakenBook tb : books) {
		for (TakenBook tb2 : s.books) {
			if (tb2 == tb) {
				s2.AddBook(tb);
			}
		}
	}
	return s2;

}
TakenBook Subscriber::operator[](int index) {
	return books[index];
}
ostream& operator<<(ostream& out, const Subscriber& s) {
	out << "Lastname: " << s.lastname << endl;
	out << "Number: " << s.number << endl;
	for (TakenBook tb : s.books) {
		out << tb << endl;
	}
	return out;
}
istream& operator>>(istream& in, Subscriber& s) {
	cout << "Lastname: ";in >> s.lastname;
	cout << "Number: ";in >> s.number;
	s.books.clear();
	int size;
	cout << "Amount of books: ";in >> size;
	
	for (int i = 0;i < size;i++) {
		TakenBook tb;
		in >> tb;
		s.books.push_back(tb);
	}
	return in;
}
Subscriber::operator string() const {
	string str = "Lastname: " + lastname + "\nNumber: " + number + "\n";
	for (TakenBook tb : books) {
		str += string(tb) + "\n";
	}
	return str;
}
bool Subscriber::operator==(const Subscriber& s) {
	return lastname == s.lastname && number == s.number && Union(s).books.size() == books.size();
}
Subscriber& Subscriber::operator=(const Subscriber& s) {
	this->lastname = s.lastname;
	this->number = s.number;
	books.clear();
	for (TakenBook tb : s.books) {
		books.push_back(TakenBook(tb));
	}
	return *this;
}