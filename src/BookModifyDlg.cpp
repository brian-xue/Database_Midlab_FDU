// BookModifyDlg.cpp: 实现文件
//

#include "pch.h"
#include "BookStoreApplication.h"
#include "BookModifyDlg.h"
#include "afxdialogex.h"


// BookModifyDlg 对话框

IMPLEMENT_DYNAMIC(BookModifyDlg, CDialogEx)

BookModifyDlg::BookModifyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1_BookModify, pParent)
{

}

BookModifyDlg::~BookModifyDlg()
{
}

void BookModifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1_AttributeSel, attri_sel);
}


BEGIN_MESSAGE_MAP(BookModifyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1_Confirm, &BookModifyDlg::OnBnClickedButton1Confirm)
END_MESSAGE_MAP()


// BookModifyDlg 消息处理程序


void BookModifyDlg::OnBnClickedButton1Confirm()
{
	// TODO: 在此添加控件通知处理程序代码
	sel_Attribute = attri_sel.GetCurSel();
	GetDlgItemText(IDC_EDIT2_InputValue, Val);
	sig = 1;
	EndDialog(0);
}
