#include "pch.h"
#include "buyBook.h"
#include"testLegal.h"

buyBook::buyBook()
{
	char conninfo[120] = "host=127.0.0.1 user=postgres password=****** dbname=librarysys ";
	conn = PQconnectdb(conninfo);
}

void buyBook::init(const CString& Isbn, const CString& Title, const CString& Author, const CString& Publisher, const CString& Price, const CString& Quan)
{
	isbn = CStoS(Isbn);
	title = CStoS(Title);
	author = CStoS(Author);
	publisher = CStoS(Publisher);
	price = CStoS(Price);
	quantity = CStoS(Quan);
}

bool buyBook::exec()
{
	if (isValidInput(isbn) && isValidInput(title) && isValidInput(author) && isValidInput(publisher) && isValidInput(quantity))
	{
std::string sql = "insert into bookpurchase (isbn,title,author,publisher,quantity,paidstatus,price) values('" + isbn + "' , '" + title + "' , '" + author + "' , '" + publisher + "' , " + quantity + " , 0 ," + price +")";

	PGresult* res = PQexec(conn, sql.c_str());

	std::string a;
	a = PQcmdTuples(res);
	if (a != "0")
	{
		PQclear(res);
		return true;
		
	}
	else
	{
		PQclear(res);
		return false;
	}
	}
	else
	{
		return false;
	}
	
	
	
}

std::string buyBook::CStoS(const CString& a)
{
	CStringA b(a);
	return std::string(b);
}

