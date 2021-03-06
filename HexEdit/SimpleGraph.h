#pragma once
// CSimpleGraph

#include "TipWnd.h"

class CSimpleGraph : public CWnd
{
	DECLARE_DYNAMIC(CSimpleGraph)

public:
	CSimpleGraph();

	void SetData(FILE_ADDRESS, std::vector<FILE_ADDRESS> val, std::vector<COLORREF> col);

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMouseHover(WPARAM wp, LPARAM lp);
	afx_msg LRESULT OnMouseLeave(WPARAM wp, LPARAM lp);

	DECLARE_MESSAGE_MAP()

private:
	static const COLORREF m_back = RGB(255, 255, 255);  // background colour
	static const COLORREF m_axes = RGB(0, 0, 0);        // colour of axes/ticks
	static const int m_left = 32;                       // left margin
	static const int m_right = 2;                       // right margin
	static const int m_top = 2;                         // top margin
	static const int m_bottom = 6;                      // bottom margin

	int m_heightAdjust;

	// These are used to draw the bitmap offscreen - must be re-created whenever the control is resized)
	CDC * m_pdc;
    CBitmap m_bm;
	CRect m_rct;
	CFont m_hfnt, m_vfnt;

	CTipWnd m_tip;                                      // Shows info when  hovering over a bar of the graph
	int m_bar;                                          // Last bar the mouse hovered over

	// Data for the graph
	FILE_ADDRESS m_max;
	std::vector<FILE_ADDRESS> m_val;
	std::vector<COLORREF> m_col;

	// Private functions
	void update();                                      // Update the bitmap and redraws the graph
	void draw_axes();                                   // Draws the axes on the bitmap
	void track_mouse(unsigned long);                    // Turns on receipt of mouse hover/leave messages
	int get_bar(CPoint pt);                             // Which graph bar is mouse point over (-1 if not over any)
};
