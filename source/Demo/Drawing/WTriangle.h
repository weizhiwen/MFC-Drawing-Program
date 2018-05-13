#pragma once
#include "wshape.h"
#define SQRT3 1.73
#define SQRT2 1.41
class WTriangle :public WShape
{
public:
	int Length;//正三角形的边长
public:
	WTriangle();
	WTriangle(int orgX, int orgY, int length, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor);
	void Draw(CDC*pDC);
	bool IsMatched(CPoint pnt);
	void Serialize(CArchive& ar);
	~WTriangle();
	DECLARE_SERIAL(WTriangle)//声明类WRectangle是支持序列化
};

