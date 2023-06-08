#pragma once
#include<libpq-fe.h>
#include"afx.h"
#include<string>
#include<vector>
class SelBook
{public:
	SelBook();
	~SelBook()
	{
		for (auto elem : resItems)
		{
			resItems.clear();
		}
		resItems.clear();
	}

	void init();
	std::vector<std::vector<std::string>> resItems;
	CString SelIsbn(int i);
	CString SelNo(int i);
	CString SelTitle(int i);
	CString SelAuthor(int i);
	CString SelPublisher(int i);
	CString SelPrice(int i);
	CString SelStock(int i);
	void ConditionalQuery(int c,const CString & v);
	int getRowNum();

	bool ModifyBook(int p, const CString & line ,const CString& v);
	int SellBook(const CString& isbn,const CString& quan, const CString& price, const CString& stock);
	std::string CStoS(const CString& a);

private:
	PGconn* conn;

};

