#pragma once


// BookStoreSell 对话框

class BookStoreSell : public CDialogEx
{
	DECLARE_DYNAMIC(BookStoreSell)

public:
	BookStoreSell(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~BookStoreSell();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3_SELL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl sellBook_list;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
};
