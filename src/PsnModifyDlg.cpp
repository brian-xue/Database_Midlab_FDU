// PsnModifyDlg.cpp: 实现文件
//

#include "pch.h"
#include "BookStoreApplication.h"
#include "PsnModifyDlg.h"
#include "afxdialogex.h"


// PsnModifyDlg 对话框

IMPLEMENT_DYNAMIC(PsnModifyDlg, CDialogEx)

PsnModifyDlg::PsnModifyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1_MdPer, pParent)
{

}

PsnModifyDlg::~PsnModifyDlg()
{
}

void PsnModifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1_ATS, psn_AttriBox);
}


BEGIN_MESSAGE_MAP(PsnModifyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &PsnModifyDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// PsnModifyDlg 消息处理程序


void PsnModifyDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT1_MDPV, Val);
	sig = 1;
	selNum = psn_AttriBox.GetCurSel();
	EndDialog(0);
}
