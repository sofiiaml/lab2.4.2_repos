#include "pch.h"
#include "CppUnitTest.h"
#include "../2.4.2/Subscriber.h"
#include "../2.4.2/Subscriber.cpp"
#include "../2.4.2/Book.h"
#include "../2.4.2/Book.cpp"
#include "../2.4.2/TakenBook.h"
#include "../2.4.2/TakenBook.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest242
{
	TEST_CLASS(UnitTest242)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Subscriber s("Ivan", "12244345");
			Book b1("John", "abc", 2020, "defg", 250);
			TakenBook tb1(b1, "12.11.2021", "25.4.2021");
			s.AddBook(tb1);
			vector<TakenBook> books = s.getBooks();
			Assert::AreEqual(static_cast<size_t>(1), books.size());
			Assert::AreEqual<string>("John", books[0].getBook().getAuthor());
			Assert::AreEqual<string>("12.11.2021", books[0].getDatev());
			Assert::AreEqual<string>("25.4.2021", books[0].getDatep());
		}
	};
}
