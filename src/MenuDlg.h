#pragma once


// MenuDlg 对话框

class MenuDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MenuDlg)

public:
	MenuDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MenuDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2Qry();
	afx_msg void OnBnClickedButton3Buy();
	afx_msg void OnBnClickedButton4Sel();
	afx_msg void OnBnClickedButton5Sgnu();

	bool is_SU;//is superuser
	CString Un;//user name
};
