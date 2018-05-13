// AttributeDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Drawing.h"
#include "AttributeDialog.h"
#include "afxdialogex.h"
#include <iostream>
using namespace std;

// AttributeDialog 对话框

IMPLEMENT_DYNAMIC(AttributeDialog, CDialogEx)

AttributeDialog::AttributeDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(AttributeDialog::IDD, pParent)
	, orgX(0)
	, orgY(0)
	, width(200)
	, height(100)
	, textContent(_T(""))
	, textAngle(0)
	, borderWidth(10)
{

}

AttributeDialog::~AttributeDialog()
{
}

void AttributeDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_SHAPE_TYPE, shapeType);
	DDX_Text(pDX, IDC_EDIT_X, orgX);
	DDX_Text(pDX, IDC_EDIT_Y, orgY);
	DDX_Text(pDX, IDC_EDIT_WIDTH, width);
	DDX_Text(pDX, IDC_EDIT_HEIGHT, height);
	DDX_Text(pDX, IDC_EDIT_TEXT, textContent);
	DDX_Text(pDX, IDC_EDIT_TEXT_ANGLE, textAngle);
	DDX_Text(pDX, IDC_EDIT_LINE_WIDTH, borderWidth);
	DDX_Control(pDX, IDC_LIST_BORDER_TYPE, borderType);
	DDX_Control(pDX, IDC_LIST_FILL_TYPE, fillType);
	DDX_Text(pDX, IDC_BUTTON_BORDER_COLOR, borderColor);
	DDX_Text(pDX, IDC_BUTTON_FILL_COLOR, fillColor);
	DDX_Control(pDX, IDC_BUTTON_BORDER_COLOR, borderColorButton);
	DDX_Control(pDX, IDC_BUTTON_FILL_COLOR, fillColorButton);
}


BEGIN_MESSAGE_MAP(AttributeDialog, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_SHAPE_TYPE, &AttributeDialog::OnCbnSelchangeComboShapeType)
	ON_BN_CLICKED(IDOK, &AttributeDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCLE, &AttributeDialog::OnBnClickedCancle)
END_MESSAGE_MAP()


// AttributeDialog 消息处理程序


BOOL AttributeDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	// 初始化下拉列表中的内容
	CComboBox* pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_SHAPE_TYPE);
	pComboBox->InsertString(0, L"正方形");
	pComboBox->InsertString(1, L"矩形");
	pComboBox->InsertString(2, L"圆形");
	pComboBox->InsertString(3, L"椭圆形");
	pComboBox->InsertString(4, L"正三角形");
	pComboBox->InsertString(5, L"文本");
	pComboBox->SetCurSel(0); // 将第一个作为默认选项


	// 初始化列表框中的内容
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST_BORDER_TYPE);
	pListBox->InsertString(0, L"SOLID");
	pListBox->InsertString(1, L"DASH");
	pListBox->InsertString(2, L"DASHDOT");
	pListBox->SetCurSel(0);

	pListBox = (CListBox*)GetDlgItem(IDC_LIST_FILL_TYPE);
	pListBox->InsertString(0, L"SOLID");
	pListBox->InsertString(1, L"BDIALOGAL");
	pListBox->InsertString(2, L"CROSS");
	pListBox->SetCurSel(0);

	// 隐藏文本输入框和文本角度框
	CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STATIC_TEXT);
	pStatic->ShowWindow(SW_HIDE);
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_TEXT);
	pEdit->ShowWindow(SW_HIDE);

	pStatic = (CStatic*)GetDlgItem(IDC_STATIC_TEXT_ANGLE);
	pStatic->ShowWindow(SW_HIDE);
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT_TEXT_ANGLE);
	pEdit->ShowWindow(SW_HIDE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

// 点击下拉框消息的处理函数
void AttributeDialog::OnCbnSelchangeComboShapeType()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = shapeType.GetCurSel(); // 根据用户选项调整界面
	if (index == 5)
	{
		// 显示文本输入框和文本角度框
		CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STATIC_TEXT);
		pStatic->ShowWindow(SW_SHOW);
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_TEXT);
		pEdit->ShowWindow(SW_SHOW);

		pStatic = (CStatic*)GetDlgItem(IDC_STATIC_TEXT_ANGLE);
		pStatic->ShowWindow(SW_SHOW);
		pEdit = (CEdit*)GetDlgItem(IDC_EDIT_TEXT_ANGLE);
		pEdit->ShowWindow(SW_SHOW);
	}
}


void AttributeDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	comboxIndex = shapeType.GetCurSel(); // 获取图形类型选项值
	borderTypeIndex = borderType.GetCurSel(); // 获取边框类型选项值
	filltypeIndex = fillType.GetCurSel(); //获取填充类型选项值
	borderColor = borderColorButton.GetColor(); // 获取边框颜色值
	fillColor = fillColorButton.GetColor(); // 获取填充颜色值
}


void AttributeDialog::OnBnClickedCancle()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
}
