// PayDLG.cpp: 实现文件
//

#include "pch.h"
#include "BookStoreApplication.h"
#include "PayDLG.h"
#include "afxdialogex.h"
#include "resource.h"
#include "sel_BookPurchase.h"


// PayDLG 对话框

IMPLEMENT_DYNAMIC(PayDLG, CDialogEx)

PayDLG::PayDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1_PAYDLG, pParent)
{

}

PayDLG::~PayDLG()
{
}

void PayDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1_PayList, Pay_List);
}


BEGIN_MESSAGE_MAP(PayDLG, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1_Py, &PayDLG::OnBnClickedButton1Py)
	ON_BN_CLICKED(IDC_BUTTON1_Cancel, &PayDLG::OnBnClickedButton1Cancel)
END_MESSAGE_MAP()


// PayDLG 消息处理程序
BOOL PayDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	Pay_List.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);
	
	sel_BookPurchase s1;
	s1.selForPay();

	Pay_List.InsertColumn(0, _T("PurchaseNo"), 0, 100);
	Pay_List.InsertColumn(1, _T("ISBN"), 0, 200);
	Pay_List.InsertColumn(2, _T("Title"), 0, 200);
	Pay_List.InsertColumn(3, _T("Author"), 0, 200);
	Pay_List.InsertColumn(4, _T("Publisher"), 0, 200);
	Pay_List.InsertColumn(5, _T("Price"), 0, 150);
	Pay_List.InsertColumn(6, _T("Paid Status"), 0, 100);
	Pay_List.InsertColumn(7, _T("Quantity"), 0, 150);

	for (int i = 0; i < s1.getRowNum(); i++)
	{
		Pay_List.InsertItem(i, s1.GetPurNo(i));
		Pay_List.SetItemText(i, 1, s1.GetIsbn(i));
		Pay_List.SetItemText(i, 2, s1.GetTitle(i));
		Pay_List.SetItemText(i, 3, s1.GetAuthor(i));
		Pay_List.SetItemText(i, 4, s1.GetPublisher(i));
		Pay_List.SetItemText(i, 5, s1.GetPrice(i));
		Pay_List.SetItemText(i, 6, s1.GetPayStatus(i));
		Pay_List.SetItemText(i, 7, s1.GetQuantity(i));
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void PayDLG::OnBnClickedButton1Py()
{
	// TODO: 在此添加控件通知处理程序代码
	int count = 0;
	for (int i = 0; i < Pay_List.GetItemCount(); i++)
	{

		BOOL state = Pay_List.GetCheck(i);
		if (state)
		{
			count++;
		}
	}
	if (count > 1)
	{
		MessageBox(_T("You Can Only Pay For One Item at One Time!"));
		return;
	}
	else
	{
		for (int i = 0; i < Pay_List.GetItemCount(); i++)
		{

			BOOL state = Pay_List.GetCheck(i);
			if (state)
			{
				
				
				sel_BookPurchase s2;
				
				if (s2.payBill(Pay_List.GetItemText(i, 1), Pay_List.GetItemText(i, 0),Pay_List.GetItemText(i,7),Pay_List.GetItemText(i,5)))
				{

					MessageBox(_T("Paying Succeeded"));
					
					Pay_List.DeleteAllItems();
					s2.selForPay();
					for (int i = 0; i < s2.getRowNum(); i++)
					{
						Pay_List.InsertItem(i, s2.GetPurNo(i));
						Pay_List.SetItemText(i, 1, s2.GetIsbn(i));
						Pay_List.SetItemText(i, 2, s2.GetTitle(i));
						Pay_List.SetItemText(i, 3, s2.GetAuthor(i));
						Pay_List.SetItemText(i, 4, s2.GetPublisher(i));
						Pay_List.SetItemText(i, 5, s2.GetPrice(i));
						Pay_List.SetItemText(i, 6, s2.GetPayStatus(i));
						Pay_List.SetItemText(i, 7, s2.GetQuantity(i));
					}
				}
				else
				{
					MessageBox(_T("Paying Failed"));
				}
			}
		}
	}

}





void PayDLG::OnBnClickedButton1Cancel()
{
	// TODO: 在此添加控件通知处理程序代码

	sel_BookPurchase s2;
	for (int i = 0; i < Pay_List.GetItemCount(); i++)
	{

		BOOL state = Pay_List.GetCheck(i);
		if (state)
		{
			if (s2.CancelBook(Pay_List.GetItemText(i, 0)))
			{

				MessageBox(_T("Paying Succeeded"));
			}
			else
			{
				MessageBox(_T("Paying Failed"));
			}
		}
	}


	Pay_List.DeleteAllItems();
	s2.selForPay();
	for (int i = 0; i < s2.getRowNum(); i++)
	{
		Pay_List.InsertItem(i, s2.GetPurNo(i));
		Pay_List.SetItemText(i, 1, s2.GetIsbn(i));
		Pay_List.SetItemText(i, 2, s2.GetTitle(i));
		Pay_List.SetItemText(i, 3, s2.GetAuthor(i));
		Pay_List.SetItemText(i, 4, s2.GetPublisher(i));
		Pay_List.SetItemText(i, 5, s2.GetPrice(i));
		Pay_List.SetItemText(i, 6, s2.GetPayStatus(i));
		Pay_List.SetItemText(i, 7, s2.GetQuantity(i));
	}

}
