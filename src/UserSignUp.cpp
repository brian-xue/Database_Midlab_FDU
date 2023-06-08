#include "pch.h"
#include "UserSignUp.h"
#include "MD5.h"

UserSignUp::UserSignUp()
{
	char conninfo[120] = "host=127.0.0.1 user=postgres password=****** dbname=librarysys ";
	conn = PQconnectdb(conninfo);
}
int UserSignUp::SignUp(const CString& sname, const CString& rname, const CString& wid, int gndr, const CString& password, const CString& age)
{
	std::string Sname, Rname, Wid, Gender, Password, Age;
	Sname = CStoS(sname);
	Rname = CStoS(rname);
	Wid = CStoS(wid);
	Password = CStoS(password);
	Age = CStoS(age);

	if (gndr == 0)
	{
		Gender = "male";
	}
	else if(gndr==1)
	{
		Gender = "female";
	}
	else
	{
		Gender = "other";
	}

	MD5 m1;
	std::string md5_psword = m1.encode(Password);

	std::string sql1 = "select * from common_user where sname = '" + Sname + "'";
	PGresult* res1 = PQexec(conn, sql1.c_str());

	if (PQntuples(res1) != 0)
	{
		PQclear(res1);
		return 2;
	}
	else
	{
		PQclear(res1);

		std::string sql2 = "insert into common_user (sname,realname,w_id, gender, pass_word, age) values ('" + Sname + "','"+Rname+"','"+Wid+"','"+ Gender +"','"+ md5_psword +"',"+Age+")";
		PGresult* res2 = PQexec(conn, sql2.c_str());

		if (PQcmdTuples(res2) != "0")
		{
			PQclear(res2);
			return 0;
		}
		else
		{
			PQclear(res2);
			return 1;
		}
	}

	
	
}
std::string UserSignUp::CStoS(const CString& a)
{
	CStringA b(a);
	return std::string(b);
}
