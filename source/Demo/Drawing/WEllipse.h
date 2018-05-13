#pragma once
#include "wshape.h"
class WEllipse :public WShape
{
public:
	int HRadius;//椭圆的水平半轴
	int VRadius;//椭圆的垂直半轴
public:
	WEllipse();
	WEllipse(int orgX, int orgY, int hRadius, int vRadius, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor);
	void Draw(CDC*pDC);
	bool IsMatched(CPoint pnt);
	void Serialize(CArchive& ar);
	~WEllipse();
	DECLARE_SERIAL(WEllipse); //声明类WEllipse是支持序列化
};

