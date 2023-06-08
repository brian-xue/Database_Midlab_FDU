// BuyDlg.cpp: 实现文件
//

#include "pch.h"
#include "BookStoreApplication.h"
#include "BuyDlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include "SelBook.h"
#include "buyBook.h"
#include "BuyExistedBookDlg.h"
#include "BuyNewBookDlg.h"


// BuyDlg 对话框

IMPLEMENT_DYNAMIC(BuyDlg, CDialogEx)

BuyDlg::BuyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1_BuyDLG, pParent)
{

}

BuyDlg::~BuyDlg()
{
}

void BuyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1_BKlist, Bk_list);
}


BEGIN_MESSAGE_MAP(BuyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1_BUYOD, &BuyDlg::OnBnClickedButton1Buyod)
	ON_BN_CLICKED(IDC_BUTTON2_BuyNw, &BuyDlg::OnBnClickedButton2Buynw)
END_MESSAGE_MAP()


// BuyDlg 消息处理程序


BOOL BuyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	Bk_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	Bk_list.InsertColumn(0, _T("ISBN"), 0, 200);
	Bk_list.InsertColumn(1, _T("BookNo"), 0, 100);
	Bk_list.InsertColumn(2, _T("Title"), 0, 200);
	Bk_list.InsertColumn(3, _T("Author"), 0, 200);
	Bk_list.InsertColumn(4, _T("Publisher"), 0, 200);
	Bk_list.InsertColumn(5, _T("Price"), 0, 150);
	Bk_list.InsertColumn(6, _T("Stock"), 0, 100);

	SelBook s1;
	s1.init();

	for (int i = 0; i < s1.getRowNum(); i++)
	{
		Bk_list.InsertItem(i, s1.SelIsbn(i));//isbn
		Bk_list.SetItemText(i, 1, s1.SelNo(i));//bookNo
		Bk_list.SetItemText(i, 2, s1.SelTitle(i));//Title
		Bk_list.SetItemText(i, 3, s1.SelAuthor(i));//Author
		Bk_list.SetItemText(i, 4, s1.SelPublisher(i));//Publisher
		Bk_list.SetItemText(i, 5, s1.SelPrice(i));//price
		Bk_list.SetItemText(i, 6, s1.SelStock(i));//Stock
	}


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void BuyDlg::OnBnClickedButton1Buyod()
{
	// TODO: 在此添加控件通知处理程序代码
	int count = 0;
	for (int i = 0; i < Bk_list.GetItemCount(); i++)
	{

		BOOL state = Bk_list.GetCheck(i);
		if (state)
		{
			count++;
		}
	}
	if (count > 1)
	{
		MessageBox(_T("You Can Only Buy One Item at One Time!"));
		return;
	}
	else
	{
		for (int i = 0; i < Bk_list.GetItemCount(); i++)
		{
			BOOL state= Bk_list.GetCheck(i);
			if (state)
			{
				BuyExistedBookDlg dlg;
				dlg.DoModal();
				if (dlg.Quan.IsEmpty()||dlg.sig==0)
				{
					return;
				}
				buyBook buk;
				buk.init(Bk_list.GetItemText(i, 0), Bk_list.GetItemText(i, 2), Bk_list.GetItemText(i, 3), Bk_list.GetItemText(i, 4), Bk_list.GetItemText(i, 5), dlg.Quan);
				if (buk.exec())
				{
					MessageBox(_T("Purchase Succeeded"));
					
					Bk_list.DeleteAllItems();
					SelBook s2;
					s2.init();

					for (int i = 0; i < s2.getRowNum(); i++)
					{
						Bk_list.InsertItem(i, s2.SelIsbn(i));//isbn
						Bk_list.SetItemText(i, 1, s2.SelNo(i));//bookNo
						Bk_list.SetItemText(i, 2, s2.SelTitle(i));//Title
						Bk_list.SetItemText(i, 3, s2.SelAuthor(i));//Author
						Bk_list.SetItemText(i, 4, s2.SelPublisher(i));//Publisher
						Bk_list.SetItemText(i, 5, s2.SelPrice(i));//price
						Bk_list.SetItemText(i, 6, s2.SelStock(i));//Stock
					}
				}
				else
				{
					MessageBox(_T("Purchase Failed"));
				}
			}
		}
	}

}


void BuyDlg::OnBnClickedButton2Buynw()
{
	// TODO: 在此添加控件通知处理程序代码
	BuyNewBook dlg;
	dlg.DoModal();
	if (dlg.sig == 0)
	{

		return;
	}
	if (dlg.Isbn.IsEmpty() || dlg.Title.IsEmpty() || dlg.Author.IsEmpty() || dlg.Publisher.IsEmpty() || dlg.Price.IsEmpty() || dlg.Quantity.IsEmpty())
	{
		MessageBox(_T("Values Cannot be empty"));
		return;
	}
	buyBook b1;
	b1.init(dlg.Isbn, dlg.Title, dlg.Author, dlg.Publisher, dlg.Price, dlg.Quantity);
	if (b1.exec())
	{
		MessageBox(_T("Purchase Succeeded"));
	}
	else
	{
		MessageBox(_T("Purchase Failed"));
	}
	
}


