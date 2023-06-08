#include "pch.h"
#include "sel_BookPurchase.h"
#include <sstream>

sel_BookPurchase::sel_BookPurchase()
{
	char conninfo[120] = "host=127.0.0.1 user=postgres password=****** dbname=librarysys ";
	conn = PQconnectdb(conninfo);
}

void sel_BookPurchase::init()
{
	for (auto elem : resItems)
	{
		resItems.clear();
	}
	resItems.clear();

	PGresult* res = PQexec(conn, "select * from bookpurchase");
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

void sel_BookPurchase::selForPay()
{
	for (auto elem : resItems)
	{
		resItems.clear();
	}
	resItems.clear();
	
	PGresult* res = PQexec(conn, "select * from bookpurchase where paidstatus = 0");
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

void sel_BookPurchase::selForAdd()
{
	for (auto elem : resItems)
	{
		resItems.clear();
	}
	resItems.clear();

	PGresult* res = PQexec(conn, "select * from bookpurchase where paidstatus = 1");
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

CString sel_BookPurchase::GetPurNo(int i)
{
	return CString(_T(resItems[i][6].c_str()));
}

CString sel_BookPurchase::GetIsbn(int i)
{
	return CString(_T(resItems[i][0].c_str()));
}

CString sel_BookPurchase::GetTitle(int i)
{
	return CString(_T(resItems[i][1].c_str()));
}

CString sel_BookPurchase::GetAuthor(int i)
{
	return CString(_T(resItems[i][2].c_str()));
}

CString sel_BookPurchase::GetPublisher(int i)
{
	return CString(_T(resItems[i][3].c_str()));
}

CString sel_BookPurchase::GetPrice(int i)
{
	return CString(_T(resItems[i][7].c_str()));
}

CString sel_BookPurchase::GetPayStatus(int i)
{
	std::string result;
	if (resItems[i][5] == "0")
	{
		result = "unpaid";
	}
	else if (resItems[i][5] == "1")
	{
		result = "paid";
	}
	else
	{
		result = "cancel";
	}
	return CString(_T(result.c_str()));
}

CString sel_BookPurchase::GetQuantity(int i)
{
	return CString(_T(resItems[i][4].c_str()));
}

bool sel_BookPurchase::payBill(const CString& isbn, const CString& bkNo,const CString& quan,const CString& price)
{
	CStringA isbn_a(isbn);
	CStringA bkno_a(bkNo);
	CStringA quan_a(quan);
	CStringA price_a(price);

	int quantity;
	double Price, amount;

	std::string isbn_s(isbn_a);
	std::string bkno_s(bkno_a);
	std::string quan_s(quan_a);
	std::string price_s(price_a);

	std::istringstream iss(quan_s);
	iss >> quantity;

	iss.clear();
	iss.str(price_s);
	iss >> Price;

	amount = quantity * Price;

	std::string amount_s = std::to_string(amount);


	std::string sql_up = "update bookpurchase set paidstatus = 1 where purchaseno = " + bkno_s ;

	std::string sql_in = "insert into bill (isbn,catagory,amount) values( '" + isbn_s + "' , 'outcome'," + amount_s + ")";

	PGresult* res1 = PQexec(conn, sql_up.c_str());
	PGresult* res2 = PQexec(conn, sql_in.c_str());

	bool a = PQcmdTuples(res1) != "0";
	bool b = PQcmdTuples(res2) != "0";

	PQclear(res1);
	PQclear(res2);

	if (a && b)
	{
		return true;
	}
	else
	{
	return false;
	}
}


bool sel_BookPurchase::CancelBook(const CString& purNo)
{
	CStringA purNo_a(purNo);

	std::string pNo(purNo_a);

	std::string sql = "update bookpurchase set paidstatus = 2 where purchaseno = "+pNo;

	PGresult*res =PQexec(conn, sql.c_str());

	bool a = PQcmdStatus(res) != "0";
	PQclear(res);
	if (a)
	{
		return true;
	}
	else
	{
	return false;
	}
}
int sel_BookPurchase::AddBook(const CString& bkNo,const CString& isbn, const CString& title, const CString& author, const CString& publisher, const CString& quan, const CString& price)
{
	std::string sql;
	std::string Isbn;
	std::string bkno_s;

	CStringA isbn_a(isbn);
	CStringA bkNo_a(bkNo);

	bkno_s = bkNo_a;

	CStringA quantity(quan);
	std::string Quan(quantity);
	int Quantity;

	std::istringstream iss(Quan);
	iss >> Quantity;
	iss.clear();

	Isbn = isbn_a;
	sql = "select * from book where isbn = '" + Isbn + "'";

	bool a=false, b=false;//check if success

	PGresult* res = PQexec(conn, sql.c_str());
	if (PQntuples(res) > 0)//book that has existed
	{
		std::string stock_s = PQgetvalue(res, 0, 6);
		int stock;
		iss.str(stock_s);
		iss >> stock;
		stock += Quantity;

		stock_s = std::to_string(stock);
		std::string sql_up1 = "update book set stock =" + stock_s + " where isbn = '" + Isbn + "'";
		PGresult* res1 = PQexec(conn, sql_up1.c_str());
		a = PQcmdTuples(res1) != "0";
		PQclear(res1);

	}
	else
	{
		std::string Title = CStoS(title);
		std::string Author = CStoS(author);
		std::string Publisher = CStoS(publisher);
		std::string Price = CStoS(price);

		if (Price.empty())
		{
			return 2;
		}

		std::string sql_in = "insert into book (isbn,title,author,publisher,price,stock) values('" + Isbn + "' , '" + Title + "' , '" + Author + "' , '" + Publisher + "' , " + Price + "," + Quan + ")";
		PGresult* res2 = PQexec(conn, sql_in.c_str());
		b = PQcmdTuples(res2)!="0";
		PQclear(res2);
	}
	PQclear(res);

	if (a || b)
	{
		std::string sql_del = "delete from bookpurchase where purchaseno = " + bkno_s;
		PGresult* res3 = PQexec(conn, sql_del.c_str());
		bool c = PQcmdTuples(res3) != "0";
		PQclear(res3);
		if (c)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 1;
	}


	
}



std::string sel_BookPurchase::CStoS(CString cs)
{
	CStringA cs_a(cs);
	std::string cs_s(cs_a);
	return cs_s;
}

int sel_BookPurchase::getRowNum()
{
	return resItems.size();
}

