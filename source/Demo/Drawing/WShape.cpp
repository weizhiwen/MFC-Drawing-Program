#include "StdAfx.h"
#include "WShape.h"


WShape::WShape()
{
}


void WShape::SetAttribute(int orgX, int orgY, COLORREF borderColor, int borderType, int borderWidth, COLORREF fillColor, int fillType)
{
	OrgX = orgX;
	OrgY = orgY;
	BorderColor = borderColor;
	BorderType = borderType;
	BorderWidth = borderWidth;
	FillColor = fillColor;
	FillType = fillType;
}


WShape::~WShape()
{
}
