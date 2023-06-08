#pragma once


// AddBookDlg 对话框

class AddBookDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddBookDlg)

public:
	AddBookDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~AddBookDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1_AddBook };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl AddBook_List;
	afx_msg void OnBnClickedButton1Adconfirm();
};
