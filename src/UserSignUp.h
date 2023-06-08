#pragma once
#include<string>
#include"afx.h"
#include<libpq-fe.h>

class UserSignUp
{
public:
	UserSignUp();
	~UserSignUp(){}

	int SignUp(const CString& sname, const CString& rname, const CString& wid, int gndr, const CString&password, const CString&age);

	std::string CStoS(const CString& a);
private:
	PGconn* conn;
};

