#pragma once


// BookPurchaseListDlg 对话框

class BookPurchaseListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BookPurchaseListDlg)

public:
	BookPurchaseListDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~BookPurchaseListDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1_BKPurList };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl pur_List;
};
