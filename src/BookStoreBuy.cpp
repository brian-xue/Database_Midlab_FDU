// BookStoreBuy.cpp: 实现文件
//

#include "pch.h"
#include "BookStoreApplication.h"
#include "BookStoreBuy.h"
#include "afxdialogex.h"
#include "AddBookDlg.h"
#include"BuyDlg.h"
#include "PayDLG.h"
#include "BookPurchaseListDlg.h"


// BookStoreBuy 对话框

IMPLEMENT_DYNAMIC(BookStoreBuy, CDialogEx)

BookStoreBuy::BookStoreBuy(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2_BUY, pParent)
{

}

BookStoreBuy::~BookStoreBuy()
{
}

void BookStoreBuy::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(BookStoreBuy, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &BookStoreBuy::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &BookStoreBuy::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &BookStoreBuy::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6_CkButList, &BookStoreBuy::OnBnClickedButton6Ckbutlist)
END_MESSAGE_MAP()


// BookStoreBuy 消息处理程序

//buy book
void BookStoreBuy::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	BuyDlg budlg;
	budlg.DoModal();
}


//pay or cancel
void BookStoreBuy::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	PayDLG pydlg;
	pydlg.DoModal();
}









//add book
void BookStoreBuy::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	AddBookDlg adbdlg;
	adbdlg.DoModal();

}


void BookStoreBuy::OnBnClickedButton6Ckbutlist()
{
	// TODO: 在此添加控件通知处理程序代码
	BookPurchaseListDlg pdlg;
	pdlg.DoModal();
}
