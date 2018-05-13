#include "StdAfx.h"
#include "WEllipse.h"

IMPLEMENT_SERIAL(WEllipse, CObject, 1)

WEllipse::WEllipse()
{
	Type = (ElementType)3;
}




WEllipse::WEllipse(int orgX, int orgY, int hRadius, int vRadius, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor)
{
	Type = (ElementType)3;
	OrgX = orgX;
	OrgY = orgY;
	HRadius = hRadius;
	VRadius = vRadius;
	BorderWidth = borderWidth;
	BorderType = borderType;
	BorderColor = borderColor;
	FillType = fillType;
	FillColor = fillColor;
}

void WEllipse::Draw(CDC*pDC)
{
	// 创建画笔及用来保存原画笔的指针
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);

	//创建刷子及用来保存原刷子的指针
	CBrush brush, *pOldBrush;
	brush.CreateHatchBrush(FillType, FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	//绘制图形（通过外置矩形来画椭圆）
	pDC->Ellipse(OrgX - HRadius / 2, OrgY + VRadius / 2, OrgX + HRadius / 2, OrgY - VRadius / 2);

	//使用当前画笔和刷子
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool WEllipse::IsMatched(CPoint pnt)
{
	CRgn rgn;
	rgn.CreateEllipticRgn(OrgX-HRadius/2,OrgY-VRadius/2,OrgX+HRadius/2,OrgY+VRadius/2);
	BOOL flag = rgn.PtInRegion(pnt);
	if (flag)
	{
		return true;
	}
	else
		return false;
}


void WEllipse::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		//保存文件
		ar << (WORD)Type;
		ar << OrgX << OrgY;
		ar << BorderColor << BorderType << BorderWidth;
		ar << FillColor << FillType;
		ar << HRadius << VRadius;
	}
	else
	{
		//读取文件
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;
		ar >> BorderColor >> BorderType >> BorderWidth;
		ar >> FillColor >> FillType;
		ar >> HRadius >> VRadius;
	}
}

WEllipse::~WEllipse()
{
}
