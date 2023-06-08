#pragma once


// BuyNewBook 对话框

class BuyNewBook : public CDialogEx
{
	DECLARE_DYNAMIC(BuyNewBook)

public:
	BuyNewBook(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~BuyNewBook();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString Isbn, Title, Author, Publisher, Price, Quantity;
	int sig=0;
};
