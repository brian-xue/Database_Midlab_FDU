// BuyExistedBookDlg.cpp: 实现文件
//

#include "pch.h"
#include "BookStoreApplication.h"
#include "BuyExistedBookDlg.h"
#include "afxdialogex.h"


// BuyExistedBookDlg 对话框

IMPLEMENT_DYNAMIC(BuyExistedBookDlg, CDialogEx)

BuyExistedBookDlg::BuyExistedBookDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1_BEB, pParent)
{

}

BuyExistedBookDlg::~BuyExistedBookDlg()
{
}

void BuyExistedBookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(BuyExistedBookDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &BuyExistedBookDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// BuyExistedBookDlg 消息处理程序


void BuyExistedBookDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT1_InputQt, Quan);
	sig = 1;
	EndDialog(0);
}
