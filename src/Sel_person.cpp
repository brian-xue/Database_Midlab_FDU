#include "pch.h"
#include "Sel_person.h"
#include "MD5.h"

Sel_person::Sel_person(bool is, const CString& Un)
{
	char conninfo[120] = "host=127.0.0.1 user=postgres password=****** dbname=librarysys ";
	conn = PQconnectdb(conninfo);
	isSuperUser = is;
	CStringA U(Un);
	Username = U;
}

CString Sel_person::selUserName(int i)
{
	return CString(_T(resItems[i][0].c_str()));
}

CString Sel_person::selRealName(int i)
{
	return CString(_T(resItems[i][1].c_str()));
}

CString Sel_person::selWID(int i)
{
	return CString(_T(resItems[i][2].c_str()));
}

CString Sel_person::selGender(int i)
{
	return CString(_T(resItems[i][3].c_str()));
}

CString Sel_person::selPassword(int i)
{
	return CString(_T(resItems[i][4].c_str()));
}

CString Sel_person::selAge(int i)
{
	return CString(_T(resItems[i][5].c_str()));
}

int Sel_person::getRowNum()
{
	return resItems.size();
}

void Sel_person::init(int j)
{
	for (auto elem : resItems)
	{
		resItems.clear();
	}
	resItems.clear();

	std::string terminalTable;
	std::string condition;

	if (!isSuperUser)
	{
		condition = "where sname = '" + Username + "'";
	}
	else
	{
		condition = "";
	}

	if (j == 0)
	{
		terminalTable = "common_user";
	}
	else
	{
		terminalTable = "super_user";
	}
	
	std::string sql = "select * from " + terminalTable + " " + condition;

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

int Sel_person::PersonModify(int atr, int tb, const CString& val, const CString& us)
{
	CStringA Val(val);
	std::string value(Val);

	CStringA US(us);
	std::string pname(US);
	std::string appendix;
	appendix = "where sname = '"+pname+"'";

	std::string TableNam;
	if (tb == 0)
	{
		TableNam = "common_user";
	}
	else
	{
		TableNam = "super_user ";
	}

	std::string preUp;
	std::string sql;
	if (atr == 0)
	{
		preUp = "select sname from " + TableNam + " where sname = '" + value + "'";//check if the username is existed
		
		PGresult* res = PQexec(conn, preUp.c_str());

		if (PQntuples(res) != 0)
		{	
			PQclear(res);
			return 1;
		}
		else
		{
			sql = "update " + TableNam + " set sname = '" + value + "'"+appendix;
			res = PQexec(conn, sql.c_str());
			if (PQcmdTuples(res) != 0)
			{
				PQclear(res);
				return 0;
			}
			else
			{
				PQclear(res);
				return 2;
			}
		}
		
	}
	else if (atr == 1)
	{
		sql = "update " + TableNam + " set realname = '" + value + "'"+appendix;
		PGresult* res = PQexec(conn, sql.c_str());
		if (PQcmdTuples(res) != 0)
		{
			PQclear(res);
			return 0;
		}
		else
		{
			PQclear(res);
			return 2;
		}
	}
	else if (atr == 4)
	{
		std::string md5ps;
		MD5 ts;
		md5ps = ts.encode(value);
		sql = "update " + TableNam + " set password = '" + md5ps + "'" + appendix;
		PGresult* res = PQexec(conn, sql.c_str());
		if (PQcmdTuples(res) != 0)
		{
			PQclear(res);
			return 0;
		}
		else
		{
			PQclear(res);
			return 2;
		}
	}
	else if (atr == 3)
	{
		sql = "update " + TableNam + " set gender = '" + value + "'" + appendix;
		PGresult* res = PQexec(conn, sql.c_str());
		if (PQcmdTuples(res) != 0)
		{
			PQclear(res);
			return 0;
		}
		else
		{
			PQclear(res);
			return 2;
		}
	}
	else if (atr == 2)
	{
		sql = "update " + TableNam + " set w_id = '" + value + "'" + appendix;
		PGresult* res = PQexec(conn, sql.c_str());
		if (PQcmdTuples(res) != 0)
		{
			PQclear(res);
			return 0;
		}
		else
		{
			PQclear(res);
			return 2;
		}
	}
	else if (atr == 5)
	{
		sql = "update " + TableNam + " set age = " + value + appendix;
		PGresult* res = PQexec(conn, sql.c_str());
		if (PQcmdTuples(res) != 0)
		{
			PQclear(res);
			return 0;
		}
		else
		{
			PQclear(res);
			return 2;
		}
	}
	
}
