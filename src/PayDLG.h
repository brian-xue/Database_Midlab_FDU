#pragma once


// PayDLG 对话框

class PayDLG : public CDialogEx
{
	DECLARE_DYNAMIC(PayDLG)

public:
	PayDLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~PayDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1_PAYDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl Pay_List;
	afx_msg void OnBnClickedButton1Py();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1Cancel();
};
