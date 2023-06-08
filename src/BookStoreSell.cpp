// BookStoreSell.cpp: 实现文件
//

#include "pch.h"
#include "BookStoreApplication.h"
#include "BookStoreSell.h"
#include "afxdialogex.h"
#include "resource.h"
#include "SelBook.h"


// BookStoreSell 对话框

IMPLEMENT_DYNAMIC(BookStoreSell, CDialogEx)

BookStoreSell::BookStoreSell(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3_SELL, pParent)
{

}

BookStoreSell::~BookStoreSell()
{
}

void BookStoreSell::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1_SellBook_List, sellBook_list);
}


BEGIN_MESSAGE_MAP(BookStoreSell, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &BookStoreSell::OnBnClickedButton1)
END_MESSAGE_MAP()


// BookStoreSell 消息处理程序


BOOL BookStoreSell::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	sellBook_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	sellBook_list.InsertColumn(0, _T("ISBN"), 0, 200);
	sellBook_list.InsertColumn(1, _T("BookNo"), 0, 100);
	sellBook_list.InsertColumn(2, _T("Title"), 0, 200);
	sellBook_list.InsertColumn(3, _T("Author"), 0, 200);
	sellBook_list.InsertColumn(4, _T("Publisher"), 0, 200);
	sellBook_list.InsertColumn(5, _T("Price"), 0, 150);
	sellBook_list.InsertColumn(6, _T("Stock"), 0, 100);

	SelBook s1;
	s1.init();

	for (int i = 0; i < s1.getRowNum(); i++)
	{
		sellBook_list.InsertItem(i, s1.SelIsbn(i));//isbn
		sellBook_list.SetItemText(i, 1, s1.SelNo(i));//bookNo
		sellBook_list.SetItemText(i, 2, s1.SelTitle(i));//Title
		sellBook_list.SetItemText(i, 3, s1.SelAuthor(i));//Author
		sellBook_list.SetItemText(i, 4, s1.SelPublisher(i));//Publisher
		sellBook_list.SetItemText(i, 5, s1.SelPrice(i));//price
		sellBook_list.SetItemText(i, 6, s1.SelStock(i));//Stock
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void BookStoreSell::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	int count = 0;
	for (int i = 0; i < sellBook_list.GetItemCount(); i++)
	{

		BOOL state = sellBook_list.GetCheck(i);
		if (state)
		{
			count++;
		}
	}
	if (count > 1)
	{
		MessageBox(_T("You Can Only Sell One Item at One Time!"));
		return;
	}
	else
	{
		for (int i = 0; i < sellBook_list.GetItemCount(); i++)
		{
			BOOL state = sellBook_list.GetCheck(i);
			if (state)
			{
				
				SelBook buk;
				buk.init();
				CString Quantity;
				GetDlgItemText(IDC_EDIT1, Quantity);
				int res = buk.SellBook(sellBook_list.GetItemText(i, 0), Quantity, sellBook_list.GetItemText(i, 5), sellBook_list.GetItemText(i, 6));
				if (res == 0)
				{
					MessageBox(_T("Business Succeeded"));

					sellBook_list.DeleteAllItems();
					SelBook s2;
					s2.init();

					for (int i = 0; i < s2.getRowNum(); i++)
					{
						sellBook_list.InsertItem(i, s2.SelIsbn(i));//isbn
						sellBook_list.SetItemText(i, 1, s2.SelNo(i));//bookNo
						sellBook_list.SetItemText(i, 2, s2.SelTitle(i));//Title
						sellBook_list.SetItemText(i, 3, s2.SelAuthor(i));//Author
						sellBook_list.SetItemText(i, 4, s2.SelPublisher(i));//Publisher
						sellBook_list.SetItemText(i, 5, s2.SelPrice(i));//price
						sellBook_list.SetItemText(i, 6, s2.SelStock(i));//Stock
					}
				}
				else
				{
					if(res == 1)
					MessageBox(_T("Business Failed"));
					else
					{
						MessageBox(_T("Inventory Insufficient"));
					}
				}
			}
		}
	}

}
