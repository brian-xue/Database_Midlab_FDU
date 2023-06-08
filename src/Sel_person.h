#pragma once
#include<libpq-fe.h>
#include<string>
#include<vector>
#include"afx.h"


class Sel_person
{
public:
	Sel_person(bool is, const CString& Un);
	~Sel_person()
	{
		for (auto elem : resItems)
		{
			resItems.clear();
		}
		resItems.clear();
	}

	std::vector<std::vector<std::string>> resItems;
	CString selUserName(int i);
	CString selRealName(int i);
	CString selWID(int i);
	CString selGender(int i);
	CString selPassword(int i);
	CString selAge(int i);
	int getRowNum();
	void init(int j);

	int PersonModify(int atr, int tb, const CString& val, const CString& us);


private:
	bool isSuperUser;
	std::string Username;
	PGconn* conn;
};

