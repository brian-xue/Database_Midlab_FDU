#pragma once


// BuyDlg 对话框

class BuyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BuyDlg)

public:
	BuyDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~BuyDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1_BuyDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl Bk_list;
	afx_msg void OnBnClickedButton1Buyod();
	afx_msg void OnBnClickedButton2Buynw();
};
