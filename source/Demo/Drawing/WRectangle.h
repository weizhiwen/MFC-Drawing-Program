#pragma once
#include "WShape.h"
class WRectangle :public WShape
{
public:
	int Width;//矩形的宽
	int Height;//矩形的高
public:
	WRectangle();
	WRectangle(int orgX, int orgY, int width, int height, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor);
	void Draw(CDC*pDC);
	bool IsMatched(CPoint pnt);
	void Serialize(CArchive& ar);
	~WRectangle();
	DECLARE_SERIAL(WRectangle); //声明类WRectangle是支持序列化
};

