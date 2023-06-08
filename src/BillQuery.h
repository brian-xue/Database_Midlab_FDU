#pragma once


// BillQuery 对话框

class BillQuery : public CDialogEx
{
	DECLARE_DYNAMIC(BillQuery)

public:
	BillQuery(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~BillQuery();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2_BillQ };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl bill_List;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
};
