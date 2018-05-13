#pragma once
#include "afxwin.h"
#include "afxcolorbutton.h"


// AttributeDialog 对话框

class AttributeDialog : public CDialogEx
{
	DECLARE_DYNAMIC(AttributeDialog)

public:
	AttributeDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual BOOL OnInitDialog();
	virtual ~AttributeDialog();

// 对话框数据
	enum { IDD = IDD_ATTRIBUTE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()

// 自定义的消息映射函数
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancle();
	afx_msg void OnCbnSelchangeComboShapeType();
// 自定义变量
public:
	// 图元类型
	CComboBox shapeType;
	// 原点X
	int orgX;
	// 原点Y
	int orgY;
	// 宽度
	int width;
	// 高度
	int height;
	// 文本内容
	CString textContent;
	// 文本角度
	int textAngle;
	// 边框宽度
	int borderWidth;
	// 边框颜色按钮
	CMFCColorButton borderColorButton;
	// 边框颜色
	COLORREF borderColor;
	// 边框类型
	CListBox borderType;
	// 填充类型
	CListBox fillType;
	// 填充颜色按钮
	CMFCColorButton fillColorButton;
	// 填充色
	COLORREF fillColor;

	// 选项的索引号
	int comboxIndex;
	int borderTypeIndex;
	int filltypeIndex;
};
