// BuyNewBook.cpp: 实现文件
//

#include "pch.h"
#include "BookStoreApplication.h"
#include "BuyNewBookDlg.h"
#include "afxdialogex.h"
#include "resource.h"


// BuyNewBook 对话框

IMPLEMENT_DYNAMIC(BuyNewBook, CDialogEx)

BuyNewBook::BuyNewBook(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1_BNewB, pParent)
{

}

BuyNewBook::~BuyNewBook()
{
}

void BuyNewBook::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(BuyNewBook, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &BuyNewBook::OnBnClickedButton1)
END_MESSAGE_MAP()


// BuyNewBook 消息处理程序


void BuyNewBook::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	sig = 1;
	GetDlgItemText(IDC_EDIT1_Isbn, Isbn);
	GetDlgItemText(IDC_EDIT2_Title, Title);
	GetDlgItemText(IDC_EDIT3_Aut, Author);
	GetDlgItemText(IDC_EDIT4_Pub, Publisher);
	GetDlgItemText(IDC_EDIT5_pri, Price);
	GetDlgItemText(IDC_EDIT6_Qua, Quantity);
	EndDialog(0);
}
