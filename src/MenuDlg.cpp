// MenuDlg.cpp: 实现文件
//

#include "pch.h"
#include "BookStoreApplication.h"
#include "MenuDlg.h"
#include "BookStoreQuery.h"
#include "BookStoreSell.h"
#include "BookStoreBuy.h"
#include "BookStoreSignup.h"
#include "afxdialogex.h"


// MenuDlg 对话框

IMPLEMENT_DYNAMIC(MenuDlg, CDialogEx)

MenuDlg::MenuDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1_MainMenu, pParent)
{

}

MenuDlg::~MenuDlg()
{
}

void MenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MenuDlg, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON2_Qry, &MenuDlg::OnBnClickedButton2Qry)
	ON_BN_CLICKED(IDC_BUTTON3_Buy, &MenuDlg::OnBnClickedButton3Buy)
	ON_BN_CLICKED(IDC_BUTTON4_Sel, &MenuDlg::OnBnClickedButton4Sel)
	ON_BN_CLICKED(IDC_BUTTON5_SgnU, &MenuDlg::OnBnClickedButton5Sgnu)
END_MESSAGE_MAP()


// MenuDlg 消息处理程序


void MenuDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialog* pdlg = (CDialog*)AfxGetMainWnd();
	pdlg->DestroyWindow();
	CDialogEx::OnClose();
}


BOOL MenuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void MenuDlg::OnBnClickedButton2Qry()
{
	// TODO: 在此添加控件通知处理程序代码
	BookStoreQuery qdlg;
	qdlg.is_Su = is_SU;
	qdlg.Un = Un;
	qdlg.DoModal();
}


void MenuDlg::OnBnClickedButton3Buy()
{
	// TODO: 在此添加控件通知处理程序代码
	BookStoreBuy bdlg;
	bdlg.DoModal();
}


void MenuDlg::OnBnClickedButton4Sel()
{
	// TODO: 在此添加控件通知处理程序代码
	BookStoreSell sdlg;
	sdlg.DoModal();
}


void MenuDlg::OnBnClickedButton5Sgnu()
{
	// TODO: 在此添加控件通知处理程序代码
	if (is_SU)
	{
		BookStoreSignup udlg;
		udlg.DoModal();
	}
	else
	{
		MessageBox(_T("Access Denied"));
	}

	
}
