#pragma once


// PersonQuery 对话框

class PersonQuery : public CDialogEx
{
	DECLARE_DYNAMIC(PersonQuery)

public:
	PersonQuery(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~PersonQuery();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1_PerQ };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	bool isSu;
	CString Un;
	CListCtrl person_List;
	CComboBox su_CuSel;
	afx_msg void OnBnClickedButton2Check();
	afx_msg void OnBnClickedButton1Modify();
	virtual BOOL OnInitDialog();
};
