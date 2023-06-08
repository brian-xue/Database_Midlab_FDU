#pragma once


// BookModifyDlg 对话框

class BookModifyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BookModifyDlg)

public:
	BookModifyDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~BookModifyDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1_BookModify };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1Confirm();
	int sel_Attribute;
	CString Val;
	CComboBox attri_sel;
	int sig;
};
