#pragma once
#include<libpq-fe.h>
#include<vector>
#include"afx.h"
#include<string>
class Sel_Bill
{
public:
	Sel_Bill();
	~Sel_Bill()
	{
		for (auto elem : resItems)
		{
			resItems.clear();
		}
		resItems.clear();
	}
	void init();
	std::vector<std::vector<std::string>> resItems;

	void ConditionalQuery(const CString& lw, const CString& up);
	
	CString selNo(int i);
	CString selIsbn(int i);
	CString selCata(int i);
	CString selAmount(int i);
	CString selTime(int i);

	std::string CStoS(const CString& a);

	int getRowNum();

private:
	PGconn* conn;
};

