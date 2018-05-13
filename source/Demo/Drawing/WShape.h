#pragma once
enum ElementType {SQUARE, RECTANGLE, CIRCLE, ELLIPSE, TRIANGLE, TEXT};
class WShape:public CObject
{
public:
	ElementType Type; //图元类型
	int OrgX; //逻辑坐标 X
	int OrgY; //逻辑坐标 Y
	COLORREF BorderColor; //边框颜色
	int BorderType; //边框线型（实线，虚线，虚点线）
	int BorderWidth; //边框宽度
	COLORREF FillColor; //填充颜色
	int FillType; //填充类型（实心，双对角， 十字交叉）
public:
	WShape();
	virtual void Draw(CDC* pDC) = 0; // 绘制图元函数
	virtual bool IsMatched(CPoint pnt) = 0; // 判断鼠标点是否落在图形内
	virtual void Serialize(CArchive& ar) = 0; // 序列化函数
	void SetAttribute(int orgX, int orgY, COLORREF borderColor, int borderType, int borderWidth, COLORREF fillColor, int fillType); //改变图形属性表函数
	virtual ~WShape();
};

