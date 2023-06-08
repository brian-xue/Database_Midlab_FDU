// BookQuery.cpp: 实现文件
//

#include "pch.h"
#include "BookStoreApplication.h"
#include "BookQuery.h"
#include "afxdialogex.h"
#include "SelBook.h"
#include "resource.h"
#include "BookModifyDlg.h"

// BookQuery 对话框

IMPLEMENT_DYNAMIC(BookQuery, CDialogEx)

BookQuery::BookQuery(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1_bookQ, pParent)
{

}

BookQuery::~BookQuery()
{
}

void BookQuery::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2_BookList, bookList);
	DDX_Control(pDX, IDC_COMBO1_ConSel, m_selectBox);
}


BEGIN_MESSAGE_MAP(BookQuery, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1_SelConfirm, &BookQuery::OnBnClickedButton1Selconfirm)
	ON_CBN_SELCHANGE(IDC_COMBO1_ConSel, &BookQuery::OnCbnSelchangeCombo1Consel)
	ON_BN_CLICKED(IDC_BUTTON1, &BookQuery::OnBnClickedButton1)
END_MESSAGE_MAP()


// BookQuery 消息处理程序


BOOL BookQuery::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	bookList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	bookList.InsertColumn(0, _T("ISBN"),0,200);
	bookList.InsertColumn(1, _T("BookNo"),0,100);
	bookList.InsertColumn(2, _T("Title"),0,200);
	bookList.InsertColumn(3, _T("Author"),0,200);
	bookList.InsertColumn(4, _T("Publisher"),0,200);
	bookList.InsertColumn(5, _T("Price"),0,150);
	bookList.InsertColumn(6, _T("Stock"),0,100);

	m_selectBox.AddString(_T("请选择"));
	m_selectBox.AddString(_T("ISBN"));
	m_selectBox.AddString(_T("Title"));
	m_selectBox.AddString(_T("Author"));
	m_selectBox.AddString(_T("Publisher"));
	m_selectBox.AddString(_T("BookNo"));
	m_selectBox.SetCurSel(0);

	

	SelBook s1;
	s1.init();

	for (int i = 0; i < s1.getRowNum(); i++)
	{
		bookList.InsertItem(i, s1.SelIsbn(i));//isbn
		bookList.SetItemText(i, 1, s1.SelNo(i));//bookNo
		bookList.SetItemText(i, 2, s1.SelTitle(i));//Title
		bookList.SetItemText(i, 3, s1.SelAuthor(i));//Author
		bookList.SetItemText(i, 4, s1.SelPublisher(i));//Publisher
		bookList.SetItemText(i, 5, s1.SelPrice(i));//price
		bookList.SetItemText(i, 6, s1.SelStock(i));//Stock
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


int SelBoxItem=0;

void BookQuery::OnBnClickedButton1Selconfirm()
{
	CString Val;
	GetDlgItemText(IDC_EDIT1_conSelV, Val);

	if (Val.IsEmpty()&&SelBoxItem!=0)
	{
		MessageBox(_T("The Value cannot be empty"));
	}
	else
	{
		SelBook s2;
		s2.ConditionalQuery(SelBoxItem, Val);

		bookList.DeleteAllItems();
		for (int i = 0; i < s2.getRowNum(); i++)
		{
			bookList.InsertItem(i, s2.SelIsbn(i));//isbn
			bookList.SetItemText(i, 1, s2.SelNo(i));//bookNo
			bookList.SetItemText(i, 2, s2.SelTitle(i));//Title
			bookList.SetItemText(i, 3, s2.SelAuthor(i));//Author
			bookList.SetItemText(i, 4, s2.SelPublisher(i));//Publisher
			bookList.SetItemText(i, 5, s2.SelPrice(i));//price
			bookList.SetItemText(i, 6, s2.SelStock(i));//Stock
		}

	}
}


void BookQuery::OnCbnSelchangeCombo1Consel()
{
	SelBoxItem = m_selectBox.GetCurSel();
}


void BookQuery::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	int count = 0;
	for (int i = 0; i < bookList.GetItemCount(); i++)
	{
		
		BOOL state = bookList.GetCheck(i);
		if (state)
		{
			count++;
		}
	}
	if (count > 1)
	{
		MessageBox(_T("You Can Only Modify One Item at One Time!"));
		return;
	}
	else
	{
		for (int i = 0; i < bookList.GetItemCount(); i++)
		{
			BOOL state = bookList.GetCheck(i);
			if (state)
			{
				BookModifyDlg dlg;
				dlg.DoModal();
				CString bkno = bookList.GetItemText(i,1);
				SelBook s3;
				if (dlg.Val.IsEmpty()||dlg.sig==0)
				{
					return;
				}
				if (s3.ModifyBook(dlg.sel_Attribute, bkno, dlg.Val))
				{
					MessageBox(_T("Modify Success"));
					s3.init();
					bookList.DeleteAllItems();
					for (int i = 0; i < s3.getRowNum(); i++)
					{
						bookList.InsertItem(i, s3.SelIsbn(i));//isbn
						bookList.SetItemText(i, 1, s3.SelNo(i));//bookNo
						bookList.SetItemText(i, 2, s3.SelTitle(i));//Title
						bookList.SetItemText(i, 3, s3.SelAuthor(i));//Author
						bookList.SetItemText(i, 4, s3.SelPublisher(i));//Publisher
						bookList.SetItemText(i, 5, s3.SelPrice(i));//price
						bookList.SetItemText(i, 6, s3.SelStock(i));//Stock
					}

				}
				else
				{
					MessageBox(_T("Modify Failed"));
				}
				
			}
		}
		
		

	}
	

}
