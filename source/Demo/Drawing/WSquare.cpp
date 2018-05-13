#include "StdAfx.h"
#include "WSquare.h"

IMPLEMENT_SERIAL(WSquare, CObject, 1)

WSquare::WSquare()
{
	Type = (ElementType)0;
}

WSquare::WSquare(int orgX, int orgY, int width, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor)
{
	Type = (ElementType)0;
	OrgX = orgX;
	OrgY = orgY;
	Width = width;
	BorderWidth = borderWidth;
	BorderType = borderType;
	BorderColor = borderColor;
	FillType = fillType;
	FillColor = fillColor;
}


void WSquare::Draw(CDC*pDC)
{
	//创建画笔及用来保存原画笔的指针
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);

	//创建刷子及用来保存原刷子的指针
	CBrush brush, *pOldBrush;
	brush.CreateHatchBrush(FillType, FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	//绘制图形
	pDC->Rectangle(OrgX - Width / 2, OrgY + Width / 2, OrgX + Width / 2, OrgY - Width / 2);

	//使用当前画笔和刷子
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool WSquare::IsMatched(CPoint pnt)
{
	CRgn rgn;
	rgn.CreateRectRgn(OrgX - Width / 2, OrgY - Width / 2, OrgX + Width / 2, OrgY + Width / 2);
	BOOL flag = rgn.PtInRegion(pnt);
	if (flag)
	{
		return true;
	}
	else
		return false;

}

void WSquare::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		//保存文件
		ar << (WORD)Type;
		ar << OrgX << OrgY;
		ar << BorderColor << BorderType << BorderWidth;
		ar << FillColor << FillType;
		ar << Width;
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
		ar >> Width;
	}
}

WSquare::~WSquare()
{
}