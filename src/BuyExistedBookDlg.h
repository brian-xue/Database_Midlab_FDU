#pragma once


// BuyExistedBookDlg 对话框

class BuyExistedBookDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BuyExistedBookDlg)

public:
	BuyExistedBookDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~BuyExistedBookDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1_BEB };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString Quan;
	afx_msg void OnBnClickedButton1();
	int sig;
};
