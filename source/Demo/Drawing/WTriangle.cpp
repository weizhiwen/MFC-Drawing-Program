#include "StdAfx.h"
#include "WTriangle.h"
#include <math.h>

IMPLEMENT_SERIAL(WTriangle, CObject, 1)//实现类WSquare的序列化，指定版本为1

WTriangle::WTriangle()
{
	Type = (ElementType)4;//图元类型
}


WTriangle::WTriangle(int orgX, int orgY, int length, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor)
{
	Type = (ElementType)4;//图元类型
	OrgX = orgX;
	OrgY = orgY;
	Length = length;
	BorderWidth = borderWidth;
	BorderType = borderType;
	BorderColor = borderColor;
	FillType = fillType;
	FillColor = fillColor;
}


void WTriangle::Draw(CDC*pDC)
{
	// 创建画笔及用来保存原画笔的指针
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);

	//创建刷子及用来保存原刷子的指针
	CBrush brush, *pOldBrush;
	brush.CreateHatchBrush(FillType, FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	//绘制图形
	double x1 = double(OrgX), y1 = double(OrgY) + double(Length) / SQRT3;
	double x2 = double(OrgX) - double(Length) / 2, y2 = double(OrgY) - double(Length) / (2 * SQRT3);
	double x3 = double(OrgX) + double(Length) / 2, y3 = double(OrgY) - double(Length) / (2 * SQRT3);
	CPoint points[3] = { CPoint(int(x1), int(y1)), CPoint(int(x2), int(y2)), CPoint(int(x3), int(y3))};
	pDC->Polygon(points, 3);

	//使用当前画笔和刷子
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool WTriangle::IsMatched(CPoint pnt)
{
	CRgn rgn ;
	CPoint ptVertex[3];
	ptVertex[0].x = long(OrgX - Length / 2);
	ptVertex[0].y = long(OrgY + (sqrt(1.0 / 12)) * Length);
	ptVertex[1].x = long(OrgX);
	ptVertex[1].y = long(OrgY - (sqrt(1.0 / 3)) * Length);
	ptVertex[2].x = long(OrgX + (Length / 2));
	ptVertex[2].y = long(OrgY + (sqrt(1.0 / 12)) * Length);
	rgn.CreatePolygonRgn(ptVertex , 3 , ALTERNATE);

	BOOL flag= rgn.PtInRegion(pnt);
	if (flag)
	{
		return true;		
	}	
	else
		return false;

}

void WTriangle::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		//保存文件
		ar << (WORD)Type;
		ar << OrgX << OrgY;
		ar << BorderColor << BorderType << BorderWidth;
		ar << FillColor << FillType;
		ar << Length;
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
		ar >> Length;
	}
}

WTriangle::~WTriangle()
{
}
