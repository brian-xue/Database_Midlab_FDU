#pragma once
#include<libpq-fe.h>
#include<afx.h>
#include<string>
class user
{
public:
	user(const CString& user, const CString& password, PGconn* con);

	bool isSuperUser();
	int login();


private:
	std::string username;
	std::string password;
	PGconn* conn;
};

