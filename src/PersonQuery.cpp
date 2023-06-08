// PersonQuery.cpp: 实现文件
//

#include "pch.h"
#include "BookStoreApplication.h"
#include "PersonQuery.h"
#include "afxdialogex.h"
#include "resource.h"
#include "Sel_person.h"
#include "PsnModifyDlg.h"

// PersonQuery 对话框

IMPLEMENT_DYNAMIC(PersonQuery, CDialogEx)

PersonQuery::PersonQuery(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1_PerQ, pParent)
{

}

PersonQuery::~PersonQuery()
{
}

void PersonQuery::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1_PersonList, person_List);
	DDX_Control(pDX, IDC_COMBO1_SorC, su_CuSel);
}


BEGIN_MESSAGE_MAP(PersonQuery, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2_Check, &PersonQuery::OnBnClickedButton2Check)
	ON_BN_CLICKED(IDC_BUTTON1_Modify, &PersonQuery::OnBnClickedButton1Modify)
END_MESSAGE_MAP()



BOOL PersonQuery::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	person_List.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);
	person_List.InsertColumn(0, _T("User Name"), 0, 200);
	person_List.InsertColumn(1, _T("RealName"), 0, 200);
	person_List.InsertColumn(2, _T("Work_ID"), 0, 200);
	person_List.InsertColumn(3, _T("Gender"), 0, 200);
	person_List.InsertColumn(4, _T("Password"), 0, 300);
	person_List.InsertColumn(5, _T("Age"), 0, 150);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


// PersonQuery 消息处理程序


void PersonQuery::OnBnClickedButton2Check()
{
	// TODO: 在此添加控件通知处理程序代码
	int coboNum = su_CuSel.GetCurSel();
	if (coboNum == 1 && !isSu)
	{
		MessageBox(_T("Access Denied"));
	}
	else
	{
		Sel_person s1(isSu, Un);
		s1.init(coboNum);

		for (int i = 0; i < s1.getRowNum(); i++)
		{
			person_List.InsertItem(i,s1.selUserName(i));
			person_List.SetItemText(i, 1, s1.selRealName(i));
			person_List.SetItemText(i, 2, s1.selWID(i));
			person_List.SetItemText(i, 3, s1.selGender(i));
			person_List.SetItemText(i, 4, s1.selPassword(i));
			person_List.SetItemText(i, 5, s1.selAge(i));
		}
	}
}


void PersonQuery::OnBnClickedButton1Modify()
{
	// TODO: 在此添加控件通知处理程序代码
	int count = 0;
	for (int i = 0; i < person_List.GetItemCount(); i++)
	{

		BOOL state = person_List.GetCheck(i);
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
		for (int i = 0; i < person_List.GetItemCount(); i++)
		{
			BOOL state = person_List.GetCheck(i);
			if (state)
			{
				PsnModifyDlg dlg;
				dlg.DoModal();
				if (dlg.sig == 0)
				{
					return;
				}
				Sel_person s3(isSu, Un);
				CString psn = person_List.GetItemText(i, 0);
				int tbsel = su_CuSel.GetCurSel();
				int status = s3.PersonModify(dlg.selNum, tbsel, dlg.Val, psn);

				if (status == 0)
				{
					MessageBox(_T("Modify Succeeded"));
					s3.init(tbsel);

					person_List.DeleteAllItems();
					for (int i = 0; i < s3.getRowNum(); i++)
					{
						person_List.InsertItem(i, s3.selUserName(i));
						person_List.SetItemText(i, 1, s3.selRealName(i));
						person_List.SetItemText(i, 2, s3.selWID(i));
						person_List.SetItemText(i, 3, s3.selGender(i));
						person_List.SetItemText(i, 4, s3.selPassword(i));
						person_List.SetItemText(i, 5, s3.selAge(i));
					}

				}
				else if (status == 2)
				{
					MessageBox(_T("Modify failed"));
				}
				else if (status == 1)
				{
					MessageBox(_T("User name is existed! You cannot change your User Name to this"));
				}
			}

		}
	}

}



