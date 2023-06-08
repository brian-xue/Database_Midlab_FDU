// BookPurchaseListDlg.cpp: 实现文件
//

#include "pch.h"
#include "BookStoreApplication.h"
#include "BookPurchaseListDlg.h"
#include "afxdialogex.h"
#include "sel_BookPurchase.h"


// BookPurchaseListDlg 对话框

IMPLEMENT_DYNAMIC(BookPurchaseListDlg, CDialogEx)

BookPurchaseListDlg::BookPurchaseListDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1_BKPurList, pParent)
{

}

BookPurchaseListDlg::~BookPurchaseListDlg()
{
}

void BookPurchaseListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1_BkPur_list, pur_List);
}


BEGIN_MESSAGE_MAP(BookPurchaseListDlg, CDialogEx)
END_MESSAGE_MAP()


// BookPurchaseListDlg 消息处理程序


BOOL BookPurchaseListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	pur_List.InsertColumn(0, _T("PurchaseNo"), 0, 100);
	pur_List.InsertColumn(1, _T("ISBN"), 0, 200);
	pur_List.InsertColumn(2, _T("Title"), 0, 200);
	pur_List.InsertColumn(3, _T("Author"), 0, 200);
	pur_List.InsertColumn(4, _T("Publisher"), 0, 200);
	pur_List.InsertColumn(5, _T("Price"), 0, 150);
	pur_List.InsertColumn(6, _T("Paid Status"), 0, 100);
	pur_List.InsertColumn(7, _T("Quantity"), 0, 150);

	sel_BookPurchase s1;
	s1.init();

	for (int i = 0; i < s1.getRowNum(); i++)
	{
		pur_List.InsertItem(i, s1.GetPurNo(i));
		pur_List.SetItemText(i, 1, s1.GetIsbn(i));
		pur_List.SetItemText(i, 2, s1.GetTitle(i));
		pur_List.SetItemText(i, 3, s1.GetAuthor(i));
		pur_List.SetItemText(i, 4, s1.GetPublisher(i));
		pur_List.SetItemText(i, 5, s1.GetPrice(i));
		pur_List.SetItemText(i, 6, s1.GetPayStatus(i));
		pur_List.SetItemText(i, 7, s1.GetQuantity(i));
	}



	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
