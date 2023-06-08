// BillQuery.cpp: 实现文件
//

#include "pch.h"
#include "BookStoreApplication.h"
#include "BillQuery.h"
#include "afxdialogex.h"
#include "resource.h"
#include"Sel_Bill.h"


// BillQuery 对话框

IMPLEMENT_DYNAMIC(BillQuery, CDialogEx)

BillQuery::BillQuery(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2_BillQ, pParent)
{

}

BillQuery::~BillQuery()
{
}

void BillQuery::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1_BillList, bill_List);
}


BEGIN_MESSAGE_MAP(BillQuery, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &BillQuery::OnBnClickedButton1)
END_MESSAGE_MAP()


// BillQuery 消息处理程序


BOOL BillQuery::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	bill_List.InsertColumn(0, _T("BillNo"), 0, 200);
	bill_List.InsertColumn(1, _T("ISBN"), 0, 200);
	bill_List.InsertColumn(2, _T("Catagory"), 0, 200);//buy or sell
	bill_List.InsertColumn(3, _T("Amount"), 0, 200);
	bill_List.InsertColumn(4, _T("Time"), 0, 300);

	Sel_Bill s1;
	s1.init();

	for (int i = 0; i < s1.getRowNum(); i++)
	{
		bill_List.InsertItem(i, s1.selNo(i));
		bill_List.SetItemText(i, 1, s1.selIsbn(i));
		bill_List.SetItemText(i, 2, s1.selCata(i));
		bill_List.SetItemText(i, 3, s1.selAmount(i));
		bill_List.SetItemText(i, 4, s1.selTime(i));
	}


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void BillQuery::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString LwB, UpB;
	GetDlgItemText(IDC_EDIT1_LwB, LwB);
	GetDlgItemText(IDC_EDIT2_UpB, UpB);
	Sel_Bill s2;
	if (LwB.IsEmpty() && UpB.IsEmpty())
	{
		s2.init();
	}
	else
	{
		s2.ConditionalQuery(LwB, UpB);
	}

	bill_List.DeleteAllItems();
	for (int i = 0; i < s2.getRowNum(); i++)
	{
		bill_List.InsertItem(i, s2.selNo(i));
		bill_List.SetItemText(i, 1, s2.selIsbn(i));
		bill_List.SetItemText(i, 2, s2.selCata(i));
		bill_List.SetItemText(i, 3, s2.selAmount(i));
		bill_List.SetItemText(i, 4, s2.selTime(i));
	}
	
}
