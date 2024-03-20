//Source.cpp
#include <iostream>
#include <vector>
//#include "Book.h"
//#include "TakenBook.h"
#include "Subscriber.h"
using namespace std;

int main() {
     Book b1("John", "abc", 2020, "defg", 250);
     Book b2("Mark", "abcd", 2021, "defg", 250);
     Book b3("John", "abcf", 2022, "defg", 400);
     Book b4("Mark", "abcg", 2000, "defg", 250);
    TakenBook tb1(b1, "12.11.2021", "25.4.2022");
    TakenBook tb2(b2, "12.3.2020", "21.4.2021");
    TakenBook tb3(b3, "12.8.2020", "25.3.2022");
    TakenBook tb6(b1, "22.12.2021", "25.4.2022");
    TakenBook tb8(b4, "12.3.2022", "25.4.2023");
    Subscriber s("Ivan", "12244");
    s.AddBook(tb1);
    s.AddBook(tb2);
    s.AddBook(tb3);
    Subscriber s2("Petro", "12245");
    s2.AddBook(tb6);
    s2.AddBook(tb8);

    cout << "Books to be returned: " << endl;
    s.FindBooks("20.1.2022");
    cout << endl;

    cout << "Books by author John: " << endl;
    s.FindBookByAuthor("John");
    cout << endl;

    cout << "Total price of books to be returned: " << s.PriceOfBooks("20.1.2022") << endl;
    cout << endl;
    Subscriber uni = s.Union(s2);
    Subscriber diff = s.Difference(s2);
    Subscriber cross = s.Cross(s2);

    cout << "Union:" << endl << uni;
    cout << "Difference: " << endl << diff;
    cout << "Cross: " << endl << cross;

    cout << s;
    Debt d = s.FindDebt("20.3.2021");
    cout << "Debt: " << endl << d;
    return 0;
}
