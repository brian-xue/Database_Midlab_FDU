// BookStoreSignup.cpp: 实现文件
//

#include "pch.h"
#include "BookStoreApplication.h"
#include "BookStoreSignup.h"
#include "afxdialogex.h"
#include "resource.h"
#include "UserSignUp.h"


// BookStoreSignup 对话框

IMPLEMENT_DYNAMIC(BookStoreSignup, CDialogEx)

BookStoreSignup::BookStoreSignup(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1_SignUp, pParent)
{

}

BookStoreSignup::~BookStoreSignup()
{
}

void BookStoreSignup::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1_Gender, Idc_GenderComb);
}


BEGIN_MESSAGE_MAP(BookStoreSignup, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1_Sgu, &BookStoreSignup::OnBnClickedButton1Sgu)
END_MESSAGE_MAP()


// BookStoreSignup 消息处理程序


BOOL BookStoreSignup::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void BookStoreSignup::OnBnClickedButton1Sgu()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sname, rname, wid, pwd, age;
	GetDlgItemText(IDC_EDIT1_UsN, sname);
	GetDlgItemText(IDC_EDIT2_RLn,rname );
	GetDlgItemText(IDC_EDIT3_Wid,wid );
	GetDlgItemText(IDC_EDIT5_PsW,pwd );
	GetDlgItemText(IDC_EDIT6_Age,age );

	int gen = Idc_GenderComb.GetCurSel();

	bool a = (sname.IsEmpty() || rname.IsEmpty() || wid.IsEmpty() || pwd.IsEmpty() || age.IsEmpty());

	if (sname.Compare(_T("admin"))==0)
	{
		MessageBox(_T("This name is forbidden!"));
	}

	if (a)
	{
		MessageBox(_T("All the Attributes should be finished"));
		return;
	}
	else
	{
		UserSignUp u1;
		int res = u1.SignUp(sname,rname,wid,gen,pwd,age);

		if (res == 0)
		{
			MessageBox(_T("Sign Up Succeeded"));
		}
		else if (res == 1)
		{
			MessageBox(_T("SignUp Failed"));
		}
		else
		{
			MessageBox(_T("User Name has Existed. Please Try Another one"));
		}
		
	}
	EndDialog(0);
}
