// AddBookDlg.cpp: 实现文件
//

#include "pch.h"
#include "BookStoreApplication.h"
#include "AddBookDlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include "sel_BookPurchase.h"


// AddBookDlg 对话框

IMPLEMENT_DYNAMIC(AddBookDlg, CDialogEx)

AddBookDlg::AddBookDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1_AddBook, pParent)
{

}

AddBookDlg::~AddBookDlg()
{
}

void AddBookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1_AddB, AddBook_List);
}


BEGIN_MESSAGE_MAP(AddBookDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1_AdConfirm, &AddBookDlg::OnBnClickedButton1Adconfirm)
END_MESSAGE_MAP()


// AddBookDlg 消息处理程序


BOOL AddBookDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	AddBook_List.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	sel_BookPurchase s1;
	s1.selForAdd();

	AddBook_List.InsertColumn(0, _T("PurchaseNo"), 0, 100);
	AddBook_List.InsertColumn(1, _T("ISBN"), 0, 200);
	AddBook_List.InsertColumn(2, _T("Title"), 0, 200);
	AddBook_List.InsertColumn(3, _T("Author"), 0, 200);
	AddBook_List.InsertColumn(4, _T("Publisher"), 0, 200);
	AddBook_List.InsertColumn(5, _T("Price"), 0, 150);
	AddBook_List.InsertColumn(6, _T("Paid Status"), 0, 100);
	AddBook_List.InsertColumn(7, _T("Quantity"), 0, 150);

	for (int i = 0; i < s1.getRowNum(); i++)
	{
		AddBook_List.InsertItem(i, s1.GetPurNo(i));
		AddBook_List.SetItemText(i, 1, s1.GetIsbn(i));
		AddBook_List.SetItemText(i, 2, s1.GetTitle(i));
		AddBook_List.SetItemText(i, 3, s1.GetAuthor(i));
		AddBook_List.SetItemText(i, 4, s1.GetPublisher(i));
		AddBook_List.SetItemText(i, 5, s1.GetPrice(i));
		AddBook_List.SetItemText(i, 6, s1.GetPayStatus(i));
		AddBook_List.SetItemText(i, 7, s1.GetQuantity(i));
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void AddBookDlg::OnBnClickedButton1Adconfirm()
{
	// TODO: 在此添加控件通知处理程序代码
	int count = 0;
	for (int i = 0; i < AddBook_List.GetItemCount(); i++)
	{
		BOOL state = AddBook_List.GetCheck(i);
		if (state)
		{
			count++;
		}
	}
	if (count > 1)
	{
		MessageBox(_T("You Can Only Add One Book at One Time"));
		return;
	}
	
	CString Pri;
	GetDlgItemText(IDC_EDIT1_SEPrice, Pri);

	
	sel_BookPurchase s2;
	
	for (int i = 0; i < AddBook_List.GetItemCount(); i++)
	{

		BOOL state = AddBook_List.GetCheck(i);
		if (state)
		{
			int res = s2.AddBook(AddBook_List.GetItemText(i, 0), AddBook_List.GetItemText(i, 1), AddBook_List.GetItemText(i, 2),
				AddBook_List.GetItemText(i, 3), AddBook_List.GetItemText(i, 4), AddBook_List.GetItemText(i, 7), Pri);
			if (res==0)
			{

				MessageBox(_T("Adding Succeeded"));
			}
			else if(res==1)
			{
				MessageBox(_T("Adding Failed"));
			}
			else
			{
				MessageBox(_T("Price Cannot Be Empty"));
			}
		}
	}
	AddBook_List.DeleteAllItems();
	s2.selForAdd();
	for (int i = 0; i < s2.getRowNum(); i++)
	{
		AddBook_List.InsertItem(i, s2.GetPurNo(i));
		AddBook_List.SetItemText(i, 1, s2.GetIsbn(i));
		AddBook_List.SetItemText(i, 2, s2.GetTitle(i));
		AddBook_List.SetItemText(i, 3, s2.GetAuthor(i));
		AddBook_List.SetItemText(i, 4, s2.GetPublisher(i));
		AddBook_List.SetItemText(i, 5, s2.GetPrice(i));
		AddBook_List.SetItemText(i, 6, s2.GetPayStatus(i));
		AddBook_List.SetItemText(i, 7, s2.GetQuantity(i));
	}

}
