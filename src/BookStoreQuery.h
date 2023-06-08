#pragma once


// BookStoreQuery 对话框

class BookStoreQuery : public CDialogEx
{
	DECLARE_DYNAMIC(BookStoreQuery)

public:
	BookStoreQuery(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~BookStoreQuery();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1_Query };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();

	bool is_Su;
	CString Un;
};
