#pragma once


// BookStoreBuy 对话框

class BookStoreBuy : public CDialogEx
{
	DECLARE_DYNAMIC(BookStoreBuy)

public:
	BookStoreBuy(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~BookStoreBuy();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2_BUY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6Ckbutlist();
};
