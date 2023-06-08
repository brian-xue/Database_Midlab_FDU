#pragma once


// BookQuery 对话框

class BookQuery : public CDialogEx
{
	DECLARE_DYNAMIC(BookQuery)

public:
	BookQuery(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~BookQuery();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1_bookQ };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl bookList;
	CComboBox m_selectBox;
	afx_msg void OnBnClickedButton1Selconfirm();
	afx_msg void OnCbnSelchangeCombo1Consel();
	afx_msg void OnBnClickedButton1();
};
