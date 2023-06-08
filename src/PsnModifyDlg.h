#pragma once


// PsnModifyDlg 对话框

class PsnModifyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PsnModifyDlg)

public:
	PsnModifyDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~PsnModifyDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1_MdPer };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox psn_AttriBox;
	afx_msg void OnBnClickedButton1();
	int selNum;
	CString Val;
	int sig=0;
};
