#include "pch.h"
#include "SelBook.h"
#include"testLegal.h"
#include<sstream>

SelBook::SelBook()
{
	char conninfo[120] = "host=127.0.0.1 user=postgres password=****** dbname=librarysys ";
	conn = PQconnectdb(conninfo);
}

void SelBook::init()
{
	for (auto elem : resItems)
	{
		resItems.clear();
	}
	resItems.clear();

	PGresult* res = PQexec(conn, "select * from book");
	int rows = PQntuples(res);
	int cols = PQnfields(res);
	std::vector<std::string> resRow;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::string result = PQgetvalue(res, i, j);
			resRow.push_back(result);
		}
		resItems.push_back(resRow);
		resRow.clear();
	}
	PQclear(res);
}



CString SelBook::SelIsbn(int i)
{
	return CString(_T(resItems[i][0].c_str()));
}

CString SelBook::SelNo(int i)
{
	return CString(_T(resItems[i][1].c_str()));
}

CString SelBook::SelTitle(int i)
{
	return CString(_T(resItems[i][2].c_str()));
}

CString SelBook::SelAuthor(int i)
{
	return CString(_T(resItems[i][3].c_str()));
}

CString SelBook::SelPublisher(int i)
{
	return CString(_T(resItems[i][4].c_str()));
}

CString SelBook::SelPrice(int i)
{
	return CString(_T(resItems[i][5].c_str()));
}

CString SelBook::SelStock(int i)
{
	return CString(_T(resItems[i][6].c_str()));
}

void SelBook::ConditionalQuery(int c, const CString& v)
{
	CStringA m(v);
	std::string val(m);
	if (!isValidInput(val))
	{
		return;
	}
	std::string condition;
	if (c == 1)
	{
		 condition = "where isbn = '" + val+"'";
	}
	else if (c == 2)
	{
		condition = "where title like '%" + val + "%'";
	}
	else if (c == 3)
	{
		condition = "where author like '%" + val + "%'";
	}
	else if (c == 4)
	{
		condition = "where publisher like '%" + val + "%'";
	}
	else if (c == 5)
	{
		condition = "where bookno = " + val;
	}
	else
	{
		condition = "";
	}

	std::string sql = "select * from book " + condition;

	for (auto elem : resItems) //empty the vector
	{
		resItems.clear();
	}
	resItems.clear();

	PGresult* res = PQexec(conn, sql.c_str());
	int rows = PQntuples(res);
	int cols = PQnfields(res);
	std::vector<std::string> resRow;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::string result = PQgetvalue(res, i, j);
			resRow.push_back(result);
		}
		resItems.push_back(resRow);
		resRow.clear();
	}
	PQclear(res);
	
	
}

int SelBook::getRowNum()
{
	return resItems.size();
}


bool SelBook::ModifyBook(int p, const CString& line,const CString& v)
{
	CStringA la(line);
	CStringA va(v);
	std::string ls(la);
	std::string vs(va);
	std::string attri;

	switch (p)
	{
	case 0:
		attri = "title";
		break;
	case 1:
		attri = "author";
		break;
	case 2:
		attri = "publisher";
		break;
	case 3:
		attri = "price";
		break;
	default:
		break;
	}

	std::string sql;
	if (p == 3)
	{
	sql = "update book set " + attri + " = " + vs + " where bookno = " + ls;
	}
	 
	else
	{
	sql = "update book set " + attri + " = '" + vs + "' where bookno = " + ls;
	}
	PGresult* res = PQexec(conn, sql.c_str());

	std::string CompRes = PQcmdTuples(res);
	PQclear(res);
	if (CompRes.empty())
	{
		return false;
	}
	else
	{
		return true;
	}

	
}

int SelBook::SellBook(const CString& isbn,const CString& quan,const CString& price,const CString& stock)
{
	std::string Isbn, quantity,Price,Stock_s;
	Isbn = CStoS(isbn);
	quantity = CStoS(quan);
	Price = CStoS(price);
	Stock_s = CStoS(stock);

	int Quan,Stock;
	double amount;
	double Pr;

	std::istringstream iss(quantity);
	iss >> Quan;
	iss.clear();
	iss.str(Price);
	iss >> Pr;
	iss.clear();
	iss.str(Stock_s);
	iss >> Stock;


	if (Stock < Quan)
	{
		return 2;
	}
	else
	{
		Stock -= Quan;
		std::string st = std::to_string(Stock);

		amount = Quan * Pr;
		std::string Amount = std::to_string(amount);
		
		std::string sql_in, sql_up;
		sql_in = "insert into bill (isbn,catagory,amount) values('" + Isbn + " ','income', " + Amount + ")";
		sql_up = "update book set stock = " + st + " where isbn = '" + Isbn + "'";

		PGresult* res1 = PQexec(conn, sql_in.c_str());
		PGresult* res2 = PQexec(conn, sql_up.c_str());

		bool a, b;
		a = PQcmdTuples(res1) != "0";
		b = PQcmdTuples(res2) != "0";

		PQclear(res1);
		PQclear(res2);

		if (a && b)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

}

std::string SelBook::CStoS(const CString& a)
{
	CStringA b(a);
	return std::string(b);
}
