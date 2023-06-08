#include "pch.h"
#include "Sel_Bill.h"

Sel_Bill::Sel_Bill()
{
	char conninfo[120] = "host=127.0.0.1 user=postgres password=****** dbname=librarysys ";
	conn = PQconnectdb(conninfo);
}

void Sel_Bill::init()
{
	for (auto elem : resItems)
	{
		resItems.clear();
	}
	resItems.clear();

	PGresult* res = PQexec(conn, "select * from bill");
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

void Sel_Bill::ConditionalQuery(const CString& lw, const CString& up)
{
	for (auto elem : resItems)
	{
		resItems.clear();
	}
	resItems.clear();

	std::string lw_s, up_s;
	lw_s = CStoS(lw);
	up_s = CStoS(up);

	std::string s1 = " where ";
	std::string s2 = "time <= '" + up_s+"'";
	std::string s3 = "time >= '" + lw_s+"'";
	std::string sql_b = "select * from bill ";
	std::string sql;
	if (lw_s.empty())
	{
		sql = sql_b + s1 + s2;
	}
	else if (up_s.empty())
	{
		sql = sql_b + s1 + s3;
	}
	else
	{
		sql = sql_b + s1 + s2 + " and " + s3;
	}

	

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

CString Sel_Bill::selNo(int i)
{
	return CString(_T(resItems[i][0].c_str()));
}

CString Sel_Bill::selIsbn(int i)
{
	return CString(_T(resItems[i][1].c_str()));
}

CString Sel_Bill::selCata(int i)
{
	return CString(_T(resItems[i][2].c_str()));
}

CString Sel_Bill::selAmount(int i)
{
	return CString(_T(resItems[i][3].c_str()));
}

CString Sel_Bill::selTime(int i)
{
	return CString(_T(resItems[i][4].c_str()));
}

std::string Sel_Bill::CStoS(const CString& a)
{
	CStringA b(a);
	return std::string(b);
}

int Sel_Bill::getRowNum()
{
	return resItems.size();
}


