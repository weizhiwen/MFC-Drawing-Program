#pragma once
#include "WShape.h"
class WSquare :public WShape
{
public:
	int Width; //正方形的边长
public:
	WSquare();
	WSquare(int orgX, int orgY, int width, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor);
	void Draw(CDC*pDC);
	bool IsMatched(CPoint pnt);
	void Serialize(CArchive& ar);
	~WSquare();
	DECLARE_SERIAL(WSquare); //声明类WSquare是支持序列化
};

