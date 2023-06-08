// BookStoreQuery.cpp: 实现文件
//

#include "pch.h"
#include "BookStoreApplication.h"
#include "BookStoreQuery.h"
#include "afxdialogex.h"
#include "BookQuery.h"
#include "BillQuery.h"
#include "PersonQuery.h"


// BookStoreQuery 对话框

IMPLEMENT_DYNAMIC(BookStoreQuery, CDialogEx)

BookStoreQuery::BookStoreQuery(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1_Query, pParent)
{

}

BookStoreQuery::~BookStoreQuery()
{
}

void BookStoreQuery::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(BookStoreQuery, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &BookStoreQuery::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &BookStoreQuery::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &BookStoreQuery::OnBnClickedButton3)
END_MESSAGE_MAP()


// BookStoreQuery 消息处理程序


void BookStoreQuery::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	BookQuery bodlg;
	bodlg.DoModal();

}


void BookStoreQuery::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	BillQuery bidlg;
	bidlg.DoModal();
}


void BookStoreQuery::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	PersonQuery prdlg;
	prdlg.isSu = is_Su;
	prdlg.Un = Un;
	prdlg.DoModal();
}
