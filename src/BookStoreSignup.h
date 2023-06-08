#pragma once


// BookStoreSignup 对话框

class BookStoreSignup : public CDialogEx
{
	DECLARE_DYNAMIC(BookStoreSignup)

public:
	BookStoreSignup(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~BookStoreSignup();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1_SignUp };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox Idc_GenderComb;
	afx_msg void OnBnClickedButton1Sgu();
};
