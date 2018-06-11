// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。  
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。  
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问 
// https://go.microsoft.com/fwlink/?LinkId=238214.
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// LKIView.h: CLKIView 类的接口
//

#pragma once
#include "Octree.h"


class CLKIView : public CView
{
protected: // 仅从序列化创建
	CLKIView();
	DECLARE_DYNCREATE(CLKIView)

// 特性
public:
	CLKIDoc* GetDocument() const;
	
	CPoint begin_move, end_move; //平移坐标系
	bool mouse_L_down;    //判断鼠标左键是否按下
	Octree m_set;   //去重点系

// 操作
public:
	void SetInitAdaptive(CRect rect);  //自适应显示


// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	

// 实现
public:
	virtual ~CLKIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // LKIView.cpp 中的调试版本
inline CLKIDoc* CLKIView::GetDocument() const
   { return reinterpret_cast<CLKIDoc*>(m_pDocument); }
#endif

