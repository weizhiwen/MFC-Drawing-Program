#include "StdAfx.h"
#include "WText.h"
#include <math.h>

WText::WText()
{
	Type = (ElementType)5;
}


WText::WText(int orgX, int orgY, CString textContent, int textAngle, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor)
{
	Type = (ElementType)5;
	OrgX = orgX;
	OrgY = orgY;
	TextContent = textContent;
	TextAngle = textAngle;
	BorderWidth = borderWidth;
	BorderType = borderType;
	BorderColor = borderColor;
	FillType = fillType;
	FillColor = fillColor;
}

void WText::Draw(CDC* pDC)
{
	//创建带旋转角度的字体
	LOGFONT logfont;
	lstrcpy(logfont.lfFaceName, _T("楷体_GB2312"));
	logfont.lfWeight = 0;
	logfont.lfWidth = 40;
	logfont.lfHeight = 70;
	logfont.lfEscapement = TextAngle;
	logfont.lfUnderline = FALSE;
	logfont.lfItalic = FALSE;
	logfont.lfStrikeOut = FALSE;
	logfont.lfCharSet = GB2312_CHARSET;
	HFONT hFont, *hOldFont;
	hFont = CreateFontIndirect(&logfont);
	hOldFont = (HFONT*)pDC->SelectObject(hFont);
	pDC->SetBkColor(FillColor);
	pDC->SetTextColor(BorderColor);
	pDC->TextOutW(OrgX, OrgY, TextContent);
	pDC->SelectObject(hOldFont);
}

bool WText::IsMatched(CPoint pnt)
{
	SIZE  size;
	double a = TextAngle * 3.1415926 / 180.0;
	HFONT pNewFont = CreateFont(70, 40, TextAngle,0, 40, FALSE, FALSE, FALSE, GB2312_CHARSET, OUT_CHARACTER_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH&FF_SWISS, _T("楷体_GB2312"));
	HDC hDC = CreateCompatibleDC(NULL);
	SelectObject(hDC, pNewFont);
	if (GetTextExtentPoint32(hDC, TextContent, wcslen(TextContent), &size))
	{
		CRgn rgn;
		POINT ptVertex[4];
		ptVertex[0].x = OrgX;
		ptVertex[0].y = OrgY;
		ptVertex[1].x = long(OrgX + cos(a) * size.cx);
		ptVertex[1].y = long(OrgY - sin(a) * size.cx);
		ptVertex[2].x = long(OrgX + sin(a) * size.cy + cos(a) * size.cx);
		ptVertex[2].y = long(OrgY + cos(a) * size.cy - sin(a) * size.cx);
		ptVertex[3].x = long(OrgX + sin(a) * size.cy);
		ptVertex[3].y = long(OrgY + cos(a) * size.cy);
		rgn.CreatePolygonRgn(ptVertex, 4, WINDING);

		BOOL flag = rgn.PtInRegion(pnt);
		if (flag)
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;

}

void WText::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		//保存文件
		ar << (WORD)Type;
		ar << OrgX << OrgY;
		ar << BorderColor << BorderType << BorderWidth;
		ar << FillColor << FillType;
		ar << TextContent << TextAngle;
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
		ar << TextContent << TextAngle;
	}
}

WText::~WText()
{
}
