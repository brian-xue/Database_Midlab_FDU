#pragma once
#include<libpq-fe.h>
#include<afx.h>
#include<string>
class buyBook
{
public:
	buyBook();
	void init(const CString&Isbn,const CString&Title,const CString&Author,const CString& Publisher, const CString&Price, const CString&Quan);
	bool exec();
	std::string CStoS(const CString& a);

private:
	PGconn* conn;
	std::string isbn, title, author, publisher, price, quantity;
};

