#pragma once
#include<libpq-fe.h>
#include<string>
#include"afx.h"
#include<vector>

class sel_BookPurchase
{
public:
	sel_BookPurchase();
	~sel_BookPurchase() {
		for (auto elem : resItems)
		{
			resItems.clear();
		}
		resItems.clear();
	}
	void init();
	std::vector<std::vector<std::string>> resItems;
	void selForPay();
	void selForAdd();

	CString GetPurNo(int i);
	CString GetIsbn(int i);
	CString GetTitle(int i);
	CString GetAuthor(int i);
	CString GetPublisher(int i);
	CString GetPrice(int i);
	CString GetPayStatus(int i);
	CString GetQuantity(int i);

	bool payBill(const CString& isbn,const CString& bkNo,const CString& quan, const CString& priceIN);
	bool CancelBook(const CString& purNo);
	int AddBook(const CString& bkNo,const CString& isbn, const CString& title, const CString& author, const CString&publisher,const CString& quan, const CString& price);

	std::string CStoS(CString cs);
	int getRowNum();
private:
	PGconn* conn;
};

