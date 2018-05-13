#include "StdAfx.h"
#include "WCircle.h"

IMPLEMENT_SERIAL(WCircle, CObject, 1)

WCircle::WCircle()
{
	Type = (ElementType)2;
}


WCircle::WCircle(int orgX, int orgY, int radius, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor)
{
	Type = (ElementType)2;
	OrgX = orgX;
	OrgY = orgY;
	Radius = radius;
	BorderWidth = borderWidth;
	BorderType = borderType;
	BorderColor = borderColor;
	FillType = fillType;
	FillColor = fillColor;
}

void WCircle::Draw(CDC*pDC)
{
	//创建画笔及用来保存原画笔的指针
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);

	//创建刷子及用来保存原刷子的指针
	CBrush brush, *pOldBrush;
	brush.CreateHatchBrush(FillType, FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	//绘制图形（通过外置矩形来画椭圆）
	pDC->Ellipse(OrgX - Radius / 2, OrgY + Radius / 2, OrgX + Radius / 2, OrgY - Radius / 2);

	//使用当前画笔和刷子
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool WCircle::IsMatched(CPoint pnt)
{
	CRgn rgn;
	rgn.CreateEllipticRgn(OrgX-Radius,OrgY-Radius,OrgX+Radius,OrgY+Radius);
	BOOL flag = rgn.PtInRegion(pnt);
	if (flag)
	{
		return true;
	}
	else
		return false;

}

void WCircle::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		//保存文件
		ar << (WORD)Type;
		ar << OrgX << OrgY;
		ar << BorderColor << BorderType << BorderWidth;
		ar << FillColor << FillType;
		ar << Radius;
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
		ar >> Radius;
	}
}

WCircle::~WCircle()
{
}
