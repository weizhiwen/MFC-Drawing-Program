
// DrawingView.cpp : CDrawingView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Drawing.h"
#endif
#include "DrawingDoc.h"
#include "DrawingView.h"
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawingView

IMPLEMENT_DYNCREATE(CDrawingView, CScrollView)

BEGIN_MESSAGE_MAP(CDrawingView, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDrawingView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDBLCLK()
END_MESSAGE_MAP()

// CDrawingView 构造/析构

CDrawingView::CDrawingView()
{
	// TODO: 在此处添加构造代码

}

CDrawingView::~CDrawingView()
{
}

BOOL CDrawingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CDrawingView 绘制

void CDrawingView::OnDraw(CDC* pDC)
{
	CDrawingDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	int count = pDoc->shapeArray.GetCount();
	if(count > 0)
	{
		WShape *p = NULL;
		for(int i = 0; i < count; i++)
		{
			p = (WShape*)pDoc->shapeArray[i];
			p->Draw(pDC);
		}
	}
}

void CDrawingView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CDrawingView 打印


void CDrawingView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDrawingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDrawingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

//void CDrawingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
//{
//	ClientToScreen(&point);
//	OnContextMenu(this, point);
//}

//void CDrawingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
//{
//#ifndef SHARED_HANDLERS
//	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
//#endif
//}


// CDrawingView 诊断

#ifdef _DEBUG
void CDrawingView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDrawingView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDrawingDoc* CDrawingView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawingDoc)));
	return (CDrawingDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawingView 消息处理程序


// 按下鼠标左键的消息响应函数
void CDrawingView::OnLButtonDown(UINT nFlags, CPoint point)
{
	//// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDrawingDoc *pDoc = GetDocument();
	// 设备坐标转换成逻辑坐标（DP->LP）
	CClientDC dc(this);
	CPoint pntLogical = point;
	OnPrepareDC(&dc);
	dc.DPtoLP(&pntLogical);

	// 判断在鼠标左键按下的同时，Ctrl键是否按下
	if ((nFlags&MK_CONTROL) == MK_CONTROL)
	{
		AttributeDialog dialog; // 创建对话框对象
		// 在对话框显示之前获取逻辑坐标
		dialog.orgX = pntLogical.x;
		dialog.orgY = pntLogical.y;
		// 对话框的返回值是否是IDOK
		if(dialog.DoModal() == IDOK)
		{
			//获取图形的属性
			int orgX = dialog.orgX;
			int orgY = dialog.orgY;
			int width = dialog.width;
			int height = dialog.height;
			CString textContent = dialog.textContent;
			int textAngle = dialog.textAngle;
			int borderWidth = dialog.borderWidth;
			int borderType = dialog.borderTypeIndex;
			COLORREF borderColor = dialog.borderColor;
			int fillType = dialog.filltypeIndex;
			int fillColor = dialog.fillColor;
			int comboxIndex = dialog.comboxIndex;
			switch(comboxIndex)
			{
			case 0:
				{
					// 正方形
					WSquare *p = new WSquare(orgX, orgY, width, borderWidth, borderType, borderColor, fillType, fillColor);
					pDoc->shapeArray.Add(p);
					break;
				}
			case 1:
				{
					// 矩形
					WRectangle *p = new WRectangle(orgX, orgY, width, height, borderWidth, borderType, borderColor, fillType, fillColor);
					pDoc->shapeArray.Add(p);
					break;
				}
			case 2:
				{
					// 圆形
					WCircle *p = new WCircle(orgX, orgY, width, borderWidth, borderType, borderColor, fillType, fillColor);
					pDoc->shapeArray.Add(p);
					break;
				}
			case 3:
				{
					// 椭圆形
					WEllipse *p = new WEllipse(orgX, orgY, width, height, borderWidth, borderType, borderColor, fillType, fillColor);
					pDoc->shapeArray.Add(p);
					break;
				}
			case 4:
				{
					// 正三角形
					WTriangle *p = new WTriangle(orgX, orgY, width, borderWidth, borderType, borderColor, fillType, fillColor);
					pDoc->shapeArray.Add(p);
					break;
				}
			case 5:
				{
					// 文本
					WText *p = new WText(orgX, orgY, textContent, textAngle, borderWidth, borderType, borderColor, fillType, fillColor);
					pDoc->shapeArray.Add(p);
					break;
				}
			default:
				{
					MessageBox(L"请您选择图形类型！");
					break;
				}
			}
			Invalidate();//刷新窗口
		}
	} 
	// 判断鼠标的落点是否在图元内，修改操作
	else 
	{
		//未按下Ctrl键时左击，则逐个比较，看是否命中图元
		WShape *p = NULL;
		int count = pDoc->shapeArray.GetCount();
		for (int i = 0; i < count; i++)
		{
			p = (WShape*)pDoc->shapeArray[i];
			if (p->IsMatched(pntLogical))
			{
				//修改图元属性，从图元属性值里面取值赋值给对话框的变量
				AttributeDialog dialog;
				dialog.orgX = p->OrgX;
				dialog.orgY = p->OrgY;
				dialog.borderColor = p->BorderColor;
				dialog.borderWidth = p->BorderWidth;
				dialog.borderTypeIndex = p->BorderType;

				if (dialog.DoModal() == IDOK)
				{
					//利用改了以后对话框中图元的属性更新到文档图元数组的对象中
					p->OrgX = dialog.orgX;
					p->OrgY = dialog.orgY;
					
					p->BorderColor = dialog.borderColor;
					p->BorderWidth = dialog.borderWidth;
					p->BorderType = dialog.borderTypeIndex;

					p->FillColor = dialog.fillColor;
					p->FillType = dialog.filltypeIndex;

					p->SetAttribute(p->OrgX, p->OrgY, p->BorderColor, p->BorderType, p->BorderWidth, p->FillColor, p->FillType);
				}
				Invalidate();//刷新窗口
			}
		}
	}
}


void CDrawingView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDrawingDoc *pDoc = GetDocument();

	CClientDC dc(this);
	CPoint pntLogical = point;
	OnPrepareDC(&dc);
	dc.DPtoLP(&pntLogical);//DP->LP进行转换 

	WShape* p;
	int count = pDoc->shapeArray.GetCount();
	for (int i = 0; i < count; i++)
	{
		p = (WShape*)pDoc->shapeArray[i];
		if (p->IsMatched(pntLogical))
		{
			int value = AfxMessageBox(L"你是否要删除？", MB_OKCANCEL);
			if(value == IDOK)
				pDoc->shapeArray.RemoveAt(i);
		}
	}
	Invalidate();//刷新窗口
}
